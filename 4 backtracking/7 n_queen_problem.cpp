//  https://www.interviewbit.com/problems/nqueens/




//The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//N Queens: Example 1
//
//Given an integer n, return all distinct solutions to the n-queens puzzle.
//
//Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//For example,
//There exist two distinct solutions to the 4-queens puzzle:
//
//[
// [".Q..",  // Solution 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // Solution 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]




//solution
//Note the in n queen these three thinks cannot be same.
//1) row cannot be same (as we are changing row always so donot need to check also)
//2) col cannot be same 
//3) diagonal cannot be same 
//                diagonal are two types
//                    1) sum equal 
//                    2) diff equal
                    
                    
                    
                    
    
    
#define pb push_back
int check(vector <string> temp, int row, int col)       // checking row , col is correct or not
{                                                       // return 1 if correct
    int n=temp.size();
    for (int i=0;i<row;i++)         // checking in each row for given col contaning Q
        if (temp[i][col]=='Q')      
            return 0;                   // do not required for each col as each row is always changing 
    for (int i=row-1, j =col+1; i>=0&&j<=n-1;i--,j++)         // for sum digonal
    {
        if (temp[i][j]=='Q')
            return 0;
    }
     for (int i=row-1, j =col-1; i>=0&&j>=0;i--,j--)         // for diff digonal
    {
        if (temp[i][j]=='Q')
            return 0;
    }
    return 1;
}
void nqueue(int row,vector <string> temp,vector <vector <string>> &ans)
{
    int n=temp.size();
    if (row==temp.size())
        ans.pb(temp);
    else
    {
        for (int j=0;j<n;j++)       // col number
        {
            if (check(temp,row,j))// fucntion at check whether row,j is correct postion for nqueue
            {
                temp[row][j]='Q';           // posstion correct so putting Q
                nqueue(row+1,temp,ans);     // call
                temp[row][j]='.';           // reverting the postion back to .
            }
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    string s;
    for (int i=0;i<A;i++)
        s.pb('.');          // string containing only .
    vector <string> temp(A,s);          //vector of string containing .
    vector <vector <string>> ans;
    nqueue(0,temp,ans);         // queue function is called with ans empty
    return ans;
}

                    


