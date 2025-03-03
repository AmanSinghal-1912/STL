#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void prints(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void prints(vector<char>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void passbyvalue(vector<int>v){
    v.push_back(100);
}

void passbyreference(vector<int> &v){
    v.push_back(200);
}

int main(){
    // 1. Initializinggg...
    vector<int>v = {1,2,3,5}; 
    prints(v);

    // 2. Declaration...
    vector<int>v1(5,9); // vector with 5s...9 times... 
    prints(v1);

    vector<int>v2 = v;
    prints(v2); 

    vector<char>v3;

    // 3. Insertinggg elements...
    v3.push_back('A');
    v3.push_back('B');
    prints(v3);

    // 4. Updatingg...
    v3[0] = 'S';
    for(auto x : v3){
        cout<<x<<" ";
    }
    cout<<endl;

    // 5. Deleting elements...
    v1.pop_back();
    prints(v1); 

    v.erase(find(v.begin(),v.end(),3));
    prints(v);

    // 6. Finding element...
    auto it = find(v.begin(),v.end(),3);
    if(it!=v.end()){
        cout<<"Present..."<<endl;
    }
    else{
        cout<<"Not Present..."<<endl;
    }

    // 7. Resizing a vector...
    vector<int> v4 = {1, 4, 6}; // Vector resized to 7 and added elements
    v4.resize(7, 9); // initialized to 9 
    prints(v4); 

    // 8. capacity and size...
    vector<int>v5;   // vector with nothing...
    cout<<"Cap:"<<v5.capacity()<<"   Size:"<<v5.size()<<endl;
    // SO SIZE 0  CAP 0
    // PASSING SOME ELEMENTS INIT...
    v5.push_back(1);
    prints(v5);
    cout<<"Cap:"<<v5.capacity()<<"   Size:"<<v5.size()<<endl;
    v5.push_back(2);
    prints(v5);
    cout<<"Cap:"<<v5.capacity()<<"   Size:"<<v5.size()<<endl;
    v5.push_back(3);
    prints(v);
    cout<<"Cap:"<<v5.capacity()<<"   Size:"<<v5.size()<<endl;
    
    // 9. Pass by value and pass by reference...not like array which is always pass by reference...
    cout<<"PASS BY VALUE...CHECK..."<<endl;
    prints(v5);
    // FINDING IT AS PASS BY VALUE...
    passbyvalue(v5);
    // PRINTING AGAIN TO CHECK 
    prints(v5);
    // IT IS PASS BY VALUE NOW..100 NOT PRINTED...
    cout<<"PASS BY REF..CHECK"<<endl;
    passbyreference(v5);
    prints(v5);
    // SO 200 IS PRINTED...
    cout<<"Cap:"<<v5.capacity()<<"   Size:"<<v5.size()<<endl;

    // 10. Front and back elements print...
    cout<<v5.front()<<endl;
    cout<<v5.back()<<endl; 

    // 11. Reversing a vector 
    reverse(v4.begin(),v4.end());
    prints(v4);

    // 12. Ascending order...
    sort(v4.begin(), v4.end());
    prints(v4); 

    // 13. Descending order...
    sort(v4.begin(), v4.end());
    reverse(v4.begin(),v4.end()); 
    prints(v4); 

    // 14. Copying a vector...
    vector<int> v6 = v4; 
    prints(v6);

    // 15. Swapping two vectors...
    v.swap(v6);
    prints(v);
    prints(v6); 

    // 16. Removing duplicates...using unique()...
    // unique()...moves all duplicates atlast of vector and returns an iterator of the start of the duplicates...but sorting is required...
    vector<int>v7 = {2,2,5,1,1,5,7};
    sort(v7.begin(),v7.end()); 
    auto itr_new = unique(v7.begin(),v7.end()); 
    prints(v7);
    v7.erase(itr_new,v7.end());
    prints(v7);

    // 17. Finding index of an element...
    vector<int> v8 = {1, 2, 5, 9};
    auto it1 = find(v8.begin(), v8.end(), 5);
    cout << it1 - v8.begin()<<endl;

    // 18. 2D Vectors...
    vector<vector<int>>v9; 
    v9.push_back(vector<int>(4,8));
    v9.push_back(vector<int>(4,8));
    v9.push_back(vector<int>(4,8)); 
    for(auto i : v9){
        for(auto j : i){
            cout<< j <<"  ";
        }
        cout<<endl;
    }

    // 19. Jagged Array...
    vector<vector<int>>v10;

    vector<int>a(3,0);
    vector<int>b(4,0);
    vector<int>c(1,0);
    vector<int>d(7,0);
    vector<int>e(2,0);

    v10.push_back(a);
    v10.push_back(b);
    v10.push_back(c);
    v10.push_back(d);
    v10.push_back(e);

    for(auto i : v10){
        for(auto j : i){
            cout<< j <<"  ";
        }
        cout<<endl;
    }

    return 0; 
}