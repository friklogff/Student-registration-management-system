#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char trash_can[10001]; //���ն����ַ�����ǿ����׳��
char a[20] = "key.txt";//���汻���������ļ���
char b[20] = "password.txt";//���������ļ���
char c[20] = "keydata.txt";//���汻���������ļ���
char d[20] = "data.txt";//���������ļ���
struct node {
	char no[12];/*ѧ��*/
	char name[40];/*����*/
	char tele[20];/*�绰����*/
	char jg[60];/*����*/
	char addr[80];/*ͨѶ��ַ*/
	char D[18];/*���֤����*/
	struct node *next;
};

void DisplayMainMenu() {
//	system("color fc");
	printf("**********************��ӭ����ѧ����Ϣϵͳ**********************\n");
	printf("\t\t\t(1) ����¼��\n ");
	printf("\t\t\t(2) ���ݲ�ѯ\n ");
	printf("\t\t\t(3) �����޸�\n ");
	printf("\t\t\t(4) ����ɾ��\n ");
	printf("\t\t\t(5) ���ݲ���\n ");
	printf("\t\t\t(6) �˳�����\n ");
	printf("\t\t\t(7) �޸�����\n ");
	printf("\t\t\t(8) ��������\n ");
	printf("****************************************************************\n");
	printf("��������Ҫִ�е��������1~8:");
}

struct node *CreateLink() {/*β�巨��������*/
	node *head = (node *)malloc(sizeof(node));
	/*��ʱ�洢��������*/
	char no[12];
	char name[40];
	char tele[20];
	char jg[60];
	char addr[80];
	char D[18];
	node *p, * q;
	p = q = head; //��ʼ��˫ָ��ָ��ͷ���
	FILE *fp = fopen("data.txt", "a+");//�ɶ�/д���ݣ�ԭ�����ļ�����ɾȥ��λ��ָ���Ƶ��ļ�ĩβ
	//���ļ����������½��ļ�������򲻿��ļ��������
	while (fscanf(fp, "%s %s %s %s %s %s\n", no, name, tele, jg, addr, D) != EOF) {//���ݴ��ļ���������ʱ�洢
		q = (node *)malloc(sizeof(node)); //������һ���½ڵ�
		/*���������ݴ�������*/
		strcpy(q->no, no);
		strcpy(q->name, name);
		strcpy(q->tele, tele);
		strcpy(q->jg, jg);
		strcpy(q->addr, addr);
		strcpy(q->D, D);
		/*������������*/
		p->next = q;
		p = q;
	}
	p->next = NULL;
	fclose(fp);
	return head;
}

void DataInput() {//����¼�뺯��ԭ��
	/*��ʱ�洢��������*/
	char no[12];/*ѧ��*/
	char name[40];/*����*/
	char tele[20];/*�绰����*/
	char jg[60];/*����*/
	char addr[80];/*ͨѶ��ַ*/
	char D[19];/*���֤����*/
	char a, b;

	char trash_can[80];
	puts("Enter ѧ��ѧ��:");
	while (gets(no) != NULL && no[0] != '\0') { //ÿ��¼��ǰ��ȡ�����оͽ���¼��
		puts("Enter ѧ������:");
		gets(name);
		puts("Enter ѧ���绰����:");
		gets(tele);
		puts("Enter ѧ������:");
		gets(jg);
		puts("Enter ѧ��ͨѶ��ַ:");
		gets(addr);
		puts("Enter ���֤����:");
		gets(D);
		printf("ȷ��Ҫ¼�������ô������ȡ�����һ���ַ���y/anything else:");
		scanf("%c", &b);
		gets(trash_can);//���ն����ַ�
		if (b == 'y') {
			FILE *fp;
			fp = fopen("data.txt", "a+");
			//����ʼʱ�����ļ����Ѵ��ڻ��±������������ڴ򲻿��ļ������
			fprintf(fp, "%s %s %s %s %s %s\n", no, name, tele, jg, addr, D);
			fclose(fp);
			printf("�ɹ�¼��");
		} else
			printf("�ɹ�ȡ��¼��");
		puts("empty line to stop\tor\tEnter anything to continue :\n");
		if (a = getchar() != '\n') {
			printf("Enter ѧ��ѧ��\n");
			gets(trash_can);//���ն����ַ�
			continue;
		} else
			printf("Bye!\n");
	}
}

