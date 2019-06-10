#include "stdafx.h"

namespace OpenGm
{
	namespace Utilities
	{
		GMAPI float4 Vector4::HermiteInterpolate(const float4& v1, const float4& t1, const float4& v2, const float4& t2, float s)
		{
			float	u1 = 2.0f*(s*s*s) - 3.0f*(s*s) + 1;
			float	u2 = -2.0f*(s*s*s) + 3.0f*(s*s);
			float	u3 = (s*s*s) - 2.0f*(s*s) + s;
			float	u4 = (s*s*s) - (s*s);
			return (v1 * u1 + v2 * u2 + t1 * u3 + t2 * u4);
		}

		GMAPI float4 Vector4::CatmullRomInterpolate(const float4& v0, const float4& v1, const float4& v2, const float4& v3, float s)
		{
			float	u1 = -(s*s*s) + 2.0f*(s*s) - s;
			float	u2 = 3.0f*(s*s*s) - 5.0f*(s*s) + 2;
			float	u3 = -3.0f*(s*s*s) + 4.0f*(s*s) + s;
			float	u4 = (s*s*s) - (s*s);
			return (v0 * u1 + v1 * u2 + v2 * u3 + v3 * u4);
		}

		GMAPI float4 Vector4::BaryCentricInterpolate(const float4& v1, const float4& v2, const float4& v3, float f, float g)
		{
			return (v1 + (v2 - v1)*f + (v3 - v1)*g);
		}
	}
}