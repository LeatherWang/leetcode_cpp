
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

int main(int argc, char **argv)
{
    int testDemo = 0;
    if(argc > 1)
        testDemo = atoi(argv[1]);

    switch (testDemo) {
    case 0:
    {
        int word;
        while(cin >> word) //在输入换行之前，都阻塞在这里
            cout<<word<<endl;

        if( cin.fail())
        {
            cout << "Fail flag: " <<  cin.fail() << endl;
            cin.clear();
        }

        string str;
        while(cin >> str) //在输入换行之前，都阻塞在这里
            cout<<str<<endl;
    }
        break;
    case 1: //【1】测试cin.get()： 1) 不会丢掉结束符号； 2) 既可以读单个字符也可以读字符串
    {
        char a1[20];
        // 输入例子：
        // - "abcd"
        // - "abcde"
        // - "abcr"
        // - "rg"  // 如果输入"rg"，会直接报错，为啥？
        cin.get(a1, 5, 'r');
        cout <<"a1数组为: "<< a1 << "<a1" << endl;
    }
        break;
    case 2://【2】测试cin.getline(): 1) 一行中的字符数超过设置值将出错，此函数的设计是为了读完一行，所以读不完就会出错；2) 会丢掉结束符
    {
        // 输入例子：
        // - "abcd"
        char a2[20];
        cin.getline(a2, 5, '\n'); //如果上面输入的是: 123r[回车]，那么这条语句就直接结束了
        cout << "a2: " << a2 << "<a2" <<endl;
    }
        break;
    case 3://【3】读文件里的图像名（包含数字和字母），并且结束符不是空格时，用于替换cin>>
    {
        //输入例子：
        // - "image10-11;image10-11.png"
        char imageName1[20];
        cin.get(imageName1, 20, ';');
        cout << "imageName1: " << imageName1 << endl;
    }
        break;
    case 4:
    {
        // 使用getline()函数
        string str1;
        getline(cin, str1);
        cout << "str1: " << str1 << endl;
    }
        break;
    default:
        break;
    }


    {
        if( cin.fail())
        {
            cout << "Fail flag: " <<  cin.fail() << endl;
            cin.clear();
        }
    }
    char ch1;
    while(!cin.eof())
    {
        cin.get(ch1);
        cout <<"ch1字符为: "<<ch1<<" ，转换为int类型为: "<<(int)ch1<<endl;
    }

    return 0;
}
