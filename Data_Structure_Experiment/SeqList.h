#pragma once
#define MAXSIZE 5001
/*函数声明*/
void SetColor(UINT uFore, UINT uBack);
void Table_Word_Frequency(int m);
void Table_Order_Select();
int getRightBorder(char* target);
int getLeftBorder(char* target);
void Table_Binary_Select();

/*顺序表*/
typedef struct Table {
	char head[255];	/*数组,保存一个单词*/
	int cnt;  /*记录一个单词出现的次数*/
	int allcnt;	/*记录全部单词出现的次数*/
}table;

/*格式控制字符串*/
const char c[] = "\t\t\t";
const char c1[] = "\n\n\n";

/*快速排序比较器*/
// a=b 返回0
// a<b 返回负值
// a>b 返回正值
int comp1(const void* a, const void* b) {
	/*默认升序*/
	return ((table*)a)->cnt - ((table*)b)->cnt;
}

int comp2(const void* a, const void* b) {
	/*默认升序*/
	return strlen(((table*)a)->head) - strlen(((table*)b)->head);
}


table words[MAXSIZE]; /*单词汇总*/
table t{};			 /*结构体类型变量*/
int num;		/*作为words的下标*/
/*顺序表的词频统计*/
void Table_Word_Frequency(int m) {
	/*初始化*/
	num = 0;
	t.allcnt = 0;
	words[MAXSIZE] = { 0 };

	char temp[255] = { 0 }; /*接收单词*/
	char tmp[255] = { 0 }; /*接收处理的单词*/

	FILE* fp = fopen("InFile.txt", "r");
	assert(fp);	/*如果打不开文件则输出错误并停止运行*/
	int i, j, k;

	/*fscanf只接受字符串类型*/
	while (fscanf(fp, "%s", temp) != EOF) {
		int key = 0;
		/*处理的标点符号*/
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
		/*然后清空未处理的单词*/
		memset(temp, '\0', sizeof(temp));
		/*将处理过的单词后在结尾加个\0*/
		tmp[key] = '\0';
		/*tmp是否之前已经被统计过了*/
		for (i = 0; i < num; i++) {
			/*如果tmp == words[i].str，之前统计过了*/
			if (strcmp(tmp, words[i].head) == 0) {
				words[i].cnt++; /*单词次数 + 1*/
				break; /*跳出for循环*/
			}
		}
		/*若i=num，说明tmp没有被统计过*/
		if (i == num) {
			for (j = 0; tmp[j] != '\0'; j++) {
				/*复制字符串*/
				words[num].head[j] = tmp[j];
			}
			words[num].head[j] = '\0'; /*末尾处*/
			words[num].cnt = 1; /*记录下一个单词，将其次数为1*/
			num++; /*存放单词数组结构体的下标增加*/
		}
		++t.allcnt; //单词总个数++
	}
	fclose(fp);	/*关闭文件*/

	/*快速排序的各种参数：
	待排序数组的首地址
	数组中待排序元素数量
	数组中各元素的占用字节大小
	比较器*/
	qsort(words, num, sizeof(table), comp1);

	FILE* fa;
	if (m == 2)
		/*顺序表的顺序查找*/
		fa = fopen("OutFile1.txt", "w+");
	else
		/*折半查找*/
		fa = fopen("OutFile3.txt", "w+");

	/*写入文件*/
	fprintf(fa, "%d\n", t.allcnt);
	for (i = num-1; i >= 0; --i) {
		//if ((words[i].cnt) / num < 0.1) {  /*低词频过滤*/
		//	continue;
		//}
		//else
		fprintf(fa, "%s\t%d\n", words[i].head, words[i].cnt);
	}
	fclose(fa);
	return;
}

