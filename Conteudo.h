#ifndef CONTEUDO_H
#define CONTEUDO_H
#include<string>

using namespace std;

class Conteudo
{
	string coteudo;
	int quantidade;
	float avaliacao;
	
	public:
		void setConteudo(string conteudo){
			this->coteudo=conteudo;
		}
		
		string getConteudo(){
			return this->coteudo;
		}
		
		
		void setQuantidade(int quantidade){
			this->quantidade=quantidade;
		}
		
		int getQuantidade(){
			return this->quantidade;
		}
		
		void setAvaliacao(float avaliacao){
			this->avaliacao=avaliacao;
		}
		
		float getAvaliacao(){
			return this->avaliacao;
		}
		
	
};

#endif
