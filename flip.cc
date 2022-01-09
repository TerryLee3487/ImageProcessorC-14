#include "flip.h"
#include "image.h"
#include "exception.h"

#include <iostream>
#include <sstream>
#include <fstream>
using std::ostringstream;
using std::endl;
using std::ifstream;

Flip::Flip(Image *img) : Decorator{img} {}


void Flip::render(PPM &ppm) {

    // first render the existing image
    img->render(ppm);

    // get all the pixels from ppm
    std::vector<Pixel> &pixels = ppm.getPixels();
    // get the width and height from original ppm
    int &width = ppm.getWidth();
    int &height = ppm.getHeight();
    
    // create a temp vector of pixels to store the transformed pixels
    std::vector<Pixel> tempPixels;

    // Modifies the internal representation (PPM) so that it now represents an image that has been flipped horizontally.
    // In other words, Pixel 1 of a row with n Pixels becomes Pixel n, Pixel 2 becomes Pixel n-1 and so on.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            tempPixels.emplace_back(pixels[i * width + (width - 1 - j)]);
        }
    }

    // assign the tempPixels to be the new pixels for img, this transformation completed
    pixels = tempPixels;
}
