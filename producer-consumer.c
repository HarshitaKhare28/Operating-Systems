//classic producer consumer problem
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int buf[5], f = -1, r = -1; // Initialize f and r to -1
sem_t mutex, full, empty;
void *produce(void *arg)
{
int i;
for(i = 0; i < 10; i++)
{
sem_wait(&empty);
sem_wait(&mutex);
printf("produced item is %d\n", i);
r = (r + 1) % 5; // Update r using modular arithmetic
buf[r] = i;
sleep(1);
sem_post(&mutex);
sem_post(&full);
}
}
void *consume(void *arg)
{
int item, i;
for(i = 0; i < 15; i++)
{
sem_wait(&full);
sem_wait(&mutex);
f = (f + 1) % 5; // Update f using modular arithmetic
item = buf[f];
printf("consumed item is %d\n", item);
sleep(1);
sem_post(&mutex);
sem_post(&empty);
}
}
int main()
{
pthread_t tid1, tid2;
sem_init(&mutex, 0, 1);
sem_init(&full, 0, 0);
sem_init(&empty, 0, 5);
pthread_create(&tid1, NULL, produce, NULL);
pthread_create(&tid2, NULL, consume, NULL);

pthread_join(tid1, NULL);
pthread_join(tid2, NULL);
sem_destroy(&mutex);
sem_destroy(&empty);
sem_destroy(&full);
return 0;
}