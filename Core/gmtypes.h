/// <summary>
/// OpenGM library types header.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>05-11-2008</created>
/// <copyright>Copyright 2004-2018 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifdef GMTYPES_H
	#error Nested inclusion of gmtypes.h
#else
	#define GMTYPES_H
#endif

typedef struct _float2
{
public:
	_float2() {};
	_float2(const float* f);
	_float2(float X, float Y);
	_float2(const _float2& V);

	// casting
    operator float* ();
    operator const float* () const;

	_float2 operator+ (const _float2& V) const;
	_float2 operator- (const _float2& V) const;
	_float2 operator* (const _float2& V) const;
	_float2 operator/ (const _float2& V) const;

	_float2 operator+ (float S) const;
	_float2 operator- (float S) const;
	_float2 operator* (float S) const;
	_float2 operator/ (float S) const;

	_float2 operator+ () const;
	_float2 operator- () const;

	_float2& operator+= (const _float2& V);
	_float2& operator-= (const _float2& V);	
	_float2& operator*= (const _float2& V);
	_float2& operator/= (const _float2& V);

	_float2& operator*= (float S);
	_float2& operator/= (float S);

	bool	operator== (const _float2& V) const;
	bool	operator!= (const _float2& V) const;

	_float2& operator=(_float2& V);
	_float2& operator=(const _float2& V);
	
public:
	union
	{
		struct
		{
			float x, y;
		};

		struct
		{
			float r, g;
		};
		float	v[2];

		// shuffles stuff
		_shuf_xx	xy;
		_shuf_yx	yx;
		_shuf_xx	xx;
		_shuf_yy	yy;
	};
} _float2;

typedef struct _float3
{
public:
	_float3() {};
	_float3(const float* f);
	_float3(float X, float Y, float Z);
	_float3(const _float2& V, float Z);
	_float3(const _float3& V);

	// casting
    operator float* ();
    operator const float* () const;

	_float3 operator+ (const _float3& V) const;
	_float3 operator- (const _float3& V) const;
	_float3 operator* (const _float3& V) const;
	_float3 operator/ (const _float3& V) const;
	
	_float3 operator+ (float S) const;
	_float3 operator- (float S) const;
	_float3 operator* (float S) const;
	_float3 operator/ (float S) const;

	_float3 operator+ () const;
	_float3 operator- () const;

	_float3& operator+= (const _float3& V);
	_float3& operator-= (const _float3& V);
	_float3& operator*= (const _float3& V);
	_float3& operator/= (const _float3& V);
	
	_float3& operator*= (float S);
	_float3& operator/= (float S);

	bool	operator== (const _float3& V) const;
	bool	operator!= (const _float3& V) const;

	_float3& operator=(_float3& V);
	_float3& operator=(const _float3& V);
	
public:
	union
	{
		struct
		{
			float x, y, z;
		};

		struct
		{
			float r, g, b;
		};

		struct
		{
			_float2	xy;
			float	z;
		};

		struct
		{
			_float2	rg;
			float	b;
		};

		struct
		{
			float	x;
			_float2	yz;
		};

		struct
		{
			float	r;
			_float2	gb;
		};

		float	v[3];

		// shuffles stuff
		_shuf_xxx	xxx;
		_shuf_xxy	xxy;
		_shuf_xxz	xxz;
		_shuf_xyx	xyx;
		_shuf_xyy	xyy;
		_shuf_xyz	xyz;
		_shuf_xzx	xzx;
		_shuf_xzy	xzy;
		_shuf_xzz	xzz;
		_shuf_yxx	yxx;
		_shuf_yxy	yxy;
		_shuf_yxz	yxz;
		_shuf_yyx	yyx;
		_shuf_yyy	yyy;
		_shuf_yyz	yyz;
		_shuf_yzx	yzx;
		_shuf_yzy	yzy;
		_shuf_yzz	yzz;
		_shuf_zxx	zxx;
		_shuf_zxy	zxy;
		_shuf_zxz	zxz;
		_shuf_zyx	zyx;
		_shuf_zyy	zyy;
		_shuf_zyz	zyz;
		_shuf_zzx	zzx;
		_shuf_zzy	zzy;
		_shuf_zzz	zzz;
	};
} _float3;

