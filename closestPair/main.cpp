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

typedef pair<coor, coor> pairOfCoors;

pairOfCoors basic(grid &myGrid, bool sort){
    
    if(myGrid.n()<=3){
        return myGrid.findClosestInRange();
    }
    if(sort)
        myGrid.sortByX();
    int mid = round(myGrid.n()/2);
    double midpoint = myGrid.at(mid).getX();
    grid leftGrid = myGrid.indexRangedSubset(0, midpoint);
    grid rightGrid = myGrid.indexRangedSubset(midpoint, myGrid.n());
    
    pairOfCoors left, right;
    left = basic(leftGrid, sort);
    right = basic(rightGrid, sort);
    
    double leftD = myGrid.distanceBetween(left);
    double rightD = myGrid.distanceBetween(right);
    double bestD = min(leftD, rightD);
    
    grid centerGrid = myGrid.rangedSubset(midpoint + bestD, midpoint - bestD, INFINITY, -INFINITY);
    if(sort)
        centerGrid.sortByY();
    pairOfCoors center = centerGrid.findClosestInRange(0,0,0,0); //midpoint?
    
    double centerD = myGrid.distanceBetween(center);

    bestD = min(bestD, centerD);
    if(bestD==centerD)
        return center;
    if(bestD==leftD)
        return left;
    return right;
}

pairOfCoors optimal(grid &myGrid){
    
    myGrid.sortByX();
    myGrid.sortByY();
    return basic(myGrid, false);
}

pairOfCoors brute(grid &myGrid){
    return myGrid.findClosestInRange();
}



int main(int argc, const char * argv[]) {
    grid myGrid;
    bool testing = true;
    myGrid.randGrid(20000, -10000, 10000);
    
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
    }
    
    myGrid.removeDups();
    
    if(argc!=1 && !testing)
        return 1;
    
    
    clock_t t1,t2;
    t1=clock();
    
    
    if(argv[1]=="brute" || testing){
        pairOfCoors q = brute(myGrid);
        cout << "closest pair distance: "<< myGrid.distanceBetween(q)<<endl;
        cout << "closest pair:\n"<< q <<endl;
    }
    
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<diff<<endl;
    t1=clock();
    
    if(argv[1]=="basic" || testing){
        pairOfCoors q = basic(myGrid, true);
        cout << "closest pair distance: "<< myGrid.distanceBetween(q) <<endl;
        cout << "closest pair:\n"<< q <<endl;
    }
    
    t2=clock();
    diff = ((float)t2-(float)t1);
    cout<<diff<<endl;
    t1=clock();
    
    
    if(argv[1]=="optimal" || testing){
        pairOfCoors q = optimal(myGrid);
        cout << "closest pair distance: "<< myGrid.distanceBetween(q) <<endl;
        cout << "closest pair:\n"<< q <<endl;
    }
    
    t2=clock();
    diff = ((float)t2-(float)t1);
    cout<<diff<<endl;
    
    return 0;
}
