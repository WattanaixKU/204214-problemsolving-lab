#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int bs(int start, int stop, int x)
{
    int mid = (start+stop)/2;
    if(v[mid] == x)
        return mid;
    if(stop-start<=1)
        return start;
    if(v[mid] < x)
        return bs(mid+1,stop,x);
    return bs(start,mid,x);
}
int main()
{
    int n,m,t,dis,c, last_robot = -1, ans = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++)
    {
        vector<int> v2;
        cin >> t;
        c = bs(0,n,t)-2;
        dis = 1000001;
        for(int j=c;j<c+4;j++)
        {
            if(j==last_robot)
                continue;
            if(j<0 || j>=n)
                continue;
            if(abs(v[j]-t)<dis)
            {
                c = j;
                dis = abs(v[j]-t);
            }
        }
        ans += dis;
        //cout << dis << " " << c << endl;
        last_robot = c;
    }
    cout << ans << endl;
    return 0;
}
