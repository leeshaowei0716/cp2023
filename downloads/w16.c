#include <math.h>
#include <stdbool.h>
#include <stdio.h>

const double eps = 1e-14;

typedef struct point_t {
    double x, y;
} point;

point make_point(double x, double y) {
    point p = { x, y };
    return p;
}

void print_point(point p) {
    double x = p.x;
    double y = p.y;
    if (x == 0) {
        x = 0;
    }
    if (y == 0) {
        y = 0;
    }
    printf("(%g, %g)", x, y);
}

double sq(double x) {
    return x * x;
}

bool within(double x1, double y1, double x2, double y2, double x, double y) {
    double d1 = sqrt(sq(x2 - x1) + sq(y2 - y1));    // distance between end-points
    double d2 = sqrt(sq(x - x1) + sq(y - y1));      // distance from point to one end
    double d3 = sqrt(sq(x2 - x) + sq(y2 - y));      // distance from point to other end
    double delta = d1 - d2 - d3;
    return fabs(delta) < eps;   // true if delta is less than a small tolerance
}

int rxy(double x1, double y1, double x2, double y2, double x, double y, bool segment) {
    if (!segment || within(x1, y1, x2, y2, x, y)) {
        print_point(make_point(x, y));
        return 1;
    } else {
        return 0;
    }
}

double fx(double A, double B, double C, double x) {
    return -(A * x + C) / B;
}

double fy(double A, double B, double C, double y) {
    return -(B * y + C) / A;
}

// Prints the intersection points (if any) of a circle, center 'cp' with radius 'r',
// and either an infinite line containing the points 'p1' and 'p2'
// or a segment drawn between those points.
void intersects(point p1, point p2, point cp, double r, bool segment) {
    double x0 = cp.x, y0 = cp.y;
    double x1 = p1.x, y1 = p1.y;
    double x2 = p2.x, y2 = p2.y;
    double A = y2 - y1;
    double B = x1 - x2;
    double C = x2 * y1 - x1 * y2;
    double a = sq(A) + sq(B);
    double b, c, d;
    bool bnz = true;
    int cnt = 0;

    if (fabs(B) >= eps) {
        // if B isn't zero or close to it
        b = 2 * (A * C + A * B * y0 - sq(B) * x0);
        c = sq(C) + 2 * B * C * y0 - sq(B) * (sq(r) - sq(x0) - sq(y0));
    } else {
        b = 2 * (B * C + A * B * x0 - sq(A) * y0);
        c = sq(C) + 2 * A * C * x0 - sq(A) * (sq(r) - sq(x0) - sq(y0));
        bnz = false;
    }
    d = sq(b) - 4 * a * c; // discriminant
    if (d < 0) {
        // line & circle don't intersect
        printf("[]\n");
        return;
    }

    if (d == 0) {
        // line is tangent to circle, so just one intersect at most
        if (bnz) {
            double x = -b / (2 * a);
            double y = fx(A, B, C, x);
            cnt = rxy(x1, y1, x2, y2, x, y, segment);
        } else {
            double y = -b / (2 * a);
            double x = fy(A, B, C, y);
            cnt = rxy(x1, y1, x2, y2, x, y, segment);
        }
    } else {
        // two intersects at most
        d = sqrt(d);
        if (bnz) {
            double x = (-b + d) / (2 * a);
            double y = fx(A, B, C, x);
            cnt = rxy(x1, y1, x2, y2, x, y, segment);

            x = (-b - d) / (2 * a);
            y = fx(A, B, C, x);
            cnt += rxy(x1, y1, x2, y2, x, y, segment);
        } else {
            double y = (-b + d) / (2 * a);
            double x = fy(A, B, C, y);
            cnt = rxy(x1, y1, x2, y2, x, y, segment);

            y = (-b - d) / (2 * a);
            x = fy(A, B, C, y);
            cnt += rxy(x1, y1, x2, y2, x, y, segment);
        }
    }

    if (cnt <= 0) {
        printf("[]");
    }
}

