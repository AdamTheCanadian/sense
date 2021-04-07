#ifndef __ATC_CV_IMAGE_FILE_STORE_H__
#define __ATC_CV_IMAGE_FILE_STORE_H__

#include <string>
#include <chrono>
#include <vector>

namespace cv {

/**
 * @brief For reading image information from a folder, image file names, and if 
 * available timestamps for the images.
 * 
 * Assumes timestamps are in a file called timestamps.txt and in the form:
 * year-month-day hour:min:seconds (2011-09-30 12:42:41.836573952)
 * This is the format KITTI data set uses.
 */
class ImageFileStore {
public:

  // The actual data we are storing and providing
  struct ImageData {
    // Full path of the image (/my/documents/image.png)
    std::string image_name = "";
    // A time stamp of the image
    std::chrono::time_point<std::chrono::steady_clock> time_stamp;
  };

  ImageFileStore(const std::string& rootDirectory = "");

  // Setup an image store where images and timestamp file are separate
  ImageFileStore(
    const std::string& imageDirectory, 
    const std::string& timeStampFile);

  void SetRootDirectory(const std::string& rootDirectory);

  void SetTimeStampFile(const std::string& fileName);

  void Read();

  // Begin/end functions to make the file store operate like a std container
  const std::vector<ImageData>::const_iterator begin() const;
  std::vector<ImageData>::iterator begin();
  const std::vector<ImageData>::const_iterator end() const;
  std::vector<ImageData>::iterator end();

private:

  std::string root_dir_;
  std::string time_stamp_filename_;
  std::vector<ImageData> image_data_;
};
}
#endif