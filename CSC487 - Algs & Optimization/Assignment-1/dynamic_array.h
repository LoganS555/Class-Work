#include <iostream>
#include <climits>

using namespace std;

struct dynamic_array{
    long *data;
    int length;
    int capacity;

    dynamic_array(){
        this->data = (long *)malloc(sizeof(long));
        this->length = 0;
        this->capacity = 1;
    }

    void push(long new_data){
        if (this->length == this->capacity){
            this->capacity*=2;
            this->data = (long *)realloc(this->data,sizeof(long)*this->capacity);
        }
        this->data[this->length] = new_data;
        this->length++;
    }  

    long& operator[](int index){
        if (index <= this->length && index >= 0){
            return this->data[index];
        }
        return this->data[0];
    }  
};