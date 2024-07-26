#include <iostream>
#include"construct.h"
using namespace mystl;
struct MyClass {
    int data;
    int data_2;
    MyClass() : data(0) {}
    MyClass(int val) : data(val) {}
    MyClass(int val1,int val2):data(val1),data_2(val2){}
};

int main() {
    MyClass* ptr1 = new MyClass();
    construct(ptr1);
    std::cout << "Default constructed: " << ptr1->data << std::endl;
    delete ptr1;

    MyClass* ptr2 = new MyClass();
    construct(ptr2, 42);
    std::cout << "Value initialized: " << ptr2->data << std::endl;
    delete ptr2;

    MyClass* ptr3 = new MyClass();
    construct(ptr3, 10,20);
    std::cout << "Constructed with args: " << ptr3->data << std::endl;
    // delete ptr3;
    destroy(ptr3);
    return 0;
}

// #include <iostream>
// #include"construct.h"
// using namespace mystl;
// Forward declaration of mystl::forward
// template <typename T>
// T&& mystl_forward(typename std::remove_reference<T>::type& t) noexcept {
//     return static_cast<T&&>(t);
// }

// template <class Ty, class... Args>
// void construct(Ty* ptr, Args&&... args)
// {
//   ::new ((void*)ptr) Ty(mystl_forward<Args>(args)...);
// }

// class MyClass {
// public:
//     MyClass(int a, double b) : a_(a), b_(b) {}
//     void print() {
//         std::cout << "a: " << a_ << ", b: " << b_ << std::endl;
//     }
// private:
//     int a_;
//     double b_;
// };

// int main() {
//     MyClass* ptr = new MyClass(0, 0.0); // Allocate memory for MyClass object
//     construct(ptr, 42, 3.14); // Construct MyClass object using construct function
//     ptr->print(); // Print the values of the constructed object
//     delete ptr; // Free the allocated memory
//     return 0;
// }

// #include <iostream>
// // #include <utility> // Include utility for std::forward
// #include<new>
// template <class Ty, class... Args>
// void construct(Ty* ptr, Args&&... args)
// {
//   ::new ((void*)ptr) Ty(std::forward<Args>(args)...);
// }

// class MyClass {
// public:
//     MyClass() : a_(0), b_(0.0) {}
//     MyClass(int a, double b) : a_(a), b_(b) {}
//     void print() {
//         std::cout << "a: " << a_ << ", b: " << b_ << std::endl;
//     }
// private:
//     int a_;
//     double b_;
// };

// int main() {
//     MyClass* ptr = new MyClass(); // Allocate memory for MyClass object
//     construct(ptr, 42, 3.14); // Construct MyClass object using construct function
//     ptr->print(); // Print the values of the constructed object
//     delete ptr; // Free the allocated memory
//     return 0;
// }


/*
    1、最简单的用法
*/
// #include <iostream>
 
// template<typename... Args>
// void f(Args... args) {
// 	std::cout << sizeof...(args) << std::endl;
// }
 
// int main()
// {
// 	f();        // 输出0
// 	f(1);       // 输出1
// 	f(1, "",3,4,5,6,7,8);   // 输出2
//     return 0;

// }
/*
    2、递归模板函数
*/
// #include <iostream>
// using namespace std;
 
// //递归终止函数
// void f()
// {
// 	cout << "empty" << endl;
// }
 
// //展开函数
// template <class T, class ...Args>
// void f(T head, Args... rest)
// {
// 	cout << "parameter " << head << endl;
// 	f(rest...);
// }
 
 
// int main(void)
// {
// 	f(1, 2, 3, 4);
// 	return 0;
// }

/*
    3、lambda表达式
*/
// #include <iostream>
// using namespace std;
 
// int main()
// {
// 	[](){                            //这里的()没有参数可以省略
// 		cout << "Hello,World\n";
// 	}();
// }

/*
    4\ 改进之后的代码
*/

// // #include <iostream>
 
// // template <class T>
// // void func(T t)
// // {
// // 	std::cout << t << std::endl;
// // }
 
// // template <class ...Args>
// // void test(Args... args)
// // {
// // 	int arr[] = { (func(args), 0)... };
// // }
 
// // int main() {
// // 	test(1, 2, 3, 4);
 
// // 	return 0;
// // }



// #include <iostream>
 
// template<class F, class... Args>
// void test(const F& f, Args&&...args)
// {
// 	std::initializer_list<int>{(f(std::forward<Args>(args)), 0)...};
// }
 
// int main() {
// 	test([](int i) {std::cout << i << std::endl; }, 1, 2, 3);
 
// 	return 0;
// }


// #include <iostream>
 
// template<typename T, typename... Args>
// auto print(T value, Args... args) {
// 	std::cout << value << std::endl;
// 	return std::initializer_list<T>{([&](){
// 		std::cout << args << std::endl;
// 	}(), value)...};
// }
// int main() {
// 	print(1, 2.1, "test");			//使用初始化列表
// 	return 0;
// }


