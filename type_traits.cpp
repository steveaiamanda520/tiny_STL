#include"type_traits.h"
#include<iostream>
using namespace mystl;

int main(){
    std::cout<<is_pair <pair<int,int>>::value; // m_true_type

    std::cout<<is_pair<int>::value;
    return 0;
}