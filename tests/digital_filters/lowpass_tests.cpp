////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "digital_filters/lowpass.h"

#include <cmath>
#include <cstdint>
#include <gtest/gtest.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Namespace(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace
{

float default_sampling_speed{ 1.0 };
float default_cutoff_frequency{ 2.0 };
float default_time_constant{ static_cast<float>(1 / (2 * M_PI * default_cutoff_frequency)) };

} // namespace

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(LowpassTest, Given_ADigitalLowpassFilter_When_SamplingSpeedIsSet_Then_SamplingSpeedIsCorrect)
{
    // Given - A digital lowpass filter,
    Digital_Filters::Digital_lowpass test_lowpass(default_sampling_speed, default_cutoff_frequency);
    EXPECT_FLOAT_EQ(test_lowpass.get_sampling_speed(), default_sampling_speed);

    // When - Sampling speed is set,
    float updated_sampling_speed{ 5.0 };
    test_lowpass.set_sampling_speed(updated_sampling_speed);
    
    // Then - Sampling speed is correct.
    EXPECT_FLOAT_EQ(test_lowpass.get_sampling_speed(), updated_sampling_speed);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(LowpassTest, Given_ADigitalLowpassFilter_When_CutoffFrequencyIsSet_Then_TimeConstantIsCorrect)
{
    // Given - A digital lowpass filter,
    Digital_Filters::Digital_lowpass test_lowpass(default_sampling_speed, default_cutoff_frequency);
    EXPECT_FLOAT_EQ(test_lowpass.get_time_constant(), default_time_constant);

    // When - Cutoff frequency is set,
    float updated_cutoff_frequency{ 100000.0 };
    float updated_time_constant{ static_cast<float>(1 / (2 * M_PI * updated_cutoff_frequency)) };

    test_lowpass.set_cutoff_frequency(updated_cutoff_frequency);

    // Then - Time constant is correct.
    EXPECT_FLOAT_EQ(test_lowpass.get_time_constant(), updated_time_constant);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(
    LowpassTest,
    Given_ADigitalLowpassFilter_When_CutoffFrequencyIsSet_Then_CutoffFrequencyIsCorrect)
{
    // Given - A digital lowpass filter,
    Digital_Filters::Digital_lowpass test_lowpass(default_sampling_speed, default_cutoff_frequency);
    EXPECT_FLOAT_EQ(test_lowpass.get_cutoff_frequency(), default_cutoff_frequency);

    // When - Time constant is set,
    float updated_cutoff_frequency{ 5.0 };
    test_lowpass.set_cutoff_frequency(updated_cutoff_frequency);

    // Then - Time constant is correct.
    EXPECT_FLOAT_EQ(test_lowpass.get_cutoff_frequency(), updated_cutoff_frequency);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(LowpassTest, Given_ADigitalLowpassFilter_When_NoTicksOccured_Then_OutputIsZero)
{
    // Given - A digital lowpass filter,
    Digital_Filters::Digital_lowpass test_lowpass(default_sampling_speed, default_cutoff_frequency);

    // When - No ticks occured,
    // Then - Output is zero.
    EXPECT_FLOAT_EQ(test_lowpass.get_output(), 0.0);    
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(LowpassTest, Given_ADigitalLowpassFilter_When_ManyTicksOccured_Then_OutputIsExpected)
{
    // Given - A digital lowpass filter,
    Digital_Filters::Digital_lowpass test_lowpass(default_sampling_speed, default_cutoff_frequency);

    // When - Many ticks occured,
    for (uint8_t idx{ 0U }; idx < 100U; idx++)
    {
        static_cast<void>(test_lowpass.tick(1.0));
    }

    // Then - Output is expected.
    EXPECT_FLOAT_EQ(test_lowpass.get_output(), 1.0);
}
