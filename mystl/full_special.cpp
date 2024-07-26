#include <iostream>

// 定义一个类模板
template <typename T, typename U>
class MyClass {
public:
    void print() {
        std::cout << "Primary template\n";
    }
};

// 对 MyClass 进行全特化，将 T 和 U 分别指定为 int 和 double
template <>
class MyClass<int, double> {
public:
    void print() {
        std::cout << "Full specialization for int and double\n";
    }
};

int main() {
    // 创建 MyClass 对象并调用 print 方法
    MyClass<int, int> obj1;
    obj1.print();  // 输出：Primary template

    MyClass<int, double> obj2;
    obj2.print();  // 输出：Full specialization for int and double

    return 0;
}
