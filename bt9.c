#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements in array:");
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int maxCount = 0;
    int mostFrequent;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    printf("Most frequent element: %d", mostFrequent);

    free(arr);
    return 0;
}




