#include<iostream>
#include<list>
#include<stack>
using namespace std; 

int main(){
    // 1. Initialising...
    stack<int>s1;
    s1.push(2);
    s1.push(4);
    s1.push(1);
    while(!(s1.empty())){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;

    // 2. Accessing...top()...only top element can be accessed...
    s1.push(5);
    s1.push(7);
    cout<<s1.top()<<endl;

    // 3. Deletingg...pop()
    // 4. empty...empty() 
    // 5. size of stack...size() 
    // 6. clearing all stack...clear()
    
    // 7. Reversing a stack...
    stack<int>temp; 
    while(!(s1.empty())){
        temp.push(s1.top());
        s1.pop();
    }
    while(!(temp.empty())){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;

    // 8. copying a stack...
    s1.push(2);
    s1.push(4);
    s1.push(1);
    stack<int>s2 = s1; 
    while(!(s2.empty())){
        cout<<s2.top()<<" ";
        s2.pop();
    }
    cout<<endl;   

    // 9. swapping two stacks...s1.swap(s2)...

    // 10. List of stacks...
    s2.push(9);
    s2.push(7);
    list<stack<int>>l; 
    l.push_front(s1);
    l.push_front(s2);
    for(auto x : l){
        while(!(x.empty())){
            cout<<x.top()<<" ";
            x.pop();
        }
        cout<<endl;
    }

    // 11. Reversing a string using stack...
    string p = "abcdef";
    stack<char>rev;
    for(auto i : p){
        rev.push(i);
    }
    while(!(rev.empty())){
        cout<<rev.top();
        rev.pop();
    }
    cout<<endl;

    return 0;

}