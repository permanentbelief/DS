#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdlib.h>
#include "stdio.h"

#define N 3 //���ó�������ѧ����

//�����ṹ��
struct Student {

	int Id;//���ѧ����ѧ��
	char Name[50];//���ѧ������
	float Score[3];//������ſεĳɼ�
} stu[N];


int main() {

	int i, j;
	float Sum[3] = { 0 }, Avg[3] = { 1 };
	//��������:
	for (i = 0; i < N; i++) {

		printf("Enter [%d] Student ID And Name:\nStudent [%d]:", i + 1, i + 1);
		scanf("%d,%s", &stu[i].Id, stu[i].Name);
		for (j = 0; j < 3; j++) {

			printf("Enert [%s] Student Score [%d]:", stu[i].Name, j + 1);
			scanf("%f", &stu[i].Score[j]);

		}
	}


	//ȫ����Ϣ���
	for (i = 0; i < 60; i++){
		printf("*");
	}
	printf("\n\t\tAll %d Student\n", N);
	printf("ID\tName\tScore[1]\tScore[2]\tScore[3]\t\n");
	for (i = 0; i < N; i++) {
		printf("%d\t%s\t%f\t%f\t%f\n", stu[i].Id, stu[i].Name, stu[i].Score[0], stu[i].Score[1], stu[i].Score[2]);
	}

	//����ѧ��ƽ���ֺ��ܺ�
	for (i = 0; i < N; i++) {

		Sum[0] += stu[i].Score[0];
		Sum[1] += stu[i].Score[1];
		Sum[2] += stu[i].Score[2];
		Avg[0] = Sum[0] / 3;
		Avg[1] = Sum[1] / 3;
		Avg[2] = Sum[2] / 3;
	}

	//���ÿ�ųɼ�����Ϣ
	printf("Score_Sum[1]=%f,Score_Sum[2]=%f,Score_Sum[3]=%f\nScore_Avg[1]=%f,Score_Avg[2]=%f,Score_Avg[3]=%f\n", Sum[0], Sum[1], Sum[2], Avg[0], Avg[1], Avg[2]);

	for (i = 0; i < 60; i++) {
		printf("*");
	}
	printf("\n");
	system("pause");
	return 0;
}