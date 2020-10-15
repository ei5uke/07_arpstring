#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float avg(int *arr1, int size) //1, returns avg of int values in an array
{
    float sum = 0;
    int i;
    for (i = 0; i < size; i++)
        sum += *(arr1 + i); //or ray1[i];
    sum /= size;
    return sum;
}

void copy(int *arr1, int *arr2, int size) //2, copies values of arr1 into arr2
{
    int i;
    for (i = 0; i < size; i++)
        *(arr2 + i) = *(arr1 + i); //or arr2[i] = arr1[i];
    return;
}

int len(char *s) //3, returns the length of the string
{
    int length = 0;
    while (*s) //as long as each value isn't 0, this while loop continues
    {
        length++;
        s++; //at one point, the last value will be 0
    }
    return length;
}

int main()
{
    //1
    int ray1[10];
    int i;
    for (i = 0; i < 10; i++)
        ray1[i] = i;
    printf("Avg of ray: %f\n", avg(ray1, 10)); //should be 4.5;

    //2
    int ray2[10];
    copy(ray1, ray2, 10);
    for (i = 0; i < 10; i++)
        printf("ray2[%d]: %d\n", i, ray2[i]);

    //3
    char systems[] = "Systems"; //7 bytes for the literal and one more for NULL
    printf("Length of s: %d\n", len(systems)); //should be 7 cuz it doesn't count the NULL

    //exercises
    char copy[256]; //strcpy
    strcpy(copy, systems);
    printf("copy: %s\n", copy); //%s prints a string

    char appleSystems[] = "apple";
    strcat(appleSystems, copy); //strcat
    printf("apple: %s\n", appleSystems);

    char oranges[] = "oranges";
    if (strcmp(appleSystems, oranges)) //strcmp
        printf("%s is a longer word than %s\n", appleSystems, oranges);
    else
        printf("%s is a longer word than %s\n", oranges, appleSystems);

    char bananas[] = "bananas";
    char *n = strchr(bananas, 'n'); //strchr, note, it returns everything after the char inclusive
    printf("%s\n", n);
    return 0;
}