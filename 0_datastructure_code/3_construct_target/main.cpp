
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class myclass
{
public:
    myclass(){ma=10;}
    myclass(int a):ma(a){}
    myclass(myclass& temp)
    {
        cout<<"copy constructor"<<endl;
        this->ma = temp.ma + 10;
    }
    myclass& operator = (myclass &temp)
    {
        cout<<"operator = "<<endl;
        this->ma = temp.ma + this->ma;
        return *this;
    }
    ~myclass(){}
    int ma;
};

int main()
{
    //【1】默认构造函数
    //myclass one = myclass();
    //cout<<"one: "<<one.ma<<endl;

    //【2】带参数构造函数
    myclass two(1);
    cout<<"two: "<<two.ma<<endl;

    //【3】拷贝构造函数
    myclass two_copy(two); //等价于 myclass two_copy = two
    cout<<"two_copy: "<<two_copy.ma<<endl;
    // 拷贝构造函数
    myclass two_copy_1 = two;
    cout<<"two_copy_1: "<<two_copy_1.ma<<endl;

    // 默认构造函数
    myclass two_copy_2;
    cout<<"two_copy_2: "<<two_copy_2.ma<<endl;

    //【4】赋值构造函数
    two_copy_2 = two_copy;
    cout<<"two_copy_2: "<<two_copy_2.ma<<endl;

    myclass *three(new myclass(3)); //new myclass(3)是生成一个临时对象
    cout<<"three: "<<three->ma<<endl;
    // 这两种方法等价
    myclass *four = new myclass(4);
    cout<<"four: "<<four->ma<<endl;

    // 默认构造函数
    myclass *five = new myclass();
    cout<<"five: "<<five->ma<<endl;
    // 赋值构造函数
    *five = *four;
    cout<<"five: "<<five->ma<<endl;
    //【5】普通的指针修改
    five = four;
    cout<<"five: "<<five->ma<<endl;

    // 带参数构造函数
    myclass *six(new myclass(6));
    cout<<"six: "<<six->ma<<endl;
    // 拷贝构造函数
    myclass *seven(new myclass(*six)); // new myclass(*six)是生成一个临时对象
    cout<<"seven: "<<seven->ma<<endl;

    return 0;
}









