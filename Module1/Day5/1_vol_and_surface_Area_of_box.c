#include <stdio.h>
struct Box {
    double length;
    double width;
    double height;
};
void calculateVolume(struct Box* box) {
    double volume = box->length * box->width * box->height;
    printf("Volume: %.2f\n", volume);
}
void calculateSurfaceArea(struct Box* box) {
    double surfaceArea = 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
    printf("Total Surface Area: %.2f\n", surfaceArea);
}
int main() {
    struct Box myBox;
    struct Box* boxPtr = &myBox;
    printf("Enter the length of the box: ");
    scanf("%lf", &(boxPtr->length));
    printf("Enter the width of the box: ");
    scanf("%lf", &(boxPtr->width));
    printf("Enter the height of the box: ");
    scanf("%lf", &(boxPtr->height));
    calculateVolume(boxPtr);
    calculateSurfaceArea(boxPtr);    
    return 0;
}
