//The following is a basic implementation of the Knight's Tour Algorithm through BackTracking

int solveKTUtil(int x, int y, int movei, int sol[n][n], int xmove[n]. int ymove[n])
{
    int k, next_x, next_y;
    if(movei == n*n)
      //n*n means the total number of squares on the chessboard
      //movei = n*n means that all moves are accommodated
        return true;
  //Now, there are 8 possible moves for a knight(which moves in L shaped fashion)
  //We try to check feasibility of all the 8 moves from the current position (x, y)
  for(k = 0 ; k < 8 ; k++)
  {
    next_x = x + xMove[k];
    next_y = y + yMove[k];
    if()
  }
}
