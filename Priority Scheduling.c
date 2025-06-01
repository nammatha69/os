#include <stdio.h>

int main() {
    int n, i, j, temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], pr[n], wt[n], tat[n];
    wt[0] = 0;

    printf("Enter burst times and priorities:\n");
    for(i = 0; i < n; i++) {
        printf("P[%d] burst time: ", i+1);
        scanf("%d", &bt[i]);
        printf("P[%d] priority (lower number = higher priority): ", i+1);
        scanf("%d", &pr[i]);
        p[i] = i+1;
    }

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[i] > pr[j]) {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }


    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);

    return 0;
}
