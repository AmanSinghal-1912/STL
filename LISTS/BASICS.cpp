#include<iostream>
#include<list> 
#include<vector>
#include<algorithm>
using namespace std; 

void print(list<int>l){
    for(auto x : l){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    // 1. Initialisinggg...
    list<int> l = {1,2,3,4,5};
    for(auto x : l){
        cout<<x<<" ";
    }
    cout<<endl;

    // 2. Declarationn...
    list<int> l1(5, 9); 
    print(l1);
    cout<<endl;

    // 3. Insering...
    l1.push_back(9);
    l1.push_front(1);
    auto it = l1.begin();
    advance(it,3);
    l1.insert(it,4);
    print(l1);
    cout<<endl;

    // 4. Accessingg...
    cout << l1.front() << "   ";
    cout << l1.back() << "   "; 
    cout<< *(next(l1.begin(),2))<<endl; 

    // 5. Finding... find(l1.begin(),l1.end(),3) 
    // 6. Deleting...l1.pop_front()...l1.pop_back()...l1.erase(itr)...
    // 7. .empty() -> true/false 
    // 8. .size() -> no of elements 
    // 9. l1.swap(l2) -> swapping two lists 
    // 10. .resize(no of elements/n,val)...if any less fill rest with that value...
    // 11. sort(l1.begin(),l1.end())...sorts the elements...
    // 12. list<int>l1 = l2....copies a list...
    // 13. reverse(l1.begin(),l1.end())...reverses the elements..
    // 14. l1.merge(l2) -> merging two lists 

    // 15. List of vectors...
    list<vector<int>>l2 = {{1,2,3,4},{3,4,5,6,7},{2,3}};
    for(auto i : l2){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    list<vector<int>>l3(3,vector<int>(4,8));
    for(auto i : l3){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }  

    return 0;
}