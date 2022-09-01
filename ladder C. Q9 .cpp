/*                                                             C. Valera and Tubes 

Valera has got a rectangle table consisting of n rows and m columns. Valera numbered the table rows starting from one, from top to bottom and the columns – starting from one, from left to right. We will represent cell that is on the intersection of row x and column y by a pair of integers (x, y).

Valera wants to place exactly k tubes on his rectangle table. A tube is such sequence of table cells (x1, y1), (x2, y2), ..., (xr, yr), that:

    r ≥ 2;
    for any integer i (1 ≤ i ≤ r - 1) the following equation |xi - xi + 1| + |yi - yi + 1| = 1 holds;
    each table cell, which belongs to the tube, must occur exactly once in the sequence. 

Valera thinks that the tubes are arranged in a fancy manner if the following conditions are fulfilled:

    no pair of tubes has common cells;
    each cell of the table belongs to some tube. 

Help Valera to arrange k tubes on his rectangle table in a fancy manner.

INPUT
The first line contains three space-separated integers n, m, k (2 ≤ n, m ≤ 300; 2 ≤ 2k ≤ n·m) — the number of rows, the number of columns and the number of tubes, correspondingly.

OUTPUT
Print k lines. In the i-th line print the description of the i-th tube: first print integer ri (the number of tube cells), then print 2ri integers xi1, yi1, xi2, yi2, ..., xiri, yiri (the sequence of table cells).
If there are multiple solutions, you can print any of them. It is guaranteed that at least one solution exists. 



I/P - 3 3 3
O/P - 3 1 1 1 2 1 3
      3 2 1 2 2 2 3
      3 3 1 3 2 3 3
*/


#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define int int64_t
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,k;cin>>n>>m>>k;
    bool flag=true;
    vector<pair<int,int> > ans;
    for(int i=1;i<=n;i++)
    {
        if(flag)
        {
            for(int j=1;j<=m;j++)
            {
                ans.push_back(make_pair(i,j));
            }
            flag=false;
        }
        else
        {
            flag=true;
            for(int j=m;j>0;j--)
            {
                ans.push_back(make_pair(i,j));
            }
        }
    }
    int pos=0,toko=k;
    for(int i=0;i<ans.size();i+=2)
    {
        pos=i;
        if(k==1)
            break;
        cout<<2<<" "<<ans[i].first<<" "<<ans[i].second<<" "<<ans[i+1].first<<" "<<ans[i+1].second<<"\n";
        k--;
    }
    cout<<ans.size()-(toko-1)*2<<" ";
    for(int i=pos;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<" ";
    cout<<"\n";
    return 0;
}
