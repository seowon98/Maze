#define MAX_STACK_SIZE 100
#define True 1
#define False 0
#define Error -1

#include<stdio.h>
#include<stdlib.h>

int maze[23][19] = //미로
{
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1 },
{ 1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1 },
{ 1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1 },
{ 1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1 },//5
{ 1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1 },
{ 1,0,1,1,1,0,1,0,0,0,1,1,1,0,1,1,1,0,1 },
{ 1,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,0,0,1 },
{ 1,0,1,0,1,0,0,0,1,1,1,1,1,1,1,0,1,1,1 },
{ 1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1 },//10
{ 1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1 },
{ 1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1 },
{ 1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1 },//13
{ 1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1 },
{ 1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1 },//15
{ 1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1 },
{ 1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1 },
{ 1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1 },
{ 1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1 },
{ 1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1 },//20
{ 1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1 },
{ 1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }//23
};

typedef int Bool;

typedef struct { //위치 정보 구조체
	int x;
	int y;
}Element;

typedef struct {  //스택
	Element stackArr[MAX_STACK_SIZE];
	int top;
}Stack;

Stack *Create() { //스택 생성
	Stack *tempstack;

	tempstack = (Stack *)malloc(sizeof(Stack)); //동적할당
	tempstack->top = -1; //top
	return tempstack;
}

Bool isEmpty(Stack *pstack) { //스택 비었는지 확인
	if (pstack->top == -1) return True;
}

Bool isFull(Stack *pstack) {
	if (pstack->top == MAX_STACK_SIZE - 1) return True;
	else return False;

}

void Push(Stack *pstack, Element Data) { //스택에 저장
	if (isEmpty(pstack)) { //비었는지 확인
		(pstack->top)++; //top 올리고
		pstack->stackArr[pstack->top].x = Data.x; 
		pstack->stackArr[pstack->top].y = Data.y;

		printf("      Push(%d,%d)\n", pstack->stackArr[pstack->top].x, pstack->stackArr[pstack->top].y);
	}
	else printf("스택이 가득찼습니다.\n");
}

Element Pop(Stack *pstack) {
	if (isEmpty(pstack)) {
		printf("      Pop(%d,%d)\n", pstack->stackArr[pstack->top].x, pstack->stackArr[pstack->top].y);
		return pstack->stackArr[pstack->top--]; //스택 값 돌려주기
	}
	else printf("스택이 비었습니다\n");
}

void printmaze() //미로 출력 함수
{
	int i, j;

	for (i = 0; i < 23; i++) {
		for (j = 0; j < 19; j++) {

			switch (maze[i][j]) {
			case 0: //통로
				printf("  ");
				break;
			case 1: //벽
				printf("■");
				break;
			case 2: //경로
				printf("○");
				break;
			case 3: //다시 돌아온 길
				printf("  ");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}

}

Element back(Stack *pstack, Element cur); //되돌아가는 함수

int main()
{
	printf("          <<<<<<미로 찾기 시작>>>>>>>>\n\n");

	Stack *pstack;
	pstack = Create(); //스택 생성

	Element cur;
	cur.x = 1;
	cur.y = 1;
	Push(pstack, cur); //시작 위치, 방향 초기화하고 스택에 저장
	maze[cur.x][cur.y] = 2;

	

	while (1) {
		if ((cur.x == 21) && (cur.y == 17)) {
			printf("     목적지에 도착!\n\n\n");
			printf("            <결과 화면>\n\n");
			printmaze();
			break;
		}
		else {

			int alter = 0; //갈 수 있는 길 갯수

			if (maze[cur.x - 1][cur.y] == 0) //N
			{
				alter++; //길 갯수 증가
				cur.x--; //이동
				Push(pstack, cur); //위치와 방향을 스택에 저장
				maze[cur.x][cur.y] = 2; //갔다고 표시
			}
			if (maze[cur.x][cur.y + 1] == 0) //E으로 길이 있다면      
			{
				alter++; //길 갯수 증가
				cur.y++; //이동
				Push(pstack, cur); //위치와 방향을 스택에 저장
				maze[cur.x][cur.y] = 2; //갔다고 표시
			}

			if (maze[cur.x + 1][cur.y] == 0) //S   
			{
				alter++; //길 갯수 증가
				cur.x++; //이동
				Push(pstack, cur); //위치와 방향을 스택에 저장
				maze[cur.x][cur.y] = 2; //갔다고 표시
			}
			if (maze[cur.x][cur.y - 1] == 0) //W
			{
				alter++; //길 갯수 증가
				cur.y--; //이동
				Push(pstack, cur); //위치와 방향을 스택에 저장
				maze[cur.x][cur.y] = 2; //갔다고 표시
			}
			if (alter == 0) cur = back(pstack, cur); //막다른 길이라면 돌아가기
		}
	}
}

Element back(Stack *pstack, Element cur) { //돌아가기 함수
	Element next;
	next= Pop(pstack); //스택에서 이전 위치 가져오기

	maze[cur.x][cur.y] = 3; //되돌아갔다고 표시

	cur = next; //위치 변경(돌아가기)

	return next;
}
