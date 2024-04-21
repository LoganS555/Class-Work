#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class stack
{
        public:
                stack(); // default size 20
                stack(int); // custom size
                void push( int );
                int pop( );
                int top( );
                bool isEmpty();
                void print();
        private:
                int toploc;
                int *dat;
                int cap;
};
