#include "stdafx.h"

namespace OpenGm
{
	namespace Utilities
	{
		float4x4 Matrix4x4::Identity = float4x4(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);

		GMAPI float4x4 Matrix4x4::MultiplyTranspose(const float4x4& m1, const float4x4& m2)
		{
			float4x4 temp;

			mul4x4(temp, m1, m2);
			return float4x4(
				temp._11, temp._21, temp._31, temp._41,
				temp._12, temp._22, temp._32, temp._42,
				temp._13, temp._23, temp._33, temp._43,
				temp._14, temp._24, temp._34, temp._44);
		}

		GMAPI float4x4 Matrix4x4::MakeUniformScale(float scale)
		{
			return float4x4(
				scale, 0.0f, 0.0f, 0.0f,
				0.0f, scale, 0.0f, 0.0f,
				0.0f, 0.0f, scale, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		GMAPI float4x4 Matrix4x4::MakeScale(float scaleX, float scaleY, float scaleZ)
		{
			return float4x4(
				scaleX, 0.0f, 0.0f, 0.0f,
				0.0f, scaleY, 0.0f, 0.0f,
				0.0f, 0.0f, scaleZ, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		GMAPI float4x4 Matrix4x4::MakeScale(const float3& scale)
		{
			return float4x4(
				scale.x, 0.0f, 0.0f, 0.0f,
				0.0f, scale.y, 0.0f, 0.0f,
				0.0f, 0.0f, scale.z, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		GMAPI float4x4 Matrix4x4::MakeTranslation(const float3& translate)
		{
			return float4x4(
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				translate.x, translate.y, translate.z, 1.0f);
		}

		GMAPI float4x4 Matrix4x4::MakeTranslation(float translateX, float translateY, float translateZ)
		{
			return float4x4(
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				translateX, translateY, translateZ, 1.0f);
		}

		GMAPI float4x4 Matrix4x4::MakeXRotation(float angle)
		{
			float cosa = cosf(angle);
			float sina = sinf(angle);

			return float4x4(
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, cosa, sina, 0.0f,
				0.0f, -sina, cosa, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		GMAPI float4x4 Matrix4x4::MakeYRotation(float angle)
		{
			float cosa = cosf(angle);
			float sina = sinf(angle);

			return float4x4(
				cosa, 0.0f, -sina, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				sina, 0.0f, cosa, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		GMAPI float4x4 Matrix4x4::MakeZRotation(float angle)
		{
			float cosa = cosf(angle);
			float sina = sinf(angle);

			return float4x4(
				cosa, sina, 0.0f, 0.0f,
				-sina, cosa, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		GMAPI float4x4 Matrix4x4::MakeRotationAroundAxis(const float3& axis, float angle)
		{
			float cosa = cosf(angle);
			float sina = sinf(angle);

			float4x4 result;
			result._11 = (axis.x * axis.x) * (1.0f - cosa) + cosa;
			result._12 = (axis.x * axis.y) * (1.0f - cosa) - (axis.z * sina);
			result._13 = (axis.x * axis.z) * (1.0f - cosa) + (axis.y * sina);

			result._21 = (axis.y * axis.x) * (1.0f - cosa) + (axis.z * sina);
			result._22 = (axis.y * axis.y) * (1.0f - cosa) + cosa;
			result._23 = (axis.y * axis.z) * (1.0f - cosa) - (axis.x * sina);

			result._31 = (axis.z * axis.x) * (1.0f - cosa) - (axis.y * sina);
			result._32 = (axis.z * axis.y) * (1.0f - cosa) + (axis.x * sina);
			result._33 = (axis.z * axis.z) * (1.0f - cosa) + cosa;

			result._14 = result._24 = result._34 = 0.0f;
			result._41 = result._42 = result._43 = 0.0f;
			result._44 = 1.0f;
			return result;
		}

		GMAPI float4x4 Matrix4x4::MakeRotation(float yaw, float pitch, float roll)
		{
			float cosc= cosf(yaw);
			float sinc= sinf(yaw);
			float cosb= cosf(pitch);
			float sinb= sinf(pitch);
			float cosa= cosf(roll);
			float sina= sinf(roll);

			return float4x4(
				cosa*cosb,	cosa*sinb*sinc - sina*cosc,	cosa*sinb*cosc + sina*sinc,	0.0f,
				sina*cosb,	sina*sinb*sinc - cosa*cosc, sina*sinb*cosc - cosa*sinc, 0.0f,
				-sinb,		cosb*sinc,					cosb*cosc,					0.0f,
				0.0f,		0.0f,						0.0f,						1.0f);
		}

		GMAPI float4x4 Matrix4x4::MakeRotation(const float3& angles)
		{
			float cosc = cosf(angles.x);
			float sinc = sinf(angles.x);
			float cosb = cosf(angles.y);
			float sinb = sinf(angles.y);
			float cosa = cosf(angles.z);
			float sina = sinf(angles.z);

			return float4x4(
				cosa*cosb, cosa*sinb*sinc - sina * cosc, cosa*sinb*cosc + sina * sinc, 0.0f,
				sina*cosb, sina*sinb*sinc - cosa * cosc, sina*sinb*cosc - cosa * sinc, 0.0f,
				-sinb, cosb*sinc, cosb*cosc, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		GMAPI float4x4 Matrix4x4::MakeCompositeTransformation(const float3& translation, const float4& rotation)
		{
			float xx = rotation.x*rotation.x, xy = rotation.x*rotation.y, xz = rotation.x*rotation.z, xw = rotation.x*rotation.w;
			float yy = rotation.y*rotation.y, yz = rotation.y*rotation.z, yw = rotation.y*rotation.w;
			float zz = rotation.z*rotation.z, zw = rotation.z*rotation.w;
			float ww = rotation.w*rotation.w;

			float4x4 result;
			result._11 = xx - yy - zz + ww;
			result._12 = 2.0f*(xy - zw);
			result._13 = 2.0f*(xz + yw);
			result._13 = 0.0f;

			result._21 = 2.0f*(xy + zw);
			result._22 = -xx + yy - zz + ww;
			result._23 = 2.0f*(yz - xw);
			result._24 = 0.0f;

			result._31 = 2.0f*(xz - yw);
			result._32 = 2.0f*(yz + xw);
			result._33 = -xx - yy + zz + ww;
			result._34 = 0.0f;

			result._41 = translation.x;
			result._42 = translation.y;
			result._43 = translation.z;
			result._44 = 1.0f;
			return result;
		}
	}
}