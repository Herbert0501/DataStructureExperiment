#pragma once
#include "SeqList.h"
#include "LinkList.h"
#include "BinaryTree.h"
#include "HashTable.h"

/*��������*/
void Menu1();
void Menu2();
void Menu3();
void Menu4();
void Menu5();
void Menu6();
void Menu7();
void SMenu1();
void SMenu2();
void SMenu3();
void SMenu4();
void SMenu5();
void SMenu6();
void SMenu7();
void SMenu();
void MInitial();
int theEnd();
void Any_Key(int n);
void errorEnter(int n);
void SetColor(UINT uFore, UINT uBack);
void Table_Word_Frequency_Count(int s);
void Link_Word_Frequency_Count();
void BinaryTree_Word_Frequency_Count();
void Hash_Word_Frequency_Count();


void MainMenu() {

	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	printf("%s%s1.�������Ա�Ĳ���\n", c1, c);
	printf("%s2.���ڶ����������Ĳ���\n", c);
	printf("%s3.���ڹ�ϣ��Ĳ���\n", c);
	printf("%s4.�˳�\n", c);
	printf("%s�밴��Ӧ���ֽ���ѡ��:", c);
	SMenu();
}

void Menu1() {

	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	printf("\n%s\t �����������Ա�Ĳ��ҡ���", c);
	printf("%s%s1.˳�����\n", c1, c);
	printf("%s2.�۰����\n", c);
	printf("%s3.������һ��\n", c);
	printf("%s�밴��Ӧ���ֽ���ѡ��:", c);
	SMenu1();

}
void SMenu1() {
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		Menu4(); break;
	case 2:
		Menu5(); break;
	case 3:
		MainMenu(); break;
	default:
		errorEnter(1);
		break;
	}
	return;
}
void Menu2() {

	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	printf("\n%s\t�������ڶ����������Ĳ��ҡ���", c);
	printf("%s%s1.��Ƶͳ��\n", c1, c);
	printf("%s2.���ʲ���\n", c);
	printf("%s3.������һ��\n", c);
	printf("%s�밴��Ӧ���ֽ���ѡ��:", c);
	SMenu2();
}
void SMenu2() {
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		BinaryTree_Word_Frequency_Count(); break;
	case 2:
		Tree_Word_Select(), Any_Key(2); break;
	case 3:
		MainMenu(); break;
	default:
		errorEnter(2);
		break;
	}
	return;
}
void Menu3() {

	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	printf("\n%s\t �������ڹ�ϣ��Ĳ��ҡ���", c);
	printf("%s%s1.��Ƶͳ��\n", c1, c);
	printf("%s2.���ʲ���\n", c);
	printf("%s3.������һ��\n", c);
	printf("%s�밴��Ӧ���ֽ���ѡ��:", c);
	SMenu3();
}
void SMenu3() {
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		Hash_Word_Frequency_Count(); break;
	case 2:
		Hash_Word_Frequency(), Hash_Search(), Any_Key(3); break;
	case 3:
		MainMenu(); break;
	default:
		errorEnter(3);
		break;
	}
	return;
}
void Menu4() {

	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	printf("\n%s\t     ����˳����ҡ���", c);
	printf("%s%s1.����˳����˳�����\n", c1, c);
	printf("%s2.���������˳�����\n", c);
	printf("%s3.������һ��\n", c);
	printf("%s�밴��Ӧ���ֽ���ѡ��:", c);
	SMenu4();

}
void SMenu4() {
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		Menu6(); break;
	case 2:
		Menu7(); break;
	case 3:
		Menu1(); break;
	default:
		errorEnter(4);
		break;
	}
	return;
}
void Menu5() {

	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	printf("\n%s\t     �����۰���ҡ���", c);
	printf("%s%s1.��Ƶͳ��\n", c1, c);
	printf("%s2.���ʲ���\n", c);
	printf("%s3.������һ��\n", c);
	printf("%s�밴��Ӧ���ֽ���ѡ��:", c);
	SMenu5();

}

void SMenu5() {
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		Table_Word_Frequency_Count(1); break;
	case 2:
		Table_Word_Frequency(1), Table_Binary_Select(), Any_Key(5); break;
	case 3:
		Menu1(); break;
	default:
		errorEnter(5);
		break;
	}
	return;
}

