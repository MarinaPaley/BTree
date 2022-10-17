#include "pch.h"
#include "CppUnitTest.h"
#include "..\Library\Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NodeTests
{
	TEST_CLASS(NodeTests)
	{
	public:
		
		TEST_METHOD(Ctor_ValidData_Success)
		{
			// Arrange & Act
			auto node = new Node(1);
			// Assert
			Assert::IsNotNull(node);
		}

		TEST_METHOD(LeftShiftOperator_ValidData_Success)
		{
			// Arrange
			const std::string expected = "1";
			const auto node  = Node(1);

			// Act
			std::stringstream  out;
			out << node;
			const std::string actual = out.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(RightShiftOperator_ValidData_Success)
		{
			// Arrange
			std::stringstream buffer;
			buffer << 1;
			Node expected = 1;

			// Act
			Node actual;
			buffer >> actual;

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(EqualOperator)
		{
			// Arrange
			const auto lha = Node(1);
			const auto rha = Node(1);
			// Act & Assert
			Assert::IsTrue(lha == rha);
		}

		TEST_METHOD(NotEqualOperator)
		{
			// Arrange
			const auto lha = Node(1);
			const auto rha = Node(2);
			// Act & Assert
			Assert::IsTrue(lha != rha);
		}

		TEST_METHOD(AboveOperator)
		{
			// Arrange
			const auto lha = Node(2);
			const auto rha = Node(1);
			// Act & Assert
			Assert::IsTrue(lha > rha);
		}

		TEST_METHOD(AboveOrEqualOperator)
		{
			// Arrange
			const auto lha = Node(2);
			const auto rha = Node(1);
			const auto node = Node(1);
			// Act & Assert
			Assert::IsTrue(lha >= rha);
			Assert::IsTrue(lha >= node);
		}

		TEST_METHOD(LessOperator)
		{
			// Arrange
			const auto lha = Node(1);
			const auto rha = Node(2);

			// Act & Assert
			Assert::IsTrue(lha < rha);
			Assert::IsFalse(lha > rha);
		}

		TEST_METHOD(LessOrEqualOperator)
		{
			// Arrange
			const auto lha = Node(1);
			const auto rha = Node(2);
			const auto node = Node(1);

			// Act & Assert
			Assert::IsTrue(lha <= rha);
			Assert::IsTrue(lha <= node);
		}
	};
}
