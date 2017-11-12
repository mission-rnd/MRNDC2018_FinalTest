#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/RepeatedDivision.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class RepeatedDivisionSpec
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
		void RepeatedDivision_Samples()
		{
			int res;
			res = RepeatedDivision(6);
			Assert::AreEqual(res, 4, L"Wrong Answer", 1, 2);

			res = RepeatedDivision(10);
			Assert::AreEqual(res,8, L"Wrong Answer", 1, 2);
		};
	
	};

}