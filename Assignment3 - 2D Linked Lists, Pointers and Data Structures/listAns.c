#include <stdio.h>
#include <stdlib.h>

#include "assignment3.h"

#define KEY_MAX 1000

static int *createSortedArray(int n, int min, int max);
static SLnodePtr createList(int n, int min);
static SLnodePtr copyList(SLnodePtr list);
static SLnodePtr mergeSortedLists(SLnodePtr L1, SLnodePtr L2);

HBnodePtr createHBlistAns(int n, int m) {
  int *a = createSortedArray(n, 0, KEY_MAX);

  HBnodePtr head = 0;
  for (int i = 0; i < n; i++) {
    // create HB node
    HBnodePtr tmp = malloc(sizeof(struct HBnode));
    // set key
    tmp->key = a[i];
    tmp->next = head;
    head = tmp;
    // creat the bottom list of size random()%m and entries >= a[i]
    tmp->bottom = createList(random() % (m + 1), a[i]);
  }
  free(a);
  return head;
}

SLnodePtr flattenListAns(const HBnodePtr head) {
  // if the list is empty return NULL
  if (head == NULL)
    return NULL;

  // at least one node
  HBnodePtr first = head, second = head->next;
  // create SL node
  SLnodePtr tmp1 = malloc(sizeof(struct SLnode));
  // copy the key from the first node
  tmp1->key = first->key;
  // copy the bottom list
  tmp1->next = copyList(head->bottom);
  while (second != NULL) {
    // create SL node
    SLnodePtr tmp2 = malloc(sizeof(struct SLnode));
    // copy the key
    tmp2->key = second->key;
    // copy the bottom list
    tmp2->next = copyList(second->bottom);
    // merge the tmp1 and tmp2 lists
    tmp1 = mergeSortedLists(tmp1, tmp2);
    second = second->next;
  }
  return tmp1;
}

void freeSLlistAns(SLnodePtr head) {
  while (head) {
    SLnodePtr freenode = head;
    head = head->next;
    free(freenode);
  }
}

void freeHBlistAns(HBnodePtr head) {

  while (head) {
    HBnodePtr freenode = head;
    head = head->next;
    freeSLlist(freenode->bottom);
    free(freenode);
  }
}
/***  STATIC FUNCTIONS ***/

// compare function for qsort
static int comp(const void *p1, const void *p2) {
  return *(int *)p2 - *(int *)p1;
}
static int *createSortedArray(int n, int min, int max) {
  // Generates an array of size n with entries between min and min+max
  // and sorts it in non-increasing order
  int *a = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    a[i] = min + rand() % max;
  qsort(a, n, sizeof(int), comp);
  return a;
}

static SLnodePtr copyList(SLnodePtr list) {
  // Returns a copy of SL list
  if (list == NULL)
    return NULL; // empty list
  SLnodePtr tmp = malloc(sizeof(struct SLnode));
  tmp->key = list->key;
  tmp->next = copyList(list->next);
  return tmp;
}

static SLnodePtr mergeSortedLists(SLnodePtr L1, SLnodePtr L2) {
  // Merges L1 and L2 and returns a pointer to the merged list.
  if (L1 == NULL)
    return L2; // L1 is empty
  if (L2 == NULL)
    return L1; // L2 is empty
  SLnodePtr L = NULL;
  if (L1->key <= L2->key) {
    L = L1;
    L->next = mergeSortedLists(L1->next, L2);
  } else {
    L = L2;
    L->next = mergeSortedLists(L1, L2->next);
  }
  return L;
}

static SLnodePtr createList(int n, int min) {
  // create a random array of size n with entries between min and
  // min+KEY_MAX and sort in non-increasing order
  int *a = createSortedArray(n, min, KEY_MAX);

  // insert the entries of the array into a linked list
  SLnodePtr head = 0;
  for (int i = 0; i < n; i++) {
    SLnodePtr tmp = malloc(sizeof(struct SLnode));
    tmp->key = a[i];
    tmp->next = head;
    head = tmp;
  }
  free(a);
  return head;
}
