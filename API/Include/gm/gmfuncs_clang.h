/// <summary>
/// OpenGM library C-language functions.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>24-02-2019</created>
/// <copyright>Copyright 2004-2019 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifdef GMFUNCS_CLANG_H
#error Nested inclusion of gmfuncs_clang.h
#else
#define GMFUNCS_CLANG_H
#endif

NODISCARD GMAPI float2 FASTCALL abs2_clang(const float2& v);
NODISCARD GMAPI float3 FASTCALL abs3_clang(const float3& v);
NODISCARD GMAPI float4 FASTCALL abs4_clang(const float4& v);
NODISCARD GMAPI bool FASTCALL all2_clang(const float2& x);
NODISCARD GMAPI bool FASTCALL all3_clang(const float3& x);
NODISCARD GMAPI bool FASTCALL all4_clang(const float4& x);
NODISCARD GMAPI bool FASTCALL any2_clang(const float2& x);
NODISCARD GMAPI bool FASTCALL any3_clang(const float3& x);
NODISCARD GMAPI bool FASTCALL any4_clang(const float4& x);
NODISCARD GMAPI float2 FASTCALL ceil2_clang(const float2& v);
NODISCARD GMAPI float3 FASTCALL ceil3_clang(const float3& v);
NODISCARD GMAPI float4 FASTCALL ceil4_clang(const float4& v);
NODISCARD GMAPI float3 FASTCALL cross3_clang(const float3& a, const float3& b);
NODISCARD GMAPI float4 FASTCALL cross4_clang(const float4& a, const float4& b);
NODISCARD GMAPI float FASTCALL degrees_clang(const float& x);
NODISCARD GMAPI float FASTCALL determinant2x2_clang(const float2x2& m);
NODISCARD GMAPI float FASTCALL determinant3x3_clang(const float3x3& m);
NODISCARD GMAPI float FASTCALL determinant4x4_clang(const float4x4& m);
NODISCARD GMAPI float FASTCALL distance2_clang(const float2& a, const float2& b);
NODISCARD GMAPI float FASTCALL distance3_clang(const float3& a, const float3& b);
NODISCARD GMAPI float FASTCALL distance4_clang(const float4& a, const float4& b);
NODISCARD GMAPI float4 FASTCALL dst_clang(const float& d);
NODISCARD GMAPI float FASTCALL dot2_clang(const float2& a, const float2& b);
NODISCARD GMAPI float FASTCALL dot3_clang(const float3& a, const float3& b);
NODISCARD GMAPI float FASTCALL dot4_clang(const float4& a, const float4& b);
NODISCARD GMAPI float2 FASTCALL faceforward2_clang(const float2& n, const float2& i, const float2& ng);
NODISCARD GMAPI float3 FASTCALL faceforward3_clang(const float3& n, const float3& i, const float3& ng);
NODISCARD GMAPI float4 FASTCALL faceforward4_clang(const float4& n, const float4& i, const float4& ng);
NODISCARD GMAPI float2 FASTCALL floor2_clang(const float2& x);
NODISCARD GMAPI float3 FASTCALL floor3_clang(const float3& x);
NODISCARD GMAPI float4 FASTCALL floor4_clang(const float4& x);
NODISCARD GMAPI float2x2 FASTCALL inverse2x2_clang(const float2x2& m);
NODISCARD GMAPI float3x3 FASTCALL inverse3x3_clang(const float3x3& m);
NODISCARD GMAPI float4x4 FASTCALL inverse4x4_clang(const float4x4& m);
NODISCARD GMAPI float FASTCALL length2_clang(const float2& x);
NODISCARD GMAPI float FASTCALL length3_clang(const float3& x);
NODISCARD GMAPI float FASTCALL length4_clang(const float4& x);
NODISCARD GMAPI float2 FASTCALL lerp2_clang(const float2& a, const float2& b, const float& s);
NODISCARD GMAPI float3 FASTCALL lerp3_clang(const float3& a, const float3& b, const float& s);
NODISCARD GMAPI float4 FASTCALL lerp4_clang(const float4& a, const float4& b, const float& s);
NODISCARD GMAPI float2 FASTCALL mad2_clang(const float2& a, const float& s, const float2& b);
NODISCARD GMAPI float3 FASTCALL mad3_clang(const float3& a, const float& s, const float3& b);
NODISCARD GMAPI float4 FASTCALL mad4_clang(const float4& a, const float& s, const float4& b);
NODISCARD GMAPI float2x2 FASTCALL mul2x2_clang(const float2x2& a, const float2x2& b);
NODISCARD GMAPI float3x3 FASTCALL mul3x3_clang(const float3x3& a, const float3x3& b);
NODISCARD GMAPI float4x4 FASTCALL mul4x4_clang(const float4x4& a, const float4x4& b);
NODISCARD GMAPI float2 FASTCALL mul2_clang(const float2& a, const float2x2& b);
NODISCARD GMAPI float3 FASTCALL mul3_clang(const float3& a, const float3x3& b);
NODISCARD GMAPI float4 FASTCALL mul4_clang(const float4& a, const float4x4& b);
NODISCARD GMAPI float3 FASTCALL mul43_clang(const float3& v, const float4x4& b);
NODISCARD GMAPI float2 FASTCALL normalize2_clang(const float2& v);
NODISCARD GMAPI float3 FASTCALL normalize3_clang(const float3& v);
NODISCARD GMAPI float4 FASTCALL normalize4_clang(const float4& v);
NODISCARD GMAPI float3 FASTCALL normal3_clang(const float3& a, const float3& b, const float3& c);
NODISCARD GMAPI float FASTCALL radians_clang(const float& x);
NODISCARD GMAPI float2 FASTCALL reflect2_clang(const float2& i, const float2& n);
NODISCARD GMAPI float3 FASTCALL reflect3_clang(const float3& i, const float3& n);
NODISCARD GMAPI float4 FASTCALL reflect4_clang(const float4& i, const float4& n);
NODISCARD GMAPI float2 FASTCALL refract2_clang(const float2& i, const float2& n, const float& eta);
NODISCARD GMAPI float3 FASTCALL refract3_clang(const float3& i, const float3& n, const float& eta);
NODISCARD GMAPI float4 FASTCALL refract4_clang(const float4& i, const float4& n, const float& eta);
NODISCARD GMAPI float2 FASTCALL round2_clang(const float2& x);
NODISCARD GMAPI float3 FASTCALL round3_clang(const float3& x);
NODISCARD GMAPI float4 FASTCALL round4_clang(const float4& x);
NODISCARD GMAPI float2x2 FASTCALL transpose2x2_clang(const float2x2& m);
NODISCARD GMAPI float3x3 FASTCALL transpose3x3_clang(const float3x3& m);
NODISCARD GMAPI float4x4 FASTCALL transpose4x4_clang(const float4x4& m);
