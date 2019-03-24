#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
pii tbl[1001];
priority_queue<pii, vector<pii>, greater<pii> > pq;
bool visited[1001];
int main()
{
    int n,p,x,y;
    bool found = false;
    pii c;
    cin >> n >> p;
    p *= p;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        tbl[i] = make_pair(x,y);
        visited[i] = 0;
        if((x*x+y*y) <= p)
            pq.push(make_pair(1,i));
    }
    if(20000<=p)
        pq.push(make_pair(1,n));
    tbl[n] = make_pair(100,100);
    while(!pq.empty())
    {
        c = pq.top();
        pq.pop();
        if(c.second == n)
        {
            cout << c.first << endl;
            found = true;
            break;
        }
        if(visited[c.second])
            continue;
        visited[c.second] = 1;
        x = tbl[c.second].first;
        y = tbl[c.second].second;
        for(int i=0;i<=n;i++)
        {
            if(((tbl[i].first-x)*(tbl[i].first-x)+(tbl[i].second-y)*(tbl[i].second-y))<=p && !visited[i])
                pq.push(make_pair(c.first+1,i));
        }
    }
    if(!found)
        cout << -1 << endl;
    return 0;
}
