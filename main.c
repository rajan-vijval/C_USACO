#include <stdio.h>

int getTXTString(char * str, FILE * fp) {
    if (fp == NULL) return 0;
    while (fscanf(fp, "%s", str) != EOF) {
        return 1;
    }
    return 0;
}

int main() {
    char *str;
    const int ASCII_OFFSET = 64;

    FILE *fp = fopen("sample.txt", "r");

    getTXTString(str, fp);
    char *s1 = str;
    printf("\nfirst char: %c", s1[0]);
    printf("\nsecond char: %c\n", s1[1]);

    int mod1 = 1;
    int mod2 = 1;

    for (int i=0; s1[i] != NULL; i++) {
        mod1 *= (s1[i] - ASCII_OFFSET);
    }

    getTXTString(str, fp);
    printf("%s\n", str);
    char *s2 = str;

    for (int c=0; s2[c] != NULL; c++) {
        mod2 *= (s2[c] - ASCII_OFFSET);
    }

    if ((mod1 % 47) == (mod2 % 47)) {
        printf("GO");
    } else {
        printf("STAY");
    }



    return 0;
}
