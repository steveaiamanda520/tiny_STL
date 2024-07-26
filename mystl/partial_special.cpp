#include <iostream>

// 定义一个类模板
template <typename T, typename U>
class MyClass {
public:
    void print() {
        std::cout << "Primary template\n";
    }
};

// 对 MyClass 进行偏特化，将 U 指定为 double
template <typename T>
class MyClass<T, double> {
public:
    void print() {
        std::cout << "Partial specialization for any T and double\n";
    }
};

int main() {
    // 创建 MyClass 对象并调用 print 方法
    MyClass<int, int> obj1;
    obj1.print();  // 输出：Primary template

    MyClass<int, double> obj2;
    obj2.print();  // 输出：Partial specialization for any T and double

    return 0;
}
