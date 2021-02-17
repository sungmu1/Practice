#include<iostream>
#include<string.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	char* word = (char*)malloc(sizeof(char)*10);;
    int word_length=0;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << " " ;
        cin >> word;
        //cout << word;
        word_length = strlen(word);
        for(int i=0 ; i<word_length ; i++)
        {
            if( word[i] != word[word_length-1-i] )
            {
               cout << "0" << endl;
               break;
            }
            if( i ==word_length-1)
               cout << "1" << endl;
        }  
	}
    
    	free(word);  
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
