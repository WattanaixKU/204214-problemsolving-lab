#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int k=0;k<t;k++)
    {
        int i = 0, j = 0;
        bool ans = 1;
        string inp;
        char stack[100];
        cin >> inp;
        while(inp[i]!='\0')
        {
            if(inp[i]=='{' || inp[i]=='[' || inp[i]=='(')
            {
                
                stack[j] = inp[i];
                j++;
            }
            else
            {
                if(j==0)
                {
                    ans = 0;
                    break;
                }
                switch(inp[i])
                {
                    case '}':
                        if(stack[j-1]=='{')
                            j--;
                        else
                            ans = 0;
                        break;
                    case ']':
                        if(stack[j-1]=='[')
                            j--;
                        else
                            ans = 0;
                        break;
                    case ')':
                        if(stack[j-1]=='(')
                            j--;
                        else
                            ans = 0;
                        break;
                }
            }
            //cout << stack << " " << inp[i] << ans << endl;
            i++;
        }
        if(j!=0 && ans == 1)
            ans = 0;
        if(ans)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}