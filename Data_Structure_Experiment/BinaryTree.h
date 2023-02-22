#pragma once
/*�����������ṹ��*/
typedef struct TreeNode {
	int cnt;		/*��¼����*/
	char word[255];	/*�浥��*/
	struct TreeNode* left, * right;	/*���Һ���*/
}TreeNode, * pTreeNode;


double TimeSize();
int calcTreeLevel(pTreeNode p);
int BinaryKSize(pTreeNode p, int k);
void Tree_Word_Frequency();
void Tree_Word_Select();
void inorder(pTreeNode root, FILE* fo);
void SetColor(UINT uFore, UINT uBack);
pTreeNode insertNode(pTreeNode p, char* temp);


int allword;/*��¼ȫ����������*/
TreeNode* root;/*���ڵ�*/
/*��Ƶͳ�� */
void Tree_Word_Frequency() {
	/*��ʼһЩ����*/
	allword = 0;
	char temp[255] = ""; /*�浥��*/
	char tmp[255] = "";/*������ĵ���*/
	root = NULL;

	FILE* fi;
	fi = fopen("InFile.txt", "r");
	assert(fi != NULL);		/*����ʧ���������������������*/

	while (fscanf(fi, "%s", temp) != EOF) {
		int key = 0;
		/*���������*/
		for (int k = 0; k < strlen(temp); ++k) {
			if (isalpha(temp[k])) {
				/*��Сдת��*/
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
		/*���*/
		root = insertNode(root, tmp);
	}
	fclose(fi);

	/*д��*/
	FILE* fo = fopen("OutFile4.txt", "w+");
	fprintf(fo, "%d\n", allword);
	/*�������д��*/
	inorder(root, fo);
	fclose(fo);
}
pTreeNode insertNode(pTreeNode p, char* temp) {
	/*������Ϊ�վ��½�*/
	if (p == NULL) {
		p = (pTreeNode)malloc(sizeof(TreeNode));
		strcpy(p->word, temp);	/*����*/
		p->cnt = 1;	/*������Ϊ1*/
		p->left = NULL;
		p->right = NULL;
		++allword;	/*��������++*/
	}
	else if (strcmp(p->word, temp) == 0) {
		/*��ͬ�ĵ��ʾͼ�һ*/
		++p->cnt;
		/*�ܵ�����Ҳ++*/
		++allword;
	}
	else if (strcmp(p->word, temp) < 0) {
		/*��������,���û�ҵ��Ͱ�С�ķ�������*/
		p->left = insertNode(p->left, temp);
	}
	else {
		/*��֮*/
		p->right = insertNode(p->right, temp);
	}
	return p;
}

/*�������д���ļ�*/
void inorder(pTreeNode root, FILE* fo) {
	if (!root) return;
	inorder(root->left, fo);
	fprintf(fo, "%s\t%d\n", root->word, root->cnt);
	inorder(root->right, fo);
}

/*�������������Ĳ���*/
pTreeNode TreeSearchBST(pTreeNode p, char* temp) {
	/*�����Ϊ�� ���� �ҵ���,������ݹ�*/
	if (!p || (strcmp(p->word, temp) == 0)) return p;
	/*�Ƚ�<0ȥ������*/
	else if ((strcmp(p->word, temp) < 0))
		return TreeSearchBST(p->left, temp);
	/*��֮*/
	else
		return TreeSearchBST(p->right, temp);
}
/*�������������Ĳ���*/
void Tree_Word_Select() {
	system("cls");
	printf("\n%s/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/", c);
	SetColor(2, 15);
	printf("\n%s\t     �������ʲ��ҡ���", c);
	SetColor(0, 15);
	Tree_Word_Frequency();

	char temp[255] = "";
	printf("%s%s����������ҵĵ��ʣ�", c1, c);
	scanf("%s", temp);

	time_t startTime = clock();

	pTreeNode cur = root;
	/*���Һ���*/
	pTreeNode p = TreeSearchBST(cur, temp);

	if (p == NULL) {
		SetColor(4, 15);
		printf("%s����ʧ�ܣ�", c);
		SetColor(0, 15);
	}
	else {
		double TimeS = TimeSize();
		time_t endTime = clock();
		/*ʹ�ù�ʽclock()/CLOCKS_PER_SEC������һ���������������ʱ��*/
		double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
		printf("%s�õ��ʵĴ�ƵΪ��%d", c, p->cnt);
		printf("\n%s���Ҹõ��������ѵ�ʱ�䣺%.6f", c, totalTime);
		printf("\n%sƽ�����ҳ��ȣ�%.4f", c, TimeS);
	}
	return;
}
/*ͳ�ƶ������Ĳ���(�߶�)*/
int calcTreeLevel(pTreeNode p) {
	int leftlv = 0;
	int rightlv = 0;
	if (p == NULL) return 0;
	else {
		leftlv = 1 + calcTreeLevel(p->left);	//����·�������Ĳ���
		rightlv = 1 + calcTreeLevel(p->right);	//����·�������Ĳ���
		/*��󷵻�����ߵ���һ�ߵ���ֵ*/
		return (leftlv > rightlv) ? leftlv : rightlv;
	}
}
/*ͳ�Ƶ�k���ж��ٸ�Ԫ��*/
/*��������������k-1��Ľڵ��������Ϊ��ǰ���ĸ��ڵ���һ�㣬���Եݹ���ȥÿ�μ�ȥһ�㣩��*/
/*ֻҪ����Ĳ��� k ����1���͵����˵�K��*/
int BinaryKSize(pTreeNode p, int k) {
	if (!p)
		return 0;
	else if (k == 1)
		return 1;
	else {
		return BinaryKSize(p->left, k - 1)		/*������������ÿ����ͬʱ����*/
			+ BinaryKSize(p->right, k - 1);
	}
}
/*����ƽ�����ҳ��ȣ��ɹ����ҳɹ���ƽ�����ҳ���Ϊ��
�ƣ�����߶�*����Ԫ�ظ�����/�ڵ�����*/
double TimeSize() {
	pTreeNode p = root;
	int allnode = 0;
	int level = calcTreeLevel(p);/*��¼����*/
	for (int i = 1; i <= level; ++i) {
		int count = BinaryKSize(p, i);	/*��ȡ�ò�Ԫ�ظ���*/
		allnode += i * count;
	}
	double TimeS = (double)allnode / allword;
	return TimeS;
}