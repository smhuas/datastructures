#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class hello {
public:
    template<typename ...Targ>
    T add(Targ... args);//{return (... + args);}
};

template<typename T>
template<typename ...Targ>
T hello<T>::add(Targ... args)
{
    vector<T> vec;
    (vec.push_back(args), ... );
    for(auto i:vec)
    {
        cout<<i<<endl;
    }
    return (... + args);
}

int main()
{
    hello<int> h;
    cout<< h.add(1,2,3) << endl;
  
}