#include "stdafx.h"
#include "shared.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace GlacialBytes::OpenGm;

namespace CoreTest
{
	TEST_CLASS(DegreesTest)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
		}

		TEST_METHOD(degrees_ForZeroValue)
		{
			/*float r = degrees(0.0f);
			VectorAssert::IsPositive(r);
			VectorAssert::AreEquals(r, float2(1.0f, 2.0f));*/
		}
	};
}