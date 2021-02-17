#include<iostream>
#include<stdlib.h>
using namespace std;

int pascal_triangle(int size);

int main(int argc, char** argv)
{
	int test_case;
	int T; //case 갯수
    int size;//삼각형의 크기
	
	cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> size;
        cout << "#" << test_case << endl ;
        pascal_triangle(size);
	}
	return 0;//정상종료시 반
}

int pascal_triangle(int size)
{
    int *active = (int*)malloc(sizeof(int)*10);
    int *save = (int*)malloc(sizeof(int)*10);
    int tmp=0;
    for(int i=0 ; i<size ; i++)
    {
        for(int j=0 ; j<i+1 ; j++)
        {
             if( j == i )
            {    
                active[j] = 1;
                cout << 1 << endl;
            }
            else if( j  == 0)
            {
                active[j] = 1;
                cout << 1 << " ";
            }
            else
            {
                tmp += save[j-1];
                tmp += save[j];
                active[j] = tmp;
                cout << tmp << " ";
                tmp =0;
            }
        }
    		for(int k=0 ; k<i+1 ;k++)
            {	
            	save[k] = active[k];
            }
    }
	free(active);
	free(save);
}
