#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70.2, 98));
}

TEST(Monitor, TemperatureCritical) {
  ASSERT_FALSE(isTemperatureOk(104));
  ASSERT_FALSE(isTemperatureOk(94));
  EXPECT_EQ(isTemperatureOk(100), 1);
  ASSERT_TRUE(isTemperatureOk(98.6));
}
TEST(Monitor, PulseRateCritical) {
  ASSERT_FALSE(isPulseRateOk(59));
  ASSERT_FALSE(isPulseRateOk(101));
  ASSERT_TRUE(isPulseRateOk(75));
  ASSERT_TRUE(isPulseRateOk(61));
}
TEST(Monitor, Spo2Critical) {
  ASSERT_FALSE(isSpo2Ok(89));
  ASSERT_TRUE(isSpo2Ok(95));
}

TEST(Monitor, VitalsTemperatureCritical) {
  ASSERT_FALSE(vitalsOk(98.5, 102, 100.7));
}
