#include<iostream>
#include<climits>
using namespace std;

typedef long long ll;

ll kadane(int arr[], int n){
	int current_sum = 0;
	ll max_sum = INT_MIN;
	
	for(int i=0; i<n; i++){
		current_sum += arr[i];
		if(current_sum <0){
			current_sum = 0;
		}
		
		if(current_sum>max_sum){
			max_sum = current_sum;
		}	
	}
	return max_sum;
}


ll maxSubarraySum(int arr[], int n, int k){
	
	ll kadane_sum = kadane(arr, n);
	
	if(k==1){
		return kadane_sum;
	}
	
	ll curr_prefix_sum = 0, curr_suffix_sum=0;
	ll max_prefix_sum = INT_MIN, max_suffix_sum = INT_MIN;
	
	for(int i=0; i<n; i++){
		curr_prefix_sum = curr_prefix_sum + arr[i];
		max_prefix_sum = max(curr_prefix_sum, max_prefix_sum);
	}
	
	ll total_sum = curr_prefix_sum;
	
	for(int i=n-1; i>=0; i--){
		curr_suffix_sum = curr_suffix_sum + arr[i];
		max_suffix_sum = max(max_suffix_sum, curr_suffix_sum);
	}
	
	ll ans;
	if(total_sum<0){
		ans = max(max_suffix_sum+max_prefix_sum, kadane_sum);
	}else{
		ans = max(max_suffix_sum+max_prefix_sum+(total_sum)*(k-2), kadane_sum);
	}
	return ans;
}




int main(){
	
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int arr[n];
		
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		
		cout << maxSubarraySum(arr, n, k) << endl;
		
	}
	
	
	return 0;
}
