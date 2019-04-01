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
    int ans[n][n];
    for(int i=0;i<n;i++)
    {
        tmp = 0;
        for(int j=i;j<n;j++)
        {
            tmp += a[j];
            ans[i][j] = tmp;
        }
    }
    for(int ii=0;ii<k;ii++)
    {
        bool find = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
                if(ans[i][j] == q[ii])
                    find = 1;
        }
        if(find)
            cout << 'Y';
        else
            cout << 'N';
    }
    cout << endl;
    return 0;
}
