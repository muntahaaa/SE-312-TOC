#include <stdio.h>

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
    } else {
        for (int i = l; i <= r; i++) {
            swap((str + l), (str + i));
            permute(str, l + 1, r);
            swap((str + l), (str + i)); // backtrack
        }
    }
}

void combine(char *str, int start, int n, char *data, int index, int r) {
    if (index == r) {
        for (int i = 0; i < r; i++) {
            printf("%c", data[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < n; i++) {
        data[index] = str[i];
        combine(str, i + 1, n, data, index + 1, r);
    }
}

int main() {
    char str[] = "ABCDE";
    int n = sizeof(str) - 1;

    printf("Permutations:\n");
    permute(str, 0, n - 1);

    printf("\nCombinations:\n");
    char data[n];
    for (int r = 1; r <= n; r++) {
        combine(str, 0, n, data, 0, r);
    }

    return 0;
}
