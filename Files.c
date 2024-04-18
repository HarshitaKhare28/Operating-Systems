// Aim: Write a C program to implement I/O System Calls of Linux.
// a) Create a file
// b) Read contents of a file
// c) Write to a file
// d) Read contents of a file in a reverse order
// e) Search the file to find the given pattern (Grep command)
// f) Delete a file
// g) To print file status using stat
// h) To print file status using fstat
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
//create a file
struct stat file_stat;
creat ("file1.txt",S_IREAD |S_IWRITE);
int file = open("file1.txt",O_WRONLY | O_CREAT,0777);
printf("file created \n");
//write to a file
int w = write(file,"Shri Ramdeobaba College Of Engineering",38);
close(file);
//read from the file
char c1[50];
file =open("file1.txt",O_RDONLY | O_CREAT,0777);
int r = read(file,c1,40);
printf("contents of file are: \n");
puts(c1);
close(file);
//reverse the file
file = open("file1.txt",O_RDWR | O_CREAT,0777);
int sz = lseek(file,-1,SEEK_END);
printf("sz = %d",sz);

printf("\nreverse of file: ");
while(sz >= 0){
read(file, &c1,1);
printf("%c",c1[0]);
lseek(file,-2,SEEK_CUR);
sz--;
}
printf("\n");
close(file);
// search the pattern using grep:
//file=open("file1.txt",O_WRONLY | O_CREAT,0777);
//w=write(file,"Shri Ramdeobaba College Of Engineering",38);
//close(file);
char command[1024];
char pattern[100];
file = open("file1.txt", O_RDONLY);
printf("Enter Pattern: ");
scanf(" %[^\n]",pattern);
sprintf(command, "grep \"%s\" %s", pattern,"file1.txt");
printf("Executing command: %s\n", command);
system(command);
//stat
printf("Details of file using stat function: \n");
stat("prac2.c", &file_stat) ;
printf("\nFile Size: %ld bytes\n", file_stat.st_size);
printf("File Permissions: %o\n", file_stat.st_mode & 0777);
printf("File Owner UID: %d\n", file_stat.st_uid);
printf("File Group GID: %d\n", file_stat.st_gid);
printf("Last Access Time: %ld\n", file_stat.st_atime);
printf("Last Modification Time: %ld\n", file_stat.st_mtime);
printf("Last Status Change Time: %ld\n", file_stat.st_ctime);
//fstat
printf("Details of file using fstat function: \n");
file = open("file1.txt",O_RDWR | O_CREAT,0777);
fstat(file, &file_stat) ;
printf("\nFile Size: %ld bytes\n", file_stat.st_size);
printf("File Permissions: %o\n", file_stat.st_mode & 0777);
printf("File Owner UID: %d\n", file_stat.st_uid);
printf("File Group GID: %d\n", file_stat.st_gid);
printf("Last Access Time: %ld\n", file_stat.st_atime);
printf("Last Modification Time: %ld\n", file_stat.st_mtime);
printf("Last Status Change Time: %ld\n", file_stat.st_ctime);
close(file);
//delete file
unlink(“file1.txt”);
printf("\nfile deleted successfully\n");
return 0;
}