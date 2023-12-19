#include <stdio.h>
#include <gd.h>

int main() {
    // Create a new GD image (French flag dimensions: 900x600)
    gdImagePtr im = gdImageCreateTrueColor(900, 600);

    // Define colors (RGB format)
    int blue = gdImageColorAllocate(im, 0, 0, 255);
    int white = gdImageColorAllocate(im, 255, 255, 255);
    int red = gdImageColorAllocate(im, 255, 0, 0);

    // Draw vertical stripes (3 equal-width stripes)
    int stripeWidth = 900 / 3;
    gdImageFilledRectangle(im, 0, 0, stripeWidth - 1, 599, blue);
    gdImageFilledRectangle(im, stripeWidth, 0, 2 * stripeWidth - 1, 599, white);
    gdImageFilledRectangle(im, 2 * stripeWidth, 0, 899, 599, red);

    // Save the image to a file
    FILE *outputFile = fopen("french_flag.png", "wb");
    gdImagePng(im, outputFile);
    fclose(outputFile);

    // Free the GD image
    gdImageDestroy(im);

    return 0;
}
