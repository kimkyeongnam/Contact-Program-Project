#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	char *name;
	char *call;
	char *birth;
}; //���� ���ǿ� �´� ����ü ����

void insert(struct student *p, int *n); //1. Registration
void print_all(struct student *p, int n); //2. ShowAll
void delete_tel(struct student *p, int *n); //3. Delete
void find_by_birth(struct student *p, int n); //4. FindBirth
void free_all(struct student *p, int n); //5. Exit

int main()
{
	int n = 0, input, max_num, i;//�� �ο��� ���� max_num, ���� �Էµ� �ο��� n, �Է¼��� input
	struct student *p; //�����Ҵ����� ����� ���� ������ ����ü�� �����߽��ϴ�.
	printf("Max_num:"); //�ִ� �Է� �ο� ����
	scanf("%d", &max_num); //�Է¹޾�
	p = (struct student*)malloc(max_num * sizeof(struct student)); //�׸�ŭ ������ ����ü�� �����Ҵ����ְ�
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
			if (max_num == n || n == 100) printf("OVERFLOW\n"); //���� max_num�� n�� ������ ������ ���ǿ��� ����� ������ overflow�� ����ϵ���,
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
			free_all(p, n); //������ �Լ��� �̿��� ���ݱ��� ����ߴ� �޸𸮸� free���ְ�
			return 0; //�������� ��������ϴ�
		}
	}
	return 0;
}

