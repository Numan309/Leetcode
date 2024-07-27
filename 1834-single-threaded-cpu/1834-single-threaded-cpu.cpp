class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
        int n = tasks.size();
        //Sort the task on the basis of enqueueTime
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        
         long long timer = tasks[0][0];
        int i=0;
  //   processing time ,index   
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //put all the task into min heap whose enqueue is less than or equal timer
        
        while(!pq.empty() || i<n)
        {
        
        while(i<n && timer>=tasks[i][0])
        {
            pq.push({tasks[i][1],tasks[i][2]});
            i++;
        }
        //min_heap is empty
        if(pq.empty())
        {
            timer = tasks[i][0];
        }
        //not empty
        else
        {
            ans.push_back(pq.top().second);
            timer+=pq.top().first;
            pq.pop();
        }
        }
        return ans;
    }
};