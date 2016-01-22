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
        pair<coor, coor> findClosestInRange(double highX = 0, double lowX = 0, double highY = 0, double lowY = 0, bool splitByMidpoint = false, size_t midpointValue = INFINITY);
        coor at(size_t i);
        grid rangedSubset(double highX = 0, double lowX = 0, double highY = 0, double lowY = 0);
        grid indexRangedSubset(int low, size_t high);
        void printGrid();
        void randGrid(int n, int max, int min);
};

#endif /* defined(__closestPair__grid__) */
