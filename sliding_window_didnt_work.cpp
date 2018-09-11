#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t);
};
string Solution::minWindow(string s, string t) {
    map <char,int> count;
    set <char> tset;
    set <char> curr;
    pair <int,int> answer(0,0);
    for(auto i:t){

        count.insert(pair<char,int>(i,0));
        tset.insert(i);
    }
    int i=0,j=-1;
    while((i  < s.length()) && (j < s.length())){                      // Difference
        ++j;
        //cout<<"chk1"<<endl;
        if(tset.find(s[j]) != tset.end()){
            curr.insert(s[j]);
            ++count[s[j]];
        }

        if(tset.size() == curr.size()){
            while(true){
                //cout<<i<<endl;
                if(tset.find(s[i])!=tset.end() && count[s[i]] > 1){
                    --count[s[i]];
                    ++i;

                }
                else if(tset.find(s[i])!=tset.end() && count[s[i]] == 1 )
                {
                    answer.first = i;
                    //cout<<i<<" "<<j<<endl;
                    answer.second = j;
                    //cout<<i<<" "<<j<<endl;
                    break;
                }
                else{
                    ++i;
                }
            }
        }

    }
    if(answer.first < 0)
        return "";
    return s.substr(answer.first, answer.second + 1 - answer.first);

}
