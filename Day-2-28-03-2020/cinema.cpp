#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int num;
    vector<int> q;
    cin >> n;
    do
    {
        cin >> num;
        q.push_back(num);
    } while(q.size()<n);

    vector<int> money;
    money.push_back(0);
    money.push_back(0);
    money.push_back(0);
    for(vector<int>::iterator it=q.begin();it!=q.end();++it)
    {
        if(*it==25)
        {
            money[0]++;
            continue;
        }
        if(*it==50)
        {
            if(money[0]>0)
            {
                money[0]--;
                money[1]++;
                continue;
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
        if(*it==100)
        {
            if(money[1]>0 && money[0]>0)
            {
                money[1]--;
                money[0]--;
                money[2]++;
                continue;
            }
            else if(money[1]<1 && money[0]>2)
            {
                money[0] -= 3;
                money[2]++;
                continue;
            }
            else
            {
                cout<< "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
