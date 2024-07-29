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

namespace GlacialBytes
{
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
			/// 2D vectors utility functions.
			/// </summary>
			class Vector2
			{
			public:
				const float2 Up = float2(0.0f, 1.0f);
				const float2 Left = float2(-1.0f, 0.0f);
				const float2 Right = float2(1.0f, 0.0f);
				const float2 Down = float2(0.0f, -1.0f);

				/// <summary>
				/// Minimize each component.
				/// </summary>
				/// <remarks>x = min(x1, x2), y = min(y1, y2), ... </remarks>
				__forceinline static float2 Min(const float2& v1, const float2& v2)
				{
					return float2(v1.x < v2.x ? v1.x : v2.x, v1.y < v2.y ? v1.y : v2.y);
				}

				/// <summary>
				/// Maximize each component.
				/// </summary>
				/// <remarks>x = max(x1, x2), y = max(y1, y2), ...</remarks>
				__forceinline static float2 Max(const float2& v1, const float2& v2)
				{
					return float2(v1.x > v2.x ? v1.x : v2.x, v1.y > v2.y ? v1.y : v2.y);
				}

				/// <summary>
				/// Hermite interpolation between position V1, tangent T1 (when s == 0) and position V2, tangent T2 (when s == 1).
				/// </summary>
				/// <param name="v1"></param>
				/// <param name="t1"></param>
				/// <param name="v2"></param>
				/// <param name="t2"></param>
				/// <param name="s"></param>
				/// <returns>Интерполированное значение вектора.</returns>
				static float2 HermiteInterpolate(const float2& v1, const float2& t1, const float2& v2, const float2& t2, float s);

				/// <summary>
				/// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1).
				/// </summary>
				/// <param name="v0"></param>
				/// <param name="v1"></param>
				/// <param name="v2"></param>
				/// <param name="v3"></param>
				/// <param name="s"></param>
				/// <returns>Интерполированное значение вектора.</returns>
				static float2 CatmullRomInterpolate(const float2& v0, const float2& v1, const float2& v2, const float2& v3, float s);

				/// <summary>
				/// Barycentric interpolation.
				/// </summary>
				/// <param name="v1"></param>
				/// <param name="v2"></param>
				/// <param name="v3"></param>
				/// <param name="f"></param>
				/// <param name="g"></param>
				/// <returns>Интерполированное значение вектора.</returns>
				/// <remarks>V1 + f(V2-V1) + g(V3-V1)</remarks>
				static float2 BaryCentricInterpolate(const float2& v1, const float2& v2, const float2& v3, float f, float g);
			};

			/// <summary>
			/// 3D vectors utility functions.
			/// </summary>
			class Vector3
			{
			public:
				const float3 Up = float3(0.0f, 1.0f, 0.0f);
				const float3 Down = float3(0.0f, -1.0f, 0.0f);
				const float3 Left = float3(-1.0f, 0.0f, 0.0f);
				const float3 Right = float3(1.0f, 0.0f, 0.0f);
				const float3 Front = float3(0.0f, 0.0f, 1.0f);
				const float3 Back = float3(0.0f, 0.0f, -1.0f);

				/// <summary>
				/// Minimize each component.
				/// </summary>
				/// <remarks>x = min(x1, x2), y = min(y1, y2), ... </remarks>
				__forceinline static float3 Min(const float3& v1, const float3& v2)
				{
					return float3(
						v1.x < v2.x ? v1.x : v2.x,
						v1.y < v2.y ? v1.y : v2.y,
						v1.z < v2.z ? v1.z : v2.z);
				}

				/// <summary>
				/// Maximize each component.
				/// </summary>
				/// <remarks>x = max(x1, x2), y = max(y1, y2), ...</remarks>
				__forceinline static float3 Max(const float3& v1, const float3& v2)
				{
					return float3(
						v1.x > v2.x ? v1.x : v2.x,
						v1.y > v2.y ? v1.y : v2.y,
						v1.z > v2.z ? v1.z : v2.z);
				}

				/// <summary>
				/// Hermite interpolation between position V1, tangent T1 (when s == 0) and position V2, tangent T2 (when s == 1).
				/// </summary>
				static float3 HermiteInterpolate(const float3& v1, const float3& t1, const float3& v2, const float3& t2, float s);

