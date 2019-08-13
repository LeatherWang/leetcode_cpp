#include <iostream>
#include <cstring>

using namespace std;

int factor_val(void)
{
    int result = 0;
    char ch = cin.peek();
    if(ch == '(')
    {
        cin.get();
        result = expression_val();
        cin.get();
    }
    else
    {
        while(true)
        {
            if(isdigit(ch))
            {
                cin.get();
                result = result*10 + ch-'0';
                ch = cin.peek();
            }
            else
                break;
        }
    }
    return result;
}

int term_val(void)
{
    int result = factor_val();
    while(true)
    {
        char op = cin.peek();
        if(op == '*' || op == '/')
        {
            cin.peek();
            int a = factor_val();
            if(op=='*')
                result *= a;
            else
                result /= a;
        }
        else
            break;
    }
    return result;
}

int expression_val(void)
{
    int result = term_val();
    while(1)
    {
        char op = cin.peek();
        if(op == '+' || op == '-')
        {
            cin.get(); //! @attention 不可少
            int a = term_val();
            if(op == '+')
                result +=a;
            else
                result -=a;
        }
        else
            break;
    }
    return result;
}

//输入：(2+3)*(5+7)+9/3
//输出： 63
int main()
{
    return 0;
}















