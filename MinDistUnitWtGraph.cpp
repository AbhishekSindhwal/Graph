#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[],int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(vector<int>graph[],int noOfVertices){
    for(int i=0;i<=noOfVertices;i++)
    {
        for(auto j:graph[i])
        {
           cout<<j<<" ";
        }
        cout<<endl;
    }
}
void minDistance(vector<int>g[],vector<int>&dis,int node)
{
    
    queue<int>q;
    q.push(node);
    dis[node]=0;
    while(!q.empty())
    {
        q.pop();
        for(auto it:g[node])
        {
            if(dis[node]+1<dis[it]){
                dis[it]=dis[node]+1;
                q.push(it);
            }
        }
        node=q.front();
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
    printGraph(graph,noOfVertices);
    vector<int>dis(noOfVertices,INT_MAX);
    minDistance(graph,dis,0);
    for(int i=0;i<dis.size();i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}