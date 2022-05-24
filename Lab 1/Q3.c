#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[]) {
    int c, duplicate = 0, uppercase = 0, error = 0;
    while (--argc > 0 && (*++argv)[0] == '-') {
        c = *++argv[0];
        while (c && error == 0) {
            switch(c) {
                case 'd':
                    duplicate = 1;
                    break;
                case 'u':
                    uppercase = 1;
                    break;
                default:
                    printf("Illegal option: %c\n", c);
                    error = 1;
                    argc = 0;
                    break;
            }
            c = *++argv[0];
        }
    }
    if (argc > 0) {
        return 0;
    } else if (error == 1) {
        return 0;
    } else {
        while ((c = getchar()) != EOF) {
            if (uppercase) {
                if (isalpha(c)){
                    c = toupper(c);
                }
            }
            if (duplicate) {
                putchar(c);
                putchar(c);
            } else {
                putchar(c);
            }
        }
    }
    return 0;
}
