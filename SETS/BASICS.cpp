#include<iostream>
#include<set>
#include<vector>
using namespace std;

void print(set<int>s){
    for(auto x : s){
        cout<<x<<" ";
    } 
    cout<<endl;
}

// 2. 
struct comp{
    bool operator() (int a, int b) const{
        return a > b;
    }
};

// 13.
struct mycomp{
    bool operator()(pair<int,int>a, pair<int,int>b) const{
        if(a.second==b.second){
            return a.first > b.first; 
        }
        return a.second > b.second;
    }
    // dot -> pairs / values
    // arrow -> iterator pointing to pair
};

// 14.
struct mycompdiff{
    bool operator()(pair<int,int>a, pair<int,int>b) const{
        if(abs(a.second-a.first)==abs(b.second-b.first)){
            return a.first > b.first;
        }
        return abs(a.second-a.first) > abs(b.second-b.first);
    }
};

// 15.
struct mycomprank{
    bool operator()(pair<char,int>a, pair<char,int>b) const{
        if(a.first==b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

int main(){
    // 1. How a SET is initialized and how its stored in ascending order...
    set <int> s = {3,5,2,1}; 
    for(auto x : s){
        cout<<x<<" ";
    } 
    cout<<endl;
    // OUTPUT-: 1 2 3 5   

    // 2. CUSTOM COMPARATOR**
    set<int,comp>s1; 
    s1.insert(3);
    s1.insert(5);
    s1.insert(1);
    for(auto x : s1){
        cout<<x<<" ";
    } 
    cout<<endl;
    // OUTPUT - 5 3 1

    // 3. Inserting elements-: insert() / emplace() 
    set<int>s2 = {3,6,2};
    s2.insert(1);
    s2.insert(5);
    print(s2);

    // 4. Accessing Elements...
    set<int>:: iterator it;
    for(it = s2.begin(); it!=s2.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    // next(iterator,number of steps) & advance(iterator,number of steps)...
    set<int>:: iterator it1 = s2.begin();
    auto a = next(it1,2); 
    cout<<*a<<" ";
    advance(a,2);
    cout<<*a<<" ";
    cout<<endl;

    // 5. Updation-: Not possible in sets...as it may unfollow balance search tree props...

    // 6. Finding an element-: .find() if gets returns an iterator pointing at 3 else points at .end()...
    auto it2 = s2.find(1);
    if(it2==s2.end()){
        cout<<"Not found.."<<endl;
    }
    else{
        cout<<"Found.."<<endl;
    }

    // 7. Deleting an element-: .erase(iterator/value)...
    s2.erase(3);
    print(s2);
    s2.erase(it2);
    print(s2); 

    // 8. Empty or not-: .empty() 
    if(s2.empty())
    cout<<"Empty.."<<endl;
    else
    cout<<"Not Empty.."<<endl; 

    // 9. finding size of a set-: .size()...empty ka size is 0...
    cout<<s2.size()<<endl;

    // 10. Reverse iterators...rbegin() and rend()...
    // it3++ because internally there is always a pointer that moves backwards...in case reverse begin and end...
    for(auto it3 = s2.rbegin(); it3!=s2.rend(); it3++){
        cout<<*it3<<" ";
    }
    cout<<endl;

    // 11. Swapping two sets....s1.swap(s2)...
    set<int>a1 = {1,2,3};
    set<int>b1 = {4,5,6};
    a1.swap(b1);
    print(a1);
    print(b1);

    // 12. using pair<int,int> in sets instead of just int...
    set<pair<int,int>> s3; 
    s3.insert({1,11});
    s3.insert({2,12});
    s3.insert({2,13});
    s3.insert({1,11});
    for(auto it = s3.begin(); it!=s3.end(); it++){
        cout<<"("<<it->first<<"and"<<it->second<<") ";
    }
    cout<<endl;

    set<string>s4 = {"abcx","abcd","abc"};
    for(auto it = s4.begin(); it!=s4.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    // string -> lexographical order...dictionary wala...
    // pair<int,int> -> first element ke basis par... 

    // 13. sorts on basis of second element...
    set<pair<int,int>,mycomp> s5; 
    s5.insert({1,11});
    s5.insert({2,11});
    s5.insert({2,13});
    s5.insert({1,11});
    for(auto it = s5.begin(); it!=s5.end(); it++){
        cout<<"("<<it->first<<"and"<<it->second<<") ";
    }
    cout<<endl;

    // 14. sorts on basis of difference of first and second element 
    set<pair<int,int>,mycompdiff> s6; 
    s6.insert({1,11});
    s6.insert({2,12});
    s6.insert({2,13});
    s6.insert({1,11});
    for(auto it = s6.begin(); it!=s6.end(); it++){
        cout<<"("<<it->first<<"and"<<it->second<<") ";
    }
    cout<<endl;

    // 15. {char - rank} in set...if char is same...rank should be in descending order...
    set<pair<char, int>, mycomprank> s7;
    s7.insert({ 'a', 3 });
    s7.insert({ 'c', 2 });
    s7.insert({ 'c', 4 });
    s7.insert({ 'c', 5 });
    s7.insert({ 'b', 4 });
    s7.insert({ 'b', 3 });
 
    for (auto i = s7.begin(); i != s7.end(); i++) {
        cout << i->first << " " << i->second << endl;
    }

    // 16. Intialization through any other container...
    vector<int>v{1,2,3,4};
    set<int>s8(v.begin(),v.end());
    print(s8);

    return 0;
}

