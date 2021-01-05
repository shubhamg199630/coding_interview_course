//  https://www.interviewbit.com/problems/edit-distance/

//Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)
//
//You have the following 3 operations permitted on a word:
//
//Insert a character
//Delete a character
//Replace a character
//
//
//Input Format:
//
//The first argument of input contains a string, A.
//The second argument of input contains a string, B.
//Output Format:
//
//Return an integer, representing the minimum number of steps required.
//Constraints:
//
//1 <= length(A), length(B) <= 450
//Examples:
//
//Input 1:
//    A = "abad"
//    B = "abac"
//
//Output 1:
//    1
//
//Explanation 1:
//    Operation 1: Replace d with c.
//
//Input 2:
//    A = "Anshuman"
//    B = "Antihuman"
//
//Output 2:
//    2
//
//Explanation 2:
//    => Operation 1: Replace s with t.
//    => Operation 2: Insert i.
        
// memorization



int editdis(string A, string B, int m ,int n,vector <vector <int>> &dp)
{
    //cout<<m<<n<<endl;
    if (m==0)
        return n;
    else if(n==0)
        return m;
    else if (dp[m][n]!=-1)
        return dp[m][n];
    else 
    {
        if (A[m-1]==B[n-1])
            dp[m][n]=editdis(A,B,m-1,n-1,dp);
        else 
        {
            int x=min(editdis(A,B,m,n-1,dp),editdis(A,B,m-1,n,dp));
            dp[m][n]=min(x,editdis(A,B,m-1,n-1,dp))+1;
        }
        return dp[m][n];
    }
}
int Solution::minDistance(string A, string B) {
    int m=A.size();
    int n=B.size();
    vector <vector <int>> dp(m+1, vector <int> (n+1,-1));
    return editdis(A,B,m,n,dp);
}




// Tabular form

int lcs(string A,string B,int n1,int n2,vector<vector <int>> &dp)
{
    dp[0][0]=0;
    for (int i=1;i<=n1;i++)
        dp[i][0]=i;
    for (int i=1;i<=n2;i++)
        dp[0][i]=i;
    for (int i=1;i<=n1;i++)
    {
        for (int j=1;j<=n2;j++)
        {
            if (A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1];
            else 
                dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
        }
    }
    return dp[n1][n2];
}


int Solution::minDistance(string A, string B) {
    vector <vector <int>> dp(A.size()+1,vector <int> (B.size()+1,-1));
    return lcs(A,B,A.size(),B.size(),dp);
    
}

