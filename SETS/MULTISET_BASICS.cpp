// Multiset can have duplicate values...still sorted...

#include<iostream>
#include<vector>
#include<set>
// #include "SET_BASICS.cpp"
using namespace std;

void multiset_print(multiset<int>s){
    for(auto x : s){
        cout<<x<<" ";
    } 
    cout<<endl;
}

// 5.
struct comp{
    bool operator()(int a, int b) const{
        return a > b;
    }
};

// 7.
struct Person{
    string first_name;
    string last_name;
    int age;

    void prints() const{
        cout<<this->first_name<<" "<<this->last_name<<" "<<this->age<<endl;
    }
};

struct comp_person{
    bool operator()(Person a, Person b) const{
        if(a.first_name==b.first_name){
            if(a.last_name == b.last_name){
                return a.age > b.age;
            }
            return a.last_name > b.last_name;
        }
        return a.first_name > b.first_name;
    }
};

void prints(Person a){
    cout<<a.first_name<<" "<<a.last_name<<" "<<a.age<<endl;
}

int main(){
    // 1. Initialising Multiset...
    multiset<int>m1 = {1,1,2,2,5,1,3,4};
    multiset_print(m1);

    // 2. .erase() -> deletes all occurances of that value...
    m1.erase(next(m1.begin(),3));
    multiset_print(m1); 

    m1.erase(1);
    multiset_print(m1); 

    // 3. .find() returns the iterator pointing the first occurence...
    multiset<int>m2 = {1,1,2,2,5,1,3,4};
    auto it = m2.find(2);
    for(;it!=m2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // 4. .count()..returns no of occurances...
    cout<<m2.count(1)<<endl;

    // 5. using decreasing order custom comp...
    multiset<int,comp>m3 = {1,1,2,2,5,1,3,4}; 
    for(auto it = m3.begin(); it!=m3.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // 6. Multiset of pairs...
    multiset<pair<string,int>>m4 = {{"abc",3},{"abcde",5},{"abcde",5}};
    for(auto it = m4.begin(); it!=m4.end(); it++){
        cout<<"("<<it->first<<" and "<<it->second<<") ";
    }
    cout<<endl;

    // 7. Multiset for user defined dtype...
    multiset<Person,comp_person>m5;
    m5.insert({"Aman","Singhal",21});
    m5.insert({"Aagam","Chhajer",20});
    m5.insert({"Aagam","Chhajer",21});
    m5.insert({"Aagam","Chhaj",21});
    for(auto it=m5.begin();it!=m5.end();it++){
        it->prints();
    }
    // Lessons...
    // You can't make an iterator of struct or class...like...Person :: iterator i ❌  
    // Define the custom comparator always separately...
    // it is a iterator pointing with Person object...thus member func prints() came...

    // 8. Swapping 2 multisets...(must be of same type...)
    multiset<Person,comp_person>m6;
    m6.insert({"Rahul", "Sharma", 25});
    m6.insert({"Aryan", "Verma", 22});
    m5.swap(m6);
    cout<<endl;
    for(auto it=m5.begin();it!=m5.end();it++){
        prints(*it);
    }   
    cout<<endl;
    for(auto it=m6.begin();it!=m6.end();it++){
        prints(*it);
    }

    // 9. Multiset of vectors...
    multiset<vector<int>>m7;
    m7.insert({1,9,4,5,7,0});
    m7.insert({4,5,7});
    m7.insert({5});
    m7.insert({1,2,4,5,7,0});
    for(auto it=m7.begin();it!=m7.end();it++){
        for(auto i=it->begin();i!=it->end();i++){
            cout<<*i<<" ";
        }
        cout<<endl;
    }
    // Lessons...
    // It doesnt sort the vectors...just sort elements of set...

}