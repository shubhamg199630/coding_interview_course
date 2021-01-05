//https://www.interviewbit.com/problems/longest-common-subsequence/
//
//
//
//Problem Description
//
//Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.
//
//You need to return the length of such longest common subsequence.
//
//
//
//Problem Constraints
//1 <= |A|, |B| <= 1005
//
//
//
//Input Format
//First argument is an string A.
//
//Second argument is an string B.
//
//
//
//Output Format
//Return the length of such longest common subsequence between string A and string B.
//
//
//
//Example Input
//Input 1:
//
// A = "abbcdgf"
// B = "bbadcgf"
//
//
//Example Output
//Output 1:
//
// 5
//
//
//Example Explanation
//Explanation 1:
//
// The longest common subsequence is "bbcgf", which has a length of 5

     
     





int lcs(string A, string B, int n1, int n2,vector <vector <int>> &dp)
{
    //cout<<n1<<n2<<endl;
    if (n1==0||n2==0)
        return 0;
    else if (dp[n1][n2]!=-1)
        return dp[n1][n2];
    else
    {
        if (A[n1-1]==B[n2-1])
            return dp[n1][n2]=lcs(A,B,n1-1, n2-1,dp)+1;
        else
            return dp[n1][n2]=max(lcs(A,B,n1-1, n2,dp),lcs(A,B,n1, n2-1,dp));
    }
}


int Solution::solve(string A, string B) {
    vector <vector <int>> dp(A.size()+1,vector <int> (B.size()+1,-1));
    return lcs(A,B,A.size(), B.size(),dp);
}
