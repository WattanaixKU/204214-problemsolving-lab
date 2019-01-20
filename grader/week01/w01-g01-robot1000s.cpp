#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<char, int> di = {{'N', 0}, {'S', 1}, {'E', 2}, {'W', 3}};
    int k, mx = -1, count[4] = {0,0,0,0};
    string s;
    cin >> s >> k;
    for(int t=0;s[t]!='\0';t++)
        count[di[s[t]]]++;
    for(int i=0;i<=min(k,count[0]);i++)
        for(int j=0;j<=min(k-i,count[1]);j++)
            for(int u=0;u<=min(k-i-j,count[2]);u++)
                if(k-i-j-u <= count[3])
                    mx = max(mx,abs(count[0]-i-count[1]+j)+abs(count[2]-u-count[3]+(k-i-j-u)));
    cout << mx*2 << endl;
    return 0;
}
