/* This code is working on Leet code but interview error is coming*/
//https://leetcode.com/problems/search-a-2d-matrix/submissions/


int temp=0;
int BSrow(vector <vector <int>> &A, int x, int start,int endd)
{
  //  cout<<"ada";
    if (start>endd)
        return temp;
    else 
    {
        int mid=start+(endd-start)/2;
        if (A[mid][0]==x)
            return mid;
        else if (A[mid][0]<x)
        {
            temp=mid;
            return BSrow(A,x,mid+1,endd);
        }
        else
        {
            return BSrow(A,x,start,mid-1);
        }
    }
    
}
int BScol(vector <int> A,int x, int start,int endd)
{
   // cout<<"SAdasdas";
    if (start>endd)
        return 0;
    else
    {
        int mid=start+(endd-start)/2;
        if (A[mid]==x)
            return 1;
        else if (A[mid]>x)
            return BScol(A,x,start,mid-1);
        else
            return BScol(A,x, mid+1, endd);
    }
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int res=BSrow(A,B,0,A.size()-1);
        return BScol(A[res],B,0,A[0].size()-1);
}
