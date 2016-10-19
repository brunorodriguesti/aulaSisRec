#ifndef USUARIO_H
#define USUARIO_H
#include<string>

using namespace std;
class Usuario
{
	int hashUsuario;
	int qtdItensAvaliados;
	
	public:
		
		Usuario();
		void setHashUsuario(int hashUsuario){
			this->hashUsuario=hashUsuario;
		}
		int getHashUsuario(){
			return this->hashUsuario;
		}
		
		void setqtdItensAvaliados(int qtdItensAvaliados){
			this->qtdItensAvaliados=qtdItensAvaliados;
		}
		
		int getQtdItensAvaliados(){
			return this->getQtdItensAvaliados();
		}
		
};

#endif
