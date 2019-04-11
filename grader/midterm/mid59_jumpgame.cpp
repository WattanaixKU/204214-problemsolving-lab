#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<pair<int,pair<int,int> > > pq;
    int n,h,p;
    bool find = 0;
    pair<int, int> c;
    cin >> n >> p;
    int tbl[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> tbl[i][j];
    pq.push(make_pair(tbl[0][0]+p,make_pair(0,0)));
    while(!pq.empty())
    {
        c = pq.top().second;
        h = pq.top().first;
        int x = c.first;
        int y = c.second;
        //cout << x << " " << y << endl;
        pq.pop();
        if(c.first < 0 || c.first == n || c.second < 0 || c.second == n)
            continue;
        if(h<tbl[c.first][c.second])
            continue;
        if(c.first == n-1 && c.second == n-1)
        {
            find = 1;
            cout << "yes" << endl;
            break;
        }
        int ch = tbl[c.first][c.second] + p;
        tbl[c.first][c.second] = 1000001;
        pq.push(make_pair(ch,make_pair(x+1,y)));
        pq.push(make_pair(ch,make_pair(x-1,y)));
        pq.push(make_pair(ch,make_pair(x,y+1)));
        pq.push(make_pair(ch,make_pair(x,y-1)));
    }
    if(!find)
        cout << "no" << endl;
    return 0;
}
