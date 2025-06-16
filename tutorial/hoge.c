#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a); // &a is the address of a
    printf("入力値は %d です\n", a);
    if (a > 0) {
        printf("a is positive\n");
    } else if (a < 0) {
        printf("a is negative\n");
    } else {
        printf("a is zero\n");
    }
    return 0;
}
