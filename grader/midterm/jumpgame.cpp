#include <iostream>
using namespace std;
int tbl[3000][3000];
int n,m;
bool check(int x, int y, int h)
{
    if(x<0 || x==n || y<0 || y==m)
        return 0;
    if(h-tbl[x][y] > power)
        return 0;
    if(x==n-1 && y==m-1)
        return 1;
    bool ans = 0;
    ans = ans || check(x-1,y,tbl[x][y];
    ans = ans || check(x+1,y,tbl[x][y];
    ans = ans || check(x,y-1,tbl[x][y];
    ans = ans || check(x,y+1,tbl[x][y];
    return ans;
}


int main()
{

    return 0;
}
