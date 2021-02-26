#include<stdio.h>
using namespace std;

int main(){
    long test_num=0;
    long test_arr[10];
    long sum=0;
    scanf("%d",&test_num);
    for(int i=0;i<test_num;i++)
    {
        for(int j=0;j<10;j++)
        {
            scanf("%d",&test_arr[j]);
            if(test_arr[j]%2)
            	sum+=test_arr[j];
        }
        //cout<<"#"<<i+1<<" "<<sum<<endl;
        printf("#%d %d\n",i+1,sum);
        sum=0;
    }
}
