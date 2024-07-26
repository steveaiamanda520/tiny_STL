#ifndef MYTINYSTL_CONSTRUCT_H_
#define MYTINYSTL_CONSTRUCT_H_

// 这个头文件包含两个函数 construct，destroy
// construct : 负责对象的构造
// destroy   : 负责对象的析构

#include <new>

#include "type_traits.h"
#include "iterator.h"
#include "util.h"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4100)  // unused parameter
#endif // _MSC_VER



/*这一组模板函数是用于在给定的内存位置上构造对象的辅助函数。它们允许你在特定的内存位置上构造对象，并且支持多种构造方式。让我们逐个解释这些函数的作用：

1. **`template <class Ty> void construct(Ty* ptr)`：**
   - 这个函数用于在指定的内存位置 `ptr` 上调用类型 `Ty` 的默认构造函数，实现对象的构造过程。
   - 通过调用 `::new ((void*)ptr) Ty();` 在指定的内存位置上创建了一个类型为 `Ty` 的对象。

2. **`template <class Ty1, class Ty2> void construct(Ty1* ptr, const Ty2& value)`：**
   - 这个函数允许通过一个值 `value` 调用类型 `Ty1` 的构造函数，在指定的内存位置 `ptr` 上创建对象。
   - 通过调用 `::new ((void*)ptr) Ty1(value);` 在指定的内存位置上创建了一个类型为 `Ty1` 的对象，并用 `value` 进行初始化。

3. **`template <class Ty, class... Args> void construct(Ty* ptr, Args&&... args)`：**
   - 这个函数是一个可变参数模板函数，允许通过任意数量的参数调用类型 `Ty` 的构造函数，在指定的内存位置 `ptr` 上创建对象。
   - 通过调用 `::new ((void*)ptr) Ty(mystl::forward<Args>(args)...);` 在指定的内存位置上创建了一个类型为 `Ty` 的对象，使用 `std::forward` 转发参数列表。

这些函数提供了一种在指定的内存位置上构造对象的通用方法，支持不同的构造方式。这种手动构造对象的方法通常在实现底层的内存管理或者特殊的数据结构时使用。这样的模板函数使得在不同的情况下可以方便地调用构造函数，以适应不同的初始化需求。*/
namespace mystl
{

// construct 构造对象

template <class Ty>
void construct(Ty* ptr)
{
  ::new ((void*)ptr) Ty();
}

template <class Ty1, class Ty2>
void construct(Ty1* ptr, const Ty2& value)
{
  ::new ((void*)ptr) Ty1(value);
}

template <class Ty, class... Args>
void construct(Ty* ptr, Args&&... args)
{
  ::new ((void*)ptr) Ty(mystl::forward<Args>(args)...);
}

// destroy 将对象析构

template <class Ty>
void destroy_one(Ty*, std::true_type) {}

template <class Ty>
void destroy_one(Ty* pointer, std::false_type)
{
  if (pointer != nullptr)
  {
    pointer->~Ty();
  }
}

template <class ForwardIter>
void destroy_cat(ForwardIter , ForwardIter , std::true_type) {}

template <class ForwardIter>
void destroy_cat(ForwardIter first, ForwardIter last, std::false_type)
{
  for (; first != last; ++first)
    destroy(&*first);
}

template <class Ty>
void destroy(Ty* pointer)
{               //如果是int等类型的话，就不会发生，具有析构函数，动态分配内存的都有自己的析构函数
  destroy_one(pointer, std::is_trivially_destructible<Ty>{});
}

template <class ForwardIter>
void destroy(ForwardIter first, ForwardIter last)
{
  destroy_cat(first, last, std::is_trivially_destructible<
              typename iterator_traits<ForwardIter>::value_type>{});
}

} // namespace mystl

#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER

#endif // !MYTINYSTL_CONSTRUCT_H_

