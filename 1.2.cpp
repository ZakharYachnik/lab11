#include "1.2.h"

FILE* f, * F;
int k = 0;

struct students
{
	char FIO[30];
	int YearB;
	int YearEn;
	int marks[4];
};

students* mas = new students[15];

extern int vvod()
{
	int ch;

	while (1)
	{
		if (scanf_s("%d", &ch) != 1) {
			getchar();
			printf("\n������ �������� ���, ���������� ��� ��� ");
		}
		else break;

	}
	getchar();
	return ch;
}
extern int menu()
{
	int ch = 0;
	while (ch < 1 || ch > 8) {
		printf("\n�������� ��������\n");
		printf("\n1. ������������ ������ ���������\n");
		printf("2. ������� ������ ���������\n");
		printf("3. ����� �� ���������\n");
		printf("4. ���������� � ������ ���������\n");
		printf("5. ��������� 1 ���������\n");
		printf("6. �������� ������ � ��������\n");
		printf("7. ���������� �� ���������\n");
		printf("8. ������� ���������, ������� ������ ���� 3\n");
		printf("9. �����\n");

		printf("\n��� �����: ");
		ch = vvod();
		printf("\n");
	}
	return ch;
}


extern int readf()
{
	if (fopen_s(&f, "struct.dat", "r+b"))
	{
		printf("������ �������� �����");
		return 1;
	}


	char b[10];
	if (fread(b, 1, 1, f) == 0) {
		printf("���� ����!");
		return 1;
	}
	rewind(f);

	k = 0;
	for (int i = 0; !feof(f); i++)
	{
		char a[50];
		int j = 0;

		fgets(a, 50, f);
		for (j = 0; a[j] != '\n'; j++);
		strncpy_s((mas + i)->FIO, a, j - 1);


		fscanf_s(f, "%d", &(mas + i)->marks[0]);
		fgetc(f);
		fgetc(f);

		fscanf_s(f, "%d", &(mas + i)->marks[1]);
		fgetc(f);
		fgetc(f);

		fscanf_s(f, "%d", &(mas + i)->marks[2]);
		fgetc(f);
		fgetc(f);

		fscanf_s(f, "%d", &(mas + i)->YearB);
		fgetc(f);
		fgetc(f);

		fscanf_s(f, "%d", &(mas + i)->YearEn);
		fgetc(f);
		fgetc(f);

		k++;
	}
	fclose(f);
}

