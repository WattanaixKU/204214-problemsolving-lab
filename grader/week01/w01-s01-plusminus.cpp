#include <iostream>
using namespace std;
int main()
{
    int n,ans;
    cin >> n;
    n--;
    cin >> ans;
    for(int i=0;i<n;i++)
    {
        char sw;
        int tmp;
        cin >> sw >> tmp;
        if(sw == '+')
            ans += tmp;
        else
            ans -= tmp;
    }
    cout << ans << endl;
    return 0;
}