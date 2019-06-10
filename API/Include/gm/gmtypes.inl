/// <summary>
/// OpenGM library header.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>14-06-2005</created>
/// <copyright>Copyright 2005-2018 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifdef GMTYPES_INL
	#error Nested inclusion of gmtypes.inl
#else
	#define GMTYPES_INL
#endif

////////////////////////////////////////////////////////
// _float2 operators
////////////////////////////////////////////////////////

__forceinline _float2::_float2(const float* f)
{
	x = f[0]; y = f[1];
}

__forceinline _float2::_float2(float X, float Y)
{
	x = X; y = Y;
}

__forceinline _float2::_float2(const _float2& V)
{
	x = V.x; y = V.y;
}

__forceinline _float2::operator float* ()
{
	return (float*) &x;
}

__forceinline _float2::operator const float* () const
{
	return (const float*) &x;
}

__forceinline _float2& _float2::operator+= (const _float2& V)
{
	x += V.x;
    y += V.y;
    return *this;
}

__forceinline _float2& _float2::operator-= (const _float2& V)
{
	x -= V.x;
    y -= V.y;
    return *this;
}

__forceinline _float2& _float2::operator*= (const _float2& V)
{
	x *= V.x;
    y *= V.y;
    return *this;
}

__forceinline _float2& _float2::operator/= (const _float2& V)
{
	x /= V.x;
    y /= V.y;
    return *this;
}

__forceinline _float2& _float2::operator*= (float S)
{
	x *= S;
    y *= S;
    return *this;
}

__forceinline _float2& _float2::operator/= (float S)
{
	float InvS = 1.0f/S;
	x *= InvS;
    y *= InvS;
    return *this;
}

__forceinline _float2 _float2::operator+ () const
{
	return (_float2&) *this;
}

__forceinline _float2 _float2::operator- () const
{
	return _float2(-x, -y);
}

__forceinline _float2 _float2::operator+ (const _float2& V) const
{
	return _float2(x + V.x, y + V.y);
}

__forceinline _float2 _float2::operator- (const _float2& V) const
{
	return _float2(x - V.x, y - V.y);
}

__forceinline _float2 _float2::operator* (const _float2& V) const
{
	return _float2(x * V.x, y * V.y);
}

__forceinline _float2 _float2::operator/ (const _float2& V) const
{	
	return _float2(x / V.x, y / V.y);
}

__forceinline _float2 _float2::operator+ (float S) const
{
	return _float2(x + S, y + S);
}

__forceinline _float2 _float2::operator- (float S) const
{
	return _float2(x - S, y - S);
}

__forceinline _float2 _float2::operator* (float S) const
{
	return _float2(x * S, y * S);
}

__forceinline _float2 _float2::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float2(x * InvS, y * InvS);
}

__forceinline bool	_float2::operator== (const _float2& V) const
{
	return (x == V.x && y == V.y);
}

__forceinline bool	_float2::operator!= (const _float2& V) const
{
	return (x != V.x || y != V.y);
}

__forceinline _float2& _float2::operator=(_float2& V)
{
	x = V.x;
	y = V.y;
	return *this;
}

__forceinline _float2& _float2::operator=(const _float2& V)
{
	x = V.x;
	y = V.y;
	return *this;
}

////////////////////////////////////////////////////////
// _float3 operators
////////////////////////////////////////////////////////

__forceinline _float3::_float3(const float* f)
{
	x = f[0]; y = f[1]; z = f[2];
}

__forceinline _float3::_float3(float X, float Y, float Z)
{
	x = X; y = Y; z = Z;
}

__forceinline _float3::_float3(const _float2& V, float Z)
{
	x = V.x; y = V.y; z = Z;
}

__forceinline _float3::_float3(const _float3& V)
{
	x = V.x; y = V.y; z = V.z;
}

__forceinline _float3::operator float* ()
{
	return (float*) &x;
}

__forceinline _float3::operator const float* () const
{
	return (const float*) &x;
}

__forceinline _float3& _float3::operator+= (const _float3& V)
{
	x += V.x;
    y += V.y;
	z += V.z;
    return *this;
}

__forceinline _float3& _float3::operator-= (const _float3& V)
{
	x -= V.x;
    y -= V.y;
	z -= V.z;
    return *this;
}

__forceinline _float3& _float3::operator*= (const _float3& V)
{
	x *= V.x;
    y *= V.y;
	z *= V.z;
    return *this;
}

__forceinline _float3& _float3::operator/= (const _float3& V)
{
	x /= V.x;
    y /= V.y;
	z /= V.z;
    return *this;
}

__forceinline _float3& _float3::operator*= (float S)
{
	x *= S;
    y *= S;
	z *= S;
    return *this;
}

__forceinline _float3& _float3::operator/= (float S)
{
	float InvS = 1.0f/S;
	x *= InvS;
    y *= InvS;
	z *= InvS;
    return *this;
}

__forceinline _float3 _float3::operator+ () const
{
	return (_float3&) *this;
}

__forceinline _float3 _float3::operator- () const
{
	return _float3(-x, -y, -z);
}

__forceinline _float3 _float3::operator+ (const _float3& V) const
{
	return _float3(x + V.x, y + V.y, z + V.z);
}

__forceinline _float3 _float3::operator- (const _float3& V) const
{
	return _float3(x - V.x, y - V.y, z - V.z);
}

__forceinline _float3 _float3::operator* (const _float3& V) const
{
	return _float3(x * V.x, y * V.y, z * V.z);
}

__forceinline _float3 _float3::operator/ (const _float3& V) const
{	
	return _float3(x / V.x, y / V.y, z / V.z);
}

