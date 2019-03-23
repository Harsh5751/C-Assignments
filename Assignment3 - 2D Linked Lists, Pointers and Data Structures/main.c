#include <stdio.h>
#include <stdlib.h>
#include "assignment3.h"

// test functions
int checkHBList(HBnodePtr node, int n, int m);
int checkFlatten(SLnodePtr P1, SLnodePtr PAns);
int checkBottomList(SLnodePtr node, int m, int numnodes);

int main(int argc, char **argv) 
{
  
  int markCreate, markFlatten;
  int n = atoi(argv[1]), m = atoi(argv[2]);
  HBnodePtr L = createHBlist(n,m);
  markCreate = checkHBList(L, n, m);
  
  HBnodePtr gen = createHBlistAns(n,m);
  SLnodePtr P1 = flattenList(gen);
  SLnodePtr P2 = flattenListAns(gen);
  markFlatten = checkFlatten(P1, P2);

  freeSLlistAns(P2);
  freeHBlistAns(gen);

  freeSLlist(P1);
  freeHBlist(L);
  
  if (n >= 100) {
	  markCreate *= 2;
	  markFlatten *= 2;
  }
  
  printf("n = %4d, m = %4d:        %d         %d\n", n, m, markCreate, markFlatten);
  
  return 0;
}

int checkHBList(HBnodePtr node, int n, int m) {
    // nodes exhausted
    if (node == NULL && n == 0) return 1;
    else if (node == NULL) return 0;
    
    // check bottom list
    if (checkBottomList(node->bottom, m, 0) == 0) return 0;
    // if bottom exists, check immediate key relation
    if (node->bottom != NULL && node->bottom->key < node->key) return 0;

    // check ordering of HBList
    if (node->next != NULL && node->next->key < node->key) return 0;
    return checkHBList(node->next, n-1, m);
}

int checkBottomList(SLnodePtr node, int m, int numnodes) {
    if (node == NULL && numnodes <= m) return 1;
    else if (node == NULL) return 0;

    if (node->next != NULL && node->next->key < node->key) return 0;
    return checkBottomList(node->next, m, numnodes+1);
}

int checkFlatten(SLnodePtr P1, SLnodePtr PAns) {
    while (PAns != NULL) {
        if (P1->key != PAns->key) return 0;
        P1 = P1->next; PAns = PAns->next;
    }
    return 1;
}


