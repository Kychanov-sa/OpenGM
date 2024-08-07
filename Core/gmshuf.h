/// <summary>
/// OpenGM library shufle types.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>12-07-2004</created>
/// <copyright>Copyright 2004-2024 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifdef GMSHUF_H
	#error Nested inclusion of gmshuf.h
#else
	#define GMSHUF_H
#endif

struct _shuf_xy	{	float x, y;	_shuf_xy& operator=(_float2& v);	};
struct _shuf_yx	{	float x, y;	_shuf_yx& operator=(_float2& v);	};
struct _shuf_xx	{	float x, y;	_shuf_xx& operator=(_float2& v);	};
struct _shuf_yy	{	float x, y;	_shuf_yy& operator=(_float2& v);	};

struct _shuf_xxx	{	float x, y, z;	_shuf_xxx& operator=(_float3& v);	};
struct _shuf_xxy	{	float x, y, z;	_shuf_xxy& operator=(_float3& v);	};
struct _shuf_xxz	{	float x, y, z;	_shuf_xxz& operator=(_float3& v);	};
struct _shuf_xyx	{	float x, y, z;	_shuf_xyx& operator=(_float3& v);	};
struct _shuf_xyy	{	float x, y, z;	_shuf_xyy& operator=(_float3& v);	};
struct _shuf_xyz	{	float x, y, z;	_shuf_xyz& operator=(_float3& v);	};
struct _shuf_xzx	{	float x, y, z;	_shuf_xzx& operator=(_float3& v);	};
struct _shuf_xzy	{	float x, y, z;	_shuf_xzy& operator=(_float3& v);	};
struct _shuf_xzz	{	float x, y, z;	_shuf_xzz& operator=(_float3& v);	};
struct _shuf_yxx	{	float x, y, z;	_shuf_yxx& operator=(_float3& v);	};
struct _shuf_yxy	{	float x, y, z;	_shuf_yxy& operator=(_float3& v);	};
struct _shuf_yxz	{	float x, y, z;	_shuf_yxz& operator=(_float3& v);	};
struct _shuf_yyx	{	float x, y, z;	_shuf_yyx& operator=(_float3& v);	};
struct _shuf_yyy	{	float x, y, z;	_shuf_yyy& operator=(_float3& v);	};
struct _shuf_yyz	{	float x, y, z;	_shuf_yyz& operator=(_float3& v);	};
struct _shuf_yzx	{	float x, y, z;	_shuf_yzx& operator=(_float3& v);	};
struct _shuf_yzy	{	float x, y, z;	_shuf_yzy& operator=(_float3& v);	};
struct _shuf_yzz	{	float x, y, z;	_shuf_yzz& operator=(_float3& v);	};
struct _shuf_zxx	{	float x, y, z;	_shuf_zxx& operator=(_float3& v);	};
struct _shuf_zxy	{	float x, y, z;	_shuf_zxy& operator=(_float3& v);	};
struct _shuf_zxz	{	float x, y, z;	_shuf_zxz& operator=(_float3& v);	};
struct _shuf_zyx	{	float x, y, z;	_shuf_zyx& operator=(_float3& v);	};
struct _shuf_zyy	{	float x, y, z;	_shuf_zyy& operator=(_float3& v);	};
struct _shuf_zyz	{	float x, y, z;	_shuf_zyz& operator=(_float3& v);	};
struct _shuf_zzx	{	float x, y, z;	_shuf_zzx& operator=(_float3& v);	};
struct _shuf_zzy	{	float x, y, z;	_shuf_zzy& operator=(_float3& v);	};
struct _shuf_zzz	{	float x, y, z;	_shuf_zzz& operator=(_float3& v);	};

