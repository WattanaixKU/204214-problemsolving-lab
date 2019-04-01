#include <iostream>
using namespace std;
int main()
{
    int n,k,tmp = 0,mx = -1;
    cin >> n >> k;
    int a[n],q[k];
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<k;i++)
    {
        cin >> q[i];
        mx = max(mx,q[i]);
    }
    mx++;
    int ans[mx];
    for(int i=0;i<mx;i++)
        ans[i] = 0;
    for(int i=0;i<n;i++)
    {
        tmp = 0;
        for(int j=i;j<n;j++)
        {
            tmp += a[j];
            //cout <<i <<" " << j << " "<< tmp << endl;
            if(tmp<=mx)
                ans[tmp] = 1;
        }
    }
    for(int i=0;i<k;i++)
    {
        if(ans[q[i]])
            cout << 'Y';
        else
            cout << 'N';
    }
    cout << endl;
    return 0;
}
