#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[],int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
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
bool detectCycle(vector<int> g[],int v){
    vector<int> vis(v+1,0);
    queue<pair<int ,int>>q;
    for(int i=0;i<=v;i++)
    {
        if(vis[i]!=1)
        {
            vis[i]=1;
            q.push({i,-1});
            while(!q.empty())
            {
                int temp=q.front().first;
                int par=q.front().second;
                q.pop();
                for(auto it:g[temp])
                {
                    if(vis[it]!=1){
                        q.push({it,temp});
                        vis[it]=1;
                    }
                    else if(par!=it){
                        return true;
                    }
                }
            }
        }
    }
    return false;
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
    if(detectCycle(graph,noOfVertices))
    {
        cout<<"Cycle is present in the graph.";
    }
    else{
        cout<<"No cycle found.";
    }
    return 0;
}