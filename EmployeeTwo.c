#include <string.h>
#include "employee.h"

// NOTE: 5 functions have been defined below
// ptr - points to table to be searched
// tableSize - size of the table
// targetPtr - points to value that will be searched for in table
// functionPtr - points to a comparison function below and will perform the associated check

// What does setting a function to static do? -- Only usable within this file, nobody else can use this in another file
// functionPtr is the address of the function just use the name
//()(The second set of parentheses is the arguments of the function call)

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr,
                                         int (*functionPtr)(const void *, PtrToConstEmployee))
                                         //Tells what function to call //Parameters for that function
{
    PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
        if ((*functionPtr)(targetPtr, ptr) == 0)
            return (PtrToEmployee)ptr;
    return NULL;
}

// The functionPtr will point to one of these comparison functions to perform a check

static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return *(long *)targetPtr != tableValuePtr->number;
    // const void *targetPtr ==> typecast as int pointer then dereference
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *)targetPtr, tableValuePtr->name); // const void *targetPtr ==> typecast as char pointer then pass into strcmp()
}

// These are called wrappers. These functions are what you will use in your main!!!

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number) //Calls another function, passes number
{
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber); //Want to compare by number
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char *name) //Calls same function, passes name
{
    return searchEmployeeTable(ptr, size, name, compareEmployeeName); //Want to compare by name
}