__forceinline _float3 _float3::operator+ (float S) const
{
	return _float3(x + S, y + S, z + S);
}

__forceinline _float3 _float3::operator- (float S) const
{
	return _float3(x - S, y - S, z - S);
}

__forceinline _float3 _float3::operator* (float S) const
{
	return _float3(x * S, y * S, z * S);
}

__forceinline _float3 _float3::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float3(x * InvS, y * InvS, z * InvS);
}

__forceinline bool	_float3::operator== (const _float3& V) const
{
	return (x == V.x && y == V.y && z == V.z);
}

__forceinline bool	_float3::operator!= (const _float3& V) const
{
	return (x != V.x || y != V.y || z != V.z);
}

__forceinline _float3& _float3::operator=(_float3& V)
{
	x = V.x;
	y = V.y;
	z = V.z;
	return *this;
}

__forceinline _float3& _float3::operator=(const _float3& V)
{
	x = V.x;
	y = V.y;
	z = V.z;
	return *this;
}


////////////////////////////////////////////////////////
// _float4 operators
////////////////////////////////////////////////////////

__forceinline _float4::_float4(const float* f)
{
	x = f[0]; y = f[1]; z = f[2]; w = f[3];
}

__forceinline _float4::_float4(float X, float Y, float Z, float W)
{
	x = X; y = Y; z = Z; w = W;
}

__forceinline _float4::_float4(const _float2& V, float Z, float W)
{
	x = V.x; y = V.y; z = Z; w = W;
}

__forceinline _float4::_float4(const _float2& V1, const _float2& V2)
{
	x = V1.x; y = V1.y; z = V2.x; w = V2.y;
}

__forceinline _float4::_float4(const _float3& V, float W)
{
	x = V.x; y = V.y; z = V.z; w = W;
}

__forceinline _float4::_float4(const _float4& V)
{
#ifdef GM_STUPIDCOMPILER
	x = V.x; y = V.y; z = V.z; w = V.w;
#else
	for (int i=0; i<4; i++) v[i] = V.v[i];
#endif
}

__forceinline _float4::operator float* ()
{
	return (float*) &x;
}

__forceinline _float4::operator const float* () const
{
	return (const float*) &x;
}

__forceinline _float4& _float4::operator+= (const _float4& V)
{
#ifdef GM_STUPIDCOMPILER
	x += V.x;
    y += V.y;
	z += V.z;
	w += V.w;
#else
	for (int i=0; i<4; i++) v[i] += V.v[i];
#endif
    return *this;
}

__forceinline _float4& _float4::operator-= (const _float4& V)
{
#ifdef GM_STUPIDCOMPILER
	x -= V.x;
    y -= V.y;
	z -= V.z;
	w -= V.w;
#else
	for (int i=0; i<4; i++) v[i] -= V.v[i];
#endif
    return *this;
}

__forceinline _float4& _float4::operator*= (const _float4& V)
{
#ifdef GM_STUPIDCOMPILER
	x *= V.x;
    y *= V.y;
	z *= V.z;
	w *= V.w;
#else
	for (int i=0; i<4; i++) v[i] *= V.v[i];
#endif
    return *this;
}

__forceinline _float4& _float4::operator/= (const _float4& V)
{
#ifdef GM_STUPIDCOMPILER
	x /= V.x;
    y /= V.y;
	z /= V.z;
	w /= V.w;
#else
	for (int i=0; i<4; i++) v[i] /= V.v[i];
#endif
    return *this;
}

__forceinline _float4& _float4::operator*= (float S)
{
#ifdef GM_STUPIDCOMPILER
	x *= S;
    y *= S;
	z *= S;
	w *= S;
#else
	for (int i=0; i<4; i++) v[i] *= S;
#endif
    return *this;
}

__forceinline _float4& _float4::operator/= (float S)
{
	float InvS = 1.0f/S;
#ifdef GM_STUPIDCOMPILER
	x *= InvS;
    y *= InvS;
	z *= InvS;
	w *= InvS;
#else
	for (int i=0; i<4; i++) v[i] *= InvS;
#endif
    return *this;
}

__forceinline _float4 _float4::operator+ () const
{
	return (_float4&) *this;
}

__forceinline _float4 _float4::operator- () const
{
	return _float4(-x, -y, -z, -w);
}

__forceinline _float4 _float4::operator+ (const _float4& V) const
{
	return _float4(x + V.x, y + V.y, z + V.z, w + V.w);
}

__forceinline _float4 _float4::operator- (const _float4& V) const
{
	return _float4(x - V.x, y - V.y, z - V.z, w - V.w);
}

__forceinline _float4 _float4::operator* (const _float4& V) const
{
	return _float4(x * V.x, y * V.y, z * V.z, w * V.w);
}

__forceinline _float4 _float4::operator/ (const _float4& V) const
{	
	return _float4(x / V.x, y / V.y, z / V.z, w / V.w);
}

__forceinline _float4 _float4::operator+ (float S) const
{
	return _float4(x + S, y + S, z + S, w + S);
}

__forceinline _float4 _float4::operator- (float S) const
{
	return _float4(x - S, y - S, z - S, w - S);
}

__forceinline _float4 _float4::operator* (float S) const
{
	return _float4(x * S, y * S, z * S, w * S);
}

__forceinline _float4 _float4::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float4(x * InvS, y * InvS, z * InvS, w * InvS);
}

__forceinline bool	_float4::operator== (const _float4& V) const
{
	return (x == V.x && y == V.y && z == V.z && w == V.w);
}

