/*
	Sort an array A using Quick Sort.
	Line 1 : Integer n i.e. Array size
	Line 2 : Array elements (separated by space)
	
	Sample Input 1 :
	6 
	2 6 8 5 4 3
	Sample Output 1 :
	2 3 4 5 6 8
	
	Sample Input 2 :
	5
	1 5 2 7 3
	Sample Output 2 :
	1 2 3 5 7 

*/

#include<iostream>
using namespace std;

// taking the first element and placing it in its correct position

int partition(int input[], int si, int ei){
	int count = 0;
	int firstElement = input[si];
	for(int i=si; i<=ei; i++){
		if(input[i]<firstElement){
			count++;
		}
	}
	
	int temp = input[(si+count)];
	input[(si+count)] = input[si];
	input[si] = temp;
	
	int j = ei, i = si;
	
	/* Below code in while-loop ensuring that 
		after the element positioned at its correct place
		
		it is checked that the elements before the elements all values are small and all value after is greater or equal.
		
		if that is not the case then swap
	*/
	
	while(i<=j){
		if(input[i]<firstElement){i++;}
		
		else if(input[j]>=firstElement){j--;}
		
		else{
			temp = input[i];
			input[i] = input[j];
			input[j] = temp;
			i++;
			j--;
		}
	}
	return count+si;
	
}

// recursive approach

void QsHelper(int input[], int si, int ei){
	if(si>=ei){
		return;
	}
	int c = partition(input, si, ei);
	
	// after a random element is positioned at it's correct place 
	// then calling recursion before and after consecutively.
	
	QsHelper(input, si, c-1);
	QsHelper(input, c+1, ei);
}

void QuickSort(int input[], int size){
	QsHelper(input, 0, size-1);
}

int main(){
	cout << "Enter size of the array " << endl;
	int size;
	cin >> size;
	int *array = new int[size];
	cout << "Enter the elements in the array " << endl;
	
	for(int i=0; i<size; i++){
		cin >> array[i];
	}
	
	QuickSort(array, size);
	
	for(int i=0; i<size; i++){
		cout << array[i] << " ";
	}
	
}

