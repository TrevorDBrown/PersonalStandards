/*
*   ProjectName
*   (c)2021 Trevor D. Brown. All rights reserved.
*   Distributed under the MIT license.
*
*   Template.c - a template implementation file for C applications.
*
*   History:
*   12/23/2021 - Trevor D. Brown
*   - Create template file for PersonalStandards repository.
*/

/*
*   Imports and Macros are defined in the header.
*   Except for this file's associated header file.
*/
#import "Template.h"

// Some functions are only accessible within their respective file, and must be declared before public functions.
void aFunctionPrivateToThisFile(char aString[]){
    printf(aString);
}

// main is always required.
int main(int argc, char *argv[]){
    char aStringToPass[] = "Hello World!";
    aFunctionPrivateToThisFile(aStringToPass);
    return 0;
};

// Some functions do not return anything.
void aFunctionWithMultipleWordsInName(){
    // This function can do stuff without having to pass any data back to the calling function.
};

// Some functions return a primitive value.
char aFunctionThatReturnsACharacter(){
    return 'A';
}