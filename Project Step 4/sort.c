#include"my_define.h"
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