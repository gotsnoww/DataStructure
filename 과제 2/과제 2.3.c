#include <stdio.h>

#define NO_OF_TERMS 20

typedef struct Term { //Term ����ü
	int coef;         //�������� ����� coef�� ������ expon�� ��������� ����
	int expon;
} Term;

int Cs; //������ C �迭�� ���۰� ��
int Ce;

//����ü �迭 �� ���ڿ� �������� ����� ������ �Է��ϴ� �Լ�
void insert(Term poly[], int avail, int coef, int expon) {
	poly[avail].coef = coef;
	poly[avail].expon = expon;
}

//������ A�� B�� ���ڷ� �޾� �� ���� ���� C�� ���ϴ� �Լ�
void Poly_Add(Term poly[], int As, int Ae, int Bs, int Be, int *avail)
{
	Cs = *avail;

	int sumCoef = 0;
	while (As <= Ae && Bs <= Be) //while �ݺ����� ���鼭 poly[avail] ������ ����ü �迭�� C�� �� ����
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

	//while���� ������ �������� ������ ��� ���� ����� ������ ����
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

//����ü �迭�� �̿��Ͽ� �������� ����ϴ� �Լ�
void Print_Poly(Term poly[], int As, int Ae, int Bs, int Be, int avail)
{
	for (int i = 0; i < avail; i++) {
		if (i == As)
			printf("Polynomial A: ");
		else if (i == Bs)
			printf("Polynomial B: ");
		else if (i == Cs)
			printf("Polynomial C: ");

		if(poly[i].expon != 0) //�������� ������ 0�ΰ�� ����� ����ϴ� ���ǹ�
			printf("%dx^%d", poly[i].coef, poly[i].expon);
		else
			printf("%dx", poly[i].coef);

		//���ǿ� ���� +������ ����
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
	int avail = 6;   //main �Լ����� �������� avail ���� �ٸ��Լ������� ������Ű�� ���� �ּ�&������ ���
	Poly_Add(poly, As, Ae, Bs, Be, &avail);  //A�� B�� ���� C�� ���ϴ� �Լ�
	Print_Poly(poly, As, Ae, Bs, Be, avail); //������ ���

	return 0;
}
