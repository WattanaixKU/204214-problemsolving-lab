#include <iostream>
#include <cmath>
using namespace std;
bool tree[1048576];
int drop(int d,int pos)
{
    tree[pos] = !tree[pos];
    if(d==0)
        return pos;
    if(tree[pos*2+1] == tree[pos*2+2])
        return drop(d-1,pos*2+1);
    return drop(d-1,pos*2+2);
}
int main()
{
    int t,d,b;
    cin >> t;
    for(int r=0;r<t;r++)
    {
        cin >> d >> b;
        for(int i=0;i<pow(2,d);i++)
            tree[i] = 0;
            //cout << i << endl;
        for(int i=0;i<b-1;i++)
            drop(d-1,0);
        cout << drop(d-1,0)+1 << endl;
    }
    cin >> t;
    return 0;
}