				/// <summary>
				/// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1).
				/// </summary>
				static float3 CatmullRomInterpolate(const float3& v0, const float3& v1, const float3& v2, const float3& v3, float s);

				/// <summary>
				/// Barycentric interpolation.
				/// </summary>
				/// <remarks>V1 + f(V2-V1) + g(V3-V1)</remarks>
				static float3 BaryCentricInterpolate(const float3& v1, const float3& v2, const float3& v3, float f, float g);

				/// <summary>
				/// Отклоняет вектор оси на указанное значение в случайную сторону.
				/// </summary>
				/// <param name="Axis">Отклоняемый вектор оси.</param>
				/// <param name="deviation">Значение отклонения.</param>
				/// <returns>Отклонённая ось.</returns>
				/// <remarks>0.5f corresponds to 180 degrees deviation</remarks>
				static float3 Deviate(const float3& Axis, float deviation);
			};

			/// <summary>
			/// 3D vectors utility functions.
			/// </summary>
			class Vector4
			{
			public:
				const float4 Up = float4(0.0f, 1.0f, 0.0f, 0.0f);
				const float4 Down = float4(0.0f, -1.0f, 0.0f, 0.0f);
				const float4 Left = float4(-1.0f, 0.0f, 0.0f, 0.0f);
				const float4 Right = float4(1.0f, 0.0f, 0.0f, 0.0f);
				const float4 Front = float4(0.0f, 0.0f, 1.0f, 0.0f);
				const float4 Back = float4(0.0f, 0.0f, -1.0f, 0.0f);
				const float4 Future = float4(0.0f, 0.0f, 0.0f, 1.0f);
				const float4 Past = float4(0.0f, 0.0f, 0.0f, -1.0f);

				/// <summary>
				/// Minimize each component.
				/// </summary>
				/// <remarks>x = min(x1, x2), y = min(y1, y2), ... </remarks>
				__forceinline static float4 Min(const float4& v1, const float4& v2)
				{
					return float4(
						v1.x < v2.x ? v1.x : v2.x,
						v1.y < v2.y ? v1.y : v2.y,
						v1.z < v2.z ? v1.z : v2.z,
						v1.w < v2.w ? v1.w : v2.w);
				}

				/// <summary>
				/// Maximize each component.
				/// </summary>
				/// <remarks>x = max(x1, x2), y = max(y1, y2), ...</remarks>
				__forceinline static float4 Max(const float4& v1, const float4& v2)
				{
					return float4(
						v1.x > v2.x ? v1.x : v2.x,
						v1.y > v2.y ? v1.y : v2.y,
						v1.z > v2.z ? v1.z : v2.z,
						v1.w > v2.w ? v1.w : v2.w);
				}

				/// <summary>
				/// Hermite interpolation between position V1, tangent T1 (when s == 0) and position V2, tangent T2 (when s == 1).
				/// </summary>
				static float4 HermiteInterpolate(const float4& v1, const float4& t1, const float4& v2, const float4& t2, float s);

				/// <summary>
				/// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1).
				/// </summary>
				static float4 CatmullRomInterpolate(const float4& v0, const float4& v1, const float4& v2, const float4& v3, float s);

				/// <summary>
				/// Barycentric interpolation.
				/// </summary>
				/// <remarks>V1 + f(V2-V1) + g(V3-V1)</remarks>
				static float4 BaryCentricInterpolate(const float4& v1, const float4& v2, const float4& v3, float f, float g);
			};
#pragma endregion

#pragma region Matrices

			/// <summary>
			/// Matrix 2x2 utility functions.
			/// </summary>
			class Matrix2x2
			{
			public:
				/// <summary>
				/// Identity matrix.
				/// </summary>
				static float2x2 Identity;

				/// <summary>
				/// Matrix multiplication, followed by a transpose.
				/// </summary>
				/// <param name="m1"></param>
				/// <param name="m2"></param>
				/// <returns>Result = T(m1 * m2)</returns>
				static float2x2 MultiplyTranspose(const float2x2& m1, const float2x2& m2);

