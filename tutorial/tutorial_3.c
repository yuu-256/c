#include <stdio.h>
#include <string.h>

int main() {

    //input
    char name[100];
    scanf("%s",name);

    //length
    int length = strlen(name);
    printf("%d\n", length);

    //Alice check
    if (strcmp(name, "Alice")==0) {
        printf("ようこそ、アリスさん！\n");
    } else {
        printf("こんにちは、%sさん\n", name);
    }
    return 0;
}



    

