#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char trash_can[10001]; //回收多余字符，增强程序健壮性
char a[20] = "key.txt";//储存被加密密码文件名
char b[20] = "password.txt";//储存密码文件名
char c[20] = "keydata.txt";//储存被加密数据文件名
char d[20] = "data.txt";//储存数据文件名
struct node {
	char no[12];/*学号*/
	char name[40];/*姓名*/
	char tele[20];/*电话号码*/
	char jg[60];/*籍贯*/
	char addr[80];/*通讯地址*/
	char D[18];/*身份证号码*/
	struct node *next;
};

void DisplayMainMenu() {
//	system("color fc");
	printf("**********************欢迎进入学籍信息系统**********************\n");
	printf("\t\t\t(1) 数据录入\n ");
	printf("\t\t\t(2) 数据查询\n ");
	printf("\t\t\t(3) 数据修改\n ");
	printf("\t\t\t(4) 数据删除\n ");
	printf("\t\t\t(5) 数据插入\n ");
	printf("\t\t\t(6) 退出程序\n ");
	printf("\t\t\t(7) 修改密码\n ");
	printf("\t\t\t(8) 导出数据\n ");
	printf("****************************************************************\n");
	printf("请输入你要执行的任务序号1~8:");
}

struct node *CreateLink() {/*尾插法建立链表*/
	node *head = (node *)malloc(sizeof(node));
	/*临时存储数据数组*/
	char no[12];
	char name[40];
	char tele[20];
	char jg[60];
	char addr[80];
	char D[18];
	node *p, * q;
	p = q = head; //初始化双指针指向头结点
	FILE *fp = fopen("data.txt", "a+");//可读/写数据，原来的文件不被删去，位置指针移到文件末尾
	//若文件不存在则新建文件，避免打不开文件情况出现
	while (fscanf(fp, "%s %s %s %s %s %s\n", no, name, tele, jg, addr, D) != EOF) {//数据从文件到数组临时存储
		q = (node *)malloc(sizeof(node)); //开辟下一个新节点
		/*数组中数据存入链表*/
		strcpy(q->no, no);
		strcpy(q->name, name);
		strcpy(q->tele, tele);
		strcpy(q->jg, jg);
		strcpy(q->addr, addr);
		strcpy(q->D, D);
		/*建立结点间连接*/
		p->next = q;
		p = q;
	}
	p->next = NULL;
	fclose(fp);
	return head;
}

void DataInput() {//数据录入函数原型
	/*临时存储数据数组*/
	char no[12];/*学号*/
	char name[40];/*姓名*/
	char tele[20];/*电话号码*/
	char jg[60];/*籍贯*/
	char addr[80];/*通讯地址*/
	char D[19];/*身份证号码*/
	char a, b;

	char trash_can[80];
	puts("Enter 学生学号:");
	while (gets(no) != NULL && no[0] != '\0') { //每次录入前读取到空行就结束录入
		puts("Enter 学生姓名:");
		gets(name);
		puts("Enter 学生电话号码:");
		gets(tele);
		puts("Enter 学生籍贯:");
		gets(jg);
		puts("Enter 学生通讯地址:");
		gets(addr);
		puts("Enter 身份证号码:");
		gets(D);
		printf("确定要录入该数据么（仅读取输入第一个字符）y/anything else:");
		scanf("%c", &b);
		gets(trash_can);//回收多余字符
		if (b == 'y') {
			FILE *fp;
			fp = fopen("data.txt", "a+");
			//程序开始时运行文件就已存在或新被建立，不存在打不开文件的情况
			fprintf(fp, "%s %s %s %s %s %s\n", no, name, tele, jg, addr, D);
			fclose(fp);
			printf("成功录入");
		} else
			printf("成功取消录入");
		puts("empty line to stop\tor\tEnter anything to continue :\n");
		if (a = getchar() != '\n') {
			printf("Enter 学生学号\n");
			gets(trash_can);//回收多余字符
			continue;
		} else
			printf("Bye!\n");
	}
}

struct node *DataSearch(node *head) {//数据查询函数原型
	char num[13];//存储查找的学号值
	int flag = 0;
	if (head->next == NULL) {
		printf("\nThe list is void!\n");
		return head;
	}
	printf("输入查找学生的学号");
	scanf("%s", num);
	struct node *p1;
	p1 = head; //初始化指针指向头结点

