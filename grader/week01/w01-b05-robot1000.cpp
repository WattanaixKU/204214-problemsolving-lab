#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int i = 0, x = 0, y = 0;
    while(s[i]!='\0')
    {
        switch(s[i])
        {
            case 'N':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'S':
                y--;
                break;
            case 'W':
                x--;
                break;
            case 'Z':
                x = 0;
                y = 0;
                break;
        }
        i++;
    }
    cout << x << " " << y << endl;
    return 0;
}