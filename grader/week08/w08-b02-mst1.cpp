#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> ipii;
int n,m;
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
    cin >> n >> m;
    vector<pii> tmp;
    tmp.push_back(make_pair(0,0));
    int s,f,d;
    for(int i=0;i<n;i++)
    {
        tmp[0].first = i;
        g.push_back(tmp);
    }
    for(int i=0;i<m;i++)
    {
        cin >> s >> f >> d;
        s--;
        f--;
        g[s].push_back(make_pair(f,d));
        g[f].push_back(make_pair(s,d));
    }
}
int prim(int starter)
{
    int sum_of_path = 0, unvisited = n;
    priority_queue<ipii, vector<ipii>, greater<ipii> > pq;
    int visited[n];
    int path_to[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
        cout << visited[i] << " ";
        path_to[n] = -1;
    }
    cout << endl;
    for(int i=0;i<n;i++)
        cout << visited[i] << " ";
    cout << endl;
    pq.push(make_pair(0, make_pair(starter ,starter)));
    while(!pq.empty() && unvisited > 0)
    {
        ipii c = pq.top();
        pq.pop();
        cout << c.second.first << " " << c.second.second << " " << c.first << endl;
        cout << c.second.second << " " << visited[c.second.second] << endl;
        if(visited[c.second.second])
            continue;
        visited[c.second.second] = 1;
        cout << "I'm here" << endl;
        unvisited--;
        path_to[c.second.second] = path_to[c.second.first] + c.first;
        sum_of_path+=path_to[c.second.second];
        int e = g[c.second.second].size();
        for(int i=0;i<e;i++)
            if(!visited[g[c.second.second][i].first])
                pq.push(make_pair(g[c.second.second][i].second, make_pair(c.second.second, g[c.second.second][i].first)));
    }
    cout << "I'm out" << endl;
    return sum_of_path;
}
int main()
{
    get_input();
    //check_graph();
    cout << prim(0) << endl;
    return 0;
}