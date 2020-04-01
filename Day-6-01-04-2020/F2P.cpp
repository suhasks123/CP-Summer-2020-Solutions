#include<bits/stdc++.h>

using namespace std;


int calculateCrystals(int h, int n)
{
    vector<int> arr;
    int i;
    int temp;
    for(i=0;i<h;i++)
    {
        arr.push_back(0);
    }
    for(i=0;i<n;i++)
    {
        cin >> temp;
        arr[temp-1] = 1;
    }
    int crystals = 0;
    for(i=h-1;i>=0;)
    {
        if(i==0 || i==1)
        {
            break;
        }
        if(arr[i-1]==0 || arr[i-2]==1)
        {
            arr[i] = 0;
            if(arr[i-1] == 0)
            {
                arr[i-1] = 1;
                i--;
                continue;
            }
            else if(arr[i-1] == 1)
            {
                arr[i-1] = 0;
                i -= 2;
                continue;
            }
        }
        else
        {
            crystals++;
            arr[i] = 0;
            arr[i-1] = 0;
            arr[i-2] = 1;
            i -= 2;
            continue;
        }
    }

    return crystals;
}


int main()
{
    int t, h, n;
    cin >> t;
    vector<int> f;
    int k, i, temp;
    for(k=0;k<t;k++)
    {
        cin >> h >> n;
        //vector<int> heights, arr;
        /*for(i=0;i<n;i++)
        {
            cin>> temp;
            heights.push_back(temp);
        }*/
        int crystals = calculateCrystals(h, n);
        f.push_back(crystals);
    }

    for(k=0;k<t;k++)
        cout << f[k] << "\n";

    return 0;

}
