# Computer Vision (CV)

Contains all functionality for working with images

## Design Philosphy

Main type is a `cv::Image<PixelT>`. It is a templated image class. This is different than most computer vision libraries which either 
  a) make images a matrix, 
  b) one continous array of bytes.   

The disadvantage, from a coding perspective of approach a) and b) is you have to have tests everywhere on what type of image you have. Do you have a grayscale image (1 channel), a 3 channel image but its in form YCbCr (or HSV), or is it RGB?

The fact is while all images (gray scale, RGB, etc.) are images... they are treated differently and used differently. Using a template approach we can easily create images of different types, and the code is explict on what image type its working with (cv::histogram_equalize(RgbImage img) takes an RGB image, not some matrix or array of bytes).


## Dependenices

- C++14
  - Using C++14 and above functionality
- GoogleTest
  - If running unit tests. If one does not want the unit tests can simply remove building of unit tests in CMakeLists.txt
- core/
  - For ASSERT(), part of the whole `sense` repo but if one moves `cv` out they will require `core`
- [stb_image](https://github.com/nothings/stb/blob/master/stb_image.h)
  - For reading and saving images
  - Copied the file over and so it is part of cv/ but wanted to make it clear that this is an external dependency.