#include <stdio.h>

int main() {
    int n, i, time, remain, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];
    remain = n;

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int t = 0;
    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] > tq) {
                    t += tq;
                    rt[i] -= tq;
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i];
                    rt[i] = 0;
                    remain--;
                }
            }
        }
    }

    // Turnaround time
    for(i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);

    return 0;
}
