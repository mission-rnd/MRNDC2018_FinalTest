#include "stdafx.h"
#include "../src/LastOne.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class LastOneSpec
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

		[TestMethod, Timeout(1000)]
		void lastOne_Sample1()
		{
			const int N = 5, M = 5;
			int values[N][M] = {
				{ 2, 1, 0, 2, 1 },
				{ 1, 0, 1, 2, 1 },
				{ 1, 0, 0, 2, 1 }
			};
			int res = lastOne(&values[0][0], 3, 5);
			Assert::AreEqual(2, res, L"Wrong Answer", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void lastOne_Sample2()
		{
			const int N = 4, M = 4;
			int values[N][M] = {
				{ 2, 1, 0, 1 },
				{ 1, 1, 1, 0 },
				{ 0, 0, 0, 1 },
				{ 2, 1, 1, 0 }
			};
			int res = lastOne(&values[0][0], 4, 4);
			//-1 as the top right 1 cant be converted
			Assert::AreEqual(-1, res, L"Wrong Answer", 1, 2);

		};


	};
}
