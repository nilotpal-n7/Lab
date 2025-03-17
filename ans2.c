#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {
    int i = 0;
    int j = 0;
    bool r = 0;
    char rep;

    while(true) {
        if(i >= strlen(s) && j >= strlen(p))
            break;

        if(p[j] == '*')
            r = 1, rep = p[j - 1];

        if(s[i] != p[j]) {
            if(p[j] == '.')
                j++;

            else if(p[j + 1] != '*' && p[j] != '*')
                return 0;

            else if(r && s[i] != rep && s[i] != p[j + 1]) {
                if(p[j + 1] == '.')
                    r = 0, j+=2;
                else if(p[j + 2] == '*')
                    j += 2, i--;
                else
                    return 0;
            }
            else if(s[i] == p[j + 1])
                r = 0, j+=2;
        }
        else
            j++;
        i++;
    };
    return 1;
}

int main() {
    char p[20];
    char s[20];
    scanf("%s %s", s, p);
    bool ans = isMatch(s, p);
    printf("%d", ans);
    return 0;
}
