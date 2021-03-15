
#sys.stdin = open(&quot;input.txt&quot;, &quot;r&quot;)
result = [
	"Game has not completed",
	"Draw",
	"O won",
	"X won"
]# 결과를 출력할 리스트

#O_ok = [&apos;O&apos;,&apos;O&apos;,&apos;O&apos;,&apos;O&apos;]
#X_ok = [&apos;X&apos;,&apos;X&apos;,&apos;X&apos;,&apos;X&apos;]
'''
return값
0 : 게임 안끝남
1 : 무승부
2 : O 가 이김
3 : X 가 이김
'''
def four_validate(four_array) :
	tmp = 't' #여기서 t는 통과하라는 의미
	for y in four_array:
		if y =='.' :
			tmp = 'f'
			break;
		elif y =='O' and (tmp == 'O' or tmp == 't') : tmp ='O'  #이전에 통과였는데 O라면
		elif y =='X' and (tmp == 'X' or tmp == 't') : tmp = 'X' #이전에 통과였는데 X라면
		elif y =='T'  : tmp = tmp
		elif tmp != y :
			tmp = 'f'
			break;
	if tmp == 'O': return 2
	elif tmp == 'X': return 3
	else : return 0
        
def validate_tictacto(tictacto) :
	#가로 판명
	for  x in tictacto:
		result = four_validate(x)
		if result == 2 or result == 3 : return result
	#세로 판명
	tmp = [] #임시방편으로 넣어줄 배열
	for i in range(0,4):
		for x in tictacto:
			tmp.append(x[i])
		result = four_validate(tmp)
		if result == 2 or result == 3 : return result
		tmp.clear()
	#대각선 판명
	left = 0
	right =3
	tmp1 = []
	tmp2 = []
	for x in tictacto :
		tmp1.append(x[left])
		tmp2.append(x[right])
		left = left+1
		right = right-1
	result = four_validate(tmp1)
	if result == 2 or result == 3 : return result
	result = four_validate(tmp2)
	if result == 2 or result == 3 : return result
	tmp1.clear()
	tmp2.clear()
	#무승부
	for x in tictacto:
		for y in x:
			if y == '.' : return 0
	#게임이 안끝남
	return 1

T = int(input())

column, row = 4, 4

for test_case in range(1, T + 1):
	tictacto = [ list(input()) for _ in range(column) ] #틱택토 이차배열 정의
    #validate함수로 현재 결과를 확인
	print('#{} {}'.format(test_case, result[ validate_tictacto(tictacto) ]))
	#blank처리
	if test_case != T and input() != '' :
		print('Error')

