#include"my_define.h"

void free_all(struct student *p, FILE *fp, int n) //6. Exit
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