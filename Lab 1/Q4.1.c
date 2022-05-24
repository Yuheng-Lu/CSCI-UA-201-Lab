#include <stdio.h>
int isdiv35(int n);
int main() {
    printf("%d", isdiv35(3242));
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