	while (p1->next != NULL) {//将Pl指针不断向后移动，搜索目标结点
		p1 = p1->next;
		if (atoi(num) == atoi(p1->no)) {
			if (flag == 0) {
				printf("找到下列数据\n");
				printf("\n学号\t\t姓名\t 电话号码\t 籍贯\t\t通讯地址\t  身份证号码\n");
			}
			flag = 1;
			printf("%s \t%s \t%s \t %s \t%s \t\t  %s\n", p1->no, p1->name, p1->tele, p1->jg, p1->addr, p1->D);
		}
	}
	if (flag == 0)
		printf("\nThe node is not found!\n");
	return head;
}

struct node *DataChange(node *head) {//数据修改函数原型
	/*临时存储数据数组*/
	char num[13];
	char no[12];/*学号*/
	char name[40];/*姓名*/
	char tele[20];/*电话号码*/
	char jg[60];/*籍贯*/
	char addr[80];/*通讯地址*/
	char D[19];/*身份证号码*/
	/*收集并储存信息*/
	if (head->next == NULL) {
		printf("\nThe list is void!\n");
		return head;
	}
	printf("输入查找的学号");
	scanf("%s", num);
	getchar();//回收回车
	char a;
	struct node *p1, * p2;
	//空链表，不做任何处理
	p1 = head;
	//将Pl指针不断向后移动，搜索目标结点
	while (atoi(num) != atoi(p1->no) && p1->next != NULL) {
		p2 = p1;
		p1 = p1->next;
	}
	if (atoi(num) == atoi(p1->no)) {
		printf("找到下列数据\n");
		printf("\n学号\t\t姓名\t 电话号码\t 籍贯\t\t通讯地址\t  身份证号码\n");
		printf("%s \t%s \t%s \t %s \t%s \t\t  %s\n", p1->no, p1->name, p1->tele, p1->jg, p1->addr, p1->D);
		/*收集并储存信息多信息待开发*/
		puts("Enter 学生学号:");
		gets(no);
		puts("Enter 学生姓名:");
		gets(name);
		puts("Enter 学生电话号码:");
		gets(tele);
		puts("Enter 学生籍贯:");
		gets(jg);
		puts("Enter 学生通讯地址:");
		gets(addr);
		puts("Enter 身份证号码:");
		gets(D);
		printf("确定要修改该数据么y/anything:");
		scanf("%c", &a);
		gets(trash_can);//回收多余字符
		if (a == 'y') {
			strcpy(p1->name, name);
			strcpy(p1->tele, tele);
			strcpy(p1->no, no);
			strcpy(p1->D, D);
			strcpy(p1->jg, jg);
			strcpy(p1->addr, addr);
			node *p = head->next;
			printf("修改后数据");
			printf("\n学号\t\t姓名\t 电话号码\t 籍贯\t\t通讯地址\t  身份证号码\n");
			printf("%s \t%s \t%s \t %s \t%s \t\t  %s\n", p1->no, p1->name, p1->tele, p1->jg, p1->addr, p1->D);
		} else
			printf("取消修改成功");
	} else
		printf("\nThe node is not found!\n");
	return head;
}

struct node *DataDele(struct node *head) {
	char a;
	int position;
	if (head->next == NULL) {
		printf("\nThe list is void!\n");
		return head;	//空链表，不做任何处理
	}
	node *p = head->next;
	int i = 1;
	printf("\n序号\t 学号\t\t姓名\t 电话号码\t 籍贯\t\t通讯地址\t  身份证号码\n");
	while (p) {
		//输出链表节点数据到屏幕
		printf("(%d)\t %s \t%s \t%s \t %s \t%s \t\t  %s\n", i++, p->no, p->name, p->tele, p->jg, p->addr, p->D);
		p = p->next;
	}

TX:
	printf("输入删除学生序号：");
	scanf("%d", &position);
	gets(trash_can);//回收多余字符
	if ( position <= 0 || position >= i) {
		printf("\n\n输入错误,请再次输入\n");
		goto TX;
	}
	struct node *p1, * p2;
	p1 = head;
	while (position > 0 && p1->next != NULL) {
		position--;
		p2 = p1;
		p1 = p1->next;
	}

