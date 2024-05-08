// class MinStack {
// public:
// stack<long>s;
// long min;

//     MinStack() {
//     //  min_ele=Mini_index;
//     //  itn mini=mini;
//     // while(!s.empty())s.pop();
//     // min_ele=INT_MAX;
//     }
    
//     void push(int val) {
//         if(s.size()==0){
//            s.push(val);
//            min=val;
//         }
//         else{
//             if(val>=min){
//                 s.push(val);
//             }
//             else{
//                 s.push(2*val-min);
//                 min=val;
//             }
//         }
//     }
    
//     void pop() {
//         if(s.empty())return;
//         else{
//             if(s.top()>=min){
//                 s.pop();
//             }
//             else{
//                 min=2ll*min-s.top();
//                 s.pop();
//             }
//         }
//     }
    
//     int top() {
//         if(s.empty())return -1;
//         if(s.top()>min){return s.top();}

//         return min;
//     }
    
//     int getMin() {
//         if(s.size()==0)return -1;
//         // return s.pop();
//         return min;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */
class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> s;
    long mn;
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            mn = x;
        }
        else if(x <= mn){
            // put 2*x - mn into stack
            s.push(2ll*x - mn);
            mn = x;//modify mn
        }
        else{
            s.push(x);
        }
    }
    
    void pop() {
        if(s.empty()) return;
        // stack top can never be smaller than mn, if it is then it indicates a flag which means before popping, you have to update mn
        if(s.top() < mn){
            // mn = 2*mn - s.top()
            mn = 2ll*mn - s.top();
        }
        
        s.pop();
    }
    
    // critical part
    int top() {
        if(s.empty()) return -1;
        if(s.top() < mn){
            return mn;//minimum retrurn
        }
        return s.top();//maximum return
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return mn;
    }
};