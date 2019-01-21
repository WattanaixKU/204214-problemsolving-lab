#include <iostream>
using namespace std;
int main()
{
    string inp;
    cin >> inp;
    int i = 0, j = 0;
    while(inp[i]!='\0')
    {
        if(inp[i]!='_')
            j++;
        else
        {
            for(int k=0;k<j;k++)
            {
                cout << inp[i-k-1];
            }
            cout << '_';
            j = 0;
        }
        i++;
    }
    for(int k=0;k<j;k++)
    {
        cout << inp[i-k-1];
    }
    return 0;
}