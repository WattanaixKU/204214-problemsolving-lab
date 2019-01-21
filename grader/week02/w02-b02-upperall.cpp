#include <iostream>
using namespace std;
int main()
{
    int i = 0;
    string inp;
    cin >> inp;
    while(inp[i]!='\0')
    {
        if(inp[i]>='a' && inp[i]<='z')
            cout << (char)(inp[i]-32);
        else
            cout << inp[i];
        i++;
    }
    return 0;
}