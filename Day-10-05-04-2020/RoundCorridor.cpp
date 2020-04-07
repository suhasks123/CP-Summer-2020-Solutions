#include<bits/stdc++.h>

using namespace std;

string Move(long long n, long long m, long long sx, long long sy, long long ex, long long ey)
{
    if(n==m)
    {
        if(sy == ey)
            return "YES";
        else
            return "NO";
    }
    if(sx==1 && ex == 1)
    {
        if((sy <= n/2 && ey <= n/2) || (sy > n/2 && ey > n/2))
            return "YES";
        else
            return "NO";
    }

    else if(sx==1 && ex == 2)
    {
        if((sy <= n/2 && ey <= m/2) || (sy > n/2 && ey > m/2))
            return "YES";
        else
            return "NO";
    }

    else if(sx==2 && ex == 1)
    {
        if((sy <= m/2 && ey <= n/2) || (sy > m/2 && ey > n/2))
            return "YES";
        else
            return "NO";
    }

    else if(sx==2 && ex == 2)
    {
        if((sy <= m/2 && ey <= m/2) || (sy > m/2 && ey > m/2))
            return "YES";
        else
            return "NO";
    }


}


int main()
{
    int i;
    long long n, m, q, sx, sy, ex, ey;
    string ans;
    vector<string> arr;
    cin >> n >> m >> q;
    for(i=0;i<q;i++)
    {
        cin >> sx >> sy >> ex >> ey;
        ans = Move(n, m, sx, sy, ex, ey);
        arr.push_back(ans);
    }

    for(i=0;i<q;i++)
    {
        cout << arr[i] << "\n";
    }

}
