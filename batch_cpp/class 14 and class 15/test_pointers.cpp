#include <iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,6,7};
    int *b[]={a+1,a+4,a+6,a+2};
    int **c=b+2;
    cout<<*(*(c+1)+1);
}