typedef struct _float4
{
public:
	_float4() {};
	_float4(const float* f);
	_float4(float X, float Y, float Z, float W);
	_float4(const _float2& V, float Z, float W);
	_float4(const _float2& V1, const _float2& V2);
	_float4(const _float3& V, float W);
	_float4(const _float4& V);	

	// casting
    operator float* ();
    operator const float* () const;	

	_float4 operator+ (const _float4& V) const;
	_float4 operator- (const _float4& V) const;
	_float4 operator* (const _float4& V) const;
	_float4 operator/ (const _float4& V) const;

	_float4 operator+ (float S) const;
	_float4 operator- (float S) const;
	_float4 operator* (float S) const;
	_float4 operator/ (float S) const;

	_float4 operator+ () const;
	_float4 operator- () const;

	_float4& operator+= (const _float4& V);
	_float4& operator-= (const _float4& V);
	_float4& operator*= (const _float4& V);
	_float4& operator/= (const _float4& V);
	
	_float4& operator*= (float S);
	_float4& operator/= (float S);

	bool	operator== (const _float4& V) const;
	bool	operator!= (const _float4& V) const;

	_float4& operator=(_float4& V);
	_float4& operator=(const _float4& V);
	
public:
	union
	{
		struct
		{
			float x, y, z, w;
		};

		struct
		{
			float r, g, b, a;
		};

		struct
		{
			_float2	xy;
			float	z, w;
		};

		struct
		{
			_float2	rg;
			float	b, a;
		};

		struct
		{
			float	x;
			_float2	yz;
			float	w;
		};

		struct
		{
			float	r;
			_float2	gb;
			float	a;
		};

		struct
		{
			float	x, y;
			_float2	zw;
		};

		struct
		{
			float	r, g;
			_float2	ga;
		};

		struct
		{
			_float3	xyz;
			float	w;
		};

		struct
		{
			_float3	rgb;
			float	a;
		};

		struct
		{
			float	x;
			_float3	yzw;
		};

		struct
		{
			float	r;
			_float3	gba;
		};

		float	v[4];

		// shuffles stuff
		_shuf_xxxx	xxxx;
		_shuf_xxxy	xxxy;
		_shuf_xxxz	xxxz;
		_shuf_xxxw	xxxw;
		_shuf_xxyx	xxyx;
		_shuf_xxyy	xxyy;
		_shuf_xxyz	xxyz;
		_shuf_xxyw	xxyw;
		_shuf_xxzx	xxzx;
		_shuf_xxzy	xxzy;
		_shuf_xxzz	xxzz;
		_shuf_xxzw	xxzw;
		_shuf_xxwx	xxwx;
		_shuf_xxwy	xxwy;
		_shuf_xxwz	xxwz;
		_shuf_xxww	xxww;
		_shuf_xyxx	xyxx;
		_shuf_xyxy	xyxy;
		_shuf_xyxz	xyxz;
		_shuf_xyxw	xyxw;
		_shuf_xyyx	xyyx;
		_shuf_xyyy	xyyy;
		_shuf_xyyz	xyyz;
		_shuf_xyyw	xyyw;
		_shuf_xyzx	xyzx;
		_shuf_xyzy	xyzy;
		_shuf_xyzz	xyzz;
		_shuf_xyzw	xyzw;
		_shuf_xywx	xywx;
		_shuf_xywy	xywy;
		_shuf_xywz	xywz;
		_shuf_xyww	xyww;
		_shuf_xzxx	xzxx;
		_shuf_xzxy	xzxy;
		_shuf_xzxz	xzxz;
		_shuf_xzxw	xzxw;
		_shuf_xzyx	xzyx;
		_shuf_xzyy	xzyy;
		_shuf_xzyz	xzyz;
		_shuf_xzyw	xzyw;
		_shuf_xzzx	xzzx;
		_shuf_xzzy	xzzy;
		_shuf_xzzz	xzzz;
		_shuf_xzzw	xzzw;
		_shuf_xzwx	xzwx;
		_shuf_xzwy	xzwy;
		_shuf_xzwz	xzwz;
		_shuf_xzww	xzww;
		_shuf_xwxx	xwxx;
		_shuf_xwxy	xwxy;
		_shuf_xwxz	xwxz;
		_shuf_xwxw	xwxw;
		_shuf_xwyx	xwyx;
		_shuf_xwyy	xwyy;
		_shuf_xwyz	xwyz;
		_shuf_xwyw	xwyw;
		_shuf_xwzx	xwzx;
		_shuf_xwzy	xwzy;
		_shuf_xwzz	xwzz;
		_shuf_xwzw	xwzw;
		_shuf_xwwx	xwwx;
		_shuf_xwwy	xwwy;
		_shuf_xwwz	xwwz;
		_shuf_xwww	xwww;
		_shuf_yxxx	yxxx;
		_shuf_yxxy	yxxy;
		_shuf_yxxz	yxxz;
		_shuf_yxxw	yxxw;
		_shuf_yxyx	yxyx;
		_shuf_yxyy	yxyy;
		_shuf_yxyz	yxyz;
		_shuf_yxyw	yxyw;
		_shuf_yxzx	yxzx;
		_shuf_yxzy	yxzy;
		_shuf_yxzz	yxzz;
		_shuf_yxzw	yxzw;
		_shuf_yxwx	yxwx;
		_shuf_yxwy	yxwy;
		_shuf_yxwz	yxwz;
		_shuf_yxww	yxww;
		_shuf_yyxx	yyxx;
		_shuf_yyxy	yyxy;
		_shuf_yyxz	yyxz;
		_shuf_yyxw	yyxw;
		_shuf_yyyx	yyyx;
		_shuf_yyyy	yyyy;
		_shuf_yyyz	yyyz;
		_shuf_yyyw	yyyw;
		_shuf_yyzx	yyzx;
		_shuf_yyzy	yyzy;
		_shuf_yyzz	yyzz;
		_shuf_yyzw	yyzw;
		_shuf_yywx	yywx;
		_shuf_yywy	yywy;
		_shuf_yywz	yywz;
		_shuf_yyww	yyww;
		_shuf_yzxx	yzxx;
		_shuf_yzxy	yzxy;
		_shuf_yzxz	yzxz;
		_shuf_yzxw	yzxw;
		_shuf_yzyx	yzyx;
		_shuf_yzyy	yzyy;
		_shuf_yzyz	yzyz;
		_shuf_yzyw	yzyw;
		_shuf_yzzx	yzzx;
		_shuf_yzzy	yzzy;
		_shuf_yzzz	yzzz;
		_shuf_yzzw	yzzw;
		_shuf_yzwx	yzwx;
		_shuf_yzwy	yzwy;
		_shuf_yzwz	yzwz;
		_shuf_yzww	yzww;
		_shuf_ywxx	ywxx;
		_shuf_ywxy	ywxy;
		_shuf_ywxz	ywxz;
		_shuf_ywxw	ywxw;
		_shuf_ywyx	ywyx;
		_shuf_ywyy	ywyy;
		_shuf_ywyz	ywyz;
		_shuf_ywyw	ywyw;
		_shuf_ywzx	ywzx;
		_shuf_ywzy	ywzy;
		_shuf_ywzz	ywzz;
		_shuf_ywzw	ywzw;
		_shuf_ywwx	ywwx;
		_shuf_ywwy	ywwy;
		_shuf_ywwz	ywwz;
		_shuf_ywww	ywww;
		_shuf_zxxx	zxxx;
		_shuf_zxxy	zxxy;
		_shuf_zxxz	zxxz;
		_shuf_zxxw	zxxw;
		_shuf_zxyx	zxyx;
		_shuf_zxyy	zxyy;
		_shuf_zxyz	zxyz;
		_shuf_zxyw	zxyw;
		_shuf_zxzx	zxzx;
		_shuf_zxzy	zxzy;
		_shuf_zxzz	zxzz;
		_shuf_zxzw	zxzw;
		_shuf_zxwx	zxwx;
		_shuf_zxwy	zxwy;
		_shuf_zxwz	zxwz;
		_shuf_zxww	zxww;
		_shuf_zyxx	zyxx;
		_shuf_zyxy	zyxy;
		_shuf_zyxz	zyxz;
		_shuf_zyxw	zyxw;
		_shuf_zyyx	zyyx;
		_shuf_zyyy	zyyy;
		_shuf_zyyz	zyyz;
		_shuf_zyyw	zyyw;
		_shuf_zyzx	zyzx;
		_shuf_zyzy	zyzy;
		_shuf_zyzz	zyzz;
		_shuf_zyzw	zyzw;
		_shuf_zywx	zywx;
		_shuf_zywy	zywy;
		_shuf_zywz	zywz;
		_shuf_zyww	zyww;
		_shuf_zzxx	zzxx;
		_shuf_zzxy	zzxy;
		_shuf_zzxz	zzxz;
		_shuf_zzxw	zzxw;
		_shuf_zzyx	zzyx;
		_shuf_zzyy	zzyy;
		_shuf_zzyz	zzyz;
		_shuf_zzyw	zzyw;
		_shuf_zzzx	zzzx;
		_shuf_zzzy	zzzy;
		_shuf_zzzz	zzzz;
		_shuf_zzzw	zzzw;
		_shuf_zzwx	zzwx;
		_shuf_zzwy	zzwy;
		_shuf_zzwz	zzwz;
		_shuf_zzww	zzww;
		_shuf_zwxx	zwxx;
		_shuf_zwxy	zwxy;
		_shuf_zwxz	zwxz;
		_shuf_zwxw	zwxw;
		_shuf_zwyx	zwyx;
		_shuf_zwyy	zwyy;
		_shuf_zwyz	zwyz;
		_shuf_zwyw	zwyw;
		_shuf_zwzx	zwzx;
		_shuf_zwzy	zwzy;
		_shuf_zwzz	zwzz;
		_shuf_zwzw	zwzw;
		_shuf_zwwx	zwwx;
		_shuf_zwwy	zwwy;
		_shuf_zwwz	zwwz;
		_shuf_zwww	zwww;
		_shuf_wxxx	wxxx;
		_shuf_wxxy	wxxy;
		_shuf_wxxz	wxxz;
		_shuf_wxxw	wxxw;
		_shuf_wxyx	wxyx;
		_shuf_wxyy	wxyy;
		_shuf_wxyz	wxyz;
		_shuf_wxyw	wxyw;
		_shuf_wxzx	wxzx;
		_shuf_wxzy	wxzy;
		_shuf_wxzz	wxzz;
		_shuf_wxzw	wxzw;
		_shuf_wxwx	wxwx;
		_shuf_wxwy	wxwy;
		_shuf_wxwz	wxwz;
		_shuf_wxww	wxww;
		_shuf_wyxx	wyxx;
		_shuf_wyxy	wyxy;
		_shuf_wyxz	wyxz;
		_shuf_wyxw	wyxw;
		_shuf_wyyx	wyyx;
		_shuf_wyyy	wyyy;
		_shuf_wyyz	wyyz;
		_shuf_wyyw	wyyw;
		_shuf_wyzx	wyzx;
		_shuf_wyzy	wyzy;
		_shuf_wyzz	wyzz;
		_shuf_wyzw	wyzw;
		_shuf_wywx	wywx;
		_shuf_wywy	wywy;
		_shuf_wywz	wywz;
		_shuf_wyww	wyww;
		_shuf_wzxx	wzxx;
		_shuf_wzxy	wzxy;
		_shuf_wzxz	wzxz;
		_shuf_wzxw	wzxw;
		_shuf_wzyx	wzyx;
		_shuf_wzyy	wzyy;
		_shuf_wzyz	wzyz;
		_shuf_wzyw	wzyw;
		_shuf_wzzx	wzzx;
		_shuf_wzzy	wzzy;
		_shuf_wzzz	wzzz;
		_shuf_wzzw	wzzw;
		_shuf_wzwx	wzwx;
		_shuf_wzwy	wzwy;
		_shuf_wzwz	wzwz;
		_shuf_wzww	wzww;
		_shuf_wwxx	wwxx;
		_shuf_wwxy	wwxy;
		_shuf_wwxz	wwxz;
		_shuf_wwxw	wwxw;
		_shuf_wwyx	wwyx;
		_shuf_wwyy	wwyy;
		_shuf_wwyz	wwyz;
		_shuf_wwyw	wwyw;
		_shuf_wwzx	wwzx;
		_shuf_wwzy	wwzy;
		_shuf_wwzz	wwzz;
		_shuf_wwzw	wwzw;
		_shuf_wwwx	wwwx;
		_shuf_wwwy	wwwy;
		_shuf_wwwz	wwwz;
		_shuf_wwww	wwww;
	};
} _float4;