__forceinline bool	_float4::operator!= (const _float4& V) const
{
	return (x != V.x || y != V.y || z != V.z || w != V.w);
}

__forceinline _float4& _float4::operator=(_float4& V)
{
	x = V.x;
	y = V.y;
	z = V.z;
	w = V.w;
	return *this;
}

__forceinline _float4& _float4::operator=(const _float4& V)
{
	x = V.x;
	y = V.y;
	z = V.z;
	w = V.w;
	return *this;
}


////////////////////////////////////////////////////////
// _float2x2 operators
////////////////////////////////////////////////////////

__forceinline _float2x2::_float2x2(const float* f)
{
	_m00 = f[0]; _m01 = f[1];
	_m10 = f[2]; _m11 = f[3];
}

__forceinline _float2x2::_float2x2(float m00, float m01, float m10, float m11)
{
	_m00 = m00; _m01 = m01;
	_m10 = m10; _m11 = m11;
}

__forceinline _float2x2::_float2x2(_float2 m00_01, _float2 m10_11)
{
	_m00_m01 = m00_01; _m10_m11 = m10_11;
}

__forceinline _float2x2::_float2x2(_float2x2 &M)
{
	_m00 = M._m00; _m01 = M._m01;
	_m10 = M._m10; _m11 = M._m11;
}

__forceinline _float2x2::operator float* ()
{
	return (float*) &m;
}

__forceinline _float2x2::operator const float* () const
{
	return (const float*) &m;
}

__forceinline _float2x2 _float2x2::operator+ (float S) const
{
	return _float2x2(m[0]+S, m[1]+S, m[2]+S, m[3]+S);
}

__forceinline _float2x2 _float2x2::operator- (float S) const
{
	return _float2x2(m[0]-S, m[1]-S, m[2]-S, m[3]-S);
}

__forceinline _float2x2 _float2x2::operator* (float S) const
{
	return _float2x2(m[0]*S, m[1]*S, m[2]*S, m[3]*S);
}

__forceinline _float2x2 _float2x2::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float2x2(m[0]*InvS, m[1]*InvS, m[2]*InvS, m[3]*InvS);
}

__forceinline _float2x2 _float2x2::operator+ () const
{
	return (_float2x2&) *this;
}

__forceinline _float2x2 _float2x2::operator- () const
{
	return _float2x2(-m[0], -m[1], -m[2], -m[3]);
}

__forceinline _float2x2& _float2x2::operator=(_float2x2& M)
{
	m[0] = M.m[0]; m[1] = M.m[1];
	m[2] = M.m[2]; m[3] = M.m[3];
	return *this;
}

__forceinline _float2x2& _float2x2::operator=(const _float2x2& M)
{
	m[0] = M.m[0]; m[1] = M.m[1];
	m[2] = M.m[2]; m[3] = M.m[3];
	return *this;
}

////////////////////////////////////////////////////////
// _float2x3 operators
////////////////////////////////////////////////////////

__forceinline _float2x3::_float2x3(const float* f)
{
	_m00 = f[0]; _m01 = f[1]; _m02 = f[2];
	_m10 = f[3]; _m11 = f[4]; _m12 = f[5];
}

__forceinline _float2x3::_float2x3(float m00, float m01, float m02,
			 float m10, float m11, float m12)
{
	_m00 = m00; _m01 = m01; _m02 = m02;
	_m10 = m10; _m11 = m11; _m12 = m12;
}

__forceinline _float2x3::_float2x3(_float3 m00_01_02, _float3 m10_11_12)
{
	_m00_m01_m02 = m00_01_02; _m10_m11_m12 = m10_11_12;
}

__forceinline _float2x3::_float2x3(_float2x3 &M)
{
	_m00 = M._m00; _m01 = M._m01; _m02 = M._m02;
	_m10 = M._m10; _m11 = M._m11; _m12 = M._m12;
}

__forceinline _float2x3::operator float* ()
{
	return (float*) &m;
}

__forceinline _float2x3::operator const float* () const
{
	return (const float*) &m;
}

__forceinline _float2x3 _float2x3::operator+ (float S) const
{
	return _float2x3(m[0]+S, m[1]+S, m[2]+S, m[3]+S, m[4]+S, m[5]+S);
}

__forceinline _float2x3 _float2x3::operator- (float S) const
{
	return _float2x3(m[0]-S, m[1]-S, m[2]-S, m[3]-S, m[4]-S, m[5]-S);
}

__forceinline _float2x3 _float2x3::operator* (float S) const
{
	return _float2x3(m[0]*S, m[1]*S, m[2]*S, m[3]*S, m[4]*S, m[5]*S);
}

__forceinline _float2x3 _float2x3::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float2x3(m[0]*InvS, m[1]*InvS, m[2]*InvS, m[3]*InvS, m[4]*InvS, m[5]*InvS);
}

__forceinline _float2x3 _float2x3::operator+ () const
{
	return (_float2x3&) *this;
}

__forceinline _float2x3 _float2x3::operator- () const
{
	return _float2x3(-m[0], -m[1], -m[2], -m[3], -m[4], -m[5]);
}

__forceinline _float2x3& _float2x3::operator=(_float2x3& M)
{
	m[0] = M.m[0]; m[1] = M.m[1];  m[2] = M.m[2];
	m[3] = M.m[3]; m[4] = M.m[4];  m[5] = M.m[5];
	return *this;
}

__forceinline _float2x3& _float2x3::operator=(const _float2x3& M)
{
	m[0] = M.m[0]; m[1] = M.m[1];  m[2] = M.m[2];
	m[3] = M.m[3]; m[4] = M.m[4];  m[5] = M.m[5];
	return *this;
}

