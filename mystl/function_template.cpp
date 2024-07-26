#include<iostream>


// using namespace std;


template<class T>
inline 
const T & min(const T& a,const T& b){
    return b<a?b:a;
}
class stone{
    public:
        stone(int w,int h,int we):_w(w),_h(h),_weight(we){}

    bool operator<(const stone& rhs) const{
        return _weight<rhs._weight;
    }
    int _w,_h,_weight;
};


int main(){

    stone r1(2,3,4),r2(3,4,5);
    stone r3=min(r1,r2);

    std::cout<<r3._w<<r3._h<<std::endl;



    return 0;
}