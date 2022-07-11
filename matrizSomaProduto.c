#include <stdio.h>
#include <stdlib.h>

#define LIN1 3
#define COL1 2
#define LIN2 2
#define COL2 3

main(){
  float matriz1[LIN1][COL1];
  float matriz2[LIN2][COL2];  
  float soma[LIN1][COL1];    
  float produto[LIN1][COL2];  
  
  int i;
  int j;
  int k;
  
  for(i = 0; i < LIN1; i++)
    for(j = 0; j < COL1; j++){
      printf("Digite o elemento[%d, %d] da matriz 1\n", i, j);
      scanf("%f", &matriz1[i][j]);
    }  
    
  for(i = 0; i < LIN2; i++)
    for(j = 0; j < COL2; j++){
      printf("Digite o elemento[%d, %d] da matriz 2\n", i, j);
      scanf("%f", &matriz2[i][j]);
    }  
    
  if(LIN1 == LIN2 && COL1 == COL2){
      for(i = 0; i < LIN2; i++)
        for(j = 0; j < COL2; j++)
          soma[i][j] = matriz1[i][j]+ matriz2[i][j];          
          
      puts("MATRIZ SOMA");    
      
      for(i = 0; i < LIN1; i++){
        for(j = 0; j < COL1; j++)
          printf("%.2f\t", soma[i][j]);
        printf("\n");
      }    
  }
  else
    puts("Matriz Soma Inexistente");                
    
  if(COL1 == LIN2){
    puts("MATRIZ PRODUTO");       
    for(i = 0; i < LIN1; i++)
      for(j = 0; j < COL2; j++){
        produto[i][j] = 0;
        for(k = 0; k < COL1; k++)
          produto[i][j] += matriz1[i][k] * matriz2[k][j]; 
      } 
      
    for(i = 0; i < LIN1; i++){
      for(j = 0; j < COL2; j++)
        printf("%.2f\t", produto[i][j]);
      printf("\n");
    }              
              
  }    
  else
    puts("Matriz Produto Inexistente");                
  
  
  system("PAUSE");	
  return 0;
}
