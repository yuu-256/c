#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[100];
    float score;
} Student;

int compare_score(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    return (s2->score > s1->score) - (s2->score < s1->score);
}

int main() {
    char filename[100];
    int num_student;

    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    fscanf(fp, "%d", &num_student);

    Student *students = (Student *)malloc(sizeof(Student) *num_student);
    for (int i=0; i<num_student; i++) {
        fscanf(fp, "%d %s %f", &students[i].id, students[i].name, &students[i].score);
    }
    fclose(fp);

    // sort
    qsort(students, num_student, sizeof(Student), compare_score);

    // out
    printf("Sorted by score: \n");
    for (int i = 0; i<num_student; i++) {
        printf("%d %s %f\n", students[i].id, students[i].name, students[i].score);
    }

    free(students);
    return 0;
}
