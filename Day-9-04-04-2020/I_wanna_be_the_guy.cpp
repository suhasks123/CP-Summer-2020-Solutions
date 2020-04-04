#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, i, temp;
    cin >> n;
    cin >> a;
    unordered_set<int> x, y;
    for(i=0;i<a;i++)
    {
        cin >> temp;
        x.insert(temp);
    }
    cin >> b;
    for(i=0;i<b;i++)
    {
        cin >> temp;
        y.insert(temp);
    }

    if(a+b<n)
    {
        cout << "Oh, my keyboard!";
        return 0;
    }

    for(i=1;i<=n;i++)
    {
        if(!(x.count(i)>0 || y.count(i)>0))
        {
           cout << "Oh, my keyboard!";
           return 0;
        }
    }
    cout << "I become the guy.";
    return 0;



}
