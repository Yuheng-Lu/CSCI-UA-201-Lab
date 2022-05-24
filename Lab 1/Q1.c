#include <stdio.h>
#include <ctype.h>
int countVowels(char *str);
int main() {
    char str[] = "Eabc@Uu";
    printf("%d\n", countVowels(str));
    printf("%s", str);
    return 0;
}
int countVowels(char *str) {
    int i = 0;
    int res = 0;
    while (str[i]) {
        if (isalpha(str[i]) != 0) {
            if (str[i] == 'a' ||  str[i] == 'e' || str[i] == 'i' || str[i] =='o' || str[i] == 'u'){
                res++;
                *(str+i) = toupper(str[i]);
            }
            else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i]=='O' || str[i] == 'U') {
                res++;
                *(str+i) = tolower(str[i]);
            }
        }
        i++;
    }
    return res;
}
