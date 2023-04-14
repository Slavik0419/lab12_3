#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_3_it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
					int k = main();
					Assert::AreEqual(k, 0);

		}
	};
}
