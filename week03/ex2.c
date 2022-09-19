#include <stdio.h>
#include <math.h>

struct Point
{
    double x, y;
};

double distance(struct Point* a, struct Point* b) {
    return sqrt((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y));
}

double area(struct Point* a, struct Point* b, struct Point* c) {
    return 0.5 * fabs(
        a->x * b->y -
        b->x * a->y +
        b->x * c->y -
        c->x * b->y +
        c->x * a->y -
        a->x * c->y
    );
}

int main() {
    struct Point A = {2.5, 6};
    struct Point B = {1, 2.2};
    struct Point C = {10, 6};

    double ab_dist = distance(&A, &B);
    double abc_area = area(&A, &B, &C);

    printf("%f %f", ab_dist, abc_area);
}