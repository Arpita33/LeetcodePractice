#include<iostream>
#include<vector>
#include<map>
#include<set>
//#include<priority_queue>
using namespace std;

class PhoneDirectory {
    set<int> numbers;
public:
    PhoneDirectory(int maxNumbers) {
        for(int i=0;i<maxNumbers;i++)
        {
            numbers.insert(i);
        }
    }
    
    int get() {
        if (!numbers.empty()) 
        {
            int firstElement = *numbers.begin();
            numbers.erase(numbers.begin());
            return firstElement;
        }
        else
        {
            return -1;
        }
    }
    
    bool check(int number) {
        auto it = numbers.find(number);
        if (it != numbers.end()) { //exists in the set
             return true;
        }
        else
        {
            return false;
        }
        
    }
    
    void release(int number) {
        numbers.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */

int main()
{
    PhoneDirectory pd(5);
    cout<<pd.get()<<endl;
    cout<<pd.check(4)<<endl;
    cout<<pd.get()<<endl;
    cout<<pd.check(1)<<endl;
}