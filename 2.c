#include <stdio.h>
#include <stdlib.h>

void alloc(int ***arr, int r, int c, int n) {
    *arr = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++) {
        (*arr)[i] = (int *)malloc(3 * sizeof(int));
        scanf("%d %d %d", (*arr)[i], (*arr)[i] + 1, (*arr)[i] + 2);
    }
}

void m_free(int **arr, int n) {
    for(int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

int main() {
    int r1, c1, n1, **arr1;
    int r2, c2, n2, **arr2;
    scanf("%d %d %d", &r1, &c1, &n1);
    alloc(&arr1, r1, c1, n1);
    scanf("%d %d %d", &r2, &c2, &n2);
    alloc(&arr2, r2, c2, n2);

    if(r1 == r2 && c1 == c2){
        int n = n1;
        int **sum = (int **)malloc(n * sizeof(int *));
        for(int i = 0; i < n; i++) {
            sum[i] = (int *)malloc(3 * sizeof(int));
            sum[i][0] = arr1[i][0], sum[i][1] = arr1[i][1], sum[i][2] = arr1[i][2];
        }

        for(int i = 0; i < n2; i++) {
            int found = 1;
            for(int j = 0; j < n1; j++) {
                if(sum[j][0] == arr2[i][0] && sum[j][1] == arr2[i][1]) {
                    sum[j][2] += arr2[i][2];
                    found = 0;
                    break;
                }
            }

            if(found) {
                n++;
                sum = (int **)realloc(sum, n * sizeof(int *));
                sum[n - 1] = (int *)malloc(3 * sizeof(int));
                sum[n - 1][0] = arr2[i][0], sum[n - 1][1] = arr2[i][1], sum[n - 1][2] = arr2[i][2];
            }
        }

        for(int i = 0; i < n; i++)
            printf("%d %d %d\n", sum[i][0], sum[i][1], sum[i][2]);
        m_free(sum, n);
    }
    else
        printf("%d", -999);

    m_free(arr1, n1);
    m_free(arr2, n2);

    return 0;
}
