#include "stdafx.h"

#define QUAT_ZEROTOLERANCE	0.00001f
#define QUAT_EPSILON		0.00001f

namespace OpenGm
{
	namespace Utilities
	{
		GMAPI void gmuQuaternionMultiply(float4& Out, const float4& Quat1, const float4& Quat2)
		{
			Out.w = ((Quat1.w*Quat2.w) - (Quat1.x*Quat2.x)
				- (Quat1.y*Quat2.y) - (Quat1.z*Quat2.z));

			Out.x = ((Quat1.w*Quat2.x) + (Quat1.x*Quat2.w)
				+ (Quat1.y*Quat2.z) - (Quat1.z*Quat2.y));

			Out.y = ((Quat1.w*Quat2.y) - (Quat1.x*Quat2.z)
				+ (Quat1.y*Quat2.w) + (Quat1.z*Quat2.x));

			Out.z = ((Quat1.w*Quat2.z) + (Quat1.x*Quat2.y)
				- (Quat1.y*Quat2.x) + (Quat1.z*Quat2.w));
		}

		GMAPI float gmuQuaternionLength(const float4& Quat)
		{
			return (Quat.w*Quat.w) + (Quat.x*Quat.x) + (Quat.y*Quat.y) + (Quat.z*Quat.z);
		}

		GMAPI void gmuQuaternionNormalize(float4& Quat)
		{
			float one_over_magnitude = 1.0f / sqrtf((Quat.w*Quat.w) + (Quat.x*Quat.x) + (Quat.y*Quat.y) + (Quat.z*Quat.z));
			Quat.w *= one_over_magnitude;
			Quat.x *= one_over_magnitude;
			Quat.y *= one_over_magnitude;
			Quat.z *= one_over_magnitude;
		}

		GMAPI void gmuQuaternionInverse(float4& Quat)
		{
			Quat.w = Quat.w;
			Quat.x = -Quat.x;
			Quat.y = -Quat.y;
			Quat.z = -Quat.z;
		}

		GMAPI void gmuQuaternionPow(float4& Quat, float exponent)
		{
			// Quaternion should be normalized

			// Check for the case of identity quaterion
			if (fabs(Quat.w) < 0.9999f)
			{
				// Extract the half angle (alpha=theta/2)
				float alpha = acosf(Quat.w);

				// Compute new alpha value
				float newAlpha = alpha*exponent;

				// Compute new w value
				Quat.w = cosf(newAlpha);

				// Compute new xyz values
				Quat.xyz *= sinf(newAlpha) / sinf(alpha);
			}
		}

		GMAPI void gmuSphericalToQuaternion(float4& Quat, float latitude, float longitude, float angle)
		{
			float sin_a = sinf(angle / 2.0f);
			float cos_a = cosf(angle / 2.0f);

			float sin_lat = sinf(latitude);
			float cos_lat = cosf(latitude);

			float sin_long = sinf(longitude);
			float cos_long = cosf(longitude);

			Quat.x = sin_a * cos_lat * sin_long;
			Quat.y = sin_a * sin_lat;
			Quat.z = sin_a * sin_lat * cos_long;
			Quat.w = cos_a;
		}

