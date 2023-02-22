#pragma once
#define NULLKEY -65535		/*初始化空表*/
#define HASHNUMBER 14293 /*散列表大小，质数,通过装填因子为0.7计算出*/
/*单词总量不超过10000*/

/*存数据的结构体*/
typedef struct Word {
	char* str;		/*存单词*/
	int cnt;		/*记录单词出现次数*/
}Word;

/*哈希表结构体*/
typedef struct HashTable {
	int* elem;	/*存key*/
	int* collision;	/*记录一个key的总哈希冲突次数（成功）*/
	int coll;/*记录哈希冲突（成功）*/
	int size;	/*记录哈希表长度*/
	Word val[HASHNUMBER];
	int allnum;	/*记录总单词量*/
}HashTable;

HashTable* initHashTable(HashTable* ha);
void Hash_Word_Frequency();
UINT hashIndex(const char* temp);
void insertHash(HashTable* h, char* temp);
void Hash_Search();
int hashSelect(HashTable* ha, int key, int& count, int& collcount);
void SetColor(UINT uFore, UINT uBack);

/*哈希函数*/
UINT hashIndex(const char* temp) {
	if (temp == NULL) return 0;
	UINT index = 0;	/*可以满足大部分的单词*/
	for (int i = 0; i < strlen(temp); ++i) {
		/*为每个字符串设置唯一的下标*/
		index = 31 * index + temp[i];
		/*31为乘法因子,为了更少的乘积结果冲突*/
	}
	/*除留取余法*/
	return index % HASHNUMBER;
}

/*散列表初始化创建*/
HashTable* h;
HashTable* initHashTable(HashTable* ha) {

	int m = NULLKEY;
	ha->allnum = 0;
	ha->size = HASHNUMBER;
	ha->elem = (int*)malloc(ha->size * sizeof(int));
	ha->collision = (int*)malloc(ha->size * sizeof(int));
	for (int i = 0; i < ha->size; ++i) {
		/*初始化*/
		ha->elem[i] = m;
		ha->collision[i] = 0;
	}
	return ha;
}

/*词频统计函数*/
void Hash_Word_Frequency() {
	h = (HashTable*)malloc(sizeof(HashTable));
	h = initHashTable(h);	/*初始化*/

	char temp[255] = "";	/*接收单词*/
	char tmp[255] = "";		/*存处理过的单词*/

	FILE* fi = fopen("InFile.txt", "r");
	assert(fi != NULL);
	while (fscanf(fi, "%s", temp) != EOF) {
		int t = 0;
		/*处理英文字符串*/
		for (int k = 0; k < strlen(temp); ++k) {
			if (isalpha(temp[k])) {

				if (!islower(temp[k])) {
					temp[k] = temp[k] + 32;
				}
				tmp[t] = temp[k];
				++t;
			}
			else if (temp[k] == '\'') {
				break;
			}
		}
		/*然后清空未处理的单词*/
		memset(temp, '\0', sizeof(temp));
		/*将处理过的单词后在结尾加个\0*/
		tmp[t] = '\0';
		/*插入字符串*/
		insertHash(h, tmp);
		/*总单词数++*/
		++h->allnum;
	}
	fclose(fi);
	/*写入*/
	FILE* fo = fopen("OutFile5.txt", "w+");
	fprintf(fo, "%d\n", h->allnum);
	for (int i = 0; i < HASHNUMBER; ++i) {
		if (h->elem[i] != NULLKEY) {
			fprintf(fo, "%s\t%d\n", h->val[i].str, h->val[i].cnt);
		}
	}
	fclose(fo);
}

/*插入函数*/
void insertHash(HashTable* ha, char* temp) {
	int m = NULLKEY;
	/*求散列地址*/
	UINT addr = hashIndex(temp);
	/*设为专属key*/
	int key = addr;

	int count = 1;	/*记录冲突*/
	int collcount = 0;
	/*查找是否有重复的*/
	int flag = hashSelect(ha, key, count, collcount);

	if (flag != -1) {
		/*如果找到了相同的单词就次数加一*/
		++ha->val[flag].cnt;
	}
	/*没找到重复的单词*/
	else {
		/*冲突次数置为1*/
		ha->coll = 1;
		/*找到空的地址*/
		while (ha->elem[addr] != m) {
			/*开放地址法*/
			addr = (addr + 1) % HASHNUMBER;
			/*冲突一次就++*/
			++ha->coll;
		}
		ha->elem[addr] = key;	/*对新的空值地址，赋值*/
		ha->collision[addr] = ha->coll;	/*记录总冲突*/
		ha->val[addr].str = (char*)malloc(sizeof(char) * strlen(temp));
		assert(ha->val[addr].str != nullptr);/*申请内存失败则报错*/
		strcpy(ha->val[addr].str, temp);/*将字符串拷贝到哈希表*/
		ha->val[addr].cnt = 1;	/*频率为1*/
	}

}

/*哈希查找函数,开放地址法,count,collcount用来计算查找长度*/
int hashSelect(HashTable* ha, int key, int& count, int& collcount) {

	/*记录地址*/
	int addr = key;
	while (ha->elem[addr] != key) {
		/*记录查找成功的冲突次数*/
		collcount += ha->collision[addr];

		/*开放地址法*/
		addr = (addr + 1) % HASHNUMBER;

		++count;

		if (ha->elem[addr] == NULLKEY) {
			/*找不到就返回0*/
			return -1;
		}
	}
	/*再把找到的addr的那个查找冲突次数加上去*/
	collcount += ha->collision[addr];

	return addr;
}

void Hash_Search() {
	char tmp[255] = "";
	HashTable* ha = h;
	system("cls");
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ——单词查找——", c);
	SetColor(0, 15);

	printf("%s%s请输入待查找的单词：", c1, c);
	scanf("%s", tmp);

	time_t startTime = clock();

	/*找到key*/
	UINT key = hashIndex(tmp);
	/*下面两个变量，用于计算平均查找长度(成功)*/
	int count = 1;
	int collcount = 0;
	/*找到单词地址*/
	int addr = hashSelect(ha, key, count, collcount);

	if (addr != -1) {
		time_t endTime = clock();
		/*使用公式clock()/CLOCKS_PER_SEC来计算一个进程自身的运行时间*/
		double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
		double timeSize = collcount / count;
		printf("%s该单词的词频为：%d", c, ha->val[addr].cnt);
		printf("\n%s查找该单词所花费的时间：%.6f", c, totalTime);
		printf("\n%s平均查找长度：%.4f", c, timeSize);
	}
	else {
		SetColor(4, 15);
		printf("%s查找失败！", c);
		SetColor(0, 15);
	}
	return;
}