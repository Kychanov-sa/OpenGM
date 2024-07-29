#include "stdafx.h"

#define QUAT_ZEROTOLERANCE	0.00001f
#define QUAT_EPSILON		0.00001f

namespace GlacialBytes
{
	namespace OpenGm
	{
		namespace Utilities
		{
			float4 Quaternion::Multiply(const float4& quat1, const float4& quat2)
			{
				float4 result;
				result.w = ((quat1.w * quat2.w) - (quat1.x * quat2.x)
					- (quat1.y * quat2.y) - (quat1.z * quat2.z));

				result.x = ((quat1.w * quat2.x) + (quat1.x * quat2.w)
					+ (quat1.y * quat2.z) - (quat1.z * quat2.y));

				result.y = ((quat1.w * quat2.y) - (quat1.x * quat2.z)
					+ (quat1.y * quat2.w) + (quat1.z * quat2.x));

				result.z = ((quat1.w * quat2.z) + (quat1.x * quat2.y)
					- (quat1.y * quat2.x) + (quat1.z * quat2.w));
			}

			float Quaternion::GetLength(const float4& quat)
			{
				return (quat.w * quat.w) + (quat.x * quat.x) + (quat.y * quat.y) + (quat.z * quat.z);
			}

			void Quaternion::Normalize(float4& quat)
			{
				float one_over_magnitude = 1.0f / sqrtf((quat.w * quat.w) + (quat.x * quat.x) + (quat.y * quat.y) + (quat.z * quat.z));
				quat.w *= one_over_magnitude;
				quat.x *= one_over_magnitude;
				quat.y *= one_over_magnitude;
				quat.z *= one_over_magnitude;
			}

			float4 Quaternion::GetNormalized(float4& quat)
			{
				float one_over_magnitude = 1.0f / sqrtf((quat.w * quat.w) + (quat.x * quat.x) + (quat.y * quat.y) + (quat.z * quat.z));
				return quat * one_over_magnitude;
			}

			void Quaternion::Inverse(float4& quat)
			{
				quat.w = quat.w;
				quat.x = -quat.x;
				quat.y = -quat.y;
				quat.z = -quat.z;
			}

			float4 Quaternion::GetInverted(float4& quat)
			{
				return float4(-quat.x, -quat.y, -quat.z, quat.w);
			}

			float4 Quaternion::Pow(float4& quat, float exponent)
			{
				// Check for the case of identity quaterion
				if (fabs(quat.w) < 0.9999f)
				{
					// Extract the half angle (alpha=theta/2)
					float alpha = acosf(quat.w);

					// Compute new alpha value
					float newAlpha = alpha * exponent;

					return float4(quat.xyz * sinf(newAlpha) / sinf(alpha), cosf(newAlpha));
				}
			}

			float4 Quaternion::Slerp(const float4& quat1, const float4& quat2, float t)
			{
				float	p1[4];
				float	omega, cosom, sinom, scale0, scale1;

				cosom = quat1.x * quat2.x + quat1.y * quat2.y + quat1.z * quat2.z + quat1.w * quat2.w;
				if (cosom < 0.0f)
				{
					cosom = -cosom;
					p1[0] = -quat2.x;  p1[1] = -quat2.y;
					p1[2] = -quat2.z;  p1[3] = -quat2.w;
				}
				else {
					p1[0] = quat2.x;  p1[1] = quat2.y;
					p1[2] = quat2.z;  p1[3] = quat2.w;
				}

				if ((1.0f - cosom) > QUAT_EPSILON)
				{
					omega = acosf(cosom);
					sinom = sinf(omega);
					scale0 = sinf((1.0f - t) * omega) / sinom;
					scale1 = sinf(t * omega) / sinom;
				}
				else {
					scale0 = 1.0f - t;
					scale1 = t;
				}

				float4 result;
				result.x = scale0 * quat1.x + scale1 * p1[0];
				result.y = scale0 * quat1.y + scale1 * p1[1];
				result.z = scale0 * quat1.z + scale1 * p1[2];
				result.w = scale0 * quat1.w + scale1 * p1[3];
				return result;
			}

