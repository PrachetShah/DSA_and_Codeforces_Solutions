#include <bits/stdc++.h> 

using namespace std;

bool isSafe(int row, int col,  vector<vector<int>> &board, int n,
map<int, bool> &rowCheck, map<int, bool> &lowDiag, map<int, bool> &upDiag){
	int x = row; 
	int y=col;
	
	if(rowCheck[row]){
		return false;
	}

	x=row, y=col;
	// check diagonal
	if(lowDiag[row+col]){
		return false;
	}

	x=row, y=col;
	if(upDiag[n-1+col-row]){
		return false;
	}

	return true;
}

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
	vector<int> temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}


void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n,
 map<int, bool> &rowCheck, map<int, bool> &lowDiag, map<int, bool> &upDiag){
	if(col == n){
		addSolution(board, ans, n);
		return;
	}

	// solve 1 case, rest by recursion
	for(int row=0; row <n; row++){
		if(isSafe(row, col, board, n, rowCheck, lowDiag, upDiag)){
			board[row][col] = 1;
			rowCheck[row]=true, lowDiag[row+col]=true, upDiag[n-1+col-row]=true;
			solve(col+1, ans, board, n, rowCheck, lowDiag, upDiag);
			// backtracking
			board[row][col] = 0;
			rowCheck[row]=false, lowDiag[row+col]=false, upDiag[n-1+col-row]=false;
		}
	}
}

vector<vector<int>> nQueens(int n){
	// Write your code here
	vector<vector<int>> ans;
	vector<vector<int>> board(n, vector<int> (n, 0));
	// Using Maps to reduce time to check isSafe from O(n)->O(1)
    map<int, bool> rowCheck;
	map<int, bool> lowDiag;
	map<int, bool> upDiag;
	// col
	solve(0, ans, board, n, rowCheck, lowDiag, upDiag);

	return ans;
}