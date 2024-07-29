#include "stdafx.h"

namespace GlacialBytes
{
	namespace OpenGm
	{
		namespace Utilities
		{
			float2x4 DualQuaternion::FromTransformation(const float3& translation, const float4& rotation)
			{
				float2x4 dualQuat;

				// non-dual part (just copy rotation):
				dualQuat._11_12_13_14 = rotation;

				// dual part:
				dualQuat._21 = -0.5f * (+translation.x * rotation.y + translation.y * rotation.z + translation.z * rotation.w);
				dualQuat._22 = +0.5f * (+translation.x * rotation.x + translation.y * rotation.w - translation.z * rotation.z);
				dualQuat._23 = +0.5f * (-translation.x * rotation.w + translation.y * rotation.x + translation.z * rotation.y);
				dualQuat._24 = +0.5f * (+translation.x * rotation.z - translation.y * rotation.y + translation.z * rotation.x);
			}

			float4 DualQuaternion::GetRotation(const float2x4& dualQuat)
			{
				return dualQuat._11_12_13_14;
			}

			float3 DualQuaternion::GetTranslation(const float2x4& dualQuat)
			{
				float3 translation;
				translation.x = 2.0f * (-dualQuat._21 * dualQuat._12 + dualQuat._22 * dualQuat._11 - dualQuat._23 * dualQuat._14 + dualQuat._24 * dualQuat._13);
				translation.y = 2.0f * (-dualQuat._21 * dualQuat._13 + dualQuat._22 * dualQuat._14 + dualQuat._23 * dualQuat._11 - dualQuat._24 * dualQuat._12);
				translation.z = 2.0f * (-dualQuat._21 * dualQuat._14 - dualQuat._22 * dualQuat._13 + dualQuat._23 * dualQuat._12 + dualQuat._24 * dualQuat._11);
				return translation;
			}
		}
	}
}