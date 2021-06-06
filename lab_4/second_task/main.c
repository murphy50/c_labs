#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "utilities.h"

int main() {
    FILE* file;
    file = fopen("input.txt", "rb");
    if(file == NULL){
		printf("Uh oh, input.txt could not be opened for reading!\n");
		exit(1);
	}
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