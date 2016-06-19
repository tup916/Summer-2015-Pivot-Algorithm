//
//  2dPivot.cpp
//  
//
//  Created by Tushita Patel on 2015-07-29.
//
//
#include <iostream>
using namespace std;
#include "2dPivot.h"
#include "Pivot_initializer.h"
#include <cstdlib>
#include <time.h>
#include <math.h>
#include "swapdir.h"



int main(){
    srand(time(NULL));
//=========================Initialize lattice============================
    int lattice[12][12];
    
    for (int i = 0; i<12; i++){
        for (int j=0; j<12; j++){
            lattice[i][j] = 0;
        }
    }
//    printLattice(lattice); // Gonna print all zeroes
//=======================================================================
    
    list *rListmain = initialize();
    putXYDir(rListmain);
    changelattice(lattice, rListmain);
//    printList(rListmain);
    
    
//============================================ S W A P   D I R ===================================
    
//    printSequence(rListmain);
//    printLattice(lattice);
    
//========================================================== PIVOT INITIALIZATION =================


    
    
    int count = 0;
    printSequence(rListmain);
    int flippt1, flippt2;
    list *rList[1000];
    list *rnewly;
    int numoflists = 1;
    rList[0] = rListmain;
    bool firstway;
    int current =0;
    int stuck = 0;
    
    while (numoflists < 125)
    {
        if (stuck >= 100)   current = rand()%(numoflists-1);
        else current = numoflists;
        
        
        do{
            flippt1 = rand()%12;
            flippt2 = rand()%12; //two numbers between 0 and 11 (including)
        }while (flippt2==flippt1);
    
            if (flippt2 < flippt1) //swap, lowest to highest
            {
                int temp = flippt2;
                flippt2 = flippt1;
                flippt1 = temp;
            }
        if (flippt2-flippt1 == 6){
            if (rand()%2 == 1) firstway = true;
            else firstway = false;
        }
        if (flippt2 - flippt1 <6 || firstway) //shorted distance is between them
        {
            if (abs(rList[current-1]->elements[flippt1].x - rList[current-1]->elements[flippt2].x) == abs(rList[current-1]->elements[flippt1].y - rList[current-1]->elements[flippt2].y))
            {
                rnewly = mirror(rList[current-1], lattice, flippt1, flippt2);
                
                if (samelists(rnewly, rList, numoflists) == false)
                {
                    rList[numoflists] = rnewly;
                    stuck = 0;
                    numoflists++;
                    cout << "#" << numoflists << endl;
                    printLattice(lattice);
                    printList(rnewly);
                }
                else stuck++;
            }
            else
            {
                    rnewly = swappingmethod(rList[current-1], lattice, flippt1, flippt2);
     
                    if (samelists(rnewly, rList, numoflists) == false)
                    {
                        rList[numoflists] = rnewly;
                        stuck = 0;
                        numoflists++;
                        cout << "#" << numoflists << endl;
                        printLattice(lattice);
                        printList(rnewly);
                    }
                    else stuck++;
            }
        }
        else // shorter distance is the other way round
        {
              if (abs(rList[current-1]->elements[flippt1].x - rList[current-1]->elements[flippt2].x) == abs(rList[current-1]->elements[flippt1].y - rList[current-1]->elements[flippt2].y))
              {
                  rnewly = mirror(rList[current-1], lattice, flippt2, flippt1);
                  
                  if (samelists(rnewly, rList, numoflists) == false)
                  {
                      rList[numoflists] = rnewly;
                      stuck++;
                      numoflists++;
                      cout << "#" << numoflists << endl;
                      printLattice(lattice);
                      printList(rnewly);
                  }
                  else stuck++;
              }
             else
             {
                    
                     rnewly = swappingmethod(rList[current-1], lattice, flippt2, flippt1);
     
                     if (samelists(rnewly, rList, numoflists) == false)
                     {
                         rList[numoflists] = rnewly;
                         stuck = 0;
                         numoflists++;
                         cout << "#" << numoflists << endl;
                         printLattice(lattice);
                         printList(rnewly);
                     }
                     else stuck++;
            }
        }
        
        count++;
    }
    

    
    
    
    
//    else
//    {
//        if (rand()%100 <50)
//            cout << "we go " << flippt1 << " to " << flippt2;
//        else
//              cout << "we go " << flippt2 << " to " << flippt1;
//    }
//    
    
           
        
//    if (abs(rListmain->elements[flippt1].x - rListmain->elements[flippt2].x) == abs(rListmain->elements[flippt1].y - rListmain->elements[flippt2].y)){
//        rnew = mirror(rListmain, lattice, flippt1, flippt2);
//        cout << "This is from the main: " << endl;
//        printLattice(lattice);
//        printList(rnew);
//    }
//    else
//        cout << "NO MIRROR";
    
        return 0;
}
