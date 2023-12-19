#include <stdio.h>
#include <gd.h>

void drawTaiChi(gdImagePtr img, int x, int y, int radius, int red, int green, int blue);

int main() {
    int width = 400;
    int height = 400;

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    int white = gdImageColorAllocate(img, 255, 255, 255);
    int blue = gdImageColorAllocate(img, 0, 0, 255);
    int red = gdImageColorAllocate(img, 255, 0, 0);

    // Fill the background with white
    gdImageFilledRectangle(img, 0, 0, width - 1, height - 1, white);

    // Draw the Tai Chi symbol
    drawTaiChi(img, width / 2, height / 2, 50, red, 0, 0);

    FILE *outputFile = fopen("tai_chi.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}

void drawTaiChi(gdImagePtr img, int x, int y, int radius, int red, int green, int blue) {
    // Draw blue circle
    gdImageFilledEllipse(img, x, y, radius * 2, radius * 2, blue);

    // Draw red half of Tai Chi symbol
    gdImageFilledArc(img, x, y, radius * 2, radius * 2, 90, 270, red, gdChord);

    // Draw white half of Tai Chi symbol
    gdImageFilledArc(img, x, y, radius * 2, radius * 2, 270, 450, 255, gdChord);
}
