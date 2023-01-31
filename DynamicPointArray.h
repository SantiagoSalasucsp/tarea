#ifndef __DYNAMICPOINTARRAY_H__
#define __DYNAMICPOINTARRAY_H__
#include "Point.h"
#include <iostream>

class DynamicPointArray {
    private:
        Point *data;
        int size;

    public:
        DynamicPointArray();
        DynamicPointArray(const Point arr[], const int tam);
        DynamicPointArray(const DynamicPointArray &o);
        ~DynamicPointArray();

        void push_back(Point val);
        
        int getSize() const;
        void print() const;


        void insert(Point elem, int pos);
        void remove(int pos);
        void clear();
};

#endif
