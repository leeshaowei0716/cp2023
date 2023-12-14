#include <stdio.h>
#include <gd.h>
#include <stdlib.h>
#include <math.h>

void drawSouthKoreanFlag() {
    int width = 300;   // 寬度
    int height = 200;  // 高度
    int centerX = width / 2; // 中心X座標
    int centerY = height / 2; // 中心Y座標
    int outerRadius = 50;   // 外圈半徑
    int innerRadius = 20;   // 內圈半徑

    // 創建一個 24 位的彩色圖片
    gdImagePtr im = gdImageCreateTrueColor(width, height);

    // 設置背景色為白色
    int white = gdImageColorAllocate(im, 255, 255, 255);
    gdImageFill(im, 0, 0, white);

    // 設置藍色橢圓
    int blue = gdImageColorAllocate(im, 0, 0, 255);
    gdImageFilledEllipse(im, centerX, centerY, 2 * outerRadius, outerRadius, blue);

    // 設置紅色橢圓
    int red = gdImageColorAllocate(im, 255, 0, 0);
    gdImageFilledEllipse(im, centerX, centerY, 2 * outerRadius, innerRadius, red);

    // 設置太極圖案的顏色
    int black = gdImageColorAllocate(im, 0, 0, 0);
    int white2 = gdImageColorAllocate(im, 255, 255, 255);

    // 畫太極圖案
    gdImageFilledEllipse(im, centerX, centerY, 2 * outerRadius, 2 * outerRadius, black);
    gdImageFilledEllipse(im, centerX, centerY, 2 * innerRadius, 2 * innerRadius, white2);

    // 輸出圖片到檔案
    FILE *output = fopen("south_korean_flag.png", "wb");
    if (output == NULL) {
        fprintf(stderr, "Unable to open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    gdImagePng(im, output);

    // 釋放內存
    gdImageDestroy(im);
    fclose(output);
}

int main() {
    drawSouthKoreanFlag();
    printf("South Korean flag created: south_korean_flag.png\n");
    return 0;
}