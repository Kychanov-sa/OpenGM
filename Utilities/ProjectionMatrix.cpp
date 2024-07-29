#include "stdafx.h"

namespace GlacialBytes
{
	namespace OpenGm
	{
		namespace Utilities
		{
			float4x4 ProjectionMatrix::MakePerspectiveRH(float width, float height, float znear, float zfar)
			{
				float Q = zfar / (znear - zfar);

				float4x4 result;
				result._11 = 2.0f * znear / width;
				result._12 = 0.0f;
				result._13 = 0.0f;
				result._14 = 0.0f;

				result._21 = 0.0f;
				result._22 = 2.0f * znear / height;
				result._23 = 0.0f;
				result._24 = 0.0f;

				result._31 = 0.0f;
				result._32 = 0.0f;
				result._33 = Q;
				result._34 = -1.0f;

				result._41 = 0.0f;
				result._42 = 0.0f;
				result._43 = znear * Q;
				result._44 = 0.0f;
				return result;
			}

			float4x4 ProjectionMatrix::MakePerspectiveLH(float width, float height, float znear, float zfar)
			{
				float Q = zfar / (zfar - znear);

				float4x4 result;
				result._11 = 2.0f * znear / width;
				result._12 = 0.0f;
				result._13 = 0.0f;
				result._14 = 0.0f;

				result._21 = 0.0f;
				result._22 = 2.0f * znear / height;
				result._23 = 0.0f;
				result._24 = 0.0f;

				result._31 = 0.0f;
				result._32 = 0.0f;
				result._33 = Q;
				result._34 = 1.0f;

				result._41 = 0.0f;
				result._42 = 0.0f;
				result._43 = -znear * Q;
				result._44 = 0.0f;
				return result;
			}

			float4x4 ProjectionMatrix::MakePerspectiveFovRH(float fovY, float aspect, float znear, float zfar)
			{
				float    height, width, Q;

				height = cosf(fovY / 2.0f) / sinf(fovY / 2.0f);
				width = height / aspect;
				Q = zfar / (znear - zfar);

				float4x4 result;
				result._11 = 2.0f * znear / width;
				result._12 = 0.0f;
				result._13 = 0.0f;
				result._14 = 0.0f;

				result._21 = 0.0f;
				result._22 = 2.0f * znear / height;
				result._23 = 0.0f;
				result._24 = 0.0f;

				result._31 = 0.0f;
				result._32 = 0.0f;
				result._33 = Q;
				result._34 = -1.0f;

				result._41 = 0.0f;
				result._42 = 0.0f;
				result._43 = znear * Q;
				result._44 = 0.0f;
				return result;
			}

			float4x4 ProjectionMatrix::MakePerspectiveFovLH(float fovY, float aspect, float znear, float zfar)
			{
				float    height, width, Q;

				height = 1.0f / tanf(fovY * 0.5f);
				width = height / aspect;
				Q = zfar / (zfar - znear);

				float4x4 result;
				result._11 = width;
				result._12 = 0.0f;
				result._13 = 0.0f;
				result._14 = 0.0f;

				result._21 = 0.0f;
				result._22 = height;
				result._23 = 0.0f;
				result._24 = 0.0f;

				result._31 = 0.0f;
				result._32 = 0.0f;
				result._33 = Q;
				result._34 = 1.0f;

				result._41 = 0.0f;
				result._42 = 0.0f;
				result._43 = -znear * Q;
				result._44 = 0.0f;
				return result;
			}

			float4x4 ProjectionMatrix::MakePerspectiveOffCenterRH(float left, float right, float bottom, float top, float znear, float zfar)
			{
				float Q;

				Q = zfar / (znear - zfar);

				float4x4 result;
				result._11 = 2.0f * znear / (right - left);
				result._12 = 0.0f;
				result._13 = 0.0f;
				result._14 = 0.0f;

				result._21 = 0.0f;
				result._22 = 2.0f * znear / (top - bottom);
				result._23 = 0.0f;
				result._24 = 0.0f;

				result._31 = (left + right) / (right - left);
				result._32 = (top + bottom) / (top - bottom);
				result._33 = Q;
				result._34 = -1.0f;

				result._41 = 0.0f;
				result._42 = 0.0f;
				result._43 = znear * Q;
				result._44 = 0.0f;
				return result;
			}

