#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	char name[21];
	char call[16];
	char birth[9];
}; //���� ���ǿ� �´� ����ü ����

void insert(struct student *p, int *n); //1. Registration
void print_all(struct student *p, int n); //2. ShowAll
void delete_tel(struct student *p, int *n); //3. Delete
void find_by_birth(struct student *p, int n); //4. FindBirth

int main()
{
	int n = 0, input;//�� �ο� n, �Է¼��� input
	struct student tel[100], *p = tel;
	while (1)
	{
		//���� ���ǿ� �´� �޴��� ��� ��µǰԲ� while�� �ȿ� �ۼ��Ͽ����ϴ�.
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");

		scanf("%d", &input); //input�� ���� �Է¹޾� 1,2,3,4,5�� �����ϴµ�
		switch (input)
		{
		case 1:
			if (n > 99) printf("OVERFLOW\n"); //���� n�� 100�̻��̸� ����ü ������ �ʰ��ϱ� ������ overflow�� ����ϵ���,
			else insert(p, &n); //�ƴϸ� insert�Լ��� �����ϵ��� ��������ϴ�.
			break;
		case 2:
			print_all(p, n); //print_all�Լ��� �����ϵ��� ��������ϴ�.
			break;
		case 3:
			if (n == 0) printf("NO MEMBER\n"); //n=0, �� �ƹ��͵� �Էµ��� �ʾ��� �� no member�� ����ϵ���,
			else delete_tel(p, &n); //�ƴϸ� delete�� �ϵ��� ��������ϴ�.
			break;
		case 4:
			find_by_birth(p, n); //find_by_birth�Լ��� �����ϵ��� ��������ϴ�.
			break;
		case 5:
			return 0;
		}
	}
	return 0;
}

void insert(struct student *p, int *n) //1�� ������ ��
{
	char ar[20] = "";	//����� ���ڿ��迭 ����,
	int i, j; //for���� ����ϱ� ���� i,j ����
	struct student tmp; //�̸��� ���������� ������ �� swap�ϱ� ���� mp ����

	printf("Name:"); //�̸� �Է�
	scanf("%s", ar); //ar�� �̸��� ������
	strcpy(p[*n].name, ar); //����ü�� �־����ϴ�.

	printf("Phone_number:"); //��ȣ �Է�
	scanf("%s", ar); //ar�� ��ȣ�� ������
	strcpy(p[*n].call, ar); //����ü�� �־����ϴ�.

	printf("Birth:"); //���� �Է�
	scanf("%s", ar); //ar�� ������ ������
	strcpy(p[*n].birth, ar); //����ü�� �־����ϴ�.
	(*n)++; //�ο��� �߰��Ǿ��� ������ ��ü �ο��� ���ϴ� *n�� +1�� ���־����ϴ�.

	for (i = 0; i < *n; i++) //���� 2��for���� �̿���
	{
		for (j = 0; j < *n - 1 - i; j++)
		{
			if (strcmp(p[j].name, p[j + 1].name) > 0) //�տ� �ִ� �̸��� ���������� �ڿ� �־�� �Ѵٸ�
			{
				tmp = p[j]; //tmp�� �̿��� �ڸ��� �������־����ϴ�
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
	printf("<<%d>>\n", *n); //���������� ���� ����� ����Ǿ� �ִ��� ����ϵ��� ��������ϴ�.
}

void print_all(struct student *p, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s %s %s\n", p[i].name, p[i].call, p[i].birth); //n�� �̿��� ���� ����� �ο��� ����ϵ��� ��������ϴ�.
}

void delete_tel(struct student *p, int *n)
{
	char ar[21] = ""; //�̸��� ������ ���ڿ��迭 ar����
	int i, flag = -1; //for���� �̿��� i// �Ȱ��� �̸��� �ִ��� �Ǵ��ϱ� ����, ���� ������ �� �ε��� ���� ������ flag����
	//ó������ p�� ������ �� ���� �̸��� ���� ���� �ֱ� ������ flag�� �ʱⰪ�� -1�� �������־����ϴ�.
	printf("Name:");
	scanf("%s", ar); //�̸� �Է�

	for (i = 0; i < *n; i++)
	{
		if (strcmp(p[i].name, ar) == 0) //for���� �̿��� ���� tel�� �ɹ��� �̸��� ar�� ���ٸ�
		{
			flag = i; //�� �ε��� ���� flag�� �����ϰ�
			break; //���߱�(���� ���ǿ��� ���������� ���ٰ� �߱⿡ �ٷ� break�� �ɾ ���� ������ ���ư����� ��������ϴ�)
		}
	}
	if (flag != -1) //���� flag�� -1�� �ƴ϶��, �� ���ַ��� �̸��� �־� flag�� �� �ε��� ���� ����Ǹ�
	{
		for (i = flag; i < *n; i++) //���� ������ ��ĭ�� ������ ��ܿ���
			p[i] = p[i + 1];
		(*n)--; //�ο��� �� �� �پ��� ������ *n�� -1�� ���־����ϴ�.
	}
}

void find_by_birth(struct student *p, int n)
{
	int chk, in_bir; //p�� �����鼭 ����(��)�� ������ ������ chk, �Է¹��� �� ������ in_bir ����
	int i;
	char ar[3] = ""; //p�� �����鼭 ����(��)�� ���ڿ� ���·� ������ ar ����
	printf("Birth:");
	scanf("%d", &in_bir); //ã�� ����(��)�� �Է���
	for (i = 0; i < n; i++)
	{
		ar[0] = p[i].birth[4]; //ar�� ����(��)�� ���� ���·� ����
		ar[1] = p[i].birth[5];
		chk = atoi(ar); //atoi�� �̿��� ar�� ������ ��ȯ
		if (in_bir == chk) //���� chk�� in_bir�� ������ �ش� ���� �̸�, ��ȭ, ������ ����ϵ��� ��������ϴ�.
			printf("%s %s %s\n", p[i].name, p[i].call, p[i].birth);
	}
}