//shared memory concept 
//uing shmget and shmat
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
void main()
{ int sh_s;
int a[20],i,s=0,*su;
pid_t pid;
sh_s=shmget(IPC_PRIVATE,2,S_IRUSR|S_IWUSR);
su=(int *)shmat(sh_s,NULL,0);
printf("Enter array elements :\n");
for(i=0;i<20;i++)
scanf("%d",&a[i]);
pid=fork();
if (pid==0)
{
printf("PID for 1st process is :%d\n",getpid());
for(i=0;i<10;i++)
*su=*su+a[i];
printf("total sum is:%d\n",*su);
}
else
{
printf("PID for 2nd process is :%d\n",getpid());
for(i=10;i<20;i++)
*su=*su+a[i];

}
}