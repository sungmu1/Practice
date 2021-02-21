#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

bool verification(char* word_a, char* word_b);
void blank_modify(char* word);

int main(int argc, char** argv)
{
	int test_case;
	int T;
    char* word_a = (char *)malloc(sizeof(char)*10);
    char* word_b = (char *)malloc(sizeof(char)*10);
	
	//freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> word_a;
        cin >> word_b;
        blank_modify(word_a);
		blank_modify(word_b);
        if(verification(word_a, word_b))
            cout << "#" <<test_case << " Y" << endl;
        else if(!verification(word_a, word_b))
            cout << "#" <<test_case << " N" << endl;
        else
            cout << "Error : not verficate" << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

bool verification(char* word_a, char* word_b)
{
    int word_a_length = strlen(word_a);
    int word_b_length = strlen(word_b);
    for( int i=0 ; i < word_a_length ; i++)//일단 a
    {
        if(word_a[i] > word_b[i])
            return false;
        else if(word_a[i] < word_b[i])
            return true;
        else if(word_a[i] == word_b[i])
            continue;
        else
        {
            cout<< "Error : word is not comparable" << endl;
            return false;
        }
    }
    
    if(word_a_length > word_b_length)
        return false;
    else if(word_a_length == word_b_length)
        return false;
    else
    {
        if(word_b[word_a_length] =='a')
            return false;
        return true;
    }
}

void blank_modify(char* word)
{
    int word_length = strlen(word);
    short blank_count =0;
    for(int i=0 ; i < word_length ; i++)
    {
        if( word[i] == ' ' )
        {
            for(int j=i ; j< strlen(word)-1-blank_count ; j++)
                word[j] = word[j+1];
            word[ strlen(word)-1-blank_count ] = ' ';
            blank_count++;
        }
    }
    cout << word<<endl;
}
