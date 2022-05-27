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
void bfsTraversal(vector<int> g[],int e,int v ){
    cout<<"Bfs traversal: ";
    vector<int>vis(v+1,0);
    for(int i=1;i<=v;i++)
    {
        if(vis[i]!=1)
        {
            queue<int>q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int temp=q.front();
                q.pop();
                cout<<temp<<" ";
                for(auto j:g[temp])
                {
                    if(vis[j]!=1)
                    {
                        q.push(j);
                        vis[j]=1;
                    }
                    
                }
            }
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
    bfsTraversal(graph,noOfEdge,noOfVertices);
    printGraph(graph,noOfVertices);
    return 0;
}