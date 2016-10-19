#ifndef CONTEUDO_H
#define CONTEUDO_H
#include<string>

using namespace std;

class Conteudo
{
	string conteudo;
	int hashConteudo;
	int quantidade;
	float avaliacao;
	
	public:
		
		void setConteudo(string conteudo){
			this->conteudo=conteudo;
		}
		
		string getConteudo(){
			return this->conteudo;
		}
		
		
		void setHashConteudo(int hashConteudo){
			this->hashConteudo=hashConteudo;
		}
		
		int getHashConteudo(){
			return this->hashConteudo;
		}
		
		
		void setQuantidade(int quantidade){
			this->quantidade=quantidade+quantidade;
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
