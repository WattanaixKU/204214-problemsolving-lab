#include <iostream>
using namespace std;
int add_bin(int a, int b)
{
    int ans = 0,i=1;
    while(!(a == 0 && b == 0))
    {
        ans += (((a%2)+(b%2))%2)*i;
        a /= 2;
        b /= 2;
        i *= 2;
    }
    return ans;
}
int main()
{
    int a,b;
    while(cin >> a)
    {
        cin >> b;
        cout << add_bin(a,b) << endl;
    }
    return 0;
}