typedef struct _float2x2
{
public:
	_float2x2() {};
	_float2x2(const float* f);
	_float2x2(float m00, float m01, float m10, float m11);
	_float2x2(_float2 m00_01, _float2 m10_11);
	_float2x2(_float2x2& M);

	// casting
    operator float* ();
    operator const float* () const;

	_float2x2 operator+ (float S) const;
	_float2x2 operator- (float S) const;
	_float2x2 operator* (float S) const;
	_float2x2 operator/ (float S) const;

	_float2x2 operator+ () const;
	_float2x2 operator- () const;

	_float2x2& operator=(_float2x2& M);
	_float2x2& operator=(const _float2x2& M);
	
public:
	union
	{
		struct
		{
			float _m00, _m01;
			float _m10, _m11;
		};

		struct
		{
			float _11, _12;
			float _21, _22;
		};

		struct
		{
			_float2	_m00_m01;
			_float2	_m10_m11;
		};

		struct
		{
			_float2 _11_12;
			_float2 _21_22;
		};

		float	m[4];
		float	_m[2][2];
	};
} _float2x2;

typedef struct _float2x3
{
public:
	_float2x3() {};
	_float2x3(const float* f);
	_float2x3(float m00, float m01, float m02,
			 float m10, float m11, float m12);
	_float2x3(_float3 m00_01_02, _float3 m10_11_12);
	_float2x3(_float2x3& M);

	// casting
    operator float* ();
    operator const float* () const;

	_float2x3 operator+ (float S) const;
	_float2x3 operator- (float S) const;
	_float2x3 operator* (float S) const;
	_float2x3 operator/ (float S) const;

	_float2x3 operator+ () const;
	_float2x3 operator- () const;

	_float2x3& operator=(_float2x3& M);
	_float2x3& operator=(const _float2x3& M);
	
public:
	union
	{
		struct
		{
			float _m00, _m01, _m02;
			float _m10, _m11, _m12;
		};

		struct
		{
			float _11, _12, _13;
			float _21, _22, _23;
		};

		struct
		{
			_float2	_m00_m01;
			float	_m02;
			_float2	_m10_m11;
			float	_m12;
		};

		struct
		{
			_float2	_11_12;
			float	_13;
			_float2	_21_22;
			float	_23;
		};

		struct
		{
			float	_m00;
			_float2	_m01_m02;
			float	_m10;
			_float2	_m11_m12;
		};
		
		struct
		{
			float	_11;
			_float2	_12_13;
			float	_21;
			_float2	_22_23;
		};

		struct
		{
			_float3	_m00_m01_m02;
			_float3	_m10_m11_m12;
		};

		struct
		{
			_float3	_11_12_13;
			_float3	_21_22_23;
		};

		float	m[6];
		float	_m[2][3];
	};
} _float2x3;

