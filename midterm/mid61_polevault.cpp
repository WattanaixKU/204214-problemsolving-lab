#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> ans;
bool bst(int s, int f,int x)
{
    if(s-f>=1)
        return 0;
    int mid = (f+s)/2;
//    cout << s << " " << f << ans[mid] << endl;
    if(ans[mid] == x)
        return 1;
    if(ans[mid] < x)
        return bst(mid+1,f,x);
    return bst(s,mid-1,x);
}
int main()
{
    int n,k,tmp = 0;
    cin >> n >> k;
    int a[n],q[k];
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<k;i++)
    {
        cin >> q[i];
    }
    for(int i=0;i<n;i++)
    {
        tmp = 0;
        for(int j=i;j<n;j++)
        {
            tmp += a[j];
            ans.push_back(tmp);
        }
    }
    sort( ans.begin(), ans.end() );
    ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
    int ns = ans.size();
    for(int ii=0;ii<k;ii++)
    {
        if(bst(0,ns,q[ii]))
            cout << 'Y';
        else
            cout << 'N';
    }
    cout << endl;
    return 0;
}
