// Multimap -> multiple values can have same keys...by default increasing order of keys sorted hota hai...RED-BLACK tree...
#include<iostream>
#include<map>
#include<vector>
using namespace std; 

int main(){
    // 1. Initializing...
    multimap<int,int>mm = {{1,1},{1,2},{1,2},{2,3},{4,5}};
    for(auto it=mm.begin(); it!=mm.end(); it++){
        cout<<it->first<<" and "<<it->second<<"      ";
    }
    cout<<endl;

    // 2. Inserting...
    mm.insert({7,6});
    for(auto it=mm.begin(); it!=mm.end(); it++){
        cout<<it->first<<" and "<<it->second<<"      ";
    }
    cout<<endl;

    // 3. Acessing...
    auto itr = mm.begin();
    advance(itr,3);
    cout<<itr->first<<" and "<<itr->second<<endl;

    // 4. Others...
    // .find(3) -> return itr pointing at 3 else....if 2 3s are there..then it is based on insertion order...values arent sorted...
    // .erase(3/itr) -> deletes it...
    // a1.swap(a2) -> swaps to multimaps 
    // .empty() -> checks if its empty or not...true/false...
    // .size() -> no of key-value pairs...

    // 5. Vectors as keys...
    multimap<vector<int>,int>mm1; 
    mm1.insert({{5,1,2,6,4},4});
    mm1.insert({{2,6,4},3});
    mm1.insert({{8,7,2,1,6,4},6});
    for(auto it=mm1.begin(); it!=mm1.end(); it++){
        for(auto i=(it->first).begin();i!=(it->first).end();i++){
            cout<<*i<<" ";
        }
        cout<<" and "<<it->second<<endl;
    }
    
    // 6. Descending order of multimap...using greater<dtype>
    multimap<string,int,greater<string>>mm2 = {{"dybd",1},{"dnnu",2},{"dybd",3},{"cwsr",5}};
    for(auto it=mm2.begin(); it!=mm2.end(); it++){
        cout<<it->first<<" and "<<it->second<<"      ";
    }
    cout<<endl;

    // 7. used user defined dtype...and...custom comparator in maps last one...check...

}