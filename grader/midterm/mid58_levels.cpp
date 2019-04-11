#include <iostream>
using namespace std;
int main()
{
    int n,m,ans = 0,t0,t1,t2;
    bool a = 0,b = 0,c = 0;
    cin >> n >> m;
    n--;
    int l[n][3];
    for(int i=0;i<n;i++)
        cin >> l[i][0] >> l[i][1] >> l[i][2];
    for(int i=0;i<m;i++)
    {
        cin >> t0 >> t1 >> t2;
        if(ans==n)
            continue;
        if(l[ans][0] <= t0)
            a = true;
        if(l[ans][1] <= t1)
            b = true;
        if(l[ans][2] <= t2)
            c = true;
        if(a && b && c)
        {
            a = 0;
            b = 0;
            c = 0;
            ans++;
        }
    }
    cout << ans+1 << endl;
    return 0;
}