				/// <summary>
				/// Build a matrix which scales by (scale, scale)
				/// </summary>
				/// <param name="scale"></param>
				/// <returns></returns>
				static float2x2 MakeUniformScale(float scale);

				/// <summary>
				/// Build a matrix which scales by (scaleX, scaleY)
				/// </summary>
				/// <param name="scaleX"></param>
				/// <param name="scaleY"></param>
				/// <returns></returns>
				static float2x2 MakeScale(float scaleX, float scaleY);

				/// <summary>
				/// Build a matrix which scales by (scale.x, scale.y)
				/// </summary>
				/// <param name="scale"></param>
				/// <returns></returns>
				static float2x2 MakeScale(const float2& scale);

				/// <summary>
				/// Build a matrix which translates by (translate.x, translate.y)
				/// </summary>
				/// <param name="translate"></param>
				/// <returns></returns>
				static float2x2 MakeTranslation(const float2& translate);

				/// <summary>
				/// Build a matrix which translates by (translateX, translateY)
				/// </summary>
				/// <param name="translateX"></param>
				/// <param name="translateY"></param>
				/// <returns></returns>
				static float2x2 MakeTranslation(float translateX, float translateY);

				/// <summary>
				/// Build a matrix which rotates
				/// </summary>
				/// <param name="angle"></param>
				/// <returns></returns>
				static float2x2 MakeRotation(float angle);
			};

			/// <summary>
			/// Matrix 3x3 utility functions.
			/// </summary>
			class Matrix3x3
			{
			public:
				/// <summary>
				/// Identity matrix.
				/// </summary>
				static float3x3 Identity;

				/// <summary>
				/// Matrix multiplication, followed by a transpose.
				/// </summary>
				/// <param name="m1"></param>
				/// <param name="m2"></param>
				/// <returns>Result = T(m1 * m2)</returns>
				static float3x3 MultiplyTranspose(const float3x3& m1, const float3x3& m2);

				/// <summary>
				/// Build a matrix which scales by (scale, scale, scale)
				/// </summary>
				/// <param name="scale"></param>
				/// <returns></returns>
				static float3x3 MakeUniformScale(float scale);

				/// <summary>
				/// Build a matrix which scales by (scaleX, scaleY, scaleZ)
				/// </summary>
				/// <param name="scaleX"></param>
				/// <param name="scaleY"></param>
				/// <param name="scaleZ"></param>
				/// <returns></returns>
				static float3x3 MakeScale(float scaleX, float scaleY, float scaleZ);

				/// <summary>
				/// Build a matrix which scales by (scale.x, scale.y, scale.z)
				/// </summary>
				/// <param name="scale"></param>
				/// <returns></returns>
				static float3x3 MakeScale(const float3& scale);

				/// <summary>
				/// Build a matrix which translates by (translate.x, translate.y, translate.z)
				/// </summary>
				/// <param name="translate"></param>
				/// <returns></returns>
				static float3x3 MakeTranslation(const float3& translate);

				/// <summary>
				/// Build a matrix which translates by (translateX, translateY, translateZ)
				/// </summary>
				/// <param name="translateX"></param>
				/// <param name="translateY"></param>
				/// <param name="translateZ"></param>
				/// <returns></returns>
				static float3x3 MakeTranslation(float translateX, float translateY, float translateZ);

				/// <summary>
				/// Build a matrix which rotates around the X axis
				/// </summary>
				/// <param name="angle"></param>
				/// <returns></returns>
				static float3x3 MakeXRotation(float angle);

				/// <summary>
				/// Build a matrix which rotates around the Y axis
				/// </summary>
				/// <param name="angle"></param>
				/// <returns></returns>
				static float3x3 MakeYRotation(float angle);

				/// <summary>
				/// Build a matrix which rotates around the Z axis
				/// </summary>
				/// <param name="angle"></param>
				/// <returns></returns>
				static float3x3 MakeZRotation(float angle);

				/// <summary>
				/// Build a matrix which rotates around an arbitrary axis
				/// </summary>
				/// <param name="axis"></param>
				/// <param name="angle"></param>
				/// <returns></returns>
				static float3x3 MakeRotationAroundAxis(const float3& axis, float angle);

