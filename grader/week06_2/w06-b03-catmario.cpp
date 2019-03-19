#include <iostream>
using namespace std;
int main()
{
    int n,m,x,y,all=0;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++)
        a[i] = 501;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        x--;
        a[x] = min(a[x],y);
    }
    for(int i=0;i<n;i++)
        all += a[i];
    cout << all << endl;
    for(int i=0;i<n;i++)
        cout << i+1 << " " << a[i] << endl;
    return 0;
}