		GMAPI void gmuYawPitchRollToQuaternion(float4& Quat, float Yaw, float Pitch, float Roll)
		{
			// Compute sine and cosine of the half angles
			float	scp[2], scr[2], scy[2];
			sincos(scp, Pitch*0.5f);
			sincos(scr, Roll*0.5f);
			sincos(scy, Yaw*0.5f);

			// Compute values	
			Quat.x = scy[1] * scp[0] * scr[1] + scy[0] * scp[1] * scr[0];
			Quat.y = -scy[1] * scp[0] * scr[0] + scy[0] * scp[1] * scr[1];
			Quat.z = -scy[0] * scp[0] * scr[1] + scy[1] * scp[1] * scr[0];
			Quat.w = scy[1] * scp[1] * scr[1] + scy[0] * scp[0] * scr[0];

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

		GMAPI void gmuMatrix3x3ToQuaternion(float4& Quat, const float3x3& RotMatrix)
		{
			float	tr, s, q[4];
			int		i, j, k;
			int		nxt[3] = { 1, 2, 0 };

			tr = RotMatrix._11 + RotMatrix._22 + RotMatrix._33;

			if (tr > 0.0f)
			{
				s = sqrtf(tr + 1.0f);
				Quat.w = s / 2.0f;
				s = 0.5f / s;
				Quat.x = (RotMatrix._23 - RotMatrix._32) * s;
				Quat.y = (RotMatrix._31 - RotMatrix._13) * s;
				Quat.z = (RotMatrix._12 - RotMatrix._21) * s;
			}
			else {
				i = 0;
				if (RotMatrix._22 > RotMatrix._11)		i = 1;
				if (RotMatrix._33 > RotMatrix.m[i * 3 + i]) i = 2;
				j = nxt[i];
				k = nxt[j];

				s = sqrtf((RotMatrix.m[i * 3 + i] - (RotMatrix.m[j * 3 + j] + RotMatrix.m[k * 3 + k])) + 1.0f);
				q[i] = s * 0.5f;

				if (s != 0.0f) s = 0.5f / s;

				q[3] = (RotMatrix.m[j * 3 + k] - RotMatrix.m[k * 3 + j]) * s;
				q[j] = (RotMatrix.m[i * 3 + j] + RotMatrix.m[j * 3 + i]) * s;
				q[k] = (RotMatrix.m[i * 3 + k] + RotMatrix.m[k * 3 + i]) * s;

				Quat.x = q[0];
				Quat.y = q[1];
				Quat.z = q[2];
				Quat.w = q[3];
			}
		}

		GMAPI void gmuMatrix4x4ToQuaternion(float4& Quat, const float4x4& RotMatrix)
		{
			float	tr, s, q[4];
			int		i, j, k;
			int		nxt[3] = { 1, 2, 0 };

			tr = RotMatrix._11 + RotMatrix._22 + RotMatrix._33;

			if (tr > 0.0f)
			{
				s = sqrtf(tr + 1.0f);
				Quat.w = s / 2.0f;
				s = 0.5f / s;
				Quat.x = (RotMatrix._23 - RotMatrix._32) * s;
				Quat.y = (RotMatrix._31 - RotMatrix._13) * s;
				Quat.z = (RotMatrix._12 - RotMatrix._21) * s;
			}
			else {
				i = 0;
				if (RotMatrix._22 > RotMatrix._11)		i = 1;
				if (RotMatrix._33 > RotMatrix.m[i * 4 + i]) i = 2;
				j = nxt[i];
				k = nxt[j];

				s = sqrtf((RotMatrix.m[i * 4 + i] - (RotMatrix.m[j * 4 + j] + RotMatrix.m[k * 4 + k])) + 1.0f);
				q[i] = s * 0.5f;

				if (s != 0.0f) s = 0.5f / s;

				q[3] = (RotMatrix.m[j * 4 + k] - RotMatrix.m[k * 4 + j]) * s;
				q[j] = (RotMatrix.m[i * 4 + j] + RotMatrix.m[j * 4 + i]) * s;
				q[k] = (RotMatrix.m[i * 4 + k] + RotMatrix.m[k * 4 + i]) * s;

				Quat.x = q[0];
				Quat.y = q[1];
				Quat.z = q[2];
				Quat.w = q[3];
			}
		}

		GMAPI void gmuShortestArcToQuaternion(float4& Quat, const float3& From, const float3& To)
		{
			float3	c;
			float	one_over_magnitude;

			cross3(c, From, To);
			Quat.x = c.x;
			Quat.y = c.y;
			Quat.z = c.z;
			Quat.w = dot3(From, To);

			one_over_magnitude = 1.0f / sqrtf((Quat.w*Quat.w) + (Quat.x*Quat.x) + (Quat.y*Quat.y) + (Quat.z*Quat.z));
			Quat.w *= one_over_magnitude;
			Quat.x *= one_over_magnitude;
			Quat.y *= one_over_magnitude;
			Quat.z *= one_over_magnitude;

			Quat.w += 1.0f;	// reducing angle to halfangle

			if (Quat.w <= QUAT_EPSILON)
			{
				// angle close to PI
				if ((From.z*From.z) > (From.x*From.x))
				{
					Quat.x = 0.0f;
					Quat.y = From.z;
					Quat.z = -From.y;
				}
				else {
					Quat.x = From.y;
					Quat.y = -From.x;
					Quat.z = 0;
				}
			}

			one_over_magnitude = 1.0f / sqrtf((Quat.w*Quat.w) + (Quat.x*Quat.x) + (Quat.y*Quat.y) + (Quat.z*Quat.z));
			Quat.w *= one_over_magnitude;
			Quat.x *= one_over_magnitude;
			Quat.y *= one_over_magnitude;
			Quat.z *= one_over_magnitude;
		}

		GMAPI void gmuQuaternionToMatrix3x3(float3x3& RotMatrix, const float4& Quat)
		{
			float xx = Quat.x*Quat.x, xy = Quat.x*Quat.y, xz = Quat.x*Quat.z, xw = Quat.x*Quat.w;
			float yy = Quat.y*Quat.y, yz = Quat.y*Quat.z, yw = Quat.y*Quat.w;
			float zz = Quat.z*Quat.z, zw = Quat.z*Quat.w;
			float ww = Quat.w*Quat.w;

			RotMatrix._11 = xx - yy - zz + ww;
			RotMatrix._12 = 2.0f*(xy - zw);
			RotMatrix._13 = 2.0f*(xz + yw);

			RotMatrix._21 = 2.0f*(xy + zw);
			RotMatrix._22 = -xx + yy - zz + ww;
			RotMatrix._23 = 2.0f*(yz - xw);

			RotMatrix._31 = 2.0f*(xz - yw);
			RotMatrix._32 = 2.0f*(yz + xw);
			RotMatrix._33 = -xx - yy + zz + ww;
		}

		GMAPI void gmuQuaternionToMatrix4x4(float4x4& RotMatrix, const float4& Quat)
		{
			float xx = Quat.x*Quat.x, xy = Quat.x*Quat.y, xz = Quat.x*Quat.z, xw = Quat.x*Quat.w;
			float yy = Quat.y*Quat.y, yz = Quat.y*Quat.z, yw = Quat.y*Quat.w;
			float zz = Quat.z*Quat.z, zw = Quat.z*Quat.w;
			float ww = Quat.w*Quat.w;

			RotMatrix._11 = xx - yy - zz + ww;
			RotMatrix._12 = 2.0f*(xy - zw);
			RotMatrix._13 = 2.0f*(xz + yw);

			RotMatrix._21 = 2.0f*(xy + zw);
			RotMatrix._22 = -xx + yy - zz + ww;
			RotMatrix._23 = 2.0f*(yz - xw);

			RotMatrix._31 = 2.0f*(xz - yw);
			RotMatrix._32 = 2.0f*(yz + xw);
			RotMatrix._33 = -xx - yy + zz + ww;

			RotMatrix._14 = RotMatrix._41 = 0.0f;
			RotMatrix._24 = RotMatrix._42 = 0.0f;
			RotMatrix._34 = RotMatrix._43 = 0.0f;
			RotMatrix._44 = xx + yy + zz + ww;
		}

		GMAPI void gmuQuaternionSlerp(float4& Out, const float4& Quat1, const float4& Quat2, float t)
		{
			float	p1[4];
			float	omega, cosom, sinom, scale0, scale1;

			// косинус угла
			cosom = Quat1.x*Quat2.x + Quat1.y*Quat2.y + Quat1.z*Quat2.z + Quat1.w*Quat2.w;

			if (cosom < 0.0f)
			{
				cosom = -cosom;
				p1[0] = -Quat2.x;  p1[1] = -Quat2.y;
				p1[2] = -Quat2.z;  p1[3] = -Quat2.w;
			}
			else {
				p1[0] = Quat2.x;  p1[1] = Quat2.y;
				p1[2] = Quat2.z;  p1[3] = Quat2.w;
			}

			if ((1.0f - cosom) > QUAT_EPSILON)
			{
				// стандартный случай (slerp)
				omega = acosf(cosom);
				sinom = sinf(omega);
				scale0 = sinf((1.0f - t) * omega) / sinom;
				scale1 = sinf(t * omega) / sinom;
			}
			else {
				// если маленький угол - линейная интерполяция
				scale0 = 1.0f - t;
				scale1 = t;
			}

			Out.x = scale0 * Quat1.x + scale1 * p1[0];
			Out.y = scale0 * Quat1.y + scale1 * p1[1];
			Out.z = scale0 * Quat1.z + scale1 * p1[2];
			Out.w = scale0 * Quat1.w + scale1 * p1[3];
		}

		GMAPI void gmuQuaternionRotate(float3& Out, const float3& In, const float4& Quat)
		{
#if 1
			float xxzz = Quat.x*Quat.x - Quat.z*Quat.z;
			float wwyy = Quat.w*Quat.w - Quat.y*Quat.y;

			float xw2 = Quat.x*Quat.w*2.0f;
			float xy2 = Quat.x*Quat.y*2.0f;
			float xz2 = Quat.x*Quat.z*2.0f;
			float yw2 = Quat.y*Quat.w*2.0f;
			float yz2 = Quat.y*Quat.z*2.0f;
			float zw2 = Quat.z*Quat.w*2.0f;

			Out.x = (xxzz + wwyy)*In.x + (xy2 + zw2)*In.y + (xz2 - yw2)*In.z;
			Out.y = -((xy2 - zw2)*In.x + (xxzz - wwyy)*In.y + (yz2 + xw2)*In.z);
			Out.z = (xz2 + yw2)*In.x + (yz2 - xw2)*In.y + (wwyy - xxzz)*In.z;
#else
			float3x3 rotMatrix;
			gmuQuaternionToMatrix3x3(rotMatrix, Quat);
			mul3(Out, In, rotMatrix);
#endif
		}
	}
}