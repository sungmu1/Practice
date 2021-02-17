#include<iostream>
#define PARI_MINIMUM 5
#define PARI_MAXIMUM 15
#define PARICHE_MINIMUM 2

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;// test_case
    int pari_square, pariche_square; // 파리와 파리채 크기(정사각형)
    int strong_pari=0; //제일 값이 큰 파리
	int tmp;
    int** pari;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
        cin >> pari_square;
        cin >> pariche_square;
        pari = (int**)malloc(sizeof(int*)*pari_square);
        for(int pari_width =0 ; pari_width<pari_square ; pari_width++)
            pari[pari_width] = (int*)malloc(sizeof(int)*pari_square);
        
        for(int i=0 ; i<pari_square ; i++)
        {
            for(int j=0 ; j<pari_square; j++)
            {
                cin >> tmp;
            	if(tmp == 32) // 입력이 " "(공백)일 경우에 건너뛰기
                	continue;
            	pari[i][j] = tmp ;
                //cout << pari[i][j] << " ";
            }
            //cout << endl;
        }
        tmp =0;
        
        for(int i=0 ; i<=pari_square-pariche_square; i++)
        {
            for(int j=0 ; j<=pari_square-pariche_square; j++)
        	{
                for(int k=0; k<pariche_square ; k++)
                {
                    for(int l=0; l<pariche_square; l++)
                   		tmp += pari[i+k][j+l];
                }
                if(tmp > strong_pari)
                    strong_pari = tmp;
                tmp = 0;
        	}
        }
        cout << strong_pari << endl;
        strong_pari=0;
        for(int pari_width =0 ; pari_width<pari_square ; pari_width++)
            free(pari[pari_width]);
        free(pari);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
