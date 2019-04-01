#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<int,int>,pair<int,int> > pii;
int n,m,x,y;
char tbl[51][51];
int main()
{
    cin >> n >> m;
    int x1,y1;
    cin >> x1 >> y1 >> x >> y;
    x1--;
    y1--;
    x--;
    y--;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> tbl[i][j];

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(make_pair(0,0),make_pair(x1,y1)));
    bool find = 0;
    while(!pq.empty())
    {
        pii c = pq.top();
        pq.pop();
        if(c.second.first == x && c.second.second == y)
        {
            cout << c.first.first << endl;
            find = 1;
            break;
        }
        if(tbl[c.second.first][c.second.second] == '#')
            continue;
        if(tbl[c.second.first][c.second.second] == '*')
        {
            if(c.first.second)
                continue;
            c.first.second = 1;
        }
        tbl[c.second.first][c.second.second] = '#';
        pq.push(make_pair(make_pair(1+c.first.first,c.first.second),make_pair(c.second.first+1,c.second.second)));
        pq.push(make_pair(make_pair(1+c.first.first,c.first.second),make_pair(c.second.first-1,c.second.second)));
        pq.push(make_pair(make_pair(1+c.first.first,c.first.second),make_pair(c.second.first,c.second.second-1)));
        pq.push(make_pair(make_pair(1+c.first.first,c.first.second),make_pair(c.second.first,c.second.second+1)));
    }
    if(!find)
        cout << -1 << endl;
    return 0;
}
