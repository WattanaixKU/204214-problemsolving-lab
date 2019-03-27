#include "traffic.h"
#include <iostream>
using namespace std;
pair<pair<int,int>,pair<int,int> > ans1;
pair<pair<int,int>,pair<int,int> > ans2;

void check(int line, int start, int stop, int n, bool ver)
{
    int mid,tmp;
    bool in;
    if(stop-start==1)
    {
        if(ver)
        {
            //cout << line << " " << start << " " << line << " " << stop << endl;
            if(ans1.first.first)
                ans2 = make_pair(make_pair(line,start),make_pair(line,stop));
            else
                ans1 = make_pair(make_pair(line,start),make_pair(line,stop));
        }
        else
        {
            //cout << start << " " << line << " " << stop << " " << line << endl;
            if(ans1.first.first)
                ans2 = make_pair(make_pair(start,line),make_pair(stop,line));
            else
                ans1 = make_pair(make_pair(start,line),make_pair(stop,line));
        }
    }
    else
    {
        mid = (stop+start)/2;
        if(ver)
            tmp = traffic_query(line,start,line,mid);
        else
            tmp = traffic_query(start,line,mid,line);
        //cout << start << " " << mid << " " << stop << " " << line << " tmp=" << tmp << " n=" << n << endl;
        in = false;
        if((tmp-(mid-start)) >= 1)
        {
            in = true;
            check(line,start,mid,tmp,ver);
        }
        else
            check(line,mid,stop,n-tmp,ver);
        if(((n-tmp)-(stop-mid)) >= 1 && in)
            check(line,mid,stop,n-tmp,ver);
    }
}
int main()
{
    int n,k,t;
    ans1 = make_pair(make_pair(0,0),make_pair(0,0));
    ans2 = make_pair(make_pair(0,0),make_pair(0,0));
    traffic_init(&n, &k);
    for(int i=1; i<=n && k; i++)
    {
        t = traffic_query(i,1,i,n);
        if(t!=(n-1))
        {
            check(i,1,n,t,true);
            k -= t-(n-1);
        }
    }
    for(int i=1; i<=n && k; i++)
    {
        t = traffic_query(1,i,n,i);
        if(t!=(n-1))
        {
            check(i,1,n,t,false);
            k -= t-(n-1);
        }
    }
    traffic_report( ans1.first.first,
                    ans1.first.second,
                    ans1.second.first,
                    ans1.second.second, 
                    ans2.first.first,
                    ans2.first.second,
                    ans2.second.first,
                    ans2.second.second);
    return 0;
}
