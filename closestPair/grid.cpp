//
//  grid.cpp
//  closestPair
//
//  Created by Nick Ray on 1/18/16.
//  Copyright (c) 2016 test. All rights reserved.
//

#include "grid.h"

size_t grid::n(){
    return allPairs.size();
}
pair<coor, coor> grid::getCoorPair(){
    if(allPairs.size()==2){
        return pair<coor, coor>(allPairs[0], allPairs[1]);
    }
    return pair<coor, coor>(coor(INFINITY, INFINITY), coor(-INFINITY, -INFINITY));
}

void grid::removeDups(){
    unique(allPairs.begin(),allPairs.end());
}

void grid::add(double a, double b){
    a = floorf(a * 10000000) / 10000000;
    b = floorf(b * 10000000) / 10000000;
    allPairs.push_back(coor(a,b));
    if(a<minX)
        minX=a;
    if(a>maxX)
        maxX=a;
    if(b<minY)
        minY=b;
    if(b>maxY)
        maxY=b;
}
void grid::add(coor a){
    double x = floorf(a.getX() * 10000000) / 10000000;
    double y = floorf(a.getY() * 10000000) / 10000000;
    a = coor(x,y);
    allPairs.push_back(a);
    if(a.getX()<minX)
        minX=a.getX();
    if(a.getX()>maxX)
        maxX=a.getX();
    if(a.getY()<minY)
        minY=a.getX();
    if(a.getY()>maxY)
        maxY=a.getY();
}
double grid::getMinX(){
    return minX;
}
double grid::getMaxX(){
    return maxX;
}
double grid::getMinY(){
    return minY;
}
double grid::getMaxY(){
    return maxX;
}
double grid::distanceBetween(coor a, coor b){
    return sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2));
}
double grid::distanceBetween(pair<coor, coor> a){
    return distanceBetween(a.first, a.second);
}
void grid::sortByX(){
    sort(allPairs.begin(), allPairs.end(), coor::byX);
}
void grid::sortByY(){
    sort(allPairs.begin(), allPairs.end(), coor::byY);
}
pair<coor, coor> grid::findClosestInIndexRange(int min, int max){
    double minDistance = INFINITY;
    pair<coor, coor> closest = pair<coor, coor>(coor(INFINITY, INFINITY), coor(-INFINITY, -INFINITY));
    
    for (int i = min; i<max; i++){
        for(int j = i+1 ;j<max; j++){
            double d = distanceBetween(allPairs[i], allPairs[j]);
            if(d<minDistance){
                minDistance = d;
                closest = pair<coor, coor>(allPairs[i], allPairs[j]);
            }
        }
    }
    return closest;
}



coor grid::at(size_t i){
    return allPairs[i];
}

grid grid::rangedSubset(double highX, double lowX, int min, int max){
    grid subset;
    for (int i = min; i<max; i++){
        if(allPairs[i].withinRange(highX, lowX))
            subset.add(allPairs[i]);
    }
    return subset;
}
grid grid::indexRangedSubset(int low, size_t high){
    grid subset;
    for (int i = max(low,0); i<min(high,subset.n()); i++){
        subset.add(allPairs[i]);
    }
    return subset;
}

void grid::printGrid(){
    cout <<"Pairs: "<<endl;
    for(int i=0;i<allPairs.size();i++){
        cout<<allPairs[i].getX()<<", "<<allPairs[i].getY()<<endl;
    }
}
void grid::randGrid(int n, int max, int min){
    srand (time(NULL));
    for(int i=0;i<n;i++){
        double x = min + (max - min)*(double)rand() / RAND_MAX;
        double y = min + (max - min)*(double)rand() / RAND_MAX;
        this->add(coor(x,y));
    }
}
