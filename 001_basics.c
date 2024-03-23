#include <stdio.h>

int test(int a) {
  printf("test() : hello world\n");
  return 0;
}

int test2(int a) {
  if (a <= 0) {
    return;
  }
  printf("test(%d)\n", a);
  return test2(a - 1);
}

int main() {
  test(5);
  int (*pfTest)(int) = test; // function pointer
  pfTest(5);

  // recursive function
  test2(5);
  return 0;
}