struct node *DataSearch(node *head) {//���ݲ�ѯ����ԭ��
	char num[13];//�洢���ҵ�ѧ��ֵ
	int flag = 0;
	if (head->next == NULL) {
		printf("\nThe list is void!\n");
		return head;
	}
	printf("�������ѧ����ѧ��");
	scanf("%s", num);
	struct node *p1;
	p1 = head; //��ʼ��ָ��ָ��ͷ���

	while (p1->next != NULL) {//��Plָ�벻������ƶ�������Ŀ����
		p1 = p1->next;
		if (atoi(num) == atoi(p1->no)) {
			if (flag == 0) {
				printf("�ҵ���������\n");
				printf("\nѧ��\t\t����\t �绰����\t ����\t\tͨѶ��ַ\t  ���֤����\n");
			}
			flag = 1;
			printf("%s \t%s \t%s \t %s \t%s \t\t  %s\n", p1->no, p1->name, p1->tele, p1->jg, p1->addr, p1->D);
		}
	}
	if (flag == 0)
		printf("\nThe node is not found!\n");
	return head;
}

struct node *DataChange(node *head) {//�����޸ĺ���ԭ��
	/*��ʱ�洢��������*/
	char num[13];
	char no[12];/*ѧ��*/
	char name[40];/*����*/
	char tele[20];/*�绰����*/
	char jg[60];/*����*/
	char addr[80];/*ͨѶ��ַ*/
	char D[19];/*���֤����*/
	/*�ռ���������Ϣ*/
	if (head->next == NULL) {
		printf("\nThe list is void!\n");
		return head;
	}
	printf("������ҵ�ѧ��");
	scanf("%s", num);
	getchar();//���ջس�
	char a;
	struct node *p1, * p2;
	//�����������κδ���
	p1 = head;
	//��Plָ�벻������ƶ�������Ŀ����
	while (atoi(num) != atoi(p1->no) && p1->next != NULL) {
		p2 = p1;
		p1 = p1->next;
	}
	if (atoi(num) == atoi(p1->no)) {
		printf("�ҵ���������\n");
		printf("\nѧ��\t\t����\t �绰����\t ����\t\tͨѶ��ַ\t  ���֤����\n");
		printf("%s \t%s \t%s \t %s \t%s \t\t  %s\n", p1->no, p1->name, p1->tele, p1->jg, p1->addr, p1->D);
		/*�ռ���������Ϣ����Ϣ������*/
		puts("Enter ѧ��ѧ��:");
		gets(no);
		puts("Enter ѧ������:");
		gets(name);
		puts("Enter ѧ���绰����:");
		gets(tele);
		puts("Enter ѧ������:");
		gets(jg);
		puts("Enter ѧ��ͨѶ��ַ:");
		gets(addr);
		puts("Enter ���֤����:");
		gets(D);
		printf("ȷ��Ҫ�޸ĸ�����ôy/anything:");
		scanf("%c", &a);
		gets(trash_can);//���ն����ַ�
		if (a == 'y') {
			strcpy(p1->name, name);
			strcpy(p1->tele, tele);
			strcpy(p1->no, no);
			strcpy(p1->D, D);
			strcpy(p1->jg, jg);
			strcpy(p1->addr, addr);
			node *p = head->next;
			printf("�޸ĺ�����");
			printf("\nѧ��\t\t����\t �绰����\t ����\t\tͨѶ��ַ\t  ���֤����\n");
			printf("%s \t%s \t%s \t %s \t%s \t\t  %s\n", p1->no, p1->name, p1->tele, p1->jg, p1->addr, p1->D);
		} else
			printf("ȡ���޸ĳɹ�");
	} else
		printf("\nThe node is not found!\n");
	return head;
}

