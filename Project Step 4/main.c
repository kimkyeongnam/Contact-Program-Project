#include"my_define.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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