#ifndef ITEM_H
#define ITEM_H
#include<string>

using namespace std;

class UsuarioItem
{
	string usuario;
    string item;
	int avaliacao;
	string data;
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
		
		
		 void setAvaliacao(int avaliacao){
			this->avaliacao=avaliacao;
		}	
		
		string getAvaliacao(){
			return this->avaliacao;
		}
		
		void setData(string data){
			this->data=data;
		}	
		
		string getData(){
			return this->data;
		}
	
};

#endif
