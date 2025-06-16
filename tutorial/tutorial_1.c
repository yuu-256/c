#include <stdio.h>

int main() {
    
    // input
    int a;
    scanf("%d", &a);

    // output
    if (a>0) {
        if (a%2 == 0) {
            printf("Positive even\n");
        } else {
            printf("Positive odd\n");
        }
    } else if (a<0) {
        printf("Negative\n");
    } else {
        printf("Zero\n");
    }

    return 0;
}
