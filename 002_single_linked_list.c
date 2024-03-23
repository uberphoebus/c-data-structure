#include <stdio.h>

typedef struct NODE {
  int nData;         // data
  struct NODE *next; // next node pointer
} NODE;

int main() {

  // test node
  NODE list[5] = {0};

  list[0].nData = 100;
  list[1].nData = 200;
  list[2].nData = 300;
  list[3].nData = 400;
  list[4].nData = 500;

  // connect
  list[0].next = &list[4];
  list[1].next = &list[2];
  list[2].next = &list[3];
  list[3].next = 0;
  list[4].next = &list[1];

  for (int i = 0; i < 5; ++i)  {
    printf("list[%d] : %d [%p]\n", i, list[i].nData, list[i].next);
  }

  NODE *pTmp = &list[0]; // pointing first node head
  while (pTmp != NULL) {
    printf("%p : %d\n", pTmp, pTmp->nData);
    pTmp = pTmp->next; // overwrite pointing address
  }

  return 0;
}