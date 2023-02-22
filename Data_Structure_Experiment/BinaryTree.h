#pragma once
/*建立二叉树结构体*/
typedef struct TreeNode {
	int cnt;		/*记录次数*/
	char word[255];	/*存单词*/
	struct TreeNode* left, * right;	/*左右孩子*/
}TreeNode, * pTreeNode;


double TimeSize();
int calcTreeLevel(pTreeNode p);
int BinaryKSize(pTreeNode p, int k);
void Tree_Word_Frequency();
void Tree_Word_Select();
void inorder(pTreeNode root, FILE* fo);
void SetColor(UINT uFore, UINT uBack);
pTreeNode insertNode(pTreeNode p, char* temp);


int allword;/*记录全部单词数量*/
TreeNode* root;/*根节点*/
/*词频统计 */
void Tree_Word_Frequency() {
	/*初始一些变量*/
	allword = 0;
	char temp[255] = ""; /*存单词*/
	char tmp[255] = "";/*处理过的单词*/
	root = NULL;

	FILE* fi;
	fi = fopen("InFile.txt", "r");
	assert(fi != NULL);		/*若打开失败则输出崩溃并结束运行*/

	while (fscanf(fi, "%s", temp) != EOF) {
		int key = 0;
		/*处理标点符号*/
		for (int k = 0; k < strlen(temp); ++k) {
			if (isalpha(temp[k])) {
				/*大小写转化*/
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
		/*添加*/
		root = insertNode(root, tmp);
	}
	fclose(fi);

	/*写入*/
	FILE* fo = fopen("OutFile4.txt", "w+");
	fprintf(fo, "%d\n", allword);
	/*中序遍历写入*/
	inorder(root, fo);
	fclose(fo);
}
pTreeNode insertNode(pTreeNode p, char* temp) {
	/*如果结点为空就新建*/
	if (p == NULL) {
		p = (pTreeNode)malloc(sizeof(TreeNode));
		strcpy(p->word, temp);	/*拷贝*/
		p->cnt = 1;	/*次数记为1*/
		p->left = NULL;
		p->right = NULL;
		++allword;	/*单词总量++*/
	}
	else if (strcmp(p->word, temp) == 0) {
		/*相同的单词就加一*/
		++p->cnt;
		/*总单词量也++*/
		++allword;
	}
	else if (strcmp(p->word, temp) < 0) {
		/*继续向左,如果没找到就把小的放在左树*/
		p->left = insertNode(p->left, temp);
	}
	else {
		/*反之*/
		p->right = insertNode(p->right, temp);
	}
	return p;
}

/*中序遍历写入文件*/
void inorder(pTreeNode root, FILE* fo) {
	if (!root) return;
	inorder(root->left, fo);
	fprintf(fo, "%s\t%d\n", root->word, root->cnt);
	inorder(root->right, fo);
}

/*二叉树排序树的查找*/
pTreeNode TreeSearchBST(pTreeNode p, char* temp) {
	/*如果树为空 或者 找到了,则结束递归*/
	if (!p || (strcmp(p->word, temp) == 0)) return p;
	/*比较<0去左子树*/
	else if ((strcmp(p->word, temp) < 0))
		return TreeSearchBST(p->left, temp);
	/*反之*/
	else
		return TreeSearchBST(p->right, temp);
}
/*二叉树排序树的查找*/
void Tree_Word_Select() {
	system("cls");
	printf("\n%s/****基于不同策略的单词统计和检索系统****/", c);
	SetColor(2, 15);
	printf("\n%s\t     ——单词查找——", c);
	SetColor(0, 15);
	Tree_Word_Frequency();

	char temp[255] = "";
	printf("%s%s请输入待查找的单词：", c1, c);
	scanf("%s", temp);

	time_t startTime = clock();

	pTreeNode cur = root;
	/*查找函数*/
	pTreeNode p = TreeSearchBST(cur, temp);

	if (p == NULL) {
		SetColor(4, 15);
		printf("%s查找失败！", c);
		SetColor(0, 15);
	}
	else {
		double TimeS = TimeSize();
		time_t endTime = clock();
		/*使用公式clock()/CLOCKS_PER_SEC来计算一个进程自身的运行时间*/
		double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
		printf("%s该单词的词频为：%d", c, p->cnt);
		printf("\n%s查找该单词所花费的时间：%.6f", c, totalTime);
		printf("\n%s平均查找长度：%.4f", c, TimeS);
	}
	return;
}
/*统计二叉树的层数(高度)*/
int calcTreeLevel(pTreeNode p) {
	int leftlv = 0;
	int rightlv = 0;
	if (p == NULL) return 0;
	else {
		leftlv = 1 + calcTreeLevel(p->left);	//从左路返上来的层数
		rightlv = 1 + calcTreeLevel(p->right);	//从右路返上来的层数
		/*最后返回树最高的那一边的数值*/
		return (leftlv > rightlv) ? leftlv : rightlv;
	}
}
/*统计第k层有多少个元素*/
/*返回左右子树第k-1层的节点个数（因为当前树的根节点算一层，所以递归下去每次减去一层）。*/
/*只要传入的参数 k 等于1，就到达了第K层*/
int BinaryKSize(pTreeNode p, int k) {
	if (!p)
		return 0;
	else if (k == 1)
		return 1;
	else {
		return BinaryKSize(p->left, k - 1)		/*左树和右树的每层结点同时遍历*/
			+ BinaryKSize(p->right, k - 1);
	}
}
/*计算平均查找长度（成功查找成功的平均查找长度为：
∑（本层高度*本层元素个数）/节点总数*/
double TimeSize() {
	pTreeNode p = root;
	int allnode = 0;
	int level = calcTreeLevel(p);/*记录层数*/
	for (int i = 1; i <= level; ++i) {
		int count = BinaryKSize(p, i);	/*获取该层元素个数*/
		allnode += i * count;
	}
	double TimeS = (double)allnode / allword;
	return TimeS;
}