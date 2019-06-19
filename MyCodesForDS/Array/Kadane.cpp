#include<bits/stdc++.h>
using namespace std;

int kadane1(int a[], int size)
{
    //returns the sum of the contiguous subarray with max sum
    
    int mSF = -99999;
    int mEH = 0;
    for(int i = 0 ; i < size; i++)
    {
        mEH += a[i];
        if(mSF < mEH)
            mSF = mEH;
        if(mEH < 0)
            mEH = 0;
    }
    return mSF;
}


int kadane2(int a[], int size)
{
    //returns the sum of the contiguous subarray with max sum
    
    int mSF = -99999;
    int mEH = 0;
    for(int i = 0 ; i < size; i++)
    {
        mEH += a[i];
        if(mEH < 0)
            mEH = 0;
    
        else if(mSF < mEH)
            mSF = mEH;
    }
    return mSF;
}


//Allowing all negative

int lCS(int a[], int size)
{
    int curr = a[0];
    int mSF = a[0];
    
    for(int i = 1 ; i < size ; i++)
    {
        curr = max(a[i], curr + a[i]);
        mSF = max(curr, mSF);
    }
    return mSF;
}

//To print the subarray


int kadaneWithPrint(int a[], int size)
{
    //returns the sum of the contiguous subarray with max sum
    
    int mSF = -99999;
    int mEH = 0;
    int start = 0 ; end = 0; s = 0;
    for(int i = 0 ; i < size; i++)
    {
        mEH += a[i];
        if(mSF < mEH)
        {
            mSF = mEH;
            start = s;
            end = i;
        }
        if(mEH < 0)
        {
            mEH = 0;
            s = i + 1;
        }    
    }
    return mSF;
}

