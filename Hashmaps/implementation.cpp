#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

//In hash maps,the data is stored in the form of keys against which some value is assigned. Keys and values do not need to be of the same data type.
//Type of data structure in which data is stored in the form of key value pair

int main() {
    //creation of map
    unordered_map<string,int> m;

    //insertion way-1
    pair<string,int> p1 = make_pair("school",3);
    m.insert(p1);

    //insertion way-2
    pair<string, int> p2("study",2);
    m.insert(p2);

    //insertion way-3
    //value of 1 given corresponding to teacher
    m["teacher"]=1;
    m["teacher"]=2;
    //first time-> creation/insertion is done
    //second time-> update of value is done
    //now value corresponding to teacher is 2

    //unique entry exists for every key
    //no duplicate entries for a key

    //searching
    cout<<m["study"]<<endl;
    cout<<m.at("school")<<endl;

    //accessing a key which does not exist
    //cout<<m.at("unknownKey")<<endl; //output is error
    cout<<m["unknownKey"]<<endl; //output is 0
    cout<<m.at("unknownKey")<<endl;

    //size
    cout<<m.size()<<endl;

    //to check presence
    cout<<m.count("school")<<endl;
    cout<<m.count("student")<<endl;
    //count() function gives 1 when present and 0 when absent

    //erase
    m.erase("unknownKey");
    cout<<m.size()<<endl;

    //accessing the whole map-traversing
    for(auto i:m) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    //ITERATOR
    unordered_map<string,int> :: iterator it = m.begin();
    //run loop till iterator reaches end of map
    while(it != m.end()) {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }




}