				/// <summary>
				/// Build a matrix which rotates around basic axis
				/// </summary>
				/// <param name="yaw"></param>
				/// <param name="pitch"></param>
				/// <param name="roll"></param>
				/// <returns></returns>
				/// <remarks>Yaw around the Y axis, a pitch around the X axis and a roll around the Z axis.</remarks>
				static float3x3 MakeRotation(float yaw, float pitch, float roll);

				/// <summary>
				/// Build a matrix which rotates around basic axis
				/// </summary>
				/// <param name="angles"></param>
				/// <returns></returns>
				/// <remarks>Yaw around the Y axis, a pitch around the X axis and a roll around the Z axis.</remarks>
				static float3x3 MakeRotation(const float3& angles);
			};

			/// <summary>
			/// Matrix 4x4 utility functions.
			/// </summary>
			class Matrix4x4
			{
			public:
				/// <summary>
				/// Identity matrix.
				/// </summary>
				static float4x4 Identity;

				/// <summary>
				/// Matrix multiplication, followed by a transpose.
				/// </summary>
				/// <param name="m1"></param>
				/// <param name="m2"></param>
				/// <returns>Result = T(m1 * m2)</returns>
				static float4x4 MultiplyTranspose(const float4x4& m1, const float4x4& m2);

				/// <summary>
				/// Build a matrix which scales by (scale, scale, scale, 1.0f)
				/// </summary>
				/// <param name="scale"></param>
				/// <returns></returns>
				static float4x4 MakeUniformScale(float scale);

				/// <summary>
				/// Build a matrix which scales by (scaleX, scaleY, scaleZ, 1.0f)
				/// </summary>
				/// <param name="scaleX"></param>
				/// <param name="scaleY"></param>
				/// <param name="scaleZ"></param>
				/// <returns></returns>
				static float4x4 MakeScale(float scaleX, float scaleY, float scaleZ);

				/// <summary>
				/// Build a matrix which scales by (scale.x, scale.y, scale.z, 1.0f)
				/// </summary>
				/// <param name="scale"></param>
				/// <returns></returns>
				static float4x4 MakeScale(const float3& scale);

				/// <summary>
				/// Build a matrix which translates by (translate.x, translate.y, translate.z)
				/// </summary>
				/// <param name="translate"></param>
				/// <returns></returns>
				static float4x4 MakeTranslation(const float3& translate);

				/// <summary>
				/// Build a matrix which translates by (translateX, translateY, translateZ)
				/// </summary>
				/// <param name="translateX"></param>
				/// <param name="translateY"></param>
				/// <param name="translateZ"></param>
				/// <returns></returns>
				static float4x4 MakeTranslation(float translateX, float translateY, float translateZ);

				/// <summary>
				/// Build a matrix which rotates around the X axis
				/// </summary>
				/// <param name="angle"></param>
				/// <returns></returns>
				static float4x4 MakeXRotation(float angle);

				/// <summary>
				/// Build a matrix which rotates around the Y axis
				/// </summary>
				/// <param name="angle"></param>
				/// <returns></returns>
				static float4x4 MakeYRotation(float angle);

				/// <summary>
				/// Build a matrix which rotates around the Z axis
				/// </summary>
				/// <param name="angle"></param>
				/// <returns></returns>
				static float4x4 MakeZRotation(float angle);

				/// <summary>
				/// Build a matrix which rotates around an arbitrary axis
				/// </summary>
				/// <param name="axis"></param>
				/// <param name="angle"></param>
				/// <returns></returns>
				static float4x4 MakeRotationAroundAxis(const float3& axis, float angle);

				/// <summary>
				/// Build a matrix which rotates around basic axis
				/// </summary>
				/// <param name="yaw"></param>
				/// <param name="pitch"></param>
				/// <param name="roll"></param>
				/// <returns></returns>
				/// <remarks>Yaw around the Y axis, a pitch around the X axis and a roll around the Z axis.</remarks>
				static float4x4 MakeRotation(float yaw, float pitch, float roll);

