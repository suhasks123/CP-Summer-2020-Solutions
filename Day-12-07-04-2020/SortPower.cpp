

class Solution {

int getPower(int n)
    {
        int ctr = 0;
        int num  = n;
        while(num!=1)
        {
            if(num%2==0)
                num/=2;
            else if(num%2!=0)
                num = (3*num)+1;
            ctr++;
        }
        return ctr;
    }
public:
    bool comp(int a, int b)
    {
        if(getPower(a) != getPower(b))
            return getPower(a) < getPower(b);
        else
            return a<b;
    }
public:
    int getKth(int lo, int hi, int k) {

        int i;
        vector<int> arr;
        for(i=lo;i<=hi; i++)
            arr.push_back(i);
        //Compare c;
        sort(arr.begin(), arr.end(), [this] (int a, int b) {
            return comp(a, b); });
        return arr[k-1];
    }
};
