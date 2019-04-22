#include <iostream>
#include <vector>
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

int main()
{
    int n,m,m1,m2;
    char mode;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        boss_tbl.push_back(i);
        team_size.push_back(1);
    }
    for(int i=0;i<m;i++)
    {
        cin >> mode >> m1 >> m2;
        m1--;
        m2--;
        if(mode == 'q')
            cout << (is_team(m1, m2) ? "yes" : "no") << endl;
        else
            merge_team(m1 ,m2);
    }
    return 0;
}