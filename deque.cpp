/*
deque is double ended queue
use when u need to insert and delete elements from begin or end.
*/
#include <iostream>
#include <deque>
using namespace std;

#define PRINT(X,Y) for(auto i:X){cout<<i<<" ";} cout<<" -->"<<Y<<endl

int main()
{
    deque<int> d= {1,2,3,4}; PRINT(d,"initial list");
    d.push_back(5); PRINT(d,"push_back");
    d.push_front(0); PRINT(d,"push_front");
    d.insert(d.begin()+1,22);   PRINT(d,"insert @begin+1");  
    d.erase(d.begin()+1);   PRINT(d,"erase @begin+1");  
}

