#include<iostream>

using namespace std;

int verification(int n); //3의 배수 갯수를 세어줌

int main(int argc, char** argv)
{
    int number;//경우의 수
    int amount; // 3의 배수의 갯수
    
    cin>>number;
    //cout<<number;
    
    for(int i=1 ; i<=number ; i++)
    {
        amount = verification(i);
    	if(amount==0)
        	cout<<i; //3의 배수가 없으면 그냥 숫자를 출력
    	else if( amount > 0 )
        {
            for(int j=0; j<amount ; j++)
            {
                cout<<"-";
            }
        }
        else
        {
            cout<< "Error";
        	cout << "Error number = " << i << endl ;
        }
        cout<< " "; // 숫자간 띄어쓰기
    }
    

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int verification(int n)
{
    int sum=0;
    if ( n >10 )
    {
        sum += verification(n/10);
    	n -= (n/10)*10;
    }
    
    if( n%3 == 0 && n !=0 )
        return 1+sum;
    else
        return sum;
}
