#include <iostream>
#include <algorithm>
using namespace std;


enum order {
    ASCENDING,
    DESCENDING
};


template <typename T>
struct list{
    T data;
    struct list *next;
};

template <typename T>
class mylist {
    list<T> *lst = nullptr;
public:
    mylist() = default;
    ~mylist(){erase();}
    mylist(initializer_list<T> l);
    void replace_val_by_pos(T val,int pos);
    void replace_all_by_val(T val);
    void add(T val); 
    void add_front(T val); 
    void add_back(T val);
    template<typename ...Targ> void push_back(Targ... val);
    
    void del_front(); 
    void del_back();
    void del_by_pos(uint16_t pos);
    void del_by_val(T val);
    template<typename ...Targ> void del_by_val(Targ... val);
    void erase();
    void remove_duplicates();
    void sort(order val);    
    void print();
    int count();
};

template<typename T>
mylist<T>::mylist(initializer_list<T> l)
{
    for(auto i:l)
    {
        add(i);
    }    
}

template<typename T>
void mylist<T>::replace_all_by_val(T val)
{
    if(lst != nullptr){
        list<T> *p = lst;
        for(;p != nullptr; p->data = val,p = p->next);
    }else{    
        cout<< "List is empty !!!"<<endl;
    }
    
}


template<typename T>
void mylist<T>::replace_val_by_pos(T val, int pos)
{
    int cnt = 0;    
    if( (lst != nullptr) && (pos <= count()) && (pos != 0))
    {
        list<T> *p = lst;
        for (;p != nullptr;p = p->next){
            ++cnt;
            if(pos == cnt){
                p->data = val;
            }
        }
        
    }else{
        if(pos > count())
        {
            cout<< "Please give the position within range!!!" <<endl;
        } else if(pos == 0){
            cout << "Position cannot be zero "<<endl;
        } else{        
            cout<< "List is empty !!!"<<endl;
        }
    }
}


template<typename T>
void mylist<T>::add(T val)
{
    list<T> *temp = new list<T>;  temp->data = val;  temp->next = nullptr;
    list<T> *p = lst;    
    if(lst == nullptr){
        lst = temp;
    } else{ 
        for(;p->next != nullptr;  p = p->next );   
        p->next = temp;
    }    
}

template<typename T>
void mylist<T>::add_front(T val)
{
    list<T> *temp = new list<T>;  temp->data = val;  
    if(lst == nullptr){
        temp->next = nullptr;
    } else {
        temp->next = lst;
    }
    lst = temp;
}

template<typename T>
void mylist<T>::add_back(T val)
{
    list<T> *temp = new list<T>;  temp->data = val; temp->next = nullptr;
    list<T> *p = lst;
    if(lst == nullptr)
    {
        lst = temp;
    } else {
        for(;p->next != nullptr;  p = p->next ); 
        p->next = temp;
    }
}

template<typename T>
template<typename ...Targ>
void mylist<T>::push_back(Targ... val)
{    
    (add_back(val), ...);
}

template<typename T>
void mylist<T>::del_front()
{
    if(lst != nullptr) {
        list<T> *p = lst;
        lst = lst->next;
        delete p;
    } else {
        cout<< "No data to delete "<<endl;
    }
}

template<typename T>
void mylist<T>::del_back()
{
    list<T> *p = lst;
    if(lst == nullptr) {
        cout<< "No data to delete "<<endl;
    } else if (lst->next == nullptr) {
        cout<< "only one element is present "<< endl;
    } else {
        for(;p->next->next != nullptr;  p = p->next );
        delete p->next;
        p->next = nullptr;        
    }
}

template<typename T>
void mylist<T>::erase()
{
    list<T> *p = lst;
    while(p != nullptr)
    {        
        delete p;
        p = lst->next;
        lst = p;
    }
}

