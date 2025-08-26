////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "digital_filters/lowpass.h"

#include <gtest/gtest.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Namespace(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace
{

float default_sampling_speed{ 1.0 };
float default_time_constant{ 2.0 };

} // namespace

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(LowpassTest, Given_ADigitalLowpassFilter_When_SamplingSpeedIsSet_Then_SamplingSpeedIsCorrect)
{
    // Given - A digital lowpass filter,
    Digital_Filters::Lowpass::Digital_lowpass test_lowpass(default_sampling_speed,
        default_time_constant);
    EXPECT_FLOAT_EQ(test_lowpass.get_sampling_speed(), default_sampling_speed);

    // When  - Sampling speed is set,
    float updated_sampling_speed{ 5.0 };
    test_lowpass.set_sampling_speed(updated_sampling_speed);
    
    // Then  - Sampling speed is correct.
    EXPECT_FLOAT_EQ(test_lowpass.get_sampling_speed(), updated_sampling_speed);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(LowpassTest, Given_ADigitalLowpassFilter_When_TimeConstantIsSet_Then_TimeConstantIsCorrect)
{
    // Given - A digital lowpass filter,
    Digital_Filters::Lowpass::Digital_lowpass test_lowpass(default_sampling_speed,
        default_time_constant);
    EXPECT_FLOAT_EQ(test_lowpass.get_time_constant(), default_time_constant);

    // When  - Time constant is set,
    float updated_time_constant{ 5.0 };
    test_lowpass.set_time_constant(updated_time_constant);

    // Then - Time constant is correct.
    EXPECT_FLOAT_EQ(test_lowpass.get_time_constant(), updated_time_constant);
}
