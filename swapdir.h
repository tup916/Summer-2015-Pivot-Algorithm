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
using namespace std;
#include <iomanip>


void middletoside(int lattice[12][12], list *rlist);
void sidetomiddle(int lattice[12][12], list *rlist);
bool repeatofcoord(list *rnew);
bool isAround(element eleven, element zero);
list *swappingmethod(list *rListmain, int lattice[12][12], int a, int b);
    
 