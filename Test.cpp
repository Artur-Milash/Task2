#include <gtest/gtest.h>
#include "Any_type.h"
#include <string.h>

TEST(AnyTypeClassTesting, Add_and_get_int_operator) {
	Any_type test;
	test = 3;

	ASSERT_EQ(test.to_int(), 3);
}

TEST(AnyTypeClassTesting, Call_bad_cast) {
	Any_type test{7.8};

	ASSERT_THROW(test.to_bool(), std::bad_cast);
}

TEST(AnyTypeClassTesting, Add_and_get_int_constructor) {
	Any_type test{3};

	ASSERT_EQ(test.to_int(), 3);
}

TEST(AnyTypeClassTesting, Swap) {
	Any_type first{ 10.76 }, second{ 'c' };

	first.swap(second);
	
	ASSERT_EQ(first.to_char(), 'c');
	ASSERT_EQ(second.to_double(), 10.76);
}

TEST(AnyTypeClassTesting, Destroy) {
	Any_type test{ 56 };

	test.destroy();

	ASSERT_THROW(test.to_int(), std::bad_cast);
}

int main(int args, char** argv) {
	testing::InitGoogleTest(&args, argv);
	return RUN_ALL_TESTS();
}