template<typename T>
void mylist<T>::del_by_pos(uint16_t pos)
{
    int ret = 0 ;
    int cnt= count();
    if( (lst != nullptr) ||  (pos != 0) || (pos <= cnt) )
    {
        if(pos != 1) {
            list<T> *p = lst;
            while (p != nullptr) 
            {                         
                if(++ret == pos-1) {
                    delete p->next;
                    if(p->next->next != nullptr) {
                        p->next = p->next->next;
                    } else {                
                        p->next = nullptr;
                    }                
                    break;
                }
                p = p->next;
            }
            if(pos-1 != ret)
            {
                cout<<"Invalid position given!! please check the position "<< endl;
            }
        }
        else {
            del_front();
        }             
    }
    else
    {
        if(pos <= cnt )
        {
            cout<< "please give position within the range!! "<< endl;
        } else if(pos == 0) {
            cout<< "Please give position more than 0 "<<endl;
        }
    }
    
}


template<typename T>
template<typename ...Targ>
void mylist<T>::del_by_val(Targ... val)
{
    (del_by_val(val), ...);
}

template<typename T>
void mylist<T>::del_by_val(T val)
{    
    if(lst != nullptr){
        add_front(00); // add dummy node
        list<T> *p = lst;
        while(p->next != nullptr){
            if(p->next->data == val) {            
                delete p->next;
                if(p->next->next != nullptr) {
                    p->next = p->next->next;
                } else {                
                    p->next = nullptr;
                }                
            }
            else {
                p = p->next;
            }
        }
        del_front();    // remove dummy node

    } else {    
        cout<<"list is empty "<<endl;
    }
    
}
template<typename T>
void mylist<T>::sort(order val)
{
    int Fcnt,Scnt;
    T tmp = 0;
    if(lst != nullptr){
        list<T> *p = lst;
        Fcnt = 0;
        while(p != nullptr){
            list<T> *t = p->next;
            while(t != nullptr){
                ++Scnt;
                if((val == order::ASCENDING)? (p->data > t->data) : (p->data < t->data)){                    
                      tmp = t->data;
                      t->data = p->data;
                      p->data = tmp;                                     
                }
                t = t->next;
            }
            p = p->next;
        }
    } else {
        cout<<"List is empty!! "<<endl;
    }
} 

template<typename T>
void mylist<T>::remove_duplicates()
{
    int Fcnt,Scnt;
    if(lst != nullptr){
        list<T> *p = lst;
        Fcnt = 0;
        while(p != nullptr){        
            ++Fcnt; Scnt = 0;
            list<T> *t = p->next;
            while(t != nullptr){
                ++Scnt;
                if(p->data == t->data){                    
                    del_by_pos(Scnt+Fcnt);
                    --Scnt;                    
                }
                t = t->next;
            }
            p = p->next;
        }
    }else{
        cout<<"List is empty!! "<<endl;
    }
}

template<typename T>
int mylist<T>::count()
{
    int ret = 0;
    if(lst != nullptr)
    {
        list<T> *p = lst;
        while (p != nullptr) {++ret; p = p->next;}       
    }    
    return ret;
}

template<typename T>
void mylist<T>::print()
{
    list<T> *p = lst; 
    if(lst != nullptr){
        while(p != nullptr)
        {
            cout<<p->data;
            p = p->next;
            if(p != nullptr){
                cout<<"->";
            }
        }
        cout<<endl;
        
    }else{
        cout<<"list is empty "<<endl;
    }  
}


int main()
{
    mylist<int> l = {1,2,3,4,5,8,9,7,4,2,24,5,6,7,8,5,4,3,33,4,4,4,
                     3,4,5,6,7,7,8,89,6,5,4,3,2,2,23,4,4,55,6,45,56,
                     23,45,33,11,44,66,33,11,55,222,3343,222,333,222,
                     67,34,22,112,47,231,78,79,78,80,65,6970,886,98
                     };                      
    l.print();

    
    
     
}