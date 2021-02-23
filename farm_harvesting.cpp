#include<iostream>

using namespace std;

void char_to_int(string str, int* arr);

int main(int argc, char** argv)
{
	int test_case;
	static int T;
    short farm; // 농장의 크기
	
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d\n",&farm);
        string farm_width_char;// 한줄을 받을 농장 가로의 char형 배열
        short farm_middle = farm/2; //farm의 중간값
        short start = farm_middle; //한줄마다 시작의 위치
    	short cont=1; //continuos 한줄에서 연속으로 캐는 횟수
        int sum=0; // 농산물 합산
        
        for(int i=0; i < farm ; i++) // farm의 세로수만큼
        {
        	int* farm_width = (int *)malloc(sizeof(int)*farm); // 한줄을 받을 농장 가로의 int형 배열
            getline(cin,farm_width_char);
            char_to_int(farm_width_char, farm_width);
            
         	if( i < farm/2)//세로길이 중간전까지
            {
                for(int j=0 ; j <cont ; j++)
                    sum += farm_width[ start+j ];
                cont += 2;
                start --;
            }
            else if( i == farm/2)//세로길이 중간
            {
                for(int j=0; j < farm ; j++)
                    sum += farm_width[j];
            }
            else //세로길이 중간 넘길 때
            {
                cont -=2;
                start++;
                for(int j=0 ; j<cont ; j++)
                    sum += farm_width[start+j];
            }
            free(farm_width);
        }
        cout << "#" <<test_case << " " << sum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void char_to_int(string str, int* arr)
{
    for(int i=0 ; i < str.length() ; i++)
        arr[i] = str[i]-48;
}
