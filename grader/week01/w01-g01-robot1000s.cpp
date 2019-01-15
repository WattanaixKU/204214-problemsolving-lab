#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int count[4] = {0,0,0,0};
    string s;
    int k;
    cin >> s >> k;
    int i = 0;
    while(s[i]!='\0')
    {
        switch(s[i])
        {
            case 'N':
                count[0]+=1;
                break;
            case 'S':
                count[1]+=1;
                break;
            case 'E':
                count[2]+=1;
                break;
            case 'W':
                count[3]+=1;
                break;
        }
        i++;
    }
    int mx = -1;
    for(int i=0;i<=min(k,count[0]);i++)
    {
        for(int j=0;j<=min(k,count[1]);j++)
        {
            for(int u=0;u<=min(k,count[2]);u++)
            {
                for(int h=0;h<=min(k,count[3]);h++)
                {
                    if(i+j+u+h == k)
                        mx = max(mx,abs(count[0]-i-count[1]+j)+abs(count[2]-u-count[3]+h));
                }
            }
        }
        
    }
    cout << mx*2 << endl;
    return 0;
}