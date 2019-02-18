#include<stdio.h> //�������
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
void register_from_file(struct student *p, FILE *fp, int *n, int max_num);//5. RegFromFile
void sort(struct student *p, int *n); //�̸��� ���������� �����ϴ� �Լ�
void free_all(struct student *p, FILE *fp, int n); //6. Exit

int main()
{
	int n = 0, input, max_num, i;//�� �ο��� ���� max_num, ���� �Էµ� �ο��� n, �Է¼��� input
	struct student *p; //�����Ҵ����� ����� ���� ������ ����ü�� �����߽��ϴ�.
	FILE *fp = NULL; //�����ϰ� ó������ NULL�� ���� �������־����ϴ�.
	printf("Max_num:"); //�ִ� �Է� �ο� ����
	scanf("%d", &max_num); //�Է¹޾�
	p = (struct student*)malloc(max_num * sizeof(struct student)); //�׸�ŭ ������ ����ü�� �����Ҵ����ְ�
	while (1)
	{
		//���� ���ǿ� �´� �޴��� ��� ��µǰԲ� while�� �ȿ� �ۼ��Ͽ����ϴ�.
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
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
			register_from_file(p, fp, &n, max_num); //register_from_file�Լ��� �����ϵ��� ��������ϴ�.
			break;
		case 6:
			free_all(p, fp, n); //������ �Լ��� �̿��� �Էµ� �ڷḦ �ؽ�Ʈ�� ���� �� ���ݱ��� ����ߴ� �޸𸮸� free���ְ�
			return 0; //�������� ��������ϴ�
		}
	}
	return 0;
}

void insert(struct student *p, int *n) //1��
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

	sort(p, n); //�����Լ��� �ҷ��� ���������� �̸��� �����߽��ϴ�.
	printf("<<%d>>\n", *n); //���������� ���� ����� ����Ǿ� �ִ��� ����ϵ��� ��������ϴ�.
}

void print_all(struct student *p, int n) //2��
{
	int i;
	for (i = 0; i<n; i++)
		printf("%s %s %s\n", p[i].name, p[i].call, p[i].birth); //n�� �̿��� ���� ����� �ο��� ����ϵ��� ��������ϴ�.
}

