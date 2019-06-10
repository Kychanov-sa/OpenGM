#include "stdafx.h"

namespace OpenGm
{
	namespace Utilities
	{
		
		GMAPI void gmuCompositeTransformation(float4x4& Out, float3& translation, float4& rotation)
		{
			float xx = rotation.x*rotation.x, xy = rotation.x*rotation.y, xz = rotation.x*rotation.z, xw = rotation.x*rotation.w;
			float yy = rotation.y*rotation.y, yz = rotation.y*rotation.z, yw = rotation.y*rotation.w;
			float zz = rotation.z*rotation.z, zw = rotation.z*rotation.w;
			float ww = rotation.w*rotation.w;

			Out._11 = xx - yy - zz + ww;
			Out._12 = 2.0f*(xy - zw);
			Out._13 = 2.0f*(xz + yw);
			Out._14 = 0.0f;

			Out._21 = 2.0f*(xy + zw);
			Out._22 = -xx + yy - zz + ww;
			Out._23 = 2.0f*(yz - xw);
			Out._24 = 0.0f;

			Out._31 = 2.0f*(xz - yw);
			Out._32 = 2.0f*(yz + xw);
			Out._33 = -xx - yy + zz + ww;
			Out._34 = 0.0f;

			Out._41 = translation.x;
			Out._42 = translation.y;
			Out._43 = translation.z;
			Out._44 = 1.0f;
		}

		GMAPI void gmuBuildShadow(float4x4& Out, const float4& light, const float4& plane)
		{
			float4	p = plane;
			float4	l = light;
			float	d = dot3(p.xyz, l.xyz);

			normalize4(p);
			Out._11 = p.x*l.x + d;	Out._12 = p.x*l.y;		Out._13 = p.x*l.z;		Out._14 = p.x*l.w;
			Out._21 = p.y*l.x;		Out._22 = p.y*l.y + d;	Out._23 = p.y*l.z;		Out._24 = p.y*l.w;
			Out._31 = p.z*l.x;		Out._32 = p.z*l.y;		Out._33 = p.z*l.z + d;	Out._34 = p.z*l.w;
			Out._41 = p.w*l.x;		Out._42 = p.w*l.y;		Out._43 = p.w*l.z;		Out._44 = p.w*l.w + d;
		}

		GMAPI void gmuBuildReflect(float4x4& Out, const float4& plane)
		{
			
		}
	}
}