class MyQueue {
public:
stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.size() != 0){
            int elem = s2.top();
            s2.pop();
            return elem;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            int elem = s2.top();
            s2.pop();
            return elem;
        }
    }
    
    int peek() {
        if(s2.size() != 0){
           
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            
            return s2.top();
        }
    }
    
    bool empty() {
        return s2.size() == 0  && s1.size() == 0;
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