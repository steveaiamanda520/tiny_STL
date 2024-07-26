#include<iostream>
using namespace std;

int main(){
    int n=10;
    const int *p1=&n;
    // *p1=20;
    int *p2=const_cast<int*> (p1);
    *p2=100;
    cout<<*p2<<endl;

    return 0;
}