#include<iostream>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int col){
	
	// column up check
	
	for(int i=row-1; i>=0 ; i--){
		if(board[i][col] == 1){
			return false;
		}
	}
	
	// Left Diagonal 
	for(int i=row-1, j = col-1; i>=0 && j>=0; i--,j--){
		if(board[i][j] == 1){
			return false;
		}
	}
	
	// Right diagonal
	for(int i=row-1, j=col+1; i>=0 && j<n; i--,j++){
		if(board[i][j]==1){
			return false;
		}
	}
	
	
	return true;
	
}


void nQueenHelper(int n, int row){
	if(row == n){
		// we have reached some solution
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << board[i][j] << " ";
			}
		}
		cout << endl;
		return;
	}
	
	for(int j=0; j<n; j++){
		if(isPossible(n, row, j)){
			board[row][j] = 1;
			nQueenHelper(n, row+1);
			board[row][j] = 0;
		}
	}
	
	return;
}


void placeNQueens(int n){
	
	// memset(board, 0, 11*11*sizeof(int));
	
	for(int i=0; i<11; i++){
		for(int j=0; j<11; j++){
			board[i][j] = 0;
		}
	}
	
	
	nQueenHelper(n, 0);
	
	
}

int main(){
	int k;
	cin >> k;
	placeNQueens(k);
	
	return 0;
	
}
