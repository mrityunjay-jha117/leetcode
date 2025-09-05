// // brute-force o(n^2)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==target)return true;
//             }
//         }
//         return false;
// }
// };
// binary search o(nlogm)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         for(int i=0;i<n;i++){
//             int low=0;
//             int high=m-1;
//             while(low<=high){
//                 int mid=(high-low)/2+low;
//                 if(target==matrix[i][mid])return true;
//                 if(target>matrix[i][mid])low=mid+1;
//                 else high=mid-1;
//             }
//         }
//         return false;
// }
// };
// the staircase method o(m+n)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         int i=0,j=m-1;
//         while(i<n && j>=0){
//             if(matrix[i][j]==target)return true;
//             else if(matrix[i][j]>target){j--;}
//             else if(matrix[i][j]<target){i++;}
//         }
//         return false;
//     }
// };
// something bizzare doing recursin with dnc
// https://leetcode.com/problems/search-a-2d-matrix-ii/solutions/6225324
// divide-and-conquer-solution-for-interviews
class Solution {
public:
    bool func(vector<vector<int>>& matrix, int ai, int aj, int bi, int bj, int target) {
        if (ai > bi || aj > bj) return false;

        // submatrix range check
        if (target < matrix[ai][aj] || target > matrix[bi][bj]) return false;

        int midrow = (ai + bi) / 2;
        int midcol = (aj + bj) / 2;

        if (matrix[midrow][midcol] == target) return true;

        if (matrix[midrow][midcol] > target) {
            // search top-left, top-right (excluding midcol), bottom-left (excluding midrow)
            return func(matrix, ai, aj, midrow - 1, bj, target) || 
                   func(matrix, midrow, aj, bi, midcol - 1, target);
        } else {
            // search bottom-right, bottom-left (excluding midcol), top-right (excluding midrow)
            return func(matrix, ai, midcol + 1, bi, bj, target) || 
                   func(matrix, midrow + 1, aj, bi, midcol, target);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        return func(matrix, 0, 0, n - 1, m - 1, target);
    }
};
