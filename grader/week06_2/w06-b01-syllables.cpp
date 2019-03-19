#include <iostream>
using namespace std;
bool check(char c)
{
    if(c == 'a')
        return 1;
    if(c == 'e')
        return 1;
    if(c == 'i')
        return 1;
    if(c == 'o')
        return 1;
    if(c == 'u')
        return 1;
    return 0;
}
int main()
{
    int n, j, count;
    string s;
    bool st;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        j = 0;
        st = 0;
        count = 0;
        while(s[j]!='\0')
        {
            if(check(s[j]) && !st)
                count++;
            st = check(s[j]);
            j++;
        }
        cout << count << endl;
    }
    return 0;
}
