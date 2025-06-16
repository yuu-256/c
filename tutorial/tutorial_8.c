#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[100];
    float score;
} Student;
    
void updata_student_score(Student *ps, int num_student, int target_id, float new_score) {
    for (int i=0; i<num_student; i++) {
        if ((ps+i)->id == target_id) {
            (ps+i)->score = new_score;
        }
    }
} 

void print_all_students(Student *ps, int num_student) {
    for (int i=0; i<num_student; i++) {
        printf("ID: %d, Name: %s, Score: %f\n", (ps+i)->id, (ps+i)->name, (ps+i)->score);
    }
}

int main() {
    int num_student;
    char filename[100];
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%d", &num_student);

    Student *students = (Student *)malloc(sizeof(Student)*num_student);
    Student *ps = students;
    for (int i=0;i<num_student;i++) {
        fscanf(fp, "%d %s %f", &students[i].id, students[i].name, &students[i].score);
    }
    fclose(fp);

    int target_id;
    float new_score;
    scanf("%d %f", &target_id, &new_score);
    print_all_students(ps, num_student);
    updata_student_score(ps, num_student, target_id, new_score);
    print_all_students(ps, num_student);
    free(students);
    return 0;
}
