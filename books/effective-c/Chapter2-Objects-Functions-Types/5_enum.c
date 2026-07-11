#include <stdio.h>

// Pay attention to the typedef example and compare it to the regular ones.

enum day { sun, mon, tue, wed, thu, fri, sat };
enum cardinal_points { north = 0, east = 90, south = 180, west = 270 };
typedef enum { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec } months;

int main(void) {
    enum day a_day = sun;
    printf("%d\n", a_day);
    printf("%d\n", tue);

    enum cardinal_points point = east;
    printf("%d\n", point);

    months month = aug;
    printf("%d\n", month);
}