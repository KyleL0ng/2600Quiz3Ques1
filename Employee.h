#include <stdio.h> 
#include <stddef.h> 

typedef struct { 
    long number; 
    char *name; 
    char *phone; 
    double salary; 
} Employee, *PtrToEmployee; //Each variable is 8 bytes, so 32 total
typedef const Employee *PtrToConstEmployee; //PtrToConstEmployee points to this struct