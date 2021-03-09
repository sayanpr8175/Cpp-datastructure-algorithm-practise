/*
	Return subset of an array 
	
	Given an integer array (of length n), find and return all the subsets of input array.
	Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
	Note : The order of subsets are not important.

	Input format :
	Line 1 : Size of array
	Line 2 : Array elements (separated by space)
	
	Sample Input:
	3
	15 20 12
	
	Sample Output:
	12 
	20 
	20 12 
	15 
	15 12 
	15 20 
	15 20 12
	
*/

#include<iostream>
using namespace std;

int subset(int input[], int size, int output[][20]){
	
	if(size==0){ 					// Base case
		output[0][0] = 0;
		return 1;
	}
	
	int ans = subset(input+1, size-1, output);   // induction 
	
	for(int i =0; i<ans; i++){
		int num_cols = output[i][0];
		output[i+ans][0] = num_cols+1;  // each row's first column holds the count of how many columns are filled in with value;
		output[i+ans][1] = input[0];      
		
		for(int j=1; j<=num_cols; j++){
			output[i+ans][j+1] = output[i][j];
		}
	}
	
	return 2*ans;
	
}

int main(){
	
	int output[3000][20], input[20];
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> input[i] ;
	}
	
	int size = subset(input, n, output);
	
	for(int i=0; i<size; i++){
		int no_cols = output[i][0];
		for(int j=1; j<=no_cols; j++){
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
	
}
