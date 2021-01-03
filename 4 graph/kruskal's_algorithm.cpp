#include<bits/stdc++.h>
using namespace std;

struct edge {          // defining edge with weight and source and distination
    int src;
    int dst;
    int wt;
};

struct node{            // creating node for
    int parent;
    int rank;
};
int find(vector <node> & a, int v)
{
    //cout<<"Sdsa"<<v<<" "<<a[v].parent<<endl;
    if (a[v].parent ==-1)
        return v;
    return a[v].parent =find(a,a[v].parent);   // path compression
}
void union_(vector <node> & a, int s, int d)   // making union of two set
{
    int p1=find(a,s);   // parent of source
    int p2=find(a,d);   // parent of destination

    if (a[p1].rank>a[p2].rank)  // p1 has higher rank;
    {
        a[p2].parent=p1;       // so parent of p2 is not changed to p1
        a[p1].rank +=1;
    }
    else                      //  p2 has higher rank;
    {
        a[p1].parent=p2;      //  so parent of p1 is p2;
        a[p2].rank +=1;
    }
}
bool comparator(edge s, edge d)
{
    return s.wt<d.wt;
}
void kruskals (vector <edge> &edge_list, vector <node> &a, int v,
                            int e, vector <edge> &mst)
{
    //we need to sort edge by weight
    sort(edge_list.begin(),edge_list.end(), comparator);
    int count =0,i=0;   // number of edge in mst =0 currently
    while ((count<v-1)&&i<e)
    {
        //cout<<edge_list[i].src<<" asa "<<edge_list[i].dst<<endl;
        int p1=find(a,edge_list[i].src);// selecting first vectex parent
        int p2=find(a,edge_list[i].dst); // selecting second vectex parent
        //cout<<p1<<" "<<p2<<" "<<endl;;
        if (p1==p2)    // cycle detect both belongs to same set
        {
            i++;
            continue;
        }
        else
        {
            count++ ;          //increasing the count
            union_(a,p1,p2);     // union of p1 and p2 into single set.
            mst.push_back(edge_list[i]);
            i++;
        }

    }

}
void print_mst(vector <edge> &mst)
{
    cout<<"=======edges_in_mst"<<endl;
    int sum=0;
    for (int i=0;i<mst.size();i++)
    {
        cout<<mst[i].src<<" "<<mst[i].dst<<" "<<mst[i].wt<<endl;
        sum+=mst[i].wt;
    }
    cout<<"cost_of_mst= "<<sum<<endl;
}
int main()
{
    int v,e;     // 0 to v-1
    cin>>v>>e;  // vertex and edge
    vector <node> a(v);

    for (int i=0;i<v;i++)    // marking all parent with -1 and rank =0;
    {
        a[i].parent=-1;
        a[i].rank=0;
    }
    vector <edge> edge_list;   // edge list
    for (int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        edge temp;
        temp.src=s;
        temp.dst=d;
        temp.wt=w;
        edge_list.push_back(temp);
    }
    vector <edge> mst;
    kruskals(edge_list,a,v, e,mst);
    print_mst(mst);
}
