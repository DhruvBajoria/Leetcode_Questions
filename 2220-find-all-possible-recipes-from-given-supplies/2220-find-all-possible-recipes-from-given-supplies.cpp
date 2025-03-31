class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ingredients, vector<string>& supplies) {
         unordered_map<string,vector<string>> graph;
        int n = rec.size();
        unordered_set<string> s;
        for(auto x : supplies) s.insert(x);            //store all the supplies in unordered set
		
        unordered_map<string,int> indegree;   //to store the indegree of all recipes
        for(auto x : rec)indegree[x] = 0;                      //initially take the indegree of all recipes to be 0
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (int)ingredients[i].size(); j++){
                if(s.find(ingredients[i][j]) == s.end()){     
                    graph[ingredients[i][j]].push_back(rec[i]);    //if the ingredient required to make a recipe is not in supplies then  
                    indegree[rec[i]]++;                     //we need to make a directed edge from that ingredient to recipe
                }
            }
        }
        
        //KAHN'S ALGORITHM
        queue<string> q;
        for(auto x : indegree){
            if(x.second == 0){
                q.push(x.first);
            }
        }
       vector<string> ans;
        while(!q.empty()){
            string tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto nbr : graph[tmp]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return ans;
    }
};