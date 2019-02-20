#include <iostream>
using namespace std;

int tbl[64726];
pair<int,bool> find_index(int x, int begin, int end)
{
    if(begin > end)
        return make_pair(end,false);
    int i = (begin+end)/2;
    if(tbl[i]==x)
        return make_pair(i,true);
    else if(tbl[i] > x)
        return find_index(x, begin, i-1);
    else 
        return find_index(x, i+1, end);
}
int main()
{
    int i=2;
    tbl[0] = 1;
    tbl[1] = 2;
    while(tbl[i-1]<=1000000)
    {
        tbl[i] = tbl[i-1];
        int j;
        for(j=1;(j*j)<tbl[i-1];j++)
        {
            if(tbl[i-1]%j==0)
                tbl[i]+=2;
        }
        if(tbl[i-1]==j*j)
            tbl[i]++;
            
        i++;
    }
    int t,a,b;
    pair<int,bool> pa,pb;
    cin >> t;
    for(int r=0;r<t;r++)
    {
        cin >> a >> b;

        pa = find_index(a,0 , 64726);
        pb = find_index(b,0 , 64726);
        cout << "Case " << r+1 << ": ";
        if(pa.second && pb.second)
            cout << pb.first - pa.first + 1 << endl;
        else if(pa.second)
            cout << pb.first - pa.first + 1<< endl;
        else
            cout << pb.first - pa.first << endl;
    }
    return 0;
}
