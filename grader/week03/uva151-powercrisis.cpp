#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t,n,count,ord;
    bool pass = 1;
    cin >> n;
    while(n!=0)
    {
        if(n==13)
        {
            cout << 1 << endl;
            cin >> n;
            continue;
        }
        count = 1;
        vector<int> tl;
        for(int i=1;i<=n;i++)
            tl.push_back(i);
        while(true)
        {
            ord = 0;
            vector<int> l(tl);
            pass = 1;
            for(int i=1;i<n;i++)
            {
                ord = ord%(n-i+1);
                //cout << " " << l[ord];
                //cin >> t;;
                if(l[ord]==13)
                {
                    pass = 0;
                    i = n;
                }
                l.erase(l.begin()+ord);
                ord += count;
            }
            //cout << endl;
            count += 1;
            if(pass)
                break;
            //cout << count << endl;
        }
        cout << count << endl;
        cin >> n;
    }
}