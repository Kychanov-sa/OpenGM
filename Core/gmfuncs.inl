/// <summary>
/// OpenGM library inline functions.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>14-06-2005</created>
/// <copyright>Copyright 2005-2018 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifdef GMFUNCS_INL
	#error Nested inclusion of gmfuncs.inl
#else
	#define GMFUNCS_INL
#endif

INLINE float fmax2(float x, float y)
{
	return x > y ? x : y;
}

INLINE float fmax3(float x, float y, float z)
{
	return x > y ? (x > z ? x : z) : (y > z ? y : z);
}

INLINE float fmax4(float x, float y, float z, float w)
{
	float r = fmax3(x, y, z);
	return r > w ? r : w;
}

INLINE float fmin2(float x, float y)
{
	return x < y ? x : y;
}

INLINE float fmin3(float x, float y, float z)
{
	return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

INLINE float fmin4(float x, float y, float z, float w)
{
	float r = fmin3(x, y, z);
	return r < w ? r : w;
}

const __m128  f3 = _mm_set_ss(3.0f);  // 3 as single precision SSE value
const __m128  f05 = _mm_set_ss(0.5f);  // 0.5 as single precision SSE value

INLINE float frsqrt(const float& value)
{
#if defined(_WIN64) || defined(__x86_64__) || defined(_M_X64)
	uint32_t tmp = ((GM_1_AS_INT << 1) + GM_1_AS_INT - *(uint32_t*)&value) >> 1;
	float y = *(float*)&tmp;
	return y * (1.47f - 0.47f * value * y * y);

#if false
	union {
		float vh;
		int i0;
	};

	union {
		float vr;
		int i1;
	};

	vh = value * 0.5f;
	i1 = 0x5f3759df - (i0 >> 1);
	return vr * (1.5f - vh * vr * vr);
#endif

#else
	float r;
	__m128  xx = _mm_load_ss(&value);
	__m128  xr = _mm_rsqrt_ss(xx);
	__m128  xt;

	xt = _mm_mul_ss(xr, xr);
	xt = _mm_mul_ss(xt, xx);
	xt = _mm_sub_ss(f3, xt);
	xt = _mm_mul_ss(xt, f05);
	xr = _mm_mul_ss(xr, xt);

	_mm_store_ss(&r, xr);

	return r;

#if false
	const __m128 fOneHalf = _mm_set_ss(0.5f);
	__m128 Y0, X0, X1, X2, FOver2;
	float temp;
	Y0 = _mm_set_ss(value);
	X0 = _mm_rsqrt_ss(Y0);
	FOver2 = _mm_mul_ss(Y0, fOneHalf);
	X1 = _mm_mul_ss(X0, X0);
	X1 = _mm_sub_ss(fOneHalf, _mm_mul_ss(FOver2, X1));
	X1 = _mm_add_ss(X0, _mm_mul_ss(X0, X1));
	X2 = _mm_mul_ss(X1, X1);
	X2 = _mm_sub_ss(fOneHalf, _mm_mul_ss(FOver2, X2));
	X2 = _mm_add_ss(X1, _mm_mul_ss(X1, X2));
	_mm_store_ss(&temp, X2);
	return temp;
#endif
#endif
}

INLINE float fsign(float f)
{
	union f32tou32
	{
		float f32;
		uint32_t u32;
	} value, result;

	value.f32 = f;
	result.u32 = (value.u32 & 0x80000000) | (0x3f800000);
	return result.f32;
}