extern void changes()
{
	if (readf() == 1)
		return;

	printf("\n������� ������ ������ �������� �� ������� ��������(1, 2, 3...): ");

	int zap;

	while (1)
	{
		zap = vvod();
		if (zap <= k) break;
		else printf("����� ������ �� ����������, ���������� ��� ���: ");
	}


	printf("\n������� ��� ������ ��������\n");
	int ch = -1;
	while (ch < 1 || ch > 6)
	{
		printf("1) ���\n");
		printf("2) ������ �� ������\n");
		printf("3) ������ �� ������ ����������\n");
		printf("4) ������ �� �����������\n");
		printf("5) ��� ��������\n");
		printf("6) ��� �����������\n");

		printf("\n��� �����: ");
		ch = vvod();
	}

	switch (ch)
	{
	case 1:
		printf("\n������� ����� ���: ");
		gets_s((mas + zap - 1)->FIO);
		printf("���������!\n");
		break;

	case 2:
		printf("\n������� ����� ������ �� ������: ");
		while (1) {
			(mas + zap - 1)->marks[0] = vvod();
			if ((mas + zap - 1)->marks[0] < 0 || (mas + zap - 1)->marks[0] > 5)
				printf("������ ������� �����������, ���������� ��� ���: ");
			else break;
		}
		printf("���������!\n");
		break;

	case 3:
		printf("\n������� ����� ������ �� ������ ����������: ");
		while (1) {
			(mas + zap - 1)->marks[1] = vvod();
			if ((mas + zap - 1)->marks[1] < 0 || (mas + zap - 1)->marks[1] > 5)
				printf("������ ������� �����������, ���������� ��� ���: ");
			else break;
		}
		printf("���������!\n");
		break;

	case 4:
		printf("\n������� ����� ������ �� �����������: ");
		while (1) {
			(mas + zap - 1)->marks[2] = vvod();
			if ((mas + zap - 1)->marks[2] < 0 || (mas + zap - 1)->marks[2] > 5)
				printf("������ ������� �����������, ���������� ��� ���: ");
			else break;
		}
		printf("���������!\n");
		break;
	case 5:
		printf("\n������� ����� ��� ��������: ");
		while (1) {
			(mas + zap - 1)->YearB = vvod();
			if ((mas + zap - 1)->YearB < 1980)
				printf("���-�� �������� ��� ��������:), ���������� ��� ���: ");
			else if ((mas + zap - 1)->YearB > 2022)
				printf("����� ��� ������ �������:), ���������� ��� ���");
			else break;
		}
		printf("���������!\n");
		break;
	case 6:
		printf("\n������� ����� ��� �����������: ");
		while (1) {
			(mas + zap - 1)->YearEn = vvod();
			if ((mas + zap - 1)->YearEn < 2015)
				printf("�� ��� ����������:), ���������� ��� ���: ");
			else if ((mas + zap - 1)->YearEn < (mas + zap - 1)->YearB && (mas + zap - 1)->YearEn < 2023)
				printf("�� ����� ��� �� �������:), ���������� ��� ���: ");
			else if ((mas + zap - 1)->YearEn > 2022)
				printf("�� ����� � 2022:), ���������� ��� ���: ");
			else break;
		}
		printf("���������!\n");
		break;
	}

	if (fopen_s(&f, "struct.dat", "w"))
	{
		printf("������ �������� �����");
		return;
	}


	for (int i = 0; i < k; i++)
	{
		fputs((mas + i)->FIO, f);
		fprintf(f, "\n");

		fprintf(f, "%d\n", (mas + i)->marks[0]);

		fprintf(f, "%d\n", (mas + i)->marks[1]);

		fprintf(f, "%d\n", (mas + i)->marks[2]);

		fprintf(f, "%d\n", (mas + i)->YearB);

		if (i + 1 != k)
			fprintf(f, "%d\n", (mas + i)->YearEn);
		else fprintf(f, "%d", (mas + i)->YearEn);

	}
	fclose(f);
}



extern void print()
{
	if (readf() == 1)
		return;

	printf("\n ------------------------------------------------------------------------------------------\n");
	printf(" |#|  ��� ��������  |  ��� ��������  | ��� ����������� |  ������  | ��� ��� | ����������� |\n");
	printf(" ------------------------------------------------------------------------------------------\n");

	for (int i = 0; i < k; i++)
	{
		printf(" |%d|%14s%13d%17d%14d%11d%11d      |\n", i + 1, (mas + i)->FIO, (mas + i)->YearB, (mas + i)->YearEn, (mas + i)->marks[0], (mas + i)->marks[1], (mas + i)->marks[2]);
	}
	printf(" ------------------------------------------------------------------------------------------\n");

}

extern void form(int num)
{

	if (num == 1) {
		if (fopen_s(&f, "struct.dat", "w"))
		{
			printf("������ �������� �����");
			return;
		}
	}
	else
		if (fopen_s(&f, "struct.dat", "a"))
		{
			printf("������ �������� �����");
			return;
		}
		else fprintf(f, "\n");


	int ch;
	printf("������� ���������� ���������: ");
	ch = vvod();

	for (int i = 0; i < ch; i++)
	{
		printf("\n\n������ %d\n������� ������� � ��������(����� �.�.): ", i + 1);
		gets_s((mas + i)->FIO);
		fputs((mas + i)->FIO, f);
		fprintf(f, "\n");

		printf("������� ������ �� ������ (�� 5-�������� �����): ");
		while (1) {
			(mas + i)->marks[0] = vvod();
			if ((mas + i)->marks[0] < 0 || (mas + i)->marks[0] > 5)
				printf("������ ������� �����������, ���������� ��� ���: ");
			else break;
		}
		fprintf(f, "%d\n", (mas + i)->marks[0]);

		printf("������� ������ �� ������ ���������� (�� 5-�������� �����): ");
		while (1) {
			(mas + i)->marks[1] = vvod();
			if ((mas + i)->marks[1] < 0 || (mas + i)->marks[1] > 5)
				printf("������ ������� �����������, ���������� ��� ���: ");
			else break;
		}
		fprintf(f, "%d\n", (mas + i)->marks[1]);


		printf("������� ������ �� ����������� (�� 5-�������� �����): ");
		while (1) {
			(mas + i)->marks[2] = vvod();
			if ((mas + i)->marks[2] < 0 || (mas + i)->marks[2] > 5)
				printf("������ ������� �����������, ���������� ��� ���: ");
			else break;
		}
		fprintf(f, "%d\n", (mas + i)->marks[2]);

		printf("������� ��� �������� ��������: ");
		while (1) {
			(mas + i)->YearB = vvod();
			if ((mas + i)->YearB < 1980)
				printf("���-�� �������� ��� ��������:), ���������� ��� ���: ");
			else if ((mas + i)->YearB > 2022)
				printf("����� ��� ������ �������:), ���������� ��� ���");
			else break;
		}
		fprintf(f, "%d\n", (mas + i)->YearB);


		printf("������� ��� ����������� �������� � �����: ");
		while (1) {
			(mas + i)->YearEn = vvod();
			if ((mas + i)->YearEn < 2015)
				printf("�� ��� ����������:), ���������� ��� ���: ");
			else if ((mas + i)->YearEn < (mas + i)->YearB && (mas + i)->YearEn < 2023)
				printf("�� ����� ��� �� �������:), ���������� ��� ���: ");
			else if ((mas + i)->YearEn > 2022)
				printf("�� ����� � 2022:), ���������� ��� ���: ");
			else break;
		}
		if (i + 1 != ch)
			fprintf(f, "%d\n", (mas + i)->YearEn);
		else fprintf(f, "%d", (mas + i)->YearEn);
	}

	fclose(f);
}

