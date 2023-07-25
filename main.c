#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define STRSIZE 30

/* -----------------------------------------------------------
    //* String Library
    - //* See Introduction to C strings https://youtube.be/E4ud31QeCY
    //* 1.puts
    //* 2.strlen
    //* 3.strcopy
    //* strcmp
    //* strcat
    ------------------------------------------------------------------
*/
//* puts() functions for displaying C strings for standart out
void putsExample(void)
{
    int err;
    char str1[STRSIZE + 1] = "IPC 144 C Programming....";

    puts(""); //* quick and lazy way to add a newline without using: printf("\n");
    puts("puts() provides a quick way to display C strings\n");
    puts("and automatically apllies a single newline character at the end\n");
    puts("You can optionally add more newlines\n just as you would do\n when using the printf function\n\n\n");

    //* Displaying C strings:
    err = puts(str1); //* should note: returns EOF (end of file) error or non-zero for succesful

    //*[Optionally] Validate output:
    if (err == EOF) //* Generally only occurs if there is an error of some sort,you rarely need to check for this
    {
        puts("There was an error displaying the C string...\n");
    }
    else
    {
        puts("Looks like the puts functions worked without any error!\n");
    }
}

//* strlen() function for determing length of a C string
void strlenExample(void)
{
    char str1[STRSIZE + 1] = "C-String!";
    char str2[STRSIZE + 1] = {0};
    int valid;

    //* String length of variable str1
    printf("The length of C string str1 (%s) is: %d", str1, strlen(str1));

    //*Sample validation of a string being entered to meet
    //* a minimum length requirement
    do
    {
        printf("Enter a string that is exactly 6 characters long: ");
        scanf("%30[^\n]", str2);
        // clearBuffer();

        valid = strlen(str2) == 6 ? 1 : 0;
        if (!valid)
        {
            puts("\tERROR! String must be 6 characters in length!\n");
        }
        else
        {
            puts("Fantastic well done!");
        }
    } while (!valid);

    puts("");
}
//*strcpy() function for copying one C string to another
void strcpyExample(void)
{
    char str1[STRSIZE + 1] = "C-String!";
    char str2[STRSIZE + 1] = {0};
    char str3[STRSIZE + 1] = "Values....";
    char *result = NULL;

    puts("Current values of the C strings:");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    printf("result: %s\n\n", result == NULL ? "NULL!" : result);

    //* Copy str1 to str2
    puts("Now.... let's copy str1 to str2!\n\n");
    result = strcpy(str2, str1);

    puts("Current values of the C strings:");
    printf("str1: %s\n", str1);
    printf("st2: %s\n", str2);
    printf("str3: %s\n", str3);
    printf("result: %s\n\n", result == NULL ? "NULL!" : result);

    //* Copy str1 to str3 (replace its contents)
    puts("Now... let's copy str1 to str3!\n\n");
    result = strcpy(str3, str1); //*WARNING: overwrites contents of str3

    puts("Current values of the C strings:");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    printf("result: %s\n\n", result == NULL ? "NULL!" : result);
}

//* strcmp() function for comparing two C strings
void strcmpExample(void)
{
    char str1[STRSIZE + 1] = "abcde";
    char str2[STRSIZE + 1] = "Abcde";
    char str3[STRSIZE + 1] = "zabcd";
    char str4[STRSIZE + 1] = "abcde";
    char str5[STRSIZE + 1] = "abcdf";
    char str6[STRSIZE + 1] = "abcdf and more";
    int result;

    puts("String Compare Examples");
    puts("-----------------------");
    puts("Using the following variables/values:");
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("str3 = %s\n", str3);
    printf("str4 = %s\n", str4);
    printf("str5 = %s\n\n", str5);
    printf("str6 = %s\n\n", str6);


    printf("Comparing str1: %s to str2: %s, result: %d\n", str1, str2, strcmp(str1, str2));
    printf("Comparing str1: %s to str3: %s, result: %d\n", str1, str3,strcmp(str1,str3));
    printf("Comparing str2: %s to str1: %s, result: %d\n", str2, str1,strcmp(str2,str1));
    printf("Comparing str2: %s to str3: %s, result: %d\n", str2, str3,strcmp(str2,str3));
    printf("Comparing str3: %s to str1: %s, result: %d\n", str3, str1,strcmp(str3,str1));
    printf("Comparing str3: %s to str2: %s, result: %d\n", str3, str2,strcmp(str3,str2));
    printf("Comparing str1: %s to str5: %s, result: %d\n", str1, str5,strcmp(str3,str2));
    printf("Comparing str5: %s to str1: %s, result: %d\n", str5, str1,strcmp(str3,str2));
    printf("Comparing str5: %s to str6: %s, result: %d\n", str5, str6,strcmp(str3,str2));



}
//* strcat() function for appending one C string to another
void strcatExample(void) 
{
    char str1[STRSIZE + 1] = "Bobby-Joe";
    char str2[STRSIZE + 1] = "Hillary Newton";
    char str3[STRSIZE +1] = "Bloomberg-WHite";

    char strFullName[(STRSIZE + 1) * 3] = { 0 };
    //* Task: In a single C string character array strFullName, combine all the indivodial
    //*         name parts to construct a "full name"

    strcpy(strFullName, str1);
    printf("strFullName: %s", strFullName);
    strcat(strFullName, str2);
    printf("strFullName: %s\n", strFullName);
    strcat(strFullName,str3); //* <---- error? ...... just because it will overram the program to fix this problem multiply the size of string
    printf("strFullName: %s\n\n", strFullName);

} 
int main()
{
    putsExample();
    strlenExample();
    strcpyExample();
    strcmpExample();
    strcatExample();
} 