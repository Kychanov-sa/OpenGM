#include "stdafx.h"

namespace OpenGm
{
	namespace Utilities
	{
		GMAPI float4x4 ViewMatrix::MakeLookAtRH(const float3& eye, const float3& at, const float3& up)
		{
			float3 xAxis, yAxis, zAxis;

			// Normalize the z basis vector.
			zAxis = eye - at;
			normalize3(zAxis);	

			// Compute the orthogonal axes from the cross product of the gaze and the pup vector.
			cross3(xAxis, up, zAxis);
			normalize3(xAxis);
			cross3(yAxis, zAxis, xAxis);

			// Start building the matrix. The first three rows contain the 
			// basis vectors used to rotate the view to point at the look-at 
			// point. The fourth row contains the translation values. 
			// Rotations are still about the eyepoint.
			float4x4 result;
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

			result._14 = 0.0f;
			result._24 = 0.0f;
			result._34 = 0.0f;
			result._44 = 1.0f;
			return result;
		}

		GMAPI float4x4 ViewMatrix::MakeLookAtLH(const float3& eye, const float3& at, const float3& up)
		{
			float3 xAxis, yAxis, zAxis;

			// Get the z basis vector, which points straight ahead; the
			// difference from the eye point to the look-at point. This is the 
			// direction of the gaze (+z).
			zAxis = at - eye;

			// Normalize the z basis vector.
			normalize3(zAxis);

			// Compute the orthogonal axes from the cross product of the gaze 
			// and the pup vector.
			cross3(xAxis, up, zAxis);
			normalize3(xAxis);
			cross3(yAxis, zAxis, xAxis);

			// Start building the matrix. The first three rows contain the 
			// basis vectors used to rotate the view to point at the look-at 
			// point. The fourth row contains the translation values. 
			// Rotations are still about the eyepoint.
			float4x4 result;
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

			result._14 = 0.0f;
			result._24 = 0.0f;
			result._34 = 0.0f;
			result._44 = 1.0f;
			return result;
		}

		GMAPI float4x4 ViewMatrix::MakeReflection(const float4& plane)
		{
			float4	p = plane;

			normalize4(p);
			float4x4 result;
			result._11 = -2 * p.x*p.x + 1;	result._12 = -2 * p.y*p.x;	result._13 = -2 * p.z*p.x;	result._14 = 0;
			result._21 = -2 * p.x*p.y;	result._22 = -2 * p.y*p.y + 1;	result._23 = -2 * p.z*p.y;	result._24 = 0;
			result._31 = -2 * p.x*p.z;	result._32 = -2 * p.y*p.z;	result._33 = -2 * p.z*p.z + 1;	result._34 = 0;
			result._41 = -2 * p.x*p.w;	result._42 = -2 * p.y*p.w;	result._43 = -2 * p.z*p.w;	result._44 = 1;
			return result;
		}
	}
}