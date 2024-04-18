// Aim: Write C programsto implement:
// 1. Memory allocation schemes
// 2. Disk scheduling algorithms
#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 89999
#define INT_MIN -89999
void bestFit(int *processes, int *memories, int max_pros, int max_mems){
int selected_process = 0;
int selected_memory = 0;
int t = max_pros;
while(t--){
int best_fitting_memory = INT_MAX;
for(int i = 0; i < max_mems; i++){
if(processes[selected_process] <= memories[i]){
if(best_fitting_memory > abs(processes[selected_process] - memories[i])){
best_fitting_memory = abs(processes[selected_process] - memories[i]);
selected_memory = i;
}
}
}
if(best_fitting_memory == INT_MAX){
printf("Process %d cannot be allocated Memory\n",

processes[selected_process]);
}
else{
printf("Process %d allocated to memory %d\n", processes[selected_process],
memories[selected_memory]);
memories[selected_memory] = best_fitting_memory;
}
selected_process++;
}
}
void worstFit(int *processes, int *memories, int max_pros, int max_mems){
int selected_process = 0;
int selected_memory = 0;
int t = max_pros;
while(t--){

int worst_fitting_memory = INT_MIN;
for(int i = 0; i < max_mems; i++){
if(processes[selected_process] <= memories[i]){
if(worst_fitting_memory < abs(processes[selected_process] - memories[i])){
worst_fitting_memory = abs(processes[selected_process] - memories[i]);
selected_memory = i;
}
}
}
if(worst_fitting_memory == INT_MIN){
printf("Process %d cannot be allocated Memory\n",

processes[selected_process]);
}
else{
printf("Process %d allocated to memory %d\n", processes[selected_process],
memories[selected_memory]);
memories[selected_memory] = worst_fitting_memory;
}
selected_process++;
}
}
void firstFit(int *processes, int *memories, int max_pros, int max_mems){
int selected_process = 0;
int selected_memory = 0;
int t = max_pros;
while(t--){
int flag = 0;
for(int i = 0; i < max_mems; i++){
if(processes[selected_process] <= memories[i]){
selected_memory = i;
flag = 1;
break;
}
}
if(!flag){
printf("Process %d cannot be allocated Memory\n",

processes[selected_process]);
}
else{
printf("Process %d allocated to memory %d\n", processes[selected_process],
memories[selected_memory]);
memories[selected_memory] = abs(processes[selected_process] -
memories[selected_memory]);
}
selected_process++;
}
}
int main() {
int processes[] = {212, 417, 112, 426};
int memories[] = {100, 500, 200, 300, 600};
int max_nums = sizeof(processes) / sizeof(processes[0]);
int max_mems = sizeof(memories) / sizeof(memories[0]);
// printf("BEST FIT\n");

#include <stdio.h>
#include <stdlib.h>
// Function to implement FCFS disk scheduling algorithm
void fcfs(int *requests, int num_requests, int head_position) {
int total_seek_time = 0;
int current_position = head_position;
for (int i = 0; i < num_requests; i++) {
printf("Head Moved %d -> %d\n", current_position, requests[i]);
total_seek_time += abs(requests[i] - current_position);
current_position = requests[i];
}
printf("\nFCFS: Total seek time = %d\n", total_seek_time);
}
// Function to implement SCAN disk scheduling algorithm
void scan(int *requests, int num_requests, int head_position, int max_cylinder) {
int total_seek_time = 0;
int current_position = head_position;
Output:

2: Disk Scheduling Algorithms
Code:
// bestFit(processes, memories, max_nums, max_mems);
// printf("\nWORST FIT\n");
// worstFit(processes, memories, max_nums, max_mems);
printf("\nFIRST FIT\n");
firstFit(processes, memories, max_nums, max_mems);
return 0;
}