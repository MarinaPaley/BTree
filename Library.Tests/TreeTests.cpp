#include "CppUnitTest.h"
#include "..\Library\Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeTests
{
	TEST_CLASS(TreeTests)
	{
	public:

		TEST_METHOD(Ctor_ValidData_Success)
		{
			// Arrange & Act
			auto tree = new Tree();

			// Assert
			Assert::AreEqual(tree->GetCount(), 0);
		}

		TEST_METHOD(Add_ValidData_Success)
		{
			// Arrange
			auto tree = new Tree();

			// Act
			tree->Add(1);

			// Assert
			Assert::AreEqual(tree->GetCount(), 1);
		}

		TEST_METHOD(CtorInitializer_ValidData_Success)
		{
			// Arrange & act
			auto tree = new Tree{ 1, 2, 3, 4, 5 };

			// Assert
			Assert::AreEqual(tree->GetCount(), 5);
		}

		TEST_METHOD(Delete_ValidData_Success)
		{
			// Arrange
			auto tree = new Tree{ 1, 2, 3, 4, 5 };

			// Act
			auto deleted = tree->Delete(3);

			//
			Assert::IsTrue(deleted);
			Assert::AreEqual(tree->GetCount(), 4);
		}

		TEST_METHOD(Delete_WrongData_Success)
		{
			// Arrange
			auto tree = new Tree{ 1, 2, 3, 4, 5 };

			// Act
			auto deleted = tree->Delete(6);

			//
			Assert::IsFalse(deleted);
			Assert::AreEqual(tree->GetCount(), 5);
		}

		TEST_METHOD(Contains_ValidData_Success)
		{
			// Arrange
			auto tree = new Tree{ 1, 2, 3, 4, 5 };

			// Act
			auto contains = tree->Contains(3);

			// Assert
			Assert::IsTrue(contains);
		}

		TEST_METHOD(Contains_WrongData_Success)
		{
			// Arrange
			auto tree = new Tree{ 1, 2, 3, 4, 5 };

			// Act
			auto contains = tree->Contains(6);

			// Assert
			Assert::IsFalse(contains);
		}

		TEST_METHOD(ToString_ValidData_Success)
		{
			// Arrange
			auto tree = new Tree{ 5, 3, 7, 4, 8, 2, 6, 1 };
			std::wstring expected = L"{1, 2, 3, 4, 5, 6, 7, 8}";

			// Act
			std::wstring actual = tree->ToString();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ToString_EmptyData_Success)
		{
			// Arrange
			auto tree = new Tree();
			std::wstring expected = L"{}";

			// Act
			std::wstring actual = tree->ToString();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ShiftOperator_ValidData_Success)
		{
			// Arrange
			Tree tree  = { 5, 3, 7, 4, 8, 2, 6, 1 };
			const std::string expected = "{1, 2, 3, 4, 5, 6, 7, 8}";

			// Act
			std::stringstream buffer;
			buffer << tree;
			const std::string actual = buffer.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ShiftOperator_EmptyData_Success)
		{
			// Arrange
			Tree tree;
			const std::string expected = "{}";

			// Act
			std::stringstream buffer;
			buffer << tree;
			const std::string actual = buffer.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
};
