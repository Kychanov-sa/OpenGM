/// <summary>
/// OpenGM Utilities library header.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>14-06-2005</created>
/// <copyright>Copyright 2005-2018 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifndef GMU_H
#define GMU_H

#include <gm\gm.h>

namespace OpenGm
{
#ifdef GMAPI
#undef GMAPI
#endif
	namespace Utilities
	{
#ifdef GM_BUILDING_LIB
#define GMAPI
#else
#define GMAPI extern
#endif

#pragma region Vectors
		/// <summary>
		/// Minimize each component.
		/// </summary>
		/// <remarks>x = min(x1, x2), y = min(y1, y2), ... </remarks>
		GMAPI void gmuMinimize2(float2& Out, const float2& v1, const float2& v2);

		/// <summary>
		/// Minimize each component.
		/// </summary>
		/// <remarks>x = min(x1, x2), y = min(y1, y2), ... </remarks>
		GMAPI void gmuMinimize3(float3& Out, const float3& v1, const float3& v2);

		/// <summary>
		/// Minimize each component.
		/// </summary>
		/// <remarks>x = min(x1, x2), y = min(y1, y2), ... </remarks>
		GMAPI void gmuMinimize4(float4& Out, const float4& v1, const float4& v2);

		/// <summary>
		/// Maximize each component.
		/// </summary>
		/// <remarks>x = max(x1, x2), y = max(y1, y2), ...</remarks>
		GMAPI void gmuMaximize2(float2& Out, const float2& v1, const float2& v2);

		/// <summary>
		/// Maximize each component.
		/// </summary>
		/// <remarks>x = max(x1, x2), y = max(y1, y2), ...</remarks>
		GMAPI void gmuMaximize3(float3& Out, const float3& v1, const float3& v2);

		/// <summary>
		/// Maximize each component.
		/// </summary>
		/// <remarks>x = max(x1, x2), y = max(y1, y2), ...</remarks>
		GMAPI void gmuMaximize4(float4& Out, const float4& v1, const float4& v2);

		/// <summary>
		/// Hermite interpolation between position V1, tangent T1 (when s == 0) and position V2, tangent T2 (when s == 1).
		/// </summary>
		GMAPI void gmuHermite2(float2& Out, const float2& v1, const float2& t1, const float2& v2, const float2& t2, float s);

		/// <summary>
		/// Hermite interpolation between position V1, tangent T1 (when s == 0) and position V2, tangent T2 (when s == 1).
		/// </summary>
		GMAPI void gmuHermite3(float3& Out, const float3& v1, const float3& t1, const float3& v2, const float3& t2, float s);

		/// <summary>
		/// Hermite interpolation between position V1, tangent T1 (when s == 0) and position V2, tangent T2 (when s == 1).
		/// </summary>
		GMAPI void gmuHermite4(float4& Out, const float4& v1, const float4& t1, const float4& v2, const float4& t2, float s);

		/// <summary>
		/// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1).
		/// </summary>
		GMAPI void gmuCatmullRom2(float2& Out, const float2& v0, const float2& v1, const float2& v2, const float2& v3, float s);

		/// <summary>
		/// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1).
		/// </summary>
		GMAPI void gmuCatmullRom3(float3& Out, const float3& v0, const float3& v1, const float3& v2, const float3& v3, float s);

		/// <summary>
		/// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1).
		/// </summary>
		GMAPI void gmuCatmullRom4(float4& Out, const float4& v0, const float4& v1, const float4& v2, const float4& v3, float s);

		/// <summary>
		/// Barycentric coordinates.
		/// </summary>
		/// <remarks>V1 + f(V2-V1) + g(V3-V1)</remarks>
		GMAPI void gmuBaryCentric2(float2& Out, const float2& v1, const float2& v2, const float2& v3, float f, float g);

		/// <summary>
		/// Barycentric coordinates.
		/// </summary>
		/// <remarks>V1 + f(V2-V1) + g(V3-V1)</remarks>
		GMAPI void gmuBaryCentric3(float3& Out, const float3& v1, const float3& v2, const float3& v3, float f, float g);

		/// <summary>
		/// Barycentric coordinates.
		/// </summary>
		/// <remarks>V1 + f(V2-V1) + g(V3-V1)</remarks>
		GMAPI void gmuBaryCentric4(float4& Out, const float4& v1, const float4& v2, const float4& v3, float f, float g);
#pragma endregion

#pragma region Matrices
		// Identity matrix
		GMAPI void gmuIdentity2x2(float2x2& m);
		GMAPI void gmuIdentity3x3(float3x3& m);
		GMAPI void gmuIdentity4x4(float4x4& m);

