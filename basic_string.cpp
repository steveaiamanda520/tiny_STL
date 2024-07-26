#include"basic_string.h"

#include<iostream>
using namespace std;



int main(){

    char a[]={'2','3','4'};
    cout<<a<<endl;

    
    cout<<char_traits<char>::length(a)<<endl;

    basic_string<char> m(10,'a');
    cout<<m<<endl;

    m.append(3,'b');
    cout<<m<<endl;

    m.insert(m.end(),m.begin(),m.end());
    m.erase(m.begin()+10);
    cout<<m<<endl;
    
}