			float3 Quaternion::RotateVector(const float3& in, const float4& quat)
			{
#if 1
					float xxzz = quat.x * quat.x - quat.z * quat.z;
					float wwyy = quat.w * quat.w - quat.y * quat.y;

					float xw2 = quat.x * quat.w * 2.0f;
					float xy2 = quat.x * quat.y * 2.0f;
					float xz2 = quat.x * quat.z * 2.0f;
					float yw2 = quat.y * quat.w * 2.0f;
					float yz2 = quat.y * quat.z * 2.0f;
					float zw2 = quat.z * quat.w * 2.0f;

					float3 result;
					result.x = (xxzz + wwyy) * in.x + (xy2 + zw2) * in.y + (xz2 - yw2) * in.z;
					result.y = -((xy2 - zw2) * in.x + (xxzz - wwyy) * in.y + (yz2 + xw2) * in.z);
					result.z = (xz2 + yw2) * in.x + (yz2 - xw2) * in.y + (wwyy - xxzz) * in.z;
#else
					float3x3 rotMatrix;
					gmuquaternionToMatrix3x3(rotMatrix, quat);
					mul3(result.In, rotMatrix);
#endif
			}
			
			float4 Quaternion::FromSpherical(float latitude, float longitude, float angle)
			{
				float sin_a = sinf(angle / 2.0f);
				float cos_a = cosf(angle / 2.0f);

				float sin_lat = sinf(latitude);
				float cos_lat = cosf(latitude);

				float sin_long = sinf(longitude);
				float cos_long = cosf(longitude);

				float4 result;
				result.x = sin_a * cos_lat * sin_long;
				result.y = sin_a * sin_lat;
				result.z = sin_a * sin_lat * cos_long;
				result.w = cos_a;
				return result;
			}

			float4 Quaternion::FromYawPitchRoll(float yaw, float pitch, float roll)
			{
				// Compute sine and cosine of the half angles
				float	scp[2], scr[2], scy[2];
				fsincos(pitch * 0.5f, scp[0], scp[1]);
				fsincos(roll * 0.5f, scr[0], scr[1]);
				fsincos(yaw * 0.5f, scy[0], scy[1]);

				// Compute values	
				float4 result;
				result.x = scy[1] * scp[0] * scr[1] + scy[0] * scp[1] * scr[0];
				result.y = -scy[1] * scp[0] * scr[0] + scy[0] * scp[1] * scr[1];
				result.z = -scy[0] * scp[0] * scr[1] + scy[1] * scp[1] * scr[0];
				result.w = scy[1] * scp[1] * scr[1] + scy[0] * scp[0] * scr[0];
				return result;

				/*float SinYaw   = sinf(Yaw*0.5f);
				float SinPitch = sinf(Pitch*0.5f);
				float SinRoll  = sinf(Roll*0.5f);
				float CosYaw   = cosf(Yaw*0.5f);
				float CosPitch = cosf(Pitch*0.5f);
				float CosRoll  = cosf(Roll*0.5f);

				Quat.x = SinRoll * CosPitch * CosYaw - CosRoll * SinPitch * SinYaw;
				Quat.y = CosRoll * SinPitch * CosYaw + SinRoll * CosPitch * SinYaw;
				Quat.z = CosRoll * CosPitch * SinYaw - SinRoll * SinPitch * CosYaw;
				Quat.w = CosRoll * CosPitch * CosYaw + SinRoll * SinPitch * SinYaw;*/
			}

			float4 Quaternion::FromMatrix3x3(const float3x3& rotation)
			{
				float4 result;
				float	tr, s, q[4];
				int		i, j, k;
				int		nxt[3] = { 1, 2, 0 };

				tr = rotation._11 + rotation._22 + rotation._33;
				if (tr > 0.0f)
				{
					s = sqrtf(tr + 1.0f);
					result.w = s / 2.0f;
					s = 0.5f / s;
					result.x = (rotation._23 - rotation._32) * s;
					result.y = (rotation._31 - rotation._13) * s;
					result.z = (rotation._12 - rotation._21) * s;
				} else {
					i = 0;
					if (rotation._22 > rotation._11)		i = 1;
					if (rotation._33 > rotation.m[i * 3 + i]) i = 2;
					j = nxt[i];
					k = nxt[j];

					s = sqrtf((rotation.m[i * 3 + i] - (rotation.m[j * 3 + j] + rotation.m[k * 3 + k])) + 1.0f);
					q[i] = s * 0.5f;

					if (s != 0.0f) s = 0.5f / s;

					q[3] = (rotation.m[j * 3 + k] - rotation.m[k * 3 + j]) * s;
					q[j] = (rotation.m[i * 3 + j] + rotation.m[j * 3 + i]) * s;
					q[k] = (rotation.m[i * 3 + k] + rotation.m[k * 3 + i]) * s;

					result.x = q[0];
					result.y = q[1];
					result.z = q[2];
					result.w = q[3];
				}
				return result;
			}

