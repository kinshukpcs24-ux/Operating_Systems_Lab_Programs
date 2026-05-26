#include <stdio.h>

int main() {
    int P, R;
    printf("Enter number of processes: ");
    scanf("%d", &P);
    printf("Enter number of resources: ");
    scanf("%d", &R);

    int alloc[P][R], max[P][R], avail[R];

    printf("\nEnter Allocation Matrix (%d x %d):\n", P, R);
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix (%d x %d):\n", P, R);
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources (%d values):\n", R);
    for (int i = 0; i < R; i++) {
        scanf("%d", &avail[i]);
    }

    int f[P], ans[P], ind = 0;
    for (int k = 0; k < P; k++) {
        f[k] = 0; // initially all processes are unfinished
    }

    int need[P][R];
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int k = 0; k < P; k++) {
        for (int i = 0; i < P; i++) {
            if (f[i] == 0) {
                int flag = 1; // assume process can finish
                for (int j = 0; j < R; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 0; // cannot finish
                        break;
                    }
                }
                if (flag == 1) {
                    ans[ind++] = i;
                    for (int y = 0; y < R; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1; // mark as finished
                }
            }
        }
    }

    int deadlock = 0;
    for (int i = 0; i < P; i++) {
        if (f[i] == 0) {
            deadlock = 1;
            break;
        }
    }

    if (deadlock == 0) {
        printf("\nSystem is in a safe state.\nSafe sequence is: ");
        for (int i = 0; i < P; i++) {
            printf("P%d ", ans[i]);
        }
        printf("\n");
    } else {
        printf("\nDeadlock detected! No safe sequence exists.\n");
    }

    return 0;
}
