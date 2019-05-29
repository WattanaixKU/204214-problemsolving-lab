#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int> > ipii;
int main()
{
    int T;
    cin >> T;
    for(int t=0;t<T;t++)
    {
        int n, m;
        cin >> n >> m;
        int tbl[n][m];
        bool visited[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin >> tbl[i][j];
                visited[i][j] = 0;
            }
        priority_queue<ipii, vector<ipii>, greater<ipii> > pq;
        ipii c;
        pq.push(make_pair(0,make_pair(0,0)));
        while(!pq.empty())
        {
            c = pq.top();
            pq.pop();
            if(c.second.first < 0 || c.second.first == n || c.second.second < 0 || c.second.second == m)
                continue;
            if(visited[c.second.first][c.second.second])
                continue;
            visited[c.second.first][c.second.second] = 1;
            c.first += tbl[c.second.first][c.second.second];
            if(c.second.first == n-1 && c.second.second == m-1)
            {
                cout << c.first << endl;
                break;
            }
            pq.push(make_pair(c.first,make_pair(c.second.first+1,c.second.second)));
            pq.push(make_pair(c.first,make_pair(c.second.first-1,c.second.second)));
            pq.push(make_pair(c.first,make_pair(c.second.first,c.second.second+1)));
            pq.push(make_pair(c.first,make_pair(c.second.first,c.second.second-1)));
        }
        //check_graph();
    }
    return 0;
}

