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
    return 0;
}