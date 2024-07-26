

/*    该代码实现   类的公有继承*/
#include <iostream>

// 基类 Base
struct Base {
    int base_value;

    void print_base() {
        std::cout << "Base value: " << base_value << std::endl;
    }
};

// 派生类 Derived，公有继承自 Base
struct Derived : public Base {
    int derived_value;

    void print_derived() {
        std::cout << "Derived value: " << base_value << std::endl;
    }
};

int main() {
    // 创建 Derived 类对象
    Derived derived_obj;

    // 设置基类成员变量
    derived_obj.base_value = 100;

    // 设置派生类成员变量
    derived_obj.derived_value = 200;

    // 调用基类成员函数
    derived_obj.print_base();

    // 调用派生类成员函数
    derived_obj.print_derived();

    return 0;
}
