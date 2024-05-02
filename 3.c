#include <stdio.h>
int main()
{
	// Matrix for storing Process Id, Burst
	// Time, Average Waiting Time & Average
	// Turn Around Time.
	int A[100][4];
	int i, j, n, total = 0, index, temp;
	float avg_wt, avg_tat;
	printf("Enter number of process: ");
	scanf("%d", &n);
	printf("Enter Burst Time:\n");
	// User Input Burst Time and alloting Process Id.
	for (i = 0; i < n; i++) {
		printf("P%d: ", i + 1);
		scanf("%d", &A[i][1]);
		A[i][0] = i + 1;
	}
	// Sorting process according to their Burst Time.
	for (i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++)
			if (A[j][1] < A[index][1])
				index = j;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;

		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
	}
	A[0][2] = 0;
	// Calculation of Waiting Times
	for (i = 1; i < n; i++) {
		A[i][2] = 0;
		for (j = 0; j < i; j++)
			A[i][2] += A[j][1];
		total += A[i][2];
	}
	avg_wt = (float)total / n;
	total = 0;
	printf("P	 BT	 WT	 TAT\n");
	// Calculation of Turn Around Time and printing the
	// data.
	for (i = 0; i < n; i++) {
		A[i][3] = A[i][1] + A[i][2];
		total += A[i][3];
		printf("P%d	 %d	 %d	 %d\n", A[i][0],
			A[i][1], A[i][2], A[i][3]);
	}
	avg_tat = (float)total / n;
	printf("Average Waiting Time= %f", avg_wt);
	printf("\nAverage Turnaround Time= %f", avg_tat);
}

	Round Robin
#include<stdio.h>
int main()

{

    //Input no of processed

    int  n;

    printf("Enter Total Number of Processes:");

    scanf("%d", &n);

    int wait_time = 0, ta_time = 0, arr_time[n], burst_time[n], temp_burst_time[n];

    int x = n;

 

    //Input details of processes

    for(int i = 0; i < n; i++)

    {

        printf("Enter Details of Process %d \n", i + 1);

        printf("Arrival Time:  ");

        scanf("%d", &arr_time[i]);

        printf("Burst Time:   ");

        scanf("%d", &burst_time[i]);

        temp_burst_time[i] = burst_time[i];

    }

 

    //Input time slot

    int time_slot;

    printf("Enter Time Slot:");

    scanf("%d", &time_slot);

 

    //Total indicates total time

    //counter indicates which process is executed

    int total = 0,  counter = 0,i;

    printf("Process ID       Burst Time       Turnaround Time      Waiting Time\n");

    for(total=0, i = 0; x!=0; )  

    {  

        // define the conditions

        if(temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0)    

        {  

            total = total + temp_burst_time[i];  

            temp_burst_time[i] = 0;  

            counter=1;  

        }     

        else if(temp_burst_time[i] > 0)  

        {  

            temp_burst_time[i] = temp_burst_time[i] - time_slot;  

            total  += time_slot;    

        }  

        if(temp_burst_time[i]==0 && counter==1)  

        {  

            x--; //decrement the process no.  

            printf("\nProcess No %d  \t\t %d\t\t\t\t %d\t\t\t %d", i+1, burst_time[i],

                   total-arr_time[i], total-arr_time[i]-burst_time[i]);  

            wait_time = wait_time+total-arr_time[i]-burst_time[i];  

            ta_time += total -arr_time[i];  

            counter =0;     

        }  

        if(i==n-1)  

        {  

            i=0;  

        }  

        else if(arr_time[i+1]<=total)  

        {  

            i++;  

        }  

        else  

        {  

            i=0;  

        }  

    }  

    float average_wait_time = wait_time * 1.0 / n;

    float average_turnaround_time = ta_time * 1.0 / n;

    printf("\nAverage Waiting Time:%f", average_wait_time);

    printf("\nAvg Turnaround Time:%f", average_turnaround_time);

    return 0;

}
