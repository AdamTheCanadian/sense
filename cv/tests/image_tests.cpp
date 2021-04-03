#include "cv/image.h"
#include <gtest/gtest.h>

TEST(CvImageTests, RgbConstruction) {
  cv::RgbImage image(3, 3);
  EXPECT_EQ(image.height(), 3);
  EXPECT_EQ(image.width(), 3);

  cv::RgbImage image2(30, 70);
  EXPECT_EQ(image2.width(), 30);
  EXPECT_EQ(image2.height(), 70);
}

// If the assert message changes within image.h this test will fail
TEST(CvImageTests, RgbInvalidAccess) {
  cv::RgbImage image(3, 3);

  // Out of bounds on the row, these are testing the non const version of access
  EXPECT_DEATH(image.at(3, 2), 
    "Assertion `i < height_` failed in image.h line 17: height index out of bounds");
  EXPECT_DEATH(image(3, 2), 
    "Assertion `i < height_` failed in image.h line 17: height index out of bounds");
  EXPECT_DEATH(image.at(2, 3), 
    "Assertion `j < width_` failed in image.h line 18: width_ index out of bounds");
  EXPECT_DEATH(image(2, 3), 
    "Assertion `j < width_` failed in image.h line 18: width_ index out of bounds");
  
  const cv::RgbImage image2(3, 3);
  // Testing the const version
  EXPECT_DEATH(image2.at(3, 2), 
    "Assertion `i < height_` failed in image.h line 23: height index out of bounds");
  EXPECT_DEATH(image2(3, 2), 
    "Assertion `i < height_` failed in image.h line 23: height index out of bounds");
  EXPECT_DEATH(image2.at(2, 3), 
    "Assertion `j < width_` failed in image.h line 24: width_ index out of bounds");
  EXPECT_DEATH(image2(2, 3), 
    "Assertion `j < width_` failed in image.h line 24: width_ index out of bounds");
}