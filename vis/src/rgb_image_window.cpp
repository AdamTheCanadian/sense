#include "vis/rgb_image_window.h"

using namespace vis;

RgbImageWindow::RgbImageWindow(const std::string& winName) :
  tex_(0),
  tex_initialized_(false),
  tex_width_(0),
  tex_height_(0),
  win_name_(winName) {

}

void RgbImageWindow::Draw() {
  if (ImGui::Begin(win_name_.c_str())) {
    ImGui::Image((void*)(intptr_t)tex_, ImGui::GetContentRegionAvail());
  }
  ImGui::End();
}

void RgbImageWindow::UpdateImage(const cv::RgbImage* img) {
  if (!tex_initialized_) {
    InitTexture(img->width(), img->height());
  }
  glBindTexture(GL_TEXTURE_2D, tex_);
  glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, tex_width_, tex_height_, GL_RGB, GL_UNSIGNED_BYTE, &img->at(0, 0));
  glBindTexture(GL_TEXTURE_2D, 0);
}

void RgbImageWindow::InitTexture(std::uint16_t w, std::uint16_t h) {
  glGenTextures(1, &tex_);
  glBindTexture(GL_TEXTURE_2D, tex_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
  glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  // Unbind the texture
  glBindTexture(GL_TEXTURE_2D, 0);
  tex_width_ = w;
  tex_height_ = h;
  tex_initialized_ = true;
}