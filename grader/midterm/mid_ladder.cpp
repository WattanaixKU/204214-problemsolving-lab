#include <iostream>
using namespace std;
int main()
{
    int n,k,ans = 0,x;
    cin >> n >> k;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=0;i<k;i++)
    {
        cin >> x;
        if(ans == n)
            continue;
        ans = min(x+ans,n);
        ans = max(0,min(a[ans]+ans,n));
    }
    cout << ans << endl;
    return 0;
}
