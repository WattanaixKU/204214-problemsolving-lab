#include <iostream>
using namespace std;
int main()
{
    int n,x,y,r,ans = 10000000;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y >> r;
        ans = min(ans, abs(y)-r);
    }
    if(ans > 0)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
