#include "vis/display.h"
#include "vis/rgb_image_window.h"
#include "cv/io.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("No input image provided \n");
    printf("\t Usage: ./display_image <image_name>\n");
    printf("\t only works on RGB images\n");
    return 1;
  }
  cv::RgbImage image = cv::img_read(argv[1]);
  if (image.rows() == 0 || image.cols() == 0) {
    printf("Error reading image %s\n", argv[1]);
    return 1;
  }
  std::cout << "Read image " << argv[1] << "\n\t size: " <<
    image.rows() << "x" << image.cols() << std::endl;
  vis::Display display("My Window", 800, 600);
  vis::RgbImageWindow rgb_window(&image, "RGB Image");

  while (!display.Shutdown()) {
    
    rgb_window.Draw();
    display.Update();
  }
}