typedef struct _float2x4
{
public:
	_float2x4() {};
	_float2x4(const float* f);
	_float2x4(float m00, float m01, float m02, float m03,
			 float m10, float m11, float m12, float m13);
	_float2x4(_float4 m00_01_02_03, _float4 m10_11_12_13);
	_float2x4(_float2x4& M);

	// casting
    operator float* ();
    operator const float* () const;

	_float2x4 operator+ (float S) const;
	_float2x4 operator- (float S) const;
	_float2x4 operator* (float S) const;
	_float2x4 operator/ (float S) const;

	_float2x4 operator+ () const;
	_float2x4 operator- () const;

	_float2x4& operator=(_float2x4& M);
	_float2x4& operator=(const _float2x4& M);
	
public:
	union
	{
		struct
		{
			float _m00, _m01, _m02, _m03;
			float _m10, _m11, _m12, _m13;
		};

		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
		};

		struct
		{
			_float2	_m00_m01, _m02_m03;
			_float2	_m10_m11, _m12_m13;
		};

		struct
		{
			float	_m00;
			_float2	_m01_m02;
			float	_m03;
			float	_m10;
			_float2	_m11_m12;
			float	_m13;
		};

		struct
		{
			_float2	_11_12, _13_14;
			_float2	_21_22, _23_24;
		};

		struct
		{
			float	_11;
			_float2	_12_13;
			float	_14;
			float	_21;
			_float2	_22_23;
			float	_24;
		};

		struct
		{
			_float3	_m00_m01_m02;
			float	_m03;
			_float3	_m10_m11_m12;
			float	_m13;
		};

		struct
		{
			float	_m00;
			_float3	_m01_m02_m03;			
			float	_m10;
			_float3	_m11_m12_m13;			
		};

		struct
		{
			_float3	_11_12_13;
			float	_14;
			_float3	_21_22_23;
			float	_24;
		};

		struct
		{
			float	_11;
			_float3	_12_13_14;			
			float	_21;
			_float3	_22_23_24;
		};

		struct
		{
			_float4	_m00_m01_m02_m03;
			_float4	_m10_m11_m12_m13;
		};

		struct
		{
			_float4	_11_12_13_14;
			_float4	_21_22_23_24;
		};

		float	m[8];
		float	_m[2][4];
	};
} _float2x4;

