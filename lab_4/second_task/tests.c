#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include"utilities.h"

void TestWordsInFile(FILE* file) {  
    assert(4 == WordsInFile(file));
}

void TestSentenceInFile(FILE* file) {
    assert(1 == SentenceInFile(file));
}

void TestMaxSentence(FILE* file) {
    char* max_sent = MaxSentence(file);
    assert(strcmp("This is test file.", max_sent) == 0);
    free(max_sent);
}

void TestMaxWord(FILE* file) {
    char* max_word = MaxWord(file);
    assert(strcmp("This", max_word) == 0);
    free(max_word);
}

void TestAverageLetters(FILE* file) {
    assert(3.5 == AverageLetters(file));
}

void TestAverageWords(FILE* file) {
    assert(4.0 == AverageWords(file));
}

int main() {
    FILE* file;
    file = fopen("tests.txt", "rb");
    TestWordsInFile(file);
    TestSentenceInFile(file);
    TestMaxWord(file);
    TestMaxSentence(file);
    TestAverageLetters(file);
    TestAverageWords(file);
    fclose(file);
    return 0;
}