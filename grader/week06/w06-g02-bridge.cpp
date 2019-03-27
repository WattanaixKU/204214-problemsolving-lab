#include <iostream>
using namespace std;
int main()
{
    int n;
    int v[n];
    int h[n];
    int tbl[n];
    int current;
    bool write = false;
    for(int i =0;i<n;i++)
        cin >> v[i];
    for(int i =0;i<n;i++)
        cin >> h[i];
    for(int i = 0;i<n;i++)
    {
        if(v[i]==h[i])
        {
            write = true;
            current = i;
        }
        if(write)
            tbl[i] = 1;
        else
            tbl[i] = 0;
    }
    for(int i=1;i<n;i++)
    {
        if(h[i]==v[0] && i<=current)
        {
            current = i;
            tbl[i] = 1;
        }
        for(int j=0;j<n;j++)
        {
            if(v[i]==h[j])
            {
            }
            else
            {
                tbl[i] = tbl[i-1];
            }
        }
    }
    
    return 0;
}