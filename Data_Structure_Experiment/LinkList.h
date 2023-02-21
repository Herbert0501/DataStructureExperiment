#pragma once
/*存储单词数据*/
typedef struct Data {
	char* w;	/*单词*/
	int t;		/*记录词频*/
}Data;

/*链表*/
typedef struct Node {
	Data val;	/*数值*/
	struct Node* next;	/*指针域*/
}Node, * pNode;

/*虚拟头结点*/
typedef struct HeadNode {
	int allnum;	/*全部单词*/
	pNode next;	/*指针域*/
}HeadNode, * pHeadNode;


void Link_Word_Frequency();
void Link_Word_Find();
void LinkDestroy();
void SetColor(UINT uFore, UINT uBack);
void insertNodes(pHeadNode head, char* str);
pNode Link_QuicklySort(pNode begin, pNode end);
void quicksort(pNode begin, pNode end);


pHeadNode head;/*头结点*/
pNode tail = NULL;/*尾结点*/
/*词频统计函数*/
void Link_Word_Frequency() {
	FILE* fi, * fo;		/*文件指针*/
	char str[255] = "";	/*存单词*/
	char tmp[255] = "";	/*处理过的单词*/
	/*文件打开*/
	fi = fopen("InFile.txt", "r");
	assert(fi != NULL);
	/*初始化*/
	head = (pHeadNode)malloc(sizeof(HeadNode));
	head->allnum = 0;
	head->next = NULL;
	tail = NULL;

	/*读入文件*/
	while (fscanf(fi, "%s", str) != EOF) {
		/*处理标点符号*/
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
		/*然后清空未处理的单词*/
		memset(str, '\0', sizeof(str));
		/*将处理过的单词后在结尾加个\0*/
		tmp[key] = '\0';

		/*插入链表中*/
		insertNodes(head, tmp);
		/*总单词数++*/
		++head->allnum;
	}
	fclose(fi);

	/*快速排序*/
	quicksort(head->next, NULL);
	/*写入*/
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

/*链表插入函数*/
void insertNodes(pHeadNode head, char* str) {
	pNode p = head->next;

	/*检查重复的单词*/
	while (p) {
		if (strcmp(p->val.w, str) == 0) {
			++p->val.t;	/*次数加一*/
			return;		/*跳出函数*/
		}
		p = p->next;
	}
	/*如果没有该单词则新建*/
	pNode node = (pNode)malloc(sizeof(Node));
	node->val.w = (char*)malloc(sizeof(char) * strlen(str));
	/*次数设为1*/
	node->val.t = 1;
	node->next = NULL;
	/*复制单词*/
	strcpy(node->val.w, str);
	/*接下来是尾插法*/
	if (!tail) {
		head->next = node;
	}
	else {
		tail->next = node;
	}
	tail = node;
	return;
}

/*链表的查找函数*/
void Link_Word_Find() {
	int flag = 0;
	char tmp[255] = "";

	system("cls");
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ——单词查找——", c);
	SetColor(0, 15);

	printf("%s%s请输入待查找的单词：", c1, c);
	scanf("%s", tmp);

	time_t startTime = clock();

	pNode p = head->next;
	int count = 0;

	/*如果p不是空则查找*/
	while (p) {
		++count;
		/*如果相等则输出*/
		if (strcmp(p->val.w, tmp)==0) {
			flag = 1;
			time_t endTime = clock();
			/*使用公式clock()/CLOCKS_PER_SEC来计算一个进程自身的运行时间*/
			double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
			double timeSize = (count + 1.0) / 2;
			printf("%s该单词的词频为：%d", c, p->val.t);
			printf("\n%s查找该单词所花费的时间：%.6f", c, totalTime);
			printf("\n%s平均查找长度：%.4f", c, timeSize);
			break;
		}
		p = p->next;
	}
	if (flag == 0) {
		SetColor(4, 15);
		printf("%s查找失败！", c);
		SetColor(0, 15);
	}
	return;
}

/*交换函数*/
void Swap(int* p1, int* p2) {
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/*链表快速排序函数*/
/*符合快排思想*/
/*实际上就是不断地将fast遍历到的小于key的结点
交换到与slow结点的下一个节点进行交换，并移动slow*/
pNode Link_QuicklySort(pNode begin, pNode end) {
	pNode slow = begin;			/*慢指针*/
	pNode fast = begin->next;	/*快指针*/
	int val = begin->val.t;		/*记录val, 基准值*/
	char tmp[255] = "";			/*临时存储*/

	while (fast != end) {
		/*词频升序*/
		if (fast->val.t > val) {
			slow = slow->next;
			/*交换*/
			Swap(&fast->val.t, &slow->val.t);
			strcpy(tmp, fast->val.w);
			strcpy(fast->val.w, slow->val.w);
			strcpy(slow->val.w, tmp);
		}
		fast = fast->next;
	}
	/*结束循环后再次交换*/
	Swap(&begin->val.t, &slow->val.t);
	strcpy(tmp, begin->val.w);
	strcpy(begin->val.w, slow->val.w);
	strcpy(slow->val.w, tmp);

	return slow;
}
/*快排的递归调用*/
void quicksort(pNode begin, pNode end) {

	if (begin != end) {
		pNode temp = NULL;
		temp = Link_QuicklySort(begin, temp);
		/*分块进行排序*/
		quicksort(begin, temp);
		quicksort(temp->next, end);
	}
}
/*链表的销毁*/
void LinkDestroy() {
	pNode p = head->next;
	pNode tmp;
	while (p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
}