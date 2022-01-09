#include "rotate.h"
#include "image.h"
#include "exception.h"

#include <iostream>
#include <sstream>
#include <fstream>
using std::ostringstream;
using std::endl;
using std::ifstream;

Rotate::Rotate(Image *img) : Decorator{img} {}


void Rotate::render(PPM &ppm) {

    // first render the existing image
    img->render(ppm);

     // get all the pixels from ppm
    std::vector<Pixel> &pixels = ppm.getPixels();
    // get the width and height from original ppm
    int &width = ppm.getWidth();
    int &height = ppm.getHeight();

    // create a temp vector of pixels to store the transformed pixels
    std::vector<Pixel> tempPixels;

    // Modifies the internal representation (PPM) so that it now represents an image that has been rotated 90
    // clockwise. If i is the column index and j is the row index of a pixel in the rotated image, then the following will give
    // the required values for the new pixels, where ppm contains the current image.
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            tempPixels.emplace_back(pixels[width * (height - j - 1) + i]);
        }
    }

    // swap the width and length for the new image
    int tmpWidth = width;
    width = height;
    height = tmpWidth;
    
    // assign the tempPixels to be the new pixels for img, this transformation completed
    pixels = tempPixels;
}
