class Solution {
public:
// bool issafe(int row,int col,vector<string>&board,int n){////Q 
//     // up diagonal
//     int dupcol=col;
//     int duprow=row;
//     while(row>=0 && col>=0){
//         if(board[row][col]=='Q')return false;
//         row--;
//         col--;
//     }
//     // left arrow   (<-)
//     col=dupcol;
//     row=duprow;
//     while(col>=0){
//         if(board[row][col]=='Q')return false;
//         col--;
//     }
//     //     // low diagonal

//     col=dupcol;
//     row=duprow;
//     while(row<n && col>=0){
//     if(board[row][col]=='Q')return false;
//     col--;
//     row++;
//     }
//     return true;
// }
// void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
//     if(col==n){
//         ans.push_back(board);
//         return ;
//     }
//     for(int row=0;row<n;row++){
//         if(issafe(row,col,board,n)){
//             board[row][col]='Q';
//             solve(col+1,board,ans,n);
//             board[row][col]='.';
//         }
//     }
// }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>>ans;
//         vector<string>board(n);
//         string s(n,'.');
//         for(int i=0;i<n;i++){
//             board[i]=s;
//         }
//         solve(0,board,ans,n);
//         return ans;
        
//     }


// approach2
void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};