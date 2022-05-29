#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[],int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void printGraph(vector<int>graph[],int noOfVertices){
    cout<<endl;
    for(int i=1;i<=noOfVertices;i++)
    {
        for(auto j:graph[i])
        {
           cout<<j<<" ";
        }
        cout<<endl;
    }
}
void dfsTraversal(vector<int>g[],vector<int> &vis,int i){
    cout<<i<<" ";
    vis[i]=1;
    for(auto j:g[i]){
        if(vis[j]!=1){
            dfsTraversal(g,vis,j);
        }
    }
}
int main(){
    int noOfEdge,noOfVertices;
    vector<int> vis(noOfVertices+1,0);
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
    for(int i=1;i<=v;i++)
    { 
        if(vis[i]!=1)
        {
            dfsTraversal(graph,vis,i);
        }
    }
    printGraph(graph,noOfVertices);
    return 0;
}