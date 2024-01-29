//https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
public:
    stack<int> st;
    MyQueue() {
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        int val = temp.top();
        temp.pop();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return val;
    }
    
    int peek() {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        int val = temp.top();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return val;
    }
    
    bool empty() {
        return st.size()==0;
    }
};


/*
		function	Time Complexity    Space Complexity 

		push 		 O(1)                 O(1)
		pop			 O(n)                 O(n)
		peek		 O(n)                 O(n)
		empty        O(1)                 O(1)
*/

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */