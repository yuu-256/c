#include <stdio.h>
#include <string.h>

char *find_longest_name(char namelist[][100], int size) {
    char *longestname = namelist[0];
    for (int i = 0; i < size; i++) {
        if (strlen(longestname) < strlen(namelist[i])) {
            longestname = namelist[i];
        }
    }
    return longestname;
}

int main() {
    int listsize;
    char namelist[100][100];
    scanf("%d", &listsize);
    for (int i = 0; i < listsize; i++) {
        scanf("%s", namelist[i]);
    }

    char *name_max = find_longest_name(namelist, listsize);
    printf("The longest name is: %s\n", name_max);
    printf("Length: %d\n", listsize);
    return 0;
}
