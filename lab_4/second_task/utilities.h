#ifndef UTILITIES_H
#define UTILITIES_H

int WordsInFile(FILE* file) {
    int count = 0;
    char* tmp = (char*)malloc(20);
    while (fscanf(file, "%s", tmp) != EOF) {
        ++count;
    }
    free(tmp);
    fseek(file, 0L, SEEK_SET);
    return count;
}

int SentenceInFile(FILE* file) {
    int senteces = 0;
    char* tmp = (char*)malloc(20);
    for (int i = 0; fscanf(file, "%s", tmp) != EOF; i++) {
        int len = strlen(tmp);
        if (tmp[len - 1] == '!' || tmp[len - 1] == '?' || tmp[len - 1] == '.') {
            ++senteces;
        }
    }
    free(tmp);
    fseek(file, 0L, SEEK_SET);
    return senteces;
}

char* MaxSentence(FILE* file) {
    char* max = (char*)malloc(200);
    char* tmp = (char*)malloc(20);
    char* tmp_sent = (char*)malloc(100);
    for (int i = 0; fscanf(file, "%s", tmp) != EOF; i++) {
        if (i == 0) {
            sprintf(max, "%s", tmp);
            sprintf(tmp_sent, "%s", tmp);
        }
        else if (strlen(tmp_sent) == 0) {
            sprintf(tmp_sent, "%s", tmp);
        }
        else {
            sprintf(tmp_sent, "%s%s%s", tmp_sent, " ", tmp);
        }
        int len = strlen(tmp);
        if (tmp[len - 1] == '!' || tmp[len - 1] == '?' || tmp[len - 1] == '.') {
            if (strlen(max) < strlen(tmp_sent)) {
                sprintf(max, "%s", tmp_sent);
                sprintf(tmp_sent, "%s", "");
            }
            else {
                sprintf(tmp_sent, "%s", "");
            }
        }
    }
    free(tmp);
    free(tmp_sent);
    fseek(file, 0L, SEEK_SET);
    return max;
}

double AverageLetters(FILE* file) {
    int sum = 0;
    char* tmp = (char*)malloc(20);
    int i = 0;
    for (i; fscanf(file, "%s", tmp) != EOF; i++) {
        int len = strlen(tmp);
        if (tmp[len - 1] == ',' || tmp[len - 1] == '!' || tmp[len - 1] == '?' || tmp[len - 1] == '.') {
            tmp[len - 1] = '\0';
        }
        sum += strlen(tmp);
    }
    free(tmp);
    fseek(file, 0L, SEEK_SET);
    return (double)sum / i;
}

char* MaxWord(FILE* file) {
    char* max = (char*)malloc(20);
    char* tmp = (char*)malloc(20);
    for (int i = 0; fscanf(file, "%s", tmp) != EOF; i++) {
        int len = strlen(tmp);
        if (i == 0) {
            sprintf(max, "%s", tmp);
        }
        if (tmp[len - 1] == ',' || tmp[len - 1] == '!' || tmp[len - 1] == '?' || tmp[len - 1] == '.') {
            tmp[len - 1] = '\0';
        }
        if (strlen(max) < strlen(tmp)) {
            sprintf(max, "%s", tmp);
        }
    }
    free(tmp);
    fseek(file, 0L, SEEK_SET);
    return max;
}

double AverageWords(FILE* file) {
    double average = (double)WordsInFile(file) / SentenceInFile(file);
    return  average;
}
#endif