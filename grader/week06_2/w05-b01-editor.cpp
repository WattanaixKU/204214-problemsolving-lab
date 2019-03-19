#include <iostream>
using namespace std;
int p = 0,j;
string ans,s;
void move_l()
{
    if(p!=1)
    {
        p--;
        while(ans[p-1]!=' ')
            p--;
    }
}

void move_r()
{
    if(ans[p]!='\0')
    {
        p++;
        while(ans[p]!=' ')
            p++;
        p++;
    }
}

void store_s()
{
    for(int k=p;ans[k]!='\0';k++)
    {
        s[j] = ans[k];
        j++;
    }
    s[j] = '\0';
}

void load_s()
{
    int t = p;
    while(s[j]!='\0')
    {
        ans[p] = s[j];
        p++;
        j++;
    }
    ans[p] = '\0';
    p = t;
}

int main()
{
    char cmd;
    int n;
    cin >> n;
    ans[0] = ' ';
    ans[1] = '\0';
    p = 1;
    for(int i=0;i<n;i++)
    {
        cin >> cmd;
        switch(cmd)
        {
            case 'i':
                cin >> s;
                j = 0;
                while(s[j]!='\0')
                    j++;
                s[j++] = ' ';
                store_s();
                j = 0;
                load_s();
                move_r();
                //ans[0] = '-';
                break;
            case 'r':
                move_r();
                break;
            case 'l':
                move_l();
                break;
            case 'b':
                j = 0;
                store_s();
                move_l();
                j = 0;
                load_s();
                break;
            case 'd':
                if(ans[p]!='\0')
                {
                    move_r();
                    j = 0;
                    store_s();
                    move_l();
                    j = 0;
                    load_s();
                }
        }
    }
    for(int i=1;ans[i]!='\0';i++)
        cout << ans[i];
    return 0;
}
