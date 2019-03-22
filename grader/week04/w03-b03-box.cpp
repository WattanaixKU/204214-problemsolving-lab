#include <iostream>
using namespace std;
char tbl[30][30];
bool visited[30][30];
int n,m;
bool check(int x, int y)
{
    if(x<0 || y<0 || y>=m-1)
        return 0;
    else if(x>=n-1)
        return 1;
    if(visited[x][y])
        return 0;
    visited[x][y] = 1;
    if(tbl[x][y] == '.' && tbl[x+1][y] == '.' && tbl[x][y+1] == '.' && tbl[x+1][y+1] == '.')
        return check(x-1,y) || check(x+1,y) || check(x,y-1) || check(x,y+1);
    return 0;
}
int main()
{
    bool ans = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> tbl[i][j];
            visited[i][j] = 0;
        }
        for(int j=0;j<m-1;j++)
            ans = ans || check(0,j);
    if(ans)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
