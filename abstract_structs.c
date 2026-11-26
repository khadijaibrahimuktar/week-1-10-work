#include <stdio.h>

struct Shape {
    double (*calculateArea)(void *derivedShape);
};

struct Square {
    struct Shape base;
    double side;
};

struct Circle {
    struct Shape base;
    double radius;
};

double squareArea(void *shapePtr) {
    const struct Square *square = shapePtr;
    return square->side * square->side;
}

double circleArea(void *shapePtr) {
    const struct Circle *circle = shapePtr;
    return 3.14159 * circle->radius * circle->radius;
}

int main(void) {
    struct Square sq;
    sq.side = 5.0;
    sq.base.calculateArea = squareArea;

    struct Circle circ;
    circ.radius = 3.0;
    circ.base.calculateArea = circleArea;

    printf("Area of Square: %.2f\n", sq.base.calculateArea(&sq));
    printf("Area of Circle: %.2f\n", circ.base.calculateArea(&circ));

    return 0;
}
