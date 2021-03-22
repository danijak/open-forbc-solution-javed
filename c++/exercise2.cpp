/////////////////////////////////////////////////////////////////////////////////////////////
//  _____                                        _                   
// |_   _|                                      / |_                 
//   | |   _ .--.   .--.  _ .--.   .---.  .---.`| |-' .--.   _ .--.  
//   | |  [ `.-. | ( (`\][ '/'`\ \/ /__\\/ /'`\]| | / .'`\ \[ `/'`\] 
//  _| |_  | | | |  `'.'. | \__/ || \__.,| \__. | |,| \__. | | |     
// |_____|[___||__][\__) )| ;.__/  '.__.''.___.'\__/ '.__.' [___]    
//                       [__|                                        
// 
// Create a program capable of summing element-by-element two equally long std::vectors.
// The sum can happen in a sequential or parallel way. The latter is a bonus.
// The result must be returned in the form of another std::vector.
//
// Keep track of the progress by logging the status to stdout. No constraints are given
// on the logging format (you can use multi lines, a progres bar or anything you want).
//
// The peculiarity of this exercise is that the status logging has to be performed by 
// another thread with respect to the one (or the ones) performing the sum.
//
/////////////////////////////////////////////////////////////////////////////////////////////


// ************I have done only first part of this excercise*********************
#include <bits/stdc++.h> 
using namespace std;
int main(){

    int n;
    cout<<"Enter the length of the vector";
    cin>>n;
    vector<int> arr1;
    vector<int> arr2;
    int data;
    cout<<"Enter first vector";
    for(int i=0;i<n;i++){
        cin>>data;
        arr1.push_back(data);
    }
    cout<<"Enter second vector";
    for(int i=0;i<n;i++){
        cin>>data;
        arr2.push_back(data);
    }

vector<int> result;
 result.reserve(arr1.size());
transform (arr1.begin(), arr1.end(), arr2.begin(), result.begin(), plus<int>());
cout<<"Final result:"<<endl;
for(int i=0;i<n;i++){
        cout<<result[i]<<endl;
    }
}