////////////////////////////////////////////////////////
// _float2x4 operators
////////////////////////////////////////////////////////

__forceinline _float2x4::_float2x4(const float* f)
{
	_m00 = f[0]; _m01 = f[1]; _m02 = f[2]; _m03 = f[3];
	_m10 = f[4]; _m11 = f[5]; _m12 = f[6]; _m13 = f[7];
}

__forceinline _float2x4::_float2x4(float m00, float m01, float m02, float m03,
			 float m10, float m11, float m12, float m13)
{
	_m00 = m00; _m01 = m01; _m02 = m02; _m03 = m03;
	_m10 = m10; _m11 = m11; _m12 = m12; _m13 = m13;
}

__forceinline _float2x4::_float2x4(_float4 m00_01_02_03, _float4 m10_11_12_13)
{
	_m00_m01_m02_m03 = m00_01_02_03; _m10_m11_m12_m13 = m10_11_12_13;
}

__forceinline _float2x4::_float2x4(_float2x4 &M)
{
	_m00 = M._m00; _m01 = M._m01; _m02 = M._m02; _m03 = M._m03;
	_m10 = M._m10; _m11 = M._m11; _m12 = M._m12; _m13 = M._m13;
}

__forceinline _float2x4::operator float* ()
{
	return (float*) &m;
}

__forceinline _float2x4::operator const float* () const
{
	return (const float*) &m;
}

__forceinline _float2x4 _float2x4::operator+ (float S) const
{
	return _float2x4(m[0]+S, m[1]+S, m[2]+S, m[3]+S, m[4]+S, m[5]+S, m[6]+S, m[7]+S);
}

__forceinline _float2x4 _float2x4::operator- (float S) const
{
	return _float2x4(m[0]-S, m[1]-S, m[2]-S, m[3]-S, m[4]-S, m[5]-S, m[6]-S, m[7]-S);
}

__forceinline _float2x4 _float2x4::operator* (float S) const
{
	return _float2x4(m[0]*S, m[1]*S, m[2]*S, m[3]*S, m[4]*S, m[5]*S, m[6]*S, m[7]*S);
}

__forceinline _float2x4 _float2x4::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float2x4(m[0]*InvS, m[1]*InvS, m[2]*InvS, m[3]*InvS, m[4]*InvS, m[5]*InvS, m[6]*InvS, m[7]*InvS);
}

__forceinline _float2x4 _float2x4::operator+ () const
{
	return (_float2x4&) *this;
}

__forceinline _float2x4 _float2x4::operator- () const
{
	return _float2x4(-m[0], -m[1], -m[2], -m[3], -m[4], -m[5], -m[6], -m[7]);
}

__forceinline _float2x4& _float2x4::operator=(_float2x4& M)
{
	m[0] = M.m[0]; m[1] = M.m[1]; m[2] = M.m[2]; m[3] = M.m[3];
	m[4] = M.m[4]; m[5] = M.m[5]; m[6] = M.m[6]; m[7] = M.m[7];
	return *this;
}

__forceinline _float2x4& _float2x4::operator=(const _float2x4& M)
{
	m[0] = M.m[0]; m[1] = M.m[1]; m[2] = M.m[2]; m[3] = M.m[3];
	m[4] = M.m[4]; m[5] = M.m[5]; m[6] = M.m[6]; m[7] = M.m[7];
	return *this;
}

////////////////////////////////////////////////////////
// _float3x2 operators
////////////////////////////////////////////////////////

__forceinline _float3x2::_float3x2(const float* f)
{
	_m00 = f[0]; _m01 = f[1];
	_m10 = f[2]; _m11 = f[3];
	_m20 = f[4]; _m21 = f[5];
}

__forceinline _float3x2::_float3x2(float m00, float m01,
								float m10, float m11,
								float m20, float m21)
{
	_m00 = m00; _m01 = m01;
	_m10 = m10; _m11 = m11;
	_m20 = m20; _m21 = m21;
}

__forceinline _float3x2::_float3x2(_float2 m00_01, _float2 m10_11, _float2 m20_21)
{
	_m00_m01 = m00_01; _m10_m11 = m10_11; _m20_m21 = m20_21;
}

__forceinline _float3x2::_float3x2(_float3x2 &M)
{
	_m00 = M._m00; _m01 = M._m01;
	_m10 = M._m10; _m11 = M._m11;
	_m20 = M._m20; _m21 = M._m21;
}

__forceinline _float3x2::operator float* ()
{
	return (float*) &m;
}

__forceinline _float3x2::operator const float* () const
{
	return (const float*) &m;
}

__forceinline _float3x2 _float3x2::operator+ (float S) const
{
	return _float3x2(m[0]+S, m[1]+S, m[2]+S, m[3]+S, m[4]+S, m[5]+S);
}

__forceinline _float3x2 _float3x2::operator- (float S) const
{
	return _float3x2(m[0]-S, m[1]-S, m[2]-S, m[3]-S, m[4]-S, m[5]-S);
}

__forceinline _float3x2 _float3x2::operator* (float S) const
{
	return _float3x2(m[0]*S, m[1]*S, m[2]*S, m[3]*S, m[4]*S, m[5]*S);
}

__forceinline _float3x2 _float3x2::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float3x2(m[0]*InvS, m[1]*InvS, m[2]*InvS, m[3]*InvS, m[4]*InvS, m[5]*InvS);
}

__forceinline _float3x2 _float3x2::operator+ () const
{
	return (_float3x2&) *this;
}

