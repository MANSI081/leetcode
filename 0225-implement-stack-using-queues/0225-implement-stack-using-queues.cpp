class MyStack {
public:
queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {

        int n=q1.size();

        for(int i=0;i<n-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        // the last element in q1 is the one to be popped
        int x=q1.front();
        q1.pop();

        // swap the name of q1 and q2 to maintain order
        swap(q1,q2);
        return x;
        
    }
    
    int top() {

        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */