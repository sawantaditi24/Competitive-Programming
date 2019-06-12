//Reversing the order of words in a string
//For example, 
//i love prog -> prog love i 

void reverseWords(char* s)
{
    char *word_begin = NULL;
    char *temp = s;
    while(*temp)
    {
        if(!word_begin && *temp != ' ')
            word_begin = temp;
        if(word_begin && (*(temp + 1) == ' ' || *(temp + 1) == '\0'))
        {       rev(word_begin, temp);
                word_begin NULL;
    
        }    
        *temp++;
        
    }
    rev(s, temp - 1;)
    
}

void rev(char *begin, char *end)
{
    char temp;
    while(begin < end)
    {
        temp = *begin;
        *begin = *end;
        *end = temp;
        *begin++;
        *end--;
    }
}

//////////////////////////

//Print all words possible from phone digits

void p(int number[], int n)
{
    string result[n + 1];
    //This is an array of strings, wherein every array element holds a possible combination
    result[n] = '\0';
    //string ends with '\0', which is the reason for the increased size
    pWU(number, 0, result, n);
}

string hT[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void pWU(int number[], int c_d, int output[], int n)
{
    int i;
    if(c_d == n)
    {
        //This means that all possible combinations have been added to output
        cout<<output;
        return
    }
    
    for(i = 0 ; i < hT[number[c_d]].size(); i++)
    {
        //Number array stores the digits that are pressed
        //number[c_d] represents the pressed digit we are checking for 
        //ht[number[c_d]] is a string of all possible letters that can 
        //be printed when this digit is pressed
        output[c_d] = hT[number[c_d]][i];
        pWU(number, c_d + 1, output, n);
        if(number[c_d] == 0 || number[c_d] == 1)
            return;
    }
}
