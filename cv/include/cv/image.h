#ifndef __ATC_CV_IMAGE_H__
#define __ATC_CV_IMAGE_H__

#include <vector>
#include <cstdint>
#include "cv/pixel_types.h"
#include "core/safe_assert.h"

namespace cv {

/**
 * @brief Image class
 * 
 * Construct an image with a known width and height.
 * For example a 800x600 image is 800 width, and 600 height.
 * 
 * Pixel access operators are provided (.at() and () functions). The coordinate
 * system used is top left of image is (0, 0) and x is to the right, y is down.
 * So for example if the image pixels are:
 * 1, 2, 3, 4
 * 5, 6, 7, 8
 * 
 * The image is 4x2 (width == 4, height == 2)
 * pixel at (0, 0) == 1
 * pixel at (0, 1) == 2
 * pixel at (1, 3) == 8
 * 
 * @tparam PixelT 
 */
template<class PixelT> 
class Image {
public:
  Image(std::uint16_t width, std::uint16_t height) : 
    width_(width), height_(height), data_(width_ * height_) {}
  
  PixelT& at(std::uint16_t i, std::uint16_t j) {
    ASSERT(i < height_, "height index out of bounds");
    ASSERT(j < width_, "width_ index out of bounds");
    return data_[i * width_ + j];
  }

  const PixelT& at(std::uint16_t i, std::uint16_t j) const {
    ASSERT(i < height_, "height index out of bounds");
    ASSERT(j < width_, "width_ index out of bounds");
    return data_[i * width_ + j];
  }
  
  std::uint16_t width() const {
    return width_;
  }

  std::uint16_t height() const {
    return height_;
  }

  const PixelT& operator() (std::uint16_t i, std::uint16_t j) const {
    return at(i, j);
  }

  PixelT& operator() (std::uint16_t i, std::uint16_t j) {
    return at(i, j);
  }

private:
  std::uint16_t width_;
  std::uint16_t height_;
  std::vector<PixelT> data_;
};

// Typedef the RGB image
using RgbImage = Image<PixelRgb>;
}
#endif