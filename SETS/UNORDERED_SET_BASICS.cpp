// UNORDERED SET-: no order...elements are stored randomly...no duplicates...
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void prints(unordered_set<int> &a){
    for(auto it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

// 3.
struct Person{
    string first_name;
    string last_name;

    bool operator==(Person b) const{
        return ((this->first_name==b.first_name) && (this->last_name==b.last_name));
    }
    // needs to be written within struct unlike last time...as this is binary one...(a==b) whereas last one was (...) unary one...
    // checks if 2 same elements are there...
};

// Unordered set uses concept of HASHING rather than Red-Black tree...
// Har ek value enter hoga to usko ek unique hash value provide hogi...
// isliye hamara finding wala kaam O(1) mai hojata hai...
struct myhash{
    size_t operator()(Person p) const {
        return hash<string>()(p.first_name) ^ hash<string>()(p.last_name);
    }
};

int main(){
    // 1. Initialising an unordered set...
    unordered_set<int>u1;
    u1.insert({3,4,4,6,6});
    prints(u1);

    // 2. Same operations like set and multiset...
    // delete -> .erase(4/itr)
    // finding -> .find()...return itr or .end() 
    // traversing-> see prints() 
    // updating -> not possible...
    // empty? -> .empty()...true/false 
    // .size() -> no of elements 
    // u1.swap(u2) -> swaps 2 unordered sets 
    
    // 3. User defined function...
    unordered_set<Person,myhash>u2;
    u2.insert({{"A","C"},{"a","c"},{"A","c"},{"a","C"},{" ","C"},{" ","c"}});
    for(auto it=u2.begin();it!=u2.end();it++){
        cout<<it->first_name<<" and "<<it->last_name<<endl;
    }
    // Lessons...
    // We didnt use custom comp here...myhash is used for hashing...helps to generate hashing value...
    // like A,C has 7532857957259 value..similarly sabka value alag hai...
    // isliye finding can be done in O(1)...
    // hash value ke liye..() overloaded this...dono ke liye hash value generate horaha and ^ is used to combine hash values...

}