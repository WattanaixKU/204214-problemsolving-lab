#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<pair<int,bool> > s;
    int n,m,start,d,count = 0;
    pair<int,bool> c;
    cin >> n >> m;
    bool tbl[n][n];
    bool visited[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            tbl[i][j] = 0;
    for(int i=0;i<m;i++)
    {
        cin >> start >> d;
        start--;
        d--;
        tbl[start][d] = 1;
        tbl[d][start] = 1;
    }
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
        s.push(make_pair(i,1));
    }
    while(!s.empty())
    {
        c = s.top();
        s.pop();
        if(visited[c.first])
            continue;
        visited[c.first] = 1;
        if(c.second == 1)
            count++;
        for(int i=0;i<n;i++)
        {
            if(tbl[c.first][i] == 1)
                s.push(make_pair(i,0));
        }
    }
    cout << count << endl;
    return 0;
}
