#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    wt[0] = 0;

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &bt[i]);
    }

    // Waiting time
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    // Turnaround time
    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);

    return 0;
}
