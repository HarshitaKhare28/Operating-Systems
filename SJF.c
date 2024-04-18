// code for the process scheduling algorithm: SJF(Shortest Job First)
#include<stdio.h>
// Structure to represent each process
struct Process {
int id; // Process ID
int burst_time; // Burst time (duration of execution)
int arrival_time; // Arrival time
int waiting_time; // Waiting time
int turnaround_time; // Turnaround time
};
// Function to perform SJF scheduling
void sjf(struct Process p[], int n) {
// Sort processes based on arrival time using bubble sort
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (p[j].arrival_time > p[j + 1].arrival_time) {
// Swap the processes
struct Process temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;
}
}
}
int current_time = 0; // Current time
float total_waiting_time = 0; // Total waiting time
float total_turnaround_time = 0; // Total turnaround time
// Calculate waiting time and turnaround time for each process
for (int i = 0; i < n; i++) {
if (current_time < p[i].arrival_time) {
current_time = p[i].arrival_time;
}
p[i].waiting_time = current_time - p[i].arrival_time;
total_waiting_time += p[i].waiting_time;
current_time += p[i].burst_time;
p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
total_turnaround_time += p[i].turnaround_time;
}
// Print results

printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
for (int i = 0; i < n; i++) {
printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].burst_time, p[i].arrival_time, p[i].waiting_time,
p[i].turnaround_time);
}
// Print average waiting time and average turnaround time
printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}
int main() {
int n;
printf("Enter the number of processes: ");
scanf("%d", &n);
// Input burst time and arrival time for each process
struct Process processes[n];
for (int i = 0; i < n; i++) {
printf("Enter burst time for process %d: ", i + 1);
scanf("%d", &processes[i].burst_time);
printf("Enter arrival time for process %d: ", i + 1);
scanf("%d", &processes[i].arrival_time);
processes[i].id = i + 1;
}
// Perform SJF scheduling
sjf(processes, n);
return 0;
}