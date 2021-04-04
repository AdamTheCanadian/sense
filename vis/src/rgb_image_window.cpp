#include "vis/rgb_image_window.h"

using namespace vis;

RgbImageWindow::RgbImageWindow(const cv::RgbImage* image, const std::string& winName) : 
  img_(image), 
  tex_(0),
  win_name_(winName) {
  

  glGenTextures(1, &tex_);
  glBindTexture(GL_TEXTURE_2D, tex_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_->width(), img_->height(), 0, GL_RGB, GL_UNSIGNED_BYTE, &img_->at(0, 0));
  glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  // Unbind the texture
  glBindTexture(GL_TEXTURE_2D, 0);
}

void RgbImageWindow::Draw() {
  if (ImGui::Begin(win_name_.c_str())) {
    ImGui::Image((void*)(intptr_t)tex_, ImGui::GetContentRegionAvail());
  }
  ImGui::End();
}