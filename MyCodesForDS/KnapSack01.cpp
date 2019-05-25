//Only contains the knapsack function
//Add input output to test
//Implementation of Bottom Up Approach for 0/1 Knapsack Problem

int kS(int W, int wt[], int val[], int n)
{
    int i, w;
    //W is total knapSack Capacity
    //wt holds weights of n items
    //val profits of n items
    //We need to select items so as to maximise profits
    //While being constrained by knapsack Capacity
    
    int K[n+1][W+1];
    //The DP table. 
    //+1 in sizes so as to include the possibility of not including any item at all 
    
    for(i = 0 ; i <=n ; i++)
    {
        for(w = 0 ; w <= W; w++)
        {
            if(i == 0 || w == 0)
                K[i][w] = 0;
                //If value is zero, no point in adding it to knapsack
                //If weight is zero, such an item cannot exist
            else if(wt[i - 1] <= w)//   if ith item can be accommodated in KS, satisfying constraint
                K[i][w] = max((val[i-1] + K[i - 1][w - wt[i - 1]]), K[i - 1][w]);
        
            else
                K[i][w] = K[i - 1][w];
        }
    }
}

