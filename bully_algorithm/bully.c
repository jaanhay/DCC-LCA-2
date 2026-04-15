#include <stdio.h>

int processes[10], n;

void election(int initiator) {
    int i, flag = 0;

    printf("\nProcess %d starts election\n", initiator);

    for(i = initiator + 1; i <= n; i++) {
        if(processes[i] == 1) {
            printf("Process %d sends election message to %d\n", initiator, i);
            flag = 1;
            election(i);
        }
    }

    if(flag == 0) {
        printf("\nProcess %d becomes the coordinator\n", initiator);
    }
}

int main() {
    int i, failed_process;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        processes[i] = 1;  // all processes are alive initially
    }

    printf("Enter the process that fails: ");
    scanf("%d", &failed_process);

    processes[failed_process] = 0;  // mark failed process

    printf("\nProcess %d has failed\n", failed_process);

    // Start election from next process
    election(failed_process - 1);

    return 0;
}