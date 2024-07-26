#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_



// 这个头文件用于提取类型信息

// use standard header for type_traits
#include <type_traits>
/*类型属性检查：可以检查一个类型是否是特定的属性，比如是否是指针类型、是否是引用类型、是否是数组类型等。
类型关系检查：可以检查两个类型之间的关系，比如是否相同类型、是否是相同类型的引用或指针、是否是基本数据类型等。
类型属性转换：可以将一个类型转换成另一个具有相似属性的类型，比如将一个类型转换成其 const 版本、volatile 版本、引用版本等。
类型比较：可以比较两个类型的属性，比如检查两个类型是否相同、是否可以进行隐式转换等。
类型特性查询：可以查询一个类型的属性信息，比如类型的大小、对齐方式、是否是标量类型等。*/
namespace mystl
{

// helper struct
//关键字 constexpr 表示 value 是一个编译时常量，它的值在编译期间就已经确定。
template <class T, T v>
struct m_integral_constant
{
  static constexpr T value = v;
};

template <bool b>
using m_bool_constant = m_integral_constant<bool, b>;

typedef m_bool_constant<true>  m_true_type;
typedef m_bool_constant<false> m_false_type;

/*****************************************************************************************/
// type traits

// is_pair

// --- forward declaration begin
template <class T1, class T2>
struct pair;
// --- forward declaration end

template <class T>
struct is_pair : mystl::m_false_type {};

template <class T1, class T2>
struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};

} // namespace mystl

#endif // !MYTINYSTL_TYPE_TRAITS_H_