		// Matrix multiplication, followed by a transpose. (Out = T(M1 * M2))
		GMAPI void gmuMultiplyTranspose2x2(float2x2& Out, const float2x2& m1, const float2x2& m2);
		GMAPI void gmuMultiplyTranspose3x3(float3x3& Out, const float3x3& m1, const float3x3& m2);
		GMAPI void gmuMultiplyTranspose4x4(float4x4& Out, const float4x4& m1, const float4x4& m2);

		// Calculate inverse of matrix.
		GMAPI void gmuInverse2x2(float2x2& m);
		GMAPI void gmuInverse3x3(float3x3& m);
		GMAPI void gmuInverse4x4(float4x4& m);

		// Calculate transposed matrix.
		GMAPI void gmuTranspose2x2(float2x2& Out, const float2x2& m);
		GMAPI void gmuTranspose3x3(float3x3& Out, const float3x3& m);
		GMAPI void gmuTranspose4x4(float4x4& Out, const float4x4& m);

		// Build a matrix which scales by (sx, sy, sz)
		GMAPI void gmuBuildScale2x2(float2x2& Out, float sx, float sy);
		GMAPI void gmuBuildScale2x2v(float2x2& Out, float2& scale);
		GMAPI void gmuBuildScale3x3(float3x3& Out, float sx, float sy, float sz);
		GMAPI void gmuBuildScale3x3v(float3x3& Out, float3& scale);
		GMAPI void gmuBuildScale4x4(float4x4& Out, float sx, float sy, float sz);
		GMAPI void gmuBuildScale4x4v(float4x4& Out, float3& scale);

		// Build a matrix which translates by (x, y, z)
		GMAPI void gmuBuildTranslation2x2(float2x2& Out, float tx, float ty);
		GMAPI void gmuBuildTranslation2x2v(float2x2& Out, float2& translation);
		GMAPI void gmuBuildTranslation3x3(float3x3& Out, float tx, float ty, float tz);
		GMAPI void gmuBuildTranslation3x3v(float3x3& Out, float3& translation);
		GMAPI void gmuBuildTranslation4x4(float4x4& Out, float tx, float ty, float tz);
		GMAPI void gmuBuildTranslation4x4v(float4x4& Out, float3& translation);

		// Build a matrix which rotates around the X,Y,Z axis
		GMAPI void gmuBuildRotationX3x3(float3x3& Out, float angle);
		GMAPI void gmuBuildRotationX4x4(float4x4& Out, float angle);
		GMAPI void gmuBuildRotationY3x3(float3x3& Out, float angle);
		GMAPI void gmuBuildRotationY4x4(float4x4& Out, float angle);
		GMAPI void gmuBuildRotationZ2x2(float2x2& Out, float angle);
		GMAPI void gmuBuildRotationZ3x3(float3x3& Out, float angle);
		GMAPI void gmuBuildRotationZ4x4(float4x4& Out, float angle);

		// Build a matrix which rotates around an arbitrary axis
		GMAPI void gmuBuildRotationAxis3x3(float3x3& Out, const float3& Axis, float Angle);
		GMAPI void gmuBuildRotationAxis4x4(float4x4& Out, const float3& Axis, float Angle);

		// Yaw around the Y axis, a pitch around the X axis,
		// and a roll around the Z axis.
		GMAPI void gmuBuildRotationYawPitchRoll4x4(float4x4& Out, float Yaw, float Pitch, float Roll);	// NYI
		GMAPI void gmuBuildRotationYawPitchRoll4x4v(float4x4& Out, float3& angles);						// NYI

																										// Build a lookat matrix. (right-handed/left-handed)
		GMAPI void gmuBuildLookAtRH4x4(float4x4& Out, const float3& Eye, const float3& At, const float3& Up);
		GMAPI void gmuBuildLookAtLH4x4(float4x4& Out, const float3& Eye, const float3& At, const float3& Up);

		// Build a perspective projection matrix. (right-handed/left-handed)
		GMAPI void gmuBuildPerspectiveRH4x4(float4x4& Out, float w, float h, float zn, float zf);
		GMAPI void gmuBuildPerspectiveLH4x4(float4x4& Out, float w, float h, float zn, float zf);
		GMAPI void gmuBuildPerspectiveFovRH4x4(float4x4& Out, float fovY, float aspect, float zn, float zf);
		GMAPI void gmuBuildPerspectiveFovLH4x4(float4x4& Out, float fovY, float aspect, float zn, float zf);
		GMAPI void gmuBuildPerspectiveOffCenterRH4x4(float4x4& Out, float l, float r, float b, float t, float zn, float zf);
		GMAPI void gmuBuildPerspectiveOffCenterLH4x4(float4x4& Out, float l, float r, float b, float t, float zn, float zf);
		GMAPI void gmuBuildOrthoRH4x4(float4x4& Out, float w, float h, float zn, float zf);
		GMAPI void gmuBuildOrthoLH4x4(float4x4& Out, float w, float h, float zn, float zf);
		GMAPI void gmuBuildOrthoOffCenterRH4x4(float4x4& Out, float l, float r, float b, float t, float zn, float zf);
		GMAPI void gmuBuildOrthoOffCenterLH4x4(float4x4& Out, float l, float r, float b, float t, float zn, float zf);