				/// <summary>
				/// Build a matrix which rotates around basic axis
				/// </summary>
				/// <param name="angles"></param>
				/// <returns></returns>
				/// <remarks>Yaw around the Y axis, a pitch around the X axis and a roll around the Z axis.</remarks>
				static float4x4 MakeRotation(const float3& angles);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="translation"></param>
				/// <param name="rotation"></param>
				/// <returns></returns>
				static float4x4 MakeCompositeTransformation(const float3& translation, const float4& rotation);

				/// <summary>
				/// Build a matrix which flattens geometry into a plane, as if casting a shadow from a light.
				/// If the light's w-component is 0, the ray from the origin to the light represents a directional light.
				/// If it is 1, the light is a point light.
				/// </summary>
				/// <param name="Out"></param>
				/// <param name="light"></param>
				/// <param name="plane"></param>
				static float4x4 BuildShadow(const float4& light, const float4& plane);

				/// <summary>
				/// Строит матрицу отражения относительно плоскости.
				/// </summary>
				/// <param name="plane">Плоскость отражения.</param>
				/// <returns>Матрица отражения.</returns>
				static float4x4 BuildReflect(const float4& plane);
			};

			/// <summary>
			/// View matrix utility functions.
			/// </summary>
			class ViewMatrix
			{
			public:
				/// <summary>
				/// Build a lookat matrix (right-handed)
				/// </summary>
				/// <param name="eye"></param>
				/// <param name="at"></param>
				/// <param name="up"></param>
				/// <returns></returns>
				static float4x4 MakeLookAtRH(const float3& eye, const float3& at, const float3& up);

				/// <summary>
				/// Build a lookat matrix (left-handed)
				/// </summary>
				/// <param name="eye"></param>
				/// <param name="at"></param>
				/// <param name="up"></param>
				/// <returns></returns>
				static float4x4 MakeLookAtLH(const float3& eye, const float3& at, const float3& up);

				/// <summary>
				/// Build a matrix which reflects the coordinate system about a plane.
				/// </summary>
				/// <param name="plane"></param>
				/// <returns></returns>
				static float4x4 MakeReflection(const float4& plane);				
			};

			/// <summary>
			/// Projection matrix utility functions.
			/// </summary>
			class ProjectionMatrix
			{
			public:
				/// <summary>
				/// Build a perspective projection matrix (right-handed)
				/// </summary>
				/// <param name="width"></param>
				/// <param name="height"></param>
				/// <param name="znear"></param>
				/// <param name="zfar"></param>
				/// <returns></returns>
				static float4x4 MakePerspectiveRH(float width, float height, float znear, float zfar);

				/// <summary>
				/// Build a perspective projection matrix (left-handed)
				/// </summary>
				/// <param name="width"></param>
				/// <param name="height"></param>
				/// <param name="znear"></param>
				/// <param name="zfar"></param>
				/// <returns></returns>
				static float4x4 MakePerspectiveLH(float width, float height, float znear, float zfar);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="fovY"></param>
				/// <param name="aspect"></param>
				/// <param name="znear"></param>
				/// <param name="zfar"></param>
				/// <returns></returns>
				static float4x4 MakePerspectiveFovRH(float fovY, float aspect, float znear, float zfar);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="fovY"></param>
				/// <param name="aspect"></param>
				/// <param name="znear"></param>
				/// <param name="zfar"></param>
				/// <returns></returns>
				static float4x4 MakePerspectiveFovLH(float fovY, float aspect, float znear, float zfar);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="left"></param>
				/// <param name="right"></param>
				/// <param name="bottom"></param>
				/// <param name="top"></param>
				/// <param name="znear"></param>
				/// <param name="zfar"></param>
				/// <returns></returns>
				static float4x4 MakePerspectiveOffCenterRH(float left, float right, float bottom, float top, float znear, float zfar);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="left"></param>
				/// <param name="right"></param>
				/// <param name="bottom"></param>
				/// <param name="top"></param>
				/// <param name="znear"></param>
				/// <param name="zfar"></param>
				/// <returns></returns>
				static float4x4 MakePerspectiveOffCenterLH(float left, float right, float bottom, float top, float znear, float zfar);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="width"></param>
				/// <param name="height"></param>
				/// <param name="znear"></param>
				/// <param name="zfar"></param>
				/// <returns></returns>
				static float4x4 MakeOrthoRH(float width, float height, float znear, float zfar);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="width"></param>
				/// <param name="height"></param>
				/// <param name="znear"></param>
				/// <param name="zfar"></param>
				/// <returns></returns>
				static float4x4 MakeOrthoLH(float width, float height, float znear, float zfar);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="left"></param>
				/// <param name="right"></param>
				/// <param name="bottom"></param>
				/// <param name="top"></param>
				/// <param name="znear"></param>
				/// <param name="zfar"></param>
				/// <returns></returns>
				static float4x4 MakeOrthoOffCenterRH(float left, float right, float bottom, float top, float znear, float zfar);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="left"></param>
				/// <param name="right"></param>
				/// <param name="bottom"></param>
				/// <param name="top"></param>
				/// <param name="znear"></param>
				/// <param name="zfar"></param>
				/// <returns></returns>
				static float4x4 MakeOrthoOffCenterLH(float left, float right, float bottom, float top, float znear, float zfar);
			};
#pragma endregion

#pragma region Quaternions

