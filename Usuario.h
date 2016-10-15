#ifndef USUARIO_H
#define USUARIO_H
#include<string>

using namespace std;
class Usuario
{
	string usuario;
	
	public:
		//Usuario(string user){
		//	usuario = user;
		//}	
		Usuario();
		void setUsuario(string user){
			this->usuario=user;
		}
		string getUsuario(){
			return usuario;
		}
		
		
	
		
};

#endif
