#include <stdio.h>
#include <stdlib.h>

/**
 * This simple program only introduce myself like "Hi, my name is eric, 18 years
 * old!". It can be run with the following three methods.
 * 1. hi eric 18
 * 2. hi < data.txt // the data.txt contains the name and age seperated by space
 * 3. hi // enter you name and age according to the prompt.
 */
int main(int argc, char const *argv[]) {
    // check whether the count of program arguments was great equal to 3
    // eg: hi liudonghua 18
    if (argc >= 3) {
        printf("Hi, my name is %s, %d years old!", argv[1], atoi(argv[2]));
        return 0;
    }
    char name[10];
    int age;
    // check whether the input was from stdin
    // eg: hi < data.txt
    fseek(stdin, 0, SEEK_END);
    int num = ftell(stdin);
    if (num > 0) {
        rewind(stdin);
        fscanf(stdin, "%s %d", name, &age);
        printf("Hi, my name is %s, %d years old!", name, age);
        return 0;
    }
    // check whether the input was from FIFOS
    // ToDo
    // the last condition is read input from interactive prompt
    printf("Enter you name: ");
    scanf("%s", name);
    printf("Enter you age: ");
    scanf("%d", &age);
    printf("Hi, my name is %s, %d years old!", name, age);
    return 0;
}
