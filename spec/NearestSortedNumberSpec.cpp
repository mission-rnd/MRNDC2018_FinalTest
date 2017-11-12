#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/NearestSortedNumber.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class NearestSortedNumberSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes

#pragma endregion 
		int checker(char *expected,char *actual){
			if (expected == NULL || actual == NULL) 
				return (actual == expected);
			int len1 = 0, len2 = 0;
			for (len1 = 0; expected[len1]; len1++);
			for (len2 = 0; actual[len2]; len2++);
			if (len1 != len2) return 0;
			for (int i = 0; i < len1; i++){
				if (expected[i] != actual[i]) return 0;
			}
			return 1;
		}

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Samples()
		{
			char *res;
			res = NearestSortedNumber("25", 2);
			Assert::AreEqual(checker("25", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("10", 2);
			Assert::AreEqual(checker("9", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("19", 2);
			Assert::AreEqual(checker("19", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("20", 2);
			Assert::AreEqual(checker("19", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("2wer5", 2);
			if (res != NULL) Assert::AreEqual(1,2, L"Expected NULL", 1, 2);
		};

	};

}