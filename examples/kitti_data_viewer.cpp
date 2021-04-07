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

  vis::Display display("Kitti data set viewer", 1200, 800);
  uint32_t num_images = image_store.NumberOfImages();
  std::cout << "Num images " << num_images << std::endl;
  uint32_t count = 0;
  while (!display.Shutdown()) {
    if (count < num_images) {
      cv::RgbImage image = cv::img_read(image_store.GetImage(count).image_name.c_str());
      vis::RgbImageWindow rgb_window(&image, "RGB Image");
      rgb_window.Draw();
      count += 1;
    }
    else {
      break;
    }
    display.Update();
  }
}