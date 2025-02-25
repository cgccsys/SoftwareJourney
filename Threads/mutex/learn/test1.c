#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  pthread_spinlock_t lock;
  pthread_mutex_t test;
  if (argc != 2) {
    fprintf(stderr, "Error/n");
    exit(1);
  }
  char *str = argv[1];
  pthread_spin_init(&lock, 1);
  while (1) {
    printf("%s\n", str);
    int inp;
    printf("Enter your choice 1 to continue\n");
    scanf("%d", &inp);
    if (inp == 1) {
      continue;
    } else {
      break;
    }
  }
  pthread_spin_destroy(&lock);
  return 0;
}
