#include <stdio.h>

double allo_calc(int salary, double allo_perc) {
    return salary * allo_perc;
}

double gross_calc(int salary, double house, double med, double mil, double util) {
    return salary + house + med + mil + util;
}

double tax_calc(double salary, double tax_perc) {
    return salary * tax_perc;
}

int main() {
    char job;
    int salary;

    double house_all = 0.25;  // 25% for house allowance
    double med_all = 0.085;   // 8.5% for medical allowance
    double mil_all = 0.037;   // 3.7% for monthly mileage allowance
    double util_all = 0.072;  // 7.2% for utilities allowance

    printf("Please Enter your Code: ");
    scanf("%c", &job);

    switch (job) {
        case 'C':
            salary = 5000;
            break;
        case 'D':
            salary = 4800;
            break;
        case 'M':
            salary = 3950;
            break;
        case 'S':
            salary = 3100;
            break;
        case 'T':
            salary = 2800;
            break;
        case 'R':
            salary = 1450;
            break;
        case 'B':
            salary = 1770;
            break;
        default:
            printf("Invalid job code entered.\n");
            return 1; // Exit the program with an error code
    }

    double gross_salary = gross_calc(salary, allo_calc(salary, house_all), allo_calc(salary, med_all), allo_calc(salary, mil_all), allo_calc(salary, util_all));
    double tax_rate;

    if (gross_salary > 5500) {
        tax_rate = 0.14;
    } else if (gross_salary > 5000) {
        tax_rate = 0.12;
    } else if (gross_salary > 4500) {
        tax_rate = 0.10;
    } else if (gross_salary > 4000) {
        tax_rate = 0.08;
    } else {
        tax_rate = 0.06;
    }

    double tax_amount = tax_calc(gross_salary, tax_rate);
    double net_salary = gross_salary - tax_amount;

    // Display the results with consistent indentation
    printf("SALARY INFORMATION");
    printf("\n-----------------------------\n");
    printf("-----------------------------\n");
    printf("Basic Salary:        %10d\n", salary);
    printf("House Rent Allowance:%10.2f\n", allo_calc(salary, house_all));
    printf("Medical Allowance:   %10.2f\n", allo_calc(salary, med_all));
    printf("Mileage Allowance:   %10.2f\n", allo_calc(salary, mil_all));
    printf("Utilities Allowance: %10.2f\n", allo_calc(salary, util_all));
    printf("Gross Salary:        %10.2f\n", gross_salary);
    printf("Income Tax Amount:   %10.2f\n", tax_amount);
    printf("Net Monthly Salary:  %10.2f\n", net_salary);
    

    return 0; 
}