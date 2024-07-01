#include "stdafx.h"
#include "shared.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace GlacialBytes::OpenGm;

namespace CoreTest
{
	TEST_CLASS(InlinesTest)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
		}

#pragma region fmax2
		TEST_METHOD(fmax2_ForPositiveValues)
		{
			auto r = fmax2(1.0f, 4.0f);
			ScalarAssert::AreEquals(r, 4.0f);
		}

		TEST_METHOD(fmax2_ForNegativeValues)
		{
			auto r = fmax2(-1.0f, -4.0f);
			ScalarAssert::AreEquals(r, -1.0f);
		}

		TEST_METHOD(fmax2_ForMixedValues)
		{
			auto r = fmax2(-1.0f, 4.0f);
			ScalarAssert::AreEquals(r, 4.0f);
		}
#pragma endregion

#pragma region fmax3
		TEST_METHOD(fmax3_ForPositiveValues)
		{
			auto r = fmax3(1.0f, 4.0f, 2.0f);
			ScalarAssert::AreEquals(r, 4.0f);
		}

		TEST_METHOD(fmax3_ForNegativeValues)
		{
			auto r = fmax3(-1.0f, -4.0f, -2.0f);
			ScalarAssert::AreEquals(r, -1.0f);
		}

		TEST_METHOD(fmax3_ForMixedValues)
		{
			auto r = fmax3(-1.0f, 4.0f, 0.0f);
			ScalarAssert::AreEquals(r, 4.0f);
		}
#pragma endregion

#pragma region fmax4
		TEST_METHOD(fmax4_ForPositiveValues)
		{
			auto r = fmax4(1.0f, 4.0f, 2.0f, 0.0f);
			ScalarAssert::AreEquals(r, 4.0f);
		}

		TEST_METHOD(fmax4_ForNegativeValues)
		{
			auto r = fmax4(-1.0f, -4.0f, -2.0f, -0.4f);
			ScalarAssert::AreEquals(r, -0.4f);
		}

		TEST_METHOD(fmax4_ForMixedValues)
		{
			auto r = fmax4(-1.0f, 4.0f, 0.0f, 1.0f);
			ScalarAssert::AreEquals(r, 4.0f);
		}
#pragma endregion

#pragma region fmin2
		TEST_METHOD(fmin2_ForPositiveValues)
		{
			auto r = fmin2(1.0f, 4.0f);
			ScalarAssert::AreEquals(r, 1.0f);
		}

		TEST_METHOD(fmin2_ForNegativeValues)
		{
			auto r = fmin2(-1.0f, -4.0f);
			ScalarAssert::AreEquals(r, -4.0f);
		}

		TEST_METHOD(fmin2_ForMixedValues)
		{
			auto r = fmin2(-1.0f, 4.0f);
			ScalarAssert::AreEquals(r, -1.0f);
		}
#pragma endregion

#pragma region fmin3
		TEST_METHOD(fmin3_ForPositiveValues)
		{
			auto r = fmin3(1.0f, 4.0f, 2.0f);
			ScalarAssert::AreEquals(r, 1.0f);
		}

		TEST_METHOD(fmin3_ForNegativeValues)
		{
			auto r = fmin3(-1.0f, -4.0f, -2.0f);
			ScalarAssert::AreEquals(r, -4.0f);
		}

		TEST_METHOD(fmin3_ForMixedValues)
		{
			auto r = fmin3(-1.0f, 4.0f, 0.0f);
			ScalarAssert::AreEquals(r, -1.0f);
		}
#pragma endregion

#pragma region fmin4
		TEST_METHOD(fmin4_ForPositiveValues)
		{
			auto r = fmin4(1.0f, 4.0f, 2.0f, 0.0f);
			ScalarAssert::AreEquals(r, 0.0f);
		}

		TEST_METHOD(fmin4_ForNegativeValues)
		{
			auto r = fmin4(-1.0f, -4.0f, -2.0f, -0.4f);
			ScalarAssert::AreEquals(r, -4.0f);
		}

		TEST_METHOD(fmin4_ForMixedValues)
		{
			auto r = fmin4(-1.0f, 4.0f, 0.0f, 1.0f);
			ScalarAssert::AreEquals(r, -1.0f);
		}
#pragma endregion

