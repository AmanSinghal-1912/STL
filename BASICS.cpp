#include<iostream>
#include<vector>

using namespace std;

int main(){

    // 1...
    // ITERATORS:::: same as pointers...just every iterator is bit different and not every iterator is used for all containers...
    vector <int> v {1,2,3,4,5};
    vector<int>:: iterator it;

    // INPUT ITERATORS...accessing and traversing...
    for(it = v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // OUTPUT ITERATORS...modification
    it = v.begin();
    it++;
    *it = 23;
    for(it = v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // FORWARD ITERATORS...same as input and output just move in forward direction one by one...

    // BIDIRECTIONAL...dono side mai move kar sakta hai..but only one at a time...
    it = v.begin();
    it++;
    it++;
    --it;
    cout<<*it<<endl;

    // RANDOM ACCESS ITERATOR...kabhi bhi kisiko bhi access kar sakta hai...
    it = v.begin();
    cout<<*(it+3)<<" ";
    cout<<it[3]<<" ";

    return 0;

}
