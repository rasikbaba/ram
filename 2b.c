#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void bubble_sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[10], i, n;
    pid_t pid;
    printf("Enter the number of elements in the array (max 10): ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    pid = fork();
    if (pid == -1) {
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        char *args[12];
        args[0] = "display_reverse";
        for (i = 0; i < n; i++) {
            char num[10];
            sprintf(num, "%d", arr[i]);
            args[i+1] = malloc(sizeof(char) * (strlen(num) + 1));
            strcpy(args[i+1], num);
        }
        args[n+1] = NULL;
        execve("display_reverse", args, NULL);
        printf("Exec failed.\n");
        exit(1);
    } else {
        bubble_sort(arr, n);
        wait(NULL);
        printf("Parent process sorted array: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
