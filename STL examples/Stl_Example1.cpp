#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<map>

using namespace std;

int main(){
	
	/*
	vector<int> v;
	
	for(int i=0; i<v.size(); i++){
		v.push_back(i+1);
	}
	
	vector<int>::iterator it;
	
	for(it=v.begin(); it!=v.end(); it++){
		cout << *it << endl;
	}
	*/
	
	/*
	
	string s = "Sayan";
	string s1(s,1,4);
	cout << s << endl;
	cout << s1 << endl;
	
	*/
	
	/*
	pair<int, char> p;
	pair<int, char> p2(1, 'a');
	
	cout << p2.first << " " << p2.second << endl;
	
	p = make_pair(2, 'b');
	
	cout << p.first << " " << p.second << endl;
	*/
	
	/*
	
	set<int> s;
	int arr[] = {1, 2, 3, 4, 5, 6, 5};
	
	for(int i=0; i<7; i++){
		s.insert(arr[i]);
	}
	
	set<int>::iterator it;
	for(it=s.begin(); it!=s.end(); it++){
		cout << *it << endl;
	}
	
	if(s.find(6)==s.end()){
		cout << "Element found " << endl;
	}
		
	*/
	
	//MAP
	
	int arr[] = {1, 2, 3, 4, 5, 6, 5};
	map<int,int> m;
	
	for(int i=0; i<7; i++){
		m[arr[i]] = m[arr[i]]+1;
	}
	
	map<int, int>::iterator it;
	
	for(it=m.begin(); it!=m.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
	m.erase(1);
	
	for(it=m.begin(); it!=m.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	
	return 0;
}