#pragma region fsincos
		const float fsincos_epsilon = 0.0001f;

		TEST_METHOD(fsincos_0)
		{
			float sine = 0.0f, cosine = 0.0f;
			fsincos(0.0f, &sine, &cosine);
			ScalarAssert::AreEquals(sine, 0.0f, fsincos_epsilon);
			ScalarAssert::AreEquals(cosine, 1.0f, fsincos_epsilon);
		}

		TEST_METHOD(fsincos_90)
		{
			float sine = 0.0f, cosine = 0.0f;
			fsincos(GM_PI2, &sine, &cosine);
			ScalarAssert::AreEquals(sine, 1.0f, fsincos_epsilon);
			ScalarAssert::AreEquals(cosine, 0.0f, fsincos_epsilon);
		}

		TEST_METHOD(fsincos_180)
		{
			float sine = 0.0f, cosine = 0.0f;
			fsincos(GM_PI, &sine, &cosine);
			ScalarAssert::AreEquals(sine, 0.0f, fsincos_epsilon);
			ScalarAssert::AreEquals(cosine, -1.0f, fsincos_epsilon);
		}

		TEST_METHOD(fsincos_270)
		{
			float sine = 0.0f, cosine = 0.0f;
			fsincos(GM_PI + GM_PI2, &sine, &cosine);
			ScalarAssert::AreEquals(sine, -1.0f, fsincos_epsilon);
			ScalarAssert::AreEquals(cosine, 0.0f, fsincos_epsilon);
		}

		TEST_METHOD(fsincos_360)
		{
			float sine = 0.0f, cosine = 0.0f;
			fsincos(GM_2PI, &sine, &cosine);
			ScalarAssert::AreEquals(sine, 0.0f, fsincos_epsilon);
			ScalarAssert::AreEquals(cosine, 1.0f, fsincos_epsilon);
		}
#pragma endregion

//#pragma region finvsqrt
//		const float finvsqrt_epsilon = 0.01f;
//
//		TEST_METHOD(finvsqrt_1024)
//		{
//			auto r = finvsqrt(1024.0f);
//			ScalarAssert::AreEquals(r, 0.03125f, finvsqrt_epsilon);
//		}
//
//		TEST_METHOD(finvsqrt_1)
//		{
//			auto r = finvsqrt(1.0f);
//			ScalarAssert::AreEquals(r, 1.0f, finvsqrt_epsilon);
//		}
//
//		TEST_METHOD(finvsqrt_4)
//		{
//			auto r = finvsqrt(4.0f);
//			ScalarAssert::AreEquals(r, 0.5f, finvsqrt_epsilon);
//		}
//
//		TEST_METHOD(finvsqrt_100)
//		{
//			auto r = finvsqrt(100.0f);
//			ScalarAssert::AreEquals(r, 0.1f, finvsqrt_epsilon);
//		}
//#pragma endregion

#pragma region fsign
		const float fsign_epsilon = 0.000001f;

		TEST_METHOD(fsign_ForZero)
		{
			auto r = fsign(0.0f);
			ScalarAssert::AreEquals(r, 1.0f);
		}

		TEST_METHOD(fsign_ForPositive)
		{
			auto r = fsign(4343.0f);
			ScalarAssert::AreEquals(r, 1.0f);
		}

		TEST_METHOD(fsign_ForNegatve)
		{
			auto r = fsign(-32.0f);
			ScalarAssert::AreEquals(r, -1.0f);
		}
#pragma endregion

#pragma region frsqrt
		const float frsqrt_epsilon = 0.01f;

		TEST_METHOD(frsqrt_1024)
		{
			auto r = frsqrt(1024.0f);
			ScalarAssert::AreEquals(r, 0.03125f, frsqrt_epsilon);
		}

		TEST_METHOD(frsqrt_1)
		{
			auto r = frsqrt(1.0f);
			ScalarAssert::AreEquals(r, 1.0f, frsqrt_epsilon);
		}

		TEST_METHOD(frsqrt_4)
		{
			auto r = frsqrt(4.0f);
			ScalarAssert::AreEquals(r, 0.5f, frsqrt_epsilon);
		}

		TEST_METHOD(frsqrt_100)
		{
			auto r = frsqrt(100.0f);
			ScalarAssert::AreEquals(r, 0.1f, frsqrt_epsilon);
		}
#pragma endregion
	};
}