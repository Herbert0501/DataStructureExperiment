#pragma once
#define NULLKEY -65535		/*��ʼ���ձ�*/
#define HASHNUMBER 14293 /*ɢ�б��С������,ͨ��װ������Ϊ0.7�����*/
/*��������������10000*/

/*�����ݵĽṹ��*/
typedef struct Word {
	char* str;		/*�浥��*/
	int cnt;		/*��¼���ʳ��ִ���*/
}Word;

/*��ϣ��ṹ��*/
typedef struct HashTable {
	int* elem;	/*��key*/
	int* collision;	/*��¼һ��key���ܹ�ϣ��ͻ�������ɹ���*/
	int coll;/*��¼��ϣ��ͻ���ɹ���*/
	int size;	/*��¼��ϣ����*/
	Word val[HASHNUMBER];
	int allnum;	/*��¼�ܵ�����*/
}HashTable;

HashTable* initHashTable(HashTable* ha);
void Hash_Word_Frequency();
UINT hashIndex(const char* temp);
void insertHash(HashTable* h, char* temp);
void Hash_Search();
int hashSelect(HashTable* ha, int key, int& count, int& collcount);
void SetColor(UINT uFore, UINT uBack);

/*��ϣ����*/
UINT hashIndex(const char* temp) {
	if (temp == NULL) return 0;
	UINT index = 0;	/*��������󲿷ֵĵ���*/
	for (int i = 0; i < strlen(temp); ++i) {
		/*Ϊÿ���ַ�������Ψһ���±�*/
		index = 31 * index + temp[i];
		/*31Ϊ�˷�����,Ϊ�˸��ٵĳ˻������ͻ*/
	}
	/*����ȡ�෨*/
	return index % HASHNUMBER;
}

/*ɢ�б��ʼ������*/
HashTable* h;
HashTable* initHashTable(HashTable* ha) {

	int m = NULLKEY;
	ha->allnum = 0;
	ha->size = HASHNUMBER;
	ha->elem = (int*)malloc(ha->size * sizeof(int));
	ha->collision = (int*)malloc(ha->size * sizeof(int));
	for (int i = 0; i < ha->size; ++i) {
		/*��ʼ��*/
		ha->elem[i] = m;
		ha->collision[i] = 0;
	}
	return ha;
}

/*��Ƶͳ�ƺ���*/
void Hash_Word_Frequency() {
	h = (HashTable*)malloc(sizeof(HashTable));
	h = initHashTable(h);	/*��ʼ��*/

	char temp[255] = "";	/*���յ���*/
	char tmp[255] = "";		/*�洦����ĵ���*/

	FILE* fi = fopen("InFile.txt", "r");
	assert(fi != NULL);
	while (fscanf(fi, "%s", temp) != EOF) {
		int t = 0;
		/*����Ӣ���ַ���*/
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
		/*Ȼ�����δ����ĵ���*/
		memset(temp, '\0', sizeof(temp));
		/*��������ĵ��ʺ��ڽ�β�Ӹ�\0*/
		tmp[t] = '\0';
		/*�����ַ���*/
		insertHash(h, tmp);
		/*�ܵ�����++*/
		++h->allnum;
	}
	fclose(fi);
	/*д��*/
	FILE* fo = fopen("OutFile5.txt", "w+");
	fprintf(fo, "%d\n", h->allnum);
	for (int i = 0; i < HASHNUMBER; ++i) {
		if (h->elem[i] != NULLKEY) {
			fprintf(fo, "%s\t%d\n", h->val[i].str, h->val[i].cnt);
		}
	}
	fclose(fo);
}

/*���뺯��*/
void insertHash(HashTable* ha, char* temp) {
	int m = NULLKEY;
	/*��ɢ�е�ַ*/
	UINT addr = hashIndex(temp);
	/*��Ϊר��key*/
	int key = addr;

	int count = 1;	/*��¼��ͻ*/
	int collcount = 0;
	/*�����Ƿ����ظ���*/
	int flag = hashSelect(ha, key, count, collcount);

	if (flag != -1) {
		/*����ҵ�����ͬ�ĵ��ʾʹ�����һ*/
		++ha->val[flag].cnt;
	}
	/*û�ҵ��ظ��ĵ���*/
	else {
		/*��ͻ������Ϊ1*/
		ha->coll = 1;
		/*�ҵ��յĵ�ַ*/
		while (ha->elem[addr] != m) {
			/*���ŵ�ַ��*/
			addr = (addr + 1) % HASHNUMBER;
			/*��ͻһ�ξ�++*/
			++ha->coll;
		}
		ha->elem[addr] = key;	/*���µĿ�ֵ��ַ����ֵ*/
		ha->collision[addr] = ha->coll;	/*��¼�ܳ�ͻ*/
		ha->val[addr].str = (char*)malloc(sizeof(char) * strlen(temp));
		assert(ha->val[addr].str != nullptr);/*�����ڴ�ʧ���򱨴�*/
		strcpy(ha->val[addr].str, temp);/*���ַ�����������ϣ��*/
		ha->val[addr].cnt = 1;	/*Ƶ��Ϊ1*/
	}

}

/*��ϣ���Һ���,���ŵ�ַ��,count,collcount����������ҳ���*/
int hashSelect(HashTable* ha, int key, int& count, int& collcount) {

	/*��¼��ַ*/
	int addr = key;
	while (ha->elem[addr] != key) {
		/*��¼���ҳɹ��ĳ�ͻ����*/
		collcount += ha->collision[addr];

		/*���ŵ�ַ��*/
		addr = (addr + 1) % HASHNUMBER;

		++count;

		if (ha->elem[addr] == NULLKEY) {
			/*�Ҳ����ͷ���0*/
			return -1;
		}
	}
	/*�ٰ��ҵ���addr���Ǹ����ҳ�ͻ��������ȥ*/
	collcount += ha->collision[addr];

	return addr;
}

void Hash_Search() {
	char tmp[255] = "";
	HashTable* ha = h;
	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	SetColor(2, 15);
	printf("\n%s\t     �������ʲ��ҡ���", c);
	SetColor(0, 15);

	printf("%s%s����������ҵĵ��ʣ�", c1, c);
	scanf("%s", tmp);

	time_t startTime = clock();

	/*�ҵ�key*/
	UINT key = hashIndex(tmp);
	/*�����������������ڼ���ƽ�����ҳ���(�ɹ�)*/
	int count = 1;
	int collcount = 0;
	/*�ҵ����ʵ�ַ*/
	int addr = hashSelect(ha, key, count, collcount);

	if (addr != -1) {
		time_t endTime = clock();
		/*ʹ�ù�ʽclock()/CLOCKS_PER_SEC������һ���������������ʱ��*/
		double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
		double timeSize = collcount / count;
		printf("%s�õ��ʵĴ�ƵΪ��%d", c, ha->val[addr].cnt);
		printf("\n%s���Ҹõ��������ѵ�ʱ�䣺%.6f", c, totalTime);
		printf("\n%sƽ�����ҳ��ȣ�%.4f", c, timeSize);
	}
	else {
		SetColor(4, 15);
		printf("%s����ʧ�ܣ�", c);
		SetColor(0, 15);
	}
	return;
}