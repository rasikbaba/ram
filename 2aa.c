#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void bubbleSort(int array[], int n) {
    int i,j,temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(array[j]>array[j+1]) {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

int main() {
    int n,i;
    printf("Enter number of integers: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d integers: \n", n);
    for(i=0; i<n; i++) {
        scanf("%d", &array[i]);
    }
    pid_t pid=fork(); //create a child process
    if(pid<0) {
        printf("Fork failed\n"); //error occurred
        return 1;
    } else if(pid==0) { //child process
        bubbleSort(array, n);
        printf("Child process sorted the integers\n");
        printf("Sorted integers: \n");
        for(i=0; i<n; i++) {
            printf("%d", array[i]);
            printf("\n");
        }
    } else { //parent process
        wait(NULL);
        printf("Parent process is now completed\n");
    }
    return 0;
}
