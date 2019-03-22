#include <iostream>
using namespace std;
typedef pair<int,pair<bool,bool> > ibb;
char tbl[30][30];
int n,m,rare = 0, super_rare = 0;
ibb check(int x, int y)
{
    ibb c = make_pair(0,make_pair(0,0));
    int land = 0;
    bool forest = 0, mine = 0;
    if(x<0 || y<0 || x>=n || y>=m)
        return c;
    else if(tbl[x][y] == '#')
        return c;
    if(tbl[x][y] == '*')
        forest = 1;
    else if(tbl[x][y] == '$')
        mine = 1;
    tbl[x][y] = '#';
    c = check(x-1,y);
    ibb c1 = check(x,y-1);
    ibb c2 = check(x,y+1);
    ibb c3 = check(x+1,y);
    land = 1+c.first + c1.first + c2.first + c3.first;
    forest = forest || c.second.first || c1.second.first || c2.second.first || c3.second.first;
    mine = mine || c.second.second || c1.second.second || c2.second.second || c3.second.second;
    return make_pair(land,make_pair(forest,mine));
}
int main()
{
    ibb t;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> tbl[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            t = check(i,j);
            if(t.second.first && t.second.second)
                super_rare += t.first;
            else if(t.second.first || t.second.second)
                rare += t.first;
        }
    cout << super_rare << " " << rare << endl;
    return 0;
}
