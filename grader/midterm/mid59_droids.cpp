#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int>::iterator vi;
/*vi bs(int start, int stop, int x)
{
    int mid = (start+stop)/2;
    if(v[mid] == x)
        return 
    return ans;
}
*/
int main()
{
    int n,m,t,dis,c, last_robot = -1, ans = 0;
    cin >> n >> m;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++)
    {
        cin >> t;
        dis = 1000001;
        for(int j=0;j<n;j++)
        {
            if(last_robot == j)
                continue;
            if(abs(v[j]-t)<dis)
            {
                dis = abs(v[j]-t);
                c = j;
            }
        }
        ans += dis;
        //cout << dis << " " << c << endl;
        last_robot = c;
    }
    cout << ans << endl;
    return 0;
}
