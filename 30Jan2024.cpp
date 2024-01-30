//https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        if(tokens.size()==1){
            return stoi(tokens[0]);
        }
        
        stack<int> st;
        int ans = 0;
        for(auto x: tokens){

            if(x=="+" || x=="-" || x=="*"|| x=="/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int val = 0;
                if(x=="+")val= (a+b);
                else if(x=="-")val= (a-b);
                else if(x=="*")val= (a*b);
                else if(x=="/")val= (a/b);

                st.push(val);
                ans = val;
            }
            else{
                st.push(stoi(x));
            }   
        }   

        return ans;
    }
};


// Time Complexity - O(n);
// Space Complexity - O(n);