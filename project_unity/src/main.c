// test_example.c
#include "../Unity/src/unity.h"      // Include Unity header for unit testing
#include "example.h"    // Include the header file for the functions being tested

// Function that runs before each test (optional)
void setUp(void) {
    // Initialization code before each test, if necessary
}

// Function that runs after each test (optional)
void tearDown(void) {
    // Cleanup code after each test, if necessary
}

// Test case for the add function
void test_add_should_return_sum_of_integers(void) {
    TEST_ASSERT_EQUAL_INT(5, add(2, 3));  // Check if 2 + 3 = 5
    TEST_ASSERT_EQUAL_INT(0, add(-1, 1)); // Check if -1 + 1 = 0
    TEST_ASSERT_EQUAL_INT(-2, add(-1, -1)); // Check if -1 + -1 = -2
}

// Test case for the subtract function
void test_subtract_should_return_difference_of_integers(void) {
    TEST_ASSERT_EQUAL_INT(1, subtract(3, 2));  // Check if 3 - 2 = 1
    TEST_ASSERT_EQUAL_INT(0, subtract(1, 1));  // Check if 1 - 1 = 0
    TEST_ASSERT_EQUAL_INT(-1, subtract(2, 3)); // Check if 2 - 3 = -1
}

int main(void) {
    UNITY_BEGIN(); // Start the Unity test framework
    
    // Run test cases
    RUN_TEST(test_add_should_return_sum_of_integers);
    RUN_TEST(test_subtract_should_return_difference_of_integers);
    
    return UNITY_END(); // End the Unity test framework
}

