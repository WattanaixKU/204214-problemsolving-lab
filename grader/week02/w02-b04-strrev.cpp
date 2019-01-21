#include <iostream>
using namespace std;
int main()
{
    string inp;
    cin >> inp;
    int i = 0;
    while(inp[i]!='\0')
        i++;
    for(int j=i-1;j>=0;j--)
        cout << inp[j];
    return 0;
}
