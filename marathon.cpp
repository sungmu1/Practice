#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int par_number = participant.size();
    vector<string> par(participant);
    for(int i=0 ; i < par_number; i++)//참여자를 모두 비교
    {
        vector<string> com(completion);
        //cout << "com.size : " << com.size() << endl;
        int com_size = com.size();
        int erase_v = com.size()-1;
        if(com_size ==0)
            return par.back();
        for(int j=0 ; j<com_size; j++)//완주자를 모두 비교
        {
            //cout << par.back().compare(com.back()) << endl;
            //if(strcmp(par.back(),com.back()))//참여자중에 완주자가 있다면
            if(par.back().compare(com.back())==0)
            {
                par.pop_back();
                completion.erase(completion.begin() + erase_v);
                break;
            }
            erase_v--;
            if(j==com_size-1)//참여자 한명이 완주자에 없을때
                return par.back();
            com.pop_back();//임시 완주자에서 하나를 뺌
        }
    }
}
