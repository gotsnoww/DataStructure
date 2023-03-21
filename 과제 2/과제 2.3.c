#include <stdio.h>

#define NO_OF_TERMS 20

typedef struct Term { //Term 구조체
	int coef;         //방정식의 계수인 coef와 지수인 expon을 멤버변수로 가짐
	int expon;
} Term;

int Cs; //방정식 C 배열의 시작과 끝
int Ce;

//구조체 배열 내 인자에 방정식의 계수와 지수를 입력하는 함수
void insert(Term poly[], int avail, int coef, int expon) {
	poly[avail].coef = coef;
	poly[avail].expon = expon;
}

//방정식 A와 B를 인자로 받아 두 개를 더한 C를 구하는 함수
void Poly_Add(Term poly[], int As, int Ae, int Bs, int Be, int *avail)
{
	Cs = *avail;

	int sumCoef = 0;
	while (As <= Ae && Bs <= Be) //while 반복문을 돌면서 poly[avail] 이후의 구조체 배열에 C의 값 저장
	{
		if (poly[As].expon > poly[Bs].expon) {
			insert(poly, *avail, poly[As].coef, poly[As].expon);
			As++;
		}
		else if (poly[As].expon == poly[Bs].expon) {
			sumCoef = poly[As].coef + poly[Bs].coef;
			if (sumCoef)
				insert(poly, *avail, sumCoef, poly[As].expon);
			As++;
			Bs++;
		}
		else if (poly[As].expon < poly[Bs].expon) {
			insert(poly, *avail, poly[Bs].coef, poly[Bs].expon);
			Bs++;
		}
		*avail += 1;
	}

	//while문의 조건을 만족하지 못했을 경우 남은 계수와 지수를 삽입
	for (int i = As; i <= Ae; i++) {
		insert(poly, *avail, poly[i].coef, poly[i].expon);
		*avail += 1;
	}
	for (int i = Bs; i <= Be; i++) {
		insert(poly, *avail, poly[i].coef, poly[i].expon);
		*avail += 1;
	}
	Ce = *avail -1;
}

//구조체 배열을 이용하여 방정식을 출력하는 함수
void Print_Poly(Term poly[], int As, int Ae, int Bs, int Be, int avail)
{
	for (int i = 0; i < avail; i++) {
		if (i == As)
			printf("Polynomial A: ");
		else if (i == Bs)
			printf("Polynomial B: ");
		else if (i == Cs)
			printf("Polynomial C: ");

		if(poly[i].expon != 0) //방정식의 지수가 0인경우 계수만 출력하는 조건문
			printf("%dx^%d", poly[i].coef, poly[i].expon);
		else
			printf("%dx", poly[i].coef);

		//조건에 따른 +연산자 삽입
		if (i == Ae || i == Be || i == Ce)
			printf("\n\n");
		else printf(" + ");
	}
}

int main() {
	                          //A(x) = 3x^5 + 2x^3 + 2,    B(x) = 4x^4 + 5x^3 + 2x
	Term poly[NO_OF_TERMS] = { {3, 5}, { 2,3 }, { 2,0 }, { 4,4 }, { 5,3 }, { 2,1 } }; 
	int As = 0;
	int Ae = 2;
	int Bs = 3;
	int Be = 5;
	int avail = 6;   //main 함수내의 지역변수 avail 값을 다른함수에서도 증가시키기 위해 주소&포인터 사용
	Poly_Add(poly, As, Ae, Bs, Be, &avail);  //A와 B를 더한 C를 구하는 함수
	Print_Poly(poly, As, Ae, Bs, Be, avail); //방정식 출력

	return 0;
}
