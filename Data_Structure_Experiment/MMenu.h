#pragma once
#include "SeqList.h"
#include "LinkList.h"
#include "BinaryTree.h"
#include "HashTable.h"

/*函数声明*/
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
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	printf("%s%s1.基于线性表的查找\n", c1, c);
	printf("%s2.基于二叉排序树的查找\n", c);
	printf("%s3.基于哈希表的查找\n", c);
	printf("%s4.退出\n", c);
	printf("%s请按相应数字进行选择:", c);
	SMenu();
}

void Menu1() {

	system("cls");
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	printf("\n%s\t ——基于线性表的查找——", c);
	printf("%s%s1.顺序查找\n", c1, c);
	printf("%s2.折半查找\n", c);
	printf("%s3.返回上一级\n", c);
	printf("%s请按相应数字进行选择:", c);
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
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	printf("\n%s\t——基于二叉排序树的查找——", c);
	printf("%s%s1.词频统计\n", c1, c);
	printf("%s2.单词查找\n", c);
	printf("%s3.返回上一级\n", c);
	printf("%s请按相应数字进行选择:", c);
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
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	printf("\n%s\t ——基于哈希表的查找——", c);
	printf("%s%s1.词频统计\n", c1, c);
	printf("%s2.单词查找\n", c);
	printf("%s3.返回上一级\n", c);
	printf("%s请按相应数字进行选择:", c);
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
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	printf("\n%s\t     ——顺序查找——", c);
	printf("%s%s1.基于顺序表的顺序查找\n", c1, c);
	printf("%s2.基于链表的顺序查找\n", c);
	printf("%s3.返回上一级\n", c);
	printf("%s请按相应数字进行选择:", c);
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
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	printf("\n%s\t     ——折半查找——", c);
	printf("%s%s1.词频统计\n", c1, c);
	printf("%s2.单词查找\n", c);
	printf("%s3.返回上一级\n", c);
	printf("%s请按相应数字进行选择:", c);
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
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	printf("\n%s\t ——基于顺序表的顺序查找——", c);
	printf("%s%s1.词频统计\n", c1, c);
	printf("%s2.单词查找\n", c);
	printf("%s3.返回上一级\n", c);
	printf("%s请按相应数字进行选择:", c);
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
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	printf("\n%s\t ——基于链表的顺序查找——", c);
	printf("%s%s1.词频统计\n", c1, c);
	printf("%s2.单词查找\n", c);
	printf("%s3.返回上一级\n", c);
	printf("%s请按相应数字进行选择:", c);
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

/*顺序表的词频统计函数调用函数*/
void Table_Word_Frequency_Count(int s) {
	system("cls");
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ——词频统计——", c);
	SetColor(0, 15);

	time_t startTime = clock();
	Table_Word_Frequency(s);
	time_t endTime = clock();

	double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	printf("%s%s--已完成词频统计\n\n", c1, c);
	printf("%s--词频统计所花费的时间：%.6f\n", c, totalTime);
	printf("\n%s请按任意键返回", c);
	_getch();
	if (s == 1) {
		Menu5();
	}
	else if (s == 2) {
		Menu6();
	}
	return;
}

/*基于链表的顺序查找*/
void Link_Word_Frequency_Count() {
	system("cls");
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ——词频统计——", c);
	SetColor(0, 15);

	time_t startTime = clock();
	Link_Word_Frequency();
	time_t endTime = clock();

	double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	printf("%s%s--已完成词频统计\n\n", c1, c);
	printf("%s--词频统计所花费的时间：%.6f\n", c, totalTime);

	printf("\n%s请按任意键返回", c);
	_getch();
	Menu7();

	return;
}

/*基于二叉树的查找*/
void BinaryTree_Word_Frequency_Count() {
	system("cls");
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ——词频统计——", c);
	SetColor(0, 15);

	time_t startTime = clock();
	Link_Word_Frequency();
	time_t endTime = clock();

	double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	printf("%s%s--已完成词频统计\n\n", c1, c);
	printf("%s--词频统计所花费的时间：%.6f\n", c, totalTime);

	printf("\n%s请按任意键返回", c);
	_getch();
	Menu2();

	return;
}

/*基于哈希表的查找*/
void Hash_Word_Frequency_Count() {
	system("cls");
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ——词频统计——", c);
	SetColor(0, 15);

	time_t startTime = clock();
	Hash_Word_Frequency();
	time_t endTime = clock();

	double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	printf("%s%s--已完成词频统计\n\n", c1, c);
	printf("%s--词频统计所花费的时间：%.6f\n", c, totalTime);

	printf("\n%s请按任意键返回", c);
	_getch();
	Menu2();

	return;
}

/*主页面获取函数*/
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
			printf("\n\t\t\t\t****感谢您的使用****\n"),
			SetColor(0, 15),
			theEnd(); break;
	default:
		errorEnter(0);
		break;
	}
	return;
}

/*初始化与启动函数*/
void MInitial() {
	/*设置窗体大小和颜色和名字*/
	system("mode con cols=95 lines=35");
	system("color F0");
	/* L 表示将ANSI字符串转换成unicode的字符串*/
	SetConsoleTitle(L"基于不同策略的单词统计和检索系统");

	MainMenu();
	SMenu();
}
int theEnd() {

	system("pause");
	exit(1);
}
void Any_Key(int n) {
	printf("\n%s请按任意键返回<", c);
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
/*输入的选项不对的情况下*/
void errorEnter(int n) {
	system("cls");
	SetColor(4, 15);
	printf("\n%s输入错误！", c);
	SetColor(0, 15);
	Any_Key(n);
	return;
}

void SetColor(UINT uFore, UINT uBack) {
	/*获取窗口句柄,STD_OUTPUT_HANDLE表示标准输出的句柄。GetStdHandle是Windows API函数*/
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	/*设置前景色和后景色, 0x10相当于(int)16*/
	SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
}