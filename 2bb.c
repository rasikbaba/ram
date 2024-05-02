#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

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
    
    if (n <= 0 || n > 10) {
        printf("Invalid number of elements.\n");
        return 1;
    }
    
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
        args[0] = "echo"; // Replace with actual command or program
        for (i = 0; i < n; i++) {
            char num[10];
            sprintf(num, "%d", arr[i]);
            args[i+1] = strdup(num);
            if (args[i+1] == NULL) {
                perror("strdup");
                exit(EXIT_FAILURE);
            }
        }
        args[n+1] = NULL;
        
        execvp("echo", args); // Replace with actual command or program
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        bubble_sort(arr, n);
        wait(NULL);
        printf("Sorted array: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    return 0;
}
