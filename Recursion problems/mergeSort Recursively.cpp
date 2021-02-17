#include <iostream>
using namespace std;

void merge(int a[], int startIndex, int endIndex){
	int arr[10000];
	int mid = (startIndex+endIndex)/2;
	int i = startIndex;
	int j = mid+1;
	int k = startIndex;
	
	while(i<=mid && j<=endIndex){
		if(a[i]<a[j]){
			arr[k] = a[i];
			k++; i++;
		}
		
		else if(a[j]<a[i]){
			
			arr[k] = a[j];
			k++; j++;
		}
		
		else{
			arr[k] = a[i]; k++; i++;
			arr[k] = a[j]; k++; j++;
		}
	}
	
		while(i<=mid){
			arr[k] = a[i];
			k++; i++;
		}
		
		while(j<=endIndex){
			arr[k] = a[j];
			k++; j++;
		}
		
		for(int i=startIndex; i<=endIndex; i++){
			a[i] = arr[i];
		}

}

void mergeSort(int a[], int startIndex, int endIndex){
	// base case
	if(startIndex>=endIndex){
		return;
	}
	
	int mid = (startIndex+endIndex)/2;
	
	mergeSort(a, startIndex, mid);
	mergeSort(a, mid+1, endIndex);
	
	merge(a, startIndex, endIndex);
	
}

void mergeSortPass(int a[], int size){
	// nothing to sort case
	if(size==0 || size==1){
		return;
	}
	
	mergeSort(a, 0, size-1);
}

int main(){
	cout << "Enter the size of the array " << endl;
	int size;
	cin >> size;
	int * arr = new int[size];
	cout << "enter elements in the array " << endl;
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}
	
	mergeSortPass(arr, size);
	
	cout << endl;
	
	for(int i=0; i<size; i++){
		cout << arr[i] << " ";
	}
	
}
