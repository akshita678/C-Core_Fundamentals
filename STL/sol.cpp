#include <iostream>
#include<vector>
#include<algorithm> // needed for sort function
using namespace std;
int main(){
    vector<int>v;
    // adding new values into vector 
    v.push_back(90);
    v.push_back(89);
    v.push_back(78);
    v.push_back(98);
    //deleeting values 
    v.pop_back();
    cout<<v.size(); // returns 1 
    // deleting at an index 
    // insertion 
    v.insert(v.begin()+1,78); // adds 78 at 1st index 
     cout<<v.size(); // return 4 
     // sorting in vector 
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; 
    }
    // binary search
    int ans=binary_search(v.begin(),v.end(),90); // return 1 when present 
    cout<<ans<<endl;
  // clearing a vector 
 // v.clear(); // clears entire vector
    return 0;
}