struct _shuf_xxxx	{	float x, y, z, w; _shuf_xxxx& operator=(_float4& v);	};
struct _shuf_xxxy	{	float x, y, z, w; _shuf_xxxy& operator=(_float4& v);	};
struct _shuf_xxxz	{	float x, y, z, w; _shuf_xxxz& operator=(_float4& v);	};
struct _shuf_xxxw	{	float x, y, z, w; _shuf_xxxw& operator=(_float4& v);	};
struct _shuf_xxyx	{	float x, y, z, w; _shuf_xxyx& operator=(_float4& v);	};
struct _shuf_xxyy	{	float x, y, z, w; _shuf_xxyy& operator=(_float4& v);	};
struct _shuf_xxyz	{	float x, y, z, w; _shuf_xxyz& operator=(_float4& v);	};
struct _shuf_xxyw	{	float x, y, z, w; _shuf_xxyw& operator=(_float4& v);	};
struct _shuf_xxzx	{	float x, y, z, w; _shuf_xxzx& operator=(_float4& v);	};
struct _shuf_xxzy	{	float x, y, z, w; _shuf_xxzy& operator=(_float4& v);	};
struct _shuf_xxzz	{	float x, y, z, w; _shuf_xxzz& operator=(_float4& v);	};
struct _shuf_xxzw	{	float x, y, z, w; _shuf_xxzw& operator=(_float4& v);	};
struct _shuf_xxwx	{	float x, y, z, w; _shuf_xxwx& operator=(_float4& v);	};
struct _shuf_xxwy	{	float x, y, z, w; _shuf_xxwy& operator=(_float4& v);	};
struct _shuf_xxwz	{	float x, y, z, w; _shuf_xxwz& operator=(_float4& v);	};
struct _shuf_xxww	{	float x, y, z, w; _shuf_xxww& operator=(_float4& v);	};
struct _shuf_xyxx	{	float x, y, z, w; _shuf_xyxx& operator=(_float4& v);	};
struct _shuf_xyxy	{	float x, y, z, w; _shuf_xyxy& operator=(_float4& v);	};
struct _shuf_xyxz	{	float x, y, z, w; _shuf_xyxz& operator=(_float4& v);	};
struct _shuf_xyxw	{	float x, y, z, w; _shuf_xyxw& operator=(_float4& v);	};
struct _shuf_xyyx	{	float x, y, z, w; _shuf_xyyx& operator=(_float4& v);	};
struct _shuf_xyyy	{	float x, y, z, w; _shuf_xyyy& operator=(_float4& v);	};
struct _shuf_xyyz	{	float x, y, z, w; _shuf_xyyz& operator=(_float4& v);	};
struct _shuf_xyyw	{	float x, y, z, w; _shuf_xyyw& operator=(_float4& v);	};
struct _shuf_xyzx	{	float x, y, z, w; _shuf_xyzx& operator=(_float4& v);	};
struct _shuf_xyzy	{	float x, y, z, w; _shuf_xyzy& operator=(_float4& v);	};
struct _shuf_xyzz	{	float x, y, z, w; _shuf_xyzz& operator=(_float4& v);	};
struct _shuf_xyzw	{	float x, y, z, w; _shuf_xyzw& operator=(_float4& v);	};
struct _shuf_xywx	{	float x, y, z, w; _shuf_xywx& operator=(_float4& v);	};
struct _shuf_xywy	{	float x, y, z, w; _shuf_xywy& operator=(_float4& v);	};
struct _shuf_xywz	{	float x, y, z, w; _shuf_xywz& operator=(_float4& v);	};
struct _shuf_xyww	{	float x, y, z, w; _shuf_xyww& operator=(_float4& v);	};
struct _shuf_xzxx	{	float x, y, z, w; _shuf_xzxx& operator=(_float4& v);	};
struct _shuf_xzxy	{	float x, y, z, w; _shuf_xzxy& operator=(_float4& v);	};
struct _shuf_xzxz	{	float x, y, z, w; _shuf_xzxz& operator=(_float4& v);	};
struct _shuf_xzxw	{	float x, y, z, w; _shuf_xzxw& operator=(_float4& v);	};
struct _shuf_xzyx	{	float x, y, z, w; _shuf_xzyx& operator=(_float4& v);	};
struct _shuf_xzyy	{	float x, y, z, w; _shuf_xzyy& operator=(_float4& v);	};
struct _shuf_xzyz	{	float x, y, z, w; _shuf_xzyz& operator=(_float4& v);	};
struct _shuf_xzyw	{	float x, y, z, w; _shuf_xzyw& operator=(_float4& v);	};
struct _shuf_xzzx	{	float x, y, z, w; _shuf_xzzx& operator=(_float4& v);	};
struct _shuf_xzzy	{	float x, y, z, w; _shuf_xzzy& operator=(_float4& v);	};
struct _shuf_xzzz	{	float x, y, z, w; _shuf_xzzz& operator=(_float4& v);	};
struct _shuf_xzzw	{	float x, y, z, w; _shuf_xzzw& operator=(_float4& v);	};
struct _shuf_xzwx	{	float x, y, z, w; _shuf_xzwx& operator=(_float4& v);	};
struct _shuf_xzwy	{	float x, y, z, w; _shuf_xzwy& operator=(_float4& v);	};
struct _shuf_xzwz	{	float x, y, z, w; _shuf_xzwz& operator=(_float4& v);	};
struct _shuf_xzww	{	float x, y, z, w; _shuf_xzww& operator=(_float4& v);	};
struct _shuf_xwxx	{	float x, y, z, w; _shuf_xwxx& operator=(_float4& v);	};
struct _shuf_xwxy	{	float x, y, z, w; _shuf_xwxy& operator=(_float4& v);	};
struct _shuf_xwxz	{	float x, y, z, w; _shuf_xwxz& operator=(_float4& v);	};
struct _shuf_xwxw	{	float x, y, z, w; _shuf_xwxw& operator=(_float4& v);	};
struct _shuf_xwyx	{	float x, y, z, w; _shuf_xwyx& operator=(_float4& v);	};
struct _shuf_xwyy	{	float x, y, z, w; _shuf_xwyy& operator=(_float4& v);	};
struct _shuf_xwyz	{	float x, y, z, w; _shuf_xwyz& operator=(_float4& v);	};
struct _shuf_xwyw	{	float x, y, z, w; _shuf_xwyw& operator=(_float4& v);	};
struct _shuf_xwzx	{	float x, y, z, w; _shuf_xwzx& operator=(_float4& v);	};
struct _shuf_xwzy	{	float x, y, z, w; _shuf_xwzy& operator=(_float4& v);	};
struct _shuf_xwzz	{	float x, y, z, w; _shuf_xwzz& operator=(_float4& v);	};
struct _shuf_xwzw	{	float x, y, z, w; _shuf_xwzw& operator=(_float4& v);	};
struct _shuf_xwwx	{	float x, y, z, w; _shuf_xwwx& operator=(_float4& v);	};
struct _shuf_xwwy	{	float x, y, z, w; _shuf_xwwy& operator=(_float4& v);	};
struct _shuf_xwwz	{	float x, y, z, w; _shuf_xwwz& operator=(_float4& v);	};
struct _shuf_xwww	{	float x, y, z, w; _shuf_xwww& operator=(_float4& v);	};
struct _shuf_yxxx	{	float x, y, z, w; _shuf_yxxx& operator=(_float4& v);	};
struct _shuf_yxxy	{	float x, y, z, w; _shuf_yxxy& operator=(_float4& v);	};
struct _shuf_yxxz	{	float x, y, z, w; _shuf_yxxz& operator=(_float4& v);	};
struct _shuf_yxxw	{	float x, y, z, w; _shuf_yxxw& operator=(_float4& v);	};
struct _shuf_yxyx	{	float x, y, z, w; _shuf_yxyx& operator=(_float4& v);	};
struct _shuf_yxyy	{	float x, y, z, w; _shuf_yxyy& operator=(_float4& v);	};
struct _shuf_yxyz	{	float x, y, z, w; _shuf_yxyz& operator=(_float4& v);	};
struct _shuf_yxyw	{	float x, y, z, w; _shuf_yxyw& operator=(_float4& v);	};
struct _shuf_yxzx	{	float x, y, z, w; _shuf_yxzx& operator=(_float4& v);	};
struct _shuf_yxzy	{	float x, y, z, w; _shuf_yxzy& operator=(_float4& v);	};
struct _shuf_yxzz	{	float x, y, z, w; _shuf_yxzz& operator=(_float4& v);	};
struct _shuf_yxzw	{	float x, y, z, w; _shuf_yxzw& operator=(_float4& v);	};
struct _shuf_yxwx	{	float x, y, z, w; _shuf_yxwx& operator=(_float4& v);	};
struct _shuf_yxwy	{	float x, y, z, w; _shuf_yxwy& operator=(_float4& v);	};
struct _shuf_yxwz	{	float x, y, z, w; _shuf_yxwz& operator=(_float4& v);	};
struct _shuf_yxww	{	float x, y, z, w; _shuf_yxww& operator=(_float4& v);	};
struct _shuf_yyxx	{	float x, y, z, w; _shuf_yyxx& operator=(_float4& v);	};
struct _shuf_yyxy	{	float x, y, z, w; _shuf_yyxy& operator=(_float4& v);	};
struct _shuf_yyxz	{	float x, y, z, w; _shuf_yyxz& operator=(_float4& v);	};
struct _shuf_yyxw	{	float x, y, z, w; _shuf_yyxw& operator=(_float4& v);	};
struct _shuf_yyyx	{	float x, y, z, w; _shuf_yyyx& operator=(_float4& v);	};
struct _shuf_yyyy	{	float x, y, z, w; _shuf_yyyy& operator=(_float4& v);	};
struct _shuf_yyyz	{	float x, y, z, w; _shuf_yyyz& operator=(_float4& v);	};
struct _shuf_yyyw	{	float x, y, z, w; _shuf_yyyw& operator=(_float4& v);	};
struct _shuf_yyzx	{	float x, y, z, w; _shuf_yyzx& operator=(_float4& v);	};
struct _shuf_yyzy	{	float x, y, z, w; _shuf_yyzy& operator=(_float4& v);	};
struct _shuf_yyzz	{	float x, y, z, w; _shuf_yyzz& operator=(_float4& v);	};
struct _shuf_yyzw	{	float x, y, z, w; _shuf_yyzw& operator=(_float4& v);	};
struct _shuf_yywx	{	float x, y, z, w; _shuf_yywx& operator=(_float4& v);	};
struct _shuf_yywy	{	float x, y, z, w; _shuf_yywy& operator=(_float4& v);	};
struct _shuf_yywz	{	float x, y, z, w; _shuf_yywz& operator=(_float4& v);	};
struct _shuf_yyww	{	float x, y, z, w; _shuf_yyww& operator=(_float4& v);	};
struct _shuf_yzxx	{	float x, y, z, w; _shuf_yzxx& operator=(_float4& v);	};
struct _shuf_yzxy	{	float x, y, z, w; _shuf_yzxy& operator=(_float4& v);	};
struct _shuf_yzxz	{	float x, y, z, w; _shuf_yzxz& operator=(_float4& v);	};
struct _shuf_yzxw	{	float x, y, z, w; _shuf_yzxw& operator=(_float4& v);	};
struct _shuf_yzyx	{	float x, y, z, w; _shuf_yzyx& operator=(_float4& v);	};
struct _shuf_yzyy	{	float x, y, z, w; _shuf_yzyy& operator=(_float4& v);	};
struct _shuf_yzyz	{	float x, y, z, w; _shuf_yzyz& operator=(_float4& v);	};
struct _shuf_yzyw	{	float x, y, z, w; _shuf_yzyw& operator=(_float4& v);	};
struct _shuf_yzzx	{	float x, y, z, w; _shuf_yzzx& operator=(_float4& v);	};
struct _shuf_yzzy	{	float x, y, z, w; _shuf_yzzy& operator=(_float4& v);	};
struct _shuf_yzzz	{	float x, y, z, w; _shuf_yzzz& operator=(_float4& v);	};
struct _shuf_yzzw	{	float x, y, z, w; _shuf_yzzw& operator=(_float4& v);	};
struct _shuf_yzwx	{	float x, y, z, w; _shuf_yzwx& operator=(_float4& v);	};
struct _shuf_yzwy	{	float x, y, z, w; _shuf_yzwy& operator=(_float4& v);	};
struct _shuf_yzwz	{	float x, y, z, w; _shuf_yzwz& operator=(_float4& v);	};
struct _shuf_yzww	{	float x, y, z, w; _shuf_yzww& operator=(_float4& v);	};
struct _shuf_ywxx	{	float x, y, z, w; _shuf_ywxx& operator=(_float4& v);	};
struct _shuf_ywxy	{	float x, y, z, w; _shuf_ywxy& operator=(_float4& v);	};
struct _shuf_ywxz	{	float x, y, z, w; _shuf_ywxz& operator=(_float4& v);	};
struct _shuf_ywxw	{	float x, y, z, w; _shuf_ywxw& operator=(_float4& v);	};
struct _shuf_ywyx	{	float x, y, z, w; _shuf_ywyx& operator=(_float4& v);	};
struct _shuf_ywyy	{	float x, y, z, w; _shuf_ywyy& operator=(_float4& v);	};
struct _shuf_ywyz	{	float x, y, z, w; _shuf_ywyz& operator=(_float4& v);	};
struct _shuf_ywyw	{	float x, y, z, w; _shuf_ywyw& operator=(_float4& v);	};
struct _shuf_ywzx	{	float x, y, z, w; _shuf_ywzx& operator=(_float4& v);	};
struct _shuf_ywzy	{	float x, y, z, w; _shuf_ywzy& operator=(_float4& v);	};
struct _shuf_ywzz	{	float x, y, z, w; _shuf_ywzz& operator=(_float4& v);	};
struct _shuf_ywzw	{	float x, y, z, w; _shuf_ywzw& operator=(_float4& v);	};
struct _shuf_ywwx	{	float x, y, z, w; _shuf_ywwx& operator=(_float4& v);	};
struct _shuf_ywwy	{	float x, y, z, w; _shuf_ywwy& operator=(_float4& v);	};
struct _shuf_ywwz	{	float x, y, z, w; _shuf_ywwz& operator=(_float4& v);	};
struct _shuf_ywww	{	float x, y, z, w; _shuf_ywww& operator=(_float4& v);	};
struct _shuf_zxxx	{	float x, y, z, w; _shuf_zxxx& operator=(_float4& v);	};
struct _shuf_zxxy	{	float x, y, z, w; _shuf_zxxy& operator=(_float4& v);	};
struct _shuf_zxxz	{	float x, y, z, w; _shuf_zxxz& operator=(_float4& v);	};
struct _shuf_zxxw	{	float x, y, z, w; _shuf_zxxw& operator=(_float4& v);	};
struct _shuf_zxyx	{	float x, y, z, w; _shuf_zxyx& operator=(_float4& v);	};
struct _shuf_zxyy	{	float x, y, z, w; _shuf_zxyy& operator=(_float4& v);	};
struct _shuf_zxyz	{	float x, y, z, w; _shuf_zxyz& operator=(_float4& v);	};
struct _shuf_zxyw	{	float x, y, z, w; _shuf_zxyw& operator=(_float4& v);	};
struct _shuf_zxzx	{	float x, y, z, w; _shuf_zxzx& operator=(_float4& v);	};
struct _shuf_zxzy	{	float x, y, z, w; _shuf_zxzy& operator=(_float4& v);	};
struct _shuf_zxzz	{	float x, y, z, w; _shuf_zxzz& operator=(_float4& v);	};
struct _shuf_zxzw	{	float x, y, z, w; _shuf_zxzw& operator=(_float4& v);	};
struct _shuf_zxwx	{	float x, y, z, w; _shuf_zxwx& operator=(_float4& v);	};
struct _shuf_zxwy	{	float x, y, z, w; _shuf_zxwy& operator=(_float4& v);	};
struct _shuf_zxwz	{	float x, y, z, w; _shuf_zxwz& operator=(_float4& v);	};
struct _shuf_zxww	{	float x, y, z, w; _shuf_zxww& operator=(_float4& v);	};
struct _shuf_zyxx	{	float x, y, z, w; _shuf_zyxx& operator=(_float4& v);	};
struct _shuf_zyxy	{	float x, y, z, w; _shuf_zyxy& operator=(_float4& v);	};
struct _shuf_zyxz	{	float x, y, z, w; _shuf_zyxz& operator=(_float4& v);	};
struct _shuf_zyxw	{	float x, y, z, w; _shuf_zyxw& operator=(_float4& v);	};
struct _shuf_zyyx	{	float x, y, z, w; _shuf_zyyx& operator=(_float4& v);	};
struct _shuf_zyyy	{	float x, y, z, w; _shuf_zyyy& operator=(_float4& v);	};
struct _shuf_zyyz	{	float x, y, z, w; _shuf_zyyz& operator=(_float4& v);	};
struct _shuf_zyyw	{	float x, y, z, w; _shuf_zyyw& operator=(_float4& v);	};
struct _shuf_zyzx	{	float x, y, z, w; _shuf_zyzx& operator=(_float4& v);	};
struct _shuf_zyzy	{	float x, y, z, w; _shuf_zyzy& operator=(_float4& v);	};
struct _shuf_zyzz	{	float x, y, z, w; _shuf_zyzz& operator=(_float4& v);	};
struct _shuf_zyzw	{	float x, y, z, w; _shuf_zyzw& operator=(_float4& v);	};
struct _shuf_zywx	{	float x, y, z, w; _shuf_zywx& operator=(_float4& v);	};
struct _shuf_zywy	{	float x, y, z, w; _shuf_zywy& operator=(_float4& v);	};
struct _shuf_zywz	{	float x, y, z, w; _shuf_zywz& operator=(_float4& v);	};
struct _shuf_zyww	{	float x, y, z, w; _shuf_zyww& operator=(_float4& v);	};
struct _shuf_zzxx	{	float x, y, z, w; _shuf_zzxx& operator=(_float4& v);	};
struct _shuf_zzxy	{	float x, y, z, w; _shuf_zzxy& operator=(_float4& v);	};
struct _shuf_zzxz	{	float x, y, z, w; _shuf_zzxz& operator=(_float4& v);	};
struct _shuf_zzxw	{	float x, y, z, w; _shuf_zzxw& operator=(_float4& v);	};
struct _shuf_zzyx	{	float x, y, z, w; _shuf_zzyx& operator=(_float4& v);	};
struct _shuf_zzyy	{	float x, y, z, w; _shuf_zzyy& operator=(_float4& v);	};
struct _shuf_zzyz	{	float x, y, z, w; _shuf_zzyz& operator=(_float4& v);	};
struct _shuf_zzyw	{	float x, y, z, w; _shuf_zzyw& operator=(_float4& v);	};
struct _shuf_zzzx	{	float x, y, z, w; _shuf_zzzx& operator=(_float4& v);	};
struct _shuf_zzzy	{	float x, y, z, w; _shuf_zzzy& operator=(_float4& v);	};
struct _shuf_zzzz	{	float x, y, z, w; _shuf_zzzz& operator=(_float4& v);	};
struct _shuf_zzzw	{	float x, y, z, w; _shuf_zzzw& operator=(_float4& v);	};
struct _shuf_zzwx	{	float x, y, z, w; _shuf_zzwx& operator=(_float4& v);	};
struct _shuf_zzwy	{	float x, y, z, w; _shuf_zzwy& operator=(_float4& v);	};
struct _shuf_zzwz	{	float x, y, z, w; _shuf_zzwz& operator=(_float4& v);	};
struct _shuf_zzww	{	float x, y, z, w; _shuf_zzww& operator=(_float4& v);	};
struct _shuf_zwxx	{	float x, y, z, w; _shuf_zwxx& operator=(_float4& v);	};
struct _shuf_zwxy	{	float x, y, z, w; _shuf_zwxy& operator=(_float4& v);	};
struct _shuf_zwxz	{	float x, y, z, w; _shuf_zwxz& operator=(_float4& v);	};
struct _shuf_zwxw	{	float x, y, z, w; _shuf_zwxw& operator=(_float4& v);	};
struct _shuf_zwyx	{	float x, y, z, w; _shuf_zwyx& operator=(_float4& v);	};
struct _shuf_zwyy	{	float x, y, z, w; _shuf_zwyy& operator=(_float4& v);	};
struct _shuf_zwyz	{	float x, y, z, w; _shuf_zwyz& operator=(_float4& v);	};
struct _shuf_zwyw	{	float x, y, z, w; _shuf_zwyw& operator=(_float4& v);	};
struct _shuf_zwzx	{	float x, y, z, w; _shuf_zwzx& operator=(_float4& v);	};
struct _shuf_zwzy	{	float x, y, z, w; _shuf_zwzy& operator=(_float4& v);	};
struct _shuf_zwzz	{	float x, y, z, w; _shuf_zwzz& operator=(_float4& v);	};
struct _shuf_zwzw	{	float x, y, z, w; _shuf_zwzw& operator=(_float4& v);	};
struct _shuf_zwwx	{	float x, y, z, w; _shuf_zwwx& operator=(_float4& v);	};
struct _shuf_zwwy	{	float x, y, z, w; _shuf_zwwy& operator=(_float4& v);	};
struct _shuf_zwwz	{	float x, y, z, w; _shuf_zwwz& operator=(_float4& v);	};
struct _shuf_zwww	{	float x, y, z, w; _shuf_zwww& operator=(_float4& v);	};
struct _shuf_wxxx	{	float x, y, z, w; _shuf_wxxx& operator=(_float4& v);	};
struct _shuf_wxxy	{	float x, y, z, w; _shuf_wxxy& operator=(_float4& v);	};
struct _shuf_wxxz	{	float x, y, z, w; _shuf_wxxz& operator=(_float4& v);	};
struct _shuf_wxxw	{	float x, y, z, w; _shuf_wxxw& operator=(_float4& v);	};
struct _shuf_wxyx	{	float x, y, z, w; _shuf_wxyx& operator=(_float4& v);	};
struct _shuf_wxyy	{	float x, y, z, w; _shuf_wxyy& operator=(_float4& v);	};
struct _shuf_wxyz	{	float x, y, z, w; _shuf_wxyz& operator=(_float4& v);	};
struct _shuf_wxyw	{	float x, y, z, w; _shuf_wxyw& operator=(_float4& v);	};
struct _shuf_wxzx	{	float x, y, z, w; _shuf_wxzx& operator=(_float4& v);	};
struct _shuf_wxzy	{	float x, y, z, w; _shuf_wxzy& operator=(_float4& v);	};
struct _shuf_wxzz	{	float x, y, z, w; _shuf_wxzz& operator=(_float4& v);	};
struct _shuf_wxzw	{	float x, y, z, w; _shuf_wxzw& operator=(_float4& v);	};
struct _shuf_wxwx	{	float x, y, z, w; _shuf_wxwx& operator=(_float4& v);	};
struct _shuf_wxwy	{	float x, y, z, w; _shuf_wxwy& operator=(_float4& v);	};
struct _shuf_wxwz	{	float x, y, z, w; _shuf_wxwz& operator=(_float4& v);	};
struct _shuf_wxww	{	float x, y, z, w; _shuf_wxww& operator=(_float4& v);	};
struct _shuf_wyxx	{	float x, y, z, w; _shuf_wyxx& operator=(_float4& v);	};
struct _shuf_wyxy	{	float x, y, z, w; _shuf_wyxy& operator=(_float4& v);	};
struct _shuf_wyxz	{	float x, y, z, w; _shuf_wyxz& operator=(_float4& v);	};
struct _shuf_wyxw	{	float x, y, z, w; _shuf_wyxw& operator=(_float4& v);	};
struct _shuf_wyyx	{	float x, y, z, w; _shuf_wyyx& operator=(_float4& v);	};
struct _shuf_wyyy	{	float x, y, z, w; _shuf_wyyy& operator=(_float4& v);	};
struct _shuf_wyyz	{	float x, y, z, w; _shuf_wyyz& operator=(_float4& v);	};
struct _shuf_wyyw	{	float x, y, z, w; _shuf_wyyw& operator=(_float4& v);	};
struct _shuf_wyzx	{	float x, y, z, w; _shuf_wyzx& operator=(_float4& v);	};
struct _shuf_wyzy	{	float x, y, z, w; _shuf_wyzy& operator=(_float4& v);	};
struct _shuf_wyzz	{	float x, y, z, w; _shuf_wyzz& operator=(_float4& v);	};
struct _shuf_wyzw	{	float x, y, z, w; _shuf_wyzw& operator=(_float4& v);	};
struct _shuf_wywx	{	float x, y, z, w; _shuf_wywx& operator=(_float4& v);	};
struct _shuf_wywy	{	float x, y, z, w; _shuf_wywy& operator=(_float4& v);	};
struct _shuf_wywz	{	float x, y, z, w; _shuf_wywz& operator=(_float4& v);	};
struct _shuf_wyww	{	float x, y, z, w; _shuf_wyww& operator=(_float4& v);	};
struct _shuf_wzxx	{	float x, y, z, w; _shuf_wzxx& operator=(_float4& v);	};
struct _shuf_wzxy	{	float x, y, z, w; _shuf_wzxy& operator=(_float4& v);	};
struct _shuf_wzxz	{	float x, y, z, w; _shuf_wzxz& operator=(_float4& v);	};
struct _shuf_wzxw	{	float x, y, z, w; _shuf_wzxw& operator=(_float4& v);	};
struct _shuf_wzyx	{	float x, y, z, w; _shuf_wzyx& operator=(_float4& v);	};
struct _shuf_wzyy	{	float x, y, z, w; _shuf_wzyy& operator=(_float4& v);	};
struct _shuf_wzyz	{	float x, y, z, w; _shuf_wzyz& operator=(_float4& v);	};
struct _shuf_wzyw	{	float x, y, z, w; _shuf_wzyw& operator=(_float4& v);	};
struct _shuf_wzzx	{	float x, y, z, w; _shuf_wzzx& operator=(_float4& v);	};
struct _shuf_wzzy	{	float x, y, z, w; _shuf_wzzy& operator=(_float4& v);	};
struct _shuf_wzzz	{	float x, y, z, w; _shuf_wzzz& operator=(_float4& v);	};
struct _shuf_wzzw	{	float x, y, z, w; _shuf_wzzw& operator=(_float4& v);	};
struct _shuf_wzwx	{	float x, y, z, w; _shuf_wzwx& operator=(_float4& v);	};
struct _shuf_wzwy	{	float x, y, z, w; _shuf_wzwy& operator=(_float4& v);	};
struct _shuf_wzwz	{	float x, y, z, w; _shuf_wzwz& operator=(_float4& v);	};
struct _shuf_wzww	{	float x, y, z, w; _shuf_wzww& operator=(_float4& v);	};
struct _shuf_wwxx	{	float x, y, z, w; _shuf_wwxx& operator=(_float4& v);	};
struct _shuf_wwxy	{	float x, y, z, w; _shuf_wwxy& operator=(_float4& v);	};
struct _shuf_wwxz	{	float x, y, z, w; _shuf_wwxz& operator=(_float4& v);	};
struct _shuf_wwxw	{	float x, y, z, w; _shuf_wwxw& operator=(_float4& v);	};
struct _shuf_wwyx	{	float x, y, z, w; _shuf_wwyx& operator=(_float4& v);	};
struct _shuf_wwyy	{	float x, y, z, w; _shuf_wwyy& operator=(_float4& v);	};
struct _shuf_wwyz	{	float x, y, z, w; _shuf_wwyz& operator=(_float4& v);	};
struct _shuf_wwyw	{	float x, y, z, w; _shuf_wwyw& operator=(_float4& v);	};
struct _shuf_wwzx	{	float x, y, z, w; _shuf_wwzx& operator=(_float4& v);	};
struct _shuf_wwzy	{	float x, y, z, w; _shuf_wwzy& operator=(_float4& v);	};
struct _shuf_wwzz	{	float x, y, z, w; _shuf_wwzz& operator=(_float4& v);	};
struct _shuf_wwzw	{	float x, y, z, w; _shuf_wwzw& operator=(_float4& v);	};
struct _shuf_wwwx	{	float x, y, z, w; _shuf_wwwx& operator=(_float4& v);	};
struct _shuf_wwwy	{	float x, y, z, w; _shuf_wwwy& operator=(_float4& v);	};
struct _shuf_wwwz	{	float x, y, z, w; _shuf_wwwz& operator=(_float4& v);	};
struct _shuf_wwww	{	float x, y, z, w; _shuf_wwww& operator=(_float4& v);	};