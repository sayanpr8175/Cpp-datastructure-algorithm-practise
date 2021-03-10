/*
	Return subsets sum to K
	
	Given an array A of size n and an integer K, return all subsets of A which sum to K.
	Subsets are of length varying from 0 to n, that contain elements of the array. 
	But the order of elements should remain same as in the input array.
	
	Sample Input :
			9 
			5 12 3 17 1 18 15 3 17 
			6
			
	Sample Output :
	
			3 3
			5 1
	
*/

#include<iostream>
using namespace std;

int SubsetSumtoK(int input[], int length, int output[][30], int k){
	if(length==0){
		if(k==0){
			output[0][0] = 0;
			return 1;
		}
		else{
			return 0;
		}
	}
	
	int output1[100][30];
	int output2[100][30];
	
	int s1 = SubsetSumtoK(input+1, length-1, output1, k-input[0]);
	int s2 = SubsetSumtoK(input+1, length-1, output2, k);
	
	for(int i=0; i<s1; i++){
		output[i][0] = output1[i][0]+1;
		output[i][1] = input[0];
		for(int k=1; k<=output1[i][0]; k++){
			output[i][k+1] = output1[i][k];
		}
	}
	
	
	for(int i=0; i<s2; i++){
		for(int j=0; j<=output2[i][0]; j++){
			output[i+s1][j] = output2[i][j];
		}
	}
		return s1+s2;
}


int main(){
	int n;
	int input[100];
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	
	int output[100][30];
	int size = SubsetSumtoK(input, n, output, k);
	
	for(int i=0; i<size; i++){
		for(int k=1; k<=output[i][0]; k++){
			
			cout << output[i][k] << " ";
		}
		cout << endl;
	}
		
}


