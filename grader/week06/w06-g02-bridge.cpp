#include <iostream>
using namespace std;
int main()
{
    int n;
    int v[n];
    int h[n];
    int tbl[n];
    int current[n];
    int c = 0;
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
            c = i;
        }
        if(write)
            tbl[i] = 1;
        else
            tbl[i] = 0;
        current[i] = c;
    }
    for(int i=1;i<n;i++)
    {
        write = false;
        for(int j=0;j<n;j++)
        {
            if(v[i]==h[j] || write)
            {
                if(j>current[j])
                {
                    current[j] = j;
                    tbl[j]++;
                }
                else if(j==current[j] && j<current)
            }
        }
    }
    
    return 0;
}