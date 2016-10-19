#ifndef INTERESSEUSUARIO_H
#define INTERESSEUSUARIO_H

class InteresseUsuario
{	
	int hashUsuario;
	int hashGenero;
	int qtdGenero;
	int tamanhoGeneroItem;
	int qtdDocumento;	
	
	public:
		void inicializaQtdGenero(){
			this->qtdGenero=0;
		}
		
		void setHashUsuario(int hashUsuario){
			this->hashUsuario= hashUsuario;
		}
		
		int  getHashUsuario(){
			return this->hashUsuario;
		}
		
		void setHashGenero(int hashGenero){
			this->hashGenero = hashGenero;
		}
		
		int  getHashGenero(){
			return this->hashGenero;
		}
		
		void setQtdGenero(int qtdGenero){
			this->qtdGenero=qtdGenero+this->qtdGenero;
		}
		
		
		int getQtdGenero(){
			return this->qtdGenero;
		}
		
				
		int getTamanhoGeneroItem(){
			return this->tamanhoGeneroItem;
		}
		
		void setHashQtdDocumento(int qtdDocumento){
			this->qtdDocumento = qtdDocumento;
		}
		
		int  getQtdDocumento(){
			return this->qtdDocumento;
		}
		
	protected:
};

#endif