__forceinline _float3x2 _float3x2::operator- () const
{
	return _float3x2(-m[0], -m[1], -m[2], -m[3], -m[4], -m[5]);
}

__forceinline _float3x2& _float3x2::operator=(_float3x2& M)
{
	m[0] = M.m[0]; m[1] = M.m[1];
	m[2] = M.m[2]; m[3] = M.m[3];
	m[4] = M.m[4]; m[5] = M.m[5];
	return *this;
}

__forceinline _float3x2& _float3x2::operator=(const _float3x2& M)
{
	m[0] = M.m[0]; m[1] = M.m[1];
	m[2] = M.m[2]; m[3] = M.m[3];
	m[4] = M.m[4]; m[5] = M.m[5];
	return *this;
}

////////////////////////////////////////////////////////
// _float3x3 operators
////////////////////////////////////////////////////////

__forceinline _float3x3::_float3x3(const float* f)
{
	_m00 = f[0]; _m01 = f[1]; _m02 = f[2];
	_m10 = f[3]; _m11 = f[4]; _m12 = f[5];
	_m20 = f[6]; _m21 = f[7]; _m22 = f[8];
}

__forceinline _float3x3::_float3x3(float m00, float m01, float m02,
								float m10, float m11, float m12,
								float m20, float m21, float m22)
{
	_m00 = m00; _m01 = m01; _m02 = m02;
	_m10 = m10; _m11 = m11; _m12 = m12;
	_m20 = m20; _m21 = m21; _m22 = m22;
}

__forceinline _float3x3::_float3x3(_float3 m00_01_02, _float3 m10_11_12, _float3 m20_21_22)
{
	_m00_m01_m02 = m00_01_02; _m10_m11_m12 = m10_11_12; _m20_m21_m22 = m20_21_22;
}

__forceinline _float3x3::_float3x3(_float3x3 &M)
{
	_m00 = M._m00; _m01 = M._m01; _m02 = M._m02;
	_m10 = M._m10; _m11 = M._m11; _m12 = M._m12;
	_m20 = M._m20; _m21 = M._m21; _m22 = M._m22;
}

__forceinline _float3x3::operator float* ()
{
	return (float*) &m;
}

__forceinline _float3x3::operator const float* () const
{
	return (const float*) &m;
}

__forceinline _float3x3 _float3x3::operator+ (float S) const
{
	return _float3x3(m[0]+S, m[1]+S, m[2]+S,
					m[3]+S, m[4]+S, m[5]+S,
					m[6]+S, m[7]+S, m[8]+S);
}

__forceinline _float3x3 _float3x3::operator- (float S) const
{
	return _float3x3(m[0]-S, m[1]-S, m[2]-S,
					m[3]-S, m[4]-S, m[5]-S,
					m[6]-S, m[7]-S, m[8]-S);
}

__forceinline _float3x3 _float3x3::operator* (float S) const
{
	return _float3x3(m[0]*S, m[1]*S, m[2]*S,
					m[3]*S, m[4]*S, m[5]*S,
					m[6]*S, m[7]*S, m[8]*S);
}

__forceinline _float3x3 _float3x3::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float3x3(m[0]*InvS, m[1]*InvS, m[2]*InvS,
					m[3]*InvS, m[4]*InvS, m[5]*InvS,
					m[6]*InvS, m[7]*InvS, m[8]*InvS);
}

__forceinline _float3x3 _float3x3::operator+ () const
{
	return (_float3x3&) *this;
}

__forceinline _float3x3 _float3x3::operator- () const
{
	return _float3x3(-m[0], -m[1], -m[2], -m[3], -m[4], -m[5], -m[6], -m[7], -m[8]);
}

__forceinline _float3x3& _float3x3::operator=(_float3x3& M)
{
	m[0] = M.m[0]; m[1] = M.m[1]; m[2] = M.m[2];
	m[3] = M.m[3]; m[4] = M.m[4]; m[5] = M.m[5];
	m[6] = M.m[6]; m[7] = M.m[7]; m[8] = M.m[8];
	return *this;
}

__forceinline _float3x3& _float3x3::operator=(const _float3x3& M)
{
	m[0] = M.m[0]; m[1] = M.m[1]; m[2] = M.m[2];
	m[3] = M.m[3]; m[4] = M.m[4]; m[5] = M.m[5];
	m[6] = M.m[6]; m[7] = M.m[7]; m[8] = M.m[8];
	return *this;
}

////////////////////////////////////////////////////////
// _float3x4 operators
////////////////////////////////////////////////////////

__forceinline _float3x4::_float3x4(const float* f)
{
	_m00 = f[0]; _m01 = f[1]; _m02 = f[2]; _m03 = f[3];
	_m10 = f[4]; _m11 = f[5]; _m12 = f[6]; _m13 = f[7];
	_m20 = f[8]; _m21 = f[9]; _m22 = f[10]; _m23 = f[11];
}

__forceinline _float3x4::_float3x4(float m00, float m01, float m02, float m03,
								float m10, float m11, float m12, float m13,
								float m20, float m21, float m22, float m23)
{
	_m00 = m00; _m01 = m01; _m02 = m02; _m03 = m03;
	_m10 = m10; _m11 = m11; _m12 = m12; _m13 = m13;
	_m20 = m20; _m21 = m21; _m22 = m22; _m23 = m23;
}

__forceinline _float3x4::_float3x4(_float4 m00_01_02_03, _float4 m10_11_12_13, _float4 m20_21_22_23)
{
	_m00_m01_m02_m03 = m00_01_02_03;
	_m10_m11_m12_m13 = m10_11_12_13;
	_m20_m21_m22_m23 = m20_21_22_23;
}

