#include "stdafx.h"
#include "shared.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace GlacialBytes::OpenGm;

namespace CoreTest
{
	TEST_CLASS(AllTest)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
		}

		TEST_METHOD(all2_ForAllNonZeroValues)
		{
			float2 v(1.0f, 2.0f);
			bool r = all2(v);
			Assert::IsTrue(r);
		}

		TEST_METHOD(all2_ForOneNonZeroValues)
		{
			float2 v(1.0f, 0.0f);
			bool r = all2(v);
			Assert::IsFalse(r);
		}

		TEST_METHOD(all2_ForAllZeroValues)
		{
			float2 v(0.0f, 0.0f);
			bool r = all2(v);
			Assert::IsFalse(r);
		}

		TEST_METHOD(all3_ForAllNonZeroValues)
		{
			float3 v(1.0f, 2.0f, 3.0f);
			bool r = all3(v);
			Assert::IsTrue(r);
		}

		TEST_METHOD(all3_ForOneNonZeroValues)
		{
			float3 v(1.0f, 0.0f, 3.0f);
			bool r = all3(v);
			Assert::IsFalse(r);
		}

		TEST_METHOD(all3_ForAllZeroValues)
		{
			float3 v(0.0f, 0.0f, 0.0f);
			bool r = all3(v);
			Assert::IsFalse(r);
		}

		TEST_METHOD(all4_ForAllNonZeroValues)
		{
			float4 v(1.0f, 2.0f, 3.0f, 4.0f);
			bool r = all4(v);
			Assert::IsTrue(r);
		}

		TEST_METHOD(all4_ForOneNonZeroValues)
		{
			float4 v(1.0f, 0.0f, 3.0f, 4.0f);
			bool r = all4(v);
			Assert::IsFalse(r);
		}

		TEST_METHOD(all4_ForAllZeroValues)
		{
			float4 v(0.0f, 0.0f, 0.0f, 0.0f);
			bool r = all4(v);
			Assert::IsFalse(r);
		}
	};
}