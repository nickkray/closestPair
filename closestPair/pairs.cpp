//
//  pairs.cpp
//  closestPair
//
//  Created by Nick Ray on 1/18/16.
//  Copyright (c) 2016 test. All rights reserved.
//

#include "pairs.h"

coor::coor(double a, double b){
    l = a;
    r = b;
}

coor::coor(){
    l=0;
    r=0;
}

void coor::setX(double a){
    l = a;
}

void coor::setY(double b){
    r = b;
}

double coor::getX() const{
    return l;
}

double coor::getY() const{
    return r;
}

bool coor::withinRange(double highX, double lowX, double highY, double lowY){
    if (highX==0 && highY == 0 && lowX == 0 && lowY==0)
        return true;
    if(l>highX || l<lowX || r>highY || r<lowY)
        return false;
    return true;
}

bool coor::operator==(const coor &rhs) const{
    return ((this->l==rhs.l)&&(this->r==rhs.r));
}