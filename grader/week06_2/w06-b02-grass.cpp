#include <iostream>
using namespace std;
int main()
{
    int n, m, line;
    cin >> n >> m;
    char tbl[n][n];
    char cmd;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> tbl[i][j];
    for(int c=0;c<m;c++)
    {
        cin >> cmd >> line;
        line--;
        //cout << cmd << line << endl;
        switch(cmd)
        {
            case 'L':
                for(int i=0;i<n;i++)
                {
                    if(tbl[line][i]=='x')
                        tbl[line][i] = '.';
                    else
                        i = n;
                }
                break;
            case 'R':
                for(int i=n-1;i>=0;i--)
                {
                    if(tbl[line][i]=='x')
                        tbl[line][i] = '.';
                    else
                        i = -1;
                }
                break;
            case 'U':
                for(int i=0;i<n;i++)
                {
                    if(tbl[i][line]=='x')
                        tbl[i][line] = '.';
                    else
                        i = n;
                }
                break;
            case 'D':
                for(int i=n-1;i>=0;i--)
                {
                    if(tbl[i][line]=='x')
                        tbl[i][line] = '.';
                    else
                        i = -1;
                }
                break;
            case 'A':
                for(int i=0;i<n;i++)
                    if(tbl[line][i]=='.')
                        tbl[line][i] = 'x';
                break;
            case 'B':
                for(int i=0;i<n;i++)
                    if(tbl[i][line]=='.')
                        tbl[i][line] = 'x';
                break;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << tbl[i][j];
        }
        cout << endl;
    }
    return 0;
}