		GMAPI void gmuCompositeTransformation(float4x4& Out, float3& translation, float4& rotation);

		// Build a matrix which flattens geometry into a plane, as if casting
		// a shadow from a light.
		// If the light's w-component is 0, the ray from the origin to the light represents a directional light.
		// If it is 1, the light is a point light.
		GMAPI void gmuBuildShadow(float4x4& Out, const float4& light, const float4& plane);

		// Build a matrix which reflects the coordinate system about a plane
		GMAPI void gmuBuildReflect(float4x4& Out, const float4& plane);

		// Transform
		GMAPI void gmuDeviate(float3& Out, const float3& Axis, float deviation);	// 0.5f corresponds to 180 degrees deviation
#pragma endregion

#pragma region Quaternions
		GMAPI void gmuQuaternionMultiply(float4& Out, const float4& Quat1, const float4& Quat2);
		GMAPI float gmuQuaternionLength(const float4& Quat);
		GMAPI void gmuQuaternionNormalize(float4& Quat);
		GMAPI void gmuQuaternionInverse(float4& Quat);
		GMAPI void gmuQuaternionPow(float4& Quat, float exponent);
		GMAPI void gmuQuaternionSlerp(float4& Out, const float4& Quat1, const float4& Quat2, float t);
		GMAPI void gmuQuaternionRotate(float3& Out, const float3& In, const float4& Quat);

		GMAPI void gmuSphericalToQuaternion(float4& Quat, float latitude, float longitude, float angle);
		GMAPI void gmuYawPitchRollToQuaternion(float4& Quat, float Yaw, float Pitch, float Roll);
		GMAPI void gmuMatrix3x3ToQuaternion(float4& Quat, const float3x3& RotMatrix);
		GMAPI void gmuMatrix4x4ToQuaternion(float4& Quat, const float4x4& RotMatrix);
		GMAPI void gmuShortestArcToQuaternion(float4& Quat, const float3& From, const float3& To);
		GMAPI void gmuQuaternionToMatrix3x3(float3x3& RotMatrix, const float4& Quat);
		GMAPI void gmuQuaternionToMatrix4x4(float4x4& RotMatrix, const float4& Quat);
#pragma endregion

#pragma region Dual-Quaternions
		GMAPI void gmuTransformToUnitDualQuaternion(float2x4& dq, const float3& t, const float4& r);
		GMAPI void gmuUnitDualQuaternionToTransform(float3& t, float4& r, const float2x4& dq);
		GMAPI void gmuDualQuaternionToTransform(float3& t, float4& r, const float2x4& dq);
		GMAPI void gmuDualQuaternionToMatrix4x4(float4x4& matrix, const float2x4& DualQuat);
#pragma endregion

#pragma region Transforms
		// sets xform to an identity matrix (clears it)
		GMAPI void gmuXFormSetIdentity(xform3d& xform);

		GMAPI void gmuMatrix4x4ToXForm(xform3d& xform, const float4x4& Matrix);
		GMAPI void gmuXFormToMatrix4x4(float4x4& Matrix, const xform3d& xform);

		GMAPI void gmuXFormBuildLookAtRH(xform3d& Out, const float3& Eye, const float3& At, const float3& Up);
		GMAPI void gmuXFormBuildLookAtLH(xform3d& Out, const float3& Eye, const float3& At, const float3& Up);
#pragma endregion

#pragma region Noise
		GMAPI void	gmuRandNoise(int seed);

		GMAPI float gmuNoise1(const float s);
		GMAPI float gmuNoise2(const float2& v);
		GMAPI float gmuNoise3(const float3& v);

		GMAPI float gmuTurbulence2(const float2& v, float freq);
		GMAPI float gmuTurbulence3(const float3& v, float freq);

		GMAPI float gmuTileableNoise1(const float s, float w);
		GMAPI float gmuTileableNoise2(const float2& v, float w, float h);
		GMAPI float gmuTileableNoise3(const float3& v, float w, float h, float d);

		GMAPI float gmuTileableTurbulence2(const float2& v, float w, float h, float freq);
		GMAPI float gmuTileableTurbulence3(const float3& v, float w, float h, float d, float freq);
#pragma endregion
	}
}

#endif