
방정식 A와 B를 더한 결과인 방정식 C를 출력하는 알고리즘.
방정식의 계수와 지수를 멤버변수로 가지는 Term 구조체를 사용하여 배열 형태로 값을 저장한다.
값을 삽입하는 insert 함수, 방정식 A와 B를 더해서 방정식 C를 구해주는 Poly_Add 함수, 방정식을 출력하는 Print_poly 함수로 구성되어 있다.

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

- 과제에 대한 고찰

과제의 핵심은 Poly_Add() 함수를 구현해보는 것이었다.
이를 구현하면서 한가지 다시 상기하게 됐던 개념이 있는데, main함수 내에서 사용되는 지역변수 avail이 다른 함수에서 값 변경이 안된다는 것이다.
따라서 변수 avail의 주소를 넘겨준 후 포인터를 이용하여 avail 변수의 주소로 접근하여 그 값을 변경시켜주는 동작이 필요했다.
처음엔 Poly_Add 함수 내에서 avail 앞에 * 포인터를 붙이지 않아서 오류가 많이 발생했는데 그 이유를 알고난 후 고쳤을 때 정상적으로 실행이 됐다.
이외의 부분 구현은 잘 되었던 것 같다.
	
또한 과제의 논의 항목중 수행시간에 대한 항목이 있었다.
방정식 A와 B의 지수를 모두 같게 해서 실행을 해 보았을 때랑 모두 다르게 해서 실행을 해 보았을 때의 수행시간을 비교하는 것이다.
지수를 모두 같게 해보았을 때는 Poly_Add 함수에서의 while문이 최소로 동작한다.
항상 계수를 더하는 조건문에서 As와 Bs의 값을 항상 증가시켜 주므로 3번의 동작이면 끝이 난다.
이에 따라 남은 항을 더해줄 필요도 없고, 방정식을 출력하는 Print_ploy 함수에서도 avail의 값이 최소로 사용되기에 for문 또한 최소로 동작한다.
따라서 지수를 모두 같게 했을 때는 수행시간이 최소가 된다.
반대로, 지수를 모두 다르게 한다면 while문과 for문에서의 동작이 최대로 이루어진다.
avail의 값도 최대로 사용될 것이며 남은항을 더해주는 for문도 실행되며 수행시간이 최대가 될 것이다.
