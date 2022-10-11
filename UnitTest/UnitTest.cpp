#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project\class.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private:
		circle cir1{ 15 };
		circle cir2{ 2 };
		circle cir3{ 9 };

		trapezoid trap1{ 19.55,5.55,14.5,10.6 };
		trapezoid trap2{ 8,4,3,5 };
		trapezoid trap3{ 21,7,15,13 };

		rectangle rec1{ 1.255,8 };
		rectangle rec2{ 1.5,2 };
		rectangle rec3{ 2,2 };

	public:
		TEST_METHOD(TestCircle)
		{
			Assert::IsTrue((round(cir1.getSquare() * 1000) / 1000) == 706.858);
			Assert::IsTrue((round(cir2.getSquare() * 1000) / 1000) == 12.566);
			Assert::IsTrue((round(cir3.getSquare() * 1000) / 1000) == 254.469);
			Assert::IsTrue((round(cir1.getPerimeter() * 1000) / 1000) == 94.248);
			Assert::IsTrue((round(cir2.getPerimeter() * 1000) / 1000) == 12.566);
			Assert::IsTrue((round(cir3.getPerimeter() * 1000) / 1000) == 56.549);

			Assert::IsTrue((round(rec1.getSquare() * 1000) / 1000) == 10.04);
			Assert::IsTrue((round(rec2.getSquare() * 1000) / 1000) == 3);
			Assert::IsTrue((round(rec3.getSquare() * 1000) / 1000) == 4);


			Assert::IsTrue((round(rec1.getPerimeter() * 1000) / 1000) == 18.51);
			Assert::IsTrue(rec2.getPerimeter() == 7);
			Assert::IsTrue(rec3.getPerimeter() == 8);

			Assert::IsTrue((round(trap1.getSquare() * 1000) / 1000) == 125.552);
			Assert::IsTrue(trap2.getSquare() == 18);
			Assert::IsTrue(trap3.getSquare() == 168);
			Assert::IsTrue(trap1.getPerimeter() == 50.2);
			Assert::IsTrue(trap2.getPerimeter() == 20);
			Assert::IsTrue(trap3.getPerimeter() == 56);
		}
	};
}

