// Problem: https://www.interviewbit.com/problems/gas-station/
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int start = 0, end = 0;
    int current_fuel = 0;
    int flag = 0;
    int n = size(A);
    while (true) {
        if (start == 0) {
            if (flag == 1) {
                return -1;
            }
            flag = 1;
        }
        current_fuel += A[end];
        if (current_fuel >= B[end]) {
            current_fuel -= B[end];
            (++end) % n;
            if (end == start) {
                return start;
            }
        }
        // If we hit a barrier in the road where the fuel is less than required
        else if (current_fuel < B[end]) {
            // If the fuel obtained at start is more than the fuel consumed when going
            // from start to start + 1
            if (A[start] >= B[start]) {
                (++end) % n;
                start = end;
                current_fuel = 0;
            }
            else if (A[start] < B[start]) {
                current_fuel -= A[start];
                current_fuel += B[start];
                (++start) % n;
            }
        }
    }
    
}