void Menu6() {

	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	printf("\n%s\t ��������˳����˳����ҡ���", c);
	printf("%s%s1.��Ƶͳ��\n", c1, c);
	printf("%s2.���ʲ���\n", c);
	printf("%s3.������һ��\n", c);
	printf("%s�밴��Ӧ���ֽ���ѡ��:", c);
	SMenu6();

}
void SMenu6() {
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		Table_Word_Frequency_Count(2); break;
	case 2:
		Table_Word_Frequency(2), Table_Order_Select(), Any_Key(6); break;
	case 3:
		Menu4(); break;
	default:
		errorEnter(6);
		break;
	}
	return;
}
void Menu7() {

	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	printf("\n%s\t �������������˳����ҡ���", c);
	printf("%s%s1.��Ƶͳ��\n", c1, c);
	printf("%s2.���ʲ���\n", c);
	printf("%s3.������һ��\n", c);
	printf("%s�밴��Ӧ���ֽ���ѡ��:", c);
	SMenu7();

}
void SMenu7() {
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		Link_Word_Frequency_Count(), LinkDestroy(); break;
	case 2:
		Link_Word_Frequency(), Link_Word_Find(),
			LinkDestroy(), Any_Key(7); break;
	case 3:
		Menu4(); break;
	default:
		errorEnter(7);
		break;
	}
	return;
}

/*˳���Ĵ�Ƶͳ�ƺ������ú���*/
void Table_Word_Frequency_Count(int s) {
	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ������Ƶͳ�ơ���", c);
	SetColor(0, 15);

	time_t startTime = clock();
	Table_Word_Frequency(s);
	time_t endTime = clock();

	double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	printf("%s%s--����ɴ�Ƶͳ��\n\n", c1, c);
	printf("%s--��Ƶͳ�������ѵ�ʱ�䣺%.6f\n", c, totalTime);
	printf("\n%s�밴���������", c);
	_getch();
	if (s == 1) {
		Menu5();
	}
	else if (s == 2) {
		Menu6();
	}
	return;
}

/*���������˳�����*/
void Link_Word_Frequency_Count() {
	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ������Ƶͳ�ơ���", c);
	SetColor(0, 15);

	time_t startTime = clock();
	Link_Word_Frequency();
	time_t endTime = clock();

	double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	printf("%s%s--����ɴ�Ƶͳ��\n\n", c1, c);
	printf("%s--��Ƶͳ�������ѵ�ʱ�䣺%.6f\n", c, totalTime);

	printf("\n%s�밴���������", c);
	_getch();
	Menu7();

	return;
}

/*���ڶ������Ĳ���*/
void BinaryTree_Word_Frequency_Count() {
	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ������Ƶͳ�ơ���", c);
	SetColor(0, 15);

	time_t startTime = clock();
	Link_Word_Frequency();
	time_t endTime = clock();

	double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	printf("%s%s--����ɴ�Ƶͳ��\n\n", c1, c);
	printf("%s--��Ƶͳ�������ѵ�ʱ�䣺%.6f\n", c, totalTime);

	printf("\n%s�밴���������", c);
	_getch();
	Menu2();

	return;
}

/*���ڹ�ϣ��Ĳ���*/
void Hash_Word_Frequency_Count() {
	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ������Ƶͳ�ơ���", c);
	SetColor(0, 15);

	time_t startTime = clock();
	Hash_Word_Frequency();
	time_t endTime = clock();

	double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	printf("%s%s--����ɴ�Ƶͳ��\n\n", c1, c);
	printf("%s--��Ƶͳ�������ѵ�ʱ�䣺%.6f\n", c, totalTime);

	printf("\n%s�밴���������", c);
	_getch();
	Menu2();

	return;
}

/*��ҳ���ȡ����*/
void SMenu() {
	int n;
	scanf_s("%d", &n);
	system("cls");
	switch (n)
	{
	case 1:
		Menu1(); break;
	case 2:
		Menu2(); break;
	case 3:
		Menu3(); break;
	case 4:
		SetColor(1, 15),
			printf("\n\t\t\t\t****��л����ʹ��****\n"),
			SetColor(0, 15),
			theEnd(); break;
	default:
		errorEnter(0);
		break;
	}
	return;
}

/*��ʼ������������*/
void MInitial() {
	/*���ô����С����ɫ������*/
	system("mode con cols=95 lines=35");
	system("color F0");
	/* L ��ʾ��ANSI�ַ���ת����unicode���ַ���*/
	SetConsoleTitle(L"���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ");

	MainMenu();
	SMenu();
}
int theEnd() {

	system("pause");
	exit(1);
}
void Any_Key(int n) {
	printf("\n%s�밴���������<", c);
	_getch();
	switch (n)
	{
	case 0:
		MainMenu();
	case 1:
		Menu1();
	case 2:
		Menu2();
	case 3:
		Menu3();
	case 4:
		Menu4();
	case 5:
		Menu5();
	case 6:
		Menu6();
	case 7:
		Menu7();
	default:
		break;
	}


}
/*�����ѡ��Ե������*/
void errorEnter(int n) {
	system("cls");
	SetColor(4, 15);
	printf("\n%s�������", c);
	SetColor(0, 15);
	Any_Key(n);
	return;
}

void SetColor(UINT uFore, UINT uBack) {
	/*��ȡ���ھ��,STD_OUTPUT_HANDLE��ʾ��׼����ľ����GetStdHandle��Windows API����*/
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	/*����ǰ��ɫ�ͺ�ɫ, 0x10�൱��(int)16*/
	SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
}