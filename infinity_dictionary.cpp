#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

bool verification(char* word_a, char* word_b);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    	char* word_a = (char *)malloc(sizeof(char)*10);
    	char* word_b = (char *)malloc(sizeof(char)*10);
		cin >> word_a;
        while(strlen(word_a) == 0)
			cin >> word_a;
        cin >> word_b;
        while(strlen(word_b) == 0)
        	cin >> word_b;
        //cout << word_a <<word_b ;
        
        if(verification(word_a, word_b))
            cout << "#" <<test_case << " Y" << endl;
        else if(!verification(word_a, word_b))
            cout << "#" <<test_case << " N" << endl;
        else
            cout << "Error : not verficate" << endl;
		free(word_a);
        free(word_b);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

bool verification(char* word_a, char* word_b)
{
    int word_a_length = strlen(word_a);
    int word_b_length = strlen(word_b);
    int blank_a =0, blank_b=0;
    int increase_a =0, increase_b=0;
    for( int i=0 ; i < word_a_length ; i++)//일단 a
    {
        if(word_a[i+blank_a] == ' ') //공백이 있을경우에는 공백을 제외하고 생각
        {
            blank_a++;
            word_a_length--;
    	}
        if(word_b[i+blank_b] == ' ') //공백이 있을경우에는 공백을 제외하고 생각
        {
            blank_b ++;
            word_b_length--;
        }
        
        increase_a = i+blank_a;
        increase_b = i+blank_b;
       // cout << increase_a << " "<< word_a[increase_a] << " " <<word_b[increase_b]<<endl;
        if(word_a[increase_a] > word_b[increase_b])
            return false;
        else if(word_a[increase_a] < word_b[increase_b])
            return true;
        else if(word_a[increase_a] == word_b[increase_b])
            continue;
        else
        {
            cout<< "Error : word is not comparable" << endl;
            return false;
        }
    }
    //앞에는 a랑 모두 같을경우
    if(word_a_length > word_b_length) //a가 b보다 길때
        return false;
    else if(word_a_length == word_b_length) //a랑 b가 길이가 같을 때
        return false;
    else //a보다 b가 길때
    {
        if(word_a_length+1 < word_b_length) //b가 a보다 글자가 2개 더 많을 때
            return true;
        //b가 a보다 글자가 1개 더 많을 때
        if(word_b[word_a_length] !='a') //1개가 a가 아닐때
          	return true;
        else if(word_b[word_a_length] == 'a') // 1개가 a일때
        	return false;
    }
}
