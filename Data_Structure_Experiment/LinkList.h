#pragma once
/*�洢��������*/
typedef struct Data {
	char* w;	/*����*/
	int t;		/*��¼��Ƶ*/
}Data;

/*����*/
typedef struct Node {
	Data val;	/*��ֵ*/
	struct Node* next;	/*ָ����*/
}Node, * pNode;

/*����ͷ���*/
typedef struct HeadNode {
	int allnum;	/*ȫ������*/
	pNode next;	/*ָ����*/
}HeadNode, * pHeadNode;


void Link_Word_Frequency();
void Link_Word_Find();
void LinkDestroy();
void SetColor(UINT uFore, UINT uBack);
void insertNodes(pHeadNode head, char* str);
pNode Link_QuicklySort(pNode begin, pNode end);
void quicksort(pNode begin, pNode end);


pHeadNode head;/*ͷ���*/
pNode tail = NULL;/*β���*/
/*��Ƶͳ�ƺ���*/
void Link_Word_Frequency() {
	FILE* fi, * fo;		/*�ļ�ָ��*/
	char str[255] = "";	/*�浥��*/
	char tmp[255] = "";	/*������ĵ���*/
	/*�ļ���*/
	fi = fopen("InFile.txt", "r");
	assert(fi != NULL);
	/*��ʼ��*/
	head = (pHeadNode)malloc(sizeof(HeadNode));
	head->allnum = 0;
	head->next = NULL;
	tail = NULL;

	/*�����ļ�*/
	while (fscanf(fi, "%s", str) != EOF) {
		/*���������*/
		int k = 0;
		int key = 0;
		for (k = 0; k < strlen(str); ++k) {
			if (isalpha(str[k])) {
				if (!islower(str[k])) {
					str[k] = str[k] + 32;
				}
				tmp[key] = str[k];
				++key;
			}
			else if (str[k] == '\'') {
				break;
			}
		}
		/*Ȼ�����δ����ĵ���*/
		memset(str, '\0', sizeof(str));
		/*��������ĵ��ʺ��ڽ�β�Ӹ�\0*/
		tmp[key] = '\0';

		/*����������*/
		insertNodes(head, tmp);
		/*�ܵ�����++*/
		++head->allnum;
	}
	fclose(fi);

	/*��������*/
	quicksort(head->next, NULL);
	/*д��*/
	fo = fopen("OutFile2.txt", "w+");
	pNode p = head->next;
	fprintf(fo, "%d\n", head->allnum);
	while (p) {
		fprintf(fo, "%s\t%d\n", p->val.w, p->val.t);
		p = p->next;
	}
	fclose(fo);
	return;
}

/*������뺯��*/
void insertNodes(pHeadNode head, char* str) {
	pNode p = head->next;

	/*����ظ��ĵ���*/
	while (p) {
		if (strcmp(p->val.w, str) == 0) {
			++p->val.t;	/*������һ*/
			return;		/*��������*/
		}
		p = p->next;
	}
	/*���û�иõ������½�*/
	pNode node = (pNode)malloc(sizeof(Node));
	node->val.w = (char*)malloc(sizeof(char) * strlen(str));
	/*������Ϊ1*/
	node->val.t = 1;
	node->next = NULL;
	/*���Ƶ���*/
	strcpy(node->val.w, str);
	/*��������β�巨*/
	if (!tail) {
		head->next = node;
	}
	else {
		tail->next = node;
	}
	tail = node;
	return;
}

/*����Ĳ��Һ���*/
void Link_Word_Find() {
	int flag = 0;
	char tmp[255] = "";

	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	SetColor(2, 15);
	printf("\n%s\t     �������ʲ��ҡ���", c);
	SetColor(0, 15);

	printf("%s%s����������ҵĵ��ʣ�", c1, c);
	scanf("%s", tmp);

	time_t startTime = clock();

	pNode p = head->next;
	int count = 0;

	/*���p���ǿ������*/
	while (p) {
		++count;
		/*�����������*/
		if (strcmp(p->val.w, tmp)==0) {
			flag = 1;
			time_t endTime = clock();
			/*ʹ�ù�ʽclock()/CLOCKS_PER_SEC������һ���������������ʱ��*/
			double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
			double timeSize = (count + 1.0) / 2;
			printf("%s�õ��ʵĴ�ƵΪ��%d", c, p->val.t);
			printf("\n%s���Ҹõ��������ѵ�ʱ�䣺%.6f", c, totalTime);
			printf("\n%sƽ�����ҳ��ȣ�%.4f", c, timeSize);
			break;
		}
		p = p->next;
	}
	if (flag == 0) {
		SetColor(4, 15);
		printf("%s����ʧ�ܣ�", c);
		SetColor(0, 15);
	}
	return;
}

/*��������*/
void Swap(int* p1, int* p2) {
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/*�������������*/
/*���Ͽ���˼��*/
/*ʵ���Ͼ��ǲ��ϵؽ�fast��������С��key�Ľ��
��������slow������һ���ڵ���н��������ƶ�slow*/
pNode Link_QuicklySort(pNode begin, pNode end) {
	pNode slow = begin;			/*��ָ��*/
	pNode fast = begin->next;	/*��ָ��*/
	int val = begin->val.t;		/*��¼val, ��׼ֵ*/
	char tmp[255] = "";			/*��ʱ�洢*/

	while (fast != end) {
		/*��Ƶ����*/
		if (fast->val.t > val) {
			slow = slow->next;
			/*����*/
			Swap(&fast->val.t, &slow->val.t);
			strcpy(tmp, fast->val.w);
			strcpy(fast->val.w, slow->val.w);
			strcpy(slow->val.w, tmp);
		}
		fast = fast->next;
	}
	/*����ѭ�����ٴν���*/
	Swap(&begin->val.t, &slow->val.t);
	strcpy(tmp, begin->val.w);
	strcpy(begin->val.w, slow->val.w);
	strcpy(slow->val.w, tmp);

	return slow;
}
/*���ŵĵݹ����*/
void quicksort(pNode begin, pNode end) {

	if (begin != end) {
		pNode temp = NULL;
		temp = Link_QuicklySort(begin, temp);
		/*�ֿ��������*/
		quicksort(begin, temp);
		quicksort(temp->next, end);
	}
}
/*���������*/
void LinkDestroy() {
	pNode p = head->next;
	pNode tmp;
	while (p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
}