			float4 Quaternion::FromMatrix4x4(const float4x4& rotation)
			{
				float4 result;
				float	tr, s, q[4];
				int		i, j, k;
				int		nxt[3] = { 1, 2, 0 };

				tr = rotation._11 + rotation._22 + rotation._33;

				if (tr > 0.0f)
				{
					s = sqrtf(tr + 1.0f);
					result.w = s / 2.0f;
					s = 0.5f / s;
					result.x = (rotation._23 - rotation._32) * s;
					result.y = (rotation._31 - rotation._13) * s;
					result.z = (rotation._12 - rotation._21) * s;
				}
				else {
					i = 0;
					if (rotation._22 > rotation._11)		i = 1;
					if (rotation._33 > rotation.m[i * 4 + i]) i = 2;
					j = nxt[i];
					k = nxt[j];

					s = sqrtf((rotation.m[i * 4 + i] - (rotation.m[j * 4 + j] + rotation.m[k * 4 + k])) + 1.0f);
					q[i] = s * 0.5f;

					if (s != 0.0f) s = 0.5f / s;

					q[3] = (rotation.m[j * 4 + k] - rotation.m[k * 4 + j]) * s;
					q[j] = (rotation.m[i * 4 + j] + rotation.m[j * 4 + i]) * s;
					q[k] = (rotation.m[i * 4 + k] + rotation.m[k * 4 + i]) * s;

					result.x = q[0];
					result.y = q[1];
					result.z = q[2];
					result.w = q[3];
				}
				return result;
			}

			float4 Quaternion::FromShortestArc(const float3& from, const float3& to)
			{
				float4 result;
				float3 c;
				float	one_over_magnitude;

				c = cross3(from, to);
				result.x = c.x;
				result.y = c.y;
				result.z = c.z;
				result.w = dot3(from, to);

				one_over_magnitude = 1.0f / sqrtf((result.w * result.w) + (result.x * result.x) + (result.y * result.y) + (result.z * result.z));
				result.w *= one_over_magnitude;
				result.x *= one_over_magnitude;
				result.y *= one_over_magnitude;
				result.z *= one_over_magnitude;

				result.w += 1.0f;	// reducing angle to halfangle

				if (result.w <= QUAT_EPSILON)
				{
					// angle close to PI
					if ((from.z * from.z) > (from.x * from.x))
					{
						result.x = 0.0f;
						result.y = from.z;
						result.z = -from.y;
					}
					else {
						result.x = from.y;
						result.y = -from.x;
						result.z = 0;
					}
				}

				one_over_magnitude = 1.0f / sqrtf((result.w * result.w) + (result.x * result.x) + (result.y * result.y) + (result.z * result.z));
				result.w *= one_over_magnitude;
				result.x *= one_over_magnitude;
				result.y *= one_over_magnitude;
				result.z *= one_over_magnitude;
				return result;
			}
			
			float3x3 Quaternion::ToMatrix3x3(const float4& quat)
			{
				float xx = quat.x * quat.x, xy = quat.x * quat.y, xz = quat.x * quat.z, xw = quat.x * quat.w;
				float yy = quat.y * quat.y, yz = quat.y * quat.z, yw = quat.y * quat.w;
				float zz = quat.z * quat.z, zw = quat.z * quat.w;
				float ww = quat.w * quat.w;

				float4x4 result;
				result._11 = xx - yy - zz + ww;
				result._12 = 2.0f * (xy - zw);
				result._13 = 2.0f * (xz + yw);

				result._21 = 2.0f * (xy + zw);
				result._22 = -xx + yy - zz + ww;
				result._23 = 2.0f * (yz - xw);

				result._31 = 2.0f * (xz - yw);
				result._32 = 2.0f * (yz + xw);
				result._33 = -xx - yy + zz + ww;
				return result;
			}
			
			float4x4 Quaternion::ToMatrix4x4(const float4& quat)
			{
				float xx = quat.x * quat.x, xy = quat.x * quat.y, xz = quat.x * quat.z, xw = quat.x * quat.w;
				float yy = quat.y * quat.y, yz = quat.y * quat.z, yw = quat.y * quat.w;
				float zz = quat.z * quat.z, zw = quat.z * quat.w;
				float ww = quat.w * quat.w;

				float4x4 result;
				result._11 = xx - yy - zz + ww;
				result._12 = 2.0f * (xy - zw);
				result._13 = 2.0f * (xz + yw);

				result._21 = 2.0f * (xy + zw);
				result._22 = -xx + yy - zz + ww;
				result._23 = 2.0f * (yz - xw);

				result._31 = 2.0f * (xz - yw);
				result._32 = 2.0f * (yz + xw);
				result._33 = -xx - yy + zz + ww;

				result._14 = result._41 = 0.0f;
				result._24 = result._42 = 0.0f;
				result._34 = result._43 = 0.0f;
				result._44 = xx + yy + zz + ww;
				return result;
			}
		}
	}
}