typedef struct _float3x2
{
public:
	_float3x2() {};
	_float3x2(const float* f);
	_float3x2(float m00, float m01,
			 float m10, float m11,
			 float m20, float m21);
	_float3x2(_float2 m00_01, _float2 m10_11, _float2 m20_21);
	_float3x2(_float3x2& M);

	// casting
    operator float* ();
    operator const float* () const;

	_float3x2 operator+ (float S) const;
	_float3x2 operator- (float S) const;
	_float3x2 operator* (float S) const;
	_float3x2 operator/ (float S) const;

	_float3x2 operator+ () const;
	_float3x2 operator- () const;

	_float3x2& operator=(_float3x2& M);
	_float3x2& operator=(const _float3x2& M);
	
public:
	union
	{
		struct
		{
			float _m00, _m01;
			float _m10, _m11;
			float _m20, _m21;
		};

		struct
		{
			float _11, _12;
			float _21, _22;
			float _31, _32;
		};

		struct
		{
			_float2	_m00_m01;
			_float2	_m10_m11;
			_float2	_m20_m21;
		};

		struct
		{
			_float2 _11_12;
			_float2 _21_22;
			_float2 _31_32;
		};

		float	m[6];
		float	_m[3][2];
	};
} _float3x2;

typedef struct _float3x3
{
public:
	_float3x3() {};
	_float3x3(const float* f);
	_float3x3(float m00, float m01, float m02,
			 float m10, float m11, float m12,
			 float m20, float m21, float m22);
	_float3x3(_float3 m00_01_02, _float3 m10_11_12, _float3 m20_21_22);
	_float3x3(_float3x3& M);

	// casting
    operator float* ();
    operator const float* () const;

	_float3x3 operator+ (float S) const;
	_float3x3 operator- (float S) const;
	_float3x3 operator* (float S) const;
	_float3x3 operator/ (float S) const;

	_float3x3 operator+ () const;
	_float3x3 operator- () const;

	_float3x3& operator=(_float3x3& M);
	_float3x3& operator=(const _float3x3& M);
	
public:
	union
	{
		struct
		{
			float _m00, _m01, _m02;
			float _m10, _m11, _m12;
			float _m20, _m21, _m22;
		};

		struct
		{
			float _11, _12, _13;
			float _21, _22, _23;
			float _31, _32, _33;
		};

		struct
		{
			_float2	_m00_m01;
			float	_m02;
			_float2	_m10_m11;
			float	_m12;
			_float2	_m20_m21;
			float	_m22;
		};

		struct
		{
			_float2	_11_12;
			float	_13;
			_float2	_21_22;
			float	_23;
			_float2	_31_32;
			float	_33;
		};

		struct
		{
			float	_m00;
			_float2	_m01_m02;
			float	_m10;
			_float2	_m11_m12;
			float	_m20;
			_float2	_m21_m22;
		};
		
		struct
		{
			float	_11;
			_float2	_12_13;
			float	_21;
			_float2	_22_23;
			float	_31;
			_float2	_32_33;
		};

		struct
		{
			_float3	_m00_m01_m02;
			_float3	_m10_m11_m12;
			_float3	_m20_m21_m22;
		};

		struct
		{
			_float3	_11_12_13;
			_float3	_21_22_23;
			_float3	_31_32_33;
		};

		float	m[9];
		float	_m[3][3];
	};
} _float3x3;

