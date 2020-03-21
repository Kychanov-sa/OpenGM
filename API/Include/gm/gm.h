/// <summary>
/// OpenGM library header.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>14-06-2005</created>
/// <copyright>Copyright 2005-2018 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifndef GM_H
#define GM_H

#include <stdint.h>
#include <math.h>

#pragma warning(disable : 4522)

namespace OpenGm
{
#ifdef GM_BUILDING_LIB
#define GMAPI
#else
#define GMAPI extern
#endif

#pragma region Compiler specific stuff
#if defined(_MSC_VER)
#ifndef FASTCALL
#	define FASTCALL __fastcall
#endif
#ifndef INLINE
#	define INLINE __forceinline
#endif
#ifndef STDCALL
#	define STDCALL __stdcall
#endif
#ifndef CDECL
#	define CDECL __cdecl
#endif
#if _MSVC_LANG > 201402L
#	define NODISCARD			[[nodiscard]]
#else
#	define NODISCARD
#endif
#	define DECLALIGN16			__declspec(align(16))
#	define DECLALIGN32			__declspec(align(32))
#	define DECLALIGN64			__declspec(align(64))
#ifndef NOTHROW
#	define NOTHROW				__declspec(nothrow)
#endif
#endif
#pragma endregion

#pragma region Constants
const float GM_PI = 3.1415926535897932384626433832795028841971693993751f;
const float GM_1BYPI = 0.31830988618379067153776752674508f;
const float GM_SQRT2 = 1.4142135623730950488016887242096980785696718753769f;
const float GM_2PI = 2.0f * GM_PI;
const float GM_PI2 = GM_PI * 0.5f;
const float GM_EPS = 1e-12f;
const float GM_EPSPOW2 = GM_EPS * GM_EPS;
const float GM_MAXFLOAT = 1.0e+38f;
const uint32_t GM_1_AS_INT = 0x3F800000;
#pragma endregion

#pragma region Type definitions
	struct _float2;
	struct _float3;
	struct _float4;

#include "gmshuf.h"
#include "gmtypes.h"

	typedef _float2		 __declspec(align(16)) float2;
	typedef _float3		 __declspec(align(16)) float3;
	typedef _float4		 __declspec(align(16)) float4;

	typedef _float2x2	 __declspec(align(16)) float2x2;
	typedef _float2x3	 __declspec(align(16)) float2x3;
	typedef _float2x4	 __declspec(align(16)) float2x4;
	typedef _float3x2	 __declspec(align(16)) float3x2;
	typedef _float3x3	 __declspec(align(16)) float3x3;
	typedef _float3x4	 __declspec(align(16)) float3x4;
	typedef _float4x2	 __declspec(align(16)) float4x2;
	typedef _float4x3	 __declspec(align(16)) float4x3;
	typedef _float4x4	 __declspec(align(16)) float4x4;

