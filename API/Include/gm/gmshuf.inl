/// <summary>
/// OpenGM library header.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>14-06-2005</created>
/// <copyright>Copyright 2005-2018 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifdef GMSHUF_INL
	#error Nested inclusion of gmtypes.inl
#else
	#define GMSHUF_INL
#endif

__forceinline _shuf_xy& _shuf_xy::operator=(_float2& v) { x = v.x; y = v.y; return *this; }
__forceinline _shuf_yx& _shuf_yx::operator=(_float2& v) { x = v.y; y = v.x; return *this; }
__forceinline _shuf_xx& _shuf_xx::operator=(_float2& v) { x = v.x; y = v.x; return *this; }
__forceinline _shuf_yy& _shuf_yy::operator=(_float2& v) { x = v.y; y = v.y; return *this; }

__forceinline _shuf_xxx& _shuf_xxx::operator=(_float3& v) { x = v.x; y = v.x; z = v.x; return *this; }
__forceinline _shuf_xxy& _shuf_xxy::operator=(_float3& v) { x = v.x; y = v.x; z = v.y; return *this; }
__forceinline _shuf_xxz& _shuf_xxz::operator=(_float3& v) { x = v.x; y = v.x; z = v.z; return *this; }
__forceinline _shuf_xyx& _shuf_xyx::operator=(_float3& v) { x = v.x; y = v.y; z = v.x; return *this; }
__forceinline _shuf_xyy& _shuf_xyy::operator=(_float3& v) { x = v.x; y = v.y; z = v.y; return *this; }
__forceinline _shuf_xyz& _shuf_xyz::operator=(_float3& v) { x = v.x; y = v.y; z = v.z; return *this; }
__forceinline _shuf_xzx& _shuf_xzx::operator=(_float3& v) { x = v.x; y = v.z; z = v.x; return *this; }
__forceinline _shuf_xzy& _shuf_xzy::operator=(_float3& v) { x = v.x; y = v.z; z = v.y; return *this; }
__forceinline _shuf_xzz& _shuf_xzz::operator=(_float3& v) { x = v.x; y = v.z; z = v.z; return *this; }
__forceinline _shuf_yxx& _shuf_yxx::operator=(_float3& v) { x = v.y; y = v.x; z = v.x; return *this; }
__forceinline _shuf_yxy& _shuf_yxy::operator=(_float3& v) { x = v.y; y = v.x; z = v.y; return *this; }
__forceinline _shuf_yxz& _shuf_yxz::operator=(_float3& v) { x = v.y; y = v.x; z = v.z; return *this; }
__forceinline _shuf_yyx& _shuf_yyx::operator=(_float3& v) { x = v.y; y = v.y; z = v.x; return *this; }
__forceinline _shuf_yyy& _shuf_yyy::operator=(_float3& v) { x = v.y; y = v.y; z = v.y; return *this; }
__forceinline _shuf_yyz& _shuf_yyz::operator=(_float3& v) { x = v.y; y = v.y; z = v.z; return *this; }
__forceinline _shuf_yzx& _shuf_yzx::operator=(_float3& v) { x = v.y; y = v.z; z = v.x; return *this; }
__forceinline _shuf_yzy& _shuf_yzy::operator=(_float3& v) { x = v.y; y = v.z; z = v.y; return *this; }
__forceinline _shuf_yzz& _shuf_yzz::operator=(_float3& v) { x = v.y; y = v.z; z = v.z; return *this; }
__forceinline _shuf_zxx& _shuf_zxx::operator=(_float3& v) { x = v.z; y = v.x; z = v.x; return *this; }
__forceinline _shuf_zxy& _shuf_zxy::operator=(_float3& v) { x = v.z; y = v.x; z = v.y; return *this; }
__forceinline _shuf_zxz& _shuf_zxz::operator=(_float3& v) { x = v.z; y = v.x; z = v.z; return *this; }
__forceinline _shuf_zyx& _shuf_zyx::operator=(_float3& v) { x = v.z; y = v.y; z = v.x; return *this; }
__forceinline _shuf_zyy& _shuf_zyy::operator=(_float3& v) { x = v.z; y = v.y; z = v.y; return *this; }
__forceinline _shuf_zyz& _shuf_zyz::operator=(_float3& v) { x = v.z; y = v.y; z = v.z; return *this; }
__forceinline _shuf_zzx& _shuf_zzx::operator=(_float3& v) { x = v.z; y = v.z; z = v.x; return *this; }
__forceinline _shuf_zzy& _shuf_zzy::operator=(_float3& v) { x = v.z; y = v.z; z = v.y; return *this; }
__forceinline _shuf_zzz& _shuf_zzz::operator=(_float3& v) { x = v.z; y = v.z; z = v.z; return *this; }

