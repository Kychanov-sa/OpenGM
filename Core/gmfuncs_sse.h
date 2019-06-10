/// <summary>
/// OpenGM library SSE functions.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>24-02-2019</created>
/// <copyright>Copyright 2004-2019 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifdef GMFUNCS_SSE_H
#error Nested inclusion of gmfuncs_sse.h
#else
#define GMFUNCS_SSE_H
#endif

GMAPI float2 FASTCALL abs2_sse(const float2& v);
GMAPI float3 FASTCALL abs3_sse(const float3& v);
GMAPI float4 FASTCALL abs4_sse(const float4& v);
GMAPI bool FASTCALL all2_sse(const float2& x);
GMAPI bool FASTCALL all3_sse(const float3& x);
GMAPI bool FASTCALL all4_sse(const float4& x);
GMAPI bool FASTCALL any2_sse(const float2& x);
GMAPI bool FASTCALL any3_sse(const float3& x);
GMAPI bool FASTCALL any4_sse(const float4& x);
GMAPI float2 FASTCALL ceil2_sse(const float2& v);
GMAPI float3 FASTCALL ceil3_sse(const float3& v);
GMAPI float4 FASTCALL ceil4_sse(const float4& v);
GMAPI float3 FASTCALL cross3_sse(const float3& a, const float3& b);
GMAPI float4 FASTCALL cross4_sse(const float4& a, const float4& b);
GMAPI float FASTCALL degrees_sse(const float& x);
GMAPI float FASTCALL determinant2x2_sse(const float2x2& m);
GMAPI float FASTCALL determinant3x3_sse(const float3x3& m);
GMAPI float FASTCALL determinant4x4_sse(const float4x4& m);
GMAPI float FASTCALL distance2_sse(const float2& a, const float2& b);
GMAPI float FASTCALL distance3_sse(const float3& a, const float3& b);
GMAPI float FASTCALL distance4_sse(const float4& a, const float4& b);
GMAPI float4 FASTCALL dst_sse(const float& d);
GMAPI float FASTCALL dot2_sse(const float2& a, const float2& b);
GMAPI float FASTCALL dot3_sse(const float3& a, const float3& b);
GMAPI float FASTCALL dot4_sse(const float4& a, const float4& b);
GMAPI float2 FASTCALL faceforward2_sse(const float2& n, const float2& i, const float2& ng);
GMAPI float3 FASTCALL faceforward3_sse(const float3& n, const float3& i, const float3& ng);
GMAPI float4 FASTCALL faceforward4_sse(const float4& n, const float4& i, const float4& ng);
GMAPI float2 FASTCALL floor2_sse(const float2& x);
GMAPI float3 FASTCALL floor3_sse(const float3& x);
GMAPI float4 FASTCALL floor4_sse(const float4& x);
GMAPI float2x2 FASTCALL inverse2x2_sse(const float2x2& m);
GMAPI float3x3 FASTCALL inverse3x3_sse(const float3x3& m);
GMAPI float4x4 FASTCALL inverse4x4_sse(const float4x4& m);
GMAPI float FASTCALL length2_sse(const float2& x);
GMAPI float FASTCALL length3_sse(const float3& x);
GMAPI float FASTCALL length4_sse(const float4& x);
GMAPI float2 FASTCALL lerp2_sse(const float2& a, const float2& b, const float& s);
GMAPI float3 FASTCALL lerp3_sse(const float3& a, const float3& b, const float& s);
GMAPI float4 FASTCALL lerp4_sse(const float4& a, const float4& b, const float& s);
GMAPI float2 FASTCALL mad2_sse(const float2& a, const float& s, const float2& b);
GMAPI float3 FASTCALL mad3_sse(const float3& a, const float& s, const float3& b);
GMAPI float4 FASTCALL mad4_sse(const float4& a, const float& s, const float4& b);
GMAPI float2x2 FASTCALL mul2x2_sse(const float2x2& a, const float2x2& b);
GMAPI float3x3 FASTCALL mul3x3_sse(const float3x3& a, const float3x3& b);
GMAPI float4x4 FASTCALL mul4x4_sse(const float4x4& a, const float4x4& b);
GMAPI float2 FASTCALL mul2_sse(const float2& a, const float2x2& b);
GMAPI float3 FASTCALL mul3_sse(const float3& a, const float3x3& b);
GMAPI float4 FASTCALL mul4_sse(const float4& a, const float4x4& b);
GMAPI float3 FASTCALL mul43_sse(const float3& v, const float4x4& b);
GMAPI float2 FASTCALL normalize2_sse(const float2& v);
GMAPI float3 FASTCALL normalize3_sse(const float3& v);
GMAPI float4 FASTCALL normalize4_sse(const float4& v);
GMAPI float3 FASTCALL normal3_sse(const float3& a, const float3& b, const float3& c);
GMAPI float FASTCALL radians_sse(const float& x);
GMAPI float2 FASTCALL reflect2_sse(const float2& i, const float2& n);
GMAPI float3 FASTCALL reflect3_sse(const float3& i, const float3& n);
GMAPI float4 FASTCALL reflect4_sse(const float4& i, const float4& n);
GMAPI float2 FASTCALL refract2_sse(const float2& i, const float2& n, const float& eta);
GMAPI float3 FASTCALL refract3_sse(const float3& i, const float3& n, const float& eta);
GMAPI float4 FASTCALL refract4_sse(const float4& i, const float4& n, const float& eta);
GMAPI float2 FASTCALL round2_sse(const float2& x);
GMAPI float3 FASTCALL round3_sse(const float3& x);
GMAPI float4 FASTCALL round4_sse(const float4& x);
GMAPI float2x2 FASTCALL transpose2x2_sse(const float2x2& m);
GMAPI float3x3 FASTCALL transpose3x3_sse(const float3x3& m);
GMAPI float4x4 FASTCALL transpose4x4_sse(const float4x4& m);