	printf("确定要删除该数据么（仅读取输入第一个字符）y/anything else:");
	scanf("%c", &a);
	gets(trash_can);//回收多余字符
	if (a == 'y') {
		if (p1 != head->next)
			p2->next = p1->next;
		else
			head->next = p1->next;
		free(p1);
		printf("\n删除成功\n");
	} else {
		printf("\n取消删除成功\n");
		return head;
	}
	return head;
}

void ReLink(node *head) {
	node *p = head->next;
	FILE *w = fopen("data.txt", "w");//只能向文件写数据，若指定的文件不存在则创建它，如果存在则先删除它再重建一个新文件
	//每次更新链表重写所有文件，程序开始时运行文件就已存在或新被建立，不存在打不开文件的情况
	while (p) {//遍历链表将数据存入文件
		fprintf(w, "%s %s %s %s %s %s\n", p->no, p->name, p->tele, p->jg, p->addr, p->D);
		p = p->next;
	}
	printf("\n");
	fclose(w);
	return;
}

void save(node *head, char *way) {
	node *p = head->next;
	FILE *w = fopen(way, "r");
	if (w == NULL) {	//路径下无重名文件
		FILE *w = fopen(way, "w");//只能向文件写数据，若指定的文件不存在则创建它，如果存在则先删除它再重建一个新文件
		fprintf(w, "学号\t\t姓名\t 电话号码\t\t 籍贯\t\t通讯地址\t\t  身份证号码\n");
		while (p) {//遍历链表将数据存入文件
			fprintf(w, "%s \t%s \t%s \t %s \t%s \t\t  %s\n", p->no, p->name, p->tele, p->jg, p->addr, p->D);
			p = p->next;
		}
		printf("\n");
		fclose(w);
	} else {
		printf("路径下有重名文件请更改路径或更换文件名重试\n");
		fclose(w);
	}
}

struct node *DataInsert(struct node *head) {
	int i = 1;
	node *p = head->next;
	char  a;
	printf("\n序号\t 学号\t\t姓名\t 电话号码\t 籍贯\t\t通讯地址\t  身份证号码\n");
	while (p) {
		//输出链表节点数据到屏幕
		printf("(%d)\t %s \t%s \t%s \t %s \t%s \t\t  %s\n", i++, p->no, p->name, p->tele, p->jg, p->addr, p->D);
		p = p->next;
	}
	if (i == 1)
		printf("\n!!!!!链表为空，输入-1直接添加\n\n");
	double position;
TX:
	printf("(1)在尾部插入输入-1\n(2)插入在第几行之前输入1~n\n\n请输入插入位置(输入-2取消插入操作)：");
	scanf("%lf", &position);
	gets(trash_can);//回收多余字符
	if (position == -2) {
		printf("取消本次插入操作成功");
		return head;
	}
	if (position == 0 || (int)position < -1 || int(position) != position || position >= i) {
		printf("\n\n输入错误,请再次输入\n");
		goto TX;
	}
	char no[12];/*学号*/
	char name[40];/*姓名*/
	char tele[20];/*电话号码*/
	char D[18];/*身份证号码*/
	char jg[60];/*籍贯*/
	char addr[80];/*通讯地址*/
	struct node *p1, * p2;
	p1 = head;
	puts("Enter 学生学号:");
	getchar();
	gets(no);
	puts("Enter 学生姓名:");
	gets(name);
	puts("Enter 学生电话号码:");
	gets(tele);
	puts("Enter 学生籍贯:");
	gets(jg);
	puts("Enter 学生通讯地址:");
	gets(addr);
	puts("Enter 身份证号码:");
	gets(D);
	/*收集并储存信息*/
	printf("确定要在该行前插入该数据么 （仅读取输入第一个字符）y/anything else:");
	scanf("%c", &a);
	if (a == 'y') {
		//在尾部插入
		if (position == -1) {
			while (p1->next != NULL) {
				p2 = p1;
				p1 = p1->next;
			}
			p2 = (node *)malloc(sizeof(node));
			p1->next = p2;
			p2->next = NULL;
			strcpy(p2->name, name);
			strcpy(p2->tele, tele);
			strcpy(p2->no, no);
			strcpy(p2->D, D);
			strcpy(p2->jg, jg);
			strcpy(p2->addr, addr);
		}
		// 在某个位置插入
		if (position > 0) {
			while (position > 0 && p1->next != NULL) {
				position--;
				p2 = p1;
				p1 = p1->next;
			}
			struct node *newnode = (node *)malloc(sizeof(node));
			p2->next = newnode;
			strcpy(newnode->name, name);
			strcpy(newnode->tele, tele);
			strcpy(newnode->no, no);
			strcpy(newnode->D, D);
			strcpy(newnode->jg, jg);
			strcpy(newnode->addr, addr);
			newnode->next = p1;
		}
		printf("插入成功");
	} else
		printf("取消插入成功");
	return head;
}