__forceinline _float3x4::_float3x4(_float3x4 &M)
{
	_m00 = M._m00; _m01 = M._m01; _m02 = M._m02; _m03 = M._m03;
	_m10 = M._m10; _m11 = M._m11; _m12 = M._m12; _m13 = M._m13;
	_m20 = M._m20; _m21 = M._m21; _m22 = M._m22; _m23 = M._m23;
}

__forceinline _float3x4::operator float* ()
{
	return (float*) &m;
}

__forceinline _float3x4::operator const float* () const
{
	return (const float*) &m;
}

__forceinline _float3x4 _float3x4::operator+ (float S) const
{
	return _float3x4(m[0]+S, m[1]+S, m[2]+S, m[3]+S,
					m[4]+S, m[5]+S,	m[6]+S, m[7]+S,
					m[8]+S, m[9]+S, m[10]+S, m[11]+S);
}

__forceinline _float3x4 _float3x4::operator- (float S) const
{
	return _float3x4(m[0]-S, m[1]-S, m[2]-S,	m[3]-S,
					m[4]-S, m[5]-S,	m[6]-S, m[7]-S,
					m[8]-S,	m[9]-S, m[10]-S, m[11]-S);
}

__forceinline _float3x4 _float3x4::operator* (float S) const
{
	return _float3x4(m[0]*S, m[1]*S, m[2]*S,	m[3]*S,
					m[4]*S, m[5]*S,	m[6]*S, m[7]*S,
					m[8]*S,	m[9]*S, m[10]*S, m[11]*S);
}

__forceinline _float3x4 _float3x4::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float3x4(m[0]*InvS, m[1]*InvS, m[2]*InvS, m[3]*InvS,
					m[4]*InvS, m[5]*InvS, m[6]*InvS, m[7]*InvS,
					m[8]*InvS, m[9]*InvS, m[10]*InvS, m[11]*InvS);
}

__forceinline _float3x4 _float3x4::operator+ () const
{
	return (_float3x4&) *this;
}

__forceinline _float3x4 _float3x4::operator- () const
{
	return _float3x4(-m[0], -m[1], -m[2], -m[3],
					-m[4], -m[5], -m[6], -m[7],
					-m[8], -m[9], -m[10], -m[11]);
}

__forceinline _float3x4& _float3x4::operator=(_float3x4& M)
{
	m[0] = M.m[0]; m[1] = M.m[1]; m[2] = M.m[2]; m[3] = M.m[3];
	m[4] = M.m[4]; m[5] = M.m[5]; m[6] = M.m[6]; m[7] = M.m[7];
	m[8] = M.m[8]; m[9] = M.m[9]; m[10] = M.m[10]; m[11] = M.m[11];
	return *this;
}

__forceinline _float3x4& _float3x4::operator=(const _float3x4& M)
{
	m[0] = M.m[0]; m[1] = M.m[1]; m[2] = M.m[2]; m[3] = M.m[3];
	m[4] = M.m[4]; m[5] = M.m[5]; m[6] = M.m[6]; m[7] = M.m[7];
	m[8] = M.m[8]; m[9] = M.m[9]; m[10] = M.m[10]; m[11] = M.m[11];
	return *this;
}

////////////////////////////////////////////////////////
// _float4x2 operators
////////////////////////////////////////////////////////

__forceinline _float4x2::_float4x2(const float* f)
{
	_m00 = f[0]; _m01 = f[1];
	_m10 = f[2]; _m11 = f[3];
	_m20 = f[4]; _m21 = f[5];
	_m30 = f[6]; _m31 = f[7];
}

__forceinline _float4x2::_float4x2(float m00, float m01,
								float m10, float m11,
								float m20, float m21,
								float m30, float m31)
{
	_m00 = m00; _m01 = m01;
	_m10 = m10; _m11 = m11;
	_m20 = m20; _m21 = m21;
	_m30 = m30; _m31 = m31;
}

__forceinline _float4x2::_float4x2(_float2 m00_01, _float2 m10_11, _float2 m20_21, _float2 m30_31)
{
	_m00_m01 = m00_01; _m10_m11 = m10_11; _m20_m21 = m20_21; _m30_m31 = m30_31;
}

__forceinline _float4x2::_float4x2(_float4x2 &M)
{
	_m00 = M._m00; _m01 = M._m01;
	_m10 = M._m10; _m11 = M._m11;
	_m20 = M._m20; _m21 = M._m21;
	_m30 = M._m30; _m31 = M._m31;
}

__forceinline _float4x2::operator float* ()
{
	return (float*) &m;
}

__forceinline _float4x2::operator const float* () const
{
	return (const float*) &m;
}

__forceinline _float4x2 _float4x2::operator+ (float S) const
{
	return _float4x2(m[0]+S, m[1]+S, m[2]+S, m[3]+S, m[4]+S, m[5]+S, m[6]+S, m[7]+S);
}

__forceinline _float4x2 _float4x2::operator- (float S) const
{
	return _float4x2(m[0]-S, m[1]-S, m[2]-S, m[3]-S, m[4]-S, m[5]-S, m[6]-S, m[7]-S);
}

__forceinline _float4x2 _float4x2::operator* (float S) const
{
	return _float4x2(m[0]*S, m[1]*S, m[2]*S, m[3]*S, m[4]*S, m[5]*S, m[6]*S, m[7]*S);
}

__forceinline _float4x2 _float4x2::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float4x2(m[0]*InvS, m[1]*InvS, m[2]*InvS, m[3]*InvS, m[4]*InvS, m[5]*InvS, m[6]*InvS, m[7]*InvS);
}

