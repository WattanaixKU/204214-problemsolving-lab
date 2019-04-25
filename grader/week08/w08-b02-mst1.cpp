#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> ipii;
int n,m;
vector<pair<int, pii> > g;
vector<int> boss_tbl;
vector<int> team_size;

void get_input()
{
    int s,f,d;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        //cin >> s >> f >> d;
        scanf(" %d%d%d", &s, &f, &d);
        s--;
        f--;
        g.push_back(make_pair(d,make_pair(s,f)));
    }
    sort(g.begin(), g.end());
}

int find_boss(int member)
{
    while(boss_tbl[member] != member)
        member = boss_tbl[member];
    return member;
}

bool is_team(int x, int y) //is_union
{
    int boss_x = find_boss(x);
    int boss_y = find_boss(y);
    if(boss_x == boss_y)
        return true;
    return false;
}

void merge_team(int x, int y)
{
    int boss_x = find_boss(x);
    int boss_y = find_boss(y);
    if(team_size[boss_x] < team_size[boss_y])
    {
        boss_tbl[boss_x] = boss_y;
        team_size[boss_y] += team_size[boss_x];
        team_size[boss_x] = 0; //Just make more sense (team x was gone T-T)
    }
    else
    {
        boss_tbl[boss_y] = boss_x;
        team_size[boss_x] += team_size[boss_y];
        team_size[boss_y] = 0;
    }
}

int kruskal()
{
    int ans = 0;
    int size_of_new_tree = 0;
    while(size_of_new_tree!=n && !g.empty())
    {
        pair<int, pii> c = g.front();
        g.erase(g.begin());
        if(!is_team(c.second.first, c.second.second))
        {
            ans += c.first;
            size_of_new_tree++;
            merge_team(c.second.first, c.second.second);
        }
        //cout << c.second.first << " " << c.second.second << endl;
    }
    return ans;
}

int main()
{
    get_input();
    for(int i=0;i<n;i++)
    {
        boss_tbl.push_back(i);
        team_size.push_back(1);
    }
    //check_graph();
    cout << kruskal() << endl;
    return 0;
}