			float4x4 ProjectionMatrix::MakePerspectiveOffCenterLH(float left, float right, float bottom, float top, float znear, float zfar)
			{
				float Q;

				Q = zfar / (zfar - znear);

				float4x4 result;
				result._11 = 2.0f * znear / (right - left);
				result._12 = 0.0f;
				result._13 = 0.0f;
				result._14 = 0.0f;

				result._21 = 0.0f;
				result._22 = 2.0f * znear / (top - bottom);
				result._23 = 0.0f;
				result._24 = 0.0f;

				result._31 = (left + right) / (left - right);
				result._32 = (top + bottom) / (bottom - top);
				result._33 = Q;
				result._34 = 1.0f;

				result._41 = 0.0f;
				result._42 = 0.0f;
				result._43 = -znear * Q;
				result._44 = 0.0f;
				return result;
			}

			float4x4 ProjectionMatrix::MakeOrthoRH(float width, float height, float znear, float zfar)
			{
				float Q;

				Q = 1.0f / (znear - zfar);

				float4x4 result;
				result._11 = 2.0f / width;
				result._12 = 0.0f;
				result._13 = 0.0f;
				result._14 = 0.0f;

				result._21 = 0.0f;
				result._22 = 2.0f / height;
				result._23 = 0.0f;
				result._24 = 0.0f;

				result._31 = 0.0f;
				result._32 = 0.0f;
				result._33 = Q;
				result._34 = 0.0f;

				result._41 = 0.0f;
				result._42 = 0.0f;
				result._43 = znear * Q;
				result._44 = 1.0f;
				return result;
			}

			float4x4 ProjectionMatrix::MakeOrthoLH(float width, float height, float znear, float zfar)
			{
				float Q;

				Q = 1.0f / (zfar - znear);

				float4x4 result;
				result._11 = 2.0f / width;
				result._12 = 0.0f;
				result._13 = 0.0f;
				result._14 = 0.0f;

				result._21 = 0.0f;
				result._22 = 2.0f / height;
				result._23 = 0.0f;
				result._24 = 0.0f;

				result._31 = 0.0f;
				result._32 = 0.0f;
				result._33 = Q;
				result._34 = 0.0f;

				result._41 = 0.0f;
				result._42 = 0.0f;
				result._43 = -znear * Q;
				result._44 = 1.0f;
				return result;
			}

			float4x4 ProjectionMatrix::MakeOrthoOffCenterRH(float left, float right, float bottom, float top, float znear, float zfar)
			{
				float Q;

				Q = 1.0f / (znear - zfar);

				float4x4 result;
				result._11 = 2.0f / (right - left);
				result._12 = 0.0f;
				result._13 = 0.0f;
				result._14 = 0.0f;

				result._21 = 0.0f;
				result._22 = 2.0f / (top - bottom);
				result._23 = 0.0f;
				result._24 = 0.0f;

				result._31 = 0.0f;
				result._32 = 0.0f;
				result._33 = Q;
				result._34 = 0.0f;

				result._41 = (left + right) / (left - right);
				result._42 = (top + bottom) / (top - bottom);
				result._43 = znear * Q;
				result._44 = 1.0f;
				return result;
			}

			float4x4 ProjectionMatrix::MakeOrthoOffCenterLH(float left, float right, float bottom, float top, float znear, float zfar)
			{
				float Q;

				Q = 1.0f / (zfar - znear);

				float4x4 result;
				result._11 = 2.0f / (right - left);
				result._12 = 0.0f;
				result._13 = 0.0f;
				result._14 = 0.0f;

				result._21 = 0.0f;
				result._22 = 2.0f / (top - bottom);
				result._23 = 0.0f;
				result._24 = 0.0f;

				result._31 = 0.0f;
				result._32 = 0.0f;
				result._33 = Q;
				result._34 = 0.0f;

				result._41 = (left + right) / (left - right);
				result._42 = (top + bottom) / (top - bottom);
				result._43 = -znear * Q;
				result._44 = 1.0f;
				return result;
			}
		}
	}
}