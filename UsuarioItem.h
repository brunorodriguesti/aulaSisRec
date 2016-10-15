#ifndef USUARIOITEM_H
#define USUARIOITEM_H
#include<string>

#include "Conteudo.h"
using namespace std;

class UsuarioItem
{
	string usuario;
    string item;
	double avaliacao;
	string data;
	vector<Conteudo> conteudo;
	
	public:
		void setUsuario(string usuario){
             this->usuario = usuario;  
         }
         
         string getUsuario(){
                return this->usuario;      
         }
        
        void setItem(string item){
			this->item=item;
		}	
		
		string getItem(){
			return this->item;
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
};

#endif
