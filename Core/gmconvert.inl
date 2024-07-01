/// <summary>
/// OpenGM library convert functions.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>10-06-2019</created>
/// <copyright>Copyright 2005-2024 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifdef GMCONVERT_INL
	#error Nested inclusion of gmfuncs.inl
#else
	#define GMCONVERT_INL
#endif

const __declspec(align(16)) float Convert::rad2deg = (180.0f / GM_PI);
const __declspec(align(16)) float Convert::deg2rad = (GM_PI / 180.0f);

INLINE int FASTCALL Convert::FloatToInt(const float value) noexcept
{
	const int magic = (150 << 23) | (1 << 22);
	float _value = value + *(float*)&magic;
	return *(int*)&_value - magic;
}

INLINE float FASTCALL Convert::IntToFloat(const int value) noexcept
{
	return float(value);
}

INLINE float16 FASTCALL Convert::FloatToHalf(const float value) noexcept
{
	register int i = *((unsigned int*)(&value));
	register int s = (i >> 16) & 0x00008000;
	register int e = ((i >> 23) & 0x000000ff) - (127 - 15);
	register int m = i & 0x007fffff;

	if (e <= 0)
	{
		if (e < -10) return 0;
		m = (m | 0x00800000) >> (1 - e);
		return s | (m >> 13);
	} else if (e == 0xff - (127 - 15)) {
		if (m == 0)
		{
			// Inf
			return s | 0x7c00;
		} else {
			// NAN
			m >>= 13;
			return s | 0x7c00 | m | (m == 0);
		}
	} else {
		// Overflow
		if (e > 30) return s | 0x7c00;
		return s | (e << 10) | (m >> 13);
	}
}

INLINE float FASTCALL Convert::HalfToFloat(const float16 value) noexcept
{
	register int s = (value >> 15) & 0x00000001;
	register int e = (value >> 10) & 0x0000001f;
	register int m = value & 0x000003ff;
	union
	{
		int		i;
		float	f;
	} result;

	if (e == 0)
	{
		if (m == 0)
		{
			// Plus or minus zero
			result.i = (s << 31);
			return result.f;
		} else {
			// Denormalized number -- renormalize it
			while (!(m & 0x00000400))
			{
				m <<= 1;
				e -= 1;
			}

			e += 1;
			m &= ~0x00000400;
		}
	} else if (e == 31) {
		if (m == 0)
		{
			// Inf
			result.i = (s << 31) | 0x7f800000;
			return result.f;
		} else {
			// NaN
			result.i = (s << 31) | 0x7f800000 | (m << 13);
			return result.f;
		}
	}

	e = e + (127 - 15);
	m = m << 13;
	result.i = (s << 31) | (e << 23) | m;
	return result.f;
}

INLINE float FASTCALL Convert::DegreesToRadians(const float value) noexcept
{
	return value * deg2rad;
}

INLINE float FASTCALL Convert::RadiansToDegrees(const float value) noexcept
{
	return value * rad2deg;
}

INLINE float4 FASTCALL Convert::ARGBToFloat4(const uint32_t value) noexcept
{
	union u32tou8x4
	{
		uint32_t u32;
		uint8_t u8[4];
	} _value = { value };

	const float s = 1.0f / 255.0f;
	return float4(float(_value.u8[1])*s, float(_value.u8[2])*s, float(_value.u8[3])*s, float(_value.u8[0])*s);
}

INLINE uint32_t FASTCALL Convert::Float4ToARGB(const float4& value) noexcept
{
	union u32tou8x4
	{
		uint32_t u32;
		uint8_t u8[4];
	} result;

	result.u8[0] = uint8_t(value.a*255.0f);
	result.u8[1] = uint8_t(value.r*255.0f);
	result.u8[2] = uint8_t(value.g*255.0f);
	result.u8[3] = uint8_t(value.b*255.0f);
	return result.u32;
}

INLINE float4 FASTCALL Convert::RGBEToFloat4(const uint32_t value) noexcept
{
	union u32tou8x4
	{
		uint32_t u32;
		uint8_t u8[4];
	} _value = { value };

	if (_value.u8[3] != 0)
		return float4(float(_value.u8[0]), float(_value.u8[1]), float(_value.u8[2]), 1.0f) * ldexpf(1.0f, _value.u8[3] - (int)(128 + 8));
	else
		return float4(0.0f, 0.0f, 0.0f, 0.0f);
}

INLINE uint32_t FASTCALL Convert::Float4ToRGBE(const float4& value) noexcept
{
	union u32tou8x4
	{
		uint32_t u32;
		uint8_t u8[4];
	} result;

	float v = fmax3(value.r, value.g, value.b);
	if (v < 1e-32f)
	{
		return 0L;
	} else {
		int ex;
		float m = frexpf(v, &ex) * 256.0f / v;
		result.u8[0] = uint8_t(m * value.r);
		result.u8[1] = uint8_t(m * value.g);
		result.u8[2] = uint8_t(m * value.b);
		result.u8[3] = uint8_t(ex + 128);
		return result.u32;
	}
}

INLINE uint32_t FASTCALL Convert::Float3ToUDEC3(const float3& value) noexcept
{
	// Convert to 0 to (2^10)-1 range
	uint32_t x = uint32_t((value.x + 1.0f) * 511.5f);
	uint32_t y = uint32_t((value.y + 1.0f) * 511.5f);
	uint32_t z = uint32_t((value.z + 1.0f) * 511.5f);
	return (x & 0x3ff) | ((y & 0x3ff) << 10) | ((z & 0x3ff) << 20);
}

INLINE int32_t FASTCALL Convert::Float3ToDEC3N(const float3& value) noexcept
{
	// Convert to signed integer -511 to +511 range
	int32_t x = int32_t(value.x * 511.0f);
	int32_t y = int32_t(value.y * 511.0f);
	int32_t z = int32_t(value.z * 511.0f);
	return (x & 0x3ff) | ((y & 0x3ff) << 10) | ((z & 0x3ff) << 20);
}