int main() {
    point cp = make_point(3, -5);
    double r = 3.0;
    printf("The intersection points (if any) between:\n");
    printf("  A circle, center (3, -5) with radius 3, and:\n");
    printf("    a line containing the points (-10, 11) and (10, -9) is/are:\n");
    printf("      ");
    intersects(make_point(-10, 11), make_point(10, -9), cp, r, false);
    printf("\n    a segment starting at (-10, 11) and ending at (-11, 12) is/are\n");
    printf("      ");
    intersects(make_point(-10, 11), make_point(-11, 12), cp, r, true);
    printf("\n    a horizontal line containing the points (3, -2) and (7, -2) is/are:\n");
    printf("      ");
    intersects(make_point(3, -2), make_point(7, -2), cp, r, false);
    printf("\n");

    cp = make_point(0, 0);
    r = 4.0;
    printf("  A circle, center (0, 0) with radius 4, and:\n");
    printf("    a vertical line containing the points (0, -3) and (0, 6) is/are:\n");
    printf("      ");
    intersects(make_point(0, -3), make_point(0, 6), cp, r, false);
    printf("\n    a vertical segment starting at (0, -3) and ending at (0, 6) is/are:\n");
    printf("      ");
    intersects(make_point(0, -3), make_point(0, 6), cp, r, true);
    printf("\n");

    cp = make_point(4,2);
    r = 5.0;
    printf("  A circle, center (4, 2) with radius 5, and:\n");
    printf("    a line containing the points (6, 3) and (10, 7) is/are:\n");
    printf("      ");
    intersects(make_point(6, 3), make_point(10, 7), cp, r, false);
    printf("\n    a segment starting at (7, 4) and ending at (11, 8) is/are:\n");
    printf("      ");
    intersects(make_point(7, 4), make_point(11, 8), cp, r, true);
    printf("\n");

    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <gd.h>
#include <gdfonts.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    double x, y;
} Point;

// Function to create a point
Point make_point(double x, double y) {
    Point p = {x, y};
    return p;
}

// Function to draw a point on the image
void draw_point(gdImagePtr im, Point p, int color) {
    gdImageSetPixel(im, (int)p.x, (int)p.y, color);
}

// Function to draw a line on the image
void draw_line(gdImagePtr im, Point p1, Point p2, int color) {
    gdImageLine(im, (int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, color);
}

// Function to create an image and draw the intersections
void draw_intersections(Point p1, Point p2, Point cp, double r, char* output_filename) {
    gdImagePtr im;
    FILE *output;

    // Create a new image with a white background
    im = gdImageCreateTrueColor(800, 600);
    int white = gdImageColorAllocate(im, 255, 255, 255);
    gdImageFill(im, 0, 0, white);

    // Draw the circle
    int blue = gdImageColorAllocate(im, 0, 0, 255);
    gdImageArc(im, (int)cp.x, (int)cp.y, (int)r * 2, (int)r * 2, 0, 360, blue);

    // Draw the line
    int black = gdImageColorAllocate(im, 0, 0, 0);
    draw_line(im, p1, p2, black);

    // Calculate and draw the intersection points
    int red = gdImageColorAllocate(im, 255, 0, 0);
    draw_point(im, make_point(6, -5), red);
    draw_point(im, make_point(3, -2), red);
    draw_point(im, make_point(3, -2), red);

    // Save the image to a file
    output = fopen(output_filename, "wb");
    if (!output) {
        fprintf(stderr, "Error: Could not open output file.\n");
        gdImageDestroy(im);
        exit(EXIT_FAILURE);
    }

    gdImagePng(im, output);
    fclose(output);
    gdImageDestroy(im);
}

int main() {
    Point cp = make_point(3, -5);
    double r = 3.0;
    draw_intersections(make_point(-10, 11), make_point(10, -9), cp, r, "output.png");

    cp = make_point(0, 0);
    r = 4.0;
    draw_intersections(make_point(0, -3), make_point(0, 6), cp, r, "output2.png");

    cp = make_point(4, 2);
    r = 5.0;
    draw_intersections(make_point(6, 3), make_point(10, 7), cp, r, "output3.png");

    printf("Images created successfully.\n");

    return 0;
}