typedef struct _float3x4
{
public:
	_float3x4() {};
	_float3x4(const float* f);
	_float3x4(float m00, float m01, float m02, float m03,
			 float m10, float m11, float m12, float m13,
			 float m20, float m21, float m22, float m23);
	_float3x4(_float4 m00_01_02_03, _float4 m10_11_12_13, _float4 m20_21_22_23);
	_float3x4(_float3x4& M);

	// casting
    operator float* ();
    operator const float* () const;

	_float3x4 operator+ (float S) const;
	_float3x4 operator- (float S) const;
	_float3x4 operator* (float S) const;
	_float3x4 operator/ (float S) const;

	_float3x4 operator+ () const;
	_float3x4 operator- () const;

	_float3x4& operator=(_float3x4& M);
	_float3x4& operator=(const _float3x4& M);
	
public:
	union
	{
		struct
		{
			float _m00, _m01, _m02, _m03;
			float _m10, _m11, _m12, _m13;
			float _m20, _m21, _m22, _m23;
		};

		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
		};

		struct
		{
			_float2	_m00_m01, _m02_m03;
			_float2	_m10_m11, _m12_m13;
			_float2	_m20_m21, _m22_m23;
		};

		struct
		{
			float	_m00;
			_float2	_m01_m02;
			float	_m03;
			float	_m10;
			_float2	_m11_m12;
			float	_m13;
			float	_m20;
			_float2	_m21_m22;
			float	_m23;
		};

		struct
		{
			_float2	_11_12, _13_14;
			_float2	_21_22, _23_24;
			_float2	_31_32, _33_34;
		};

		struct
		{
			float	_11;
			_float2	_12_13;
			float	_14;
			float	_21;
			_float2	_22_23;
			float	_24;
			float	_31;
			_float2	_32_33;
			float	_34;
		};

		struct
		{
			_float3	_m00_m01_m02;
			float	_m03;
			_float3	_m10_m11_m12;
			float	_m13;
			_float3	_m20_m21_m22;
			float	_m23;
		};

		struct
		{
			float	_m00;
			_float3	_m01_m02_m03;			
			float	_m10;
			_float3	_m11_m12_m13;
			float	_m20;
			_float3	_m21_m22_m23;
		};

		struct
		{
			_float3	_11_12_13;
			float	_14;
			_float3	_21_22_23;
			float	_24;
			_float3	_31_32_33;
			float	_34;
		};

		struct
		{
			float	_11;
			_float3	_12_13_14;			
			float	_21;
			_float3	_22_23_24;
			float	_31;
			_float3	_32_33_34;
		};

		struct
		{
			_float4	_m00_m01_m02_m03;
			_float4	_m10_m11_m12_m13;
			_float4	_m20_m21_m22_m23;
		};

		struct
		{
			_float4	_11_12_13_14;
			_float4	_21_22_23_24;
			_float4	_31_32_33_34;
		};

		float	m[12];
		float	_m[3][4];
	};
} _float3x4;

