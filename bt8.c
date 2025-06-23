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

    int *arr2 = NULL;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int isGreater = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                isGreater = 0; // Nếu có tòa nhà phía sau cao hơn hoặc bằng → không lấy
                break;
            }
        }
        if (isGreater) {
            int *temp = (int *) realloc(arr2, n * sizeof(int));
            arr2 = temp;
            arr2[count] = arr[i];
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", arr2[i]);
    }
    free(arr);
    free(arr2);
}




