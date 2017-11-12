#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/StudentsLoop.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class StudentsLoopSpec
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
		struct loopnode * createnode(int roll)	{
			struct loopnode *new_node = (struct loopnode*)malloc(sizeof(struct loopnode));
			new_node->roll = roll;
			new_node->next = NULL;
			return new_node;
		}

		struct loopnode * createListFromArray(int * nums, int len, int loopIndex) {
			struct loopnode* headnode = createnode(nums[0]);
			struct loopnode* curNode = headnode;
			struct loopnode* loopnodeTemp;
			if (loopIndex == 0){
				loopnodeTemp = headnode;
			}
			int i = 1;
			while (i<len){
				curNode->next = createnode(nums[i]);
				curNode = curNode->next;
				if (i == loopIndex) {
					loopnodeTemp = curNode;
				}
				i++;
			}
			curNode->next = NULL;
			if (loopIndex != -1) {
				curNode->next = loopnodeTemp;
			}
			return headnode;
		}

		void validateLoop(struct loopnode* expected, struct loopnode* actual, int n) {
			int i = 0;
			if (expected != NULL) {
				if (actual == NULL) {
					Assert::AreEqual(1, 2, L"Fail", 1, 2);
				}
				else {
					int i = 0;
					//Loop n times
					while (i<n) {
						int val1 = expected->roll;
						int val2 = actual->roll;
						if (val1 != val2) {
							Assert::AreEqual(1, 2, L"Fail", 1, 2);
						}
						i++;
						expected = expected->next;
						actual = actual->next;
						if (actual == NULL) {
							Assert::AreEqual(1, 2, L"Fail", 1, 2);
						}
					}

				}

			}
			else {
				if (actual != NULL) {
					Assert::AreEqual(1, 2, L"Fail", 1, 2);
				}
			}
		}

		void validateNonLoop(struct loopnode* expected, struct loopnode* actual) {
			int i = 0;
			if (expected != NULL) {
				if (actual == NULL) {
					Assert::AreEqual(1, 2, L"Fail", 1, 2);
				}
				else {
					while (expected != NULL) {
						int val1 = expected->roll;
						int val2 = actual->roll;
						if (val1 != val2) {
							Assert::AreEqual(1, 2, L"Fail", 1, 2);
						}
						expected = expected->next;
						actual = actual->next;
						if (actual == NULL && expected != NULL) {
							Assert::AreEqual(1, 2, L"Fail", 1, 2);
						}

					}

				}

			}
			else {
				if (actual != NULL) {
					Assert::AreEqual(1,2, L"Fail", 1, 2);
				}
			}
		}

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Samples()
		{
			int nums[5] = { 10, 20, 5, 3, 1 };
			struct loopnode* head = createListFromArray(nums, 5, 1);
			struct loopnode* headcopy = createListFromArray(nums, 5, 1);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);
			validateLoop(head, actualhead, 10);
		};
		
	};

}