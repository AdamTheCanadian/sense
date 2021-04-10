#ifndef __ATC_SPOC_VIS_IMAGE_WINDOW_H__
#define __ATC_SPOC_VIS_IMAGE_WINDOW_H__

#include "imgui.h"
#include "implot.h"
#include "cv/image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdint>
#include <string>

namespace vis {

class RgbImageWindow {
public:
  RgbImageWindow(const std::string& winName);

  void Draw();

  void UpdateImage(const cv::RgbImage* img);
private:

  void InitTexture(std::uint16_t w, std::uint16_t h);

  GLuint tex_;
  bool tex_initialized_;
  std::uint16_t tex_width_;
  std::uint16_t tex_height_;
  std::string win_name_;
};
}
#endif