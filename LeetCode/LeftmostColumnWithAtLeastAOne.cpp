    /**
     * // This is the BinaryMatrix's API interface.
     * // You should not implement it, or speculate about its implementation
     * class BinaryMatrix {
     *   public:
     *     int get(int x, int y);
     *     vector<int> dimensions();
     * };
     */

    class Solution {
    public:
        int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) 
        {
            // Get the dimensions of the matrix
            vector<int>dims = binaryMatrix.dimensions();
            int rows = dims[0];
            int cols = dims[1];
            int ans = -1;
            int r = 0, c = cols - 1;
            //Start with topmost-rightmost element of the matrix
            while( r < rows && c >= 0) 
            {   //If it's a one, we go left
                if (binaryMatrix.get(r, c) == 1) 
                {
                    ans = c;
                    c--;
                } // If it's a zero, go down
                else 
                    r++;

            }
            return ans;

        }
    };
