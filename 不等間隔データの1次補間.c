#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) { 
	// int argcは引数の個数 char *argv[]は引数の文字列を指すポインタ型配列
	
	//ファイルパスの確認
	printf("%s\n", argv[1]);
	
	FILE *fp1,*fp2;
	int n,i,j,k;
	int x_max;
	double data1[20000],data2[20000],data3[20000],data4[20000];
	double dx,A;
	
	if ((fp1 = fopen(argv[1], "r"))==NULL) {
    	printf("INPUT FILE OPEN ERROR\n");
		printf("\n");
		system("pause");
    	return -1;
  	}
	
	strcat(argv[1], "_lerp.csv");
	if ((fp2 = fopen(argv[1], "w"))==NULL) {
    	printf("OUTPUT FILE OPEN ERROR\n");
		printf("\n");
		system("pause");
    	return -1;
  	}
	
	//分割数
	printf("データを何等分するかを入力\n");
	scanf("%d", &n);
	
	//データ読み込み
	j=0;
	for(i=0; i<20000; i++){
		if(fscanf(fp1, "%lf,%lf", &data1[i], &data2[i]) != EOF){
			j++;
		};
	}
	
	//dx
	x_max = (int)data1[j-1] + 1;
	for(i=0; i<=n; i++){
		data3[i] = (double)i * (double)x_max / (double)n;
	}
	
	//1次補間
	k=0;
	for(i=0; i<=n; i++){
		if(i==0){
			data4[0]=data2[0];
		}else if(i<n){
			while(data1[k] < data3[i]){
				k++;
			}
			A = (data2[k] - data2[k-1]) / (data1[k] - data1[k-1]);
			data4[i] = A * (data3[i] - data1[k-1]) + data2[k-1];
			
			fprintf(fp2, "%.16lf,%.16lf\n", data3[i], data4[i]);
		}else if(i==n){
			data4[n] = data2[n];
		}else{
			printf("処理エラー");
		}
	}
	
	//データ出力
	for(i=0; i<=n; i++){
		
	}
	
	fclose(fp1);
	fclose(fp2);
	
	//任意のキー入力で終了
	printf("\n");
	system("pause"); 
	return 0;
	
}