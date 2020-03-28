#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    int i;
    vector<int> candy;
    for(i=0;i<n;i++)
    {
        candy.push_back(0);
    }
    if(arr[0]>arr[1])
    {
        candy[0]=2;
        candy[1]=1;
    }
    else if(arr[1]>arr[0])
    {
        candy[0]=1;
        candy[1]=2;
    }
    else if(arr[0]==arr[1])
    {
        candy[0]=1;
        candy[1]=1;
    }
    for(i=1;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            candy[i+1] = 1;
        }
        else if(arr[i]<arr[i+1])
        {
            candy[i+1] = candy[i] + 1;
        }
        else if(arr[i]==arr[i+1])
        {
            candy[i+1] = 1;
        }
    }

    for(i=n-1;i>0;i--)
    {
        /*if(arr[i]>arr[i-1] && candy[i]==candy[i-1])
        {
            candy[i-1] = 1;
        }*/
        if(arr[i]<arr[i-1] && candy[i]>=candy[i-1])
        {
            candy[i-1] = candy[i] + 1;
        }
        /*else if(arr[i]==arr[i-1])
        {
            candy[i+1] = 1;
        }*/
    }
    long sum=0;
    for(i=0;i<n;i++)
    {
        sum += candy[i];
    }
    return sum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
