#include<iostream>
#include<queue> 
#include<stack> 
#include<algorithm>
using namespace std; 

// 12.
void enqueue(stack<int>&s1, int n){
    stack<int>s2;
    while(!(s1.empty())){
        s2.push(s1.top());
        s1.pop();
    }
    s2.push(n); 
    while(!(s2.empty())){
        s1.push(s2.top());
        s2.pop();
    }
}

int dequeue(stack<int>&s1){
    if(s1.empty()){
        return -1;
    }
    s1.pop();
    return 0;
} 

// 13.
struct Point{
    int x;
    int y;
};

int main(){
    // 1. Initialisinggg...
    queue<int>q;
    q.push(3);
    q.push(4);
    while(!(q.empty())){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    // 2. Declaration...
    q.push(3);
    q.push(4);
    queue<int>q1 = q;
    while(!(q1.empty())){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;

    // 3. Inserting...push() 
    // 4. Deleting...pop() 
    // 5. Front element...front() 
    // 6. Back element...back() 
    // 7. .size() -> no of elements 
    // 8. empty() -> true/false
    // 9. q1.swap(q2) -> swapping two queues
    
    // 10. Reversing a queue..
    stack<int>rev;
    while(!(q.empty())){
        rev.push(q.front());
        q.pop();
    }
    while(!(rev.empty())){
        cout<<rev.top()<<" ";
        rev.pop();
    }
    cout<<endl;

    // 11. Queue of pairs...
    queue<pair<char,int>>q2;
    q2.push({'a',65});
    q2.push({'b',66});
    q2.push({'c',67});
    q2.push({'d',68});
    q2.push({'e',69});
    while(!(q2.empty())){
        cout<<q2.front().first<<" & "<<q2.front().second<<"    ";
        q2.pop();
    }
    cout<<endl;

    // 12. Implementing a queue using stacks...
    stack<int>n;
    n.push(1);
    n.push(2);
    n.push(3); // top -> 3 2 1
    enqueue(n,4); // new element inserts at back...top -> 3 2 1 4  
    if(dequeue(n)){
        cout<<"Successful"<<endl;
    }
    while(!(n.empty())){
        cout<<n.top()<<" ";
        n.pop();
    }
    cout<<endl;

    // 13. User defined dtype...
    queue<Point>p;
    p.push({1,2});
    p.push({4,6});
    p.push({3,2});
    while(!(p.empty())){
        cout<<p.front().x<<" & "<<p.front().y<<"    ";
        p.pop();
    }
    return 0;
    
}