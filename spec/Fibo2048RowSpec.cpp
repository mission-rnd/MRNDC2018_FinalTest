#include "stdafx.h"
#include "../src/Fibo2048Row.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Fibo2048RowSpec
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

		void validate_fibo(int *expected, int *actual, int len) {
			for (int i = 0; i < len; i++){
				Assert::AreEqual(expected[i], actual[i], L"Wrong Answer for fiboRow,Keep debug point and check", 1, 2);
			}
		}
		[TestMethod, Timeout(1000)]
		void Fibo2048_Sample1()
		{
			int n = 4;
			int row[6] = { 2, 3, 2, 3 };
			int expected[6] = { 0, 0, 5, 5 };
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
		};

		[TestMethod, Timeout(1000)]
		void Fibo2048_NullCheck() {
			mergerow(NULL, 5, 'r');
		};
	};

	
}
