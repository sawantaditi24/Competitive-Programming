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
