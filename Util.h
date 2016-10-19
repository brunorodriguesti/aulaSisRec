#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <string.h>


using namespace std;

class Util
{
	public:
		
	int hash(const char* str) {
	    int hash = 0;
    	int c = 0;

    	while (c < strlen(str)) {
        	hash += (int)str[c] << (int)str[c+1];
        	c++;
    	}
    	if(hash < 0){
    		hash=hash*(-1);
		}
    	return hash;
}



	protected:
};

#endif