extern void deletef()
{
	if (readf() == 1)
		return;

	printf("������� ������ � ����� �������� ������ �������: ");
	int zap;

	while (1)
	{
		zap = vvod();
		if (zap <= k) break;
		else printf("����� ������ �� ����������, ���������� ��� ���: ");
	}


	if (fopen_s(&f, "struct.dat", "w"))
	{
		printf("������ �������� �����");
		return;
	}


	for (int i = 0; i < k; i++)
	{
		if (i != zap - 1) {
			fputs((mas + i)->FIO, f);
			fprintf(f, "\n");

			fprintf(f, "%d\n", (mas + i)->marks[0]);

			fprintf(f, "%d\n", (mas + i)->marks[1]);

			fprintf(f, "%d\n", (mas + i)->marks[2]);

			fprintf(f, "%d\n", (mas + i)->YearB);

			if (i + 1 == k || (zap == k && i + 2 == k))
				fprintf(f, "%d", (mas + i)->YearEn);
			else
				fprintf(f, "%d\n", (mas + i)->YearEn);
		}
	}
	fclose(f);
}

extern void findf()
{
	if (readf() == 1)
		return;

	if (fopen_s(&f, "struct.dat", "rb"))
	{
		printf("������ �������� �����");
		return;
	}

	int ch = 0;
	while (ch < 1 || ch > 6) {
		printf("\n1. ���\n");
		printf("2. ������ �� ������\n");
		printf("3. ������ �� ������ ����������\n");
		printf("4. ������ �� �����������\n");
		printf("5. ��� ��������\n");
		printf("6. ��� ����������� � �����\n");

		printf("��� �����: ");
		ch = vvod();
	}

	switch (ch)
	{
	case 1:
		printf("\n");
		for (int i = 0; i < k; i++)
		{
			printf("%d | ", i + 1);
			puts((mas + i)->FIO);
			printf("\n");
		}
		break;
	case 2:
		printf("\n");
		for (int i = 0; i < k; i++)
		{
			printf("%d | %d\n", i + 1, (mas + i)->marks[0]);
		}
		break;
	case 3:
		printf("\n");
		for (int i = 0; i < k; i++)
		{
			printf("%d | %d\n", i + 1, (mas + i)->marks[1]);
		}
		break;
	case 4:
		printf("\n");
		for (int i = 0; i < k; i++)
		{
			printf("%d | %d\n", i + 1, (mas + i)->marks[2]);
		}
		break;
	case 5:
		printf("\n");
		for (int i = 0; i < k; i++)
		{
			printf("%d | %d\n", i + 1, (mas + i)->YearB);
		}
		break;
	case 6:
		printf("\n");
		for (int i = 0; i < k; i++)
		{
			printf("%d | %d\n", i + 1, (mas + i)->YearEn);
		}
		break;
	}

	fclose(f);

}

