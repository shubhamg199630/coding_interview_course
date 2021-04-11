int ans=-1;
int binarysearch(int *a, int low, int high)
{
    if (low>high)
        return ans;
    else 
    {
        int mid=(low+high)/2;
        if (a[mid]<0)       //left 
        {    
            ans=mid;
            return binarysearch(a,low, mid-1);
        }
        else 
            return binarysearch(a,mid+1,high);    
    }
}
int countNegatives(int** grid, int gridSize, int* gridColSize){
    // for each row apply binary;
        int r=gridSize;      // row size
        int c=*gridColSize;
        //printf("%d",c);
        int count=0;
        for (int i=0;i<r;i++)
        {
            ans=c;
            int p=binarysearch(grid[i],0,c-1);
            count=count+c-p;
        }
        return count;
}