// Aim: Demonstrate bankers deadlock detection algorithm.find the processes involved in deadlock if there is a deadlock.resolve the 
// deadlock by selecting victim processes that
// has maximum number of allocated processes.
#include <stdio.h>
#include <stdbool.h>
#define PROCESSES 5
#define RESOURCES 3
void printMatrix(int matrix[PROCESSES][RESOURCES]) {
for (int i = 0; i < PROCESSES; i++) {
for (int j = 0; j < RESOURCES; j++) {
printf("%d ", matrix[i][j]);
}
printf("\n");
}
}
void detectAndResolveDeadlock(int
allocation[PROCESSES][RESOURCES], int
maxResources[PROCESSES][RESOURCES], int available[RESOURCES])
{
int need[PROCESSES][RESOURCES];
bool finish[PROCESSES] = {false};
int work[RESOURCES];
// Calculate the need matrix
for (int i = 0; i < PROCESSES; i++) {
for (int j = 0; j < RESOURCES; j++) {
need[i][j] = maxResources[i][j] - allocation[i][j];
}
}
// Initialize work with available resources
for (int i = 0; i < RESOURCES; i++) {
work[i] = available[i];

}
int safeSequence[PROCESSES];
int count = 0;
while (count < PROCESSES) {
bool found = false;
for (int i = 0; i < PROCESSES; i++) {
if (!finish[i]) {
bool canAllocate = true;
for (int j = 0; j < RESOURCES; j++) {
if (need[i][j] > work[j]) {
canAllocate = false;
break;
}
}
if (canAllocate) {
// Process i can complete
for (int j = 0; j < RESOURCES; j++) {
work[j] += allocation[i][j];
}
finish[i] = true;
safeSequence[count++] = i;
found = true;
}
}
}
if (!found) {
// Deadlock detected, find and resolve
printf("Deadlock detected\n");
// Find the victim process with the maximum allocated resources
int maxAllocatedResources = -1;
int victimProcess = -1;
for (int i = 0; i < PROCESSES; i++) {
if (!finish[i]) {
int allocatedResources = 0;
for (int j = 0; j < RESOURCES; j++) {
allocatedResources += allocation[i][j];

}
if (allocatedResources > maxAllocatedResources) {
maxAllocatedResources = allocatedResources;
victimProcess = i;
}
}
}
printf("Victim process %d selected for termination.\n", victimProcess);
// Release the resources allocated to the victim process
for (int j = 0; j < RESOURCES; j++) {
work[j] += allocation[victimProcess][j];
allocation[victimProcess][j] = 0;
}
printf("Resources released from process %d.\n", victimProcess);
// Restart the algorithm
count = 0;
for (int i = 0; i < PROCESSES; i++) {
finish[i] = false;
}
}
}
// No deadlock, print safe sequence
printf("Safe sequence: ");
for (int i = 0; i < PROCESSES - 1; i++) {
printf("P%d -> ", safeSequence[i]);
}
printf("P%d\n", safeSequence[PROCESSES - 1]);
}
int main() {
int need[PROCESSES][RESOURCES];
int allocation[PROCESSES][RESOURCES] = {
{0, 1, 0},
{2, 0, 0},
{3, 0, 3},
{2, 1, 1},
{0, 0, 2}
};
int maxResources[PROCESSES][RESOURCES] = {
{0,1,0},

{4,0,2},
{3,0,4},
{3,1,1},
{0,0,4}
};
int available[RESOURCES] = {0,0,0};
printf("Allocation matrix:\n");
printMatrix(allocation);
printf("Maximum resources matrix:\n");
printMatrix(maxResources);
printf("Available resources: ");
for (int i = 0; i < RESOURCES; i++) {
printf("%d ", available[i]);
}
printf("\n");
// Calculate the need matrix
for (int i = 0; i < PROCESSES; i++) {
for (int j = 0; j < RESOURCES; j++) {
need[i][j] = maxResources[i][j] - allocation[i][j];
}
}
printMatrix(need);
detectAndResolveDeadlock(allocation, maxResources, available);
return 0;
}