#include "vis/display.h"
#include "vis/rgb_image_window.h"
#include "cv/image_file_store.h"
#include "cv/io.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("No input image provided \n");
    printf("\t Usage: ./display_image <image_name>\n");
    printf("\t only works on RGB images\n");
    return 1;
  }
  std::string file_dir(argv[1]);
  cv::ImageFileStore image_store(file_dir);

  image_store.Read();
}