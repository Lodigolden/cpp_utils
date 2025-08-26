//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "math/basic_math.h"

#include <gtest/gtest.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(SquaredTest, Given_ZeroInput_When_SquaredIsCalled_Then_OutputIsZero)
{
    // Given - 0 input,
    // When  - squared() is called,
    // Then  - Output is zero.
    EXPECT_EQ(Basic_Math::squared<int>(0), 0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(SquaredTest, Given_NonZeroIntegerInput_When_SquaredIsCalled_Then_OutputIsExpected)
{
    // Given - Non-zero integer input,
    // When  - squared(s) is called,
    // Then  - Output is expected.
    EXPECT_EQ(Basic_Math::squared<int>(5), 25);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(SquaredTest, Given_NegativeIntegerInput_When_SquaredIsCalled_Then_OutputIsExpected)
{
    // Given - Negative integer input,
    // When  - squared() is called,
    // Then  - Output is expected.
    EXPECT_EQ(Basic_Math::squared<int>(-5), 25);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(SquaredTest, Given_NonZeroFloatInput_When_SquaredIsCalled_Then_OutputIsExpected)
{
    // Given - Non-zero float input,
    // When  - squared() is called,
    // Then  - Output is expected.
    EXPECT_FLOAT_EQ(Basic_Math::squared<float>(2.5), 6.25);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(SquaredTest, Given_NegativeFloatInput_When_SquaredIsCalled_Then_OutputIsExpected)
{
    // Given - Negative float input,
    // When  - squared() is called,
    // Then  - Output is expected.
    EXPECT_FLOAT_EQ(Basic_Math::squared<float>(2.5), 6.25);
}
