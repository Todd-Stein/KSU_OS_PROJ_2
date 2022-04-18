#include <stdio.h>
#include <math.h>

int inOrder(int a[], int b[], int n) {
	for(int i = 0; i<n; n++) {
		if(a[i] != b[i])
			return 0;
	}
	return 1;
}

int main() {
	int numProcesses = 5;
	int numResources = 3;
	int available [3] = {3, 3, 2};
	int max[5] [3] = {{7, 5, 3},
			  {3, 2, 2},
			  {9, 0, 2},
			  {2, 2, 2},
		          {4, 3, 3}};
	int allocation[5] [3] = {{0, 1, 0},
				 {2, 0, 0},
				 {3, 0 ,2},
				 {2, 1, 1},
				 {0, 0, 2}};
	int need[5] [3];
	for(int i = 0; i<numProcesses; i++) {
		for(int j = 0; j<numResources; j++) {
			need[i][j] = fabs(max[i][j] - allocation[i][j]);
		}
	}
	int processCanExecute[5] = {0, 0, 0, 0, 0};
	int processesHaveExecuted[5] = {1, 1, 1, 1, 1};
	printf("Safe sequence:\n");
	while(inOrder(processCanExecute, processesHaveExecuted, numProcesses) != 1) {
		for(int i = 0; i<numProcesses; i++) {
			for(int j = 0; j<numResources; j++) {
				if(processCanExecute[i] == 0) {
					if(need[i][j]>available[j]) {
						processCanExecute[i] = 0;
						break;
					}
					else {
						processCanExecute[i] = 2;
					}
				}
			}
			if(processCanExecute[i] == 2) {
				for(int j = 0; j<numResources; j++) {
					available[j] = available[j] + need[i][j];
					//printf("%d\n",available[j]);
				}
				printf("Process %d\n", i);
				processCanExecute[i] = 1;
			}
		}
	}
}

