#ifndef __ATC_CV_IMAGE_H__
#define __ATC_CV_IMAGE_H__

#include <vector>
#include <cstdint>
#include "cv/pixel_types.h"
#include "core/safe_assert.h"

namespace cv {
template<class PixelT> 
class Image {
public:
  Image(std::uint16_t nRows, std::uint16_t nCols) : 
    rows_(nRows), cols_(nCols), data_(nRows * nCols) {}
  
  std::uint16_t rows() const {
    return rows_;
  }

  std::uint16_t cols() const {
    return cols_;
  }

  const PixelT& at(std::uint16_t i, std::uint16_t j) const {
    ASSERT(i < rows_, "row index out of bounds");
    ASSERT(j < cols_, "col index out of bounds");
    return data_[i * cols_ + j];
  }

  PixelT& at(std::uint16_t i, std::uint16_t j) {
    ASSERT(i < rows_, "row index out of bounds");
    ASSERT(j < cols_, "col index out of bounds");
    return data_[i * cols_ + j];
  }

  const PixelT& operator() (std::uint16_t i, std::uint16_t j) const {
    return at(i, j);
  }

  PixelT& operator() (std::uint16_t i, std::uint16_t j) {
    return at(i, j);
  }

private:
  std::uint16_t rows_;
  std::uint16_t cols_;
  std::vector<PixelT> data_;
};

// Typedef the RGB image
using RgbImage = Image<PixelRgb>;
}
#endif