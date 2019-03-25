#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,inp1,inp2,ans = 0, finish = 0;
    pair<int,int> c;
    cin >> n;
    vector<pair<int,int> > vii;
    for(int i=0;i<n;i++)
    {
        cin >> inp1 >> inp2;
        vii.push_back(make_pair(inp1,inp2));
    }
    sort(vii.begin(),vii.end());
    //finish = vii[0].first;
    for(int i=0;i<n;i++)
    {
        finish+=vii[i].second;
        ans = max(finish-vii[i].first,ans);
    }
    ans = max(0,ans-10);
    cout << ans*1000 << endl;
    return 0;
}
