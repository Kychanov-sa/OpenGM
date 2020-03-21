#include "stdafx.h"
#include "CppUnitTest.h"
#include <gm\gm.h>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace OpenGm;

namespace CoreTest
{
#define FLOAT_DEFAULT_EPSILON	0.0000000001f

	class VectorAssert
	{
	public:
		static void AreEquals(const float2& v1, const float2& v2, float epsilon = FLOAT_DEFAULT_EPSILON, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = fabs(v1.x - v2.x) < FLOAT_DEFAULT_EPSILON;
			bool yCoordCondition = fabs(v1.y - v2.y) < FLOAT_DEFAULT_EPSILON;
			Assert::IsTrue(xCoordCondition, message ? message : ((L"X coordinate of vector is different on about ") + to_wstring(v1.x - v2.x)).c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : ((L"Y coordinate of vector is different on about ") + to_wstring(v1.y - v2.y)).c_str(), pLineInfo);
		}

		static void IsPositive(const float2& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = v.x >= 0.0f;
			bool yCoordCondition = v.y >= 0.0f;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is negative").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is negative").c_str(), pLineInfo);
		}

		static void IsNegative(const float2& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = v.x < 0.0f;
			bool yCoordCondition = v.y < 0.0f;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is positove").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is positove").c_str(), pLineInfo);
		}

		static void IsZero(const float2& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = v.x == 0.0f;
			bool yCoordCondition = v.y == 0.0f;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is not zero").c_str(), pLineInfo);
		}

		static void IsAroundZero(const float2& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = fabs(v.x) < GM_EPS;
			bool yCoordCondition = fabs(v.y) < GM_EPS;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is not zero").c_str(), pLineInfo);
		}

		static void AreEquals(const float3& v1, const float3& v2, float epsilon = FLOAT_DEFAULT_EPSILON, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = fabs(v1.x - v2.x) < FLOAT_DEFAULT_EPSILON;
			bool yCoordCondition = fabs(v1.y - v2.y) < FLOAT_DEFAULT_EPSILON;
			bool zCoordCondition = fabs(v1.z - v2.z) < FLOAT_DEFAULT_EPSILON;
			Assert::IsTrue(xCoordCondition, message ? message : ((L"X coordinate of vector is different on about ") + to_wstring(v1.x - v2.x)).c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : ((L"Y coordinate of vector is different on about ") + to_wstring(v1.y - v2.y)).c_str(), pLineInfo);
			Assert::IsTrue(zCoordCondition, message ? message : ((L"Z coordinate of vector is different on about ") + to_wstring(v1.z - v2.z)).c_str(), pLineInfo);
		}

		static void IsPositive(const float3& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = v.x >= 0.0f;
			bool yCoordCondition = v.y >= 0.0f;
			bool zCoordCondition = v.z >= 0.0f;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is negative").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is negative").c_str(), pLineInfo);
			Assert::IsTrue(zCoordCondition, message ? message : wstring(L"Z coordinate of vector is negative").c_str(), pLineInfo);
		}

		static void IsNegative(const float3& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = v.x < 0.0f;
			bool yCoordCondition = v.y < 0.0f;
			bool zCoordCondition = v.z < 0.0f;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is positove").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is positove").c_str(), pLineInfo);
			Assert::IsTrue(zCoordCondition, message ? message : wstring(L"Z coordinate of vector is positove").c_str(), pLineInfo);
		}

		static void IsZero(const float3& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = v.x == 0.0f;
			bool yCoordCondition = v.y == 0.0f;
			bool zCoordCondition = v.z == 0.0f;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(zCoordCondition, message ? message : wstring(L"Z coordinate of vector is not zero").c_str(), pLineInfo);
		}

		static void IsAroundZero(const float3& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = fabs(v.x) < GM_EPS;
			bool yCoordCondition = fabs(v.y) < GM_EPS;
			bool zCoordCondition = fabs(v.z) < GM_EPS;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(zCoordCondition, message ? message : wstring(L"Z coordinate of vector is not zero").c_str(), pLineInfo);
		}

		static void AreEquals(const float4& v1, const float4& v2, float epsilon = FLOAT_DEFAULT_EPSILON, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = fabs(v1.x - v2.x) < FLOAT_DEFAULT_EPSILON;
			bool yCoordCondition = fabs(v1.y - v2.y) < FLOAT_DEFAULT_EPSILON;
			bool zCoordCondition = fabs(v1.z - v2.z) < FLOAT_DEFAULT_EPSILON;
			bool wCoordCondition = fabs(v1.w - v2.w) < FLOAT_DEFAULT_EPSILON;
			Assert::IsTrue(xCoordCondition, message ? message : ((L"X coordinate of vector is different on about ") + to_wstring(v1.x - v2.x)).c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : ((L"Y coordinate of vector is different on about ") + to_wstring(v1.y - v2.y)).c_str(), pLineInfo);
			Assert::IsTrue(zCoordCondition, message ? message : ((L"Z coordinate of vector is different on about ") + to_wstring(v1.z - v2.z)).c_str(), pLineInfo);
			Assert::IsTrue(wCoordCondition, message ? message : ((L"W coordinate of vector is different on about ") + to_wstring(v1.w - v2.w)).c_str(), pLineInfo);
		}

		static void IsPositive(const float4& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = v.x >= 0.0f;
			bool yCoordCondition = v.y >= 0.0f;
			bool zCoordCondition = v.z >= 0.0f;
			bool wCoordCondition = v.w >= 0.0f;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is negative").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is negative").c_str(), pLineInfo);
			Assert::IsTrue(zCoordCondition, message ? message : wstring(L"Z coordinate of vector is negative").c_str(), pLineInfo);
			Assert::IsTrue(wCoordCondition, message ? message : wstring(L"W coordinate of vector is negative").c_str(), pLineInfo);
		}

		static void IsNegative(const float4& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = v.x < 0.0f;
			bool yCoordCondition = v.y < 0.0f;
			bool zCoordCondition = v.z < 0.0f;
			bool wCoordCondition = v.w < 0.0f;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is positove").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is positove").c_str(), pLineInfo);
			Assert::IsTrue(zCoordCondition, message ? message : wstring(L"Z coordinate of vector is positove").c_str(), pLineInfo);
			Assert::IsTrue(wCoordCondition, message ? message : wstring(L"W coordinate of vector is positove").c_str(), pLineInfo);
		}

		static void IsZero(const float4& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = v.x == 0.0f;
			bool yCoordCondition = v.y == 0.0f;
			bool zCoordCondition = v.z == 0.0f;
			bool wCoordCondition = v.w == 0.0f;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(zCoordCondition, message ? message : wstring(L"Z coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(wCoordCondition, message ? message : wstring(L"W coordinate of vector is not zero").c_str(), pLineInfo);
		}

		static void IsAroundZero(const float4& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			bool xCoordCondition = fabs(v.x) < GM_EPS;
			bool yCoordCondition = fabs(v.y) < GM_EPS;
			bool zCoordCondition = fabs(v.z) < GM_EPS;
			bool wCoordCondition = fabs(v.z) < GM_EPS;
			Assert::IsTrue(xCoordCondition, message ? message : wstring(L"X coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(yCoordCondition, message ? message : wstring(L"Y coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(zCoordCondition, message ? message : wstring(L"Z coordinate of vector is not zero").c_str(), pLineInfo);
			Assert::IsTrue(wCoordCondition, message ? message : wstring(L"W coordinate of vector is not zero").c_str(), pLineInfo);
		}
	};	

	class ScalarAssert
	{
	public:
		static void AreEquals(const float& v1, const float& v2, float epsilon = FLOAT_DEFAULT_EPSILON, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			Assert::AreEqual(v1, v2, epsilon);
		}

		static void IsPositive(const float& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			Assert::IsTrue(v >= 0.0f, message ? message : wstring(L"Scalar value is negative").c_str(), pLineInfo);
		}

		static void IsNegative(const float& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			Assert::IsTrue(v < 0.0f, message ? message : wstring(L"Scalar value is positive").c_str(), pLineInfo);
		}

		static void IsZero(const float& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			Assert::IsTrue(v == 0.0f, message ? message : wstring(L"Scalar value is not zero").c_str(), pLineInfo);
		}

		static void IsAroundZero(const float& v, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			Assert::IsTrue(fabs(v) < GM_EPS, message ? message : wstring(L"Scalar value is not zero").c_str(), pLineInfo);
		}
	};
}