/*顺序表的顺序查找*/
void Table_Order_Select() {
	char temp[255] = { 0 };
	int flag = 0;

	system("cls");
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ——单词查找——", c);
	SetColor(0, 15);

	printf("%s%s请输入待查找的单词：", c1, c);
	scanf("%s", temp);
	time_t startTime = clock();		/*记录运行开始时间*/
	/*进行遍历顺序查找*/
	for (int i = num-1; i >= 0; --i) {
		/*如果没找到则继续循环*/
		if (strcmp(words[i].head, temp) < 0 || strcmp(words[i].head, temp) > 0) {
			flag = 1;
			continue;
		}
		else {
			flag = 0;
			time_t endTime = clock();
			/*使用公式clock()/CLOCKS_PER_SEC来计算一个进程自身的运行时间*/
			double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
			double timeSize = ((num-i) + 1.0) / 2;
			printf("%s该单词的词频为：%d", c, words[i].cnt);
			printf("\n%s查找该单词所花费的时间：%.6f", c, totalTime);
			printf("\n%s平均查找长度：%.4f", c, timeSize);
			break;
		}
	}
	/*如果没找到则失败*/
	if (flag == 1) {
		SetColor(4, 15);
		printf("%s查找失败！", c);
		SetColor(0, 15);
	}
	return;
}

// 二分查找，寻找target的右边界leftBorder（不包括target）
int getRightBorder(char* target) {
	int left = 0;
	int right = num - 1;
	int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
	while (left <= right) {
		int middle = left + ((right - left) / 2);
		if (strlen(words[middle].head) > strlen(target)) {
			right = middle - 1;
		}
		else { // 寻找右边界，nums[middle] <= target的时候更新left
			left = middle + 1;
			rightBorder = left;
		}
	}
	return rightBorder;
}

// 二分查找，寻找target的左边界leftBorder（不包括target）
int getLeftBorder(char* target) {
	int left = 0;
	int right = num - 1;
	int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况
	while (left <= right) {
		int middle = left + ((right - left) / 2);
		// 寻找左边界，nums[middle] >= target的时候更新right
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

/*折半查找*/
void Table_Binary_Select() {
	system("cls");
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ——单词查找——", c);
	SetColor(0, 15);

	int flag = 0;
	char temp[255] = { 0 };
	printf("%s%s请输入待查找的单词：", c1, c);
	scanf("%s", temp);

	time_t startTime = clock();

	/*按字符串长度strlen进行排序升序*/
	qsort(words, num, sizeof(table), comp2);

	/*查找单词的左右边界下标*/
	int left = getLeftBorder(temp);
	int right = getRightBorder(temp);

	/*target 在数组范围中，且数组中存在target*/
	if (right - left > 1) {
		/*如果要找的边界相同则就为该单词直接输出*/
		if ((right - 1) == (left + 1)) {
			flag = 1;
			time_t endTime = clock();
			/*使用公式clock()/CLOCKS_PER_SEC来计算一个进程自身的运行时间*/
			double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
			double timeSize = log2(num + 1.0) - 1.0;
			printf("%s该单词的词频为：%d", c, words[left + 1].cnt);
			printf("\n%s查找该单词所花费的时间：%.6f", c, totalTime);
			printf("\n%s平均查找长度：%.4f", c, timeSize);
			return;
		}
		else {
			/*找到左右边界后，在边界内进行顺序查找*/
			for (int i = left + 1; i < right; ++i) {
				/*如果找到了*/
				if (!strcmp(words[i].head, temp)) {
					flag = 1;
					time_t endTime = clock();
					/*使用公式clock()/CLOCKS_PER_SEC来计算一个进程自身的运行时间*/
					double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
					double timeSize = log2(num + 1.0) - 1.0 + (i + 1.0) / 2;
					printf("%s该单词的词频为：%d", c, words[i].cnt);
					printf("\n%s查找该单词所花费的时间：%.6f", c, totalTime);
					printf("\n%s平均查找长度：%.4f", c, timeSize);
					break;
				}
			}
		}
	}

	/*target 在数组范围的右边或者左边||
	target 在数组范围中，且数组中不存在target*/
	if (flag == 0 || (right == -2 || left == -2)) {
		SetColor(4, 15);
		printf("%s查找失败！", c);
		SetColor(0, 15);
	}
	return;
}
