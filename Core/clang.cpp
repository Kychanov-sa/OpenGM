#include "stdafx.h"
#include "registers.h"

namespace GlacialBytes
{
	namespace OpenGm
	{
		float2 FASTCALL abs2_clang(const float2& v)
		{
			return float2(fabsf(v.x), fabsf(v.y));
		}

		float3 FASTCALL abs3_clang(const float3& v)
		{
			return float3(fabsf(v.x), fabsf(v.y), fabsf(v.z));
		}

		float4 FASTCALL abs4_clang(const float4& v)
		{
			return float4(fabsf(v.x), fabsf(v.y), fabsf(v.z), fabsf(v.w));
		}

		bool FASTCALL all2_clang(const float2& x)
		{
			return (x.x != 0.0f) && (x.y != 0.0f);
		}

		bool FASTCALL all3_clang(const float3& x)
		{
			return (x.x != 0.0f) && (x.y != 0.0f) && (x.z != 0.0f);
		}

		bool FASTCALL all4_clang(const float4& x)
		{
			return (x.x != 0.0f) && (x.y != 0.0f) && (x.z != 0.0f) && (x.w != 0.0f);
		}

		bool FASTCALL any2_clang(const float2& x)
		{
			return (x.x != 0.0f) || (x.y != 0.0f);
		}

		bool FASTCALL any3_clang(const float3& x)
		{
			return (x.x != 0.0f) || (x.y != 0.0f) || (x.z != 0.0f);
		}

		bool FASTCALL any4_clang(const float4& x)
		{
			return (x.x != 0.0f) || (x.y != 0.0f) || (x.z != 0.0f) || (x.w != 0.0f);
		}

		float2 FASTCALL ceil2_clang(const float2& v)
		{
			return float2(ceilf(v.x), ceilf(v.y));
		}

		float3 FASTCALL ceil3_clang(const float3& v)
		{
			return float3(ceilf(v.x), ceilf(v.y), ceilf(v.z));
		}

		float4 FASTCALL ceil4_clang(const float4& v)
		{
			return float4(ceilf(v.x), ceilf(v.y), ceilf(v.z), ceilf(v.w));
		}

		float3 FASTCALL cross3_clang(const float3& a, const float3& b)
		{
			return float3(
				a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x);
		}

		float4 FASTCALL cross4_clang(const float4& a, const float4& b)
		{
			return float4(
				a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x,
				1.0f);
		}

		float FASTCALL determinant2x2_clang(const float2x2& m)
		{
			return m._11 * m._22 - m._21 * m._12;
		}

		float FASTCALL determinant3x3_clang(const float3x3& m)
		{
			return m._11 * ((m._22 * m._33) - (m._32 * m._23)) -
				m._12 * (m._21 * m._33 - m._31 * m._23) +
				m._13 * (m._21 * m._32 - m._31 * m._22);
		}

		float FASTCALL determinant4x4_clang(const float4x4& m)
		{
			return m._14 * m._23 * m._32 * m._41 - m._13 * m._24 * m._32 * m._41 -
				m._14 * m._22 * m._33 * m._41 + m._12 * m._24 * m._33 * m._41 +
				m._13 * m._22 * m._34 * m._41 - m._12 * m._23 * m._34 * m._41 -
				m._14 * m._23 * m._31 * m._42 + m._13 * m._24 * m._31 * m._42 +
				m._14 * m._21 * m._33 * m._42 - m._11 * m._24 * m._33 * m._42 -
				m._13 * m._21 * m._34 * m._42 + m._11 * m._23 * m._34 * m._42 +
				m._14 * m._22 * m._31 * m._43 - m._12 * m._24 * m._31 * m._43 -
				m._14 * m._21 * m._32 * m._43 + m._11 * m._24 * m._32 * m._43 +
				m._12 * m._21 * m._34 * m._43 - m._11 * m._22 * m._34 * m._43 -
				m._13 * m._22 * m._31 * m._44 + m._12 * m._23 * m._31 * m._44 +
				m._13 * m._21 * m._32 * m._44 - m._11 * m._23 * m._32 * m._44 -
				m._12 * m._21 * m._33 * m._44 + m._11 * m._22 * m._33 * m._44;
		}

		float FASTCALL distance2_clang(const float2& a, const float2& b)
		{
			float dx = (a.x - b.x);
			float dy = (a.y - b.y);
			return sqrtf(dx * dx + dy * dy);
		}