typedef struct _float4x2
{
public:
	_float4x2() {};
	_float4x2(const float* f);
	_float4x2(float m00, float m01,
			 float m10, float m11,
			 float m20, float m21,
			 float m30, float m31);
	_float4x2(_float2 m00_01, _float2 m10_11, _float2 m20_21, _float2 m30_31);
	_float4x2(_float4x2& M);

	// casting
    operator float* ();
    operator const float* () const;

	_float4x2 operator+ (float S) const;
	_float4x2 operator- (float S) const;
	_float4x2 operator* (float S) const;
	_float4x2 operator/ (float S) const;

	_float4x2 operator+ () const;
	_float4x2 operator- () const;

	_float4x2& operator=(_float4x2& M);
	_float4x2& operator=(const _float4x2& M);
	
public:
	union
	{
		struct
		{
			float _m00, _m01;
			float _m10, _m11;
			float _m20, _m21;
			float _m30, _m31;
		};

		struct
		{
			float _11, _12;
			float _21, _22;
			float _31, _32;
			float _41, _42;
		};

		struct
		{
			_float2	_m00_m01;
			_float2	_m10_m11;
			_float2	_m20_m21;
			_float2	_m30_m31;
		};

		struct
		{
			_float2 _11_12;
			_float2 _21_22;
			_float2 _31_32;
			_float2 _41_42;
		};

		float	m[8];
		float	_m[4][2];
	};
} _float4x2;

typedef struct _float4x3
{
public:
	_float4x3() {};
	_float4x3(const float* f);
	_float4x3(float m00, float m01, float m02,
			 float m10, float m11, float m12,
			 float m20, float m21, float m22,
			 float m30, float m31, float m32);
	_float4x3(_float3 m00_01_02, _float3 m10_11_12, _float3 m20_21_22, _float3 m30_31_32);
	_float4x3(_float4x3& M);

	// casting
    operator float* ();
    operator const float* () const;

	_float4x3 operator+ (float S) const;
	_float4x3 operator- (float S) const;
	_float4x3 operator* (float S) const;
	_float4x3 operator/ (float S) const;

	_float4x3 operator+ () const;
	_float4x3 operator- () const;

	_float4x3& operator=(_float4x3& M);
	_float4x3& operator=(const _float4x3& M);
	
public:
	union
	{
		struct
		{
			float _m00, _m01, _m02;
			float _m10, _m11, _m12;
			float _m20, _m21, _m22;
			float _m30, _m31, _m32;
		};

		struct
		{
			float _11, _12, _13;
			float _21, _22, _23;
			float _31, _32, _33;
			float _41, _42, _43;
		};

		struct
		{
			_float2	_m00_m01;
			float	_m02;
			_float2	_m10_m11;
			float	_m12;
			_float2	_m20_m21;
			float	_m22;
			_float2	_m30_m31;
			float	_m32;
		};

		struct
		{
			_float2	_11_12;
			float	_13;
			_float2	_21_22;
			float	_23;
			_float2	_31_32;
			float	_33;
			_float2	_41_42;
			float	_43;
		};

		struct
		{
			float	_m00;
			_float2	_m01_m02;
			float	_m10;
			_float2	_m11_m12;
			float	_m20;
			_float2	_m21_m22;
			float	_m30;
			_float2	_m31_m32;
		};
		
		struct
		{
			float	_11;
			_float2	_12_13;
			float	_21;
			_float2	_22_23;
			float	_31;
			_float2	_32_33;
			float	_41;
			_float2	_42_43;
		};

		struct
		{
			_float3	_m00_m01_m02;
			_float3	_m10_m11_m12;
			_float3	_m20_m21_m22;
			_float3	_m30_m31_m32;
		};

		struct
		{
			_float3	_11_12_13;
			_float3	_21_22_23;
			_float3	_31_32_33;
			_float3	_41_42_43;
		};

		float	m[12];
		float	_m[4][3];
	};
} _float4x3;

