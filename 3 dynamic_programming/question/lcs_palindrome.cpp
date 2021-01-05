//  https://www.interviewbit.com/problems/longest-palindromic-subsequence/

//Problem Description
//
//Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.
//
//You need to return the length of longest palindromic subsequence in A.
//
//NOTE:
//
//Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.
//
//
//Problem Constraints
//1 <= |A| <= 1005
//
//
//
//Input Format
//First and only argument is an string A.
//
//
//
//Output Format
//Return a integer denoting the length of longest palindromic subsequence in A.
//
//
//
//Example Input
//Input 1:
//
// A = "bebeeed"
//
//
//Example Output
//Output 1:
//
// 4
//
//
//Example Explanation
//Explanation 1:
//
// The longest common pallindromic subsequence is "eeee", which has a length of 4

     
//very easy just reverse the string and apply the lcs program
//No that the memorization is giving tle so tabular appraoch is using here
int lcs(string s, string t, int m,int n,vector <vector <int>> &dp)
{
    dp[0][0]=0;
    for (int i=0;i<=m;i++)
        dp[i][0]=0,dp[0][i]=0;
    
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (s[i-1]==t[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else 
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
}

int Solution::solve(string A) {
    string B=A ;            //copying  string B to A         
    reverse(B.begin(),B.end());     // reverse B 
    vector <vector <int>> dp(A.size()+1,vector <int> (B.size()+1,-1));
    return lcs(A,B,A.size(), B.size(),dp);
}
