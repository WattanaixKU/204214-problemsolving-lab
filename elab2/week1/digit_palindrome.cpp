#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int backward = 0,tmp = n;
    while(tmp>0)
    {
        backward = backward*10 + tmp%10;
        tmp/=10;
    }
    if(backward==n)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}