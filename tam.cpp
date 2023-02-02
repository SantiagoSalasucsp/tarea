#include <iostream>
template <typename T>
class IntegerArray {
    private:
        T *data;
        T size;

    public:
        IntegerArray(T size){
            data = new T[size];
            this->size = size;
        }
        IntegerArray(const IntegerArray &o){
            data = new int[o.size];
            this->size = o.size;
            for(int i = 0; i < size; ++i)
            data[i] = o.data[i];
        }
        ~IntegerArray(){
            delete[] data;
        }
        void setData(T index, T val){
            if (index >= size){
            throw std::out_of_range ("el indice se pasa del limite");}
            data[index] = val;
        }
        int getData(T index) const{
            if (index<0 || index>=size)
            throw  std::out_of_range ( "El indice no es el correcto" );
            return data[index];
        }
        int getSize() const{
            return size;
        }
        void print() const{
            std::cout << "[ ";
            for(int i = 0; i < size; i++)
                std::cout << data[i] << " ";
            std::cout << "]" << std::endl;
        }

    void insert(T elem, T pos){
        int *tmp = new int[size + 1];
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
        }
void pushback(T elm){
    int* tmp = new int[size +1];
    for (int i=0;i<size;i++)
        {
          tmp[i]=data[i];  
        }
    tmp[size]=elm;
    size+=1;
    delete [] data;
    data=tmp;
        }
        

    void remove(T pos){
    int*tmp=new int[size-1];
    for(int i=0;i<size-1;i++)
    {
        if (i=pos)
        {i++;
        i--;}
        else 
        tmp[i]=data[i];
    }
    size--;
    delete[] data;
    data=tmp;
}

void IntegerArray::clear(){
    int* tmp=new T[0];
    size=size-size;
    delete data;
    data=tmp;
}





};

int main() {
    IntegerArray<int> a(3);

  

    
    a.setData(0, 2);
    a.setData(2, 2);
    
   
    

    a.print();

    
    return 0;
}
