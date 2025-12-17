
#include <bits/stdc++.h>
using namespace std;
vector<int> dfs(vector<vector<int>> &graph,int src){
    vector<int> res;
    stack<int> st;
    int nov=graph.size();
    vector<bool> visit(nov,false);
    st.push(src);
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        if(visit[curr]==false){
            visit[curr]=true;
            res.push_back(curr);
            for(int i=0;i<graph[curr].size();i++){
                st.push(graph[curr][i]);
            }
        }
    }
    return res;
}
int main()
{
    //create graph
    
    int noe=17;
    int nov=14;
    int edges[noe][2]={{0,1},{0,4},{0,5},{1,2},{2,3},{3,10},{4,6},{6,13},{5,7},{7,8},{8,10},{8,9},{7,9},{9,11},{11,12},{10,11},{4,5}};
    vector<vector<int>> graph(nov) ;
    for(int i=0;i<noe;i++){
        int v1=edges[i][0];
        int v2=edges[i][1];
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    // dfs
    
    vector<int> res=dfs(graph,3);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    return 0;
}
