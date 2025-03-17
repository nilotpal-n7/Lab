#include <stdio.h>
#include <string.h>

char ans[4500];
char o = '1';
char *one = &o;

char *RLE(char str[]) {
    int l = strlen(str);
    int j = 0;

    for(int i = 0; i < l; i++) {
        int count = 1;

        while((i + 1) < l && ans[i] == ans[i + 1])
            count++, i++;

        ans[j++] = count + '0';
        ans[j++] = str[i];
    };

    ans[j] = '\0';
    return ans;
}

char *countAndSay(int n) {
    if(n == 1)
        return one;

    char str[4500];
    strcpy(str, countAndSay(n - 1));
    return RLE(str);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%s", countAndSay(n));
    return 0;
}
