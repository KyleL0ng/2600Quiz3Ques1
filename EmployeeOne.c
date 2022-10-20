#include <string.h> 
#include "employee.h" 

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){ 
    const PtrToConstEmployee endPtr = ptr + tableSize; 
    for(; ptr < endPtr; ptr++)  //search until end of table  ptr++ will increment by 32 bytes each time, since each employee is 32 bytes
    { 
        if(ptr->number == targetNumber) //check if it equals the Employee number (-> dereferences number [gets value])
            return (PtrToEmployee) ptr; //return location of the number to callee. 
    } 
     return NULL;   //this will only happen if no Employee number matches in loop above 
} 

//Essentially the same functionality as above but comparing strings to check if equal 
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName){ 
    const PtrToConstEmployee endPtr = ptr + tableSize; //This is repeat code, which is bad for us
    for(; ptr < endPtr; ptr++) 
    { 
        if(strcmp(ptr->name,targetName) == 0) //Only thing that varies is how we do this check, everything else is the same
            return (PtrToEmployee) ptr; 
    } 
    return NULL; 
}