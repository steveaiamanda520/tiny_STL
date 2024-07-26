//全特化和偏特化不一样





//partial specialization

template<class Iterator>
struct iterator_traits{
    typedef typename Iterator::iterator_category iterator_category;
};

//偏特化版本

template<class T>
struct iterator_traits<T*>{
    typedef random_access_iterator_tag iterator_category;
};

template<class T>
struct iterator_traits<const T*>{
    typedef random_access_iterator_tag iterator_category;
};


template<class type>
struct __type_traits{};


template<> struct __type_traits<int> {};
template<> struct __type_traits<char> {};






