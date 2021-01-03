//  https://www.interviewbit.com/problems/combination-sum-ii/



//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
// Note:
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//Example :
//
//Given candidate set 10,1,2,7,6,1,5 and target 8,
//
//A solution set is:
//
//[1, 7]
//[1, 2, 5]
//[2, 6]
//[1, 1, 6]


// Logic is same as knapsack but for duplicate entry we have created a match function which will check the given vector is present in ans vector before adding



bool match(vector <vector<int>> &ans, vector <int> temp)
{
    for (int i=0;i<ans.size();i++)
    {
        if (temp==ans[i])
            return 1;
    }
    return 0;
}


void combination(vector <int > &A, int curr,
    vector <vector<int>> &ans,vector <int > &temp, int val)
{
    if (val==0)
    {
        if (!match(ans,temp))
            ans.push_back(temp);
    }
    else if (curr>=A.size())
        return ;
    else
    {
        if(val>=A[curr])
        {
            vector< int > temp1(temp);
            temp1.push_back(A[curr]);
            combination(A, curr+1,ans, temp1,val-A[curr]);
        }
        combination(A,curr+1,ans, temp, val);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector <vector<int>>ans;
    vector <int > temp;
    sort(A.begin(),A.end());
    combination (A, 0, ans, temp,B);
    return ans;
}
