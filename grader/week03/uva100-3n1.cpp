#include <iostream>
using namespace std;
int count(int inp)
{
    int c = 1;
    while(inp != 1)
    {
        //cout << inp << endl;
        c++;
        if(inp%2!=0)
            inp = 3*inp+1;
        else
            inp = inp / 2;
    }
    return c;
}
int main()
{
    int a,b,c,mx,t;
    while(cin >> a)
    {
        t = -1;
        mx=-1;
        cin >> b;
        if(a>b)
        {
            t = a;
            a = b;
            b = t;
        }
        for(int i=a;i<=b;i++)
        {
            c = count(i);
            if(c>mx)
                mx = c;
        }
        if(t==-1)
            cout << a << ' ' << b<< ' ' << mx << endl;
        else
            cout << b << ' ' << a<< ' ' << mx << endl;
    }
    return 0;
}
