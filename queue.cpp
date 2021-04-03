/*
queue :- insertion always from back, deletion from the begining (FIFO)
    printing elements of queue is different
*/
#include <iostream>
#include <queue>
using namespace std;

#define PRINT(X,Y) for(auto i:X){cout<<i<<" ";} cout<<" -->"<<Y<<endl

void printqueue(queue<int> que)
{
    while(!que.empty())
    {
        cout<<que.front()<<" ";
        que.pop();
    }
    cout<<endl;
}

int main()
{
    queue<int> q; 
    q.push(1); // printing the elements of queue is little different, cannot use usual printing mechanism.
    q.push(2); q.push(3); q.push(4);
    printqueue(q);    
}