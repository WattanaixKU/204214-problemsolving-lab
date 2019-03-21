#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<pair<int,bool> > s;
    int n,m,start,d,count = 0;
    pair<int,bool> c;
    cin >> n >> m;
    vector<bool> visited(n,0);
    vector<int> tv;
    vector<vector<int> > tbl(n,tv);
    for(int i=0;i<m;i++)
    {
        cin >> start >> d;
        start--;
        d--;
        tbl[start].push_back(d);
        tbl[d].push_back(start);
    }
    for(int i=0;i<n;i++)
        s.push_back(make_pair(i,1));
    while(s.size())
    {
        c = s[s.size()-1];
        s.pop_back();
        if(visited[c.first])
            continue;
        visited[c.first] = 1;
        if(c.second)
            count++;
        for(int i=0;i<tbl[c.first].size();i++)
        {
            if(!visited[tbl[c.first][i]])
                s.push_back(make_pair(tbl[c.first][i],0));
        }
    }
    cout << count << endl;
    return 0;
}
