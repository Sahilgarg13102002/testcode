#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;




double f(double x)
{
    return 3*x + sin(x) - exp(x);
}

bool same_sign(double a , double b)
{
    return f(a)*f(b)/abs(f(a)*f(b)) == 1;
}

double x_intercept(double a,double b)
{
    return ((a-b)*f(a)/(f(b)-f(a))) + a;
}

double root(double a , double b,int precision = 6)
{
    int check = 0;
    double pre_intercept = 0;
    double intercept = 0;
    int i = 0;
    while(true)
    {
        intercept = x_intercept(a,b);
        if(same_sign(intercept,a))
        {
            a = intercept;
        }
        else 
        {
            b = intercept;
        }
        if(check!=0 && int((intercept-pre_intercept)*(pow(10,precision))) == 0) 
        {
            break;    
        }
        check++;
        pre_intercept = intercept;
    }
    setprecision(precision);
    return intercept;
}

int main()
{
    double a = root(0,1.21,53); 
    cout<<setprecision(60)<<a;
    return 0;

    int b = 3
    cout<<b;
}

//0.36042372554426893583    only 4 precise
//0.36042170296032449706    upto 15 precise
