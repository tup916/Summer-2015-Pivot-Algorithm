//
//  Pivot_initializer.h
//  
//
//  Created by Tushita Patel on 2015-08-01.
//
//

#ifndef ____Pivot_initializer__
#define ____Pivot_initializer__

#include <stdio.h>

#endif /* defined(____Pivot_initializer__) */


struct element{
    int x;
    int y;
    int dir;
    element *prev, *next;
};

struct list{
    element elements[12];
};


list *initialize();
void putXYDir(list *rList);
void printLattice(int lattice[12][12]);
void changelattice(int lattice[12][12], list *rListmain);
void printlatticeDir(list *rlist);
void printList(list *rList);
void printSequence(list *rlist);
list* mirror(list* rListmain, int lattice[12][12], int a, int b);
bool samelists(list *rListmain, list *[], int numoflists);




