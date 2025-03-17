#include <stdio.h>
#include <string.h>

char ans[401];
char sol[401];

void reverse(char *num) {
    int n = strlen(num);
    char rev[401];

    for(int i = 0; i < n; i++)
        rev[i] = num[n - i - 1];

    for(int i = 0; i < n; i++)
        ans[i] = rev[i];
}

void single_num(char *num1, char *num2, int t, char *ans) {
    int n1 = strlen(num1);
    int n2 = strlen(num2);

    if(t == n2)
        return;

    int carry = 0;
    int i = 0;

    while(i < n1) {
        int res = (ans[i + t] - '0') + (num1[n1 - i - 1] - '0') * (num2[n2 - t - 1] - '0') + carry;
    
        if(res > 9) {
            ans[i + t] = (res % 10) + '0';
            carry = res / 10;
        }

        else {
            ans[i + t] = res + '0';
        };

        i++;
    }

    if(carry)
        ans[i + t] = carry + '0';

    single_num(num1, num2, t + 1, ans);
}

char *multiply(char *num1, char *num2) {
    for(int i = 0; i < 401; i++)
        ans[i] = '0';

    single_num(num1, num2, 0, ans);
    reverse(ans);

    int i = 0;
    while(ans[i] == '0')
        i++;

    sol[401 - i];
    int j = 0;

    while(i < 401) {
        sol[j] = ans[i];
        j++;
        i++;
    };

    return sol;
}

int main() {
    char num1[200], num2[200];
    scanf("%s %s", num1, num2);
    char *ans1 = multiply(num1, num2);

    puts(ans1);
    return 0;
}
