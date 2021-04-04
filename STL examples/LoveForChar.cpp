#include <iostream>
#include<set>
#include <unordered_map>
#include<string>

using namespace std;

int main() {
    // Write your code here
	string s;
    getline(cin, s);
    
    unordered_map<string, int> mp;
    set<string> st;
    set<string>::iterator it;
    
    //cout << endl << s << endl;
    int k = 0;
    
    string s2;
    for(int i=0; i<s.length(); i++){
    	if(s[i]==' '){
    		s2 = s.substr(k,i-k);
    		cout << s2 <<endl;
    		k=i+1;
    		
    		mp[s2]++;
    		st.insert(s2);
		}
		
	}
	

	
	
	for(it=st.begin(); it!=st.end(); it++){
		cout << *it << endl;
	}
    
    
    
    
}