extern void sort()
{
	if (readf() == 1)
		return;

	if (fopen_s(&f, "struct.dat", "w"))
	{
		printf("������ �������� �����, �������������");
		return;
	}

	printf("\n������� �� ������ ��������� �����������: ");
	int ch = 0;
	while (ch < 1 || ch > 6) {
		printf("\n1. ���\n");
		printf("2. ������ �� ������\n");
		printf("3. ������ �� ������ ����������\n");
		printf("4. ������ �� �����������\n");
		printf("5. ��� ��������\n");
		printf("6. ��� ����������� � �����\n");

		printf("��� �����: ");
		ch = vvod();
	}

	struct students car;
	switch (ch)
	{
	case 1:
		for (int i = 0; i < k - 1; i++) {
			for (int j = 0; j < k - 1 - i; j++) {
				if (strcmp((mas + j)->FIO, (mas + j + 1)->FIO) > 0) {
					car = *(mas + j);
					*(mas + j) = *(mas + j + 1);
					*(mas + j + 1) = car;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < k - 1; i++) {
			for (int j = 0; j < k - 1 - i; j++) {
				if ((mas + j)->marks[0] > (mas + j + 1)->marks[0]) {
					car = *(mas + j);
					*(mas + j) = *(mas + j + 1);
					*(mas + j + 1) = car;
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < k - 1; i++) {
			for (int j = 0; j < k - 1 - i; j++) {
				if ((mas + j)->marks[1] > (mas + j + 1)->marks[1]) {
					car = *(mas + j);
					*(mas + j) = *(mas + j + 1);
					*(mas + j + 1) = car;
				}
			}
		}
		break;
	case 4:
		for (int i = 0; i < k - 1; i++) {
			for (int j = 0; j < k - 1 - i; j++) {
				if ((mas + j)->marks[2] > (mas + j + 1)->marks[2]) {
					car = *(mas + j);
					*(mas + j) = *(mas + j + 1);
					*(mas + j + 1) = car;
				}
			}
		}
		break;
	case 5:
		for (int i = 0; i < k - 1; i++) {
			for (int j = 0; j < k - 1 - i; j++) {
				if ((mas + j)->YearB > (mas + j + 1)->YearB) {
					car = *(mas + j);
					*(mas + j) = *(mas + j + 1);
					*(mas + j + 1) = car;
				}
			}
		}
		break;
	case 6:
		for (int i = 0; i < k - 1; i++) {
			for (int j = 0; j < k - 1 - i; j++) {
				if ((mas + j)->YearEn > (mas + j + 1)->YearEn) {
					car = *(mas + j);
					*(mas + j) = *(mas + j + 1);
					*(mas + j + 1) = car;
				}
			}
		}
		break;
	}

	for (int i = 0; i < k; i++)
	{
		fputs((mas + i)->FIO, f);
		fprintf(f, "\n");

		fprintf(f, "%d\n", (mas + i)->marks[0]);

		fprintf(f, "%d\n", (mas + i)->marks[1]);

		fprintf(f, "%d\n", (mas + i)->marks[2]);

		fprintf(f, "%d\n", (mas + i)->YearB);

		if (i + 1 != k)
			fprintf(f, "%d\n", (mas + i)->YearEn);
		else fprintf(f, "%d", (mas + i)->YearEn);


	}

	fclose(f);
	print();
}

extern void with_3()
{
	if (readf() == 1)
		return;

	int flag = 0;
	for (int i = 0; i < k; i++)
	{
		if ((mas + i)->marks[0] == 3 || (mas + i)->marks[1] == 3 || (mas + i)->marks[2] == 3)
		{
			if (flag == 0)
			{
				printf("\n ----------------------------------------------------------------------------------------\n");
				printf(" |  ��� ��������  |  ��� ��������  | ��� ����������� |  ������  | ��� ��� | ����������� |\n");
				printf(" ----------------------------------------------------------------------------------------\n");
			}
			printf(" |%14s%13d%17d%14d%11d%11d      |\n", (mas + i)->FIO, (mas + i)->YearB, (mas + i)->YearEn, (mas + i)->marks[0], (mas + i)->marks[1], (mas + i)->marks[2]);
			flag++;
		}
	}
	if (flag != 0)
		printf(" ----------------------------------------------------------------------------------------\n");
	else
		printf("����� ��������� ���!\n");
}