void delete_tel(struct student *p, int *n) //3��
{
	char ar[21] = ""; //�̸��� ������ ���ڿ��迭 ar����
	int i, flag = -1; //for���� �̿��� i�� �Ȱ��� �̸��� �ִ��� �Ǵ��ϱ� ����, ���� ������ �� �ε��� ���� ������ flag����
					  //ó������ p�� ������ �� ���� �̸��� ���� ���� �ֱ� ������ flag�� �ʱⰪ�� -1�� �������־����ϴ�.
	int j = 0; //for���� �̿��� j���� 
	printf("Name:");
	scanf("%s", ar); //�̸� �Է�

	for (i = 0; i<*n; i++)
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

void find_by_birth(struct student *p, int n) //4��
{
	int chk, in_bir; //p�� �����鼭 ����(��)�� ������ ������ chk, �Է¹��� �� ������ in_bir ����
	int i, len;
	char ar[3] = ""; //p�� �����鼭 ����(��)�� ���ڿ� ���·� ������ ar ����
	printf("Birth:");
	scanf("%d", &in_bir); //ã�� ����(��)�� �Է���
	for (i = 0; i<n; i++)
	{
		len = strlen(p[i].birth); //���������� ��� ���� ���̸� ����
		ar[0] = p[i].birth[len - 4]; //ar�� ����(��)�� ���� ���·� ����
		ar[1] = p[i].birth[len - 3];
		chk = atoi(ar); //atoi�� �̿��� ar�� ������ ��ȯ
		if (in_bir == chk) //���� chk�� in_bir�� ������ �ش� ���� �̸�, ��ȭ, ������ ����ϵ��� ��������ϴ�.
			printf("%s %s %s\n", p[i].name, p[i].call, p[i].birth);
	}
}
void register_from_file(struct student *p, FILE *fp, int *n, int max_num) //5��
{
	int i, j = 0, flag = 0, len; //for���� ���� �� �ʿ��� i,j, flag�� len
	int result = 0;//result
	char nick[201] = "", c[201] = "", b[201] = ""; //nick,c,b�迭
	char save[200] = ""; //save�迭�� �����ϰ�
	fp = fopen("PHONE_BOOK.txt", "r"); //�ؽ�Ʈ������ ���ϴ�.
	fgets(save, 200, fp); //������ ���ڿ��� �޾ƿɴϴ�.
						  //������ �ѹ� �� ������ feof�� ������ �����ϱ� ����)

	while (!feof(fp)) //������ ������ �����鼭
	{
		if (strcmp(save, "") != 0) //���� ���ڿ��� ���𰡰� �����ִٸ�
		{
			if (*n == max_num) //���� �Է��ο��� �ִ� �Է� ������ �ο������
			{
				result = 2; //result�� 2�� �����ϰ�
				break; //�����ݴϴ�.
			}
			else { //�ƴ϶��, �� �� �Է� �ο��� �ִ� �Է� ������ �ο������� �۴ٸ�
				len = strlen(save); //���ڿ��� ���̸� ����
				save[len - 1] = '\0'; //�ε��� len-1�κ��� NULL�� ���ݴϴ�.
									  //fgets�� ����� ��� ���ڿ��� ���๮��+'\0'�� �ٱ� ������, ���๮�� �κ��� len-1�κ��� �ι��ڷ� ������־����ϴ�.
				for (i = 0; save[i]; i++) //save�� �迭 ���� ���� ��, �� ���鹮�� NULL�� ������ ������ �����鼭
				{
					if (save[i] != ' ' && flag == 0) //���� save[i]�� ���� ���Ⱑ �ƴϰ� flag�� 0�̸�
					{
						nick[j] = save[i]; //nick�迭�� �����մϴ�.
						j++; //���� ���� ���� j�� 1�� �����ݴϴ�.
					}
					else if (save[i] != ' ' && flag == 1) //���� save[i]�� ���� ���Ⱑ �ƴϰ� flag�� 1�̸�
					{
						c[j] = save[i]; //c�迭�� �����մϴ�.
						j++; //���� ���� ���� j�� 1�� �����ݴϴ�.
					}
					else if (save[i] != ' ' && flag == 2) //���� save[i]�� ���� ���Ⱑ �ƴϰ� flag�� 2�̸�
					{
						b[j] = save[i]; //b�迭�� �����մϴ�.
						j++; //���� ���� ���� j�� 1�� �����ݴϴ�.
					}
					else //���� ���Ⱑ ���Դٸ�,
					{
						if (flag == 0) //flag=0�϶� �̸��� �� ����
						{
							nick[j] = '\0'; //���ڿ��� ���� �����ϱ� ���� NULL�� ���ְ�,
							len = strlen(nick); //�����Ҵ����� �Է��ؾ��ϱ� ������ ���ڿ��� ���̸� ���� ���߽��ϴ�.
							p[(*n)].name = (char*)malloc((len + 1) * sizeof(char)); //���ڿ��� ����+1��ŭ �����Ҵ��Ͽ�
							strcpy(p[(*n)].name, nick); //���ڿ��� �־��ݴϴ�.
							flag++; //���� ������ call�� ���� �����̱� ������ flag�� ��ȭ�� �ݴϴ�.
						}
						else if (flag == 1) //flag=1�϶� ��ȭ��ȣ �� ����
						{
							c[j] = '\0';//���ڿ��� ���� �����ϱ� ���� NULL�� ���ְ�,
							len = strlen(c);//�����Ҵ����� �Է��ؾ��ϱ� ������ ���ڿ��� ���̸� ���� ���߽��ϴ�.
							p[(*n)].call = (char*)malloc((len + 1) * sizeof(char)); //���ڿ��� ����+1��ŭ �����Ҵ��Ͽ�
							strcpy(p[*n].call, c); //���ڿ��� �־��ݴϴ�.
							flag++; //���� ������ birth�� ���� �����̱� ������ flag�� ��ȭ�� �ݴϴ�.
						}
						j = 0; //j�� ��Ȱ���ϱ� ���� 0���� �ʱ�ȭ�����ݴϴ�.
					}
				}
				if (flag == 2) //flag=2�϶� ���� ����
				{
					b[8] = '\0';//���ڿ��� ���� �����ϱ� ���� NULL�� ���ְ�,
					len = strlen(b);//�����Ҵ����� �Է��ؾ��ϱ� ������ ���ڿ��� ���̸� ���� ���߽��ϴ�.
					p[*n].birth = (char*)malloc((len + 1) * sizeof(char)); //���ڿ��� ����+1��ŭ �����Ҵ��Ͽ�
					strcpy(p[*n].birth, b); //���ڿ��� �־��ݴϴ�.
					flag = 0; //���� �������� ���ο� ���ڿ��� �޾ƿ��� ������ 0���� �����ݴϴ�.
					(*n)++; //�� �ο��� �����߱� ������ ���� �ο����� 1�� �����ݴϴ�.
					j = 0; //j�� ��Ȱ���ϱ� ���� 0���� �ʱ�ȭ�����ݴϴ�.
				}
			}
		}
		else break; //save�� �ƹ��͵� �������� �ʴٸ� ����ϴ�.
		fgets(save, 200, fp); //������ ���ڿ��� �޾ƿɴϴ�.
	}
	fclose(fp); //������ �ݰ�
	if (result == 1) printf("OVERFLOW\n"); //�������� �ϳ��� �Է��ϴµ�, ��ġ�� OVERFLOW�� ����϶�� �߱� ������ �ִ��ο������� �Է��� �Ǿ��ٸ�, ���ڸ� ����ϰ�
	sort(p, n); //�ִ� �ο�����ŭ ���� �ƴϵ� ������� ������ �ؾ��ϱ� ������ sort�Լ��� �ҷ����ϴ�.
}

void sort(struct student *p, int *n) //�̸�����(������)
{
	int i, j; //for������ ����� i,j��
	int len; //�����Ҵ翡 ����� ���� len ����
	struct student tmp;
	for (i = 0; i<(*n); i++) //���� 2��for���� �̿���
	{
		for (j = 0; j<(*n) - 1 - i; j++)
		{
			if (strcmp(p[j].name, p[j + 1].name)>0) //�տ� �ִ� �̸��� ���������� �ڿ� �־�� �Ѵٸ�
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
}

void free_all(struct student *p, FILE *fp, int n) //6��
{
	int i; //for���� ������ ���� ����� ���� i ����
	fp = fopen("PHONE_BOOK.txt", "w"); //�ؽ�Ʈ ������ ����(������ ����� ����)

	for (i = 0; i < n; i++)//���Ͽ� �׵����� ��Ϲ����� �����մϴ�.
		fprintf(fp, "%s %s %s\n", p[i].name, p[i].call, p[i].birth);
	fclose(fp); //������ ���� ����
	for (i = 0; i < n; i++) //�����Ҵ����� �޾ұ� ������
	{
		free(p[i].name); //������ ������ free���־����ϴ�.
		free(p[i].call);
		free(p[i].birth);
	}
	free(p); //����ü ���� �����Ҵ��߱� ������ free���־����ϴ�.
}