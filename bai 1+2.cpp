#include <stdio.h>
#include <string.h>

#define STUDENTS 100

struct Student {
    int id;
    char name[50];
    float score;
};

void displayStudent(struct Student student) {
    printf("ID: %d, Name: %s, Score: %.2f\n", student.id, student.name, student.score);
}

int main() {
    struct Student studentList[STUDENTS];
    int count = 0;
    int options;

    do {
        printf("1. Add Student\n2. Display Students\n3. Sort Students\n4. Search Students\n5. Exit\n");
        printf("Enter your options: ");
        scanf("%d", &options);

        switch (options) {
            case 1: {
                if (count < STUDENTS) {
                    printf("Enter ID: ");
                    scanf("%d", &studentList[count].id);
                    printf("Enter Name: ");
                    scanf("%s", studentList[count].name);
                    printf("Enter Score: ");
                    scanf("%f", &studentList[count].score);
                    count++;
                } else {
                    printf("Student list is full.\n");
                }
                break;
            }
            case 2: {
                printf("Student List:\n");
                for (int i = 0; i < count; ++i) {
                    displayStudent(studentList[i]);
                }
                break;
            }
            case 3: {
                for (int i = 0; i < count - 1; ++i) {
                    for (int j = 0; j < count - i - 1; ++j) {
                        if (strcmp(studentList[j].name, studentList[j + 1].name) > 0) {
                            struct Student temp = studentList[j];
                            studentList[j] = studentList[j + 1];
                            studentList[j + 1] = temp;
                        }
                    }
                }
                printf("Students sorted by name.\n");
                break;
            }
            case 4: {
                char searchName[50];
                printf("Enter Name to search: ");
                scanf("%s", searchName);

                int found = 0;
                for (int i = 0; i < count; ++i) {
                    if (strcmp(studentList[i].name, searchName) == 0) {
                        printf("Student found:\n");
                        displayStudent(studentList[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Student not found.\n");
                }
                break;
            }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid options. Please try again.\n");
        }
    } while (options != 5);

    return 0;
}

