#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

// Shared bank account balance
int balance = 0;
pthread_mutex_t balance_mutex;

//
// Function for deposit/withdrawal
void *transaction(void *args) {
  int choice = *(int *(*args));
  pthread_mutex_lock(&balance_mutex);
  printf("Enter amount\n");
  scanf("%d", &choice);
  balance = choice + balance;
  pthread_mutex_unlock(&balance_mutex);
  return NULL;
}

int main() {
  pthread_t threads[NUM_THREADS];

  pthread_mutex_init(&balance_mutex, NULL);

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, transaction, NULL);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&balance_mutex);

  printf("Final balance: %d\n", balance);

  return 0;
}
