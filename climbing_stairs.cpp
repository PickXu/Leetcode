class Solution {
    public:
        int climbStairs(int n) {
            int* sol = new int [n];
            int i;
            sol[0] = 1;
            sol[1] = 2;
            for (i=2;i<n;i++){
                sol[i] = sol[i-1]+sol[i-2];
            }
            return sol[n-1];
        }
};
