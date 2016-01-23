//
//  grid.h
//  closestPair
//
//  Created by Nick Ray on 1/18/16.
//  Copyright (c) 2016 test. All rights reserved.
//

#ifndef __closestPair__grid__
#define __closestPair__grid__

#include <iostream>
#include <vector>
#include "pairs.h"
#include <cmath>

using namespace std;

typedef pair<coor, coor> pairOfCoors;

class grid{
    private:
        vector<coor> allPairs;
        double maxX = -INFINITY, minX=INFINITY, maxY = -INFINITY, minY = INFINITY;
    
    public:
        size_t n();
        pair<coor, coor> getCoorPair();
        void removeDups();
        void add(double a, double b);
        void add(coor a);
        double getMinX();
        double getMaxX();
        double getMinY();
        double getMaxY();
        double distanceBetween(coor a, coor b);
        double distanceBetween(pair<coor, coor> a);
        void sortByX();
        void sortByY();
        pair<coor, coor> findClosestInIndexRange(int min, int max);
        coor at(size_t i);
        grid rangedSubset(double highX = 0, double lowX = 0, int min = 0, int max = 0);
        grid indexRangedSubset(int low, size_t high);
        void printGrid();
        void randGrid(int n, int max, int min);
        pairOfCoors brute(){
            return findClosestInIndexRange(0, n());
        }
        pairOfCoors optimal(){
            sortByX();
            sortByY();
            return basic(false, 0, n());
            
        }
        pairOfCoors basic(bool sort, int min, int max){
            if(max-min<=3)
                return findClosestInIndexRange(min, max);
            if(sort)
                std::sort(allPairs.begin()+min, allPairs.begin()+max, coor::byX);
            int mid = round(max/2);
            double midpoint = allPairs[mid].getX();
            
            pairOfCoors left, right;
            left = basic(sort, min, mid);
            right = basic(sort, min+mid, max-mid);
            
            double leftD = distanceBetween(left);
            double rightD = distanceBetween(right);
            double bestD;
            if(leftD<rightD)
                bestD = leftD;
            else
                bestD = rightD;
            grid centerGrid = rangedSubset(midpoint + bestD, midpoint - bestD, min, max);
            if(sort)
                centerGrid.sortByY();
            pairOfCoors center = centerGrid.findClosestInIndexRange(0, centerGrid.n()); //midpoint?
            
            double centerD = distanceBetween(center);
            
            if(centerD<bestD)
                bestD = centerD;
            if(bestD==centerD)
                return center;
            if(bestD==leftD)
                return left;
            return right;
            
        }
};

#endif /* defined(__closestPair__grid__) */
