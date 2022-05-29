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
void dfsTraversal(vector<int>g[],int e,int v){
    vector<int> vis(v+1,0);
    stack<int> s;
    for(int i=1;i<=v;i++)
    {
        if(vis[i]!=1)
        {
            vis[i]=1;
            cout<<i<<" ";
            for(auto i:g[i])
            {
                s.push(i);
            }
            int k=s.top();
            s.pop();
            if(vis[k]==0){
                cout<<k<<" ";
            }
            vis[k]=1;
        }
    }
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
    dfsTraversal(graph,noOfEdge,noOfVertices);
    printGraph(graph,noOfVertices);
    return 0;
}