#include "stdafx.h"
#include "shared.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace GlacialBytes::OpenGm;

namespace CoreTest
{
	TEST_CLASS(CeilTest)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
		}

		TEST_METHOD(ceil2_ForPositiveValuesLessThenHalf)
		{
			float2 v(0.3f, 0.49f);
			float2 r = ceil2(v);
			VectorAssert::AreEquals(r, float2(1.0f, 1.0f));
		}

		TEST_METHOD(ceil2_ForPositiveValuesGreaterThenHalf)
		{
			float2 v(0.51f, 0.67f);
			float2 r = ceil2(v);
			VectorAssert::AreEquals(r, float2(1.0f, 1.0f));
		}

		TEST_METHOD(ceil2_ForNegativeValuesLessThenHalf)
		{
			float2 v(-0.3f, -1.49f);
			float2 r = ceil2(v);
			VectorAssert::AreEquals(r, float2(0.0f, -1.0f));
		}

		TEST_METHOD(ceil2_ForNegativeValuesGreaterThenHalf)
		{
			float2 v(-0.51f, -3.67f);
			float2 r = ceil2(v);
			VectorAssert::AreEquals(r, float2(0.0f, -3.0f));
		}
		
		TEST_METHOD(ceil2_ForAllZeroValues)
		{
			float2 v(0.0f, 0.0f);
			auto r = ceil2(v);
			VectorAssert::IsAroundZero(r);
		}

		TEST_METHOD(ceil3_ForPositiveValuesLessThenHalf)
		{
			float3 v(0.3f, 0.49f, 0.001f);
			float3 r = ceil3(v);
			VectorAssert::AreEquals(r, float3(1.0f, 1.0f, 1.0f));
		}

		TEST_METHOD(ceil3_ForPositiveValuesGreaterThenHalf)
		{
			float3 v(0.51f, 0.67f, 0.99f);
			float3 r = ceil3(v);
			VectorAssert::AreEquals(r, float3(1.0f, 1.0f, 1.0f));
		}

		TEST_METHOD(ceil3_ForNegativeValuesLessThenHalf)
		{
			float3 v(-0.3f, -1.49f, -1.00001f);
			float3 r = ceil3(v);
			VectorAssert::AreEquals(r, float3(0.0f, -1.0f, -1.0f));
		}

		TEST_METHOD(ceil3_ForNegativeValuesGreaterThenHalf)
		{
			float3 v(-0.51f, -3.67f, -5.99f);
			float3 r = ceil3(v);
			VectorAssert::AreEquals(r, float3(0.0f, -3.0f, -5.0f));
		}

		TEST_METHOD(ceil3_ForAllZeroValues)
		{
			float3 v(0.0f, 0.0f, 0.0f);
			float3 r = ceil3(v);
			VectorAssert::IsAroundZero(r);
		}
	
		TEST_METHOD(ceil4_ForPositiveValuesLessThenHalf)
		{
			float4 v(0.3f, 0.49f, 0.001f, 0.499999f);
			float4 r = ceil4(v);
			VectorAssert::AreEquals(r, float4(1.0f, 1.0f, 1.0f, 1.0f));
		}

		TEST_METHOD(ceil4_ForPositiveValuesGreaterThenHalf)
		{
			float4 v(0.51f, 0.67f, 0.99f, 0.50000001f);
			float4 r = ceil4(v);
			VectorAssert::AreEquals(r, float4(1.0f, 1.0f, 1.0f, 1.0f));
		}

		TEST_METHOD(ceil4_ForNegativeValuesLessThenHalf)
		{
			float4 v(-0.3f, -1.49f, -1.00001f, -4.4999999f);
			float4 r = ceil4(v);
			VectorAssert::AreEquals(r, float4(0.0f, -1.0f, -1.0f, -4.0f));
		}

		TEST_METHOD(ceil4_ForNegativeValuesGreaterThenHalf)
		{
			float4 v(-0.51f, -3.67f, -5.99f, -7.000000001f);
			float4 r = ceil4(v);
			VectorAssert::AreEquals(r, float4(0.0f, -3.0f, -5.0f, -7.0f));
		}

		TEST_METHOD(ceil4_ForAllZeroValues)
		{
			float4 v(0.0f, 0.0f, 0.0f, 0.0f);
			float4 r = ceil4(v);
			VectorAssert::IsAroundZero(r);
		}
	};
}