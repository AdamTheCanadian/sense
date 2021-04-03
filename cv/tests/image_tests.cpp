#include "cv/image.h"
#include <gtest/gtest.h>

TEST(CvImageTests, RgbConstruction) {
  cv::RgbImage image(3, 3);
  EXPECT_EQ(image.rows(), 3);
  EXPECT_EQ(image.cols(), 3);
}