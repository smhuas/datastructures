/*
set
*/
#include <iostream>
#include <set>
using namespace std;

#define PRINT(X,Y) for(auto i:X){cout<<i<<" ";} cout<<" -->"<<Y<<endl

int main()
{
    set<int,less<int>> s = {5,1,2,3,4};  PRINT(s,"initial list");    
    s.insert(10);   PRINT(s,"insert 10");
    s.erase(1);     PRINT(s,"erase 1");
    s.erase(10);     PRINT(s,"erase 10");
    if(s.find(2) != s.end()) {cout<<"has 2"<<endl;} else {cout<<"doesnot has 2"<<endl;}

    set < int > :: key_compare  comp  =  s.key_comp();
    cout<<comp(5,4)<<endl;

    multiset<int> ms = {1,1,2,3,4,4};   PRINT(ms,"multiset initial list");
}