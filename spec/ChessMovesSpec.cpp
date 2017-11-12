#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/ChessMoves.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class ChessMovesSpec
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
		void ChessMoves_Samples()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			char piece;


			piece = 'B';
			sourceX = sourceY = 5;
			destX = destY = 1;
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, piece);
			Assert::AreEqual(res, 1LL, L"Wrong Answer", 1, 2);


			piece = 'B';
			sourceX = sourceY = 5;
			destX = 5; destY = 4;
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, piece);
			Assert::AreEqual(res, -1LL, L"Wrong Answer", 1, 2);


			piece = 'R';
			sourceX = sourceY = 5;
			destX = 5; destY = 3;
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, piece);
			Assert::AreEqual(res, 1LL, L"Wrong Answer", 1, 2);


			piece = 'K';
			sourceX = sourceY = 5;
			destX = 5; destY = 1;
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, piece);
			Assert::AreEqual(res, 4LL, L"Wrong Answer", 1, 2);
		};

		
	};

}