/*
priority queue:- is similar to queue, keeps highest value(ascii values) in the top. 
there is no front, use top.
https://www.softwaretestinghelp.com/priority-queue-in-cpp/
*/
#include <iostream>
#include <queue>
using namespace std;

void printpriorityqueue(priority_queue<int> que)
{
    while(!que.empty())
    {
        cout<<que.top()<<" ";
        que.pop();
    }
    cout<<endl;
}

int main()
{
    priority_queue<int> pq;
    for(int n:{1,2,3,8,4,5,6}){pq.push(n);}
    printpriorityqueue(pq);

}