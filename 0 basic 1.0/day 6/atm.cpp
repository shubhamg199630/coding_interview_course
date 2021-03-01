# include <bits/stdc++.h>

using namespace std;
float a_t_m(int x, float y)
{
    if (x%5 == 0 && x+0.50<=y)
        return y-x-0.50;
    else
        return y;

}

int main()
{
    int x;
    float y;
    cin>>x>>y;
    cout<<fixed;
    cout<<setprecision(2)<<a_t_m(x,y);
    //printf("%.6f", a_t_m(x,y));
}
