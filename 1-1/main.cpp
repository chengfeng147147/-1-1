#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000000
#define PLACES 9
int  places_judge(int n)
{
	int j = 1;
	for (int i = 1; i <= PLACES; i++)
	{
		j *= 10;
		if (n<=j-1){
			return i;
		}
	}
	return 10;
}
void get_residue(int*arr2,int max,int residue){
	for (int i = 10; i <= max; i *=10){
		*arr2 = residue % i;
		arr2++;
	}
}
void set_arr(int*arr,int*arr1,int max,int times,int *arr2){
	for (int i = 0; i <= PLACES;i++)//
	{
		arr[i] = times;
		
	}
	for (int i = 1; i <= max / 10; i *= 10){

		for (int j = 0; j <= *arr1; j++)
		{
			if (i>1 && j == *arr1){
				arr[j] += *arr2 + 1;
				arr2++;
			}
			else{
				arr[j] += i;
			}
		}
		arr1++;
		
	}

}
void get_times(int max,int*arr1,int *temp,int *times){
	for (int i = 1; i < max; i*=10)//��0-9����ѭ����������ÿһλ������
	{
		*arr1 = *temp % 10;
		arr1++;
		*temp = *temp / 10;
		*times += (*temp)*i;
	}
}
void get_minus(int places,int max,int*arr){
	arr[0] -= 1;//��1��ʼ
	for (int i = 1; i < places; i++){
		max = max / 10;
		arr[0] -= max;
	}
}
int main()
{
	

		FILE *fin, *fout;
		int temp,
			times,
			residue,
			save,
			arr[10] = { 0 },
			arr1[10] = { 0 },
			arr2[10] = { 0 },
			max = 1,
			judge=0,
		    places = 0;
		
			 
		  
		fin = fopen("input.txt", "r");
		if (fin == NULL)
		{
			printf("�ļ���ʧ�ܣ�\n");
			
		}
		fscanf(fin, "%d", &temp);
		if (fclose(fin) != 0)
		{
			printf("�ļ��ر�ʧ�ܣ�\n");
		}
		
		
		
		times = 0;//ÿһλ0-9ѭ���Ĵ�������ʼ��Ϊ��
		residue = temp;//ÿһλ�����֣���û���������0-9ѭ��������
		save = temp;
		places=places_judge(save);

		for (int i = 0; i < places; i++){
			max *= 10;
		}

		get_times(max, arr1, &temp, &times);
		get_residue(arr2, max, residue);//ȡtemp��10��n���ݵ�����
		set_arr(arr, arr1, max, times, arr2);
		
		
		get_minus(places, max, arr);

		fout = fopen("output.txt", "w");
		if (fout == NULL)
		{
			printf("�ļ���ʧ�ܣ�\n");

		}
		
		for (int i = 0; i <= 9; i++){
			fprintf(fout, "%d\n", arr[i]);
		}

		if (fclose(fout) != 0)
		{
			printf("�ļ��ر�ʧ�ܣ�\n");
		}

		
		while (1){}

	return 0;
}