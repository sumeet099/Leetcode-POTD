//https://leetcode.com/problems/daily-temperatures/
// logic - observe monotonic nature and use monotonic stack opearations

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
	    int n = temperatures.size();
	    vector<int> ans(n);

	    stack<int> st;
	    
	    for(int i = 0 ; i<n; i++){
	        
	        if(!st.empty()){
	            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
	                ans[st.top()] = i - st.top();
	                st.pop();
	            }
	        }
	        st.push(i);
	    }
	    return ans;
	}
};
// Time Complexity - O(n);
// Space Complexity - O(n);