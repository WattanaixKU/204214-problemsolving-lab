#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
pii tbl[1000];
priority_queue<pii, vector<pii>, greater<pii> > pq;
bool visited[1000];
int main()
{
    int n,p,x,y;
    pii c;
    cin >> n >> p;
    p *= p;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        tbl[i] = make_pair(t1,t2);
        if((t1*t1+t2*t2) <= p)
            pq.push(make_pair(1,i));
    }
    while(!pq.empty())
    {
        c = pq.top();
        pq.pop();
        //if((100-tbl[c.second].first))
        cout << c.first << " " << c.second << endl;
    }
    return 0;
}
