#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,inp1,inp2,ans = 1, finish;
    pair<int,int> c;
    cin >> n;
    vector<pair<int,int> > vii;
    for(int i=0;i<n;i++)
    {
        cin >> inp1 >> inp2;
        vii.push_back(make_pair(inp2,inp1));
    }
    sort(vii.begin(),vii.end());
    finish = vii[0].first;
    inp1 = 0;
    while(inp1<n)
    {
        c = vii[inp1];
        inp1++;
        if(c.second<finish)
            continue;
        ans++;
        finish = c.first;
    }
    cout << ans << endl;
    return 0;
}