__forceinline _float4x2 _float4x2::operator+ () const
{
	return (_float4x2&) *this;
}

__forceinline _float4x2 _float4x2::operator- () const
{
	return _float4x2(-m[0], -m[1], -m[2], -m[3],
					-m[4], -m[5], -m[6], -m[7]);
}

__forceinline _float4x2& _float4x2::operator=(_float4x2& M)
{
	m[0] = M.m[0]; m[1] = M.m[1];
	m[2] = M.m[2]; m[3] = M.m[3];
	m[4] = M.m[4]; m[5] = M.m[5];
	m[6] = M.m[6]; m[7] = M.m[7];
	return *this;
}

__forceinline _float4x2& _float4x2::operator=(const _float4x2& M)
{
	m[0] = M.m[0]; m[1] = M.m[1];
	m[2] = M.m[2]; m[3] = M.m[3];
	m[4] = M.m[4]; m[5] = M.m[5];
	m[6] = M.m[6]; m[7] = M.m[7];
	return *this;
}

////////////////////////////////////////////////////////
// _float4x3 operators
////////////////////////////////////////////////////////

__forceinline _float4x3::_float4x3(const float* f)
{
	_m00 = f[0]; _m01 = f[1]; _m02 = f[2];
	_m10 = f[3]; _m11 = f[4]; _m12 = f[5];
	_m20 = f[6]; _m21 = f[7]; _m22 = f[8];
	_m30 = f[9]; _m31 = f[10]; _m32 = f[11];
}

__forceinline _float4x3::_float4x3(float m00, float m01, float m02,
								float m10, float m11, float m12,
								float m20, float m21, float m22,
								float m30, float m31, float m32)
{
	_m00 = m00; _m01 = m01; _m02 = m02;
	_m10 = m10; _m11 = m11; _m12 = m12;
	_m20 = m20; _m21 = m21; _m22 = m22;
	_m30 = m30; _m31 = m31; _m32 = m32;
}

__forceinline _float4x3::_float4x3(_float3 m00_01_02, _float3 m10_11_12, _float3 m20_21_22, _float3 m30_31_32)
{
	_m00_m01_m02 = m00_01_02; _m10_m11_m12 = m10_11_12; _m20_m21_m22 = m20_21_22; _m30_m31_m32 = m30_31_32;
}

__forceinline _float4x3::_float4x3(_float4x3 &M)
{
	_m00 = M._m00; _m01 = M._m01; _m02 = M._m02;
	_m10 = M._m10; _m11 = M._m11; _m12 = M._m12;
	_m20 = M._m20; _m21 = M._m21; _m22 = M._m22;
	_m30 = M._m30; _m31 = M._m31; _m32 = M._m32;
}

__forceinline _float4x3::operator float* ()
{
	return (float*) &m;
}

__forceinline _float4x3::operator const float* () const
{
	return (const float*) &m;
}

__forceinline _float4x3 _float4x3::operator+ (float S) const
{
	return _float4x3(m[0]+S, m[1]+S, m[2]+S,
					m[3]+S, m[4]+S, m[5]+S,
					m[6]+S, m[7]+S, m[8]+S,
					m[9]+S, m[10]+S, m[11]+S);
}

__forceinline _float4x3 _float4x3::operator- (float S) const
{
	return _float4x3(m[0]-S, m[1]-S, m[2]-S,
					m[3]-S, m[4]-S, m[5]-S,
					m[6]-S, m[7]-S, m[8]-S,
					m[9]-S, m[10]-S, m[11]-S);
}

__forceinline _float4x3 _float4x3::operator* (float S) const
{
	return _float4x3(m[0]*S, m[1]*S, m[2]*S,
					m[3]*S, m[4]*S, m[5]*S,
					m[6]*S, m[7]*S, m[8]*S,
					m[9]*S, m[10]*S, m[11]*S);
}

__forceinline _float4x3 _float4x3::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float4x3(m[0]*InvS, m[1]*InvS, m[2]*InvS,
					m[3]*InvS, m[4]*InvS, m[5]*InvS,
					m[6]*InvS, m[7]*InvS, m[8]*InvS,
					m[9]*InvS, m[10]*InvS, m[11]*InvS);
}

__forceinline _float4x3 _float4x3::operator+ () const
{
	return (_float4x3&) *this;
}

__forceinline _float4x3 _float4x3::operator- () const
{
	return _float4x3(-m[0], -m[1], -m[2],
					-m[3], -m[4], -m[5],
					-m[6], -m[7], -m[8],
					-m[9], -m[10], -m[11]);
}

__forceinline _float4x3& _float4x3::operator=(_float4x3& M)
{
	m[0] = M.m[0]; m[1] = M.m[1]; m[2] = M.m[2];
	m[3] = M.m[3]; m[4] = M.m[4]; m[5] = M.m[5];
	m[6] = M.m[6]; m[7] = M.m[7]; m[8] = M.m[8];
	m[9] = M.m[9]; m[10] = M.m[10]; m[11] = M.m[11];
	return *this;
}

__forceinline _float4x3& _float4x3::operator=(const _float4x3& M)
{
	m[0] = M.m[0]; m[1] = M.m[1]; m[2] = M.m[2];
	m[3] = M.m[3]; m[4] = M.m[4]; m[5] = M.m[5];
	m[6] = M.m[6]; m[7] = M.m[7]; m[8] = M.m[8];
	m[9] = M.m[9]; m[10] = M.m[10]; m[11] = M.m[11];
	return *this;
}

