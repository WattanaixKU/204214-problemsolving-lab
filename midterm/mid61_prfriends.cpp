#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int l,r,ans = 0;
    cin >> l >> r;
    l = max(l,2);
    bool a[r+1];
    for(int i=0;i<=r;i++)
        a[i] = 1;
    for(int i=2;i<=r;i++)
    {
        if(!a[i])
            continue;
        for(int j=i+i;j<=r;j+=i)
            a[j] = 0;
    }
    int lastp = -1;
    for(int i = l;i<=r;i++)
    {
        if(a[i])
        {
//            cout << i << " ";
            if(lastp == -1)
            {
                lastp = i;
                continue;
            }
            if(i-lastp == 2)
                ans++;
            lastp = i;
        }
    }
    cout << ans << endl;
    return 0;
}