			/// <summary>
			/// Кватернион.
			/// </summary>
			class Quaternion
			{
			public:
				/// <summary>
				/// 
				/// </summary>
				/// <param name="quat1"></param>
				/// <param name="quat2"></param>
				/// <returns></returns>
				static float4 Multiply(const float4& quat1, const float4& quat2);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="Quat"></param>
				/// <returns></returns>
				static float GetLength(const float4& quat);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="quat"></param>
				static void Normalize(float4& quat);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="quat"></param>
				/// <returns></returns>
				static float4 GetNormalized(float4& quat);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="Quat"></param>
				static void Inverse(float4& quat);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="quat"></param>
				/// <returns></returns>
				static float4 GetInverted(float4& quat);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="quat"></param>
				/// <param name="exponent"></param>
				/// <returns></returns>
				/// <remarks>Quaternion should be normalized.</remarks>
				static float4 Pow(float4& quat, float exponent);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="quat1"></param>
				/// <param name="quat2"></param>
				/// <param name="t"></param>
				/// <returns></returns>
				static float4 Slerp(const float4& quat1, const float4& quat2, float t);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="in"></param>
				/// <param name="quat"></param>
				/// <returns></returns>
				static float3 RotateVector(const float3& in, const float4& quat);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="latitude"></param>
				/// <param name="longitude"></param>
				/// <param name="angle"></param>
				/// <returns></returns>
				static float4 FromSpherical(float latitude, float longitude, float angle);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="yaw"></param>
				/// <param name="pitch"></param>
				/// <param name="roll"></param>
				/// <returns></returns>
				static float4 FromYawPitchRoll(float yaw, float pitch, float roll);
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="rotation"></param>
				/// <returns></returns>
				static float4 FromMatrix3x3(const float3x3& rotation);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="rotation"></param>
				/// <returns></returns>
				static float4 FromMatrix4x4(const float4x4& rotation);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="from"></param>
				/// <param name="to"></param>
				/// <returns></returns>
				static float4 FromShortestArc(const float3& from, const float3& to);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="quat"></param>
				/// <returns></returns>
				static float3x3 ToMatrix3x3(const float4& quat);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="quat"></param>
				/// <returns></returns>
				static float4x4 ToMatrix4x4(const float4& quat);
			};

			/// <summary>
			/// Двойной кватернион.
			/// </summary>
			class DualQuaternion
			{
			public:
				/// <summary>
				/// Создаёт двойной кватернион из вектора переноса и кватерниона вращения.
				/// </summary>
				/// <param name="translation">Вектор переноса.</param>
				/// <param name="rotation">Кватернион вращения.</param>
				/// <returns>Двойной кватернион.</returns>
				static float2x4 FromTransformation(const float3& translation, const float4& rotation);
				
				/// <summary>
				/// Возвращает кватернион вращения из двойного кватерниона.
				/// </summary>
				/// <param name="dualQuat">Двойной кватернион.</param>
				/// <returns>Кватернион вращения.</returns>
				static float4 GetRotation(const float2x4& dualQuat);

