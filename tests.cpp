#include <gtest/gtest.h>
#include "four.h"

TEST(FourInitialize, Constructor)
{
	Four four;
	size_t size = four.getSize();
	size_t expectedSize = 0;
	unsigned char* FourArray = four.getFourArray();

	ASSERT_EQ(size, 0);
	ASSERT_EQ(FourArray, nullptr);
}


TEST(FourInitize, InitializerListConstructorCorrect) {
	Four four {'1', '2', '0'};
	size_t size = four.getSize();
	size_t expectedSize = 3;
	unsigned char* FourArray = four.getFourArray();
	unsigned char expectedArray[] = {'0', '2', '1'};

    ASSERT_EQ(size, expectedSize);
	for (size_t i = 0; i < size; i++) 
		ASSERT_EQ(FourArray[i], expectedArray[i]);
}

TEST(FourOperators, Plus) {
	Four number1("10");
	Four number2("1");
	unsigned char expectedArray[] = {'1', '1'};

	Four res = number1 + number2;
	unsigned char* Array = res.getFourArray();

	for (size_t i = 0; i < res.getSize(); i++) 
		ASSERT_EQ(Array[i], expectedArray[i]);

}

TEST(FourOperators, Minus) {
	Four number1("123");
	Four number2("2");
	unsigned char expectedArray[] = {'1', '2', '1'};

	Four res = number1 - number2;
	unsigned char* Array = res.getFourArray();

	for (size_t i = 0; i < res.getSize(); i++) 
		ASSERT_EQ(Array[i], expectedArray[i]);

}

TEST(FourOperators, IfMore) {
	Four number1("123");
	Four number2("20");

    ASSERT_TRUE(number1 > number2);

}

TEST(FourOperators, IfLess) {
	Four number1("1");
	Four number2("2002");

    ASSERT_TRUE(number1 < number2);

}

TEST(FourOperators, IfEqual) {
	Four number1("123");
	Four number2("123");

    ASSERT_TRUE(number1 == number2);

}

TEST(FourPrint, DefaultPrint) {
	
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}