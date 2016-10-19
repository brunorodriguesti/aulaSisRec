#ifndef ITEM_H
#define ITEM_H
#include<string>
#include <vector>
using namespace std;

class Item
{
	string item;
	int hashItem;
	string title;
	int year;
	string rated;
	string release;
	string runtime;
	vector<string> genreVector;
	vector<int> hashGenero;
	string genre;
	string director;
	string writer;
	vector<string> actors;
	string plot;
	string language;
	string country;
	string awards;
	string poster;
	string metacores;
	float imdbRating;
	int imdbVotes;
	string imdbID;
	string type;
	string response;
	

	
	public:
		void setItem(string item){
			this->item=item;
		}	
		
		string getItem(){
			return this->item;
		}
		
		void setHashItem(int hashItem){
			this->hashItem = hashItem;
		}	
		
		int getHashItem(){
			return this->hashItem;
		}
		
		void setTitle(string title){
			this->title=title;
		}	
		
		string getTitle(){
			return this->title;
		}
		
		void setYear(int year){
			this->year=year;
		}
		int getYear(){
			return this->year;
		}
		
		void setRated(string rated){
			this->rated=rated;
		}	
		
		string getRated(){
			return this->rated;
		}
		
		void setRelease(string release){
			this->release=release;
		}
		
		string getRelease(){
			return this->release;
		}
		
		
				void setRuntime(string runtime){
			this->runtime=runtime;
		}	
		
		string getRuntime(){
			return this->runtime;
		}
		
		void setGenre(string genre){
			this->genre=genre;
		}	
		
		string getGenre(){
			return this->genre;
		}
		
		
		
		void setHashGenero(int hashGenero){
			this->hashGenero.push_back(hashGenero);
		}	
		
		vector<int> getHashGenero(){
			return this->hashGenero;
		}
		
	
	  void setGenreVector(string genre){
			this->genreVector.push_back(genre);
		}	
		
		vector<string> getGenreVector(){
			return this->genreVector;
		}
	
		void setWriter(string writer){
			this->writer=writer;
		}	
		
		string getWriter(){
			return this->writer;
		}
	
	
	void setActors(string actors){
			this->actors.push_back(actors);
		}	
		
	vector<string> getActors(){
			return this->actors;
		}
	
	void setPlot(string plot){
			this->plot=plot;
		}	
		
		string getPlot(){
			return this->plot;
		}
		
	void setLanguage(string language){
			this->language=language;
		}	
		
		string getLanguage(){
			return this->language;
		}
	
		void setCountry(string country){
			this->country=country;
		}	
		
		string getCountry(){
			return this->country;
		}
		
		void setAwards(string awards){
			this->awards=awards;
		}	
		
		string getAwards(){
			return this->awards;
		}
		
		void setPoster(string poster){
			this->poster=poster;
		}	
		
		string getPoster(){
			return this->poster;
		}
		void setMetacores(string metacores){
			this->metacores=metacores;
		}	
		
		string getMetacores(){
			return this->metacores;
		}
	
		void setImdbRating(float imdbRating){
			this->imdbRating=imdbRating;
		}
		float getImdbRating(){
			return this->imdbRating;
		}
		
		
		void setImdbVotes(int imdbVotes){
			this->imdbVotes=imdbVotes;
		}
		
		int getImdbVotes(){
			return this->imdbVotes;
		}
	
		void setImdbID(string imdbID){
			this->imdbID=imdbID;
		}	
		
		string getImdbID(){
			return this->imdbID;
		}
	void setType(string type){
			this->type=type;
		}	
		
		string getType(){
			return this->type;
		}
	
	
		void setResponse(string response){
			this->response=response;
		}	
		
		string getResponse(){
			return this->response;
		}
		
	 void setDirector(string director){
	 	this->director = director;
	 }
	 string getDirector(){
	 	return this->director;
	 }
	
};

#endif