void encryption (char *infname, char *outfname) { //加密解密函数
	int key = 24;
	FILE *fp1, *fp2;
	fp1 = fopen(infname, "r");
	fp2 = fopen(outfname, "w" );
	char ch1 = fgetc(fp1);
	while (ch1 != EOF) {
		fputc(ch1 ^ key, fp2);
		ch1 = fgetc(fp1);
	} //将需加密文件加密后保存到文件中
	fp1 = fopen(infname, "w" );//清空
	fclose(fp1);
	fclose(fp2);
}

void COSpassword() {
START:
	FILE *pf = fopen("password.txt", "w");
	char password[80];
	printf("请输入密码:");
	gets(password);
	if (password[0] == '\0' || password[0] == '\n') {
		printf("\n密码不能为空，请重新设置\n");
		goto START;
	}
	fprintf(pf, "%s", password);
	fclose(pf);
	pf = NULL;//及时置NULL
}

int Check(char word[]) {
	FILE *pf = fopen("password.txt", "r");
	if (pf == NULL) {
		printf("首次使用登陆密码未设置\n");
		FILE *pf = fopen("password.txt", "a+");
		COSpassword();
		return 1;
	}
	char password[80];
	fscanf(pf, "%s", password);
	if (strcmp(password, word) == 0)
		printf("密码输入正确\n");
	else
		return 0;
	fclose(pf);
	pf = NULL;//及时置NULL
	return 1;
}



int main() {
	FILE *pf = fopen("key.txt", "r");
	char ch1 = fgetc(pf);
	if (pf != NULL && ch1 != EOF)
		encryption(a, b); //解密密码
	ch1 = fgetc(pf);
	pf = fopen("keydata.txt", "r");
	if (pf != NULL && ch1 != EOF)
		encryption(c, d); //解密文件
	char password[80];
	pf = fopen("password.txt", "r");
	fclose(pf);
	if (pf != NULL) {
		printf("请输入密码:");
		gets(password);
	}
	if (Check(password) == 1) {
		node *head;
		head = CreateLink();//读取文件数据建立链表
		int x, flag = 1;
		encryption(b, a);//加密密码
		while (flag) {
			DisplayMainMenu(); // 因为要多次调用工作菜单，要采用子函数的形式
			if (scanf("%d", &x) == 0)//确保输入值为整型
				x = 999;
			gets(trash_can);//回收多余字符
			switch (x) {
				case 1:
					DataInput();
					head = CreateLink();
					break;
				case 2:
					ReLink(DataSearch(head));
					break;
				case 3:
					ReLink(DataChange(head));
					break;
				case 4:
					ReLink(DataDele(head));
					break;
				case 5:
					ReLink(DataInsert(head));
					break;
				case 6:
					flag = 0;
					break;
				case 7:
					COSpassword();
					printf("\n修改密码成功\n\n");
					encryption(b, a);//加密密码
					break;
				case 8:
					char way[80];
					printf("例子：D:\abc\a.txt\n");
					printf("请输入另存为路径及文件名:");
					gets(way);
					save(head, way);
					break;
				default:
					printf("\n输入错误\n\n");
					gets(trash_can);//回收多余字符
					break;
			}

		}
		encryption(d, c);//加密文件
		return 0;
	} else
		printf("\n密码输入错误\n\n");
	return 0;
}
