#include "stdafx.h"
#include "registers.h"
using namespace OpenGm;
//
//#ifndef _WIN64
//
//// Control registers
//__declspec(align(16))  __declspec(thread) unsigned short CWR;				// Control Word register
//__declspec(align(16)) __declspec(thread) unsigned short savedCWR;		// saved Control Word register
//
//// Masks definitions
//#define	CWR_RC		0x0c00
//#define	CWR_INVRC	0xf3ff
//#define	CWR_RC00	0x0000
//#define	CWR_RC01	0x0400
//#define	CWR_RC10	0x0800
//#define	CWR_RC11	0x0c00
//
//#define NAN_MASK	0x7f000000	// NAN if (num & NAN_MASK > NAN_MASK)
//
//__declspec(naked) void __fastcall abs2_fpu(float2& r, const float2& v)
//{
//	__asm
//	{
//		fld		dword ptr [edx]
//		fabs
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		fabs
//		fstp	dword ptr [ecx+4]
//		ret
//	}
//}
//
//__declspec(naked) void __fastcall abs3_fpu(float3& r, const float3& v)
//{
//	__asm
//	{
//		fld		dword ptr [edx]
//		fabs
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		fabs
//		fstp	dword ptr [ecx+4]
//		fld		dword ptr [edx+8]
//		fabs
//		fstp	dword ptr [ecx+8]
//		ret
//	}
//}
//
//__declspec(naked) void __fastcall abs4_fpu(float4& r, const float4& v)
//{
//	__asm
//	{
//		fld		dword ptr [edx]
//		fabs
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		fabs
//		fstp	dword ptr [ecx+4]
//		fld		dword ptr [edx+8]
//		fabs
//		fstp	dword ptr [ecx+8]
//		fld		dword ptr [edx+12]
//		fabs
//		fstp	dword ptr [ecx+12]
//		ret
//	}
//}
//
//__declspec(naked) bool	__fastcall all2_fpu(const float2& x)
//{
//	__asm
//	{
//		cmp		dword ptr [ecx], 0
//		jz		all2__fpu_false
//		cmp		dword ptr [ecx+4], 0
//		jz		all2__fpu_false
//		mov		al, 1
//		ret
//all2__fpu_false:		
//		xor		al, al
//		ret
//	}
//}
//
//__declspec(naked) bool	__fastcall all3_fpu(const float3& x)
//{
//	__asm
//	{
//		cmp		dword ptr [ecx], 0
//		jz		all3__fpu_false
//		cmp		dword ptr [ecx+4], 0
//		jz		all3__fpu_false
//		cmp		dword ptr [ecx+8], 0
//		jz		all3__fpu_false
//		mov		al, 1
//		ret
//all3__fpu_false:		
//		xor		al, al
//		ret
//	}
//}
//
//__declspec(naked) bool	__fastcall all4_fpu(const float4& x)
//{
//	__asm
//	{
//		cmp		dword ptr [ecx], 0
//		jz		all4__fpu_false
//		cmp		dword ptr [ecx+4], 0
//		jz		all4__fpu_false
//		cmp		dword ptr [ecx+8], 0
//		jz		all4__fpu_false
//		cmp		dword ptr [ecx+12], 0
//		jz		all4__fpu_false
//		mov		al, 1
//		ret
//all4__fpu_false:		
//		xor		al, al
//		ret
//	}
//}
//
//__declspec(naked) bool	__fastcall any2_fpu(const float2& x)
//{
//	__asm
//	{
//		cmp		dword ptr [ecx], 0
//		jnz		any2__fpu_true
//		cmp		dword ptr [ecx+4], 0
//		jnz		any2__fpu_true
//		xor		al, al		
//		ret
//any2__fpu_true:		
//		mov		al, 1
//		ret
//	}
//}
//
//__declspec(naked) bool	__fastcall any3_fpu(const float3& x)
//{
//	__asm
//	{
//		cmp		dword ptr [ecx], 0
//		jnz		any3__fpu_true
//		cmp		dword ptr [ecx+4], 0
//		jnz		any3__fpu_true
//		cmp		dword ptr [ecx+8], 0
//		jnz		any3__fpu_true
//		xor		al, al		
//		ret
//any3__fpu_true:		
//		mov		al, 1
//		ret
//	}
//}
//
//__declspec(naked) bool	__fastcall any4_fpu(const float4& x)
//{
//	__asm
//	{
//		cmp		dword ptr [ecx], 0
//		jnz		any4__fpu_true
//		cmp		dword ptr [ecx+4], 0
//		jnz		any4__fpu_true
//		cmp		dword ptr [ecx+8], 0
//		jnz		any4__fpu_true
//		cmp		dword ptr [ecx+12], 0
//		jnz		any4__fpu_true
//		xor		al, al		
//		ret
//any4__fpu_true:		
//		mov		al, 1
//		ret
//	}
//}
//
//__declspec(naked) void __fastcall ceil2_fpu(float2& r, const float2& v)
//{
//	__asm
//	{
//		fnstcw	word ptr [savedCWR]
//		mov		ax, word ptr [savedCWR]
//		and		ax, CWR_INVRC
//		or		ax, CWR_RC10
//		mov		word ptr [CWR], ax
//		fldcw	word ptr [CWR]
//		fld		dword ptr [edx]
//		frndint
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		frndint
//		fstp	dword ptr [ecx+4]
//		fldcw	word ptr [savedCWR]
//		ret
//	}
//}
//
//__declspec(naked) void __fastcall ceil3_fpu(float3& r, const float3& v)
//{
//	__asm
//	{
//		fnstcw	word ptr [savedCWR]
//		mov		ax, word ptr [savedCWR]
//		and		ax, CWR_INVRC
//		or		ax, CWR_RC10
//		mov		word ptr [CWR], ax
//		fldcw	word ptr [CWR]
//		fld		dword ptr [edx]
//		frndint
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		frndint
//		fstp	dword ptr [ecx+4]
//		fld		dword ptr [edx+8]
//		frndint
//		fstp	dword ptr [ecx+8]
//		fldcw	word ptr [savedCWR]
//		ret
//	}
//}
//
//__declspec(naked) void __fastcall ceil4_fpu(float4& r, const float4& v)
//{
//	__asm
//	{
//		fnstcw	word ptr [savedCWR]
//		mov		ax, word ptr [savedCWR]
//		and		ax, CWR_INVRC
//		or		ax, CWR_RC10
//		mov		word ptr [CWR], ax
//		fldcw	word ptr [CWR]
//		fld		dword ptr [edx]
//		frndint
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		frndint
//		fstp	dword ptr [ecx+4]
//		fld		dword ptr [edx+8]
//		frndint
//		fstp	dword ptr [ecx+8]
//		fld		dword ptr [edx+12]
//		frndint
//		fstp	dword ptr [ecx+12]
//		fldcw	word ptr [savedCWR]
//		ret
//	}
//}
//
//__declspec(naked) void	__fastcall cross3_fpu(float3& r, const float3& a, const float3& b)
//{
//	_asm
//	{
//		mov		eax,[esp+4]
//
//		// edx = a, eax = b, ecx = r
//		
//		// r.x = a.y*b.z - a.z*b.y;
//		fld		dword ptr [eax+8]
//		fmul	dword ptr [edx+4]
//		fld		dword ptr [edx+8]
//		fmul	dword ptr [eax+4]
//		fsubp	st(1), st(0)
//		fstp	dword ptr [ecx]
//
//		// r.y = a.z*b.x - a.x*b.z;
//		fld		dword ptr [edx+8]
//		fmul	dword ptr [eax]
//		fld		dword ptr [eax+8]
//		fmul	dword ptr [edx]
//		fsubp	st(1), st(0)
//		fstp	dword ptr [ecx+4]
//
//		// r.z = a.x*b.y - a.y*b.x;
//		fld		dword ptr [edx]
//		fmul	dword ptr [eax+4]
//		fld		dword ptr [eax]
//		fmul	dword ptr [edx+4]
//		fsubp	st(1), st(0)
//		fstp	dword ptr [ecx+8]
//
//		ret		4
//	}
//}
//
//__declspec(naked) void	__fastcall cross4_fpu(float4& r, const float4& a, const float4& b)
//{	
//	_asm
//	{
//		mov		eax,[esp+4]
//
//		// edx = a, eax = b, ecx = r
//		
//		// r.x = a.y*b.z - a.z*b.y
//		fld		dword ptr [eax+8]
//		fmul	dword ptr [edx+4]
//		fld		dword ptr [edx+8]
//		fmul	dword ptr [eax+4]
//		fsubp	st(1), st(0)
//		fstp	dword ptr [ecx]
//
//		// r.y = a.z*b.x - a.x*b.z
//		fld		dword ptr [edx+8]
//		fmul	dword ptr [eax]
//		fld		dword ptr [eax+8]
//		fmul	dword ptr [edx]
//		fsubp	st(1), st(0)
//		fstp	dword ptr [ecx+4]
//
//		// r.z = a.x*b.y - a.y*b.x & r.w = 1.0f;
//		fld		dword ptr [edx]
//		fmul	dword ptr [eax+4]
//		fld		dword ptr [eax]
//		fmul	dword ptr [edx+4]
//		mov		dword ptr [ecx+12], 0x3f800000
//		fsubp	st(1), st(0)
//		fstp	dword ptr [ecx+8]
//
//		ret		4
//	}
//}
//
//__declspec(naked) float __fastcall degrees_fpu(const float& x)
//{
//	_asm
//	{
//		fld		dword ptr [ecx]
//		fmul	dword ptr [rad2deg]
//		ret
//	}
//}
//
//__declspec(naked) float __fastcall determinant2x2_fpu(const float2x2& m)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+12]
//		fmul	dword ptr [ecx]
//		fld		dword ptr [ecx+8]
//		fmul	dword ptr [ecx+4]
//		fsubp	st(1), st(0)
//		ret
//	}
//}
//
//__declspec(naked) float __fastcall determinant3x3_fpu(const float3x3& m)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+16]
//		fmul	dword ptr [ecx+32]
//		fld		dword ptr [ecx+28]
//		fmul	dword ptr [ecx+20]
//		fsubp	st(1), st(0)
//		fmul	dword ptr [ecx]
//		fld		dword ptr [ecx+12]
//		fmul	dword ptr [ecx+32]
//		fld		dword ptr [ecx+24]
//		fmul	dword ptr [ecx+20]
//		fsubp	st(1), st(0)
//		fmul	dword ptr [ecx+4]
//		fsubp	st(1), st(0)
//		fld		dword ptr [ecx+28]
//		fmul	dword ptr [ecx+12]
//		fld		dword ptr [ecx+24]
//		fmul	dword ptr [ecx+16]
//		fsubp	st(1), st(0)
//		fmul	dword ptr [ecx+8]
//		faddp	st(1), st(0)
//		ret
//	}
//}
//
//__declspec(naked) float __fastcall determinant4x4_fpu(const float4x4& m)
//{
//	_asm
//	{
//		ret
//	}
//}
//
//__declspec(naked) float __fastcall distance2_fpu(const float2& a, const float2& b)
//{
//	_asm
//	{
//		fld		dword ptr [ecx]		; a.x
//		fsub	dword ptr [edx]		; (a.x - b.x)
//		fst		dword ptr [r0]
//		fmul	dword ptr [r0]		; (a.x - b.x)^2
//		fld		dword ptr [ecx+4]	; a.y | (a.x - b.x)^2
//		fsub	dword ptr [edx+4]	; (a.y - b.y) | (a.x - b.x)^2
//		fst		dword ptr [r0]
//		fmul	dword ptr [r0]		; (a.y - b.y)^2 |(a.x - b.x)^2
//		fadd
//		fsqrt
//		ret
//	}
//}
//
//__declspec(naked) float __fastcall distance3_fpu(const float3& a, const float3& b)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+4]
//		fsub	dword ptr [edx+4]
//		fld		dword ptr [ecx]
//		fsub	dword ptr [edx]
//		fld		st(0)
//		fmul	st(0), st(1)
//		fld		st(2)
//		fmul	st(0), st(3)
//		fadd	st(0), st(0)
//		faddp	st(1), st(0)
//		fsqrt
//		fstp	st(2)
//		fstp	st(0)
//		ret
//	}
//}
//
//__declspec(naked) float __fastcall distance4_fpu(const float4& a, const float4& b)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+4]
//		fsub	dword ptr [edx+4]
//		fld		dword ptr [ecx]
//		fsub	dword ptr [edx]
//		fld		st(0)
//		fmul	st(0), st(1)
//		fld		st(2)
//		fmul	st(0), st(3)
//		fadd	st(0), st(0)
//		faddp	st(1), st(0)
//		fsqrt
//		fstp	st(2)
//		fstp	st(0)
//		ret
//	}
//}
//
//__declspec(naked) void	__fastcall dst_fpu(float4& r, const float& d)
//{
//	_asm
//	{
//		fld		dword ptr [edx]				// d
//		fld		dword ptr [edx]				// d | d
//		fld		st(0)						// d | d | d
//		fmulp	st(1), st(0)				// d*d | d
//		fld1								// 1.0f | d | d*d | d
//		fdiv	dword ptr [edx]				// 1.0f/d | d | d*d | d
//		mov		dword ptr [ecx], 1065353216 // r.x = 1
//		fstp	dword ptr [ecx+12]			// r.w = 1.0f/d
//		fstp	dword ptr [ecx+8]			// d*d | d
//		fstp	dword ptr [ecx+4]			// d
//		fincstp
//		ret
//	}
//}
//
//__declspec(naked) float	__fastcall dot2_fpu(const float2& a, const float2& b)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+4]
//		fmul	dword ptr [edx+4]
//		fld		dword ptr [ecx]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		ret
//	}
//}
//
//__declspec(naked) float	__fastcall dot3_fpu(const float3& a, const float3& b)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+8]
//		fmul	dword ptr [edx+8]
//		fld		dword ptr [ecx+4]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [ecx]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		ret
//	}
//}
//
//__declspec(naked) float	__fastcall dot4_fpu(const float4& a, const float4& b)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+8]
//		fmul	dword ptr [edx+8]
//		fld		dword ptr [ecx+4]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [ecx]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		ret
//	}
//}
//
///*__declspec(naked) float __fastcall *PMT_FACEFORWARD2(float& n, float2& i, float2& ng)
//{
//	return 0.0f;
//}
//
//__declspec(naked) float __fastcall *PMT_FACEFORWARD3(float& n, float3& i, float3& ng)
//{
//	return 0.0f;
//}
//
//__declspec(naked) float __fastcall *PMT_FACEFORWARD4(float& n, float4& i, float4& ng)
//{
//	return 0.0f;
//}*/
//
//__declspec(naked) void __fastcall floor2_fpu(float2& r, const float2& x)
//{
//	_asm
//	{
//		fnstcw	word ptr [savedCWR]
//		mov		ax, word ptr [savedCWR]
//		and		ax, CWR_INVRC
//		or		ax, CWR_RC01
//		mov		word ptr [CWR], ax
//		fldcw	word ptr [CWR]
//		fld		dword ptr [edx]
//		frndint
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		frndint
//		fstp	dword ptr [ecx+4]
//		fldcw	word ptr [savedCWR]
//		ret
//	}
//}
//
//__declspec(naked) void __fastcall floor3_fpu(float3& r, const float3& v)
//{
//	__asm
//	{
//		fnstcw	word ptr [savedCWR]
//		mov		ax, word ptr [savedCWR]
//		and		ax, CWR_INVRC
//		or		ax, CWR_RC01
//		mov		word ptr [CWR], ax
//		fldcw	word ptr [CWR]
//		fld		dword ptr [edx]
//		frndint
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		frndint
//		fstp	dword ptr [ecx+4]
//		fld		dword ptr [edx+8]
//		frndint
//		fstp	dword ptr [ecx+8]
//		fldcw	word ptr [savedCWR]
//		ret
//	}
//}
//
//__declspec(naked) void __fastcall floor4_fpu(float4& r, const float4& v)
//{
//	__asm
//	{
//		fnstcw	word ptr [savedCWR]
//		mov		ax, word ptr [savedCWR]
//		and		ax, CWR_INVRC
//		or		ax, CWR_RC01
//		mov		word ptr [CWR], ax
//		fldcw	word ptr [CWR]
//		fld		dword ptr [edx]
//		frndint
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		frndint
//		fstp	dword ptr [ecx+4]
//		fld		dword ptr [edx+8]
//		frndint
//		fstp	dword ptr [ecx+8]
//		fld		dword ptr [edx+12]
//		frndint
//		fstp	dword ptr [ecx+12]
//		fldcw	word ptr [savedCWR]
//		ret
//	}
//}
//
//__declspec(naked) float __fastcall length2_fpu(const float2& x)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+4]
//		fld		dword ptr [ecx]
//		fld		st(0)
//		fmul	st(0), st(1)
//		fld		st(2)
//		fmul	st(0), st(3)
//		faddp	st(1), st(0)
//		fsqrt
//		fstp	st(2)
//		fstp	st(0)
//		ret
//	}
//}
//
//__declspec(naked) float __fastcall length3_fpu(const float3& x)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+8]
//		fld		dword ptr [ecx+4]
//		fld		dword ptr [ecx]
//		fld		st(0)
//		fmul	st(0), st(1)
//		fld		st(2)
//		fmul	st(0), st(3)
//		faddp	st(1), st(0)
//		fld		st(3)
//		fmul	st(0), st(4)
//		faddp	st(1), st(0)
//		fsqrt
//		fstp	st(3)
//		fstp	st(0)
//		fstp	st(0)
//		ret
//	}
//}
//
//__declspec(naked) float __fastcall length4_fpu(const float4& x)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+8]
//		fld		dword ptr [ecx+4]
//		fld		dword ptr [ecx]
//		fld		st(0)
//		fmul	st(0), st(1)
//		fld		st(2)
//		fmul	st(0), st(3)
//		faddp	st(1), st(0)
//		fld		st(3)
//		fmul	st(0), st(4)
//		faddp	st(1), st(0)
//		fsqrt
//		fstp	st(3)
//		fstp	st(0)
//		fstp	st(0)
//		ret
//	}
//}
//
///*__declspec(naked) float __fastcall *PMT_LERP(float& a, float& b, float& s)
//{
//	return 0.0f;
//}
//
//__declspec(naked) void	__fastcall *PMT_LERP2(float2& r, float2& a, float2& b, float& s)
//{
//
//}
//
//__declspec(naked) void	__fastcall *PMT_LERP3(float3& r, float3& a, float3& b, float& s)
//{
//
//}
//
//__declspec(naked) void	__fastcall *PMT_LERP4(float4& r, float4& a, float4& b, float& s)
//{
//
//}
//
//__declspec(naked) float __fastcall *PMT_MAD(float& a, float& s, float& b)
//{
//	return 0.0f;
//}
//
//__declspec(naked) void	__fastcall *PMT_MAD2(float2& r, float2& a, float2& s, float2& b)
//{
//
//}
//
//__declspec(naked) void	__fastcall *PMT_MAD3(float3& r, float3& a, float3& s, float3& b)
//{
//
//}
//
//__declspec(naked) void	__fastcall *PMT_MAD4(float4& r, float4& a, float4& s, float4& b)
//{
//
//}*/
//
//__declspec(naked) void	__fastcall mul2x2_fpu(float2x2& r, const float2x2& a, const float2x2& b)
//{
//	_asm
//	{
//		mov		eax, dword ptr [esp+4]
//		fld		dword ptr [edx]
//		fmul	dword ptr [eax]
//		fld		dword ptr [eax+4]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx]
//
//		fld		dword ptr [edx+4]
//		fmul	dword ptr [eax]
//		fld		dword ptr [edx+12]
//		fmul	dword ptr [eax+4]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+4]
//
//		fld		dword ptr [eax+8]
//		fmul	dword ptr [edx]
//		fld		dword ptr [eax+12]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+8]
//
//		fld		dword ptr [edx+12]
//		fmul	dword ptr [eax+12]
//		fld		dword ptr [edx+4]
//		fmul	dword ptr [eax+8]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+12]
//		ret	4
//	}
//}
//
//__declspec(naked) void	__fastcall mul3x3_fpu(float3x3& r, const float3x3& a, const float3x3& b)
//{
//	_asm
//	{
//		mov		eax, dword ptr [esp+4]
//		fld		dword ptr [edx+12]
//		fmul	dword ptr [eax+4]
//		fld		dword ptr [edx]
//		fmul	dword ptr [eax]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+8]
//		fmul	dword ptr [edx+24]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx]
//
//		fld		dword ptr [edx+16]
//		fmul	dword ptr [eax+4]
//		fld		dword ptr [edx+28]
//		fmul	dword ptr [eax+8]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+4]
//		fmul	dword ptr [eax]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+4]
//
//		fld		dword ptr [edx+20]
//		fmul	dword ptr [eax+4]
//		fld		dword ptr [edx+32]
//		fmul	dword ptr [eax+8]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+8]
//		fmul	dword ptr [eax]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+8]
//
//		fld		dword ptr [edx+12]
//		fmul	dword ptr [eax+16]
//		fld		dword ptr [eax+20]
//		fmul	dword ptr [edx+24]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+12]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+12]
//
//		fld		dword ptr [edx+28]
//		fmul	dword ptr [eax+20]
//		fld		dword ptr [edx+16]
//		fmul	dword ptr [eax+16]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+4]
//		fmul	dword ptr [eax+12]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+16]
//
//		fld		dword ptr [edx+32]
//		fmul	dword ptr [eax+20]
//		fld		dword ptr [edx+20]
//		fmul	dword ptr [eax+16]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+8]
//		fmul	dword ptr [eax+12]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+20]
//
//		fld		dword ptr [edx+12]
//		fmul	dword ptr [eax+28]
//		fld		dword ptr [eax+24]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fld		dword ptr  [edx+24]
//		fmul	dword ptr [eax+32]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+24]
//
//		fld		dword ptr [edx+28]
//		fmul	dword ptr [eax+32]
//		fld		dword ptr [edx+16]
//		fmul	dword ptr [eax+28]
//		faddp	st(1), st(0)
//		fld		dword ptr  [edx+4]
//		fmul	dword ptr [eax+24]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+28]
//
//		fld		dword ptr [edx+32]
//		fmul	dword ptr [eax+32]
//		fld		dword ptr [edx+20]
//		fmul	dword ptr [eax+28]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+8]
//		fmul	dword ptr [eax+24]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+32]
//		ret	4
//	}
//}
//
//__declspec(naked) void	__fastcall mul4x4_fpu(float4x4& r, const float4x4& a, const float4x4& b)
//{
//	_asm
//	{
//		mov		eax, dword ptr [esp+4]
//		fld		dword ptr [edx+32]
//		fmul	dword ptr [eax+8]
//		fld		dword ptr [edx+16]
//		fmul	dword ptr [eax+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx]
//		fmul	dword ptr [eax]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+12]
//		fmul	dword ptr [edx+48]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx]
//
//		fld		dword ptr [edx+20]
//		fmul	dword ptr [eax+4]
//		fld		dword ptr [edx+36]
//		fmul	dword ptr [eax+8]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+52]
//		fmul	dword ptr [eax+12]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+4]
//
//		fld		dword ptr [edx+40]
//		fmul	dword ptr [eax+8]
//		fld		dword ptr [edx+8]
//		fmul	dword ptr [eax]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+56]
//		fmul	dword ptr [eax+12]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+24]
//		fmul	dword ptr [eax+4]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+8]
//
//		fld		dword ptr [edx+12]
//		fmul	dword ptr [eax]
//		fld		dword ptr [eax+12]
//		fmul	dword ptr [edx+60]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+28]
//		fmul	dword ptr [eax+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+44]
//		fmul	dword ptr [eax+8]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+12]
//
//		fld		dword ptr [edx+16]
//		fmul	dword ptr [eax+20]
//		fld		dword ptr [eax+28]
//		fmul	dword ptr [edx+48]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+32]
//		fmul	dword ptr [eax+24]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+16]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+16]
//	
//		fld		dword ptr [edx+20]
//		fmul	dword ptr [eax+20]
//		fld		dword ptr [eax+16]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+52]
//		fmul	dword ptr [eax+28]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+36]
//		fmul	dword ptr [eax+24]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+20]
//
//		fld		dword ptr [eax+20]
//		fmul	dword ptr [edx+24]
//		fld		dword ptr [eax+16]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+56]
//		fmul	dword ptr [eax+28]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+40]
//		fmul	dword ptr [eax+24]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+24]
//
//		fld		dword ptr [eax+16]
//		fmul	dword ptr [edx+12]
//		fld		dword ptr [eax+28]
//		fmul	dword ptr [edx+60]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+24]
//		fmul	dword ptr [edx+44]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+20]
//		fmul	dword ptr [edx+28]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+28]
//
//		fld		dword ptr [edx+16]
//		fmul	dword ptr [eax+36]
//		fld		dword ptr [eax+44]
//		fmul	dword ptr [edx+48]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+32]
//		fmul	dword ptr [eax+40]
//		faddp	st(1), st(0)
//		fld		dword ptr  [eax+32]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+32]
//
//		fld		dword ptr [edx+20]
//		fmul	dword ptr [eax+36]
//		fld		dword ptr [eax+32]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+52]
//		fmul	dword ptr [eax+44]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+36]
//		fmul	dword ptr [eax+40]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+36]
//
//		fld		dword ptr [eax+36]
//		fmul	dword ptr [edx+24]
//		fld		dword ptr [edx+56]
//		fmul	dword ptr [eax+44]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+40]
//		fmul	dword ptr [eax+40]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+32]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+40]
//
//		fld		dword ptr [eax+32]
//		fmul	dword ptr [edx+12]
//		fld		dword ptr [eax+44]
//		fmul	dword ptr [edx+60]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+40]
//		fmul	dword ptr [edx+44]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+36]
//		fmul	dword ptr [edx+28]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+44]
//
//		fld		dword ptr [edx+16]
//		fmul	dword ptr [eax+52]
//		fld		dword ptr [eax+60]
//		fmul	dword ptr [edx+48]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+56]
//		fmul	dword ptr [edx+32]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+48]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+48]
//
//		fld		dword ptr [eax+56]
//		fmul	dword ptr [edx+36]
//		fld		dword ptr [eax+48]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+20]
//		fmul	dword ptr [eax+52]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+52]
//		fmul	dword ptr [eax+60]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+52]
//
//		fld		dword ptr [eax+52]
//		fmul	dword ptr [edx+24]
//		fld		dword ptr [edx+56]
//		fmul	dword ptr [eax+60]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+40]
//		fmul	dword ptr [eax+56]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+48]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+56]
//
//		fld		dword ptr [eax+48]
//		fmul	dword ptr [edx+12]
//		fld		dword ptr [eax+56]
//		fmul	dword ptr [edx+44]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+60]
//		fmul	dword ptr [edx+60]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+52]
//		fmul	dword ptr [edx+28]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+60]
//		ret	4
//	}
//}
//
//__declspec(naked) void	__fastcall mul2_fpu(float2& r, const float2& a, const float2x2& b)
//{
//	__asm
//	{
//		mov		eax, dword ptr [esp+4]
//		fld		dword ptr [eax+8]
//		fmul	dword ptr [edx+4]
//		fld		dword ptr [edx]
//		fmul	dword ptr [eax]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx]
//
//		fld		dword ptr [eax+4]
//		fmul	dword ptr [edx]
//		fld		dword ptr [eax+12]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+4]
//		ret	4
//	}
//}
//
//__declspec(naked) void	__fastcall mul3_fpu(float3& r, const float3& a, const float3x3& b)
//{
//	_asm
//	{
//		mov		eax, dword ptr [esp+4]
//		fld		dword ptr [eax+12]
//		fmul	dword ptr [edx+4]
//		fld		dword ptr [eax+24]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx]
//		fmul	dword ptr [eax]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx]
//
//		fld		dword ptr [eax+16]
//		fmul	dword ptr [edx+4]
//		fld		dword ptr [eax+4]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+28]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+4]
//
//		fld		dword ptr [eax+20]
//		fmul	dword ptr [edx+4]
//		fld		dword ptr [eax+8]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+32]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+8]
//		ret	4
//	}
//}
//
//__declspec(naked) void	__fastcall mul4_fpu(float4& r, const float4& a, const float4x4& b)
//{
//	_asm
//	{
//		mov		eax, dword ptr  [esp+4]
//		fld		dword ptr [eax+48]
//		fmul	dword ptr [edx+12]
//		fld		dword ptr [eax+16]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+32]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx]
//		fmul	dword ptr [eax]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx]
//
//		fld		dword ptr [eax+52]
//		fmul	dword ptr [edx+12]
//		fld		dword ptr [eax+20]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+4]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+36]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+4]
//
//		fld		dword ptr [eax+56]
//		fmul	dword ptr [edx+12]
//		fld		dword ptr [eax+40]
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+8]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+4]
//		fmul	dword ptr [eax+24]
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+8]
//
//		fld		dword ptr [eax+60]
//		fmul	dword ptr [edx+12]
//		fld		dword ptr [eax+44] // FIXME: was +40
//		fmul	dword ptr [edx+8]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+16] // FIXME: was +8
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx+4]
//		fmul	dword ptr [eax+28] // FIXME: was +24
//		faddp	st(1), st(0)
//		fstp	dword ptr [ecx+12]
//		ret	4
//	}
//}
//
//__declspec(naked) void	__fastcall mul43_fpu(float3& r, const float3& v, const float4x4& b)
//{
//	_asm
//	{		
//		mov		eax, dword ptr  [esp+4]	
//		fld		dword ptr [eax+32]
//		fmul	dword ptr [edx+8]
//		fld		dword ptr [eax+16]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [edx]
//		fmul	dword ptr [eax]
//		faddp	st(1), st(0)
//		fadd	dword ptr [eax+48]
//		fstp	dword ptr [ecx]
//
//		fld		dword ptr [eax+36]
//		fmul	dword ptr [edx+8]
//		fld		dword ptr [eax+20]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+4]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fadd	dword ptr [eax+52]
//		fstp	dword ptr [ecx+4]
//
//		fld		dword ptr [eax+40]
//		fmul	dword ptr [edx+8]
//		fld		dword ptr [eax+24]
//		fmul	dword ptr [edx+4]
//		faddp	st(1), st(0)
//		fld		dword ptr [eax+8]
//		fmul	dword ptr [edx]
//		faddp	st(1), st(0)
//		fadd	dword ptr [eax+56]
//		fstp	dword ptr [ecx+8]
//
//		ret	4
//	}
//}
//
//__declspec(naked) void	__fastcall normalize2_fpu(float2& v)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+4]
//		fld		dword ptr [ecx]
//		fld		st(0)
//		fmul	st(0), st(1)
//		fld		st(2)
//		fmul	st(0), st(3)
//		faddp	st(1), st(0)
//		fsqrt
//		fstp	st(2)
//		fstp	st(0)
//		fdivr	dword ptr _1_00
//		fst		dword ptr r0
//		fmul	dword ptr [ecx]
//		fstp	dword ptr [ecx]
//		fld		dword ptr r0
//		fmul	dword ptr [ecx+4]
//		fstp	dword ptr [ecx+4]
//		ret
//	}
//}
//
//__declspec(naked) void	_fastcall normalize3_fpu(float3& v)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+8]
//		fld		dword ptr [ecx+4]
//		fld		dword ptr [ecx]
//		fld		st(0)
//		fmul	st(0), st(1)
//		fld		st(2)
//		fmul	st(0), st(3)
//		faddp	st(1), st(0)
//		fld		st(3)
//		fmul	st(0), st(4)
//		faddp	st(1), st(0)
//		fsqrt
//		fstp	st(3)
//		fstp	st(0)
//		fstp	st(0)
//		fdivr	dword ptr _1_00
//		fst		dword ptr r0
//		fmul	dword ptr [ecx]
//		fstp	dword ptr [ecx]
//		fld		dword ptr r0
//		fmul	dword ptr [ecx+4]
//		fstp	dword ptr [ecx+4]
//		fld		dword ptr r0
//		fmul	dword ptr [ecx+8]
//		fstp	dword ptr [ecx+8]
//		ret
//	}
//}
//
//__declspec(naked) void	_fastcall normalize4_fpu(float4& v)
//{
//	_asm
//	{
//		fld		dword ptr [ecx+8]
//		fld		dword ptr [ecx+4]
//		fld		dword ptr [ecx]
//		fld		st(0)
//		fmul	st(0), st(1)
//		fld		st(2)
//		fmul	st(0), st(3)
//		faddp	st(1), st(0)
//		fld		st(3)
//		fmul	st(0), st(4)
//		faddp	st(1), st(0)
//		fsqrt
//		fstp	st(3)
//		fstp	st(0)
//		fstp	st(0)
//		fdivr	dword ptr _1_00
//		fst		dword ptr r0
//		fmul	dword ptr [ecx]
//		fstp	dword ptr [ecx]
//		fld		dword ptr r0
//		fmul	dword ptr [ecx+4]
//		fstp	dword ptr [ecx+4]
//		fld		dword ptr r0
//		fmul	dword ptr [ecx+8]
//		fstp	dword ptr [ecx+8]
//		ret
//	}
//}
//
///*__declspec(naked) void	__fastcall *PMT_NORMAL(float3& r, float3& a, float3& b, float3& c)
//{
//
//}*/
//
//__declspec(naked) float __fastcall radians_fpu(const float& x)
//{
//	_asm
//	{
//		fld		dword ptr [ecx]
//		fmul	dword ptr [deg2rad]
//		ret
//	}
//}
//
///*__declspec(naked) void	__fastcall *PMT_REFLECT2(float4& r, float2& i, float2& n)
//{
//	mov	eax, DWORD PTR _n$[ebp]
//	fld	DWORD PTR [eax]
//	fadd	ST(0), ST(0)
//	fld	DWORD PTR [eax+4]
//	fadd	ST(0), ST(0)
//	fld	DWORD PTR [edx]
//	fmul	DWORD PTR [eax]
//	fld	DWORD PTR [edx+4]
//	fmul	DWORD PTR [eax+4]
//	faddp	ST(1), ST(0)
//	fld	ST(2)
//	fmul	ST(0), ST(1)
//	fstp	DWORD PTR $T4827[ebp]
//	fld	ST(1)
//	fmul	ST(0), ST(1)
//	fstp	DWORD PTR $T4827[ebp+4]
//	fstp	ST(0)
//	fstp	ST(0)
//	fstp	ST(0)
//	fld	DWORD PTR [edx]
//	fsub	DWORD PTR $T4827[ebp]
//	fld	DWORD PTR [edx+4]
//	fsub	DWORD PTR $T4827[ebp+4]
//	fld	ST(1)
//	fstp	DWORD PTR [ecx]
//	fstp	DWORD PTR [ecx+4]
//	fstp	ST(0)
//}
//
///*__declspec(naked) void	__fastcall *PMT_REFLECT3(float4& r, float3& i, float3& n)
//{
//
//}
//
//__declspec(naked) void	__fastcall *PMT_REFLECT4(float4& r, float4& i, float4& n)
//{
//
//}
//
//__declspec(naked) void	__fastcall *PMT_REFRACT2(float4& r, float2& i, float2& n, float& eta)
//{
//
//}
//
//__declspec(naked) void	__fastcall *PMT_REFRACT3(float4& r, float3& i, float3& n, float& eta)
//{
//
//}
//
//__declspec(naked) void	__fastcall *PMT_REFRACT4(float4& r, float4& i, float4& n, float& eta)
//{
//
//}*/
//
//__declspec(naked) void __fastcall round2_fpu(float2& r, const float2& v)
//{
//	__asm
//	{
//		fnstcw	word ptr [savedCWR]
//		mov		ax, word ptr [savedCWR]
//		and		ax, CWR_INVRC
//		or		ax, CWR_RC00
//		mov		word ptr [CWR], ax
//		fldcw	word ptr [CWR]
//		fld		dword ptr [edx]
//		frndint
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		frndint
//		fstp	dword ptr [ecx+4]
//		fldcw	word ptr [savedCWR]
//		ret
//	}
//}
//
//__declspec(naked) void __fastcall round3_fpu(float3& r, const float3& v)
//{
//	__asm
//	{
//		fnstcw	word ptr [savedCWR]
//		mov		ax, word ptr [savedCWR]
//		and		ax, CWR_INVRC
//		or		ax, CWR_RC00
//		mov		word ptr [CWR], ax
//		fldcw	word ptr [CWR]
//		fld		dword ptr [edx]
//		frndint
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		frndint
//		fstp	dword ptr [ecx+4]
//		fld		dword ptr [edx+8]
//		frndint
//		fstp	dword ptr [ecx+8]
//		fldcw	word ptr [savedCWR]
//		ret
//	}
//}
//
//__declspec(naked) void __fastcall round4_fpu(float4& r, const float4& v)
//{
//	__asm
//	{
//		fnstcw	word ptr [savedCWR]
//		mov		ax, word ptr [savedCWR]
//		and		ax, CWR_INVRC
//		or		ax, CWR_RC00
//		mov		word ptr [CWR], ax
//		fldcw	word ptr [CWR]
//		fld		dword ptr [edx]
//		frndint
//		fstp	dword ptr [ecx]
//		fld		dword ptr [edx+4]
//		frndint
//		fstp	dword ptr [ecx+4]
//		fld		dword ptr [edx+8]
//		frndint
//		fstp	dword ptr [ecx+8]
//		fld		dword ptr [edx+12]
//		frndint
//		fstp	dword ptr [ecx+12]
//		fldcw	word ptr [savedCWR]
//		ret
//	}
//}
//
//__declspec(naked) void	__fastcall transpose2x2_fpu(float2x2& r, const float2x2& m)
//{
//	_asm
//	{
//		mov		eax, dword ptr [edx]		
//		mov		dword ptr [ecx], eax		
//		mov		eax, dword ptr [edx+4]
//		mov		dword ptr [ecx+8], eax
//		mov		eax, dword ptr [edx+8]		
//		mov		dword ptr [ecx+4], eax
//		mov		eax, dword ptr [edx+12]
//		mov		dword ptr [ecx+12], eax
//		ret
//	}
//}
//
//__declspec(naked) void	__fastcall transpose3x3_fpu(float3x3& r, const float3x3& m)
//{
//	_asm
//	{
//		mov		eax, dword ptr [edx]
//		mov		dword ptr [ecx], eax
//		mov		eax, dword ptr [edx+12]
//		mov		dword ptr [ecx+4], eax
//		mov		eax, dword ptr [edx+24]
//		mov		dword ptr [ecx+8], eax
//		mov		eax, dword ptr [edx+4]
//		mov		dword ptr [ecx+12], eax
//		mov		eax, dword ptr [edx+16]
//		mov		dword ptr [ecx+16], eax
//		mov		eax, dword ptr [edx+28]
//		mov		dword ptr [ecx+20], eax
//		mov		eax, dword ptr [edx+8]
//		mov		dword ptr [ecx+24], eax
//		mov		eax, dword ptr [edx+20]
//		mov		dword ptr [ecx+28], eax
//		mov		eax, dword ptr [edx+32]
//		mov		dword ptr [ecx+32], eax
//		ret
//	}
//}
//
//__declspec(naked) void	__fastcall transpose4x4_fpu(float4x4& r, const float4x4& m)
//{
//	_asm
//	{
//		mov		eax, dword ptr [edx]
//		mov		dword ptr [ecx], eax
//		mov		eax, dword ptr [edx+16]
//		mov		dword ptr [ecx+4], eax
//		mov		eax, dword ptr [edx+32]
//		mov		dword ptr [ecx+8], eax
//		mov		eax, dword ptr [edx+48]
//		mov		dword ptr [ecx+12], eax
//		mov		eax, dword ptr [edx+4]
//		mov		dword ptr [ecx+16], eax
//		mov		eax, dword ptr [edx+20]
//		mov		dword ptr [ecx+20], eax
//		mov		eax, dword ptr [edx+36]
//		mov		dword ptr [ecx+24], eax
//		mov		eax, dword ptr [edx+52]
//		mov		dword ptr [ecx+28], eax
//		mov		eax, dword ptr [edx+8]
//		mov		dword ptr [ecx+32], eax
//		mov		eax, dword ptr [edx+24]
//		mov		dword ptr [ecx+36], eax
//		mov		eax, dword ptr [edx+40]
//		mov		dword ptr [ecx+40], eax
//		mov		eax, dword ptr [edx+56]
//		mov		dword ptr [ecx+44], eax
//		mov		eax, dword ptr [edx+12]
//		mov		dword ptr [ecx+48], eax
//		mov		eax, dword ptr [edx+28]
//		mov		dword ptr [ecx+52], eax
//		mov		eax, dword ptr [edx+44]
//		mov		dword ptr [ecx+56], eax
//		mov		eax, dword ptr [edx+60]
//		mov		dword ptr [ecx+60], eax
//		ret
//	}
//}
//
///// <summary>
///// Заполняет таблицу функций реализациями на FPU.
///// </summary>
//void FillFuncTable_FPU()
//{
//	abs2 = abs2_fpu;
//	abs3 = abs3_fpu;
//	abs4 = abs4_fpu;
//	all2 = all2_fpu;
//	all3 = all3_fpu;
//	all4 = all4_fpu;
//	any2 = any2_fpu;
//	any3 = any3_fpu;
//	any4 = any4_fpu;
//	ceil2 = ceil2_fpu;
//	ceil3 = ceil3_fpu;
//	ceil4 = ceil4_fpu;
//	cross3 = cross3_fpu;
//	cross4 = cross4_fpu;
//	degrees = degrees_fpu;
//	determinant2x2 = determinant2x2_fpu;
//	determinant3x3 = determinant3x3_fpu;
//	distance2 = distance2_fpu;
//	distance3 = distance3_fpu;
//	distance4 = distance4_fpu;
//	dst = dst_fpu;
//	dot2 = dot2_fpu;
//	dot3 = dot3_fpu;
//	dot4 = dot4_fpu;
//
//	floor2	= floor2_fpu;
//	floor3	= floor3_fpu;
//	floor4	= floor4_fpu;
//
//	length2 = length2_fpu;
//	length3 = length3_fpu;
//	length4 = length4_fpu;
//
//	mul2x2 = mul2x2_fpu;
//	mul3x3 = mul3x3_fpu;
//	mul4x4 = mul4x4_fpu;
//
//	mul2 = mul2_fpu;
//	mul3 = mul3_fpu;
//	mul4 = mul4_fpu;
//	mul43= mul43_fpu;
//
//	normalize2 = normalize2_fpu;
//	normalize3 = normalize3_fpu;
//	normalize4 = normalize4_fpu;
//
//	radians = radians_fpu;
//	round2	= round2_fpu;
//	round3	= round3_fpu;
//	round4	= round4_fpu;	
//
//	transpose2x2 = transpose2x2_fpu;
//	transpose3x3 = transpose3x3_fpu;
//	transpose4x4 = transpose4x4_fpu;
//}
//#endif