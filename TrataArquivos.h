#ifndef TRATAARQUIVOS_H
#define TRATAARQUIVOS_H

#include <stdio.h>
#include <iostream>
#include<fstream>
#include<cstring>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <stdlib.h>
#include <cstdio>

#include "UsuarioItem.h"
#include "Item.h"


#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h" 


using namespace rapidjson;
using namespace std;

class TrataArquivos
{
	public:
	vector<UsuarioItem> abreArquivoTargets(){
		vector<UsuarioItem> usuarioItemAlvoT;
		string linha;
		char aux[100];
		UsuarioItem usItem;
		int cont=0;
	
		ifstream arq("targets.csv");
	
		if(arq.is_open()){
			int k=0;
			cout << "lendo arquivo targets.csv" << endl;
			while(getline(arq, linha)){
				if(cont > 0){
					strcpy(aux, linha.c_str());
					string usuarioAlvo = strtok(aux, ":");
					string itemAux = strtok(NULL, ",");
						
					usItem.setUsuario(usuarioAlvo);
					usItem.setItem(itemAux);
					usuarioItemAlvoT.push_back(usItem);			
				}
			cont++;
			}
			arq.close();
		}
		return usuarioItemAlvoT;
	}
	
	
	
	vector<UsuarioItem> abreArquivoRating(){
		string linha;
		char aux[100];
		UsuarioItem userItem;
		int cont=0;
		vector<UsuarioItem> usuarioItemHistoricoT;	
	
		ifstream arq("ratings.csv");
	
		if(arq.is_open()){
			int k=0;
			cout << "lendo arquivo ratings.csv" << endl;
			while(getline(arq, linha)){
				if(cont > 0){
					strcpy(aux, linha.c_str());
					string usuarioAux = strtok(aux, ":");
					string itemAux = strtok(NULL, ",");
					char *avaliacaoAux = strtok(NULL, ",");
					string dataAux = strtok(NULL, ",");
				
					double avaAux = atof(avaliacaoAux);
								
					userItem.setUsuario(usuarioAux);
					userItem.setItem(itemAux);
					userItem.setAvaliacao(avaAux);
					userItem.setData(dataAux);
                
                	usuarioItemHistoricoT.push_back(userItem);
				}
				
			cont++;
		}
		arq.close();

	}
	return usuarioItemHistoricoT;
}

vector<Item> lerJson(){
	string linha;
	ifstream arq("content.csv");
	char aux[8000];
	int cont=0;
	vector<Item> itemConteudoT;
	
	if(arq.is_open()){
		cout <<"lendo arquivo content.csv " << endl;
		int k=0;
		while(getline(arq, linha)){
			if(cont > 0){
				Item itemConteudo;
				strcpy(aux, linha.c_str());
				string item = strtok(aux, ",");
				char *conteudo = strtok(NULL,"\n");
				
				Document document;
				document.Parse(conteudo);
				itemConteudo.setItem(item);
							
				if(document.HasMember("Title"))
					itemConteudo.setTitle(document["Title"].GetString());
				else
					itemConteudo.setTitle("NULL");
				if(document.HasMember("Year"))	
					itemConteudo.setYear(atoi(document["Year"].GetString()));
				if(document.HasMember("Released"))	
					itemConteudo.setRelease(document["Released"].GetString());
				if(document.HasMember("Runtime"))	
					itemConteudo.setRuntime(document["Runtime"].GetString());
				if(document.HasMember("Genre")){	
					stringstream gen(document["Genre"].GetString());
					string genreAux;
					while(getline(gen, genreAux, ',')){
						genreAux.erase(remove(genreAux.begin(), genreAux.end(), ' '), genreAux.end());
						itemConteudo.setGenreVector(genreAux);
						}
				}	
					
				if(document.HasMember("Director"))	
					itemConteudo.setDirector(document["Director"].GetString());
				if(document.HasMember("Writer"))	
					itemConteudo.setWriter(document["Writer"].GetString());
				if(document.HasMember("Actors")){
					stringstream act (document["Actors"].GetString());
					string actorAux;
					while(getline(act, actorAux, ',')){
						actorAux.erase(remove(actorAux.begin(), actorAux.end(), ' '), actorAux.end());
						itemConteudo.setActors(actorAux);
						}
				}	
					
				if(document.HasMember("Plot"))		
					itemConteudo.setPlot(document["Plot"].GetString());
				if(document.HasMember("Language"))			
					itemConteudo.setLanguage(document["Language"].GetString());
				if(document.HasMember("Country"))			
					itemConteudo.setCountry(document["Country"].GetString());
				if(document.HasMember("Awards"))			
					itemConteudo.setAwards(document["Awards"].GetString());
				if(document.HasMember("Poster"))			
					itemConteudo.setPoster(document["Poster"].GetString());
				if(document.HasMember("Metascore"))				
					itemConteudo.setMetacores(document["Metascore"].GetString());
				if(document.HasMember("imdbRating"))				
					itemConteudo.setImdbRating(atof(document["imdbRating"].GetString()));
				if(document.HasMember("imdbVotes"))					
					itemConteudo.setImdbVotes(atoi(document["imdbVotes"].GetString()));
				if(document.HasMember("imdbID"))					
					itemConteudo.setImdbID(document["imdbID"].GetString());
				if(document.HasMember("Type"))					
					itemConteudo.setType(document["Type"].GetString());
				if(document.HasMember("Response"))					
					itemConteudo.setResponse(document["Response"].GetString());
				
				itemConteudoT.push_back(itemConteudo);
				
				
			}
		cont++;
		}
		arq.close();
	}
	return itemConteudoT;	
}
	
};

#endif
