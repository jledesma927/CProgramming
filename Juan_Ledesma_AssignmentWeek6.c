#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int product(int arr[], int size, int leftProd, int n) {

    if (n == size)
        return 1;

    int curr = arr[n];

    int rightProd = product(arr, size, leftProd * arr[n], n + 1);

    arr[n] = leftProd * rightProd;

    return curr * rightProd;
}

int power(int x, int pow) {
    if (pow == 0)
        return 1;
    return x * power(x, pow - 1);
}

void stringPerm(char* input, int start, int end)
{
    char tmp;

    if (start == end - 1) {
        printf("%\n", input);
        return;
    }

    for (int j = start; j < end; j++) {
        tmp = input[start];
        input[start] = input[j];
        input[j] = tmp;

        stringPerm(input,  + 1, end);

        tmp = input[start];
        input[start] = input[j];
        input[j] = tmp;
    }
}

int main() {
    int x = 2;
    int pow = 8;
    char str[] = "ABC";

    int arr[] = { 5, 3, 4, 2, 6, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d^%d = %d\n", x, pow, power(x, pow));

    product(arr, n, 1, 0);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    stringPerm(str, 0, 3);

    return 0;

}
