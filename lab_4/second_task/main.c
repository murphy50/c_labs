#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "utilities.h"

int main() {
    FILE* file;
    file = fopen("input.txt", "rb");
    printf("%lf\n", AverageLetters(file));
    printf("%lf\n", AverageWords(file));
    char* max_word = MaxWord(file);
    printf("%s\n", max_word);
    free(max_word);
    char* max_sents = MaxSentence(file);
    printf("%s\n", max_sents);
    free(max_sents);
    fclose(file);
    return 0;
}