#include <iostream>
using namespace std;
char tbl[20][20];
int n,k;
bool check(int a, int b, int x, int y, bool key)
{
    if(a<0 || b<0 || a==n || b==n)
        return 0;
    if(a==x && b==y)
        return 1;
    if(tbl[a][b] == '#')
        return 0;
    if(tbl[a][b] == 'O')
    {
        if(key)
            key = false;
        else
            return 0;
    }
    char tmp = tbl[a][b];
    tbl[a][b] = '#';
    bool ans = check(a-1,b,x,y,key) || check(a+1,b,x,y,key) || check(a,b-1,x,y,key) || check(a,b+1,x,y,key);
    tbl[a][b] = tmp;
    return ans;
}
int main()
{
    int a,b,x,y;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> tbl[i][j];
    for(int i=0;i<k;i++)
    {
        cin >> a >> b >> x >> y;
        a--;
        b--;
        x--;
        y--;
        if(check(a,b,x,y,true))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
