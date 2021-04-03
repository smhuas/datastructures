/*
map                 --> sorted map          --> cannot accept same key again and again
unordered_map       --> unsorted map        --> cannot accept same key again and again
multimap            --> this can be map/unordered_map   --> accepts same key again and again

map             --> generally is slower compared to unordered_map. when you doesn't bother about speed and consume less memory use this.
unordered_map   --> it is faster to access. it uses hash functions internally to store the elements. 
                    when u have enough memory and need faster access use this.                    
*/
#include <iostream>
#include <map>                  // it contains multimap also
#include <unordered_map>
using namespace std;

#define PRINT(X,Y) for(auto i:X) { cout<<i.first<<" "; } cout<<"         --> " << Y <<endl
unordered_multimap<string,int> temp = {{"vijay",0} , {"bhaskar",1}, {"reddy",2}, {"reddy",3}};

int main()
{
    PRINT(temp,"Input");   
    map<string,int> m;  m.insert(temp.begin(),temp.end());  PRINT(m,"map");

    unordered_map<string,int> um;  um.insert(temp.begin(),temp.end());  PRINT(um,"unordered_map");

    unordered_multimap<string,int> umm;  umm.insert(temp.begin(),temp.end());  PRINT(umm,"unordered_multimap");
        
    multimap<string,int> mm;  mm.insert(temp.begin(),temp.end());  PRINT(mm,"multimap");    
}