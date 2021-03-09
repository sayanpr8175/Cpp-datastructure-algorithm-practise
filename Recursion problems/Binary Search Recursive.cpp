/*
	Binary Search (Recursive)
	
	Given an integer sorted array (sorted in increasing order) and an element x,
	find the x in given array using binary search. Return the index of x.
	Return -1 if x is not present in the given array.
	Note : If given array size is even, take first mid.

	Input format :

	Line 1 : Array size

	Line 2 : Array elements (separated by space)

	Line 3 : x (element to be searched)
	
	Sample Input:
	
		6
		2 3 4 5 6 8 
		5 
	
	Sample Output:
		3

*/

#include<iostream>
using namespace std;

int BinarySearchHelper(int arr[], int start, int end, int k){
	if(start > end){
		return -1;		//  Base Case
	}
	
	int mid = (start+end)/2;
	
	// If Value found or not ?
	
	if(arr[mid] == k) {   	
		return mid;
	}
	
	// If value is smaller, then search in left side from mid 
	
	else if(arr[mid]>k){
		return BinarySearchHelper(arr, start, mid-1, k);
	}
	
	// If value is greater, then search in right side from mid
	
	else if(arr[mid]<k){
		return BinarySearchHelper(arr, mid+1, end, k );
	}
	
}

int BinarySearch(int arr[], int size , int k){
	int start = 0;
	int end = size-1;
	
	int index = BinarySearchHelper(arr, start, end, k);
	return index;
}


int main(){
	
	int n;
	cin >> n;
	
	int * arr = new int[n];
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	cout << "Enter the element to be searched " << endl;
	int k;
	cin >> k;
	
	cout << BinarySearch(arr, n, k) << endl;
	
}
