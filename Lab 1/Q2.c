#include <stdio.h>
#include <string.h>
int reorder(char **s1, char **s2, char **s3);
int main() {
    char *s1_1 = "helloworld";
    char *s1_2 = "helloworld";
    char *s1_3 = "helloworld";

    char *s2_1 = "helloworld";
    char *s2_2 = "hllwrld";
    char *s2_3 = "helloworld";

    char *s3_1 = "eo";
    char *s3_2 = "helloworld";
    char *s3_3 = "hllwrld";
    printf("%d\n", reorder(&s1_1, &s1_2, &s1_3));
    printf("%d\n", reorder(&s2_1, &s2_2, &s2_3));
    printf("%d\n", reorder(&s3_1, &s3_2, &s3_3));
    printf("%s\n", s3_1);
    printf("%s\n", s3_2);
    printf("%s\n", s3_3);
    return 0;
}
int reorder(char **s1, char **s2, char **s3) {
    if (strlen(*s1) == strlen(*s2) && strlen(*s1) == strlen(*s3)) {
        printf("All 3 are equal length.");
        return strlen(*s1);
    } else if (strlen(*s1) == strlen(*s2) || strlen(*s1) == strlen(*s3) || strlen(*s2) == strlen(*s3)){
        printf("Two are equal length.");
        return 2;
    } else {
        char *temp1 = *s1;
        char *temp2 = *s2;
        char *temp3 = *s3;
        if (strlen(*s1) > strlen(*s2) && strlen(*s1) > strlen(*s3)) {
            if (strlen(*s2) > strlen(*s3)) {
                *s1 = temp1;
                *s2 = temp2;
                *s3 = temp3;
            } else {
                *s1 = temp1;
                *s2 = temp3;
                *s3 = temp2;
            }
        } else if (strlen(*s2) > strlen(*s1) && strlen(*s2) > strlen(*s3)) {
            if (strlen(*s1) > strlen(*s3)) {
                *s1 = temp2;
                *s2 = temp1;
                *s3 = temp3;
            } else {
                *s1 = temp2;
                *s2 = temp3;
                *s3 = temp1;
            }
        } else {
            if (strlen(*s1) > strlen(*s2)) {
                *s1 = temp3;
                *s2 = temp1;
                *s3 = temp2;
            } else {
                *s1 = temp3;
                *s2 = temp2;
                *s3 = temp1;
            }
        }
        printf("all three are unequal length.");
        return 1;
    }
}