#include <stdio.h>
#include <stdlib.h>
int isdiv35(int n);
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 0;
    } else {
        int arg1 = atoi(argv[1]);
        int arg2 = atoi(argv[2]);
        if (arg1 > arg2) {
            printf("Error\n");
            return 0;
        } else {
            for (; arg1 <= arg2; arg1++) {
                int res = isdiv35(arg1);
                printf("%d is %d\n", arg1, res);
            }
        }
    }
    return 0;
}
int isdiv35(int n) {
    int div3 = 0;
    int div5 = 0;
    if (n % 5 == 0) {
        div5 = 1;
    }
    if (n % 3 == 0) {
        div3 = 1;
    }
    if (div3 && div5){
        return 3;
    } else if (div3 && ! div5) {
        return 1;
    } else if (div5 && ! div3) {
        return 2;
    } else {
        return 4;
    }
}