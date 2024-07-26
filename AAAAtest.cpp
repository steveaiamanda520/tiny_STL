// #include"list.h"

// #include<iostream>
// #include<string>
// using namespace std;
// 测试函数
// void test_list_node() {
//     // 创建一个 int 类型的 list_node 节点
//     mystl::list_node<int> node1(42);
//     std::cout << "node1 value: " << node1.value << std::endl;

//     // 创建一个 double 类型的 list_node 节点
//     mystl::list_node<double> node2(3.14);
//     std::cout << "node2 value: " << node2.value << std::endl;

//     // 测试完全转发构造函数
//     std::string str = "Hello";
//     mystl::list_node<std::string> node3(std::move(str));
//     std::cout << "node3 value: " << node3.value << std::endl;
// }
// int main(){
//     test_list_node();

//     return 0;
// }

#include <iostream>
#include "iterator.h"
#include<vector>

// 这里省略了 has_iterator_cat 的实现


int main() {
    // 测试实例化
    bool result = mystl::has_iterator_cat_of<std::vector<int>::iterator, std::random_access_iterator_tag>::value;
    std::cout << "Result: " << result << std::endl; // 应该输出 1 (true)

    return 0;
}