		float FASTCALL distance3_clang(const float3& a, const float3& b)
		{
			float dx = (a.x - b.x);
			float dy = (a.y - b.y);
			float dz = (a.z - b.z);
			return sqrtf(dx * dx + dy * dy + dz * dz);
		}

		float FASTCALL distance4_clang(const float4& a, const float4& b)
		{
			float dx = (a.x - b.x);
			float dy = (a.y - b.y);
			float dz = (a.z - b.z);
			return sqrtf(dx * dx + dy * dy + dz * dz);
		}

		float4 FASTCALL dst_clang(const float& d)
		{
			return float4(1.0f, d, d * d, 1.0f / d);
		}

		float FASTCALL dot2_clang(const float2& a, const float2& b)
		{
			return (a.x * b.x + a.y * b.y);
		}

		float FASTCALL dot3_clang(const float3& a, const float3& b)
		{
			return (a.x * b.x + a.y * b.y + a.z * b.z);
		}

		float FASTCALL dot4_clang(const float4& a, const float4& b)
		{
			return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
		}

		float2 FASTCALL faceforward2_clang(const float2& n, const float2& i, const float2& ng)
		{
			return -n * fsign(i.x * ng.x + i.y * ng.y);
		}

		float3 FASTCALL faceforward3_clang(const float3& n, const float3& i, const float3& ng)
		{
			return -n * fsign(i.x * ng.x + i.y * ng.y + i.z * ng.z);
		}

		float4 FASTCALL faceforward4_clang(const float4& n, const float4& i, const float4& ng)
		{
			return -n * fsign(i.x * ng.x + i.y * ng.y + i.z * ng.z + i.w * ng.w);
		}

		float2 FASTCALL floor2_clang(const float2& v)
		{
			return float2(floorf(v.x), floorf(v.y));
		}

		float3 FASTCALL floor3_clang(const float3& v)
		{
			return float3(floorf(v.x), floorf(v.y), floorf(v.z));
		}

		float4 FASTCALL floor4_clang(const float4& v)
		{
			return float4(floorf(v.x), floorf(v.y), floorf(v.z), floorf(v.w));
		}

		float FASTCALL length2_clang(const float2& v)
		{
			return sqrtf(v.x * v.x + v.y * v.y);
		}

		float FASTCALL length3_clang(const float3& v)
		{
			return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
		}

		float FASTCALL length4_clang(const float4& v)
		{
			return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
		}

		float2 FASTCALL lerp2_clang(const float2& a, const float2& b, const float& s)
		{
			return a + (b - a) * s;
		}

		float3 FASTCALL lerp3_clang(const float3& a, const float3& b, const float& s)
		{
			return a + (b - a) * s;
		}

		float4 FASTCALL lerp4_clang(const float4& a, const float4& b, const float& s)
		{
			return a + (b - a) * s;
		}

		float2 FASTCALL mad2_clang(const float2& a, const float& s, const float2& b)
		{
			return a * s + b;
		}

		float3 FASTCALL mad3_clang(const float3& a, const float& s, const float3& b)
		{
			return a * s + b;
		}

		float4 FASTCALL mad4_clang(const float4& a, const float& s, const float4& b)
		{
			return a * s + b;
		}

