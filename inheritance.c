#include <stdio.h>
#include <string.h>

struct Shape {
    char color[20];
};

struct Circle {
    struct Shape base;
    double radius;
};

int main(void) {
    struct Circle myCircle;

    snprintf(myCircle.base.color, sizeof myCircle.base.color, "%s", "Red");
    myCircle.radius = 5.0;

    printf("Circle Color (Inherited): %s\n", myCircle.base.color);
    printf("Circle Radius (Specific): %.2f\n", myCircle.radius);

    return 0;
}
