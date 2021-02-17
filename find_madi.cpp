#include <iostream>
#include <string.h>
#define MAXIMUM_LEN 30
#define MAXIMUM_MADI 10

using namespace std;

bool verification(char* string_letter, int madi_length, int string_length);

int main(int argc, char** argv)
{
	int test_case;
	int T;
    char string_letter[30];
    char first_letter;
    int string_length;
    int madi_length;
    
	//freopen("input.txt", "r", stdin);
    cin>>T;
	for(test_case = 1; test_case <= T; test_case++)
	{
        cin>>string_letter;
        first_letter = string_letter[0]; // 첫번째 글자 저장
        cout << "#" << test_case << " " ;
        string_length = strlen(string_letter);
        if(string_length>MAXIMUM_LEN)
        {
            cout << "Error : " << test_case << " letter string over 30";
            cout << " : " << strlen(string_letter) << endl;
            continue;
    	}
        for( int i=1 ; i<10 ; i++)
        {
            if( first_letter==string_letter[i] && verification(string_letter, i, string_length) )
            {
                madi_length = i;
            	break;
            }
        }
    	cout << madi_length <<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

bool verification(char* string_letter, int madi_length, int string_length)//n씩띄어서 맞는지 확인
{
    int max_jump = string_length / madi_length;
    int first_letter = string_letter[0];
    for(int i=1 ; i<max_jump ; i++)
    {
     	if(first_letter != string_letter[madi_length * i])
        	return false; 
    }
    return true;
}
