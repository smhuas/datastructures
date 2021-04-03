#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct myfunctor {
    vector<int> v1,v2;

    myfunctor(vector<int> vec1,vector<int>vec2):v1(vec1)
    {
        for(auto i:v1){
            cout<<i<<'\t';
        } cout<<endl;

    }

    void operator()(int val)
    {
        bool ret = false;
        for(auto i:v1)
        {
            if(val == i)
            {
                ret = true;
            }
        }
        //return ret;
        cout<<ret<<endl;
    }
};

int main()
{
    vector<int> v1={1,2,3};
    vector<int> v2={4,5,6};

    //myfunctor fntr(v1,v2);
    std::for_each(v1.begin(),v1.end(),myfunctor(v1,v2));
}