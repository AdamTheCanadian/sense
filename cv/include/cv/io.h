#ifndef __ATC_CV_IO_H__
#define __ATC_CV_IO_H__

#include "cv/image.h"

namespace cv {

/**
 * @brief Read an image from a given file name
 * 
 * @param f full path of the image (/my/directory/to/image.png)
 * @return RgbImage 
 */
RgbImage img_read(const char* f);

}
#endif