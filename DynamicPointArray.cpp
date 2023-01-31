#include <iostream>
#include "DynamicPointArray.h"
#include "Point.h"

DynamicPointArray::DynamicPointArray() {
    this->size = 0;
    data = new Point[size];
}

DynamicPointArray::DynamicPointArray(const Point arr[], const int size) {
    this->size = size;
    data = new Point[size];
    for(int i = 0; i < size; i++)
        data[i] = arr[i];
}

DynamicPointArray::DynamicPointArray(const DynamicPointArray &o) {
    this->size = o.size;
    data = new Point[o.size];
    for(int i = 0; i < size; i++)
        data[i] = o.data[i];
}

DynamicPointArray::~DynamicPointArray() {
    delete[] data;
}


int DynamicPointArray::getSize() const {
    return size;
}

void DynamicPointArray::print() const {
    std::cout << "[ ";
    for(int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << "]" << std::endl;
}

void DynamicPointArray::push_back(Point val) {
    Point* ptr;
    ptr= new Point[size+1];
    for( int i=0; i<size;i++)
    {ptr[i]=data[i];}
    delete[] data;
    size+=1;
    ptr[size-1]=val;

    data=ptr;
}



void DynamicPointArray::insert(Point elem, int pos) {
  if (pos>size||pos<0){
    std::cout<<"Error: Invalid position"<<std::endl;}
  else{
        Point *tmp = new Point[size + 1];
        for(int i = 0, j = 0; i < size; i++, j++) {
          if( j == pos) {
              tmp[pos] = elem;
              i--;
          } else {
            tmp[j] = data[i];
          }        
        }
        size += 1;
        delete [] data;
        data = tmp;
      } }

void DynamicPointArray::remove(int pos) {
  if (pos>size||pos<0){
    std::cout<<"Error: Invalid position"<<std::endl;}
  else {
        Point *tmp = new Point[size - 1];
        for(int i = 0, j = 0; i < size; i++, j++) {
          if( j == pos)
          i++;
          tmp[j] = data[i];    
        }
        size -= 1;
        delete [] data;
        data = tmp;
      }}

void DynamicPointArray::clear(){
    Point* tmp=new Point[0];
    size=size-size;
    delete data;
    data=tmp;

    

}
