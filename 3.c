#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

typedef struct {
    int shapeType;
    union {
        float radius;
        struct {
            float length;
            float width;
        };
        struct {
            float base;
            float height;
        };
    } dimension;
} Shape;

int main() {
    Shape s;
    scanf("%d", &s.shapeType);

    switch (s.shapeType) {
        case 1:
            scanf("%f", &s.dimension.radius);
            printf("%.2f", M_PI * s.dimension.radius * s.dimension.radius);
            break;
        
        case 2:
            scanf("%f %f", &s.dimension.length, &s.dimension.width);
            printf("%.2f", s.dimension.length * s.dimension.width);
            break;

        case 3:
            scanf("%f %f", &s.dimension.height, &s.dimension.base);
            printf("%.2f", 0.5 * s.dimension.height * s.dimension.base);
            break;
    }

    return 0;
}
