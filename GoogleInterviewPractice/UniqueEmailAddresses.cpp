#include <vector>
#include <map>
using namespace std;
#include<iostream>
int numUniqueEmails(vector<string>& emails) {
        map<string,int> a;
        int total_diff = 0;
        for (auto & email : emails) 
        {
            //cout<<element<<endl;
            string domain = email.substr(email.find("@") + 1);
            string new_email = "";
            int i=0;
            while(email[i]!='@'){ 
                
                if(email[i]=='.')
                {
                    i++; //ignore '.' in local name
                }
                
                
                if(email[i]=='+')
                {
                    break;  //ignore everything including and after '+'
                }
                new_email=new_email+email[i];
                i++;
            } 
            new_email = new_email+"@"+domain;
            if(a.find( new_email ) != a.end()) //if email already exists just increase count in map
            {
                a[new_email]+=1;
                
            }
            else
            {
                a[new_email]=1;
                total_diff+=1; // otherwise add it to unique email count
            }
        }
        return total_diff;
    }

int main()
{
    vector<string> emails;
    string a,b,c;
    a = "test.email+alex@leetcode.com";
    b = "test.e.mail+bob.cathy@leetcode.com";
    c = "testemail+david@lee.tcode.com"; 
    emails.push_back(a);
    emails.push_back(b);
    emails.push_back(c);
    int total_unique_emails = numUniqueEmails(emails);
    cout<<total_unique_emails<<endl;

}