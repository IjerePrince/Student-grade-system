#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Grades(void);

int main(void)
{
    printf("*** STUDENT GRADE MANAGEMENT SYSTEM ***\n");
    Grades();
    return 0;
}

void Grades(void)
{
    int numStud;

    printf("\nEnter number of students: ");
    scanf("%d", &numStud);

    if (numStud <= 0)
    {
        printf("Invalid number of students.\n");
        return;
    }

    // clear input buffer
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    char names[numStud][50];

    for (int i = 0; i < numStud; i++)
    {
        printf("\nEnter name of student %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);

        size_t len = strlen(names[i]);
        if (len > 0 && names[i][len - 1] == '\n')
            names[i][len - 1] = '\0';
    }

    for (int s = 0; s < numStud; s++)
    {
        int numCourses;

        printf("\nEnter number of courses for %s: ", names[s]);
        scanf("%d", &numCourses);

        if (numCourses <= 0)
        {
            printf("Invalid number of courses.\n");
            return;
        }

        int *scores = (int *)malloc(numCourses * sizeof(int));
        if (scores == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        for (int c = 0; c < numCourses; c++)
        {
            do
            {
                printf("Enter score for course %d (0 - 100): ", c + 1);
                scanf("%d", &scores[c]);

                if (scores[c] < 0 || scores[c] > 100)
                    printf("Invalid score. Try again.\n");

            } while (scores[c] < 0 || scores[c] > 100);
        }

        printf("\nGrades for %s:\n", names[s]);

        for (int c = 0; c < numCourses; c++)
        {
            char grade;

            if (scores[c] >= 80)      grade = 'A';
            else if (scores[c] >= 70) grade = 'B';
            else if (scores[c] >= 60) grade = 'C';
            else if (scores[c] >= 50) grade = 'D';
            else if (scores[c] >= 40) grade = 'E';
            else                      grade = 'F';

            printf("Course %d: %c\n", c + 1, grade);
        }

        free(scores);   // free AFTER use
    }
}