		float2x2 FASTCALL mul2x2_clang(const float2x2& a, const float2x2& b)
		{
			float2x2 result;
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					result._m[i][j] = a._m[i][0] * b._m[0][j] +
						a._m[i][1] * b._m[1][j];
				}
			}
			return result;
		}

		float3x3 FASTCALL mul3x3_clang(const float3x3& a, const float3x3& b)
		{
			float3x3 result;
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					result._m[i][j] = a._m[i][0] * b._m[0][j] +
						a._m[i][1] * b._m[1][j] +
						a._m[i][2] * b._m[2][j];
				}
			}
			return result;
		}

		float4x4 FASTCALL mul4x4_clang(const float4x4& a, const float4x4& b)
		{
			float4x4 result;
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					result._m[i][j] = a._m[i][0] * b._m[0][j] +
						a._m[i][1] * b._m[1][j] +
						a._m[i][2] * b._m[2][j] +
						a._m[i][3] * b._m[3][j];
				}
			}
			return result;
		}

		float2 FASTCALL mul2_clang(const float2& a, const float2x2& b)
		{
			//NYI
			return float2();
		}

		float3 FASTCALL mul3_clang(const float3& a, const float3x3& b)
		{
			//NYI
			return float3();
		}

		float4 FASTCALL mul4_clang(const float4& a, const float4x4& b)
		{
			//NYI
			return float4();
		}

		float3 FASTCALL mul43_clang(const float3& v, const float4x4& b)
		{
			//NYI
			return float3();
		}

		float2 FASTCALL normalize2_clang(const float2& v)
		{
			float squaredLength = (v.x * v.x + v.y * v.y);
			float invertedLength = frsqrt(squaredLength);
			return float2(v.x * invertedLength, v.y * invertedLength);
		}

		float3 FASTCALL normalize3_clang(const float3& v)
		{
			float squaredLength = (v.x * v.x + v.y * v.y + v.z * v.z);
			float invertedLength = frsqrt(squaredLength);
			return float3(v.x * invertedLength, v.y * invertedLength, v.z * invertedLength);
		}

		float4 FASTCALL normalize4_clang(const float4& v)
		{
			float squaredLength = (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
			float invertedLength = frsqrt(squaredLength);
			return float4(v.x * invertedLength, v.y * invertedLength, v.z * invertedLength, v.w * invertedLength);
		}

		float3 FASTCALL normal3_clang(const float3& a, const float3& b, const float3& c)
		{
			return cross3_clang(b - a, c - a);
		}

		float2 FASTCALL reflect2_clang(const float2& i, const float2& n)
		{
			return i - n * dot2_clang(i, n) * 2.0f;
		}

		float3 FASTCALL reflect3_clang(const float3& i, const float3& n)
		{
			return i - n * dot3_clang(i, n) * 2.0f;
		}

		float4 FASTCALL reflect4_clang(const float4& i, const float4& n)
		{
			return i - n * dot4_clang(i, n) * 2.0f;
		}

		float2 FASTCALL refract2_clang(const float2& i, const float2& n, const float& eta)
		{
			float k = 1.0f - eta * eta * (1.0f - dot2_clang(n, i) * dot2_clang(n, i));
			if (k < 0.0f)
				return float2(0.0f, 0.f);
			else
				return i * eta - n * (eta * dot2_clang(n, i) + sqrtf(k));
		}

		float3 FASTCALL refract3_clang(const float3& i, const float3& n, const float& eta)
		{
			float k = 1.0f - eta * eta * (1.0f - dot3_clang(n, i) * dot3_clang(n, i));
			if (k < 0.0f)
				return float3(0.0f, 0.f, 0.0f);
			else
				return i * eta - n * (eta * dot3_clang(n, i) + sqrtf(k));
		}

		float4 FASTCALL refract4_clang(const float4& i, const float4& n, const float& eta)
		{
			float k = 1.0f - eta * eta * (1.0f - dot4_clang(n, i) * dot4_clang(n, i));
			if (k < 0.0f)
				return float4(0.0f, 0.f, 0.0f, 0.f);
			else
				return i * eta - n * (eta * dot4_clang(n, i) + sqrtf(k));
		}

		float2 FASTCALL round2_clang(const float2& v)
		{
			return float2(roundf(v.x), roundf(v.y));
		}

		float3 FASTCALL round3_clang(const float3& v)
		{
			return float3(roundf(v.x), roundf(v.y), roundf(v.z));
		}

		float4 FASTCALL round4_clang(const float4& v)
		{
			return float4(roundf(v.x), roundf(v.y), roundf(v.z), roundf(v.w));
		}

		float2x2 FASTCALL transpose2x2_clang(const float2x2& m)
		{
			return float2x2(
				m._11, m._21,
				m._12, m._22);
		}

		float3x3 FASTCALL transpose3x3_clang(const float3x3& m)
		{
			return float3x3(
				m._11, m._21, m._31,
				m._12, m._22, m._32,
				m._13, m._23, m._33);
		}

		float4x4 FASTCALL transpose4x4_clang(const float4x4& m)
		{
			return float4x4(
				m._11, m._21, m._31, m._41,
				m._12, m._22, m._32, m._42,
				m._13, m._23, m._33, m._43,
				m._14, m._24, m._34, m._44);
		}
	}
}