#include "cv/image_file_store.h"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace cv;

cv::ImageFileStore::ImageFileStore(const std::string& rootDirectory) :
  root_dir_(rootDirectory),
  time_stamp_filename_() {
}

cv::ImageFileStore::ImageFileStore(
  const std::string& imageDirectory, 
  const std::string& timeStampFile) :
  root_dir_(imageDirectory),
  time_stamp_filename_(timeStampFile) {
  
}

void cv::ImageFileStore::SetRootDirectory(const std::string& rootDirectory) {
  root_dir_ = rootDirectory;
}

void cv::ImageFileStore::SetTimeStampFile(const std::string& fileName) {
  time_stamp_filename_ = fileName;
}

void cv::ImageFileStore::Read() {
  
  for (const auto & file : std::filesystem::directory_iterator(root_dir_)) {
    ImageData data;
    data.image_name = file.path();
    image_data_.push_back(data);
  }
  // C++ filesystem functionality does not guarantee the order we get the files,
  // so the files are likely not going to be in alphabetical order
  std::sort(image_data_.begin(), image_data_.end(), 
    [](const ImageData& lhs, const ImageData& rhs) -> bool
    { 
          return rhs.image_name > lhs.image_name; 
    });
  
  // Time stamp file is empty, has not been set. We will try the default timestamps.txt
  if (time_stamp_filename_.empty()) {
    time_stamp_filename_ = root_dir_ + "/timestamps.txt";
  }
  
  // See if there is a timestamps.txt file
  std::ifstream timestamp_file(time_stamp_filename_, std::ios::in);
  if (!timestamp_file.is_open()) {
    return;
  }

}

const std::vector<cv::ImageFileStore::ImageData>::const_iterator cv::ImageFileStore::begin() const {
  return image_data_.begin();
}

std::vector<cv::ImageFileStore::ImageData>::iterator cv::ImageFileStore::begin() {
  return image_data_.begin();
}

const std::vector<cv::ImageFileStore::ImageData>::const_iterator cv::ImageFileStore::end() const {
  return image_data_.end();
}

std::vector<cv::ImageFileStore::ImageData>::iterator cv::ImageFileStore::end() {
  return image_data_.end();
}