void insert(struct student *p, int *n) //1�� ������ ��
{
	char ar[101] = "";	//����� ���ڿ��迭 ����,
	int i, j; //for���� ����ϱ� ���� i,j ����
	struct student tmp; //�̸��� ���������� ������ �� swap�ϱ� ���� mp ����
	int len; //���ڿ��� ���̸� ������ len ����
	printf("Name:"); //�̸� �Է�
	scanf("%s", ar); //ar�� �̸��� �����ϰ�
	len = strlen(ar); //ar�� ���̸� �缭
	p[*n].name = (char*)malloc((len + 1) * sizeof(char)); //�ش� ����ü ������ �̸��� ũ�⸸ŭ �����Ҵ��Ͽ�
	strcpy(p[*n].name, ar); //����ü�� �־����ϴ�.

	printf("Phone_number:"); //��ȣ �Է�
	scanf("%s", ar); //ar�� ��ȣ�� ������
	len = strlen(ar); //ar�� ���̸� �缭
	p[*n].call = (char*)malloc((len + 1) * sizeof(char)); //�ش� ����ü ������ ��ȭ��ȣ�� ũ�⸸ŭ �����Ҵ��Ͽ�
	strcpy(p[*n].call, ar); //����ü�� �־����ϴ�.

	printf("Birth:"); //���� �Է�
	scanf("%s", ar); //ar�� ������ ������
	len = strlen(ar); //ar�� ���̸� �缭
	p[*n].birth = (char*)malloc((len + 1) * sizeof(char)); //�ش� ����ü ������ ������ ũ�⸸ŭ �����Ҵ��Ͽ�
	strcpy(p[*n].birth, ar); //����ü�� �־����ϴ�.
	(*n)++; //�ο��� �߰��Ǿ��� ������ ��ü �ο��� ���ϴ� *n�� +1�� ���־����ϴ�.

	for (i = 0; i < *n; i++) //���� 2��for���� �̿���
	{
		for (j = 0; j < *n - 1 - i; j++)
		{
			if (strcmp(p[j].name, p[j + 1].name) > 0) //�տ� �ִ� �̸��� ���������� �ڿ� �־�� �Ѵٸ�
			{
				//�ش� �κ��� ������ �ٲ��־����ϴ�.
				//�̸� ���� ����
				len = strlen(p[j].name);
				tmp.name = (char*)malloc((len + 1) * sizeof(char));
				strcpy(tmp.name, p[j].name);
				len = strlen(p[j + 1].name);
				p[j].name = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j].name, p[j + 1].name);
				len = strlen(tmp.name);
				p[j + 1].name = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j + 1].name, tmp.name);

				//��ȣ ���� ����
				len = strlen(p[j].call);
				tmp.call = (char*)malloc((len + 1) * sizeof(char));
				strcpy(tmp.call, p[j].call);
				len = strlen(p[j + 1].call);
				p[j].call = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j].call, p[j + 1].call);
				len = strlen(tmp.call);
				p[j + 1].call = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j + 1].call, tmp.call);

				//���� ���� ����
				len = strlen(p[j].birth);
				tmp.birth = (char*)malloc((len + 1) * sizeof(char));
				strcpy(tmp.birth, p[j].birth);
				len = strlen(p[j + 1].birth);
				p[j].birth = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j].birth, p[j + 1].birth);
				len = strlen(tmp.birth);
				p[j + 1].birth = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j + 1].birth, tmp.birth);
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
	int i, flag = -1; //for���� �̿��� i�� �Ȱ��� �̸��� �ִ��� �Ǵ��ϱ� ����, ���� ������ �� �ε��� ���� ������ flag����
					  //ó������ p�� ������ �� ���� �̸��� ���� ���� �ֱ� ������ flag�� �ʱⰪ�� -1�� �������־����ϴ�.
	int j = 0; //for���� �̿��� j���� 
	printf("Name:");
	scanf("%s", ar); //�̸� �Է�

	for (i = 0; i < *n; i++)
	{
		if (strcmp(p[i].name, ar) == 0) //for���� �̿��� ���� p�� �ɹ��� �̸��� ar�� ���ٸ�
		{
			flag = i; //�� �ε��� ���� flag�� �����ϰ�
			break; //���߱�(���� ���ǿ��� ���������� ���ٰ� �߱⿡ �ٷ� break�� �ɾ ���� ������ ���ư����� ��������ϴ�)
		}
	}
	if (flag != -1) //���� flag�� -1�� �ƴ϶��, �� ���ַ��� �̸��� �־� flag�� �� �ε��� ���� ����Ǹ�
	{
		for (i = 0; i < *n; i++) //ó������ ������ ������
		{
			if (i == flag) //���� ������ �ε��� ���� �����ϸ�
			{
				free(p[i].name); //�ش� �޸𸮸� �������ְ�
				free(p[i].call);
				free(p[i].birth);
				for (j = i + 1; j < *n; j++) //�� �������� ������ �ִ� ���Ҹ� ��ĭ�� ������ ��ܿ����� �߽��ϴ�.
					p[j - 1] = p[j];
				break; //�ڵ尡 �� ������ ���ư����� ����� ���� break�� �ɾ��־����ϴ�.
			}
		}
		(*n)--; //�ο����� �Ѹ� �پ��� ������ ��ü �ο���-1�� ���־����ϴ�.
	}
}

void find_by_birth(struct student *p, int n)
{
	int chk, in_bir; //p�� �����鼭 ����(��)�� ������ ������ chk, �Է¹��� �� ������ in_bir ����
	int i, len;
	char ar[3] = ""; //p�� �����鼭 ����(��)�� ���ڿ� ���·� ������ ar ����
	printf("Birth:");
	scanf("%d", &in_bir); //ã�� ����(��)�� �Է���
	for (i = 0; i < n; i++)
	{
		len = strlen(p[i].birth);
		ar[0] = p[i].birth[len - 4]; //ar�� ����(��)�� ���� ���·� ����
		ar[1] = p[i].birth[len - 3];
		chk = atoi(ar); //atoi�� �̿��� ar�� ������ ��ȯ
		if (in_bir == chk) //���� chk�� in_bir�� ������ �ش� ���� �̸�, ��ȭ, ������ ����ϵ��� ��������ϴ�.
			printf("%s %s %s\n", p[i].name, p[i].call, p[i].birth);
	}
}

void free_all(struct student *p, int n)
{
	int i;
	for (i = 0; i < n; i++) //�����Ҵ����� �޾ұ� ������
	{
		free(p[i].name); //������ ������ free���־����ϴ�.
		free(p[i].call);
		free(p[i].birth);
	}
	free(p); //����ü ���� �����Ҵ��߱� ������ free���־����ϴ�.
}