struct node *DataDele(struct node *head) {
	char a;
	int position;
	if (head->next == NULL) {
		printf("\nThe list is void!\n");
		return head;	//�����������κδ���
	}
	node *p = head->next;
	int i = 1;
	printf("\n���\t ѧ��\t\t����\t �绰����\t ����\t\tͨѶ��ַ\t  ���֤����\n");
	while (p) {
		//�������ڵ����ݵ���Ļ
		printf("(%d)\t %s \t%s \t%s \t %s \t%s \t\t  %s\n", i++, p->no, p->name, p->tele, p->jg, p->addr, p->D);
		p = p->next;
	}

TX:
	printf("����ɾ��ѧ����ţ�");
	scanf("%d", &position);
	gets(trash_can);//���ն����ַ�
	if ( position <= 0 || position >= i) {
		printf("\n\n�������,���ٴ�����\n");
		goto TX;
	}
	struct node *p1, * p2;
	p1 = head;
	while (position > 0 && p1->next != NULL) {
		position--;
		p2 = p1;
		p1 = p1->next;
	}

	printf("ȷ��Ҫɾ��������ô������ȡ�����һ���ַ���y/anything else:");
	scanf("%c", &a);
	gets(trash_can);//���ն����ַ�
	if (a == 'y') {
		if (p1 != head->next)
			p2->next = p1->next;
		else
			head->next = p1->next;
		free(p1);
		printf("\nɾ���ɹ�\n");
	} else {
		printf("\nȡ��ɾ���ɹ�\n");
		return head;
	}
	return head;
}

