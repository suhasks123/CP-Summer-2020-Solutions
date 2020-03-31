#include<bits/stdc++.h>

using namespace std;


int countSubsequence(int n)
{
    int val;
    int ctr = 0;
    int i;
    //vector<int> arr;
    unordered_set<int> uniq;
    for(i=0;i<n;i++)
    {
        cin >> val;
        if(uniq.find(val) == uniq.end())
        {
            uniq.insert(val);
            ctr++;
        }
    }
    return ctr;

}


int main()
{
    int t, n, ans, i;
    vector<int> res;
    cin >> t;
    for(i=0;i<t;i++)
    {
        cin >> n;
        ans = countSubsequence(n);
        res.push_back(ans);
    }

    for(i=0;i<t;i++)
    {
        cout << res[i] << "\n";
    }

    return 0;

}
