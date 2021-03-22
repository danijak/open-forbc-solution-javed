////////////////////////////////////////////////////////////////////////////////////////
//  ▄████▄   ▄▄▄       ▄████▄   ██░ ██ ▓█████  ███▄ ▄███▓▓█████ 
// ▒██▀ ▀█  ▒████▄    ▒██▀ ▀█  ▓██░ ██▒▓█   ▀ ▓██▒▀█▀ ██▒▓█   ▀ 
// ▒▓█    ▄ ▒██  ▀█▄  ▒▓█    ▄ ▒██▀▀██░▒███   ▓██    ▓██░▒███   
// ▒▓▓▄ ▄██▒░██▄▄▄▄██ ▒▓▓▄ ▄██▒░▓█ ░██ ▒▓█  ▄ ▒██    ▒██ ▒▓█  ▄ 
// ▒ ▓███▀ ░ ▓█   ▓██▒▒ ▓███▀ ░░▓█▒░██▓░▒████▒▒██▒   ░██▒░▒████▒
// ░ ░▒ ▒  ░ ▒▒   ▓▒█░░ ░▒ ▒  ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░   ░  ░░░ ▒░ ░
//   ░  ▒     ▒   ▒▒ ░  ░  ▒    ▒ ░▒░ ░ ░ ░  ░░  ░      ░ ░ ░  ░
// ░          ░   ▒   ░         ░  ░░ ░   ░   ░      ░      ░   
// ░ ░            ░  ░░ ░       ░  ░  ░   ░  ░       ░      ░  ░
// ░                  ░                                         
//
// Create a cache class able to store 5 keys within.
// Values must be arranged from the most recently used key to least recently used key.
//
// Assume the data to cache is the following array:
//
// ["A", "B", "C", "D", "E", "F", "G", "H", "I"]
//
// Assume at a given point the internal cache state is (key-value representation):
//
// [1:"A", 4:"D", 6:"F", 2:"B", 9:"I"]
//
// In case the next call is via key "6" (cache hit) the cache should return "F" without
// accessing the data array. The cache state changes as follows:
//
// [6:"F", 1:"A", 4:"D", 2:"B", 9:"I"]
//
// In case the next call is "8" (cache miss) the cache should retrieve "H" from the data
// array, return it and change its state as follows:
//
// [8:"H", 6:"F", 1:"A", 4:"D", 2:"B"]
//
// Bonus: make the cache able to act on a underlying data array containing ANY data type
//
// Bonus 2: abstract the cache in ors
// 
////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <vector> 
  
using namespace std; 

bool cache_search(vector <pair<int, char>> &cache, int key)
{
    for(int i=0;i<cache.size();i++){
        if(cache[i].first==key){
            cout<<"Key found"<<endl;
            cout<<"Data is: "<<cache[i].second<<endl;
            cache.insert(cache.begin(),cache[i]);
            cache.erase(cache.begin()+i+1);
            return true;
        }
    }
    return false;
           
}

void insert_in_cache(vector<char> data,vector <pair<int, char>> &cache, int key){
    if(cache.size()==5){
        cout<<"Cache full, removing last element"<<endl;
        cache.pop_back();
    }
    cache.insert(cache.begin(),make_pair(key, data[key-1]));
    cout<<"Inserted the key in cache"<<endl;
}

int main()
{
    int n;
    cout<<"enter number of elements in data";
    cin>>n;
    vector<char> data;
    cout<<"Enter the elements";
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        data.push_back(ch);
    }
    vector <pair<int, char>> cache;
    int key;
    cout<<"Enter key or 0 to exit";
    cin>>key;
    while(key!=0){
    bool key_exists=cache_search(cache,key);
    if(!key_exists){
        insert_in_cache(data,cache,key);
    }
    cout<<"Enter key or 0 to exit";
    cin>>key;
    }
    return 0;
}


