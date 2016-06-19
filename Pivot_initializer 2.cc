//
//  Pivot_initializer.cpp
//  
//
//  Created by Tushita Patel on 2015-08-01.
//
//
#include <iostream>
#include <cstdlib>
#include "Pivot_initializer 2.h"
using namespace std;
#include <iomanip>
#include "swapdir.h"

//=========================================== JUST INITIALIZATIONS =================================
list *initialize(){
    list *toReturn = new list;
 
    return toReturn;
}

void putXYDir(list *rList){
    
    rList->elements[0].x = 7;
    rList->elements[0].y = 4;
    rList->elements[0].dir = 3;
    rList->elements[1].x = 6;
    rList->elements[1].y =4;
    rList->elements[1].dir = 3;
    rList->elements[2].x = 5;
    rList->elements[2].y = 4;
    rList->elements[2].dir = 3;
    rList->elements[3].x = 4;
    rList->elements[3].y =4;
    rList->elements[3].dir = 1;
    rList->elements[4].x = 4;
    rList->elements[4].y =5;
    rList->elements[4].dir =1;
    rList->elements[5].x = 4;
    rList->elements[5].y =6;
    rList->elements[5].dir =1;
    rList->elements[6].x =4;
    rList->elements[6].y =7;
    rList->elements[6].dir =4;
    rList->elements[7].x =5;
    rList->elements[7].y =7;
    rList->elements[7].dir =4;
    rList->elements[8].x =6;
    rList->elements[8].y =7;
    rList->elements[8].dir =4;
    rList->elements[9].x =7;
    rList->elements[9].y =7;
    rList->elements[9].dir =2;
    rList->elements[10].x =7;
    rList->elements[10].y =6;
    rList->elements[10].dir =2;
    rList->elements[11].x =7;
    rList->elements[11].y =5;
    rList->elements[11].dir =2;
}
//=========================================== PRINT LATTICE =================================
void printLattice(int lattice[12][12]) {
    for (int i = 0; i<12; i++){
        for (int j=0; j<12; j++){
            std::cout << lattice[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl << std::endl;
}

//=========================================== CHANGE LATTICE =================================
void changelattice(int lattice[12][12], list *rListmain){
    
    for (int m=0; m<12; m++){
        for (int n=0; n<12; n++){
            lattice[m][n] = 0;
        }
    }
    for  (int i=0; i<12; i++){
    lattice[rListmain->elements[i].x][rListmain->elements[i].y] = 1;
    }

}
//=========================================== PRINT LATTICE DIRECTIONS =================================
void printlatticeDir(list *rlist){
    
    int latDir[12][12];
    for (int i=0; i<12;i++){
        for (int j=0; j<12; j++)
            latDir[i][j] = 0;
    }
    
    for (int i=0; i<12; i++){
        latDir[rlist->elements[i].x][rlist->elements[i].y] = rlist->elements[i].dir;
    }
    
     cout << "This is what the directio lattice looks like: " <<endl;
    
    for (int i=0; i<12; i++)
    {
        for (int j=0; j<12; j++){
            std::cout << latDir[i][j] << "  ";
        }
        std::cout << std::endl;
    }
   
    std::cout << std::endl << std::endl;

}

//=========================================== PRINT LIST =================================
void printList(list *rList){
    for(int i=0; i<12; i++){
        std::cout << "[" << rList->elements[i].x << "," << rList->elements[i].y << " :" << rList->elements[i].dir << ":]  " ;
    }

    cout << endl << endl;
}

//=========================================== PRINT SEQUENCE =================================
void printSequence(list *rlist){
    
    int latt[12][12];
    for (int i=0; i<12;i++)
    {
        for (int j=0; j<12; j++){
            latt[i][j] = 0;
        }
    }
    
    for (int i=0; i<12; i++)
    {
        latt[rlist->elements[i].x][rlist->elements[i].y] = i+1;
    }
    
    for (int i = 0; i<12; i++){
        for (int j=0; j<12; j++){

            std::cout << setw(3) << latt[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl << std::endl;

}

//================== MIRROR ================= M I R R O R =======================================================================
list* mirror(list* rListmain, int lattice[12][12], int a, int b){
    list *rnew = new list;
    //coping rListmain to rnew
    for(int i = 0; i<12; i++)
    {
        rnew->elements[i] = rListmain->elements[i];
    }

//    Erasing the things in between the two points
    for (int i= (a+1)%12; i!=b; i= (i+1)%12)
    {
        lattice[rnew->elements[i].x][rnew->elements[i].y] = 0;
    }

  
    // gotta find max directions, and then swap direction meaning accordingly
    //calculate #4s, 1s, 2, and 3s
    int one=0, two=0,three=0, four=0;
    for (int i=a; i!=b; i= (i+1)%12)
    {
        if (rListmain->elements[i].dir == 1) one++;
        if (rListmain->elements[i].dir == 2) two++;
        if (rListmain->elements[i].dir == 3) three++;
        if (rListmain->elements[i].dir == 4) four++;
    }
    
    
    // DETERMINE WHICH WAY TO SWITCH
//    cout << "#1: " << one << " #2: " << two << " #3: " << three << " #4: " << four << endl;
    if ((max(one, two) == one && max(three, four) == four) || (max(one, two) == two && max(three, four) == three)){
    for (int i= a; i!=b; i= (i+1)%12){
        if (rListmain->elements[i].dir ==1){
            rnew->elements[i].dir = 4;
        }
        if (rListmain->elements[i].dir ==2){
            rnew->elements[i].dir = 3;
        }
        if (rListmain->elements[i].dir ==4){
            rnew->elements[i].dir = 1;
        }
        if (rListmain->elements[i].dir ==3){
            rnew->elements[i].dir = 2;
        }
    }}
    else {
       
        for (int i= a; i!=b; i= (i+1)%12){
            if (rListmain->elements[i].dir ==1){
                rnew->elements[i].dir = 3;
            }
            if (rListmain->elements[i].dir ==2){
                rnew->elements[i].dir = 4;
            }
            if (rListmain->elements[i].dir ==4){
                rnew->elements[i].dir = 2;
            }
            if (rListmain->elements[i].dir ==3){
                rnew->elements[i].dir = 1;
            }
        }
        
    }
    
    //check that subsequent coordinates aren't the opposites - no overlaps
    
    for (int i=0; i<12; i++){
        
        if ((rnew->elements[i].dir == 1 && rnew->elements[(i+1)%12].dir == 2) ||
            (rnew->elements[i].dir == 2 && rnew->elements[(i+1)%12].dir == 1)||
           (rnew->elements[i].dir == 3 && rnew->elements[(i+1)%12].dir == 4) ||
            (rnew->elements[i].dir == 4 && rnew->elements[(i+1)%12].dir == 3)){
            
            changelattice(lattice, rListmain);
            
            return rListmain;
        }
        
    }
    
    
//    This is where coordinates are redone:
    int k = a;
    while (k != b)
    {
        
        if (rnew->elements[k].dir == 4) {
            rnew->elements[(k+1)%12].x = rnew->elements[k].x + 1;
            rnew->elements[(k+1)%12].y = rnew->elements[k].y;
        }
        if (rnew->elements[k].dir == 3) {
            rnew->elements[(k+1)%12].x = rnew->elements[k].x - 1;
            rnew->elements[(k+1)%12].y = rnew->elements[k].y;
            
        }
        if (rnew->elements[k].dir == 1) {
            rnew->elements[(k+1)%12].x = rnew->elements[k].x;
            rnew->elements[(k+1)%12].y = rnew->elements[k].y + 1;
        }
        if (rnew->elements[k].dir == 2) {
            rnew->elements[(k+1)%12].x = rnew->elements[k].x;
            rnew->elements[(k+1)%12].y = rnew->elements[k].y - 1;
        }

            k = (k+1)%12;
    }
    
    //     elements[11] is not around elements[0]
    if ( repeatofcoord(rnew) == true || isAround(rnew->elements[11], rnew->elements[0]) == false )
    {
        
        cout << "Couldn't believe this would happen" << endl;
        changelattice(lattice, rListmain);
        cout << "lattice renewed because of non-touching ends" << endl;
        return rListmain;
    }
    

    for (int i=(a+1)%12; i!=b; i= (i+1)%12)
    {
        if (lattice[rnew->elements[i].x][rnew->elements[i].y] != 0)
        {
            changelattice(lattice, rListmain);

            return rListmain;
        }
    }
    
    
    changelattice(lattice, rnew);

    return rnew;
    
}

//======================================================================================================================
bool same(list *rnewly, list*already){

    for (int i=0; i<12; i++){
        if (rnewly->elements[i].x == already->elements[i].x && rnewly->elements[i].y == already->elements[i].y){
            
        }
        else return false;
    }
    
    return true;
}

bool samelists(list *rnewly, list *rList[], int numoflists){

    for (int p=0; p<numoflists; p++){
        if (same(rnewly, rList[p]) == true){
            return true;
        }
    }
            return false;
}
