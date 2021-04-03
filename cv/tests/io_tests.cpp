#include "cv/io.h"
#include <gtest/gtest.h>
#include <fstream>

// Testing reading an RGB image from a PNG image
TEST(CvIoTests, RgbPngRead) {
  using namespace cv;
  #ifndef BUILD_PATH
  // Dummy assert to stop the test
  ASSERT_TRUE(1 == 2) << "BUILD_PATH not set, needed to find test images";
  #endif
  std::string path = std::string(BUILD_PATH) + "/cv/tests/test_images/rgb0.png";
  RgbImage rgb_img = img_read(path.c_str());

  EXPECT_EQ(rgb_img.cols(), 1392);
  EXPECT_EQ(rgb_img.rows(), 512);

  // Load the true image from the binary file
  std::string true_rgb_path = std::string(BUILD_PATH) + "/cv/tests/test_images/rgb0.bin";
  std::ifstream true_rgb_file(true_rgb_path, std::ios::binary);

  uint8_t rgb[3];
  for (int i = 0; i < rgb_img.rows(); i++)  {
    for (int j = 0; j < rgb_img.cols(); j++) {
    true_rgb_file.read((char*)rgb, 3);
    EXPECT_EQ(rgb_img.at(i, j).r, rgb[0]);
    EXPECT_EQ(rgb_img.at(i, j).g, rgb[1]);
    EXPECT_EQ(rgb_img.at(i, j).b, rgb[2]);
    }
  }
}