/*
*   ProjectName
*   (c)2021 Trevor D. Brown. All rights reserved.
*   Distributed under the MIT license.
*
*   Template.h - a template header file for C applications.
*
*   History:
*   12/23/2021 - Trevor D. Brown
*   - Create template file for PersonalStandards repository.
*/

/*
*   Declare imports here.
*   Imports are other header files that are associated with external libraries.
*/
#include <stdlib.h> // Standard Library
#include <stdio.h>  // Standard I/O
#include <errno.h>  // Errors
#include <string.h> // Strings

/* 
*   Declare macros to be used by the file here.
*   Macros are useful for constants and other values that could benefit from reuse. 
*   Macros should be named in all capital letters.
*   Macro names containing multiple words are typed with underscores as spaces.
*/
#define SIMPLE "A Macro"
#define ANOTHER_MACRO 9001

/*
*   Declare function signatures here.
*   These are useful for determining with function are publicly accessible by other source files.
*   The main Function is always required.
*   Function names containing multiple words are typed in camelCase. 
*/
int main(int argc, char *argv[]);

// Some functions return a primitive value.
char aFunctionThatReturnsACharacter();

// Some functions do not return anything.
void aFunctionWithMultipleWordsInName();