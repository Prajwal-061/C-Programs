#include <stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    char designation[30];
    float basic_salary;
    float hra;
    float da;
};

float GrossSalary(float basic_salary, float hra, float da) {
    float hra_amount = (hra / 100) * basic_salary;
    float da_amount = (da / 100) * basic_salary;
    float final_salary = basic_salary + hra_amount + da_amount;
    return  final_salary;
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];
    
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &emp[i].emp_id);

        printf("Name: ");
        scanf("%s", &emp[i].name);  

        printf("Designation: ");
        scanf("%s", &emp[i].designation); 

        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);

        printf("HRA Percentage: ");
        scanf("%f", &emp[i].hra);

        printf("DA Percentage: ");
        scanf("%f", &emp[i].da);
    }
    
    printf("\nEmployee Details:\n");

    for (int i = 0; i < n; i++) {

        float final_salary = GrossSalary(emp[i].basic_salary, emp[i].hra, emp[i].da);
        
        printf("\nEmployee ID: %d\nName: %s\nDesignation: %s\nBasic Salary: %f\nHRA Percentage: %f\nDA Percentage: %f\nGross Salary: %f\n",emp[i].emp_id, emp[i].name, emp[i].designation, emp[i].basic_salary, emp[i].hra, emp[i].da, final_salary);
    }
    
    return 0;
}
