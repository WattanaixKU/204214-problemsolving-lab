#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > vvi;
vector<int> vsize;
vector<bool> visited;
bool mfind(int s,int d)
{
    if(s==d)
        return 1;
    visited[s] = 1;
    bool ans = 0;
    for(int i = 0;!ans && i < vsize[s];i++)
        if(!visited[vvi[s][i]])
            ans = ans || mfind(vvi[s][i],d);
    return ans;
}
int main()
{
    int n,m,k,s,f;
    cin >> n >> m >> k;
    vector<int> t;
    for(int i=0;i<n;i++)
    {
        vvi.push_back(t);
        visited.push_back(0);
        vsize.push_back(0);
    }
    for(int i=0;i<m;i++)
    {
        cin >> s >> f;
        s--;
        f--;
        vvi[s].push_back(f);
        vvi[f].push_back(s);
        vsize[s]++;
        vsize[f]++;
    }
    bool find;
    for(int i=0;i<k;i++)
    {
        cin >> s >> f;
        s--;
        f--;
        for(int j=0;j<n;j++)
            visited[j] = 0;
        if(mfind(s,f))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
