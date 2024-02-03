Given an integer array arr, partition the array into (contiguous) subarrays of length at most k.
After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the
answer fits in a 32-bit integer.


Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length


//*****************CODE*********************//
class Solution {
public:
//Recursive and memoization solution
int solve(vector<int>&arr,int i,int k,vector<int>&dp){
    if(i>=arr.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int j=i;
    int maxnum=arr[i];
    int ans=0;
    for(int j=i;j<k+i;j++){
        if(j<arr.size()){
            maxnum= max(maxnum,arr[j]);
            ans=max(ans,solve(arr,j+1,k,dp)+ (j-i+1)*maxnum);
        }
    }
    return dp[i]=ans;
}

// using tabulation method
int solveTab(vector<int>&arr,int k){
    int n=arr.size();
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int j=i;
        int maxnum=arr[i];
        int ans=0;
        for(int j=i;j<k+i;j++){
            if(j<arr.size()){
                maxnum = max(maxnum,arr[j]);
                ans=max(ans,dp[j+1]+(j-i+1)*maxnum);
            }
        }
        dp[i]=ans;
    }
    return dp[0];
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        //using memoization
        // vector<int> dp(arr.size()+1,-1);
        // return solve(arr,0,k,dp);

        //using tabulation
        return solveTab(arr,k);
    }
};
