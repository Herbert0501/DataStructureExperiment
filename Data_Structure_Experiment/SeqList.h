#pragma once
#define MAXSIZE 5001
/*��������*/
void SetColor(UINT uFore, UINT uBack);
void Table_Word_Frequency(int m);
void Table_Order_Select();
int getRightBorder(char* target);
int getLeftBorder(char* target);
void Table_Binary_Select();

/*˳���*/
typedef struct Table {
	char head[255];	/*����,����һ������*/
	int cnt;  /*��¼һ�����ʳ��ֵĴ���*/
	int allcnt;	/*��¼ȫ�����ʳ��ֵĴ���*/
}table;

/*��ʽ�����ַ���*/
const char c[] = "\t\t\t";
const char c1[] = "\n\n\n";

/*��������Ƚ���*/
// a=b ����0
// a<b ���ظ�ֵ
// a>b ������ֵ
int comp1(const void* a, const void* b) {
	/*Ĭ������*/
	return ((table*)a)->cnt - ((table*)b)->cnt;
}

int comp2(const void* a, const void* b) {
	/*Ĭ������*/
	return strlen(((table*)a)->head) - strlen(((table*)b)->head);
}


table words[MAXSIZE]; /*���ʻ���*/
table t{};			 /*�ṹ�����ͱ���*/
int num;		/*��Ϊwords���±�*/
/*˳���Ĵ�Ƶͳ��*/
void Table_Word_Frequency(int m) {
	/*��ʼ��*/
	num = 0;
	t.allcnt = 0;
	words[MAXSIZE] = { 0 };

	char temp[255] = { 0 }; /*���յ���*/
	char tmp[255] = { 0 }; /*���մ���ĵ���*/

	FILE* fp = fopen("InFile.txt", "r");
	assert(fp);	/*����򲻿��ļ����������ֹͣ����*/
	int i, j, k;

	/*fscanfֻ�����ַ�������*/
	while (fscanf(fp, "%s", temp) != EOF) {
		int key = 0;
		/*����ı�����*/
		for (k = 0; k < strlen(temp); ++k) {
			if (isalpha(temp[k])) {

				if (!islower(temp[k])) {
					temp[k] = temp[k] + 32;
				}
				tmp[key] = temp[k];
				++key;
			}
			else if (temp[k] == '\'') {
				break;
			}
		}
		/*Ȼ�����δ����ĵ���*/
		memset(temp, '\0', sizeof(temp));
		/*��������ĵ��ʺ��ڽ�β�Ӹ�\0*/
		tmp[key] = '\0';
		/*tmp�Ƿ�֮ǰ�Ѿ���ͳ�ƹ���*/
		for (i = 0; i < num; i++) {
			/*���tmp == words[i].str��֮ǰͳ�ƹ���*/
			if (strcmp(tmp, words[i].head) == 0) {
				words[i].cnt++; /*���ʴ��� + 1*/
				break; /*����forѭ��*/
			}
		}
		/*��i=num��˵��tmpû�б�ͳ�ƹ�*/
		if (i == num) {
			for (j = 0; tmp[j] != '\0'; j++) {
				/*�����ַ���*/
				words[num].head[j] = tmp[j];
			}
			words[num].head[j] = '\0'; /*ĩβ��*/
			words[num].cnt = 1; /*��¼��һ�����ʣ��������Ϊ1*/
			num++; /*��ŵ�������ṹ����±�����*/
		}
		++t.allcnt; //�����ܸ���++
	}
	fclose(fp);	/*�ر��ļ�*/

	/*��������ĸ��ֲ�����
	������������׵�ַ
	�����д�����Ԫ������
	�����и�Ԫ�ص�ռ���ֽڴ�С
	�Ƚ���*/
	qsort(words, num, sizeof(table), comp1);

	FILE* fa;
	if (m == 2)
		/*˳����˳�����*/
		fa = fopen("OutFile1.txt", "w+");
	else
		/*�۰����*/
		fa = fopen("OutFile3.txt", "w+");

	/*д���ļ�*/
	fprintf(fa, "%d\n", t.allcnt);
	for (i = num-1; i >= 0; --i) {
		//if ((words[i].cnt) / num < 0.1) {  /*�ʹ�Ƶ����*/
		//	continue;
		//}
		//else
		fprintf(fa, "%s\t%d\n", words[i].head, words[i].cnt);
	}
	fclose(fa);
	return;
}

