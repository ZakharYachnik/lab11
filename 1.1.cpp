#include "1.2.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int ch = 0;
	while (ch < 1 || ch > 2) {

		printf("\n\n�������� � ����� �����������: asd\n");
		printf("1) ������� ��������� � ����� ���.\n");
		printf("2) ������� ������� � ����������.\n");

		printf("��� �����: ");
		ch = vvod();
	}

	if (ch == 2)
		form(1);


	while (1) {
		switch (menu())
		{
		case 1:
			form(1);
			break;

		case 2:
			print();
			break;

		case 3:
			findf();
			break;

		case 4:
			form(4);
			break;

		case 5:
			changes();
			break;

		case 6:
			deletef();
			break;

		case 7:
			sort();
			break;

		case 8:
			with_3();
			break;

		case 9:
			return 0;
		}
	}
}