typedef struct _float4x4
{
public:
	_float4x4() {};
	_float4x4(const float* f);
	_float4x4(float m00, float m01, float m02, float m03,
			 float m10, float m11, float m12, float m13,
			 float m20, float m21, float m22, float m23,
			 float m30, float m31, float m32, float m33);
	_float4x4(_float4 m00_01_02_03, _float4 m10_11_12_13, _float4 m20_21_22_23, _float4 m30_31_32_33);
	_float4x4(_float4x4& M);

	// casting
    operator float* ();
    operator const float* () const;

	_float4x4 operator+ (float S) const;
	_float4x4 operator- (float S) const;
	_float4x4 operator* (float S) const;
	_float4x4 operator/ (float S) const;

	_float4x4 operator+ () const;
	_float4x4 operator- () const;

	_float4x4& operator=(_float4x4& M);
	_float4x4& operator=(const _float4x4& M);
	
public:
	union
	{
		struct
		{
			float _m00, _m01, _m02, _m03;
			float _m10, _m11, _m12, _m13;
			float _m20, _m21, _m22, _m23;
			float _m30, _m31, _m32, _m33;
		};

		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};

		struct
		{
			_float2	_m00_m01, _m02_m03;
			_float2	_m10_m11, _m12_m13;
			_float2	_m20_m21, _m22_m23;
			_float2	_m30_m31, _m32_m33;
		};

		struct
		{
			float	_m00;
			_float2	_m01_m02;
			float	_m03;
			float	_m10;
			_float2	_m11_m12;
			float	_m13;
			float	_m20;
			_float2	_m21_m22;
			float	_m23;
			float	_m30;
			_float2	_m31_m32;
			float	_m33;
		};

		struct
		{
			_float2	_11_12, _13_14;
			_float2	_21_22, _23_24;
			_float2	_31_32, _33_34;
			_float2	_41_42, _43_44;
		};

		struct
		{
			float	_11;
			_float2	_12_13;
			float	_14;
			float	_21;
			_float2	_22_23;
			float	_24;
			float	_31;
			_float2	_32_33;
			float	_34;
			float	_41;
			_float2	_42_43;
			float	_44;
		};

		struct
		{
			_float3	_m00_m01_m02;
			float	_m03;
			_float3	_m10_m11_m12;
			float	_m13;
			_float3	_m20_m21_m22;
			float	_m23;
			_float3	_m30_m31_m32;
			float	_m33;
		};

		struct
		{
			float	_m00;
			_float3	_m01_m02_m03;			
			float	_m10;
			_float3	_m11_m12_m13;
			float	_m20;
			_float3	_m21_m22_m23;
			float	_m30;
			_float3	_m31_m32_m33;
		};

		struct
		{
			_float3	_11_12_13;
			float	_14;
			_float3	_21_22_23;
			float	_24;
			_float3	_31_32_33;
			float	_34;
			_float3	_41_42_43;
			float	_44;
		};

		struct
		{
			float	_11;
			_float3	_12_13_14;			
			float	_21;
			_float3	_22_23_24;
			float	_31;
			_float3	_32_33_34;
			float	_41;
			_float3	_42_43_44;
		};

		struct
		{
			_float4	_m00_m01_m02_m03;
			_float4	_m10_m11_m12_m13;
			_float4	_m20_m21_m22_m23;
			_float4	_m30_m31_m32_m33;
		};

		struct
		{
			_float4	_11_12_13_14;
			_float4	_21_22_23_24;
			_float4	_31_32_33_34;
			_float4	_41_42_43_44;
		};

		float	m[16];
		float	_m[4][4];
	};
} _float4x4;