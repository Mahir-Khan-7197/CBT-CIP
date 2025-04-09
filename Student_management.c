#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

struct Student {
    char name[50];
    int scores[MAX_SUBJECTS];
    float average;
    int highest;
    int lowest;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents, numSubjects;
    int i, j;

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    printf("Enter number of subjects: ");
    scanf("%d", &numSubjects);

    // Input student data
    for (i = 0; i < numStudents; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        students[i].highest = -1;
        students[i].lowest = 101;
        students[i].average = 0;

        for (j = 0; j < numSubjects; j++) {
            printf("Enter score for subject %d: ", j + 1);
            scanf("%d", &students[i].scores[j]);

            if (students[i].scores[j] > students[i].highest)
                students[i].highest = students[i].scores[j];
            if (students[i].scores[j] < students[i].lowest)
                students[i].lowest = students[i].scores[j];

            students[i].average += students[i].scores[j];
        }

        students[i].average /= numSubjects;
    }

    // Display results
    printf("\n=== Student Performance Summary ===\n");
    for (i = 0; i < numStudents; i++) {
        printf("\nName: %s\n", students[i].name);
        printf("Scores: ");
        for (j = 0; j < numSubjects; j++) {
            printf("%d ", students[i].scores[j]);
        }
        printf("\nAverage Score: %.2f", students[i].average);
        printf("\nHighest Score: %d", students[i].highest);
        printf("\nLowest Score: %d\n", students[i].lowest);
    }

    return 0;
}