void ReLink(node *head) {
	node *p = head->next;
	FILE *w = fopen("data.txt", "w");//ֻ�����ļ�д���ݣ���ָ�����ļ��������򴴽����������������ɾ�������ؽ�һ�����ļ�
	//ÿ�θ���������д�����ļ�������ʼʱ�����ļ����Ѵ��ڻ��±������������ڴ򲻿��ļ������
	while (p) {//�����������ݴ����ļ�
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
	if (w == NULL) {	//·�����������ļ�
		FILE *w = fopen(way, "w");//ֻ�����ļ�д���ݣ���ָ�����ļ��������򴴽����������������ɾ�������ؽ�һ�����ļ�
		fprintf(w, "ѧ��\t\t����\t �绰����\t\t ����\t\tͨѶ��ַ\t\t  ���֤����\n");
		while (p) {//�����������ݴ����ļ�
			fprintf(w, "%s \t%s \t%s \t %s \t%s \t\t  %s\n", p->no, p->name, p->tele, p->jg, p->addr, p->D);
			p = p->next;
		}
		printf("\n");
		fclose(w);
	} else {
		printf("·�����������ļ������·��������ļ�������\n");
		fclose(w);
	}
}

struct node *DataInsert(struct node *head) {
	int i = 1;
	node *p = head->next;
	char  a;
	printf("\n���\t ѧ��\t\t����\t �绰����\t ����\t\tͨѶ��ַ\t  ���֤����\n");
	while (p) {
		//�������ڵ����ݵ���Ļ
		printf("(%d)\t %s \t%s \t%s \t %s \t%s \t\t  %s\n", i++, p->no, p->name, p->tele, p->jg, p->addr, p->D);
		p = p->next;
	}
	if (i == 1)
		printf("\n!!!!!����Ϊ�գ�����-1ֱ�����\n\n");
	double position;
TX:
	printf("(1)��β����������-1\n(2)�����ڵڼ���֮ǰ����1~n\n\n���������λ��(����-2ȡ���������)��");
	scanf("%lf", &position);
	gets(trash_can);//���ն����ַ�
	if (position == -2) {
		printf("ȡ�����β�������ɹ�");
		return head;
	}
	if (position == 0 || (int)position < -1 || int(position) != position || position >= i) {
		printf("\n\n�������,���ٴ�����\n");
		goto TX;
	}
	char no[12];/*ѧ��*/
	char name[40];/*����*/
	char tele[20];/*�绰����*/
	char D[18];/*���֤����*/
	char jg[60];/*����*/
	char addr[80];/*ͨѶ��ַ*/
	struct node *p1, * p2;
	p1 = head;
	puts("Enter ѧ��ѧ��:");
	getchar();
	gets(no);
	puts("Enter ѧ������:");
	gets(name);
	puts("Enter ѧ���绰����:");
	gets(tele);
	puts("Enter ѧ������:");
	gets(jg);
	puts("Enter ѧ��ͨѶ��ַ:");
	gets(addr);
	puts("Enter ���֤����:");
	gets(D);
	/*�ռ���������Ϣ*/
	printf("ȷ��Ҫ�ڸ���ǰ���������ô ������ȡ�����һ���ַ���y/anything else:");
	scanf("%c", &a);
	if (a == 'y') {
		//��β������
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
		// ��ĳ��λ�ò���
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
		printf("����ɹ�");
	} else
		printf("ȡ������ɹ�");
	return head;
}

void encryption (char *infname, char *outfname) { //���ܽ��ܺ���
	int key = 24;
	FILE *fp1, *fp2;
	fp1 = fopen(infname, "r");
	fp2 = fopen(outfname, "w" );
	char ch1 = fgetc(fp1);
	while (ch1 != EOF) {
		fputc(ch1 ^ key, fp2);
		ch1 = fgetc(fp1);
	} //��������ļ����ܺ󱣴浽�ļ���
	fp1 = fopen(infname, "w" );//���
	fclose(fp1);
	fclose(fp2);
}

void COSpassword() {
START:
	FILE *pf = fopen("password.txt", "w");
	char password[80];
	printf("����������:");
	gets(password);
	if (password[0] == '\0' || password[0] == '\n') {
		printf("\n���벻��Ϊ�գ�����������\n");
		goto START;
	}
	fprintf(pf, "%s", password);
	fclose(pf);
	pf = NULL;//��ʱ��NULL
}

int Check(char word[]) {
	FILE *pf = fopen("password.txt", "r");
	if (pf == NULL) {
		printf("�״�ʹ�õ�½����δ����\n");
		FILE *pf = fopen("password.txt", "a+");
		COSpassword();
		return 1;
	}
	char password[80];
	fscanf(pf, "%s", password);
	if (strcmp(password, word) == 0)
		printf("����������ȷ\n");
	else
		return 0;
	fclose(pf);
	pf = NULL;//��ʱ��NULL
	return 1;
}



int main() {
	FILE *pf = fopen("key.txt", "r");
	char ch1 = fgetc(pf);
	if (pf != NULL && ch1 != EOF)
		encryption(a, b); //��������
	ch1 = fgetc(pf);
	pf = fopen("keydata.txt", "r");
	if (pf != NULL && ch1 != EOF)
		encryption(c, d); //�����ļ�
	char password[80];
	pf = fopen("password.txt", "r");
	fclose(pf);
	if (pf != NULL) {
		printf("����������:");
		gets(password);
	}
	if (Check(password) == 1) {
		node *head;
		head = CreateLink();//��ȡ�ļ����ݽ�������
		int x, flag = 1;
		encryption(b, a);//��������
		while (flag) {
			DisplayMainMenu(); // ��ΪҪ��ε��ù����˵���Ҫ�����Ӻ�������ʽ
			if (scanf("%d", &x) == 0)//ȷ������ֵΪ����
				x = 999;
			gets(trash_can);//���ն����ַ�
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
					printf("\n�޸�����ɹ�\n\n");
					encryption(b, a);//��������
					break;
				case 8:
					char way[80];
					printf("���ӣ�D:\abc\a.txt\n");
					printf("���������Ϊ·�����ļ���:");
					gets(way);
					save(head, way);
					break;
				default:
					printf("\n�������\n\n");
					gets(trash_can);//���ն����ַ�
					break;
			}

		}
		encryption(d, c);//�����ļ�
		return 0;
	} else
		printf("\n�����������\n\n");
	return 0;
}
