#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void swap(char* x, char* y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void generateAnagrams(char* word, int start, int end, int* count)
{
    int i;
    if (start == end)
    {
        printf("%s\n", word);
        (*count)++;
    }
    else
    {
        for (i = start; i <= end; i++)
        {
            swap((word + start), (word + i));
            generateAnagrams(word, start + 1, end, count);
            swap((word + start), (word + i));
        }
    }
}

int main()
{
    char word[15];
    int count = 0;
    printf("Enter a word: ");
    scanf("%s", word);
    int len = strlen(word);
    generateAnagrams(word, 0, len - 1, &count);
    printf("Number of anagrams: %d\n", count);
    return 0;
}
