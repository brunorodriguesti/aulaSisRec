#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
#include <conio.h>
#include <string.h>


/*
 * Arquivo de teste sem refatoração e sem usar registro
 */


int main(int argc, char *argv[]) {
  //abre e cria os arquivos
  FILE *targets;
  FILE *ratings;
  FILE *submission;
  
  targets = fopen("targets.csv", "r");
  submission = fopen("submission.csv", "w");
  
  //estava tentando usar o baseado em usuario
  int contUsuarioAvaliouItemAlvo;
  
  //armazena as linhas dos arquivos lidos
  char linhaArquivoTarget[100];
  char linhaArquivoRating[100];
  char linhaArquivoRating2[100];
  
  
  //conta as linhas dos arquivos
  int contLinhaTarget = 0;
  int contLinhaRating = 0;
  int cabecalho=0;
  
  //variaveis auxiliares
  char *userAux=NULL;
  char *itemAlvo=NULL;
  float soma;
  int contVizinho=0;
  int contNumeradorAlvo=0;	
  int contNumeradorVizinho=0;	
  float denominadorP1;
  float denominadorOP1;
  float denominadorOP2;
  float denominadorP2;
  int contItem;
  float media;
  float numeradorVizinho[8000];
  float numeradorAlvo[8000];
  float predict;
  float similaridade;
  float numerador;
  int usuariosVizinho[8000];



//abre o arquivo com o usuário e itens a serem preditados  
  while (!feof(targets))
  {
  	fgets(linhaArquivoTarget, 100, targets);  
     
     
    //começa a contar a partir da segunda linha (sem cabeçalho)
    if(contLinhaTarget > 0){
        //captura o usuario e item do arquivo target               
      	char *usuarioAlvo = strtok(linhaArquivoTarget, ":");
		char *itemAux = strtok(NULL, ",");
		
		
		//variaveis que sao zeradas a cada loop
		int contUser = 0;
		float denominadorUserAlvo=0;
		float raizDenomidorUserAlvo=0;
		int contRat=0;
		media=0;
      	soma=0;
      	contVizinho=0;	
	    contItem=0;
	    denominadorP1=0;
	    denominadorP2=0;
   	    denominadorOP1=0;
	    denominadorOP2=0;
	    float avaliacao1[8000];  //experimentando com 8000 avaliações
   	    float avaliacao2[8000];

		
        //utiliza o userAux para saber quando trocou de usuário
		if(!userAux){
			userAux=usuarioAlvo;
			contUsuarioAvaliouItemAlvo=0;
		//	ratings = fopen("ratings.csv", "r");		
		}
		
		//verifica quando o item é trocado e abre o arquivo de avaliações
		if(!itemAlvo){
            itemAlvo= strtok(itemAux, "\n");          
             ratings = fopen("ratings.csv", "r");		                       
        }              

			
		contNumeradorAlvo=0;
        //faz uma validação para saber se o usuarioAux ainda é o usuario Alvo	
		if(strcmp(userAux, usuarioAlvo)==0){
  			while (!feof(ratings)){
				fgets(linhaArquivoRating, 100, ratings);
				//pula a primeira linha do arquivo		
				if(contRat>0){
					char *usuarioX = strtok(linhaArquivoRating, ":");
					char *itemAvaliado = strtok(NULL, ",");	
					char *avaliacaoChar = strtok(NULL, ",");
					char *data = strtok(NULL, ",");
					float avaliacao = atof(avaliacaoChar);
					int usuarioTemItem=0;
					
					//se o item avaliado exisitr
                   if(itemAvaliado != NULL){
                    soma = avaliacao+soma; //experimentando

                    //verifica se o item do arquivo é o item alvo
                    if(strcmp(itemAvaliado, itemAlvo)==0){
                        //inicia o calculo do denominador do calculo do cosseno de similaridade                    
                        denominadorP1 = (avaliacao*avaliacao)+denominadorP1;
                        avaliacao1[contItem]=avaliacao; //armazena a avaliação para futuros calculos
                        
                        //armazena 8000 vizinhos e sua posição no arquivo
                    	if(contVizinho < 8000){
                    		usuariosVizinho[contVizinho]= contRat;
							contVizinho++;
						}	
                        contItem++;                       
					}	   
                   }		
				
				   //se o usuario usuario do arquvivo Rating for o mesmo do Arquivo Target armazena a avaliação dele sobre outros itens
					if(strcmp(usuarioX, userAux) ==0 ){ 
                       numeradorAlvo[contNumeradorAlvo]=avaliacao;         
                       contNumeradorAlvo++;
                 }
				}
				contRat++;
				
		}
		fclose(ratings);	
		}

       //escreve cabeçalho do arquivo
		if(cabecalho == 0){
            cabecalho=1;   
            fprintf(submission, "UserId:ItemId,Prediction\n");
        }
        
        
        //calcula a média geral dos itens avaliados (ainda em teste, pode ser útil) 
        if(soma>0){
                media=soma/contItem;
        }

        //se o denominador 1 foi calculado tira a rais quadrada
	    if(denominadorP1 > 0){
	       	denominadorP2=sqrt(denominadorP1);
            ratings = fopen("ratings.csv", "r");		                       
	    	int i;	
	    	int exec = 0;
	    	int contRat2=0;
	    	contNumeradorVizinho=0;
	    	
	    	
	    	//procura o denominador dos vizinhos
	    	while (!feof(ratings)){
				fgets(linhaArquivoRating2, 100, ratings);
              
                //veficia a posicao dos 8000 vizinhos e habilita o exec para poder calcular o denominador dele
				for(i=0; i < 8000; i++){
					if(usuariosVizinho[i]== contRat2)
						exec = 1;	
				}
														
					if(exec == 1){
						char *usuario = strtok(linhaArquivoRating2, ":");
						char *itemAvaliado = strtok(NULL, ",");	
						char *avaliacaoChar = strtok(NULL, ",");
						char *data = strtok(NULL, ",");
						float avaliacao = atof(avaliacaoChar);
                        
                        //aqui é o denominador do item vizinho (aqui o tem um O para diferenciar do denominador do item alvo
                        denominadorOP1 = (avaliacao*avaliacao)+denominadorOP1;
                        exec=0; //desabilita a execucao para nao ficar em loop
                        
                        //calcula o numerador da similaridade do cosseno
                         numerador=avaliacao*avaliacao1[contNumeradorVizinho]+numerador;
                         contNumeradorVizinho++;
					}
     									
				
				contRat2++;
				
		}
		fclose(ratings);
            //calcula a raiz quadrada do denominador do item vizinho
     		denominadorOP2 = sqrt(denominadorOP1);		  
	    	
         }
   
        //só para vizualizar a similaridade 
     	similaridade=numerador/(denominadorOP1*denominadorOP2);
     	printf("similaridade do item alvo: %f", similaridade, itemAlvo);
    	system("pause"); //para a tela para ir conferindo
     	
       // aqui ia escrever no arquivo a predição:
        //fprintf(submission, "%s:%s,%f \n", usuarioAlvo, itemAlvo, predict);
     //	printf("Pedicao do item: %s: %f", itemAlvo, predict);
//        system("pause");
        //coloca o item como null para ser verificado novamente                
      itemAlvo=NULL;
	}
	//posição do arquivo ratings
  	contLinhaTarget++;
     
	}

//fecha os arquivos	
 fclose(submission);   
 fclose(targets);
   printf("FIM");
   system("pause");
	return 0;

}
