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
vector<int> power_of_n;

void get_input()
{
    int s,f,d,tmp,chal;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        power_of_n.push_back(tmp);
    }
    for(int i=0;i<m;i++)
    {
        //cin >> s >> f >> d;
        scanf(" %d%d%d", &s, &f, &d);
        s--;
        f--;
        chal = d/(power_of_n[s]+power_of_n[f]);
        if(d%(power_of_n[s]+power_of_n[f]) != 0)
            chal++;
        g.push_back(make_pair(chal,make_pair(s,f)));
        
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

int merge_team(int x, int y)
{
    int boss_x = find_boss(x);
    int boss_y = find_boss(y);
    if(team_size[boss_x] < team_size[boss_y])
    {
        boss_tbl[boss_x] = boss_y;
        team_size[boss_y] += team_size[boss_x];
        //team_size[boss_x] = 0; //Just make more sense (team x was gone T-T)
        return team_size[boss_y];
    }
    else
    {
        boss_tbl[boss_y] = boss_x;
        team_size[boss_x] += team_size[boss_y];
        //team_size[boss_y] = 0;
        return team_size[boss_x];
    }
}

int kruskal()
{
    int ans = -1;
    int ind = 0;
    while(ind!=m)
    {
        pair<int, pii> c = g[ind];
        ind++;
        if(!is_team(c.second.first, c.second.second))
        {
            ans = max(ans, c.first);
            //cout << c.second.first << " " << c.second.second << " " << ans << endl;
            
            if(merge_team(c.second.first, c.second.second) == n)
                break;
        }
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
