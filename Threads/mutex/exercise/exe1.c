/*Create a multi-threaded program where multiple threads increment a shared
 * counter 1000 times each. Use a mutex to ensure correct results.*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define INCRE 1000
#define THREAD_NUM 5

pthread_mutex_t thr;
int count = 0;
void *inc(void *args) {
  for (int i = 0; i < INCRE; i++) {
    pthread_mutex_lock(&thr);
    count++;
    pthread_mutex_unlock(&thr);
  }
  return NULL;
}
int main(int argc, char *argv[]) {
  pthread_t threads[THREAD_NUM];
  pthread_mutex_init(&thr, NULL);
  for (int i = 0; i < THREAD_NUM; i++) {
    pthread_create(&threads[i], NULL, inc, NULL);
  }
  for (int i = 0; i < THREAD_NUM; i++) {
    pthread_join(threads[i], NULL);
  }
  pthread_mutex_destroy(&thr);
  printf("%d\n", count);
  return 0;
}
