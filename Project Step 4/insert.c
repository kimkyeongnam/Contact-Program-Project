#include"my_define.h"

void insert(struct student *p, int *n) //1. Registration
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