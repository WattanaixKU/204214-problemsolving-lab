#include <iostream>
using namespace std;
int n,m,x,y;
char tbl[51][51];
int go(int cx, int cy, int ox, int oy, bool dig)
{
    if(cx == x && cy == y)
        return 0;
    if(tbl[cx][cy] == '#')
        return 10000;
//    cout << cx << " " << cy << tbl[cx][cx]<< endl;
    if(tbl[cx][cy] == '*')
    {
        if(!dig)
            return 10000;
        dig = 0;
        if(ox == cx)
            return 1+min(go(cx,cy-1,cx,cy,dig), go(cx,cy+1,cx,cy,dig));
        else
            return 1+min(go(cx-1,cy,cx,cy,dig), go(cx+1,cy,cx,cy,dig));
    }
    tbl[cx][cy] = '#';
    return 1+min(
            min(go(cx-1,cy,cx,cy,dig), go(cx+1,cy,cx,cy,dig)), 
            min(go(cx,cy-1,cx,cy,dig), go(cx,cy+1,cx,cy,dig)) );
}
int main()
{
    cin >> n >> m;
    int x1,y1;
    cin >> x1 >> y1 >> x >> y;
    x1--;
    y1--;
    x--;
    y--;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> tbl[i][j];
 /*   for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout << tbl[i][j];
        cout <<endl;
    }
    */
    int ans = go(x1,y1,x1,y1,true);
    if(ans < 10000)
        cout << ans << endl;
    else
        cout << -1 << endl;
/*    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout << tbl[i][j];
        cout <<endl;
    }
    */
    return 0;
}
