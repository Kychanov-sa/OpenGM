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

INLINE float fmax(float x, float y)
{
	return x > y ? x : y;
}

INLINE float fmax(float x, float y, float z)
{
	return x > y ? (x > z ? x : z) : (y > z ? y : z);
}

INLINE float fmax(float x, float y, float z, float w)
{
	//NYI
}

INLINE float fmin(float x, float y)
{
	return x < y ? x : y;
}

INLINE float fmin(float x, float y, float z)
{
	return x < y ? (x < z ? x : z) : (y < z ? y : z);
}


INLINE void fsincos(const float angle, float& sine, float cosine)
{
#if defined(_WIN64) || defined(__x86_64__) || defined(_M_X64)
	sine = fsin(x);
	cosine = fcos(x);
#else
	__asm
	{
		fld		dword ptr[angle]
		fsincos
		mov		eax, dword ptr[cosine]
		fstp	dword ptr[eax]
		mov		eax, dword ptr[sine]
		fstp	dword ptr[eax]
	}
#endif
}

INLINE float finvsqrt(const float& f)
{
	uint32_t tmp = ((GM_1_AS_INT << 1) + GM_1_AS_INT - *(uint32_t *)&f) >> 1;
	float y = *(float*)&tmp;
	return y * (1.47f - 0.47f * f * y * y);
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

INLINE float frsqrt(const float& f)
{
	union {
		float vh;
		int i0;
	};

	union {
		float vr;
		int i1;
	};

	vh = f * 0.5f;
	i1 = 0x5f3759df - (i0 >> 1);
	return vr * (1.5f - vh * vr * vr);
}