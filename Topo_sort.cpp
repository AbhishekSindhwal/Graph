#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[],int u,int v){
    graph[u].push_back(v);
    //graph[v].push_back(u);
}
void printGraph(vector<int>graph[],int noOfVertices){
    for(int i=1;i<=noOfVertices;i++)
    {
        for(auto j:graph[i])
        {
           cout<<j<<" ";
        }
        cout<<endl;
    }
}
void topo_sort(vector<int>g[],vector<int>&vis,int node,stack<int>&stk)
{
    vis[node]=1;
    for(auto j:g[node])
    {
        if(vis[j]!=1)
        {
            topo_sort(g,vis,j,stk);
        }
    }
    stk.push(node);
}
int main(){
    int noOfEdge,noOfVertices;
    cout<<"Enter no. of edges and vertices: ";
    cin>>noOfEdge>>noOfVertices;
    vector<int> graph[noOfVertices+1];
    int u,v;
    for(int i=0;i<noOfEdge;i++)
    {
        cout<<"Enter the  edge: ";
        cin>>u>>v;
        addEdge(graph,u,v);
    }
    printGraph(graph,noOfVertices);
    vector<int>vis(noOfVertices+1,0);
    stack<int>stk;
    for(int i=0;i<noOfEdge;i++)
    {
        if(vis[i]!=1)
        {
            topo_sort(graph,vis,i,stk);
        }
    }
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}