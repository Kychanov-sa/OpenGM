#include "stdafx.h"
#include <intrin.h>
#include "registers.h"

namespace OpenGm
{
	float4 FASTCALL normalize4_sse(float4& v)
	{
		__m128 tmp = _mm_load_ps(&v.x);
		__m128 dp = _mm_dp_ps(tmp, tmp, 0x7F);
		dp = _mm_rsqrt_ps(dp);
		tmp = _mm_mul_ps(tmp, dp);

		float4 result;
		_mm_store_ps(&result.x, tmp);
		result.w = 1.0f;
		return result;
	}

	float FASTCALL dot4_sse(const float4& a, const float4& b)
	{
		__m128 v1 = _mm_load_ps(&a.x);
		__m128 v2 = _mm_load_ps(&b.x);
		__m128 dp = _mm_dp_ps(v1, v2, 0x7F);

		float result;
		_mm_store_ss(&result, dp);
		return result;
	}

	static inline __m128 lincomb_SSE(const __m128 &a, const float4x4 &b)
	{		
		__m128 row1 = _mm_load_ps(&b._11);
		__m128 row2 = _mm_load_ps(&b._21);
		__m128 row3 = _mm_load_ps(&b._31);
		__m128 row4 = _mm_load_ps(&b._41);
		
		__m128 result;
		result = _mm_mul_ps(_mm_shuffle_ps(a, a, 0x00), row1);
		result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(a, a, 0x55), row2));
		result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(a, a, 0xaa), row3));
		result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(a, a, 0xff), row4));
		return result;
	}

	float4x4 FASTCALL mul4x4_sse(const float4x4& a, const float4x4& b)
	{
		__m128 row1 = _mm_load_ps(&a._11);
		__m128 resultRow1 = lincomb_SSE(row1, b);

		__m128 row2 = _mm_load_ps(&a._21);
		__m128 resultRow2 = lincomb_SSE(row2, b);

		__m128 row3 = _mm_load_ps(&a._31);
		__m128 resultRow3 = lincomb_SSE(row3, b);

		__m128 row4 = _mm_load_ps(&a._41);
		__m128 resultRow4 = lincomb_SSE(row4, b);

		float4x4 result;
		_mm_store_ps(&result._11, resultRow1);
		_mm_store_ps(&result._21, resultRow2);
		_mm_store_ps(&result._31, resultRow3);
		_mm_store_ps(&result._41, resultRow4);
		return result;
	}

	// another linear combination, using AVX instructions on XMM regs
	static inline __m128 lincomb_AVX_4mem(const float *a, const float4x4 &b)
	{
		__m128 row1 = _mm_load_ps(&b._11);
		__m128 row2 = _mm_load_ps(&b._21);
		__m128 row3 = _mm_load_ps(&b._31);
		__m128 row4 = _mm_load_ps(&b._41);

		__m128 result;
		result = _mm_mul_ps(_mm_broadcast_ss(&a[0]), row1);
		result = _mm_add_ps(result, _mm_mul_ps(_mm_broadcast_ss(&a[1]), row2));
		result = _mm_add_ps(result, _mm_mul_ps(_mm_broadcast_ss(&a[2]), row3));
		result = _mm_add_ps(result, _mm_mul_ps(_mm_broadcast_ss(&a[3]), row4));
		return result;
	}

	float4x4 FASTCALL mul4x4_avx(const float4x4& a, const float4x4& b)
	{
		_mm256_zeroupper();
		__m128 resultRow1 = lincomb_AVX_4mem(&a._11, b);
		__m128 resultRow2 = lincomb_AVX_4mem(&a._21, b);
		__m128 resultRow3 = lincomb_AVX_4mem(&a._31, b);
		__m128 resultRow4 = lincomb_AVX_4mem(&a._41, b);

		float4x4 result;
		_mm_store_ps(&result._11, resultRow1);
		_mm_store_ps(&result._21, resultRow2);
		_mm_store_ps(&result._31, resultRow3);
		_mm_store_ps(&result._41, resultRow4);
		return result;
	}
}
//
//#ifndef _WIN64
//
//__declspec(naked) float	__fastcall dot4_sse(const float4& a, const float4& b)
//{
//	_asm
//	{
//		movaps	xmm0, xmmword ptr[ecx]
//		movaps	xmm1, xmmword ptr[edx]
//		mulps	xmm0, xmm1
//		movhlps	xmm1, xmm0
//		addps	xmm0, xmm1
//		movaps	xmm1, xmm0
//		shufps	xmm0, xmm0, 00000001b
//		addps	xmm0, xmm1
//		movss	dword ptr[r0], xmm0
//		fld		dword ptr[r0]
//		ret
//	}
//}
//
//__declspec(naked) void	__fastcall cross4_sse(float4& r, const float4& a, const float4& b)
//{
//	_asm
//	{
//		mov 	eax, [esp + 4]
//
//		// edx = a, eax = b, ecx = r
//		movaps	xmm0, xmmword ptr[edx]
//		movaps	xmm2, xmm0
//
//		movaps	xmm1, xmmword ptr[eax]
//		movaps	xmm3, xmm1
//
//		shufps	xmm0, xmm0, 11001001b
//		shufps	xmm1, xmm1, 11010010b
//		shufps	xmm2, xmm2, 11010010b
//		shufps	xmm3, xmm3, 11001001b
//
//		mulps	xmm0, xmm1
//		mulps	xmm2, xmm3
//
//		subps	xmm0, xmm2
//		movaps	qword ptr[ecx], xmm0
//
//		ret		4
//	}
//}
//
//__declspec(naked) float	__fastcall determinant3x3_sse2(const float3x3& m)
//{
//	_asm
//	{
//		pshufd xmm1, [ecx + 4 * 4 * 1], 11001001b
//		pshufd xmm2, [ecx + 4 * 4 * 2], 11010010b
//		mulps xmm1, xmm2						// Multiply the 2 last rows
//		pshufd xmm3, [ecx + 4 * 4 * 1], 11010010b
//		pshufd xmm4, [ecx + 4 * 4 * 2], 11001001b
//		mulps xmm3, xmm4						// ^^ Again but reverse-crossing
//		subps xmm1, xmm3
//		mulps xmm1, [ecx + 4 * 4 * 0]
//		movhlps xmm0, xmm1
//		addss xmm0, xmm1						// xmm0 = [a1 + a3, a2 + a4, Е]
//		pshufd xmm1, xmm1, 01010101b
//		addss xmm0, xmm1						// xmm0 = [a1 + a3 + a2 + a4, Е]
//		movss	dword ptr[r0], xmm0
//		fld		dword ptr[r0]
//		ret
//	}
//}
//
//__declspec(naked) float	__fastcall determinant4x4_sse2(const float4x4& m)
//{
//	_asm
//	{
//		pshufd xmm6, [ecx + 4 * 4 * 1], 10010011b	// xmm6 = [a24 a21 a22 a23]
//		movaps xmm0, [ecx + 4 * 4 * 3]				// xmm0 = [a41 a42 a43 a44]
//		pshufd xmm3, [ecx + 4 * 4 * 2], 00111001b	// xmm3 = [a32 a33 a34 a31]
//		pshufd xmm1, xmm0, 01001110b
//		mulps xmm1, xmm3						// xmm1 = [a32*a43 a33*a44 a34*a41 a31*a42]
//		pshufd xmm2, xmm0, 10010011b
//		mulps xmm2, xmm3						// xmm2 = [a32*a44 a33*a41 a34*a42 a31*a43]
//		pshufd xmm4, xmm6, 01001110b			// xmm4 = [a22 a23 a24 a21]
//		mulps xmm0, xmm3
//		pshufd xmm0, xmm0, 00111001b			// xmm0 = [a33*a42 a34*a43 a31*a44 a32*a41]
//		pshufd xmm5, xmm6, 10010011b			// xmm5 = [a23 a24 a21 a22]
//		subps xmm1, xmm0						// xmm1 = [md13 ma13 mb13 mc13]
//		pshufd xmm0, xmm1, 00111001b			// xmm0 = [md11 ma11 mb11 mc11]
//		pshufd xmm3, xmm2, 01001110b
//		subps xmm3, xmm2						// xmm3 = [md12 ma12 mb12 mc12]
//		mulps xmm0, xmm4
//		mulps xmm1, xmm6
//		mulps xmm3, xmm5
//		addps xmm0, xmm1
//		addps xmm0, xmm3						// xmm0 = [M11 M12 M13 M14]
//		mulps xmm0, [ecx + 4 * 4 * 0]				// xmm0 = [a11*M11 a12*M12 a13*M13 a14*M14]
//		movhlps xmm1, xmm0
//		addps xmm0, xmm1						// xmm0 = [A1 + A3, A2 + A4, Е]
//		pshufd xmm1, xmm0, 01010101b
//		subss xmm0, xmm1						// xmm0 = [A1 + A3 + A2 + A4, Е]
//		movss	dword ptr[r0], xmm0
//		fld		dword ptr[r0]
//		ret
//	}
//}
//
//__declspec(naked) void	__fastcall inverse4x4_sse2(float4x4& r, const float4x4& m)
//{
//	_asm
//	{
//		pshufd xmm6, [edx + 4 * 4 * 1], 10010011b	// xmm6 = [a24 a21 a22 a23]
//		pshufd xmm3, [edx + 4 * 4 * 2], 00111001b	// xmm3 = [a32 a33 a34 a31]
//		movaps xmm0, [edx + 4 * 4 * 3]				// xmm0 = [a41 a42 a43 a44]
//		pshufd xmm1, xmm0, 01001110b
//		mulps xmm1, xmm3						// xmm1 = [a32*a43 a33*a44 a34*a41 a31*a42]
//		pshufd xmm2, xmm0, 10010011b
//		mulps xmm2, xmm3						// xmm2 = [a32*a44 a33*a41 a34*a42 a31*a43]
//		pshufd xmm7, xmm6, 01001110b			// xmm7 = [a22 a23 a24 a21]
//		mulps xmm0, xmm3
//		pshufd xmm0, xmm0, 00111001b			// xmm0 = [a33*a42 a34*a43 a31*a44 a32*a41]
//		pshufd xmm5, xmm6, 10010011b			// xmm5 = [a23 a24 a21 a22]
//		subps xmm1, xmm0						// xmm1 = [md13 ma13 mb13 mc13]
//		pshufd xmm0, xmm1, 00111001b			// xmm0 = [md11 ma11 mb11 mc11]
//		pshufd xmm3, xmm2, 01001110b
//		subps xmm3, xmm2						// xmm3 = [md12 ma12 mb12 mc12]
//		mulps xmm7, xmm0
//		mulps xmm6, xmm1
//		mulps xmm5, xmm3
//		addps xmm7, xmm6
//		addps xmm7, xmm5						// xmm7 = [M11 M12 M13 M14]
//		movaps xmm6, xmm7						// xmm6 = [M11 M12 M13 M14]
//		pshufd xmm2, [edx + 4 * 4 * 0], 10010011b	// xmm2 = [a14 a11 a12 a13]
//
//		// Determinant
//		mulps xmm7, [edx + 4 * 4 * 0]				// xmm0 = [a11*M11 a12*M12 a13*M13 a14*M14]
//		pshufd xmm4, xmm2, 01001110b			// xmm4 = [a12 a13 a14 a11]
//		movhlps xmm5, xmm7
//		addps xmm7, xmm5						// xmm0 = [A1 + A3, A2 + A4, Е]
//		pshufd xmm5, xmm7, 01010101b
//		subss xmm7, xmm5						// xmm0 = [A1 + A3 + A2 + A4, Е]
//
//		// Row 2
//		pshufd xmm5, xmm2, 10010011b			// xmm5 = [a13 a14 a11 a12]
//		mulps xmm4, xmm0
//		mulps xmm2, xmm1
//		mulps xmm5, xmm3
//		addps xmm4, xmm2
//		addps xmm5, xmm4						// xmm5 = [M21 M22 M23 M24]
//
//		// Row 3
//		pshufd xmm4, [edx + 4 * 4 * 3], 00111001b	// xmm4 = [a42 a43 a44 a41]
//		movaps xmm0, [edx + 4 * 4 * 1]				// xmm0 = [a21 a22 a23 a24]
//		pshufd xmm3, [edx + 4 * 4 * 0], 00111001b	// xmm3 = [a12 a13 a14 a11]
//		pshufd xmm1, xmm0, 01001110b
//		mulps xmm1, xmm3						// xmm1 = [a12*a23 a13*a24 a14*a21 a11*a22]
//		pshufd xmm2, xmm0, 10010011b
//		mulps xmm2, xmm3						// xmm2 = [a12*a24 a13*a21 a14*a22 a11*a23]
//		mulps xmm0, xmm3
//		pshufd xmm0, xmm0, 00111001b			// xmm0 = [a13*a22 a14*a23 a11*a24 a12*a21]
//		subps xmm1, xmm0						// xmm1 = [md43 ma43 mb43 mc43]
//		pshufd xmm0, xmm1, 00111001b			// xmm0 = [md41 ma41 mb41 mc41]
//		mulps xmm4, xmm0
//		pshufd xmm3, xmm2, 01001110b
//		subps xmm3, xmm2						// xmm3 = [md42 ma42 mb42 mc42]
//		pshufd xmm2, [edx + 4 * 4 * 3], 10010011b	// xmm2 = [a44 a41 a42 a43]
//		mulps xmm2, xmm1
//		addps xmm4, xmm2
//		pshufd xmm2, [edx + 4 * 4 * 3], 01001110b	// xmm2 = [a43 a44 a41 a42]
//		mulps xmm2, xmm3
//		addps xmm4, xmm2						// xmm4 = [M31 M32 M33 M34]
//
//		// Row 4
//		pshufd xmm2, [edx + 4 * 4 * 2], 01001110b	// xmm2 = [a33 a34 a31 a32]
//		mulps xmm3, xmm2
//		rcpss xmm7, xmm7
//		pshufd xmm2, [edx + 4 * 4 * 2], 10010011b	// xmm2 = [a34 a31 a32 a33]
//		mulps xmm1, xmm2
//		pshufd xmm2, [edx + 4 * 4 * 2], 00111001b	// xmm2 = [a32 a33 a34 a31]
//		mulps xmm0, xmm2
//		pshufd xmm7, xmm7, 00000000b
//		addps xmm3, xmm1
//		addps xmm3, xmm0						// xmm3 = [M41 M42 M43 M44]
//
//		// Set the right signs multiply by the Determinant
//		pxor xmm7, [Sign]
//		mulps xmm6, xmm7
//		mulps xmm4, xmm7
//		pshufd xmm7, xmm7, 00010001b
//		mulps xmm5, xmm7
//		mulps xmm3, xmm7
//
//		// Transpose
//		movaps xmm7, xmm6
//		unpcklps xmm6, xmm5						// xmm6 = [a11, a21, a12, a22]
//		movaps xmm0, xmm4
//		unpcklps xmm4, xmm3						// xmm4 = [a31, a41, a32, a42]
//		movaps xmm2, xmm6
//		unpckhps xmm7, xmm5						// xmm2 = [a13, a23, a14, a24]		
//		unpckhps xmm0, xmm3						// xmm0 = [a33, a43, a34, a44]
//		movaps xmm1, xmm7
//		movlhps xmm6, xmm4						// xmm6 = [a11, a21, a31, a41]
//		movaps[ecx + 0 * 4 * 4], xmm6
//		movhlps xmm4, xmm2						// xmm4 = [a12, a22, a32, a42]
//		movaps[ecx + 1 * 4 * 4], xmm4
//		movlhps xmm7, xmm0						// xmm2 = [a13, a23, a33, a43]
//		movaps[ecx + 2 * 4 * 4], xmm7
//		movhlps xmm0, xmm1						// xmm0 = [a14, a24, a34, a44]
//		movaps[ecx + 3 * 4 * 4], xmm0
//
//		ret
//	}
//}
//
//__declspec(naked) void	__fastcall mul4x4_sse(float4x4& r, const float4x4& a, const float4x4& b)
//{
//	_asm
//	{
//		mov		eax, dword ptr[esp + 4]
//		// edx = a, eax = b, ecx = r
//
//		// load b
//		movaps	xmm0, xmmword ptr[eax]
//		movaps	xmm1, xmmword ptr[eax + 16]
//		movaps	xmm2, xmmword ptr[eax + 32]
//		movaps	xmm3, xmmword ptr[eax + 48]
//
//		// r0,r1,r2,r3
//		movaps	xmm4, xmmword ptr[edx]
//		movaps	xmm5, xmm4
//		movaps	xmm6, xmm4
//		movaps	xmm7, xmm4
//		shufps	xmm4, xmm4, 00000000b
//		shufps	xmm5, xmm5, 01010101b
//		shufps	xmm6, xmm6, 10101010b
//		shufps	xmm7, xmm7, 11111111b
//		mulps	xmm4, xmm0
//		mulps	xmm5, xmm1
//		mulps	xmm6, xmm2
//		mulps	xmm7, xmm3
//		addps	xmm4, xmm5
//		addps	xmm4, xmm6
//		addps	xmm4, xmm7
//		movaps	qword ptr[ecx], xmm4
//
//		// r4,r5,r6,r7
//		movaps	xmm4, xmmword ptr[edx + 16]
//		movaps	xmm5, xmm4
//		movaps	xmm6, xmm4
//		movaps	xmm7, xmm4
//		shufps	xmm4, xmm4, 00000000b
//		shufps	xmm5, xmm5, 01010101b
//		shufps	xmm6, xmm6, 10101010b
//		shufps	xmm7, xmm7, 11111111b
//		mulps	xmm4, xmm0
//		mulps	xmm5, xmm1
//		mulps	xmm6, xmm2
//		mulps	xmm7, xmm3
//		addps	xmm4, xmm5
//		addps	xmm4, xmm6
//		addps	xmm4, xmm7
//		movaps	qword ptr[ecx + 16], xmm4
//
//		// r8,r9,r10,r11
//		movaps	xmm4, xmmword ptr[edx + 32]
//		movaps	xmm5, xmm4
//		movaps	xmm6, xmm4
//		movaps	xmm7, xmm4
//		shufps	xmm4, xmm4, 00000000b
//		shufps	xmm5, xmm5, 01010101b
//		shufps	xmm6, xmm6, 10101010b
//		shufps	xmm7, xmm7, 11111111b
//		mulps	xmm4, xmm0
//		mulps	xmm5, xmm1
//		mulps	xmm6, xmm2
//		mulps	xmm7, xmm3
//		addps	xmm4, xmm5
//		addps	xmm4, xmm6
//		addps	xmm4, xmm7
//		movaps	qword ptr[ecx + 32], xmm4
//
//		// r12,r13,r14,r15
//		movaps	xmm4, xmmword ptr[edx + 48]
//		movaps	xmm5, xmm4
//		movaps	xmm6, xmm4
//		movaps	xmm7, xmm4
//		shufps	xmm4, xmm4, 00000000b
//		shufps	xmm5, xmm5, 01010101b
//		shufps	xmm6, xmm6, 10101010b
//		shufps	xmm7, xmm7, 11111111b
//		mulps	xmm4, xmm0
//		mulps	xmm5, xmm1
//		mulps	xmm6, xmm2
//		mulps	xmm7, xmm3
//		addps	xmm4, xmm5
//		addps	xmm4, xmm6
//		addps	xmm4, xmm7
//		movaps	qword ptr[ecx + 48], xmm4
//
//		ret		4
//	}
//}
//
///// <summary>
///// «аполн€ет таблицу функций реализаци€ми на SSE.
///// </summary>
//void FillFuncTable_SSE()
//{
//	cross4 = cross4_sse;
//	dot4 = dot4_sse;
//	mul4x4 = mul4x4_sse;
//}
//
///// <summary>
///// «аполн€ет таблицу функций реализаци€ми на SSE2.
///// </summary>
//void FillFuncTable_SSE2()
//{
//	inverse4x4 = inverse4x4_sse2;
//	determinant3x3 = determinant3x3_sse2;
//	determinant4x4 = determinant4x4_sse2;
//}
//#endif