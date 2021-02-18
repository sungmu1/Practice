#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;//test_case
    short attack_count=0; // n의 크기만큼의 증가율 합산(maximum 4950)
    short attack, damage;
    double skill;
    int all_damage=0;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << " ";
		cin >> damage;
        cin >> skill;
        cin >> attack;
        //cout << "damage = " << damage << ",skill = " << skill << ",attack = " << attack << ", ";
        attack_count+=(attack-1)*attack/2;
        all_damage = damage * ( attack+ attack_count *skill/100 );
        cout<<all_damage<< endl;
        //printf("%f\n",all_damage);
        all_damage=0;
        attack_count=0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
