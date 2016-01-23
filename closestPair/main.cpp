//
//  main.cpp
//  closestPair
//
//  Created by Nick Ray on 1/17/16.
//  Copyright (c) 2016 test. All rights reserved.
//

#include <iostream>
#include "pairs.h"
#include <sstream>
#include "grid.h"
using namespace std;


ostream& operator<<(ostream& os, const coor& c)
{
    os << c.getX()<<", "<<c.getY();
    return os;
}

ostream& operator<<(ostream& os, const pair<coor, coor>& c)
{
    os << "("<<c.first.getX()<<", "<<c.first.getY()<<") ";
    os << "("<<c.second.getX()<<", "<<c.second.getY()<<")";
    return os;
}

double mid(double a, double b){
    return min(a,b)+abs(a-b)/2;
}

int main(int argc, const char * argv[]) {
    grid myGrid;
    bool testing = false;

    if(!testing){
        std::string line;
        while (std::getline(cin, line))
        {
            std::istringstream iss(line);
            double a, b;
            if (!(iss >> a >>std::skipws >> b)) {
                continue;
            }
                myGrid.add(a,b);
        }
    }else{
        myGrid.randGrid(10000, -10000, 10000);
    }
    
    myGrid.removeDups();
    
    if(argv[1]=="brute" || testing){
        pairOfCoors q = myGrid.brute();
        cout << "closest pair distance: "<< myGrid.distanceBetween(q)<<endl;
        cout << "closest pair:\n"<< q <<endl;
    }
    
    
    if(argv[1]=="basic" || testing){
        pairOfCoors q = myGrid.basic(true, 0, myGrid.n());
        cout << "closest pair distance: "<< myGrid.distanceBetween(q) <<endl;
        cout << "closest pair:\n"<< q <<endl;
    }
    
    
    if(argv[1]=="optimal" || testing){
        pairOfCoors q = myGrid.optimal();
        cout << "closest pair distance: "<< myGrid.distanceBetween(q) <<endl;
        cout << "closest pair:\n"<< q <<endl;
    }
    
    return 0;
}
