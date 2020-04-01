#include<bits/stdc++.h>

using namespace std;


int calculateCrystals(int h, int n)
{
    unordered_set<int> arr;
    int i;
    int temp;
    /*for(i=0;i<h;i++)
    {
        arr.push_back(0);
    }*/
    /*if(h==9)
    {
        cout << "HELLOOOOOO\n";
    }*/
    for(i=0;i<n;i++)
    {
        cin >> temp;
        arr.insert(temp);
    }
    int crystals = 0;
    for(i=h;i>=0;)
    {
        //cout << i << "  ";
        if(i==1 || i==2 || i==0)
        {
            break;
        }
        if(arr.count(i-1)==0 || arr.count(i-2)!=0)
        {
            arr.erase(i);
            if(arr.count(i-1) == 0)
            {
                arr.insert(i-1);
                i--;
                continue;
            }
            else if(arr.count(i-1) != 0)
            {
                arr.erase(i-1);
                i -= 2;
                continue;
            }
        }
        else
        {
            crystals++;
            arr.erase(i);
            arr.erase(i-1);
            arr.insert(i-2);
            i -= 2;
            continue;
        }
    }
    //cout <<"\n";

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
