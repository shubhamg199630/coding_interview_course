#define ll long long 
ll ans=0;
ll binary_search1(ll low, ll high, ll n)
{
    if (low>high)           // stopping condition
        return ans;
    else 
    {
        ll mid=(low+high)/2;
        if (mid*mid<=n)         // right side condition
        {
            ans=mid;
            return binary_search1(mid+1,high, n);
        }
        else 
            return binary_search1(low, mid-1,n);
    }
}
class Solution {
    
public:
    int mySqrt(int x) {
        ans=0;
        return binary_search1(1,x,x);
        
    }
};