/*˳����˳�����*/
void Table_Order_Select() {
	char temp[255] = { 0 };
	int flag = 0;

	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	SetColor(2, 15);
	printf("\n%s\t     �������ʲ��ҡ���", c);
	SetColor(0, 15);

	printf("%s%s����������ҵĵ��ʣ�", c1, c);
	scanf("%s", temp);
	time_t startTime = clock();		/*��¼���п�ʼʱ��*/
	/*���б���˳�����*/
	for (int i = num-1; i >= 0; --i) {
		/*���û�ҵ������ѭ��*/
		if (strcmp(words[i].head, temp) < 0 || strcmp(words[i].head, temp) > 0) {
			flag = 1;
			continue;
		}
		else {
			flag = 0;
			time_t endTime = clock();
			/*ʹ�ù�ʽclock()/CLOCKS_PER_SEC������һ���������������ʱ��*/
			double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
			double timeSize = ((num-i) + 1.0) / 2;
			printf("%s�õ��ʵĴ�ƵΪ��%d", c, words[i].cnt);
			printf("\n%s���Ҹõ��������ѵ�ʱ�䣺%.6f", c, totalTime);
			printf("\n%sƽ�����ҳ��ȣ�%.4f", c, timeSize);
			break;
		}
	}
	/*���û�ҵ���ʧ��*/
	if (flag == 1) {
		SetColor(4, 15);
		printf("%s����ʧ�ܣ�", c);
		SetColor(0, 15);
	}
	return;
}

// ���ֲ��ң�Ѱ��target���ұ߽�leftBorder��������target��
int getRightBorder(char* target) {
	int left = 0;
	int right = num - 1;
	int rightBorder = -2; // ��¼һ��rightBorderû�б���ֵ�����
	while (left <= right) {
		int middle = left + ((right - left) / 2);
		if (strlen(words[middle].head) > strlen(target)) {
			right = middle - 1;
		}
		else { // Ѱ���ұ߽磬nums[middle] <= target��ʱ�����left
			left = middle + 1;
			rightBorder = left;
		}
	}
	return rightBorder;
}

// ���ֲ��ң�Ѱ��target����߽�leftBorder��������target��
int getLeftBorder(char* target) {
	int left = 0;
	int right = num - 1;
	int leftBorder = -2; // ��¼һ��leftBorderû�б���ֵ�����
	while (left <= right) {
		int middle = left + ((right - left) / 2);
		// Ѱ����߽磬nums[middle] >= target��ʱ�����right
		if (strlen(words[middle].head) >= strlen(target)) {
			right = middle - 1;
			leftBorder = right;
		}
		else {
			left = middle + 1;
		}
	}
	return leftBorder;
}

/*�۰����*/
void Table_Binary_Select() {
	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	SetColor(2, 15);
	printf("\n%s\t     �������ʲ��ҡ���", c);
	SetColor(0, 15);

	int flag = 0;
	char temp[255] = { 0 };
	printf("%s%s����������ҵĵ��ʣ�", c1, c);
	scanf("%s", temp);

	time_t startTime = clock();

	/*���ַ�������strlen������������*/
	qsort(words, num, sizeof(table), comp2);

	/*���ҵ��ʵ����ұ߽��±�*/
	int left = getLeftBorder(temp);
	int right = getRightBorder(temp);

	/*target �����鷶Χ�У��������д���target*/
	if (right - left > 1) {
		/*���Ҫ�ҵı߽���ͬ���Ϊ�õ���ֱ�����*/
		if ((right - 1) == (left + 1)) {
			flag = 1;
			time_t endTime = clock();
			/*ʹ�ù�ʽclock()/CLOCKS_PER_SEC������һ���������������ʱ��*/
			double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
			double timeSize = log2(num + 1.0) - 1.0;
			printf("%s�õ��ʵĴ�ƵΪ��%d", c, words[left + 1].cnt);
			printf("\n%s���Ҹõ��������ѵ�ʱ�䣺%.6f", c, totalTime);
			printf("\n%sƽ�����ҳ��ȣ�%.4f", c, timeSize);
			return;
		}
		else {
			/*�ҵ����ұ߽���ڱ߽��ڽ���˳�����*/
			for (int i = left + 1; i < right; ++i) {
				/*����ҵ���*/
				if (!strcmp(words[i].head, temp)) {
					flag = 1;
					time_t endTime = clock();
					/*ʹ�ù�ʽclock()/CLOCKS_PER_SEC������һ���������������ʱ��*/
					double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
					double timeSize = log2(num + 1.0) - 1.0 + (i + 1.0) / 2;
					printf("%s�õ��ʵĴ�ƵΪ��%d", c, words[i].cnt);
					printf("\n%s���Ҹõ��������ѵ�ʱ�䣺%.6f", c, totalTime);
					printf("\n%sƽ�����ҳ��ȣ�%.4f", c, timeSize);
					break;
				}
			}
		}
	}

	/*target �����鷶Χ���ұ߻������||
	target �����鷶Χ�У��������в�����target*/
	if (flag == 0 || (right == -2 || left == -2)) {
		SetColor(4, 15);
		printf("%s����ʧ�ܣ�", c);
		SetColor(0, 15);
	}
	return;
}
