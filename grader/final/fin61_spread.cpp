#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> boss_tbl;
vector<int> team_size;
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
    if(!is_team(x, y))
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
}
int n, m;
vector<int> power_of_n;
int main()
{
    int tmp,ans = 0;
    vector<int> vt(3);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        boss_tbl.push_back(i);
        team_size.push_back(1);
    }
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        power_of_n.push_back(tmp);
    }
    queue<vector<int> > vl;
    for(int i=0;i<m;i++)
    {
        cin >> vt[0] >> vt[1] >> vt[2];
        vt[0]--;
        vt[1]--;
        vl.push(vt);
    }
    while(!vl.empty())
    {
        if(team_size[0]==n)
            break;
        ans++;
        int this_round = vl.size();
        for(int i=0;i<this_round;i++)
        {
            vt = vl.front();
            //printf("%d | %d %d %d\n",ans, vt[0]+1, vt[1]+1, vt[2]);
            vl.pop();
            if(is_team(vt[0],vt[1]))
                continue;
            vt[2] -= power_of_n[vt[0]]+power_of_n[vt[1]];
            if(vt[2] <= 0)
                merge_team(vt[0], vt[1]);
            else
                vl.push(vt);
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}
