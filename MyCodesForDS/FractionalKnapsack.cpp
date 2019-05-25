//Implementation of Fractional Knapsack

struct Item
{
    int value, weight;
    Item(int value, int weight): value(value), weight(weight)
    {}
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value/a.weight;
    
    double r2 = (double)b.value/b.weight;
    
    return r1 > r2;
}

double fk(int W, struct Item arr[], int n)
{
    int curWeight = 0;
    //holds the current weight of knapsack, to check for overflow condition
    double finalValue = 0;
    //indicates final value of the knapsack, to be incremented at every addition of weight
    
    for(int i = 0 ; i < n ; i++)
    {
        if(curWeight + arr[i].weight <= W)
        {
            //Complete addition of Item
            curWeight += arr[i].weight;
            finalValue == arr[i].value;
        }
        else
        {
            //adding item fractionally
            int remain = W - curWeight;
            //This is the amount of weight to be added fractionally
            finalValue += arr[i].value*((double)remain/arr[i].weight);
            //the second multiplicand refers to the fraction of the item included in the knapsack
            break;
        }
    }
    return finalValue;
}
