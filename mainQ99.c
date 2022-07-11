#include <stdio.h>
#include <stdlib.h>
#define IDADE_INFERIOR 18
#define IDADE_SUPERIOR 20
#define N 			   IDADE_SUPERIOR - IDADE_INFERIOR + 1


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int casamentos[N][N];
	int homem;
	int mulher;
	int hCount, mCount;
	int idadeHomem, qtdeHomem, qtdeIdade;
	int idadeMulher, qtdeMulher;
	int idadeCasalH, idadeCasalM, qtdeCasal;
	
	
	for(hCount = 0; hCount < N; hCount++)
		for(mCount = 0; mCount < N; mCount++)
			casamentos[hCount][mCount]=0;
	
	do{
		puts("Informe a idade do casal H M");
		scanf("%d %d", &homem, &mulher);
		if(homem > 0 && mulher > 0)
			casamentos[homem - IDADE_INFERIOR][mulher - IDADE_INFERIOR]++; 
	}while(homem > 0 && mulher > 0);
	
	
	for(hCount = 0; hCount < N; hCount++){
		for(mCount = 0; mCount < N; mCount++)
			printf("%d\t", casamentos[hCount][mCount]);
		printf("\n");
	}
	
	qtdeHomem = 0;
	idadeHomem = 0;
	
	for(hCount = 0; hCount < N; hCount++){
		qtdeIdade = 0;
		for(mCount = 0; mCount < N; mCount++)
			qtdeIdade += casamentos[hCount][mCount];
		if(qtdeIdade > qtdeHomem){
			qtdeHomem = qtdeIdade;
			idadeHomem = hCount + IDADE_INFERIOR;
		}
	}
	
	qtdeMulher = 0;
	idadeMulher = 0;
	
	for(mCount = 0; mCount < N; mCount++){
		qtdeIdade = 0;
		for(hCount = 0; hCount < N; hCount++)
			qtdeIdade += casamentos[hCount][mCount];
		if(qtdeIdade > qtdeMulher){
			qtdeMulher = qtdeIdade;
			idadeMulher = mCount + IDADE_INFERIOR;
		}
	}

	qtdeCasal = 0;
	idadeCasalH = idadeCasalM = 0;
		
	for(hCount = 0; hCount < N; hCount++){
		for(mCount = 0; mCount < N; mCount++)
		  if(casamentos[hCount][mCount] > qtdeCasal){
		  	qtdeCasal = casamentos[hCount][mCount];
			 idadeCasalH =  hCount + IDADE_INFERIOR;
			 idadeCasalM =  mCount + IDADE_INFERIOR;	
		  }
	}

	
	
	printf("Idade mais frequente homem : %d\n", idadeHomem);	 
	printf("Idade mais frequente mulher : %d\n", idadeMulher);	 
	printf("Idade mais frequente de casal : %d %d\n", idadeCasalH, idadeCasalM);	 	
	
	
	return 0;
}
