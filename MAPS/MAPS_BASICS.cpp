#include<iostream>
#include<vector>
#include<map>
using namespace std; 

struct Person{
    int age;
    char grade;
};

struct comp_new{
    bool operator()(Person a, Person t) const {
        return a.age < t.age;
    }
};

struct comp_mm{
    bool operator()(int a, int b) const {
        return a < b;
    }
};

void prints(map<string,int>m1){
    for(auto it=m1.begin();it!=m1.end();it++){
        cout<<"("<<it->first<<","<<it->second<<")"<<"    ";
    }
    cout<<endl;
}

void prints_int_int(map<int,int>m1){
    for(auto it=m1.begin();it!=m1.end();it++){
        cout<<"("<<it->first<<","<<it->second<<")"<<"    ";
    }
    cout<<endl;
}

// 11.
struct comp{
    bool operator()(string a, string b) const{
        return a > b;
    }
};

int main(){
    // 1. Intializing a map...
    map<string,int>m1 = {{"abc",3},{"sdfg",4},{"anm",3},{"abc",3}};
    prints(m1);

    // 2. Insering...
    m1.insert({"bghjk",5});
    prints(m1);

    // 3. Accessing...
    cout<<m1["abc"]<<"  "<<m1.at("abc")<<endl; 

    // 4. Updating...
    m1["abc"] = 4; 
    cout<<m1["abc"]<<endl; 

    // 5. Finding...
    if(m1.find("abc")!=m1.end()){
        cout<<"Found..."<<endl;
    }
    else{
        cout<<"Not Found..."<<endl;
    }

    // 6. Erasing...
    m1.erase("anm");
    m1.erase(m1.find("abc"));
    prints(m1);

    // 7. Empty or not..
    cout<<m1.empty()<<endl;

    // 8. size -> no of pairs...
    cout<<m1.size()<<endl;

    // 9. swapping...
    map<string,int>m2 = {{"sd",2}};
    m1.swap(m2);
    prints(m1);
    prints(m2); 

    // 10. Initialisation with help of vector...
    vector<pair<int,int>>v = {{2,3},{3,4},{4,5}};
    map<int,int>m3(v.begin(),v.end());
    prints_int_int(m3);

    // 11. custom order...
    map<string, int, comp> m4 = {{"abc", 3}, {"sdfg", 4}, {"anm", 3}};
    for(auto it=m4.begin();it!=m4.end();it++){
        cout<<"("<<it->first<<","<<it->second<<")"<<"    ";
    }
    cout<<endl;

    // 12. user defined dtype...
    map<Person,int,comp_new>m5;
    m5.insert({{1,'A'},5});    
    for(auto it=m5.begin();it!=m5.end();it++){
        cout<<(it->first).age<<" , "<<(it->first).grade<<" and "<<it->second<<"  "; 
    }
    cout<<endl;

    // 13. Merging two maps...
    map<Person,int,comp_new>m6 = {{{1,'A'},5},{{2,'B'},6},{{3,'W'},8}}; 
    m5.insert(m6.begin(),m6.end());
    for(auto it=m5.begin();it!=m5.end();it++){
        cout<<(it->first).age<<" , "<<(it->first).grade<<" and "<<it->second<<"   "; 
    }
    cout<<endl;

    // 14. count() -> returns if it is present or not...
    cout<<m5.count({1,'A'})<<endl;

    // 15. traverse in reverse...
    for(auto it=m5.rbegin();it!=m5.rend();it++){
        cout<<(it->first).age<<" , "<<(it->first).grade<<" and "<<it->second<<"   "; 
    }

    // 16. changing keys and values...
    multimap<int,Person,comp_mm>mm; 
    for(auto it=m5.begin();it!=m5.end();it++){
        mm.insert({it->second,{(it->first).age,(it->first).grade}});
    }
    cout<<endl;
    for(auto it=mm.begin();it!=mm.end();it++){
        cout<<it->first<<" , "<<(it->second).age<<" and "<<(it->second).grade<<"   "; 
    }
    // What is done here...
    // I have to replace keys and values...one value can be taken by many keys...so we used a multimap...
    // just reversed it...using for loop...
    // defined comp_mm comparator above...which compares and returns one having less integer value...
}