				/// <summary>
				/// Возвращает вектор переноса из двойного кватерниона.
				/// </summary>
				/// <param name="dualQuat">Двойной кватернион.</param>
				/// <returns>Вектор переноса.</returns>
				static float3 GetTranslation(const float2x4& dualQuat);
			};
#pragma endregion

#pragma region Transforms

			/// <summary>
			/// Аффинные преобразования.
			/// </summary>
			class AffineTransformation
			{
			public:
				const xform3d Identity = xform3d(
					1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 1.0f,
					0.0f, 0.0f, 0.0f);

				__forceinline static xform3d FromMatrix4x4(const float4x4& matrix)
				{
					return xform3d(
						matrix._11_12_13,
						matrix._21_22_23,
						matrix._31_32_33,
						matrix._41_42_43);
				}

				__forceinline static float4x4 ToMatrix4x4(const xform3d& transformation)
				{
					return float4x4(
						transformation._11, transformation._12, transformation._13, 0.0f,
						transformation._21, transformation._22, transformation._23, 0.0f,
						transformation._31, transformation._32, transformation._33, 0.0f,
						transformation._41, transformation._42, transformation._43, 1.0f);
				}

				__forceinline static float3x3 GetBasic(const xform3d& transformation)
				{
					return float3x3(
						transformation._11_12_13,
						transformation._21_22_23,
						transformation._31_32_33);
				}

				__forceinline static float3 GetTranslation(const xform3d& transformation)
				{
					return transformation._41_42_43;
				}

				static xform3d FormLookAtRH(const float3& eye, const float3& at, const float3& up);
				static xform3d FormLookAtLH(const float3& eye, const float3& at, const float3& up);

				static xform3d MakeUniformScale(const float scale);
				static xform3d MakeScale(const float scaleX, const float scaleY, const float scaleZ);
				static xform3d MakeScale(const float3& scale);

				static xform3d MakeTranslation(const float3& translate);
				static xform3d MakeTranslation(const float translateX, const float translateY, const float translateZ);

				static xform3d MakeXRotation(const float angle);
				static xform3d MakeYRotation(const float angle);
				static xform3d MakeZRotation(const float angle);

				static xform3d MakeCompositeTransformation(const float3& translation, const float4& rotation);
			};
#pragma endregion

#pragma region Noise


			/// <summary>
			/// Бовый класс генератора шума.
			/// </summary>
			class BaseNoiseGenerator
			{
			public:
				BaseNoiseGenerator();
				~BaseNoiseGenerator();

			protected:
				int* p;
				float* g3;
				float* g2;
				float* g1;

			protected:
				constexpr float Bias(const float a, const float b)
				{
					return powf(a, logf(b) / logf(0.5f));
				}

				constexpr float Gain(const float a, const float b)
				{
					if (a < 0.001f)
						return 0;
					else if (a > 0.999f)
						return 1.0f;

					float p = logf(1.0f - b) / logf(0.5f);
					if (a < 0.5f)
						return float(powf(2 * a, p) / 2);
					else
						return 1 - float(powf(2 * (1.0f - a), p) / 2);
				}
			};

			/// <summary>
			/// Генератор простого шума.
			/// </summary>
			class SimpleNoiseGenerator : BaseNoiseGenerator
			{
			public:
				SimpleNoiseGenerator(int seed);
				~SimpleNoiseGenerator();

				float NextValue(const float s);
				float NextValue(const float2& v);
				float NextValue(const float3& v);

				float NextTileableValue(const float s, float w);
				float NextTileableValue(const float2& v, float w, float h);
				float NextTileableValue(const float3& v, float w, float h, float d);
			};

			/// <summary>
			/// Генератор турбулентного шума.
			/// </summary>
			class TurbulenceNoiseGenerator : BaseNoiseGenerator
			{
			public:
				TurbulenceNoiseGenerator(int seed);
				~TurbulenceNoiseGenerator();

				float NextValue(const float2& v, float freq);
				float NextValue(const float3& v, float freq);

				float NextTileableValue(const float2& v, float w, float h, float freq);
				float NextTileableValue(const float3& v, float w, float h, float d, float freq);
			};
			
#pragma endregion
		}
	}
}
#endif