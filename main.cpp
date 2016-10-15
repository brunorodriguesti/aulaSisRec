#include <iomanip>
#include <stdio.h>
#include<cstring>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <stdlib.h>
#include <cstdio>


#include "Usuario.h"
#include "Item.h"
#include "UsuarioItem.h"
#include "Conteudo.h"
#include "TrataArquivos.h"


using namespace rapidjson;
using namespace std;
using std::numeric_limits;


vector<Usuario> usuariosT;
vector<Item> itemT;
vector<UsuarioItem> usuarioItemHistoricoT;
vector<Item> itemConteudoT;
vector<UsuarioItem> usuarioItemAlvoT;


void escreveArquivo(){
	int cabecalho=0;
	cout << "escrevendo arquivo "<< endl;	
	ofstream arq;
	arq.open("submission.csv");
	cout << "Escrevendo arquivo" << endl;
	if(cabecalho == 0){
		arq  << "UserId:ItemId,Prediction \n" ;
		cabecalho=1;
	}
	  if(cabecalho == 1){
	  	for(int i=0; i < usuarioItemAlvoT.size(); i++){
	  		arq << std::setprecision(16) << usuarioItemAlvoT[i].getUsuario() << ":" << usuarioItemAlvoT[i].getItem() << "," <<  usuarioItemAlvoT[i].getAvaliacao() << endl;
		}
	  }	
			
	arq.close();
	
	
}

vector<string>recuperaConteudo(string item){
	vector<string>conteudoAux;
	for(int i = 0; i < itemConteudoT.size(); i++){
		if(item.compare(itemConteudoT[i].getItem())== 0){
			for(int k=0; k < itemConteudoT[i].getGenreVector().size(); k++){
				conteudoAux.push_back(itemConteudoT[i].getGenreVector()[k]);		
		}
		
	}
}
	return conteudoAux;

}


void recomendaItem(string usuario, string item, int posicao){
	//cout<< "Recomendando. Aguarde..." << endl;
	vector<string> generoItemAlvo= recuperaConteudo(item);
	double  soma=0;
	double contGerenro=0;
	//cout << "tamanho item alvo " << generoItemAlvo.size();
	for(int i=0; i < generoItemAlvo.size(); i++){
		//cout <<  "genero do item alvo: " << generoItemAlvo[i] << endl;
		
	}
	for(int i=0; i < usuarioItemHistoricoT.size(); i++){
			//cout << "i: " << i << "usuario Historico " << usuarioItemHistoricoT[i].getUsuario() << endl;
			if(usuario.compare(usuarioItemHistoricoT[i].getUsuario()) == 0){
				//procurar conteudo do item Alvo
				//cout << "achou usuario" << " item: " << usuarioItemHistoricoT[i].getItem()<<  endl;
				//cout << "i: " << i << "usuario Historico " << usuarioItemHistoricoT[i].getUsuario() << endl;
				
				vector<string> generoItemUsuario = recuperaConteudo(usuarioItemHistoricoT[i].getItem());
				
				for(int m=0; m < generoItemUsuario.size(); m++){
					//cout << "genero item usuario: "<< generoItemUsuario[m] << endl;
					
					for(int q=0; q < generoItemAlvo.size(); q++){
						if(generoItemUsuario[m].compare(generoItemAlvo[q]) == 0){
						//	cout << "entrou item alvo for " << generoItemAlvo[q] << endl ;
							contGerenro++;
							soma=soma+usuarioItemHistoricoT[i].getAvaliacao();
						}
							
					}					
				}
								
			}
		
		}
		if(soma > 0){
			usuarioItemAlvoT[posicao].setAvaliacao(soma/contGerenro);	
		}else{
			double a, b;
			a=10;
			b=3;
			usuarioItemAlvoT[posicao].setAvaliacao(a/b);	
		}
		
	
}





int main(int argc, char** argv) {
		
	TrataArquivos arquivos;
	usuarioItemAlvoT = arquivos.abreArquivoTargets();
	usuarioItemHistoricoT  = arquivos.abreArquivoRating();
	itemConteudoT = arquivos.lerJson();

	cout << "Qt usuario item no arquivo targets: " << usuarioItemAlvoT.size() << endl;
	cout << "Qt usuario item no arquivo ratings: " << usuarioItemHistoricoT.size() << endl;
	cout << "Qt de itens no arquivo conteudo: " << itemConteudoT.size() << endl;

	cout<< "Recomendando. Aguarde..." << endl;
	
	
	for(int i=0; i < usuarioItemAlvoT.size(); i++)	{
		cout << i << endl;
		recomendaItem(usuarioItemAlvoT[i].getUsuario(), usuarioItemAlvoT[i].getItem(), i);
		//if(i == 10){
		//	break;
		//}
	}
	
	
	escreveArquivo();
	cout << "Fim" << endl;
		
		
	return 0;
}
