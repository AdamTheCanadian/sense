#include "cv/io.h"
#include "core/safe_assert.h"
#define STB_IMAGE_IMPLEMENTATION
#include "cv/stb_image.h"

cv::RgbImage cv::img_read(const char* f) {
  /* 
    We use the STB library for reading an image. It allocates memory into a raw 
    buffer of unsigned bytes. We need to copy that data over to our desired image
    type. Not super efficient but until we get a handle of what image types we want
    to support, and desired API this is easiest.
  */

  int rows, cols, nchan;
  uint8_t* data = stbi_load(f, &cols, &rows, &nchan, 0);
  ASSERT(data != NULL, "imread error, data is null");
  ASSERT(nchan == 3, "imread incorret number of channels");
  if (data == NULL || nchan != 3) {
    stbi_image_free(data);
    return cv::RgbImage(0, 0);
  }

  cv::RgbImage image(cols, rows);
  // For skipping over bytes in the raw buffer
  uint32_t idx = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      image.at(r, c).r = data[idx + 0];
      image.at(r, c).g = data[idx + 1];
      image.at(r, c).b = data[idx + 2];
      idx += 3;
    }
  }
  stbi_image_free(data);
  return image;
}