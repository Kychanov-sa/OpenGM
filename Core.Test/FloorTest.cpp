#include "stdafx.h"
#include "shared.h"
#include "CppUnitTest.h"
#include <gm\gm.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace OpenGm;

namespace CoreTest
{
	TEST_CLASS(FloorTest)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
		}

		TEST_METHOD(floor2_ForPositiveValuesLessThenHalf)
		{
			float2 v(0.3f, 0.49f);
			float2 r = floor2(v);
			VectorAssert::AreEquals(r, float2(0.0f, 0.0f));
		}

		TEST_METHOD(floor2_ForPositiveValuesGreaterThenHalf)
		{
			float2 v(0.51f, 0.67f);
			float2 r = floor2(v);
			VectorAssert::AreEquals(r, float2(0.0f, 0.0f));
		}

		TEST_METHOD(floor2_ForNegativeValuesLessThenHalf)
		{
			float2 v(-0.3f, -1.49f);
			float2 r = floor2(v);
			VectorAssert::AreEquals(r, float2(-1.0f, -2.0f));
		}

		TEST_METHOD(floor2_ForNegativeValuesGreaterThenHalf)
		{
			float2 v(-0.51f, -3.67f);
			float2 r = floor2(v);
			VectorAssert::AreEquals(r, float2(-1.0f, -4.0f));
		}

		TEST_METHOD(floor2_ForAllZeroValues)
		{
			float2 v(0.0f, 0.0f);
			auto r = floor2(v);
			VectorAssert::IsAroundZero(r);
		}

		TEST_METHOD(floor3_ForPositiveValuesLessThenHalf)
		{
			float3 v(0.3f, 0.49f, 0.001f);
			float3 r = floor3(v);
			VectorAssert::AreEquals(r, float3(0.0f, 0.0f, 0.0f));
		}

		TEST_METHOD(floor3_ForPositiveValuesGreaterThenHalf)
		{
			float3 v(0.51f, 0.67f, 1.99f);
			float3 r = floor3(v);
			VectorAssert::AreEquals(r, float3(0.0f, 0.0f, 1.0f));
		}

		TEST_METHOD(floor3_ForNegativeValuesLessThenHalf)
		{
			float3 v(-0.3f, -1.49f, -1.00001f);
			float3 r = floor3(v);
			VectorAssert::AreEquals(r, float3(-1.0f, -2.0f, -2.0f));
		}

		TEST_METHOD(floor3_ForNegativeValuesGreaterThenHalf)
		{
			float3 v(-0.51f, -3.67f, -5.99f);
			float3 r = floor3(v);
			VectorAssert::AreEquals(r, float3(-1.0f, -4.0f, -6.0f));
		}

		TEST_METHOD(floor3_ForAllZeroValues)
		{
			float3 v(0.0f, 0.0f, 0.0f);
			float3 r = floor3(v);
			VectorAssert::IsAroundZero(r);
		}

		TEST_METHOD(floor4_ForPositiveValuesLessThenHalf)
		{
			float4 v(0.3f, 0.49f, 0.001f, 0.499999f);
			float4 r = floor4(v);
			VectorAssert::AreEquals(r, float4(0.0f, 0.0f, 0.0f, 0.0f));
		}

		TEST_METHOD(floor4_ForPositiveValuesGreaterThenHalf)
		{
			float4 v(0.51f, 0.67f, 0.99f, 3.50000001f);
			float4 r = floor4(v);
			VectorAssert::AreEquals(r, float4(0.0f, 0.0f, 0.0f, 3.0f));
		}

		TEST_METHOD(floor4_ForNegativeValuesLessThenHalf)
		{
			float4 v(-0.3f, -1.49f, -1.00001f, -4.4999999f);
			float4 r = floor4(v);
			VectorAssert::AreEquals(r, float4(-1.0f, -2.0f, -2.0f, -5.0f));
		}

		TEST_METHOD(floor4_ForNegativeValuesGreaterThenHalf)
		{
			float4 v(-0.51f, -3.67f, -5.99f, -7.000000001f);
			float4 r = floor4(v);
			VectorAssert::AreEquals(r, float4(-1.0f, -4.0f, -6.0f, -7.0f));
		}

		TEST_METHOD(floor4_ForAllZeroValues)
		{
			float4 v(0.0f, 0.0f, 0.0f, 0.0f);
			float4 r = floor4(v);
			VectorAssert::IsAroundZero(r);
		}
	};
}