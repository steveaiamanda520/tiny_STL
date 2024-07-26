#include"vector.h"
#include"algobase.h"
#include"uninitialized.h"
#include"iterator.h"

#include<iostream>

using namespace std;
// using namespace mystl;
int main(){

    mystl::vector<int> v{2,2,34,5,6,7,8,9,0,1};
    mystl::vector<int> w{5,2,34,5,6,7,8,9,0,1};
    typename mystl::vector<int>::iterator it;
    // 使用 typename 获得迭代器类型
    using IteratorType = typename mystl::iterator_traits<mystl::vector<int>::iterator>::iterator_category;

    // 传递迭代器类型
    mystl::unchecked_move_cat(v.begin(), v.end(), w.begin(), IteratorType());

    // mystl::unchecked_copy(v.begin(),v.end(),w.begin());
    // mystl::iter_swap(v.begin(),w.begin());
    // mystl::unchecked_uninit_copy(v.begin(),v.end(),w.begin(),std::integral_constant<bool, true>());
    // mystl::unchecked_move_cat(v.begin(),v.end(),w.begin(),iterator_traits<mystl::vector<int>::iterator>::iterator_category());
    //成立
    //mystl::unchecked_move_cat(v.begin(),v.end(),w.begin(),mystl::iterator_category(w.begin()));
    // mystl::unchecked_move_cat(v.begin(),v.end(),w.begin(),mystl::random_access_iterator_tag());
    // mystl::unchecked_move_cat(v.begin(),v.end(),w.begin(),mystl::iterator_category(it));
    // mystl::unchecked_move_cat(v.begin(),v.end(),w.begin(),ittt::iterator_category());
    for(auto i : w){
        cout<<i<<" ";
    }


    return 0;
}


// #include <iostream>
// #include "algobase.h"

// using namespace std;
// using namespace mystl;

// int main() {
//     // int a[] = {1,2,34,5,6};
//     // int b [] ={2,3,4,5,6};
//     int a=7;
//     int b=8;
//     mystl::iter_swap(&a, &b);
//     // for(auto i:a)
//     // {
//     //     cout<<i<<" ";
//     // }
//     cout<<a<<endl;
//     // cout << "After swapping: a = " << a << ", b = " << b << endl;

//     return 0;
// }