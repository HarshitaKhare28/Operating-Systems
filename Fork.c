// Aim: To Demonstrate process control system calls
// fork
// vfork
// wait and sleep
// getpid and getppid
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/shm.h>
#define buf_size 100
main(void){
int a[]={-200,95,150,70,-11,-170,0,57};
pid_t pid;
int i;
int* min;
int* max;

char b[buf_size];
int segmant_id = shmget(IPC_PRIVATE, 2, S_IRUSR | S_IWUSR);
int id1=shmget(IPC_PRIVATE, 2, S_IRUSR | S_IWUSR);
// attach segmennt with variable to e used by process//
max = (int*)shmat(segmant_id, NULL, 0);
min = (int*)shmat(id1,NULL,0);
*max = -9999999;
*min= 99999999;
pid=fork();
//pid=vfork();
if(pid == 0){
for(int i = 0;i<8;i++){
if(a[i] < *min){
*min = a[i];
}
}
printf("Child Process: %d\n",getpid());
sleep(10);
sprintf(b,"\n Minimum=%d \n",*min);
write(1,b,strlen(b));
}else{
for(int i = 0;i<8;i++){
if(a[i] > *max){
*max = a[i];
}
}

pid_t getppid();
printf("\n Parent Process: %d\n",getppid());
sprintf(b,"\n Maximum=%d \n", *max);
write(1,b,strlen(b));
pid=wait(NULL);
if(pid!=-1)
printf("\n Maximum= %d\n\n",*max);
printf("\n Minimum= %d\n\n",*min);
}
return 0;
}