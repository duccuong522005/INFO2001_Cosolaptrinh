#include <stdio.h>
#include <string.h>

#define EMPLOYEES 100

struct Employee {
    int empID;
    char name[50];
    char position[50];
    float salary;
};

struct Employee employees[EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount < EMPLOYEES) {
        printf("Enter employee ID: ");
        scanf("%d", &employees[employeeCount].empID);
        printf("Enter name: ");
        scanf("%s", employees[employeeCount].name);
        printf("Enter position: ");
        scanf("%s", employees[employeeCount].position);
        printf("Enter salary: ");
        scanf("%f", &employees[employeeCount].salary);

        employeeCount++;
        printf("Employee added successfully.\n");
    } else {
        printf("Employee database is full.\n");
    }
}

void displayEmployees() {
    printf("Employee List:\n");
    printf("ID\tName\tPosition\tSalary\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%d\t%s\t%s\t%.2f\n", employees[i].empID, employees[i].name, employees[i].position, employees[i].salary);
    }
}

void deleteEmployee(int empID) {
    int found = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].empID == empID) {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee with ID %d deleted.\n", empID);
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", empID);
    }
}

void sortEmployees() {
    struct Employee temp;
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = 0; j < employeeCount - i - 1; j++) {
            if (employees[j].empID > employees[j + 1].empID) {
                temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
    printf("Employees sorted by ID.\n");
}

int main() {
    int options, empID;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Sort Employees by ID\n");
        printf("5. Exit\n");
        printf("Enter your options: ");
        scanf("%d", &options);

        switch (options) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                printf("Enter employee ID to delete: ");
                scanf("%d", &empID);
                deleteEmployee(empID);
                break;
            case 4:
                sortEmployees();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid options. Please enter a valid options.\n");
        }
    }

    return 0;
}

