#include<vector>
#include<iostream>
using namespace std;


int totalFruit(vector<int>& fruits) {
    int max_count = 0;
    int start_idx = 0;
    cout<<fruits.size();
    /*while(start_idx<fruits.size())
    {
        int next_idx = start_idx+1;
        int count = 0;
        int a = fruits[start_idx];
        while(fruits[next_idx]==fruits[start_idx] && next_idx<fruits.size())
        {
            next_idx++;
            count++;
        }
        int another_element = next_idx;
        cout<<another_element<<endl;
        while(fruits[another_element]==fruits[start_idx] || fruits[next_idx]==fruits[another_element])
        {
            if(another_element>=fruits.size())break;
            another_element++;
            count++;
            //cout<<"here"<<endl;
        }
        if(count>max_count)
        {
            max_count=count;
            start_idx = next_idx;
        }
        start_idx++;

    }*/
    return max_count;
    
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
        v.push_back(1);
        // v.push_back(2);
        // v.push_back(3);
        // v.push_back(2);
        // v.push_back(1);
 
    for(int i=0;i<v.size();i++)
        cout << v[i] << " ";
    cout<<endl;
    int num = totalFruit(v);
    cout<<num<<endl;
    return 0;
}
