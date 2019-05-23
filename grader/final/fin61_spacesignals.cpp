#include <iostream>
using namespace std;
int main()
{
    string s,t;
    cin >> s;
    cin >> t;
    int i=0,j=0,ans=0;
    while(t[i]!='\0')
    {
        if(t[i] == s[j])
        {
            j++;
        }
        i++;
        if(s[j]=='\0')
        {
            j = 0;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
