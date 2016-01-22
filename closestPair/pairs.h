//
//  pairs.h
//  closestPair
//
//  Created by Nick Ray on 1/18/16.
//  Copyright (c) 2016 test. All rights reserved.
//

#ifndef __closestPair__pairs__
#define __closestPair__pairs__

#include <stdio.h>

class coor{
    private:
        double l;
        double r;
    
    public:
    
    coor(double a, double b);
    
    coor();
    
    void setX(double a);
    void setY(double b);
    double getX() const;
    double getY() const;
    
    bool static byX(coor a, coor b){
        return (a.getX()<b.getX());
    }
    
    bool static byY(coor a, coor b){
        return (a.getY()<b.getY());
    }
    bool withinRange(double highX = 0, double lowX = 0, double highY = 0, double lowY = 0);
    bool operator==(const coor &rhs) const;
};



#endif /* defined(__closestPair__pairs__) */
