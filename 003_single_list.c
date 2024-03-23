#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE {
  char szData[64];
  struct NODE *next;
} NODE;

NODE *g_pHead = NULL;

void PrintList(void) {
  NODE * pHead = g_pHead;
  while (pHead != NULL) {
    printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
    pHead = pHead->next;
  }
  putchar('\n');
}

int InsertNewNode(char *pszData) {
  NODE* pNode = (NODE*)malloc(sizeof(NODE));
  memset(pNode, 0, sizeof(NODE));
  strcpy(pNode->szData, pszData);

  if (g_pHead == NULL) {
    g_pHead = pNode;
  } else {
    pNode->next = g_pHead;
    g_pHead = pNode;
  }
  return 1;
}

int main() {

  // list test code
  InsertNewNode("TEST01");
  PrintList();
  InsertNewNode("TEST02");
  PrintList();
  InsertNewNode("TEST03");
  PrintList();
  return 0;
}