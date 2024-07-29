#include "stdafx.h"

namespace GlacialBytes
{
	namespace OpenGm
	{
		namespace Utilities
		{
			xform3d AffineTransformation::FormLookAtRH(const float3& eye, const float3& at, const float3& up)
			{
				// Get the z basis vector, which points straight ahead; the
				// difference from the eye point to the look-at point. This is the 
				// direction of the gaze (+z).
				float3 zAxis = normalize3(at - eye);
				
				// Compute the orthogonal axes from the cross product of the gaze 
				// and the pUp vector.
				float3 xAxis = normalize3(cross3(up, zAxis));
				float3 yAxis = cross3(zAxis, xAxis);

				// Start building the matrix. The first three rows contain the 
				// basis vectors used to rotate the view to point at the look-at 
				// point. The fourth row contains the translation values. 
				// Rotations are still about the eyepoint.
				xform3d result;
				result._11 = xAxis.x;
				result._21 = xAxis.y;
				result._31 = xAxis.z;
				result._41 = -dot3(xAxis, eye);

				result._12 = yAxis.x;
				result._22 = yAxis.y;
				result._32 = yAxis.z;
				result._42 = -dot3(yAxis, eye);

				result._13 = zAxis.x;
				result._23 = zAxis.y;
				result._33 = zAxis.z;
				result._43 = -dot3(zAxis, eye);
				return result;
			}

			xform3d AffineTransformation::FormLookAtLH(const float3& eye, const float3& at, const float3& up)
			{
				float3 zAxis = normalize3(eye - at);
				float3 xAxis = normalize3(cross3(up, zAxis));
				float3 yAxis = cross3(zAxis, xAxis);

				xform3d result;
				result._11 = xAxis.x;
				result._21 = xAxis.y;
				result._31 = xAxis.z;
				result._41 = -dot3(xAxis, eye);

				result._12 = yAxis.x;
				result._22 = yAxis.y;
				result._32 = yAxis.z;
				result._42 = -dot3(yAxis, eye);

				result._13 = zAxis.x;
				result._23 = zAxis.y;
				result._33 = zAxis.z;
				result._43 = -dot3(zAxis, eye);
				return result;
			}

			xform3d AffineTransformation::MakeUniformScale(const float scale)
			{
				return xform3d(
					scale, 0.0f, 0.0f,
					0.0f, scale, 0.0f,
					0.0f, 0.0f, scale,
					0.0f, 0.0f, 0.0f);
			}

			xform3d AffineTransformation::MakeScale(const float scaleX, const float scaleY, const float scaleZ)
			{
				return xform3d(
					scaleX, 0.0f, 0.0f,
					0.0f, scaleY, 0.0f,
					0.0f, 0.0f, scaleZ,
					0.0f, 0.0f, 0.0f);
			}

			xform3d AffineTransformation::MakeScale(const float3& scale)
			{
				return xform3d(
					scale.x, 0.0f, 0.0f,
					0.0f, scale.y, 0.0f,
					0.0f, 0.0f, scale.z,
					0.0f, 0.0f, 0.0f);
			}

			xform3d AffineTransformation::MakeTranslation(const float3& translate)
			{
				return xform3d(
					1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 1.0f,
					translate.x, translate.y, translate.z);
			}

			xform3d AffineTransformation::MakeTranslation(const float translateX, const float translateY, const float translateZ)
			{
				return xform3d(
					1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 1.0f,
					translateX, translateY, translateZ);
			}

			xform3d AffineTransformation::MakeXRotation(const float angle)
			{
				float cosa = cosf(angle);
				float sina = sinf(angle);

				return xform3d(
					1.0f, 0.0f, 0.0f,
					0.0f, cosa, sina,
					0.0f, -sina, cosa,
					0.0f, 0.0f, 0.0f);
			}

			xform3d AffineTransformation::MakeYRotation(const float angle)
			{
				float cosa = cosf(angle);
				float sina = sinf(angle);

				return xform3d(
					cosa, 0.0f, -sina,
					0.0f, 1.0f, 0.0f,
					sina, 0.0f, cosa,
					0.0f, 0.0f, 0.0f);
			}

			xform3d AffineTransformation::MakeZRotation(const float angle)
			{
				float cosa = cosf(angle);
				float sina = sinf(angle);

				return xform3d(
					cosa, sina, 0.0f,
					-sina, cosa, 0.0f,
					0.0f, 0.0f, 1.0f,
					0.0f, 0.0f, 0.0f);
			}

			xform3d AffineTransformation::MakeCompositeTransformation(const float3& translation, const float4& rotation)
			{
				float xx = rotation.x * rotation.x, xy = rotation.x * rotation.y, xz = rotation.x * rotation.z, xw = rotation.x * rotation.w;
				float yy = rotation.y * rotation.y, yz = rotation.y * rotation.z, yw = rotation.y * rotation.w;
				float zz = rotation.z * rotation.z, zw = rotation.z * rotation.w;
				float ww = rotation.w * rotation.w;

				xform3d result;
				result._11 = xx - yy - zz + ww;
				result._12 = 2.0f * (xy - zw);
				result._13 = 2.0f * (xz + yw);

				result._21 = 2.0f * (xy + zw);
				result._22 = -xx + yy - zz + ww;
				result._23 = 2.0f * (yz - xw);

				result._31 = 2.0f * (xz - yw);
				result._32 = 2.0f * (yz + xw);
				result._33 = -xx - yy + zz + ww;

				result._41 = translation.x;
				result._42 = translation.y;
				result._43 = translation.z;
				return result;
			}
		}
	}
}