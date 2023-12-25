#include <stdio.h>
#include <gd.h>
#include <math.h>

// 定義座標結構
typedef struct {
    double x;
    double y;
} Point;

void rotateFilledPolygon(gdImagePtr img, int centerX, int centerY, double angle, gdPoint *points, int numPoints, int color);

int main() {
    int width = 800;
    int height = 600;

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    int red = gdImageColorAllocate(img, 255, 0, 0);
    int blue = gdImageColorAllocate(img, 0, 0, 255);
    int black = gdImageColorAllocate(img, 0, 0, 0);
    int white = gdImageColorAllocate(img, 255, 255, 255);

    // 長方形塗色
    gdImageFilledRectangle(img, 0, 0, width, height, white);
    gdImageFilledRectangle(img, 0, 0, (int)width / 4, (int)height / 4, blue);

    // 橢圓形塗色
    gdImageFilledEllipse(img, (int)width * 3 / 4, (int)height / 4, (int)width / 4, (int)width / 4, red);

    // 橢圓形畫線
    gdImageEllipse(img, (int)width * 3 / 4, (int)height * 3 / 4, (int)width / 4, (int)width / 4, red);

    // 畫直線
    gdImageLine(img, (int)width / 2, (int)height / 2, (int)width / 2, (int)height / 2 + 100, blue);

    // 多邊形畫線
    gdPoint points[4];
    points[0].x = (int)width / 4;
    points[0].y = (int)height * 3 / 4;
    points[1].x = points[0].x + 100;
    points[1].y = points[0].y;
    points[2].x = points[1].x;
    points[2].y = points[1].y + 100;
    points[3].x = points[2].x - 100;
    points[3].y = points[2].y;
    gdImagePolygon(img, points, 4, black);

    // 多邊形塗色
    gdPoint points2[4];
    points2[0].x = (int)width / 3;
    points2[0].y = (int)height / 2;
    points2[1].x = points2[0].x + 100;
    points2[1].y = points2[0].y;
    points2[2].x = points2[1].x;
    points2[2].y = points2[1].y + 100;
    points2[3].x = points2[2].x - 150;
    points2[3].y = points2[2].y;
    gdImageFilledPolygon(img, points2, 4, red);

    // 旋轉多邊形並保存每次旋轉後的圖形
    for (int i = 0; i < 12; i++) {
        char filename[50];
        sprintf(filename, "rotated_image_%02d.png", i + 1);

        gdImagePtr rotatedImg = gdImageCreateTrueColor(width, height);
        gdImageAlphaBlending(rotatedImg, 0);

        // 複製原始圖形
        gdImageCopy(rotatedImg, img, 0, 0, 0, 0, width, height);

        // 旋轉多邊形
        rotateFilledPolygon(rotatedImg, 500, 200, 30.0, points2, 4, red);

        // 儲存圖形
        FILE *outputFile = fopen(filename, "wb");
        if (outputFile == NULL) {
            fprintf(stderr, "Error opening the output file.\n");
            return 1;
        }
        gdImagePngEx(rotatedImg, outputFile, 9);
        fclose(outputFile);
        gdImageDestroy(rotatedImg);
    }

    // 釋放主圖形的記憶體
    gdImageDestroy(img);

    return 0;
}

void rotateFilledPolygon(gdImagePtr img, int centerX, int centerY, double angle, gdPoint *points, int numPoints, int color) {
    float radian = (float)(angle * M_PI / 180.0);
    float cosA = cos(radian);
    float sinA = sin(radian);

    gdPoint rotatedPoints[numPoints];

    for (int i = 0; i < numPoints; i++) {
        int translatedX = points[i].x - centerX;
        int translatedY = points[i].y - centerY;

        rotatedPoints[i].x = centerX + round(translatedX * cosA - translatedY * sinA);
        rotatedPoints[i].y = centerY + round(translatedX * sinA + translatedY * cosA);
    }

    gdImageFilledPolygon(img, rotatedPoints, numPoints, color);
}
