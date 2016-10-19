#ifndef USUARIOITEM_H
#define USUARIOITEM_H

#include<string>
#include <vector>

#include "Conteudo.h"
using namespace std;

class UsuarioItem
{
	string usuario;
	int hashUsuario;
    string item;
    int hashItem;
	double avaliacao;
	string data;
	vector<Conteudo> conteudo;
	int qtdDocumentos;
	
	public:
		void setUsuario(string usuario){
             this->usuario = usuario;  
         }
         
         string getUsuario(){
                return this->usuario;      
         }
        
        
        void setHashUsuario(int hashUsuario){
             this->hashUsuario = hashUsuario;  
         }
         
         int getHashUsuario(){
                return this->hashUsuario;      
         }
        
        void setItem(string item){
			this->item=item;
		}	
		
		string getItem(){
			return this->item;
		}
		
		
		void setHashItem(int hashItem){
			this->hashItem=hashItem;
		}	
		
		int getHashItem(){
			return this->hashItem;
		}
		
		 void setAvaliacao(double avaliacao){
			this->avaliacao=avaliacao;
		}	
		
		double getAvaliacao(){
			return this->avaliacao;
		}
		
		void setData(string data){
			this->data=data;
		}
		
		string getData(){
			return this->data;
		}
		
		void setConteudo(Conteudo conteudo){
			this->conteudo.push_back(conteudo);
		}
		
		vector<Conteudo> getConteudo(){
			return this->conteudo;
		}
		
		void setQtdDocumentos(int qtdDocumentos){
			this->qtdDocumentos=qtdDocumentos;
		}
		
		int getQtdDocumentos(){
			return this->qtdDocumentos;
		}
};

#endif
