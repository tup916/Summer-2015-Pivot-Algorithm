// Using IO manipulators : setw 

#include <cstdlib> 
#include <iostream> 
#include "Pivot_initializer.h"
#include "swapdir.h"
#include <iomanip>
using namespace std ;

void middletoside(int lattice[12][12], list *rlist){
    
    int xway = rlist->elements[0].x;
    int yway = rlist->elements[0].y;
    
    for (int i=1; i<12; i++){
        if (xway>rlist->elements[i].x){
            xway = rlist->elements[i].x;
        }
        if (yway>rlist->elements[i].y){
            yway = rlist->elements[i].y;
        }
    }
    
    for (int i=0; i<12; i++){
        rlist->elements[i].x = rlist->elements[i].x - xway;
        rlist->elements[i].y = rlist->elements[i].y - yway;
    }
    changelattice(lattice, rlist);
}

void sidetomiddle(int lattice[12][12], list *rlist){
    
    for (int i=0; i<12; i++){
        rlist->elements[i].x = rlist->elements[i].x + 4;
        rlist->elements[i].y = rlist->elements[i].y + 4;
    }
    changelattice(lattice, rlist);
}


