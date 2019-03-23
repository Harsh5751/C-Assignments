/* File assignment3.h */
#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

/* Node in a singly linked list */
struct SLnode {
  int            key;
  struct SLnode *next; /* pointer to the next item in a list */
};

typedef struct SLnode *SLnodePtr;

/* Node in the "horizontal" list */
struct HBnode {
  int            key;
  struct HBnode *next; /* pointer to the next item in the
                             horizontal list */
  SLnodePtr bottom;    /* pointer to the bottom list */
};

typedef struct HBnode *HBnodePtr;

HBnodePtr createHBlist(int n, int m);
SLnodePtr flattenList(const HBnodePtr L);
void freeSLlist(SLnodePtr L);
void freeHBlist(HBnodePtr L);
void printHBlist(const HBnodePtr L);
void printSLlist(const SLnodePtr L);

// test functions
HBnodePtr createHBlistAns(int n, int m);
SLnodePtr flattenListAns(const HBnodePtr L);
void freeSLlistAns(SLnodePtr L);
void freeHBlistAns(HBnodePtr L);

#endif /* ASSIGNMENT3_H */
