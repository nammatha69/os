#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m], need[n][m];
    int finish[n], safeSeq[n];
    int count = 0;

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    // Calculate Need Matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize Finish array
    for(i = 0; i < n; i++)
        finish[i] = 0;

    // Safety Algorithm
    int work[m];
    for(j = 0; j < m; j++)
        work[j] = avail[j];

    while(count < n) {
        bool found = false;
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                for(j = 0; j < m; j++)
                    if(need[i][j] > work[j])
                        break;

                if(j == m) {
                    for(k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }

        if(!found) {
            printf("\nSystem is not in a safe state.\n");
            return 0;
        }
    }

    // If system is safe
    printf("\nSystem is in a safe state.\nSafe sequence is: ");
    for(i = 0; i < n; i++)
        printf("P[%d] ", safeSeq[i]);

    return 0;
}
