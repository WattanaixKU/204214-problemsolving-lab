#include <iostream>
using namespace std;
int main()
{
    string inp;
    cin >> inp;
    int i = 0;
    while(inp[i]!='\0')
    {
        cout << (char)((inp[i]-93)%26+97);
        i++;
    }
    return 0;
}
