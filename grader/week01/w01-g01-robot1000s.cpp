#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    map<char, int> di;// = {{'N', 0}, {'S', 1}, {'E', 2}, {'W', 3}};
    int t = 0, k, mx = -1, count[4] = {0,0,0,0};
    string s = "NSEW";
    for(int i=0;i<4;i++)
        di[s[i]] = i;
    cin >> s >> k;
    while(s[t]!='\0')
    {
        count[di[s[t]]]++;
        t++;
    }
    for(int i=0;i<=min(k,count[0]);i++)
        for(int j=0;j<=min(k,count[1]);j++)
            for(int u=0;u<=min(k,count[2]);u++)
                for(int h=0;h<=min(k,count[3]);h++)
                    if(i+j+u+h == k)
                        mx = max(mx,abs(count[0]-i-count[1]+j)+abs(count[2]-u-count[3]+h));
    cout << mx*2 << endl;
    return 0;
}