__forceinline _shuf_xxxx& _shuf_xxxx::operator=(_float4& v) { x = v.x; y = v.x; z = v.x; w = v.x; return *this; }
__forceinline _shuf_xxxy& _shuf_xxxy::operator=(_float4& v) { x = v.x; y = v.x; z = v.x; w = v.y; return *this; }
__forceinline _shuf_xxxz& _shuf_xxxz::operator=(_float4& v) { x = v.x; y = v.x; z = v.x; w = v.z; return *this; }
__forceinline _shuf_xxxw& _shuf_xxxw::operator=(_float4& v) { x = v.x; y = v.x; z = v.x; w = v.w; return *this; }
__forceinline _shuf_xxyx& _shuf_xxyx::operator=(_float4& v) { x = v.x; y = v.x; z = v.y; w = v.x; return *this; }
__forceinline _shuf_xxyy& _shuf_xxyy::operator=(_float4& v) { x = v.x; y = v.x; z = v.y; w = v.y; return *this; }
__forceinline _shuf_xxyz& _shuf_xxyz::operator=(_float4& v) { x = v.x; y = v.x; z = v.y; w = v.z; return *this; }
__forceinline _shuf_xxyw& _shuf_xxyw::operator=(_float4& v) { x = v.x; y = v.x; z = v.y; w = v.w; return *this; }
__forceinline _shuf_xxzx& _shuf_xxzx::operator=(_float4& v) { x = v.x; y = v.x; z = v.z; w = v.x; return *this; }
__forceinline _shuf_xxzy& _shuf_xxzy::operator=(_float4& v) { x = v.x; y = v.x; z = v.z; w = v.y; return *this; }
__forceinline _shuf_xxzz& _shuf_xxzz::operator=(_float4& v) { x = v.x; y = v.x; z = v.z; w = v.z; return *this; }
__forceinline _shuf_xxzw& _shuf_xxzw::operator=(_float4& v) { x = v.x; y = v.x; z = v.z; w = v.w; return *this; }
__forceinline _shuf_xxwx& _shuf_xxwx::operator=(_float4& v) { x = v.x; y = v.x; z = v.w; w = v.x; return *this; }
__forceinline _shuf_xxwy& _shuf_xxwy::operator=(_float4& v) { x = v.x; y = v.x; z = v.w; w = v.y; return *this; }
__forceinline _shuf_xxwz& _shuf_xxwz::operator=(_float4& v) { x = v.x; y = v.x; z = v.w; w = v.z; return *this; }
__forceinline _shuf_xxww& _shuf_xxww::operator=(_float4& v) { x = v.x; y = v.x; z = v.w; w = v.w; return *this; }
__forceinline _shuf_xyxx& _shuf_xyxx::operator=(_float4& v) { x = v.x; y = v.y; z = v.x; w = v.x; return *this; }
__forceinline _shuf_xyxy& _shuf_xyxy::operator=(_float4& v) { x = v.x; y = v.y; z = v.x; w = v.y; return *this; }
__forceinline _shuf_xyxz& _shuf_xyxz::operator=(_float4& v) { x = v.x; y = v.y; z = v.x; w = v.z; return *this; }
__forceinline _shuf_xyxw& _shuf_xyxw::operator=(_float4& v) { x = v.x; y = v.y; z = v.x; w = v.w; return *this; }
__forceinline _shuf_xyyx& _shuf_xyyx::operator=(_float4& v) { x = v.x; y = v.y; z = v.y; w = v.x; return *this; }
__forceinline _shuf_xyyy& _shuf_xyyy::operator=(_float4& v) { x = v.x; y = v.y; z = v.y; w = v.y; return *this; }
__forceinline _shuf_xyyz& _shuf_xyyz::operator=(_float4& v) { x = v.x; y = v.y; z = v.y; w = v.z; return *this; }
__forceinline _shuf_xyyw& _shuf_xyyw::operator=(_float4& v) { x = v.x; y = v.y; z = v.y; w = v.w; return *this; }
__forceinline _shuf_xyzx& _shuf_xyzx::operator=(_float4& v) { x = v.x; y = v.y; z = v.z; w = v.x; return *this; }
__forceinline _shuf_xyzy& _shuf_xyzy::operator=(_float4& v) { x = v.x; y = v.y; z = v.z; w = v.y; return *this; }
__forceinline _shuf_xyzz& _shuf_xyzz::operator=(_float4& v) { x = v.x; y = v.y; z = v.z; w = v.z; return *this; }
__forceinline _shuf_xyzw& _shuf_xyzw::operator=(_float4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
__forceinline _shuf_xywx& _shuf_xywx::operator=(_float4& v) { x = v.x; y = v.y; z = v.w; w = v.x; return *this; }
__forceinline _shuf_xywy& _shuf_xywy::operator=(_float4& v) { x = v.x; y = v.y; z = v.w; w = v.y; return *this; }
__forceinline _shuf_xywz& _shuf_xywz::operator=(_float4& v) { x = v.x; y = v.y; z = v.w; w = v.z; return *this; }
__forceinline _shuf_xyww& _shuf_xyww::operator=(_float4& v) { x = v.x; y = v.y; z = v.w; w = v.w; return *this; }
__forceinline _shuf_xzxx& _shuf_xzxx::operator=(_float4& v) { x = v.x; y = v.z; z = v.x; w = v.x; return *this; }
__forceinline _shuf_xzxy& _shuf_xzxy::operator=(_float4& v) { x = v.x; y = v.z; z = v.x; w = v.y; return *this; }
__forceinline _shuf_xzxz& _shuf_xzxz::operator=(_float4& v) { x = v.x; y = v.z; z = v.x; w = v.z; return *this; }
__forceinline _shuf_xzxw& _shuf_xzxw::operator=(_float4& v) { x = v.x; y = v.z; z = v.x; w = v.w; return *this; }
__forceinline _shuf_xzyx& _shuf_xzyx::operator=(_float4& v) { x = v.x; y = v.z; z = v.y; w = v.x; return *this; }
__forceinline _shuf_xzyy& _shuf_xzyy::operator=(_float4& v) { x = v.x; y = v.z; z = v.y; w = v.y; return *this; }
__forceinline _shuf_xzyz& _shuf_xzyz::operator=(_float4& v) { x = v.x; y = v.z; z = v.y; w = v.z; return *this; }
__forceinline _shuf_xzyw& _shuf_xzyw::operator=(_float4& v) { x = v.x; y = v.z; z = v.y; w = v.w; return *this; }
__forceinline _shuf_xzzx& _shuf_xzzx::operator=(_float4& v) { x = v.x; y = v.z; z = v.z; w = v.x; return *this; }
__forceinline _shuf_xzzy& _shuf_xzzy::operator=(_float4& v) { x = v.x; y = v.z; z = v.z; w = v.y; return *this; }
__forceinline _shuf_xzzz& _shuf_xzzz::operator=(_float4& v) { x = v.x; y = v.z; z = v.z; w = v.z; return *this; }
__forceinline _shuf_xzzw& _shuf_xzzw::operator=(_float4& v) { x = v.x; y = v.z; z = v.z; w = v.w; return *this; }
__forceinline _shuf_xzwx& _shuf_xzwx::operator=(_float4& v) { x = v.x; y = v.z; z = v.w; w = v.x; return *this; }
__forceinline _shuf_xzwy& _shuf_xzwy::operator=(_float4& v) { x = v.x; y = v.z; z = v.w; w = v.y; return *this; }
__forceinline _shuf_xzwz& _shuf_xzwz::operator=(_float4& v) { x = v.x; y = v.z; z = v.w; w = v.z; return *this; }
__forceinline _shuf_xzww& _shuf_xzww::operator=(_float4& v) { x = v.x; y = v.z; z = v.w; w = v.w; return *this; }
__forceinline _shuf_xwxx& _shuf_xwxx::operator=(_float4& v) { x = v.x; y = v.w; z = v.x; w = v.x; return *this; }
__forceinline _shuf_xwxy& _shuf_xwxy::operator=(_float4& v) { x = v.x; y = v.w; z = v.x; w = v.y; return *this; }
__forceinline _shuf_xwxz& _shuf_xwxz::operator=(_float4& v) { x = v.x; y = v.w; z = v.x; w = v.z; return *this; }
__forceinline _shuf_xwxw& _shuf_xwxw::operator=(_float4& v) { x = v.x; y = v.w; z = v.x; w = v.w; return *this; }
__forceinline _shuf_xwyx& _shuf_xwyx::operator=(_float4& v) { x = v.x; y = v.w; z = v.y; w = v.x; return *this; }
__forceinline _shuf_xwyy& _shuf_xwyy::operator=(_float4& v) { x = v.x; y = v.w; z = v.y; w = v.y; return *this; }
__forceinline _shuf_xwyz& _shuf_xwyz::operator=(_float4& v) { x = v.x; y = v.w; z = v.y; w = v.z; return *this; }
__forceinline _shuf_xwyw& _shuf_xwyw::operator=(_float4& v) { x = v.x; y = v.w; z = v.y; w = v.w; return *this; }
__forceinline _shuf_xwzx& _shuf_xwzx::operator=(_float4& v) { x = v.x; y = v.w; z = v.z; w = v.x; return *this; }
__forceinline _shuf_xwzy& _shuf_xwzy::operator=(_float4& v) { x = v.x; y = v.w; z = v.z; w = v.y; return *this; }
__forceinline _shuf_xwzz& _shuf_xwzz::operator=(_float4& v) { x = v.x; y = v.w; z = v.z; w = v.z; return *this; }
__forceinline _shuf_xwzw& _shuf_xwzw::operator=(_float4& v) { x = v.x; y = v.w; z = v.z; w = v.w; return *this; }
__forceinline _shuf_xwwx& _shuf_xwwx::operator=(_float4& v) { x = v.x; y = v.w; z = v.w; w = v.x; return *this; }
__forceinline _shuf_xwwy& _shuf_xwwy::operator=(_float4& v) { x = v.x; y = v.w; z = v.w; w = v.y; return *this; }
__forceinline _shuf_xwwz& _shuf_xwwz::operator=(_float4& v) { x = v.x; y = v.w; z = v.w; w = v.z; return *this; }
__forceinline _shuf_xwww& _shuf_xwww::operator=(_float4& v) { x = v.x; y = v.w; z = v.w; w = v.w; return *this; }
__forceinline _shuf_yxxx& _shuf_yxxx::operator=(_float4& v) { x = v.y; y = v.x; z = v.x; w = v.x; return *this; }
__forceinline _shuf_yxxy& _shuf_yxxy::operator=(_float4& v) { x = v.y; y = v.x; z = v.x; w = v.y; return *this; }
__forceinline _shuf_yxxz& _shuf_yxxz::operator=(_float4& v) { x = v.y; y = v.x; z = v.x; w = v.z; return *this; }
__forceinline _shuf_yxxw& _shuf_yxxw::operator=(_float4& v) { x = v.y; y = v.x; z = v.x; w = v.w; return *this; }
__forceinline _shuf_yxyx& _shuf_yxyx::operator=(_float4& v) { x = v.y; y = v.x; z = v.y; w = v.x; return *this; }
__forceinline _shuf_yxyy& _shuf_yxyy::operator=(_float4& v) { x = v.y; y = v.x; z = v.y; w = v.y; return *this; }
__forceinline _shuf_yxyz& _shuf_yxyz::operator=(_float4& v) { x = v.y; y = v.x; z = v.y; w = v.z; return *this; }
__forceinline _shuf_yxyw& _shuf_yxyw::operator=(_float4& v) { x = v.y; y = v.x; z = v.y; w = v.w; return *this; }
__forceinline _shuf_yxzx& _shuf_yxzx::operator=(_float4& v) { x = v.y; y = v.x; z = v.z; w = v.x; return *this; }
__forceinline _shuf_yxzy& _shuf_yxzy::operator=(_float4& v) { x = v.y; y = v.x; z = v.z; w = v.y; return *this; }
__forceinline _shuf_yxzz& _shuf_yxzz::operator=(_float4& v) { x = v.y; y = v.x; z = v.z; w = v.z; return *this; }
__forceinline _shuf_yxzw& _shuf_yxzw::operator=(_float4& v) { x = v.y; y = v.x; z = v.z; w = v.w; return *this; }
__forceinline _shuf_yxwx& _shuf_yxwx::operator=(_float4& v) { x = v.y; y = v.x; z = v.w; w = v.x; return *this; }
__forceinline _shuf_yxwy& _shuf_yxwy::operator=(_float4& v) { x = v.y; y = v.x; z = v.w; w = v.y; return *this; }
__forceinline _shuf_yxwz& _shuf_yxwz::operator=(_float4& v) { x = v.y; y = v.x; z = v.w; w = v.z; return *this; }
__forceinline _shuf_yxww& _shuf_yxww::operator=(_float4& v) { x = v.y; y = v.x; z = v.w; w = v.w; return *this; }
__forceinline _shuf_yyxx& _shuf_yyxx::operator=(_float4& v) { x = v.y; y = v.y; z = v.x; w = v.x; return *this; }
__forceinline _shuf_yyxy& _shuf_yyxy::operator=(_float4& v) { x = v.y; y = v.y; z = v.x; w = v.y; return *this; }
__forceinline _shuf_yyxz& _shuf_yyxz::operator=(_float4& v) { x = v.y; y = v.y; z = v.x; w = v.z; return *this; }
__forceinline _shuf_yyxw& _shuf_yyxw::operator=(_float4& v) { x = v.y; y = v.y; z = v.x; w = v.w; return *this; }
__forceinline _shuf_yyyx& _shuf_yyyx::operator=(_float4& v) { x = v.y; y = v.y; z = v.y; w = v.x; return *this; }
__forceinline _shuf_yyyy& _shuf_yyyy::operator=(_float4& v) { x = v.y; y = v.y; z = v.y; w = v.y; return *this; }
__forceinline _shuf_yyyz& _shuf_yyyz::operator=(_float4& v) { x = v.y; y = v.y; z = v.y; w = v.z; return *this; }
__forceinline _shuf_yyyw& _shuf_yyyw::operator=(_float4& v) { x = v.y; y = v.y; z = v.y; w = v.w; return *this; }
__forceinline _shuf_yyzx& _shuf_yyzx::operator=(_float4& v) { x = v.y; y = v.y; z = v.z; w = v.x; return *this; }
__forceinline _shuf_yyzy& _shuf_yyzy::operator=(_float4& v) { x = v.y; y = v.y; z = v.z; w = v.y; return *this; }
__forceinline _shuf_yyzz& _shuf_yyzz::operator=(_float4& v) { x = v.y; y = v.y; z = v.z; w = v.z; return *this; }
__forceinline _shuf_yyzw& _shuf_yyzw::operator=(_float4& v) { x = v.y; y = v.y; z = v.z; w = v.w; return *this; }
__forceinline _shuf_yywx& _shuf_yywx::operator=(_float4& v) { x = v.y; y = v.y; z = v.w; w = v.x; return *this; }
__forceinline _shuf_yywy& _shuf_yywy::operator=(_float4& v) { x = v.y; y = v.y; z = v.w; w = v.y; return *this; }
__forceinline _shuf_yywz& _shuf_yywz::operator=(_float4& v) { x = v.y; y = v.y; z = v.w; w = v.z; return *this; }
__forceinline _shuf_yyww& _shuf_yyww::operator=(_float4& v) { x = v.y; y = v.y; z = v.w; w = v.w; return *this; }
__forceinline _shuf_yzxx& _shuf_yzxx::operator=(_float4& v) { x = v.y; y = v.z; z = v.x; w = v.x; return *this; }
__forceinline _shuf_yzxy& _shuf_yzxy::operator=(_float4& v) { x = v.y; y = v.z; z = v.x; w = v.y; return *this; }
__forceinline _shuf_yzxz& _shuf_yzxz::operator=(_float4& v) { x = v.y; y = v.z; z = v.x; w = v.z; return *this; }
__forceinline _shuf_yzxw& _shuf_yzxw::operator=(_float4& v) { x = v.y; y = v.z; z = v.x; w = v.w; return *this; }
__forceinline _shuf_yzyx& _shuf_yzyx::operator=(_float4& v) { x = v.y; y = v.z; z = v.y; w = v.x; return *this; }
__forceinline _shuf_yzyy& _shuf_yzyy::operator=(_float4& v) { x = v.y; y = v.z; z = v.y; w = v.y; return *this; }
__forceinline _shuf_yzyz& _shuf_yzyz::operator=(_float4& v) { x = v.y; y = v.z; z = v.y; w = v.z; return *this; }
__forceinline _shuf_yzyw& _shuf_yzyw::operator=(_float4& v) { x = v.y; y = v.z; z = v.y; w = v.w; return *this; }
__forceinline _shuf_yzzx& _shuf_yzzx::operator=(_float4& v) { x = v.y; y = v.z; z = v.z; w = v.x; return *this; }
__forceinline _shuf_yzzy& _shuf_yzzy::operator=(_float4& v) { x = v.y; y = v.z; z = v.z; w = v.y; return *this; }
__forceinline _shuf_yzzz& _shuf_yzzz::operator=(_float4& v) { x = v.y; y = v.z; z = v.z; w = v.z; return *this; }
__forceinline _shuf_yzzw& _shuf_yzzw::operator=(_float4& v) { x = v.y; y = v.z; z = v.z; w = v.w; return *this; }
__forceinline _shuf_yzwx& _shuf_yzwx::operator=(_float4& v) { x = v.y; y = v.z; z = v.w; w = v.x; return *this; }
__forceinline _shuf_yzwy& _shuf_yzwy::operator=(_float4& v) { x = v.y; y = v.z; z = v.w; w = v.y; return *this; }
__forceinline _shuf_yzwz& _shuf_yzwz::operator=(_float4& v) { x = v.y; y = v.z; z = v.w; w = v.z; return *this; }
__forceinline _shuf_yzww& _shuf_yzww::operator=(_float4& v) { x = v.y; y = v.z; z = v.w; w = v.w; return *this; }
__forceinline _shuf_ywxx& _shuf_ywxx::operator=(_float4& v) { x = v.y; y = v.w; z = v.x; w = v.x; return *this; }
__forceinline _shuf_ywxy& _shuf_ywxy::operator=(_float4& v) { x = v.y; y = v.w; z = v.x; w = v.y; return *this; }
__forceinline _shuf_ywxz& _shuf_ywxz::operator=(_float4& v) { x = v.y; y = v.w; z = v.x; w = v.z; return *this; }
__forceinline _shuf_ywxw& _shuf_ywxw::operator=(_float4& v) { x = v.y; y = v.w; z = v.x; w = v.w; return *this; }
__forceinline _shuf_ywyx& _shuf_ywyx::operator=(_float4& v) { x = v.y; y = v.w; z = v.y; w = v.x; return *this; }
__forceinline _shuf_ywyy& _shuf_ywyy::operator=(_float4& v) { x = v.y; y = v.w; z = v.y; w = v.y; return *this; }
__forceinline _shuf_ywyz& _shuf_ywyz::operator=(_float4& v) { x = v.y; y = v.w; z = v.y; w = v.z; return *this; }
__forceinline _shuf_ywyw& _shuf_ywyw::operator=(_float4& v) { x = v.y; y = v.w; z = v.y; w = v.w; return *this; }
__forceinline _shuf_ywzx& _shuf_ywzx::operator=(_float4& v) { x = v.y; y = v.w; z = v.z; w = v.x; return *this; }
__forceinline _shuf_ywzy& _shuf_ywzy::operator=(_float4& v) { x = v.y; y = v.w; z = v.z; w = v.y; return *this; }
__forceinline _shuf_ywzz& _shuf_ywzz::operator=(_float4& v) { x = v.y; y = v.w; z = v.z; w = v.z; return *this; }
__forceinline _shuf_ywzw& _shuf_ywzw::operator=(_float4& v) { x = v.y; y = v.w; z = v.z; w = v.w; return *this; }
__forceinline _shuf_ywwx& _shuf_ywwx::operator=(_float4& v) { x = v.y; y = v.w; z = v.w; w = v.x; return *this; }
__forceinline _shuf_ywwy& _shuf_ywwy::operator=(_float4& v) { x = v.y; y = v.w; z = v.w; w = v.y; return *this; }
__forceinline _shuf_ywwz& _shuf_ywwz::operator=(_float4& v) { x = v.y; y = v.w; z = v.w; w = v.z; return *this; }
__forceinline _shuf_ywww& _shuf_ywww::operator=(_float4& v) { x = v.y; y = v.w; z = v.w; w = v.w; return *this; }
__forceinline _shuf_zxxx& _shuf_zxxx::operator=(_float4& v) { x = v.z; y = v.x; z = v.x; w = v.x; return *this; }
__forceinline _shuf_zxxy& _shuf_zxxy::operator=(_float4& v) { x = v.z; y = v.x; z = v.x; w = v.y; return *this; }
__forceinline _shuf_zxxz& _shuf_zxxz::operator=(_float4& v) { x = v.z; y = v.x; z = v.x; w = v.z; return *this; }
__forceinline _shuf_zxxw& _shuf_zxxw::operator=(_float4& v) { x = v.z; y = v.x; z = v.x; w = v.w; return *this; }
__forceinline _shuf_zxyx& _shuf_zxyx::operator=(_float4& v) { x = v.z; y = v.x; z = v.y; w = v.x; return *this; }
__forceinline _shuf_zxyy& _shuf_zxyy::operator=(_float4& v) { x = v.z; y = v.x; z = v.y; w = v.y; return *this; }
__forceinline _shuf_zxyz& _shuf_zxyz::operator=(_float4& v) { x = v.z; y = v.x; z = v.y; w = v.z; return *this; }
__forceinline _shuf_zxyw& _shuf_zxyw::operator=(_float4& v) { x = v.z; y = v.x; z = v.y; w = v.w; return *this; }
__forceinline _shuf_zxzx& _shuf_zxzx::operator=(_float4& v) { x = v.z; y = v.x; z = v.z; w = v.x; return *this; }
__forceinline _shuf_zxzy& _shuf_zxzy::operator=(_float4& v) { x = v.z; y = v.x; z = v.z; w = v.y; return *this; }
__forceinline _shuf_zxzz& _shuf_zxzz::operator=(_float4& v) { x = v.z; y = v.x; z = v.z; w = v.z; return *this; }
__forceinline _shuf_zxzw& _shuf_zxzw::operator=(_float4& v) { x = v.z; y = v.x; z = v.z; w = v.w; return *this; }
__forceinline _shuf_zxwx& _shuf_zxwx::operator=(_float4& v) { x = v.z; y = v.x; z = v.w; w = v.x; return *this; }
__forceinline _shuf_zxwy& _shuf_zxwy::operator=(_float4& v) { x = v.z; y = v.x; z = v.w; w = v.y; return *this; }
__forceinline _shuf_zxwz& _shuf_zxwz::operator=(_float4& v) { x = v.z; y = v.x; z = v.w; w = v.z; return *this; }
__forceinline _shuf_zxww& _shuf_zxww::operator=(_float4& v) { x = v.z; y = v.x; z = v.w; w = v.w; return *this; }
__forceinline _shuf_zyxx& _shuf_zyxx::operator=(_float4& v) { x = v.z; y = v.y; z = v.x; w = v.x; return *this; }
__forceinline _shuf_zyxy& _shuf_zyxy::operator=(_float4& v) { x = v.z; y = v.y; z = v.x; w = v.y; return *this; }
__forceinline _shuf_zyxz& _shuf_zyxz::operator=(_float4& v) { x = v.z; y = v.y; z = v.x; w = v.z; return *this; }
__forceinline _shuf_zyxw& _shuf_zyxw::operator=(_float4& v) { x = v.z; y = v.y; z = v.x; w = v.w; return *this; }
__forceinline _shuf_zyyx& _shuf_zyyx::operator=(_float4& v) { x = v.z; y = v.y; z = v.y; w = v.x; return *this; }
__forceinline _shuf_zyyy& _shuf_zyyy::operator=(_float4& v) { x = v.z; y = v.y; z = v.y; w = v.y; return *this; }
__forceinline _shuf_zyyz& _shuf_zyyz::operator=(_float4& v) { x = v.z; y = v.y; z = v.y; w = v.z; return *this; }
__forceinline _shuf_zyyw& _shuf_zyyw::operator=(_float4& v) { x = v.z; y = v.y; z = v.y; w = v.w; return *this; }
__forceinline _shuf_zyzx& _shuf_zyzx::operator=(_float4& v) { x = v.z; y = v.y; z = v.z; w = v.x; return *this; }
__forceinline _shuf_zyzy& _shuf_zyzy::operator=(_float4& v) { x = v.z; y = v.y; z = v.z; w = v.y; return *this; }
__forceinline _shuf_zyzz& _shuf_zyzz::operator=(_float4& v) { x = v.z; y = v.y; z = v.z; w = v.z; return *this; }
__forceinline _shuf_zyzw& _shuf_zyzw::operator=(_float4& v) { x = v.z; y = v.y; z = v.z; w = v.w; return *this; }
__forceinline _shuf_zywx& _shuf_zywx::operator=(_float4& v) { x = v.z; y = v.y; z = v.w; w = v.x; return *this; }
__forceinline _shuf_zywy& _shuf_zywy::operator=(_float4& v) { x = v.z; y = v.y; z = v.w; w = v.y; return *this; }
__forceinline _shuf_zywz& _shuf_zywz::operator=(_float4& v) { x = v.z; y = v.y; z = v.w; w = v.z; return *this; }
__forceinline _shuf_zyww& _shuf_zyww::operator=(_float4& v) { x = v.z; y = v.y; z = v.w; w = v.w; return *this; }
__forceinline _shuf_zzxx& _shuf_zzxx::operator=(_float4& v) { x = v.z; y = v.z; z = v.x; w = v.x; return *this; }
__forceinline _shuf_zzxy& _shuf_zzxy::operator=(_float4& v) { x = v.z; y = v.z; z = v.x; w = v.y; return *this; }
__forceinline _shuf_zzxz& _shuf_zzxz::operator=(_float4& v) { x = v.z; y = v.z; z = v.x; w = v.z; return *this; }
__forceinline _shuf_zzxw& _shuf_zzxw::operator=(_float4& v) { x = v.z; y = v.z; z = v.x; w = v.w; return *this; }
__forceinline _shuf_zzyx& _shuf_zzyx::operator=(_float4& v) { x = v.z; y = v.z; z = v.y; w = v.x; return *this; }
__forceinline _shuf_zzyy& _shuf_zzyy::operator=(_float4& v) { x = v.z; y = v.z; z = v.y; w = v.y; return *this; }
__forceinline _shuf_zzyz& _shuf_zzyz::operator=(_float4& v) { x = v.z; y = v.z; z = v.y; w = v.z; return *this; }
__forceinline _shuf_zzyw& _shuf_zzyw::operator=(_float4& v) { x = v.z; y = v.z; z = v.y; w = v.w; return *this; }
__forceinline _shuf_zzzx& _shuf_zzzx::operator=(_float4& v) { x = v.z; y = v.z; z = v.z; w = v.x; return *this; }
__forceinline _shuf_zzzy& _shuf_zzzy::operator=(_float4& v) { x = v.z; y = v.z; z = v.z; w = v.y; return *this; }
__forceinline _shuf_zzzz& _shuf_zzzz::operator=(_float4& v) { x = v.z; y = v.z; z = v.z; w = v.z; return *this; }
__forceinline _shuf_zzzw& _shuf_zzzw::operator=(_float4& v) { x = v.z; y = v.z; z = v.z; w = v.w; return *this; }
__forceinline _shuf_zzwx& _shuf_zzwx::operator=(_float4& v) { x = v.z; y = v.z; z = v.w; w = v.x; return *this; }
__forceinline _shuf_zzwy& _shuf_zzwy::operator=(_float4& v) { x = v.z; y = v.z; z = v.w; w = v.y; return *this; }
__forceinline _shuf_zzwz& _shuf_zzwz::operator=(_float4& v) { x = v.z; y = v.z; z = v.w; w = v.z; return *this; }
__forceinline _shuf_zzww& _shuf_zzww::operator=(_float4& v) { x = v.z; y = v.z; z = v.w; w = v.w; return *this; }
__forceinline _shuf_zwxx& _shuf_zwxx::operator=(_float4& v) { x = v.z; y = v.w; z = v.x; w = v.x; return *this; }
__forceinline _shuf_zwxy& _shuf_zwxy::operator=(_float4& v) { x = v.z; y = v.w; z = v.x; w = v.y; return *this; }
__forceinline _shuf_zwxz& _shuf_zwxz::operator=(_float4& v) { x = v.z; y = v.w; z = v.x; w = v.z; return *this; }
__forceinline _shuf_zwxw& _shuf_zwxw::operator=(_float4& v) { x = v.z; y = v.w; z = v.x; w = v.w; return *this; }
__forceinline _shuf_zwyx& _shuf_zwyx::operator=(_float4& v) { x = v.z; y = v.w; z = v.y; w = v.x; return *this; }
__forceinline _shuf_zwyy& _shuf_zwyy::operator=(_float4& v) { x = v.z; y = v.w; z = v.y; w = v.y; return *this; }
__forceinline _shuf_zwyz& _shuf_zwyz::operator=(_float4& v) { x = v.z; y = v.w; z = v.y; w = v.z; return *this; }
__forceinline _shuf_zwyw& _shuf_zwyw::operator=(_float4& v) { x = v.z; y = v.w; z = v.y; w = v.w; return *this; }
__forceinline _shuf_zwzx& _shuf_zwzx::operator=(_float4& v) { x = v.z; y = v.w; z = v.z; w = v.x; return *this; }
__forceinline _shuf_zwzy& _shuf_zwzy::operator=(_float4& v) { x = v.z; y = v.w; z = v.z; w = v.y; return *this; }
__forceinline _shuf_zwzz& _shuf_zwzz::operator=(_float4& v) { x = v.z; y = v.w; z = v.z; w = v.z; return *this; }
__forceinline _shuf_zwzw& _shuf_zwzw::operator=(_float4& v) { x = v.z; y = v.w; z = v.z; w = v.w; return *this; }
__forceinline _shuf_zwwx& _shuf_zwwx::operator=(_float4& v) { x = v.z; y = v.w; z = v.w; w = v.x; return *this; }
__forceinline _shuf_zwwy& _shuf_zwwy::operator=(_float4& v) { x = v.z; y = v.w; z = v.w; w = v.y; return *this; }
__forceinline _shuf_zwwz& _shuf_zwwz::operator=(_float4& v) { x = v.z; y = v.w; z = v.w; w = v.z; return *this; }
__forceinline _shuf_zwww& _shuf_zwww::operator=(_float4& v) { x = v.z; y = v.w; z = v.w; w = v.w; return *this; }
__forceinline _shuf_wxxx& _shuf_wxxx::operator=(_float4& v) { x = v.w; y = v.x; z = v.x; w = v.x; return *this; }
__forceinline _shuf_wxxy& _shuf_wxxy::operator=(_float4& v) { x = v.w; y = v.x; z = v.x; w = v.y; return *this; }
__forceinline _shuf_wxxz& _shuf_wxxz::operator=(_float4& v) { x = v.w; y = v.x; z = v.x; w = v.z; return *this; }
__forceinline _shuf_wxxw& _shuf_wxxw::operator=(_float4& v) { x = v.w; y = v.x; z = v.x; w = v.w; return *this; }
__forceinline _shuf_wxyx& _shuf_wxyx::operator=(_float4& v) { x = v.w; y = v.x; z = v.y; w = v.x; return *this; }
__forceinline _shuf_wxyy& _shuf_wxyy::operator=(_float4& v) { x = v.w; y = v.x; z = v.y; w = v.y; return *this; }
__forceinline _shuf_wxyz& _shuf_wxyz::operator=(_float4& v) { x = v.w; y = v.x; z = v.y; w = v.z; return *this; }
__forceinline _shuf_wxyw& _shuf_wxyw::operator=(_float4& v) { x = v.w; y = v.x; z = v.y; w = v.w; return *this; }
__forceinline _shuf_wxzx& _shuf_wxzx::operator=(_float4& v) { x = v.w; y = v.x; z = v.z; w = v.x; return *this; }
__forceinline _shuf_wxzy& _shuf_wxzy::operator=(_float4& v) { x = v.w; y = v.x; z = v.z; w = v.y; return *this; }
__forceinline _shuf_wxzz& _shuf_wxzz::operator=(_float4& v) { x = v.w; y = v.x; z = v.z; w = v.z; return *this; }
__forceinline _shuf_wxzw& _shuf_wxzw::operator=(_float4& v) { x = v.w; y = v.x; z = v.z; w = v.w; return *this; }
__forceinline _shuf_wxwx& _shuf_wxwx::operator=(_float4& v) { x = v.w; y = v.x; z = v.w; w = v.x; return *this; }
__forceinline _shuf_wxwy& _shuf_wxwy::operator=(_float4& v) { x = v.w; y = v.x; z = v.w; w = v.y; return *this; }
__forceinline _shuf_wxwz& _shuf_wxwz::operator=(_float4& v) { x = v.w; y = v.x; z = v.w; w = v.z; return *this; }
__forceinline _shuf_wxww& _shuf_wxww::operator=(_float4& v) { x = v.w; y = v.x; z = v.w; w = v.w; return *this; }
__forceinline _shuf_wyxx& _shuf_wyxx::operator=(_float4& v) { x = v.w; y = v.y; z = v.x; w = v.x; return *this; }
__forceinline _shuf_wyxy& _shuf_wyxy::operator=(_float4& v) { x = v.w; y = v.y; z = v.x; w = v.y; return *this; }
__forceinline _shuf_wyxz& _shuf_wyxz::operator=(_float4& v) { x = v.w; y = v.y; z = v.x; w = v.z; return *this; }
__forceinline _shuf_wyxw& _shuf_wyxw::operator=(_float4& v) { x = v.w; y = v.y; z = v.x; w = v.w; return *this; }
__forceinline _shuf_wyyx& _shuf_wyyx::operator=(_float4& v) { x = v.w; y = v.y; z = v.y; w = v.x; return *this; }
__forceinline _shuf_wyyy& _shuf_wyyy::operator=(_float4& v) { x = v.w; y = v.y; z = v.y; w = v.y; return *this; }
__forceinline _shuf_wyyz& _shuf_wyyz::operator=(_float4& v) { x = v.w; y = v.y; z = v.y; w = v.z; return *this; }
__forceinline _shuf_wyyw& _shuf_wyyw::operator=(_float4& v) { x = v.w; y = v.y; z = v.y; w = v.w; return *this; }
__forceinline _shuf_wyzx& _shuf_wyzx::operator=(_float4& v) { x = v.w; y = v.y; z = v.z; w = v.x; return *this; }
__forceinline _shuf_wyzy& _shuf_wyzy::operator=(_float4& v) { x = v.w; y = v.y; z = v.z; w = v.y; return *this; }
__forceinline _shuf_wyzz& _shuf_wyzz::operator=(_float4& v) { x = v.w; y = v.y; z = v.z; w = v.z; return *this; }
__forceinline _shuf_wyzw& _shuf_wyzw::operator=(_float4& v) { x = v.w; y = v.y; z = v.z; w = v.w; return *this; }
__forceinline _shuf_wywx& _shuf_wywx::operator=(_float4& v) { x = v.w; y = v.y; z = v.w; w = v.x; return *this; }
__forceinline _shuf_wywy& _shuf_wywy::operator=(_float4& v) { x = v.w; y = v.y; z = v.w; w = v.y; return *this; }
__forceinline _shuf_wywz& _shuf_wywz::operator=(_float4& v) { x = v.w; y = v.y; z = v.w; w = v.z; return *this; }
__forceinline _shuf_wyww& _shuf_wyww::operator=(_float4& v) { x = v.w; y = v.y; z = v.w; w = v.w; return *this; }
__forceinline _shuf_wzxx& _shuf_wzxx::operator=(_float4& v) { x = v.w; y = v.z; z = v.x; w = v.x; return *this; }
__forceinline _shuf_wzxy& _shuf_wzxy::operator=(_float4& v) { x = v.w; y = v.z; z = v.x; w = v.y; return *this; }
__forceinline _shuf_wzxz& _shuf_wzxz::operator=(_float4& v) { x = v.w; y = v.z; z = v.x; w = v.z; return *this; }
__forceinline _shuf_wzxw& _shuf_wzxw::operator=(_float4& v) { x = v.w; y = v.z; z = v.x; w = v.w; return *this; }
__forceinline _shuf_wzyx& _shuf_wzyx::operator=(_float4& v) { x = v.w; y = v.z; z = v.y; w = v.x; return *this; }
__forceinline _shuf_wzyy& _shuf_wzyy::operator=(_float4& v) { x = v.w; y = v.z; z = v.y; w = v.y; return *this; }
__forceinline _shuf_wzyz& _shuf_wzyz::operator=(_float4& v) { x = v.w; y = v.z; z = v.y; w = v.z; return *this; }
__forceinline _shuf_wzyw& _shuf_wzyw::operator=(_float4& v) { x = v.w; y = v.z; z = v.y; w = v.w; return *this; }
__forceinline _shuf_wzzx& _shuf_wzzx::operator=(_float4& v) { x = v.w; y = v.z; z = v.z; w = v.x; return *this; }
__forceinline _shuf_wzzy& _shuf_wzzy::operator=(_float4& v) { x = v.w; y = v.z; z = v.z; w = v.y; return *this; }
__forceinline _shuf_wzzz& _shuf_wzzz::operator=(_float4& v) { x = v.w; y = v.z; z = v.z; w = v.z; return *this; }
__forceinline _shuf_wzzw& _shuf_wzzw::operator=(_float4& v) { x = v.w; y = v.z; z = v.z; w = v.w; return *this; }
__forceinline _shuf_wzwx& _shuf_wzwx::operator=(_float4& v) { x = v.w; y = v.z; z = v.w; w = v.x; return *this; }
__forceinline _shuf_wzwy& _shuf_wzwy::operator=(_float4& v) { x = v.w; y = v.z; z = v.w; w = v.y; return *this; }
__forceinline _shuf_wzwz& _shuf_wzwz::operator=(_float4& v) { x = v.w; y = v.z; z = v.w; w = v.z; return *this; }
__forceinline _shuf_wzww& _shuf_wzww::operator=(_float4& v) { x = v.w; y = v.z; z = v.w; w = v.w; return *this; }
__forceinline _shuf_wwxx& _shuf_wwxx::operator=(_float4& v) { x = v.w; y = v.w; z = v.x; w = v.x; return *this; }
__forceinline _shuf_wwxy& _shuf_wwxy::operator=(_float4& v) { x = v.w; y = v.w; z = v.x; w = v.y; return *this; }
__forceinline _shuf_wwxz& _shuf_wwxz::operator=(_float4& v) { x = v.w; y = v.w; z = v.x; w = v.z; return *this; }
__forceinline _shuf_wwxw& _shuf_wwxw::operator=(_float4& v) { x = v.w; y = v.w; z = v.x; w = v.w; return *this; }
__forceinline _shuf_wwyx& _shuf_wwyx::operator=(_float4& v) { x = v.w; y = v.w; z = v.y; w = v.x; return *this; }
__forceinline _shuf_wwyy& _shuf_wwyy::operator=(_float4& v) { x = v.w; y = v.w; z = v.y; w = v.y; return *this; }
__forceinline _shuf_wwyz& _shuf_wwyz::operator=(_float4& v) { x = v.w; y = v.w; z = v.y; w = v.z; return *this; }
__forceinline _shuf_wwyw& _shuf_wwyw::operator=(_float4& v) { x = v.w; y = v.w; z = v.y; w = v.w; return *this; }
__forceinline _shuf_wwzx& _shuf_wwzx::operator=(_float4& v) { x = v.w; y = v.w; z = v.z; w = v.x; return *this; }
__forceinline _shuf_wwzy& _shuf_wwzy::operator=(_float4& v) { x = v.w; y = v.w; z = v.z; w = v.y; return *this; }
__forceinline _shuf_wwzz& _shuf_wwzz::operator=(_float4& v) { x = v.w; y = v.w; z = v.z; w = v.z; return *this; }
__forceinline _shuf_wwzw& _shuf_wwzw::operator=(_float4& v) { x = v.w; y = v.w; z = v.z; w = v.w; return *this; }
__forceinline _shuf_wwwx& _shuf_wwwx::operator=(_float4& v) { x = v.w; y = v.w; z = v.w; w = v.x; return *this; }
__forceinline _shuf_wwwy& _shuf_wwwy::operator=(_float4& v) { x = v.w; y = v.w; z = v.w; w = v.y; return *this; }
__forceinline _shuf_wwwz& _shuf_wwwz::operator=(_float4& v) { x = v.w; y = v.w; z = v.w; w = v.z; return *this; }
__forceinline _shuf_wwww& _shuf_wwww::operator=(_float4& v) { x = v.w; y = v.w; z = v.w; w = v.w; return *this; }