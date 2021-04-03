/*
lists are sequence containers. its double linked list.
list has slower traversal, but insertion and deletion speed is good.

vector vs list
--> vector is like array with contigous memory which can resize its memory, whereas list is like linked list cannot have contigous mem.
--> if u need fast iteration, then vector,  if u need fast insertion and deletion then list
--> vector requires only space for itself, but list needs space for next node addr and for storing the data(linked list).
--> vector random access of mem is possible, list not possible(need to traverse). 
*/

#include <iostream>
#include <list>
using namespace std;

#define PRINT(X,Y) for(auto i:X){cout<<i<<" ";} cout<<" -->"<<Y<<endl

int main()
{
    list<int> l = {1,2,3,4};   PRINT(l,"initial list");    
    l.push_back(5); PRINT(l,"push_back");
    l.push_front(0); PRINT(l,"push_front");    
    l.reverse(); PRINT(l,"reverse");
    l.erase(l.begin()); PRINT(l,"erase at beginning");

}