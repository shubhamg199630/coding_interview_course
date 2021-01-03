#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

struct node
{
    int v;
    int weight;
};
find_index_of_city(vector <string > &a, string s)
{
    for (int i=0; i<a.size(); i++)
    {
        if (a[i]==s)
            return i;
    }
}
node create_node(int des, int w)                    // function to create new node
{
    node temp;
    temp.v=des;
    temp.weight=w;
    return temp;
}

void addedge(vector <vector <node>> &graph, int src, int dest, int w)               // adding node to adj list.
{
    //cout<<"adsa";
    node temp=create_node(dest,w);
    //cout<<"sasa";
    graph[src].push_back(temp);
    temp=create_node(src,w);
    graph[dest].push_back(temp);
}
vector <int> dijkstra(vector <vector <node>> &g,int s)
{
    int n=g.size();
    vector <bool> vis (n,false);
    vector <int> set_min(n, INT_MAX);           // putting infinty intially
    set_min[s]=0; vis[s]=true;
    multimap < int , int> heap ;       // min heap using map will give log n every case
    //cout<<n<<endl;
    for (int i=0;i<n;i++)
    {
        heap.insert({set_min[i],i});
    }
    int c=1;
    while (c<n)
    {
        c++;
        auto itr=heap.begin() ;          // find min in hheap
        int d=(itr->second);
        vis[d]=true;
        //cout<<d;
        set_min[d]=itr->first;
        heap.erase(itr);
        //cout<<"q";            // removing that element from heap;
        for (int i=0;i<g[d].size();i++)         // loop for relaxing of edge
        {
            int des=g[d][i].v;
            if (vis[des]==false)
            {
                if ((set_min[d]+g[d][i].weight)<set_min[des])
                {
                    //cout<<des;;
;                  //relaxing the edge in set_min and also in heap
                    auto itr_new=heap.find(set_min[des]);
                   // cout<<"a";
                    //cout<<itr_new->second;
                    while (itr_new->second!=des)
                        itr_new++;
                   // cout<<"r";
                    heap.erase(itr_new);
                    set_min[des]=set_min[d]+g[d][i].weight;
                    heap.insert({set_min[des],des});
                }
            }
        }
        /*for (auto jtr=heap.begin();jtr!=heap.end();jtr++)
        {
            cout<<jtr->first<<" "<<jtr->second<<endl;
        }
        cout<<c<<endl;*/
    }
    return set_min;
}

int main()
{
    ifstream input;
    input.open("testcase/input/8_random_1.ip");          //input file name
    ofstream output;
    output.open("testcase/output/8_random_1.exp");         //outputfile name
    int n;
    vector <string> city_names;
    char ch;

    input>>ch>>n;
    for (int i=0; i<n; i++)
    {
        string s;
        input>>s;
        city_names.push_back(s);                    // adding city names to vector
    }
    vector <vector <node>> graph(n,vector <node> (0));  // creating graph of  n vector and each having size zero.

    input>>ch>>n;
    for (int i=0; i<n; i++)
    {
        //cout<<"ASA";
        string s1,s2;
        int w;
        input>>s1>>s2>>w;
        int src= find_index_of_city(city_names,s1);
        int des= find_index_of_city(city_names,s2);
        addedge(graph, src, des,w);
    }
    while (1)
    {
        string s1, s2;
        input>>ch;
        if (ch=='s')
            break;
        input>>s1>>s2;
        int src= find_index_of_city(city_names,s1);
        int des= find_index_of_city(city_names,s2);
        vector <int> ans=dijkstra(graph,src);
        output<<ans[des]<<endl;
    }
}
