#include <iostream>
#include <vector>
using namespace std;
vector<vector<vector<int> > > dp;
vector<vector<char> > tbl;
int n;
int wayout(int x,int y)
{
    if(y == -1)
        return x+1;
    if(x == n)
        return n + y+1;
    if(y == n)
        return 2*n + (n-x);
    if(x == -1)
        return 3*n + (n-y);
}
int gogoletsgo(int x, int y, int d)
{
    if(x < 0 || x == n || y < 0 || y == n)
        return wayout(x,y);
    if(dp[x][y][d] != -1)
        return dp[x][y][d];
    int ans;
    if(d==0)    //my switch case
    {
        if(tbl[x][y]=='.')
            ans = gogoletsgo(x-1,y,0);
        else if(tbl[x][y]=='\\')
            ans = gogoletsgo(x,y-1,3);
        else
            ans = gogoletsgo(x,y+1,2);
    }
    else if(d==1)
    {
        if(tbl[x][y]=='.')
            ans = gogoletsgo(x+1,y,1);
        else if(tbl[x][y]=='\\')
            ans = gogoletsgo(x,y+1,2);
        else
            ans = gogoletsgo(x,y-1,3);
    }
    else if(d==2)
    {
        if(tbl[x][y]=='.')
            ans = gogoletsgo(x,y+1,2);
        else if(tbl[x][y]=='\\')
            ans = gogoletsgo(x+1,y,1);
        else
            ans = gogoletsgo(x-1,y,0);
    }
    else
    {
        if(tbl[x][y]=='.')
            ans = gogoletsgo(x,y-1,3);
        else if(tbl[x][y]=='\\')
            ans = gogoletsgo(x-1,y,0);
        else
            ans = gogoletsgo(x+1,y,1);
    }
    dp[x][y][d] = ans;
    return ans;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        vector<vector<int> > outer;
        vector<char> charv;
        for(int j=0;j<n;j++)
        {
            char tmp;
            cin >> tmp;
            charv.push_back(tmp);
            vector<int> inner;
            for(int k=0;k<4;k++)
                inner.push_back(-1);
            outer.push_back(inner);
        }
        tbl.push_back(charv);
        dp.push_back(outer);
    }
    return 0;
}