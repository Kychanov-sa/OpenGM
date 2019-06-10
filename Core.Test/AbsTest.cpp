#include "stdafx.h"
#include "shared.h"
#include "CppUnitTest.h"
#include <gm\gm.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace OpenGm;

namespace CoreTest
{	
	TEST_CLASS(AbsTest)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
		}

		TEST_METHOD(abs2_ForAllPositoveValues)
		{
			float2 v(1.0f, 2.0f);
			auto r = abs2(v);
			VectorAssert::IsPositive(r);
			VectorAssert::AreEquals(r, float2(1.0f, 2.0f));
		}

		TEST_METHOD(abs2_ForAllNegativeValues)
		{
			float2 v(-1.0f, -2.0f);
			auto r = abs2(v);
			VectorAssert::IsPositive(r);
			VectorAssert::AreEquals(r, float2(1.0f, 2.0f));
		}

		TEST_METHOD(abs2_ForOneNegativeValues)
		{
			float2 v(1.0f, -2.0f);
			auto r = abs2(v);
			VectorAssert::IsPositive(r);
			VectorAssert::AreEquals(r, float2(1.0f, 2.0f));
		}

		TEST_METHOD(abs2_ForAllZeroValues)
		{
			float2 v(0.0f, 0.0f);
			auto r = abs2(v);
			VectorAssert::IsAroundZero(r);
		}

		TEST_METHOD(abs3_ForAllPositoveValues)
		{
			float3 v(1.0f, 2.0f, 3.0f);
			auto r = abs3(v);
			VectorAssert::IsPositive(r);
			VectorAssert::AreEquals(r, float3(1.0f, 2.0f, 3.0f));
		}

		TEST_METHOD(abs3_ForAllNegativeValues)
		{
			float3 v(-1.0f, -2.0f, -3.0f);
			auto r = abs3(v);
			VectorAssert::IsPositive(r);
			VectorAssert::AreEquals(r, float3(1.0f, 2.0f, 3.0f));
		}

		TEST_METHOD(abs3_ForOneNegativeValues)
		{
			float3 v(1.0f, -2.0f, 3.0f);
			auto r = abs3(v);
			VectorAssert::IsPositive(r);
			VectorAssert::AreEquals(r, float3(1.0f, 2.0f, 3.0f));
		}

		TEST_METHOD(abs3_ForAllZeroValues)
		{
			float3 v(0.0f, 0.0f, 0.0f);
			auto r = abs3(v);
			VectorAssert::IsAroundZero(r);
		}

		TEST_METHOD(abs4_ForAllPositoveValues)
		{
			float4 v(1.0f, 2.0f, 3.0f, 4.0f);
			auto r = abs4(v);
			VectorAssert::IsPositive(r);
			VectorAssert::AreEquals(r, float4(1.0f, 2.0f, 3.0f, 4.0f));
		}

		TEST_METHOD(abs4_ForAllNegativeValues)
		{
			float4 v(-1.0f, -2.0f, -3.0f, -4.0f);
			auto r = abs4(v);
			VectorAssert::IsPositive(r);
			VectorAssert::AreEquals(r, float4(1.0f, 2.0f, 3.0f, 4.0f));
		}

		TEST_METHOD(abs4_ForTwoNegativeValues)
		{
			float4 v(1.0f, -2.0f, 3.0f, -4.0f);
			auto r = abs4(v);
			VectorAssert::IsPositive(r);
			VectorAssert::AreEquals(r, float4(1.0f, 2.0f, 3.0f, 4.0f));
		}

		TEST_METHOD(abs4_ForAllZeroValues)
		{
			float4 v(0.0f, 0.0f, 0.0f, 0.0f);
			auto r = abs4(v);
			VectorAssert::IsAroundZero(r);
		}
	};
}