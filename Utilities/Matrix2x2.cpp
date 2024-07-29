#include "stdafx.h"

namespace GlacialBytes
{
	namespace OpenGm
	{
		namespace Utilities
		{
			float2x2 Matrix2x2::Identity = float2x2(
				1.0f, 0.0f,
				0.0f, 1.0f);

			float2x2 Matrix2x2::MultiplyTranspose(const float2x2& m1, const float2x2& m2)
			{
				float2x2 temp = mul2x2(m1, m2);
				return float2x2(
					temp._11, temp._21,
					temp._12, temp._22);
			}

			float2x2 Matrix2x2::MakeUniformScale(float scale)
			{
				return float2x2(
					scale, 0.0f,
					0.0f, scale);
			}

			float2x2 Matrix2x2::MakeScale(float scaleX, float scaleY)
			{
				return float2x2(
					scaleX, 0.0f,
					0.0f, scaleY);
			}

			float2x2 Matrix2x2::MakeScale(const float2& scale)
			{
				return float2x2(
					scale.x, 0.0f,
					0.0f, scale.y);
			}

			float2x2 Matrix2x2::MakeTranslation(const float2& translate)
			{
				return float2x2(
					1.0f, 0.0f,
					translate.x, translate.y);
			}

			float2x2 Matrix2x2::MakeTranslation(const float translateX, const float translateY)
			{
				return float2x2(
					1.0f, 0.0f,
					translateX, translateY);
			}

			float2x2 Matrix2x2::MakeRotation(float angle)
			{
				float cosa = cosf(angle);
				float sina = sinf(angle);

				return float2x2(
					cosa, sina,
					-sina, cosa);
			}
		}
	}
}