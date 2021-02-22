#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

bool dic_verification(string word_a, string word_b); //word_a와 word_b가 순차적인 사전의 단어인지 확인하는 함수
void blank_modify(string word, char* mod_word); //띄어쓰기 되어있는 단어를 띄어쓰기를 수정하는 함수

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
    scanf("%d\n",&T); //getline의 \n을 제외하여 입력을 받기 위함
	//cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string word_a,word_b;
    	//string word_a = (char *)malloc(sizeof(char)*20);
    	//string word_b = (char *)malloc(sizeof(char)*20);
        while(word_a.length() == 0) // 입력값이 공백이 아닐때까지 반복
        	getline(cin, word_a); //한줄을 통채로 입력받음
        while(word_b.length() == 0) // 입력값이 공백이 아닐때까지 반복
        	getline(cin, word_b); //한줄을 통채로 입력받음
        char* mod_a = (char *) malloc (sizeof(word_a.length()));
        char* mod_b = (char *) malloc (sizeof(word_b.length()));
        //cout <<"word_length : " << word_a.length() << word_a << "  " <<word_b <<endl ;
        blank_modify(word_a, mod_a);
		blank_modify(word_b, mod_b);
        //cout <<"mod_length : " << strlen(mod_a) << mod_a << "  " <<mod_b <<endl ;
        
        //cout << "mod_a : " << mod_a << ", ";
        //cout << "mod_b : " << mod_b << endl;
        if(dic_verification(mod_a, mod_b))
            cout << "#" <<test_case << " Y" << endl;
        else if(!dic_verification(mod_a, mod_b))
            cout << "#" <<test_case << " N" << endl;
        else
            cout << "#" << test_case << "error : not verificate" << endl;
        
        free(mod_a);
        free(mod_b);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

bool dic_verification(string word_a, string word_b)
{
    int word_a_length = word_a.length();
    int word_b_length = word_b.length();
    for( int i=0 ; i < word_a_length ; i++)//일단 a의 길이만큼 비교
    {
        if(word_a[i] > word_b[i]) //a가 b보다 순서가 뒤면 무조건 오답
            return false;
        else if(word_a[i] < word_b[i])//a가 b보다 순서가 앞이면 무조건 정답
            return true;
        else if(word_a[i] == word_b[i]) //계속 같은 단어일 경우에는 계속 이어나감
            continue;
        else
        {
            cout<< "Error : word is not comparable" << endl;
            return false;
        }
    }
    //a단어의 길이만큼은 같았다면
    if(word_a_length > word_b_length)
        return false;
    else if(word_a_length == word_b_length)
        return false;
    else
    {
        for(int i=word_a_length ; i<word_b_length ; i++)
        {
            if(word_b[i] !='a')
            	return true;
        }
        return false;
    }
}

void blank_modify(string word, char* mod_word)
{
    int word_length = word.length();
    short blank_count =0;
    
    for(int i=0 ; i < word_length ; i++)
    {
        if( word[i+blank_count] == ' ' )
            blank_count ++;
       mod_word[i] = word[i+blank_count];
    }
}
