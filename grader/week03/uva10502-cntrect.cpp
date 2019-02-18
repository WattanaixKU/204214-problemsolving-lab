#include <iostream>
using namespace std;
typedef pair<int,int> poi; //Pair of int
char tbl[100][100];
int count(poi tbl_size, poi sq_size)
{
    ios::sync_with_stdio(false);
    int c = 0;
    for(int i=0;i<=tbl_size.first-sq_size.first;i++)
    {
        for(int j=0;j<=tbl_size.second-sq_size.second;j++)
        {
            bool pass = true;
            for(int si=i;si<i+sq_size.first;si++)
            {
                for(int sj=j;sj<j+sq_size.second;sj++)
                {
                    if(tbl[si][sj]=='0')
                    {
                        sj = 100;
                        si = 100;
                        pass = false;
                    }
                }
            }
            if(pass)
                c++;
        }
    }
    return c;
}
int main()
{
    poi tbl_size,sq_size;
    cin >> tbl_size.first;
    int c;
    while(tbl_size.first!=0)
    {
        c = 0;
        cin >> tbl_size.second;
        for(int i=0;i<tbl_size.first;i++)
            for(int j=0;j<tbl_size.second;j++)
                cin >> tbl[i][j];
                
        for(int i=1;i<=tbl_size.first;i++)
        {
            for(int j=1;j<=tbl_size.second;j++)
            {
                //cout << i << " " << j << " " << endl;
                c += count(tbl_size, make_pair(i,j));
            }
        }
        cout << c << endl;
        cin >> tbl_size.first;
    }
}