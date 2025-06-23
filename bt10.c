#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements in array:");
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));
    int *checked = (int *) calloc(n, sizeof(int)); // mảng đánh dấu

    if (arr == NULL || checked == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int totalCount =0;

    for (int i = 0; i < n; i++) {
        if (checked[i]) {
            continue;
        }
        int count = 1;
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                checked[i] = 1;
            }
        }
        totalCount += count;
        if (n<totalCount) {
            break;
        }
        printf("%d appear %d times in array\n", arr[i], count);
    }


    free(arr);
    return 0;
}




