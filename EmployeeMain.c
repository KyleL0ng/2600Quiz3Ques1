// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c

// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    // defined in EmployeeOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);

    // defined in employeeTable.c
    extern Employee EmployeeTable[]; // extern means that it was defined somewhere else, so do not allocate space for it here
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration -- ptrToEmployee (points to the struct)
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found

    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    return EXIT_SUCCESS;
}