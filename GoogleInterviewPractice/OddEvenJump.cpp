#include <vector>
using namespace std;
#include<iostream>
/*
Got TLE,
This is a naive solution.
Working on a better solution with memoization to pass time limit.
*/
int Jump(int start_idx, vector<int>& arr, int NumOfJump)
{
    int elements = arr.size();
    if(start_idx==elements-1)
    {
        return 1;
    }
    if(NumOfJump%2==1)//odd jump
    {
        //cout<<"here"<<endl;
        int j=start_idx;
        for(int i=start_idx+1;i<elements;i++)
        {
            //cout<<arr[start_idx]<<" "<<arr[i]<<endl;
            if(arr[start_idx]<=arr[i])
            {
                //cout<<"passed first cond"<<endl;
                if(j!=start_idx)
                {
                    if(arr[i]<arr[j])
                    {
                        //cout<<"passed second cond"<<endl;
                        j=i;
                    }
                    
                }
                else
                {
                    j=i;
                }
            }
        }
        if(j>start_idx)
        {
            //cout<<"Jumped to "<<j<<endl;
            return Jump(j,arr,NumOfJump+1);
        }
        else
        {
            return 0;
        }
    }
    else if (NumOfJump%2==0) //even jump
    {
        /* code */
        int j=start_idx;
        for(int i=start_idx+1;i<elements;i++)
        {
            if(arr[start_idx]>=arr[i])
            {
                // if(arr[i]>arr[j])
                // {
                //     j=i;
                // }
                if(j!=start_idx)
                {
                    if(arr[i]>arr[j])
                    {
                        //cout<<"passed second cond"<<endl;
                        j=i;
                    }
                    
                }
                else
                {
                    j=i;
                }
            }
        }
        if(j>start_idx)
        {
            //cout<<"Jumped to "<<j<<endl;
            return Jump(j,arr,NumOfJump+1);
        }
        else
        {
            return 0;
        }

    }
    return 0;
    
}
int NumGoodIndices(vector<int>& arr)
{
    int total = 0;
    for(int i=0;i<arr.size();i++)
    //for(int i=0;i<1;i++)
    {
        int jump = Jump(i,arr,1);
        cout<<i<<" "<<arr[i]<<" "<<jump<<endl;
        total+=jump;
    }
    return total;
}
int main()
{
    // vector<int> v{2, 3, 1, 1, 4};
    // int num = NumGoodIndices(v);
    // //cout<<"here"<<endl;
    // cout<<num<<endl;
        vector<int> v;
        // v.push_back(2);
        // v.push_back(3);
        // v.push_back(1);
        // v.push_back(1);
        // v.push_back(4);
        v.push_back(81);
        v.push_back(54);
        v.push_back(96);
        v.push_back(60);
        v.push_back(58);
 
    for(int i=0;i<v.size();i++)
        cout << v[i] << " ";
    cout<<endl;
    int num = NumGoodIndices(v);
    cout<<num<<endl;
    return 0;
}
