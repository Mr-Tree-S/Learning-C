#include <stdio.h>
#include <stdlib.h>


int main()
{
	int a, b;
	int times = 4;

	srand((unsigned)time(NULL));
	a = rand()%100;
	while (1) {
		times--;
		printf("�²��ҵ����ְɣ�0~100\n");
		scanf("%d", &b);
		if (a > b)
			printf("С�ˣ���ʣ%d�λ���\n", times);
		if (a < b)
			printf("���ˣ���ʣ%d�λ���\n", times);
		if (a == b) {
			printf("��ϲ�������\n");
			break;
		}

		if (times == 0) {
			printf("�治�ң������þ�\nϵͳ����10���ػ�\n");
//			system("shutdown -s -t 10");
			break;
		}
	}

	return 0;
}