#include <iostream>
using namespace std;
int main()
{
    int n,x,y,a,b,r,ans = 0;
    cin >> n >> a >> b >> r;
    r *= r;
    for(int i =0;i<n;i++)
    {
        cin >> x >> y;
        if((x-a)*(x-a)+(y-b)*(y-b)<=r)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
