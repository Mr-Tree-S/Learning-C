#include <stdio.h>


typedef struct student {
	int num;
	int high;
	int weight;
}S;


int main()
{
	int n;
	scanf("%d", &n);

	S m[n];
	for (int i = 0; i < n; i++) {
		m[i].num = i+1;
		scanf("%d", &m[i].high);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &m[i].weight);

	S temp;
	for (int i = 0; i < n-1; i++) {
		for	(int j = 0; j < n-1-i; j++) {
			if (m[j].high > m[j+1].high) {
				temp = m[j+1];
				m[j+1] = m[j];
				m[j] = temp;
			} else if (m[j].high == m[j+1].high && m[j].weight > m[j+1].weight) {
				temp = m[j+1];
				m[j+1] = m[j];
				m[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", m[i].num);
	printf("\n");

	return 0;
}
