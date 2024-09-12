class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
          int V = graph.size();
        vector<int>color(V,-1);
	   queue<int>q;
	   
	   for(int i=0;i<V;i++)
	   {
	     if(color[i]==-1)
	     {
	          q.push(i);
	   color[i]=0;
	   while(!q.empty())
	   {
	       int node = q.front();
	       q.pop();
	       for(int j=0;j<graph[node].size();j++)
	       {
	           //color not assigned to them
	           if(color[graph[node][j]]==-1){
	               color[graph[node][j]]=(color[node]+1)%2;
	               q.push(graph[node][j]);
	           }
	          //already color assigned
	          else{
	              if(color[node]==color[graph[node][j]])
	              return 0;
	          }
	       }
	   }
	     }
	   }
	  
	   return 1;  
    }
};