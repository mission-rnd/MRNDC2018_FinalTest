#include "stdafx.h"
#include "../src/maxGold.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class maxGoldSpec
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

		int charToInt(char bin){
			switch (bin){
			case '0':	return 0;
			case '1':	return 1;
			case '2':	return 2;
			}
			return -1;
		}

		struct node* createNewNode(char bin){
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp->bin = charToInt(bin);
			temp->firstnode = NULL;
			temp->secondnode = NULL;
			temp->thirdnode = NULL;
			return temp;
		}

		struct node* constructTree(char *binString){
			struct node* root = NULL;
			struct node* nodes[2005];
			int i = 0;
			while (binString[i] != '\0'){
				nodes[i] = createNewNode(binString[i]);
				i++;
			}
			int invalid = 2;
			int mid = (i / 3);
			for (int i = 0; i < mid; i++){
				struct node* curnode = nodes[i];
				struct node* firstnode = nodes[(i * 3) + 1];
				struct node* secondnode = nodes[(i * 3) + 2];
				struct node* thirdnode = nodes[(i * 3) + 3];
				if (curnode->bin != invalid){
					if (firstnode->bin != invalid){
						curnode->firstnode = firstnode;
					}
					if (secondnode->bin != invalid){
						curnode->secondnode = secondnode;
					}
					if (thirdnode->bin != invalid){
						curnode->thirdnode = thirdnode;
					}
				}
			}
			root = nodes[0];
			return root;
		}

#pragma endregion 

		[TestMethod, Timeout(1000)]
		void maxGold_Sample()
		{
			struct node* head = NULL;
			int expectedAnswer = -1;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Sample test 01 failed", 1, 2, 1, 2);
		};

		
	};
}