////////////////////////////////////////////////////////
// _float4x4 operators
////////////////////////////////////////////////////////

__forceinline _float4x4::_float4x4(const float* f)
{
	_m00 = f[0]; _m01 = f[1]; _m02 = f[2]; _m03 = f[3];
	_m10 = f[4]; _m11 = f[5]; _m12 = f[6]; _m13 = f[7];
	_m20 = f[8]; _m21 = f[9]; _m22 = f[10]; _m23 = f[11];
	_m30 = f[12]; _m31 = f[13]; _m32 = f[14]; _m33 = f[15];
}

__forceinline _float4x4::_float4x4(float m00, float m01, float m02, float m03,
								float m10, float m11, float m12, float m13,
								float m20, float m21, float m22, float m23,
								float m30, float m31, float m32, float m33)
{
	_m00 = m00; _m01 = m01; _m02 = m02; _m03 = m03;
	_m10 = m10; _m11 = m11; _m12 = m12; _m13 = m13;
	_m20 = m20; _m21 = m21; _m22 = m22; _m23 = m23;
	_m30 = m30; _m31 = m31; _m32 = m32; _m33 = m33;
}

__forceinline _float4x4::_float4x4(_float4 m00_01_02_03, _float4 m10_11_12_13, _float4 m20_21_22_23, _float4 m30_31_32_33)
{
	_m00_m01_m02_m03 = m00_01_02_03;
	_m10_m11_m12_m13 = m10_11_12_13;
	_m20_m21_m22_m23 = m20_21_22_23;
	_m30_m31_m32_m33 = m30_31_32_33;
}

__forceinline _float4x4::_float4x4(_float4x4 &M)
{
	_m00 = M._m00; _m01 = M._m01; _m02 = M._m02; _m03 = M._m03;
	_m10 = M._m10; _m11 = M._m11; _m12 = M._m12; _m13 = M._m13;
	_m20 = M._m20; _m21 = M._m21; _m22 = M._m22; _m23 = M._m23;
	_m30 = M._m30; _m31 = M._m31; _m32 = M._m32; _m33 = M._m33;
}

__forceinline _float4x4::operator float* ()
{
	return (float*) &m;
}

__forceinline _float4x4::operator const float* () const
{
	return (const float*) &m;
}

__forceinline _float4x4 _float4x4::operator+ (float S) const
{
	return _float4x4(m[0]+S, m[1]+S, m[2]+S, m[3]+S,
					m[4]+S, m[5]+S, m[6]+S, m[7]+S,
					m[8]+S, m[9]+S, m[10]+S, m[11]+S,
					m[12]+S, m[13]+S, m[14]+S, m[15]+S);
}

__forceinline _float4x4 _float4x4::operator- (float S) const
{
	return _float4x4(m[0]-S, m[1]-S, m[2]-S, m[3]-S,
					m[4]-S, m[5]-S, m[6]-S, m[7]-S,
					m[8]-S, m[9]-S, m[10]-S, m[11]-S,
					m[12]-S, m[13]-S, m[14]-S, m[15]-S);
}

__forceinline _float4x4 _float4x4::operator* (float S) const
{
	return _float4x4(m[0]*S, m[1]*S, m[2]*S, m[3]*S,
					m[4]*S, m[5]*S, m[6]*S, m[7]*S,
					m[8]*S, m[9]*S, m[10]*S, m[11]*S,
					m[12]*S, m[13]*S, m[14]*S, m[15]*S);
}

__forceinline _float4x4 _float4x4::operator/ (float S) const
{
	float InvS = 1.0f / S;
	return _float4x4(m[0]*InvS, m[1]*InvS, m[2]*InvS, m[3]*InvS,
					m[4]*InvS, m[5]*InvS, m[6]*InvS, m[7]*InvS,
					m[8]*InvS, m[9]*InvS, m[10]*InvS, m[11]*InvS,
					m[12]*InvS, m[13]*InvS, m[14]*InvS, m[15]*InvS);
}

__forceinline _float4x4 _float4x4::operator+ () const
{
	return (_float4x4&) *this;
}

__forceinline _float4x4 _float4x4::operator- () const
{
	return _float4x4(-m[0], -m[1], -m[2], -m[3],
					-m[4], -m[5], -m[6], -m[7],
					-m[8], -m[9], -m[10], -m[11],
					-m[12], -m[13], -m[14], -m[15]);
}

__forceinline _float4x4& _float4x4::operator=(_float4x4& M)
{
	m[0] = M.m[0]; m[1] = M.m[1]; m[2] = M.m[2]; m[3] = M.m[3];
	m[4] = M.m[4]; m[5] = M.m[5]; m[6] = M.m[6]; m[7] = M.m[7];
	m[8] = M.m[8]; m[9] = M.m[9]; m[10] = M.m[10]; m[11] = M.m[11];
	m[12] = M.m[12]; m[13] = M.m[13]; m[14] = M.m[14]; m[15] = M.m[15];
	return *this;
}

__forceinline _float4x4& _float4x4::operator=(const _float4x4& M)
{
	m[0] = M.m[0]; m[1] = M.m[1]; m[2] = M.m[2]; m[3] = M.m[3];
	m[4] = M.m[4]; m[5] = M.m[5]; m[6] = M.m[6]; m[7] = M.m[7];
	m[8] = M.m[8]; m[9] = M.m[9]; m[10] = M.m[10]; m[11] = M.m[11];
	m[12] = M.m[12]; m[13] = M.m[13]; m[14] = M.m[14]; m[15] = M.m[15];
	return *this;
}