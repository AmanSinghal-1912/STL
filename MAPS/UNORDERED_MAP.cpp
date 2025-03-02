// UNORDERED MAPS -> not sorted...hashing technique is used...no duplicates...O(1) in many operations...
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct Point{
    int x;
    int y;

    bool operator == (Point b) const{
        return ((this->x == b.x) && (this->y == b.y));
    }
};

struct myhash{
    size_t operator ()(Point a) const{
        return hash<int>()(a.x) ^ hash<int>()(a.y);
    }
};

int main(){
    // 1. Initialising...
    unordered_map<int, string> ump = {{1, "hero"},{1, "ro"},{2, "timkr"}, {13, "terror"}}; 
    for(auto it=ump.begin();it!=ump.end();it++){
        cout<<it->first<<" and "<<it->second<<"      ";
    }
    cout<<endl;

    // 2. Others...
    // .insert({33,"dd"}) -> inserts in the unordered map...
    // Updating -> ump[2] = "dninxd"... 
    // Deleting -> .erase(5/itr)
    // .size() -> size of unordered map
    // .empty() -> true/false
    // ump1.swap(ump2) -> swappinggg...
    // .find(1) -> gives itr pointing 1 else .end()

    // 3. User defined and custom comparators...
    unordered_map<Point,int,myhash>ump2 = {{{1,1},2},{{2,1},3},{{4,6},10},{{1,4},5},{{1,1},2}};
    for(auto it=ump2.begin();it!=ump2.end();it++){
        cout<<it->first.x<<" and "<<it->first.y<<"    "<<it->second<<"      ";
    }


}