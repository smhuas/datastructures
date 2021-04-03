#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//#include <algorithm>
#include <tuple>
using namespace std;


auto get_inputs(){
    string s;
    cin.getline(const_cast<char *>(s.c_str()),100);
    stringstream ss(s.c_str());
    return ss;
}

int main()
{    
    int n,q;            
    get_inputs() >> n>> q; // get inputs    
    vector<vector<int>> lv;        
    for(int i=0; i < n; i++ ) {
        auto ss = get_inputs();
        vector<int> v;
        while( !ss.eof()){             
            int j; 
            ss >> j; 
            v.push_back(j);            
        }
        lv.push_back(v);
    }
    cout<<"*******"<<endl;
    vector<tuple<int,int>> vt;
    int x,y;
    for(int i=0; i < q;i++)
    {        
        get_inputs()>>x>>y;
        vt.push_back(pair<int,int>(x,y));        
    }
            
    for(auto i:vt)
    {
        cout<< lv[get<0>(i)][get<1>(i)+1]<<endl;
    }


}