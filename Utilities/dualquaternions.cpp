#include "stdafx.h"

namespace OpenGm
{
	namespace Utilities
	{
		GMAPI void gmuTransformToUnitDualQuaternion(float2x4& dq, const float3& t, const float4& r)
		{
			// non-dual part (just copy rotation):
			dq._11_12_13_14 = r;

			// dual part:
			dq._21 = -0.5f*(+t.x*r.y + t.y*r.z + t.z*r.w);
			dq._22 = +0.5f*(+t.x*r.x + t.y*r.w - t.z*r.z);
			dq._23 = +0.5f*(-t.x*r.w + t.y*r.x + t.z*r.y);
			dq._24 = +0.5f*(+t.x*r.z - t.y*r.y + t.z*r.x);
		}

		GMAPI void gmuUnitDualQuaternionToTransform(float3& t, float4& r, const float2x4& dq)
		{
			// regular quaternion (just copy the non-dual part):
			r = dq._11_12_13_14;

			// translation vector:
			t.x = 2.0f*(-dq._21*dq._12 + dq._22*dq._11 - dq._23*dq._14 + dq._24*dq._13);
			t.y = 2.0f*(-dq._21*dq._13 + dq._22*dq._14 + dq._23*dq._11 - dq._24*dq._12);
			t.z = 2.0f*(-dq._21*dq._14 - dq._22*dq._13 + dq._23*dq._12 + dq._24*dq._11);
		}

		GMAPI void gmuDualQuaternionToTransform(float3& t, float4& r, const float2x4& dq)
		{
			float invlen;

			invlen = rsqrt(dot4(dq._11_12_13_14, dq._11_12_13_14));

			// rotation part
			r = dq._11_12_13_14 * invlen;

			// translation part
			t.x = 2.0f*(-dq._21*dq._12 + dq._22*dq._11 - dq._23*dq._14 + dq._24*dq._13);
			t.y = 2.0f*(-dq._21*dq._13 + dq._22*dq._14 + dq._23*dq._11 - dq._24*dq._12);
			t.z = 2.0f*(-dq._21*dq._14 - dq._22*dq._13 + dq._23*dq._12 + dq._24*dq._11);
			t *= invlen;
		}
		/*
		GMAPI void gmuDualQuaternionToMatrix4x4(float4x4& matrix, const float2x4& DualQuat)
		{
		float	len2 = dot4(DualQuat._11_12_13_14, DualQuat._21_22_23_24);
		float	w = Qn.x, x = Qn.y, y = Qn.z, z = Qn.w;
		float	t0 = Qd.x, t1 = Qd.y, t2 = Qd.z, t3 = Qd.w;

		matrix._11 = w*w + x*x - y*y - z*z; matrix._12 = 2*x*y - 2*w*z; matrix[1][3] = 2*x*z + 2*w*y;
		matrix._21 = 2*x*y + 2*w*z; matrix[2][2] = w*w + y*y - x*x - z*z; matrix[2][3] = 2*y*z - 2*w*x;
		matrix._31 = 2*x*z - 2*w*y; matrix[3][2] = 2*y*z + 2*w*x; matrix[3][3] = w*w + z*z - x*x - y*y;

		matrix._14 = -2*t0*x + 2*w*t1 - 2*t2*z + 2*y*t3;
		matrix._24 = -2*t0*y + 2*t1*z - 2*x*t3 + 2*w*t2;
		matrix._34 = -2*t0*z + 2*x*t2 + 2*w*t3 - 2*t1*y;

		matrix /= len2;

		return M;
		}*/
	}
}