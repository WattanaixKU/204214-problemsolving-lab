#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    stack<pair<int,bool> > s;
    int n,m,start,d,count = 0;
    pair<int,bool> c;
    cin >> n >> m;
    //bool tbl[n][n];
    vector<vector<int> > tbl;
    //cout << "pass1" << endl;
    bool visited[n];
    vector<int> tv;
    for(int i=0;i<n;i++)
    {
        tbl.push_back(tv);
    }
    for(int i=0;i<m;i++)
    {
        cin >> start >> d;
        //cout << start << d << endl;
        start--;
        d--;
        //tbl[start][d] = true;
        //tbl[d][start] = true;
        tbl[start].push_back(d);
        tbl[d].push_back(start);
    }
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << tbl[i][j];
        cout << endl;
    }*/

    for(int i=0;i<n;i++)
    {
        visited[i] = false;
        s.push(make_pair(i,true));
    }
    while(!s.empty())
    {
        //cout << "size of stack" << s.size() << endl;
        c = s.top();
        //cout << "\nstart " << c.first << " " << c.second;
        s.pop();
        if(visited[c.first])
            continue;
        //cout << "go on";
        visited[c.first] = true;
        if(c.second)
            count++;
        for(int i=0;i<tbl[c.first].size();i++)
        {
            if(!visited[tbl[c.first][i]])
                s.push(make_pair(tbl[c.first][i],false));
        }
    }
    cout << count << endl;
    return 0;
}
