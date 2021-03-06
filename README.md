# Maze
미로 그리고 찾기 (스택 응용)

해결 방법>
1. 미로 그리기
-> 이차원 배열로 구성
-> 숫자로 출력 방식 지정
(0: 통로, 1: 벽, 2: 지나간 자리, 3: 되돌아간 길)
-> 되돌아간 길은 지우기 위해 공백으로 출력
-> 다른 함수에서 push나 pop할 때마다 미로에서 접근하여 숫자 변경해주기 위해 공용 공간에 생성

2. 스택에 저장하는 변수를 x, y의 현재 위치(좌표)를 저장하기 위해 구조체 Element 구성
-> typedef struct { //위치 정보 구조체
	int x;
	int y;
} Element;

3. 필요한 함수
-> 미로 출력 함수 
void printmaze()
-> 탈출구 탐색 함수
-> 앞으로 이동 함수
    탐색함수와 이동 함수는 main에.. 
이유: 탐색하고 탈출구 개수와 방향 2가지 정보를 얻고 이동, push를 한꺼번에 수행하기 위해서
-> 되돌아가기 함수
   Element back(Stack *pstack, Element cur);

알고리즘 순서>
1. 처음 자리 (1,1) 초기화, 스택 생성 및 연결 
1. 목적지에 달성했는지 확인
-> True: 목적지 달성 출력, 미로 출력, 함수 종료
-> False: 
갈 수 있는 길 탐색 및 이동, 갔던 자리 2으로 표시, Push로 현재 위치 스택에 저장
막다른 길이라면 돌아가기, Pop으로 이전 위치 가져오기, 되돌아간 길 3으로 표시 
* 모든 위치를 push하는 이유: 갈림길이 2개 이상인 곳만 저장하면 막다른 길까지 지나갔던 자리가 다 2로 저장되지만 돌아오는 건 갈림길이 2개 이상인 곳만 3으로 바뀌여서 그 사이(막다른 길~ 갈림길 2개 이상인 곳)의 2가 3으로 변하지 않는다.
<div>
<img width ="300" src="https://user-images.githubusercontent.com/60779441/77487169-13c30b80-6e75-11ea-8554-192a54a4b593.png">
<img width ="300" src="https://user-images.githubusercontent.com/60779441/77487179-1c1b4680-6e75-11ea-9a65-d6d2074627c0.png">
<img width ="300" src="https://user-images.githubusercontent.com/60779441/77487414-c3987900-6e75-11ea-8814-bbe4cf3acc5a.png">
</div>	

출력 화면
<div>
<img width ="300" src="https://user-images.githubusercontent.com/60779441/77487426-c85d2d00-6e75-11ea-8ff1-5c54bd8c1f6d.png">
<img width ="300" src="https://user-images.githubusercontent.com/60779441/77487432-cabf8700-6e75-11ea-8534-5612a38c0c9d.png">
<img width ="300" src="https://user-images.githubusercontent.com/60779441/77487437-ceeba480-6e75-11ea-978b-eb4da7829a3e.png">
</div>

결과 화면
<div>
<img src="https://user-images.githubusercontent.com/60779441/77487444-d1e69500-6e75-11ea-9447-c9a7d0a27a39.png">
</div>
