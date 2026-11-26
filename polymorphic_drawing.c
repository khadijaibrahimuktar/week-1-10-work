#include <stdio.h>

struct Shape {
    void (*draw)(void);
};

struct Circle {
    struct Shape base;
};

struct Rectangle {
    struct Shape base;
};

struct Triangle {
    struct Shape base;
};

void drawCircle(void) {
    printf("Drawing a Circle\n");
}

void drawRectangle(void) {
    printf("Drawing a Rectangle\n");
}

void drawTriangle(void) {
    printf("Drawing a Triangle\n");
}

void renderCanvas(const struct Shape *shapePtr) {
    shapePtr->draw();
}

int main(void) {
    struct Circle c1 = {{drawCircle}};
    struct Rectangle r1 = {{drawRectangle}};
    struct Triangle t1 = {{drawTriangle}};
    struct Circle c2 = {{drawCircle}};

    const struct Shape *canvas[4];
    canvas[0] = (const struct Shape *)&c1;
    canvas[1] = (const struct Shape *)&r1;
    canvas[2] = (const struct Shape *)&t1;
    canvas[3] = (const struct Shape *)&c2;

    printf("--- Rendering Canvas ---\n");
    for (int i = 0; i < 4; i++) {
        renderCanvas(canvas[i]);
    }

    return 0;
}
