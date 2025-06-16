#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    float score;
};

float max(float arr[], int n) {
    float max_val = arr[0];
    for (int i = 0; i < n; i++) {
        if (max_val < arr[i]) {
            max_val = arr[i];
        }
    }
    return max_val;
}

float min(float arr[], int n) {
    float min_val = arr[0];
    for (int i = 0; i < n; i++) {
        if (min_val > arr[i]) {
            min_val = arr[i];
        }
    }
    return min_val;
}

float mean(float arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

int main() {
    // read file
    char filename[100];
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    struct Student *students = malloc(sizeof(struct Student) * 100);
    int n = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        n++;
    }
    rewind(fp);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d %s %f", &students[i].id, students[i].name, &students[i].score); 
    }
    fclose(fp);

    // calculate mean and max
    float *scores = malloc(sizeof(float)*n);
    for (int i = 0; i<n; i++) {
        scores[i] = students[i].score;
    }

    float mean_score = mean(scores, n);
    float max_score = max(scores, n);
    
    // print results
    printf("Average score: %.1f\n", mean_score);
    printf("Highest score: %.1f\n", max_score);

    // memmory free
    free(students);
    free(scores);
    return 0;
}
