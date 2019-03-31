#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > vvi;
int main()
{
    int n,m,k,s,f;
    vector<int>::iterator itf,its;
    cin >> n >> m >> k;
    vector<int> t;
    t.push_back(0);
    for(int i=0;i<n;i++)
    {
        t[0] = i;
        vvi.push_back(t);
    }
    for(int i=0;i<m;i++)
    {
        cin >> s >> f;
        s--;
        f--;
        t.clear();
        itf = vvi[f].begin();
        its = vvi[s].begin();
        while(itf!=vvi[f].end() || its!=vvi[s].end())
        {
            if(itf == vvi[f].end())
            {
                if(t.back()!=*its)
                    t.push_back(*its);
                its++;
                continue;
            }
            if(its == vvi[s].end())
            {
                if(t.back()!=*itf)
                    t.push_back(*itf);
                itf++;
                continue;
            }
            if(*its <= *itf)
            {
                if(t.back()!=*its)
                    t.push_back(*its);
                its++;
            }
            else
            {
                if(t.back()!=*itf)
                    t.push_back(*itf);
                itf++;
            }
        }
        vvi[s] = t;
        vvi[f] = t;
    }
    bool find;
    for(int i=0;i<k;i++)
    {
        cin >> s >> f;
        s--;
        f--;
        find = 0;
        for(int j=0;j<vvi[s].size() && !find;j++)
        {
            cout << vvi[s][j] << " ";
            if(vvi[s][j] == f)
            {
                cout << 1 << endl;
                find = 1;
            }
        }
        if(!find)
            cout << 0 << endl;
    }
    
    return 0;
}