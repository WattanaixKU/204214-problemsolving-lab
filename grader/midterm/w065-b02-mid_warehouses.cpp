#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n,m,k,s,f;
    cin >> n >> m >> k;
    vector<set<int> > v(n);
    for(int i=0;i<n;i++)
        v[i].insert(i);
    for(int i=0;i<m;i++)
    {
        cin >> s >> f;
        s--;
        f--;
        if(v[s].find(f) == v[s].end())
        {
            for(set<int>::iterator it = v[f].begin();it!=v[f].end();it++)
                v[s].insert(*it);
            v[f] = v[s];
            for(set<int>::iterator it = v[s].begin();it!=v[s].end();it++)
                v[*it] = v[f];
        }
    
    }
    for(int i=0;i<k;i++)
    {
        cin >> s >> f;
        s--;
        f--;
        if(v[s].find(f)!=v[s].end())
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}