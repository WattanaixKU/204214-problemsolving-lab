#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int n,m,src,dest;
vector<vector<pii> > g;
void check_graph()
{
    for(int i=0;i<n;i++)
    {
        int e = g[i].size();
        cout << i+1 << " | ";
        for(int j=0;j<e;j++)
        {
            cout << "(" << g[i][j].first+1 << "," << g[i][j].second << ") ";
        }
        cout << endl;
    }
}
void get_input()
{
    cin >> n >> m >> src >> dest;
    vector<pii> tmp;
    tmp.push_back(make_pair(0,0));
    int s,f,d;
    for(int i=0;i<n;i++)
    {
        tmp[0].first = i;
        g.push_back(tmp);
    }
    //cout << "pass" << endl;
    for(int i=0;i<m;i++)
    {
        cin >> s >> f >> d;
        g[s].push_back(make_pair(f,d));
        g[f].push_back(make_pair(s,d));
    }
}
int dijkstra(int source, int dest)
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    pq.push(make_pair(0 ,source));
    while(!pq.empty())
    {
        pii c = pq.top();
        pq.pop();
        //cout << c.second << " " << c.first << endl;
        if(c.second == dest)
            return c.first;
        else if(visited[c.second])
            continue;
        visited[c.second] = 1;
        int e = g[c.second].size();
        for(int i=0;i<e;i++)
            if(!visited[g[c.second][i].first])
                pq.push(make_pair(g[c.second][i].second + c.first , g[c.second][i].first));
    }
    return -1;
}
int main()
{
    int T;
    cin >> T;
    for(int t=0;t<T;t++)
    {
        get_input();
        //check_graph();
        int path = dijkstra(src, dest);
        cout << "Case #" << t+1 << ": ";
        if(path != -1)
            cout << path << endl;
        else
            cout << "unreachable" << endl;
        g.clear();
    }
    return 0;
}