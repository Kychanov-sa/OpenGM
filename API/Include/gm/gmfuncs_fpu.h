/// <summary>
/// OpenGM library FPU functions.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>24-02-2019</created>
/// <copyright>Copyright 2004-2019 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifdef GMFUNCS_FPU_H
#error Nested inclusion of gmfuncs_fpu.h
#else
#define GMFUNCS_FPU_H
#endif

GMAPI float2 FASTCALL abs2_fpu(const float2& v);
GMAPI float3 FASTCALL abs3_fpu(const float3& v);
GMAPI float4 FASTCALL abs4_fpu(const float4& v);
GMAPI bool FASTCALL all2_fpu(const float2& x);
GMAPI bool FASTCALL all3_fpu(const float3& x);
GMAPI bool FASTCALL all4_fpu(const float4& x);
GMAPI bool FASTCALL any2_fpu(const float2& x);
GMAPI bool FASTCALL any3_fpu(const float3& x);
GMAPI bool FASTCALL any4_fpu(const float4& x);
GMAPI float2 FASTCALL ceil2_fpu(const float2& v);
GMAPI float3 FASTCALL ceil3_fpu(const float3& v);
GMAPI float4 FASTCALL ceil4_fpu(const float4& v);
GMAPI float3 FASTCALL cross3_fpu(const float3& a, const float3& b);
GMAPI float4 FASTCALL cross4_fpu(const float4& a, const float4& b);
GMAPI float FASTCALL degrees_fpu(const float& x);
GMAPI float FASTCALL determinant2x2_fpu(const float2x2& m);
GMAPI float FASTCALL determinant3x3_fpu(const float3x3& m);
GMAPI float FASTCALL determinant4x4_fpu(const float4x4& m);
GMAPI float FASTCALL distance2_fpu(const float2& a, const float2& b);
GMAPI float FASTCALL distance3_fpu(const float3& a, const float3& b);
GMAPI float FASTCALL distance4_fpu(const float4& a, const float4& b);
GMAPI float4 FASTCALL dst_fpu(const float& d);
GMAPI float FASTCALL dot2_fpu(const float2& a, const float2& b);
GMAPI float FASTCALL dot3_fpu(const float3& a, const float3& b);
GMAPI float FASTCALL dot4_fpu(const float4& a, const float4& b);
GMAPI float2 FASTCALL faceforward2_fpu(const float2& n, const float2& i, const float2& ng);
GMAPI float3 FASTCALL faceforward3_fpu(const float3& n, const float3& i, const float3& ng);
GMAPI float4 FASTCALL faceforward4_fpu(const float4& n, const float4& i, const float4& ng);
GMAPI float2 FASTCALL floor2_fpu(const float2& x);
GMAPI float3 FASTCALL floor3_fpu(const float3& x);
GMAPI float4 FASTCALL floor4_fpu(const float4& x);
GMAPI float2x2 FASTCALL inverse2x2_fpu(const float2x2& m);
GMAPI float3x3 FASTCALL inverse3x3_fpu(const float3x3& m);
GMAPI float4x4 FASTCALL inverse4x4_fpu(const float4x4& m);
GMAPI float FASTCALL length2_fpu(const float2& x);
GMAPI float FASTCALL length3_fpu(const float3& x);
GMAPI float FASTCALL length4_fpu(const float4& x);
GMAPI float2 FASTCALL lerp2_fpu(const float2& a, const float2& b, const float& s);
GMAPI float3 FASTCALL lerp3_fpu(const float3& a, const float3& b, const float& s);
GMAPI float4 FASTCALL lerp4_fpu(const float4& a, const float4& b, const float& s);
GMAPI float2 FASTCALL mad2_fpu(const float2& a, const float& s, const float2& b);
GMAPI float3 FASTCALL mad3_fpu(const float3& a, const float& s, const float3& b);
GMAPI float4 FASTCALL mad4_fpu(const float4& a, const float& s, const float4& b);
GMAPI float2x2 FASTCALL mul2x2_fpu(const float2x2& a, const float2x2& b);
GMAPI float3x3 FASTCALL mul3x3_fpu(const float3x3& a, const float3x3& b);
GMAPI float4x4 FASTCALL mul4x4_fpu(const float4x4& a, const float4x4& b);
GMAPI float2 FASTCALL mul2_fpu(const float2& a, const float2x2& b);
GMAPI float3 FASTCALL mul3_fpu(const float3& a, const float3x3& b);
GMAPI float4 FASTCALL mul4_fpu(const float4& a, const float4x4& b);
GMAPI float3 FASTCALL mul43_fpu(const float3& v, const float4x4& b);
GMAPI float2 FASTCALL normalize2_fpu(const float2& v);
GMAPI float3 FASTCALL normalize3_fpu(const float3& v);
GMAPI float4 FASTCALL normalize4_fpu(const float4& v);
GMAPI float3 FASTCALL normal3_fpu(const float3& a, const float3& b, const float3& c);
GMAPI float FASTCALL radians_fpu(const float& x);
GMAPI float2 FASTCALL reflect2_fpu(const float2& i, const float2& n);
GMAPI float3 FASTCALL reflect3_fpu(const float3& i, const float3& n);
GMAPI float4 FASTCALL reflect4_fpu(const float4& i, const float4& n);
GMAPI float2 FASTCALL refract2_fpu(const float2& i, const float2& n, const float& eta);
GMAPI float3 FASTCALL refract3_fpu(const float3& i, const float3& n, const float& eta);
GMAPI float4 FASTCALL refract4_fpu(const float4& i, const float4& n, const float& eta);
GMAPI float2 FASTCALL round2_fpu(const float2& x);
GMAPI float3 FASTCALL round3_fpu(const float3& x);
GMAPI float4 FASTCALL round4_fpu(const float4& x);
GMAPI float2x2 FASTCALL transpose2x2_fpu(const float2x2& m);
GMAPI float3x3 FASTCALL transpose3x3_fpu(const float3x3& m);
GMAPI float4x4 FASTCALL transpose4x4_fpu(const float4x4& m);