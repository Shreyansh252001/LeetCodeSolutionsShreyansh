;class MyQueue {
public:
  stack<int> st;
  stack<int> st1;
  int a;
    MyQueue() {
      
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty())
        {
          st1.push(st.top());
          st.pop();
        }
      
      a=st1.top();
      st1.pop();
      
       while(!st1.empty())
        {
          st.push(st1.top());
          st1.pop();
        }
      
      return a;
    }
    
    int peek() {
        a= st.top();
          while(!st.empty())
        {
          st1.push(st.top());
          st.pop();
        }
      
        a=st1.top();
      
       while(!st1.empty())
        {
          st.push(st1.top());
          st1.pop();
        }
      
      return a;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
