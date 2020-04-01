#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, h, ctr, temp;
    int t;
    vector<int> arr;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> temp;
        arr.push_back(temp);
        //m.insert(pair<int, int>(i+1, t));
    }
    //cout << "Hello";
    vector<int> level;
    for(i=0;i<n;i++)
    {
        h=0;
        ctr = arr[i];
        while(ctr!=-1)
        {
            //cout << "Hello";
            ctr = arr[ctr-1];
            h++;
        }
        level.push_back(h);
        //cout << h << " ";
    }
    sort(level.begin(), level.end());
    int count = unique(level.begin(), level.end()) - level.begin();
    /*int count;
    count = distance(level.begin(), unique(level.begin(), level.end()));*/
    cout << count;
    return 0;

}
