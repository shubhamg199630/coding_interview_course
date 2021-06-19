#include<bits/stdc++.h>
using namespace std;
/*int main()
{
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    int *p[10]={a,a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,a+9};

    for (int i=0;i<10;i++)
    {
        *(p[i])=(10 *i);
    }
    for (int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }


}*/
/*
int main()
{ 	const int a = 5,b=10;
    const int *const ptr=&a;
    printf("%d\n", *ptr);               //5
    return 0;
}*/
int main()
{ 	const int a = 5,b=10;
    const int *ptr=&a;
    ptr=&b;         // accepted
    printf("%d\n", *ptr);
    return 0;
}

//int *const p=&a;          //
