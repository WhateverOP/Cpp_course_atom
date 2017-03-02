#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "Stack.h"

#define ASSERT_OK() \
if (!ok()) \
{ \
dump(); \
assert (!"Object is OK"); \
}

using namespace std;


Stack::Stack()
{
    printf("new stack \n");
}

Stack::~Stack()
{
    delete [] data_;
    size_ = POISON_INT;
}
//--------------------------------------------------
//!Add some value in stack.
//--------------------------------------------------
bool Stack::push(double value)
{
    ASSERT_OK()
    if (size_ >= capacity_)
    {
        return(false);
    }
    else
    {
       this->data_[this->size_++] = value;
       return(true);
    }
    ASSERT_OK()
}
//--------------------------------------------------
//!Delete top element from stack.
//--------------------------------------------------
double Stack::pop()
{
    ASSERT_OK()
    if (this->size_ == 0)
    {
        return(printf("empty stack \n"));
    }
    else
    {
        return(this->data_[--this->size_]);
    }
    ASSERT_OK()
}
//--------------------------------------------------
//!Get maximum possible size of stack.
//--------------------------------------------------
size_t Stack::capacity()
{
    return(capacity_);
}
size_t Stack::size()
{
    return(size_);
}
//--------------------------------------------------
//!Get top value of stack.
//--------------------------------------------------
double Stack::top()
{
    ASSERT_OK()
    if (this->size_ == 0)
    {
        return(printf("empty stack \n"));
    }
    else
    {
       return(this->data_[--this->size_]);
    }
    ASSERT_OK()
}
//--------------------------------------------------
//!Silent verifier.
//--------------------------------------------------
bool Stack::ok()
{
    return size_ <= capacity_;
}
//--------------------------------------------------
//!Dump data.
//--------------------------------------------------
bool Stack::dump()
{
    cout << "(";
    if (ok())
        cout << "OK)" << endl;
    else
        cout << "ERROR!)" << endl;
    cout << "\t{" << endl;
    cout << "\tsize_\t\t= " << size() << endl;
    cout << "\tcapacity_\t= " << capacity() << endl;
    cout << "\tdata_ [" << capacity() << "]:"<< endl;
    cout << "\t\t{" << endl;

    for (int i=0; i<capacity(); i++)
    {
        if (i<size())
            cout << "\t*\t" << "[" << i << "] = " << data_[i];
        else
            cout << "\t\t" << "[" << i << "] = " << data_[i];
        if (data_[i] == POISON_INT)
            cout << " (POISON_INT)" << endl;
        else
            cout << endl;
    }
    cout << "\t\t}" << endl;
cout << "\t}" << endl;
}

