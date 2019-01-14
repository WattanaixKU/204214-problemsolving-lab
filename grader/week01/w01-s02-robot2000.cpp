#include <iostream>
using namespace std;
int turn_count(char c,char n)
{
    char di[4] = {'N', 'E', 'S', 'W'};
    int i = 0, count = 0;
    while(di[i]!=c)
        i++;
    while(di[(i+count)%4]!=n)
        count++;
    return count;
}
int main()
{
    string s;
    char ans[2000];
    cin >> s;
    int i = 0, j = 0;
    char cs = 'N';
    while(s[i]!='\0')
    {
        if(s[i] == 'Z')
        {
            ans[j] = 'Z';
            j++;
            i++;
            cs = 'N';
            continue;
        }
        for(int k=0;k<turn_count(cs,s[i]);k++)
        {
            ans[j] = 'R';
            j++;
        }
        cs = s[i];
        ans[j] = 'F';
        j++;
        i++;
    }
    cout << ans << endl;
    return 0;
}