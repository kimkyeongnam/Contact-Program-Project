#include"my_define.h"

void find_by_birth(struct student *p, int n) //4. FindBirth
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