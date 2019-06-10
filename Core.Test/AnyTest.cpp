#include "stdafx.h"
#include "shared.h"
#include "CppUnitTest.h"
#include <gm\gm.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace OpenGm;

namespace CoreTest
{
	TEST_CLASS(AnyTest)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
		}

		TEST_METHOD(any2_ForAllNonZeroValues)
		{
			float2 v(1.0f, 2.0f);
			bool r = any2(v);
			Assert::IsTrue(r);
		}

		TEST_METHOD(any2_ForOneNonZeroValues)
		{
			float2 v(1.0f, 0.0f);
			bool r = any2(v);
			Assert::IsTrue(r);
		}

		TEST_METHOD(any2_ForAllZeroValues)
		{
			float2 v(0.0f, 0.0f);
			bool r = any2(v);
			Assert::IsFalse(r);
		}

		TEST_METHOD(any3_ForAllNonZeroValues)
		{
			float3 v(1.0f, 2.0f, 3.0f);
			bool r = any3(v);
			Assert::IsTrue(r);
		}

		TEST_METHOD(any3_ForOneNonZeroValues)
		{
			float3 v(1.0f, 0.0f, 3.0f);
			bool r = any3(v);
			Assert::IsTrue(r);
		}

		TEST_METHOD(any3_ForAllZeroValues)
		{
			float3 v(0.0f, 0.0f, 0.0f);
			bool r = any3(v);
			Assert::IsFalse(r);
		}

		TEST_METHOD(any4_ForAllNonZeroValues)
		{
			float4 v(1.0f, 2.0f, 3.0f, 4.0f);
			bool r = any4(v);
			Assert::IsTrue(r);
		}

		TEST_METHOD(any4_ForOneNonZeroValues)
		{
			float4 v(1.0f, 0.0f, 3.0f, 4.0f);
			bool r = any4(v);
			Assert::IsTrue(r);
		}

		TEST_METHOD(any4_ForAllZeroValues)
		{
			float4 v(0.0f, 0.0f, 0.0f, 0.0f);
			bool r = any4(v);
			Assert::IsFalse(r);
		}
	};
}