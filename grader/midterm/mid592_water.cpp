#include <iostream>
using namespace std;
int main()
{
    int n,y = 0,td,ans = 0;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >> td;
        if(y-td>10)
            ans += min((y-td)*10,700);
        y = td;
    }
    cout << ans << endl;
    return 0;
}
