#include <stdio.h>

struct Student {
    int id;
    char name[100];
    float score;
};

float mean(float arr[], int n) {
    int i;
    float sum;
    sum = 0;

    for (i=0;i<n;i++) {
        sum += arr[i];
    }
    return (float)sum/n;
}

int main() {
    int i,n;
    struct Student students[100];
    float scores[100];
    float mean_score;

    //input
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &students[i].id);
        scanf("%s", &students[i].name);
        scanf("%f", &students[i].score);
    }
    for (i=0;i<n;i++) {
        scores[i] = students[i].score;
    }
    
    //calculation
    mean_score = mean(scores, n);
    printf("Average Score: %.1f\n", mean_score);

    //file output
    FILE *fp = fopen("students.txt", "w");
    for (i=0;i<n;i++) {
        fprintf(fp, "%d %s %.2f\n", students[i].id, students[i].name, students[i].score);
    }
    fclose(fp);
    return 0;
} 
