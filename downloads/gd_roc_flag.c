#include <stdio.h>
#include <gd.h>
#include <math.h>

// 定義座標結構
typedef struct {
    double x;
    double y;
} Point;

void draw_roc_flag(gdImagePtr img);
void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color);

// 計算圓與線的交點
void circleLineIntersection(double h, double k, double r, double x1, double y1, double x2, double y2);

int main() {
    // 設定圖片寬度和高度
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_roc_flag(img);

    FILE *outputFile = fopen("roc_flag_in_gd.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_roc_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white, blue;
    int center_x = (int)(width / 4);
    int center_y = (int)(height / 4);
    int sun_radius = (int)(width / 8);
    int white_circle_dia = sun_radius;
    int blue_circle_dia = white_circle_dia + white_circle_dia * 2 / 15;
    red = gdImageColorAllocate(img, 255, 0, 0);
    white = gdImageColorAllocate(img, 255, 255, 255);
    blue = gdImageColorAllocate(img, 0, 0, 149);

    gdImageFilledRectangle(img, 0, 0, width, height, red);
    gdImageFilledRectangle(img, 0, 0, (int)(width / 2.0), (int)(height / 2.0), blue);

    draw_white_sun(img, center_x, center_y, sun_radius, white);

    gdImageFilledEllipse(img, center_x, center_y, blue_circle_dia, blue_circle_dia, blue);
    gdImageFilledEllipse(img, center_x, center_y, white_circle_dia, white_circle_dia, white);

    // 連接第二組ABED的白線
    int ax = 429;
    int ay = 125;
    int bx = 279;
    int by = 165;
    int ex = 170;
    int ey = 274;
    int dx = 170;
    int dy = 274;

    // 設定線條寬度
    gdImageSetThickness(img, 3);

    gdImageLine(img, ax, ay, bx, by, white);
    gdImageLine(img, bx, by, ex, ey, white);
    gdImageLine(img, ex, ey, dx, dy, white);
    gdImageLine(img, dx, dy, ax, ay, white);

    // 新增連線 (ax, ay) 到 (dx, dy)
    gdImageLine(img, ax, ay, dx, dy, white);

    // 恢復預設線條寬度
    gdImageSetThickness(img, 1);

    // 利用一個藍色大圓與白色小圓畫出藍色環狀
    gdImageFilledEllipse(img, center_x, center_y, blue_circle_dia, blue_circle_dia, blue);
    gdImageFilledEllipse(img, center_x, center_y, white_circle_dia, white_circle_dia, white);

    // 圓的參數
    double circle_x = (int)(width / 4); // 圓心 x 座標
    double circle_y = (int)(height / 4); // 圓心 y 座標
    double radius = white_circle_dia + white_circle_dia * 2 / 15; // 圓半徑

    // 兩點座標
    double x3 = 170;
    double y3 = 274;
    double x4 = 279;
    double y4 = 165;

    // 計算圓與線段 (x3, y3) 到 (x4, y4) 的交點
    circleLineIntersection(circle_x, circle_y, radius, x4, y4, x3, y3);

    double x5 = 279;
    double y5 = 165;
    double x6 = 429;
    double y6 = 125;

    // 計算圓與線段 (x6, y6) 到 (x5, y5) 的交點
    circleLineIntersection(circle_x, circle_y, radius, x6, y6, x5, y5);
}

void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color) {
    float deg = M_PI / 180;
    float sr = sun_radius / tan(75 * deg);
    int ax, ay, bx, by, dx, dy, ex, ey;
    gdPoint points[4];

    ax = center_x;
    ay = center_y - sun_radius;
    bx = center_x - sun_radius * tan(15 * deg);
    by = center_y;
    ex = center_x;
    ey = center_y + sun_radius;
    dx = center_x + sun_radius * tan(15 * deg);
    dy = center_y;

    for (int i = 1; i <= 6; i++) {
        points[0].x = ax + sun_radius * sin(30 * deg * i);
        points[0].y = ay + sun_radius - sun_radius * cos(30 * deg * i);

        points[1].x = bx + sr - sr * cos(30 * deg * i);
        points[1].y = by - sr * sin(30 * deg * i);

        points[2].x = ex - sun_radius * sin(30 * deg * i);
        points[2].y = ey - (sun_radius - sun_radius * cos(30 * deg * i));

        points[3].x = dx - (sr - sr * cos(30 * deg * i));
        points[3].y = dy + sr * sin(30 * deg * i);

        gdImageFilledPolygon(img, points, 4, color);
        gdImagePolygon(img, points, 4, color);
    }
}

void circleLineIntersection(double h, double k, double r, double x1, double y1, double x2, double y2) {
    double m = (y2 - y1) / (x2 - x1);
    double b = y1 - m * x1;
    double A = 1 + pow(m, 2);
    double B = 2 * (m * b - m * k - h);
    double C = pow(k, 2) - pow(r, 2) + pow(h, 2) - 2 * b * k + pow(b, 2);

    double discriminant = pow(B, 2) - 4 * A * C;
    if (discriminant > 0) {
        double x_intersect1 = (-B + sqrt(discriminant)) / (2 * A);
        double y_intersect1 = m * x_intersect1 + b;
        printf("交點: (%.2f, %.2f)\n", x_intersect1, y_intersect1);

        double x_intersect2 = (-B - sqrt(discriminant)) / (2 * A);
        double y_intersect2 = m * x_intersect2 + b;
        printf("交點: (%.2f, %.2f)\n", x_intersect2, y_intersect2);
    } else if (discriminant == 0) {
        double x_intersect = -B / (2 * A);
        double y_intersect = m * x_intersect + b;
        printf("交點: (%.2f, %.2f)\n", x_intersect, y_intersect);
    } else {
        printf("No points.\n");
    }
}