	typedef int16_t float16;
	typedef _float4x3 xform3d;

#include "gmshuf.inl"
#include "gmtypes.inl"
#pragma endregion

#pragma region Functions

#if defined(_WIN64) || defined(__x86_64__) || defined(_M_X64)
	#define abs2			abs2_clang
	#define abs3			abs3_clang
	#define abs4			abs4_clang
	#define all2			all2_clang
	#define all3			all3_clang
	#define all4			all4_clang
	#define any2			any2_clang
	#define any3			any3_clang
	#define any4			any4_clang
	#define ceil2			ceil2_clang
	#define ceil3			ceil3_clang
	#define ceil4			ceil4_clang
	#define cross3			cross3_clang
	#define cross4			cross4_clang
	#define determinant2x2	determinant2x2_clang
	#define determinant3x3	determinant3x3_clang
	#define determinant4x4	determinant4x4_clang
	#define distance2		distance2_clang
	#define distance3		distance3_clang
	#define distance4		distance4_clang
	#define dst				dst_clang
	#define dot2			dot2_clang
	#define dot3			dot3_clang
	#define dot4			dot4_clang
	#define faceforward2	faceforward2_clang
	#define faceforward3	faceforward3_clang
	#define faceforward4	faceforward4_clang
	#define floor2			floor2_clang
	#define floor3			floor3_clang
	#define floor4			floor4_clang
	#define inverse2x2		inverse2x2_clang
	#define inverse3x3		inverse3x3_clang
	#define inverse4x4		inverse4x4_clang
	#define length2			length2_clang
	#define length3			length3_clang
	#define length4			length4_clang
	#define lerp2			lerp2_clang
	#define lerp3			lerp3_clang
	#define lerp4			lerp4_clang
	#define mad2			mad2_clang
	#define mad3			mad3_clang
	#define mad4			mad4_clang
	#define mul2x2			mul2x2_clang
	#define mul3x3			mul3x3_clang
	#define mul4x4			mul4x4_clang
	#define mul2			mul2_clang
	#define mul3			mul3_clang
	#define mul4			mul4_clang
	#define mul43			mul43_clang
	#define normalize2		normalize2_clang
	#define normalize3		normalize3_clang
	#define normalize4		normalize4_clang
	#define normal3			normal3_clang
	#define reflect2		reflect2_clang
	#define reflect3		reflect3_clang
	#define reflect4		reflect4_clang
	#define refract2		refract2_clang
	#define refract3		refract3_clang
	#define refract4		refract4_clang
	#define round2			round2_clang
	#define round3			round3_clang
	#define round4			round4_clang
	#define transpose2x2	transpose2x2_clang
	#define transpose3x3	transpose3x3_clang
	#define transpose4x4a	transpose4x4_clang	
#else
#include "gmfuncs_clang.h"
	#define abs2			abs2_clang
	#define abs3			abs3_clang
	#define abs4			abs4_clang
	#define all2			all2_clang
	#define all3			all3_clang
	#define all4			all4_clang
	#define any2			any2_clang
	#define any3			any3_clang
	#define any4			any4_clang
	#define ceil2			ceil2_clang
	#define ceil3			ceil3_clang
	#define ceil4			ceil4_clang
	#define cross3			cross3_clang
	#define cross4			cross4_clang
	#define determinant2x2	determinant2x2_clang
	#define determinant3x3	determinant3x3_clang
	#define determinant4x4	determinant4x4_clang
	#define distance2		distance2_clang
	#define distance3		distance3_clang
	#define distance4		distance4_clang
	#define dst				dst_clang
	#define dot2			dot2_clang
	#define dot3			dot3_clang
	#define dot4			dot4_clang
	#define faceforward2	faceforward2_clang
	#define faceforward3	faceforward3_clang
	#define faceforward4	faceforward4_clang
	#define floor2			floor2_clang
	#define floor3			floor3_clang
	#define floor4			floor4_clang
	#define inverse2x2		inverse2x2_clang
	#define inverse3x3		inverse3x3_clang
	#define inverse4x4		inverse4x4_clang
	#define length2			length2_clang
	#define length3			length3_clang
	#define length4			length4_clang
	#define lerp2			lerp2_clang
	#define lerp3			lerp3_clang
	#define lerp4			lerp4_clang
	#define mad2			mad2_clang
	#define mad3			mad3_clang
	#define mad4			mad4_clang
	#define mul2x2			mul2x2_clang
	#define mul3x3			mul3x3_clang
	#define mul4x4			mul4x4_clang
	#define mul2			mul2_clang
	#define mul3			mul3_clang
	#define mul4			mul4_clang
	#define mul43			mul43_clang
	#define normalize2		normalize2_clang
	#define normalize3		normalize3_clang
	#define normalize4		normalize4_clang
	#define normal3			normal3_clang
	#define reflect2		reflect2_clang
	#define reflect3		reflect3_clang
	#define reflect4		reflect4_clang
	#define refract2		refract2_clang
	#define refract3		refract3_clang
	#define refract4		refract4_clang
	#define round2			round2_clang
	#define round3			round3_clang
	#define round4			round4_clang
	#define transpose2x2	transpose2x2_clang
	#define transpose3x3	transpose3x3_clang
	#define transpose4x4a	transpose4x4_clang	
#endif

/// <summary>
/// Returns max value.
/// </summary>
INLINE float fmax2(float x, float y);
INLINE float fmax3(float x, float y, float z);
INLINE float fmax4(float x, float y, float z, float w);
INLINE float fmin2(float x, float y);
INLINE float fmin3(float x, float y, float z);
INLINE float fmin4(float x, float y, float z, float w);
INLINE void fsincos(const float angle, float& sine, float cosine);
INLINE float finvsqrt(const float& f);
INLINE float fsign(float f);
INLINE float frsqrt(const float& f);
#include "gmfuncs.inl"

class Convert
{
public:
	static INLINE int FASTCALL FloatToInt(const float value) noexcept;
	static INLINE float FASTCALL IntToFloat(const int value) noexcept;
	static INLINE float16 FASTCALL FloatToHalf(const float value) noexcept;
	static INLINE float FASTCALL HalfToFloat(const float16 value) noexcept;
	static INLINE float FASTCALL DegreesToRadians(const float value) noexcept;
	static INLINE float FASTCALL RadiansToDegrees(const float value) noexcept;

	static INLINE float4 FASTCALL ARGBToFloat4(const uint32_t value) noexcept;
	static INLINE uint32_t FASTCALL Float4ToARGB(const float4& value) noexcept;

	static INLINE float4 FASTCALL RGBEToFloat4(const uint32_t value) noexcept;
	static INLINE uint32_t FASTCALL Float4ToRGBE(const float4& value) noexcept;

	static INLINE uint32_t FASTCALL Float3ToUDEC3(const float3& value) noexcept;
	static INLINE int32_t FASTCALL Float3ToDEC3N(const float3& value) noexcept;

private:
	static const __declspec(align(16)) float rad2deg;
	static const __declspec(align(16)) float deg2rad;
};
#include "gmconvert.inl"

#pragma endregion
}

#endif // GM_H