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
  RgbImageWindow(const cv::RgbImage* image, const std::string& winName);

  void Draw();
private:
  const cv::RgbImage* img_;
  GLuint tex_;
  std::string win_name_;
};
}
#endif