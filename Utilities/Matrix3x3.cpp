#include "stdafx.h"

namespace OpenGm
{
	namespace Utilities
	{
		float3x3 Matrix3x3::Identity = float3x3(
			1.0f, 0.0f, 0.0f, 
			0.0f, 1.0f, 0.0f, 
			0.0f, 0.0f, 1.0f);

		GMAPI float3x3 Matrix3x3::MultiplyTranspose(const float3x3& m1, const float3x3& m2)
		{
			float3x3 temp;

			mul3x3(temp, m1, m2);
			return float3x3(
				temp._11, temp._21, temp._31,
				temp._12, temp._22, temp._32,
				temp._13, temp._23, temp._33);
		}

		GMAPI float3x3 Matrix3x3::MakeUniformScale(float scale)
		{
			return float3x3(
				scale, 0.0f, 0.0f,
				0.0f, scale, 0.0f,
				0.0f, 0.0f, scale);
		}

		GMAPI float3x3 Matrix3x3::MakeScale(float scaleX, float scaleY, float scaleZ)
		{
			return float3x3(
				scaleX, 0.0f, 0.0f,
				0.0f, scaleY, 0.0f,
				0.0f, 0.0f, scaleZ);
		}

		GMAPI float3x3 Matrix3x3::MakeScale(const float3& scale)
		{
			return float3x3(
				scale.x, 0.0f, 0.0f,
				0.0f, scale.y, 0.0f,
				0.0f, 0.0f, scale.z);
		}

		GMAPI float3x3 Matrix3x3::MakeTranslation(const float3& translate)
		{
			return float3x3(
				1.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f,
				translate.x, translate.y, translate.z);
		}

		GMAPI float3x3 Matrix3x3::MakeTranslation(float translateX, float translateY, float translateZ)
		{
			return float3x3(
				1.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f,
				translateX, translateY, translateZ);
		}

		GMAPI float3x3 Matrix3x3::MakeXRotation(float angle)
		{
			float cosa = cosf(angle);
			float sina = sinf(angle);

			return float3x3(
				1.0f, 0.0f, 0.0f,
				0.0f, cosa, sina,
				0.0f, -sina, cosa);
		}

		GMAPI float3x3 Matrix3x3::MakeYRotation(float angle)
		{
			float cosa = cosf(angle);
			float sina = sinf(angle);

			return float3x3(
				cosa, 0.0f, -sina,
				0.0f, 1.0f, 0.0f,
				sina, 0.0f, cosa);
		}

		GMAPI float3x3 Matrix3x3::MakeZRotation(float angle)
		{
			float cosa = cosf(angle);
			float sina = sinf(angle);

			return float3x3(
				cosa, sina, 0.0f,
				-sina, cosa, 0.0f,
				0.0f, 0.0f, 1.0f);
		}

		GMAPI float3x3 Matrix3x3::MakeRotationAroundAxis(const float3& axis, float angle)
		{
			float cosa = cosf(angle);
			float sina = sinf(angle);

			float3x3 result;
			result._11 = (axis.x * axis.x) * (1.0f - cosa) + cosa;
			result._12 = (axis.x * axis.y) * (1.0f - cosa) - (axis.z * sina);
			result._13 = (axis.x * axis.z) * (1.0f - cosa) + (axis.y * sina);

			result._21 = (axis.y * axis.x) * (1.0f - cosa) + (axis.z * sina);
			result._22 = (axis.y * axis.y) * (1.0f - cosa) + cosa;
			result._23 = (axis.y * axis.z) * (1.0f - cosa) - (axis.x * sina);

			result._31 = (axis.z * axis.x) * (1.0f - cosa) - (axis.y * sina);
			result._32 = (axis.z * axis.y) * (1.0f - cosa) + (axis.x * sina);
			result._33 = (axis.z * axis.z) * (1.0f - cosa) + cosa;
			return result;
		}

		GMAPI float3x3 Matrix3x3::MakeRotation(float yaw, float pitch, float roll)
		{
			float cosc = cosf(yaw);
			float sinc = sinf(yaw);
			float cosb = cosf(pitch);
			float sinb = sinf(pitch);
			float cosa = cosf(roll);
			float sina = sinf(roll);

			return float3x3(
				cosa*cosb, cosa*sinb*sinc - sina * cosc, cosa*sinb*cosc + sina * sinc,
				sina*cosb, sina*sinb*sinc - cosa * cosc, sina*sinb*cosc - cosa * sinc,
				-sinb, cosb*sinc, cosb*cosc);
		}

		GMAPI float3x3 Matrix3x3::MakeRotation(const float3& angles)
		{
			float cosc = cosf(angles.x);
			float sinc = sinf(angles.x);
			float cosb = cosf(angles.y);
			float sinb = sinf(angles.y);
			float cosa = cosf(angles.z);
			float sina = sinf(angles.z);

			return float3x3(
				cosa*cosb, cosa*sinb*sinc - sina * cosc, cosa*sinb*cosc + sina * sinc,
				sina*cosb, sina*sinb*sinc - cosa * cosc, sina*sinb*cosc - cosa * sinc,
				-sinb, cosb*sinc, cosb*cosc);
		}
	}
}