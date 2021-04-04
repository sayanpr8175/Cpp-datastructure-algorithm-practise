#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> removeDuplicates(vector<int> input){
	
		sort(input.begin(), input.end());
		vector<int> ans;
		
		vector<int>::iterator it;
		
		ans.push_back(input[0]);
		int k = 0;
		for(int i=1; i<input.size(); i++){
			
			if(input[i]!=ans[k]){
			k++;
			ans.push_back(input[i]);
			}
		}
		
		
		return ans;
		
		
	
}


int main(){
	int n;
	vector<int> vec;
	
	cin >> n;
	for(int i=0; i<n; i++){
		int k;
		cin>> k;
		vec.push_back(k);
	}
	
	vector<int> k = removeDuplicates(vec);
	vector<int>::iterator it;
	
	for(it=k.begin(); it!=k.end(); it++){
		cout << *it << " ";
	}
	
	return 0;
}

