#define MAX_STACK_SIZE 100
#define True 1
#define False 0
#define Error -1

#include<stdio.h>
#include<stdlib.h>

int maze[23][19] = //�̷�
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

typedef struct { //��ġ ���� ����ü
	int x;
	int y;
}Element;

typedef struct {  //����
	Element stackArr[MAX_STACK_SIZE];
	int top;
}Stack;

Stack *Create() { //���� ����
	Stack *tempstack;

	tempstack = (Stack *)malloc(sizeof(Stack)); //�����Ҵ�
	tempstack->top = -1; //top
	return tempstack;
}

Bool isEmpty(Stack *pstack) { //���� ������� Ȯ��
	if (pstack->top == -1) return True;
}

Bool isFull(Stack *pstack) {
	if (pstack->top == MAX_STACK_SIZE - 1) return True;
	else return False;

}

void Push(Stack *pstack, Element Data) { //���ÿ� ����
	if (isEmpty(pstack)) { //������� Ȯ��
		(pstack->top)++; //top �ø���
		pstack->stackArr[pstack->top].x = Data.x; 
		pstack->stackArr[pstack->top].y = Data.y;

		printf("      Push(%d,%d)\n", pstack->stackArr[pstack->top].x, pstack->stackArr[pstack->top].y);
	}
	else printf("������ ����á���ϴ�.\n");
}

Element Pop(Stack *pstack) {
	if (isEmpty(pstack)) {
		printf("      Pop(%d,%d)\n", pstack->stackArr[pstack->top].x, pstack->stackArr[pstack->top].y);
		return pstack->stackArr[pstack->top--]; //���� �� �����ֱ�
	}
	else printf("������ ������ϴ�\n");
}

void printmaze() //�̷� ��� �Լ�
{
	int i, j;

	for (i = 0; i < 23; i++) {
		for (j = 0; j < 19; j++) {

			switch (maze[i][j]) {
			case 0: //���
				printf("  ");
				break;
			case 1: //��
				printf("��");
				break;
			case 2: //���
				printf("��");
				break;
			case 3: //�ٽ� ���ƿ� ��
				printf("  ");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}

}

Element back(Stack *pstack, Element cur); //�ǵ��ư��� �Լ�

int main()
{
	printf("          <<<<<<�̷� ã�� ����>>>>>>>>\n\n");

	Stack *pstack;
	pstack = Create(); //���� ����

	Element cur;
	cur.x = 1;
	cur.y = 1;
	Push(pstack, cur); //���� ��ġ, ���� �ʱ�ȭ�ϰ� ���ÿ� ����
	maze[cur.x][cur.y] = 2;

	

	while (1) {
		if ((cur.x == 21) && (cur.y == 17)) {
			printf("     �������� ����!\n\n\n");
			printf("            <��� ȭ��>\n\n");
			printmaze();
			break;
		}
		else {

			int alter = 0; //�� �� �ִ� �� ����

			if (maze[cur.x - 1][cur.y] == 0) //N
			{
				alter++; //�� ���� ����
				cur.x--; //�̵�
				Push(pstack, cur); //��ġ�� ������ ���ÿ� ����
				maze[cur.x][cur.y] = 2; //���ٰ� ǥ��
			}
			if (maze[cur.x][cur.y + 1] == 0) //E���� ���� �ִٸ�      
			{
				alter++; //�� ���� ����
				cur.y++; //�̵�
				Push(pstack, cur); //��ġ�� ������ ���ÿ� ����
				maze[cur.x][cur.y] = 2; //���ٰ� ǥ��
			}

			if (maze[cur.x + 1][cur.y] == 0) //S   
			{
				alter++; //�� ���� ����
				cur.x++; //�̵�
				Push(pstack, cur); //��ġ�� ������ ���ÿ� ����
				maze[cur.x][cur.y] = 2; //���ٰ� ǥ��
			}
			if (maze[cur.x][cur.y - 1] == 0) //W
			{
				alter++; //�� ���� ����
				cur.y--; //�̵�
				Push(pstack, cur); //��ġ�� ������ ���ÿ� ����
				maze[cur.x][cur.y] = 2; //���ٰ� ǥ��
			}
			if (alter == 0) cur = back(pstack, cur); //���ٸ� ���̶�� ���ư���
		}
	}
}

Element back(Stack *pstack, Element cur) { //���ư��� �Լ�
	Element next;
	next= Pop(pstack); //���ÿ��� ���� ��ġ ��������

	maze[cur.x][cur.y] = 3; //�ǵ��ư��ٰ� ǥ��

	cur = next; //��ġ ����(���ư���)

	return next;
}
