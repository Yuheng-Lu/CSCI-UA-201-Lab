#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error\n");
        return 0;
    }
    char *str = argv[1];
    char *except = argv[2];
    char *dup = argv[3];
    int i, j, k, l;

    for (i = 0;str[i] != '\0';++i) {
        if (str[i] < 'a' || str[i] > 'z') {
            printf("Error\n");
            return 0;
        }
    }
    for (j = 0;str[j] != '\0';++j) {
        int in_except = 0;
        int in_dup = 0;
        for (k = 0; except[k] != '\0'; k++) {
            if (str[j] == except[k]) {
                in_except = 1;
                break;
            }
        }
        if (!in_except) {
            for (l = 0; dup[l] != '\0'; l++) {
                if (str[j] == dup[l]) {
                    in_dup = 1;
                    break;
                }
            }
        }
        if (!in_except && in_dup) {
            putchar(str[j]);
            putchar(str[j]);
        } else if (!in_except) {
            putchar(str[j]);
        }
    }
    printf("\n");
    return 0;
}