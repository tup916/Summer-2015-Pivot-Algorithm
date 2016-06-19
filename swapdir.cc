//
//  swapdir.cpp
//  
//
//  Created by Tushita Patel on 2015-08-02.
//
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "Pivot_initializer.h"
using namespace std;
#include <iomanip>

//Moves the polygon: wherever it is on the lattice
//to the top left-most corner of the lattice
void middletoside(int lattice[12][12], list *rlist){
    
    int xway = rlist->elements[0].x;
    int yway = rlist->elements[0].y;
    
    for (int i=1; i<size; i++){
        if (xway>rlist->elements[i].x){
            xway = rlist->elements[i].x;
        }
        if (yway>rlist->elements[i].y){
            yway = rlist->elements[i].y;
        }
    }
    
    for (int i=0; i<size; i++){
        rlist->elements[i].x = rlist->elements[i].x - xway;
        rlist->elements[i].y = rlist->elements[i].y - yway;
    }
    changelattice(lattice, rlist);
}

//Moves the polygon: from the top left-most corner of the lattice
// to the middle on the lattice
void sidetomiddle(int lattice[12][12], list *rlist){
    
    for (int i=0; i<size; i++){
        rlist->elements[i].x = rlist->elements[i].x + 4;
        rlist->elements[i].y = rlist->elements[i].y + 4;
    }
    changelattice(lattice, rlist);
}



//============================== REPEAT OF COORDINATES ======================================
// Is there is a repeat/overlap of edges?
bool repeatofcoord(list *rnew){
    
    for (int i=0; i<11; i++){
        for (int j=i+1; j<size; j++){
            if (rnew->elements[i].x == rnew->elements[j].x && rnew->elements[i].y == rnew->elements[j].y)
                return true;
        }
    }
    
    return false;
}

//============================= IS AROUND ================================================
//checks if the 11th index is adjacent to the 0th index.
bool isAround(element eleven, element zero){
    
    if (abs(eleven.x - zero.x) + abs(eleven.y - zero.y) == 1)
        return true;
    else
        return false;
    
}

//================================================ SWAP DIR ====================================================

list *swappingmethod(list *rListmain, int lattice[12][12], int a, int b){
    
// Create a new list, and copy everything from the previous list, so any changes made to this one, don't change the previous one.
    changelattice(lattice, rListmain);
    list *rnew = new list;
    if (rnew == NULL){
        cout << "Memory is full. " << endl;
        return NULL;
    }
    for(int i = 0; i<size; i++)
    {
        rnew->elements[i] = rListmain->elements[i];
    }
    
    sidetomiddle(lattice, rnew);
// ==================================== MAIN THING: SWAPPING DIRECTIONS BEGINS ================================
//  Erase the 1s from between a and b, so we can overlap, if there is any, on these.
//  Also, count the number of points in between a and b, using c. (c is the numof directions that would be changed
    int c=0;
    for (int i= (a+1)%size; i!=b; i= (i+1)%size){
        lattice[rnew->elements[i].x][rnew->elements[i].y] = 0;
        c++;
    }
    //    cout << "Erased the things in between the two points: " << endl;
    
    c++; // Add one because the direction of a is changed too
    
// store the directions in an array, arr, so we can swap them later (There is a shortcut, but I feel like this is a safer way
    int arr[c]; //an array of directions
    int k= 0;
    for (int i= a; i!=b; i=(i+1)%size){
//        cout << rnew->elements[i].dir << " ";
        arr[k] = rnew->elements[i].dir;
        k++;
    }
// Finally swap
    k= c-1;
    for (int i =a; i!=b; i= (i+1)%size){
        rnew->elements[i].dir = arr[k];
        k--;
    }

// ================================== MAIN THING: SWAPPING DIRECTIONS OVER ====================================
    
//check that subsequent coordinates aren't the opposites - no reverse overlaps
// Making sure there are no adjacent opposites
    for (int i=0; i<size; i++){
        
        if ((rnew->elements[i].dir == 1 && rnew->elements[(i+1)%size].dir == 2) ||
            (rnew->elements[i].dir == 2 && rnew->elements[(i+1)%size].dir == 1)||
            (rnew->elements[i].dir == 3 && rnew->elements[(i+1)%size].dir == 4) ||
            (rnew->elements[i].dir == 4 && rnew->elements[(i+1)%size].dir == 3))
        {
            changelattice(lattice, rListmain);
            delete rnew;
            return NULL;
        }
    }

//    This is where coordinates are redone:
//  change/modify x and y values based on what direction they have
    k = a;
    while (k != b){
        
        if (rnew->elements[k].dir == 4) {
            rnew->elements[(k+1)%size].x = rnew->elements[k].x + 1;
            rnew->elements[(k+1)%size].y = rnew->elements[k].y;
        }
        if (rnew->elements[k].dir == 3) {
            rnew->elements[(k+1)%size].x = rnew->elements[k].x - 1;
            rnew->elements[(k+1)%size].y = rnew->elements[k].y;
            
        }
        if (rnew->elements[k].dir == 1) {
            rnew->elements[(k+1)%size].x = rnew->elements[k].x;
            rnew->elements[(k+1)%size].y = rnew->elements[k].y + 1;
        }
        if (rnew->elements[k].dir == 2) {
            rnew->elements[(k+1)%size].x = rnew->elements[k].x;
            rnew->elements[(k+1)%size].y = rnew->elements[k].y - 1;
        }
        k = (k+1)%size;
    }
    

    
//  if elements[11] is not around elements[0] or there is a reverse-overlap
    if ( repeatofcoord(rnew) == true || isAround(rnew->elements[11], rnew->elements[0]) == false || flippedpoly(rnew) == true)
    {
        changelattice(lattice, rListmain);
        delete rnew;
        return NULL;
    }
    
// If there is an already occupied point, i.e. there is an overlap, send back the previous list
    for (int i=(a+1)%size; i!=b; i= (i+1)%size){
        if (lattice[rnew->elements[i].x][rnew->elements[i].y] != 0)
        {
            changelattice(lattice, rListmain);
            delete rnew;
            return NULL;
            
        }
    }
// At this stage, there is nothing wrong with rnew, and rnew is totally do-able.
// All the cases when rnew is not doable, we returned the previous list.
// change the lattice according to the new one, now that this is possible
    middletoside(lattice, rnew);

    
    return rnew;
}
