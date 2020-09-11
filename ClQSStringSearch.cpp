#include "stdafx.h"
#include "ClQSStringSearch.h"
        
ClQSStringSearch::ClQSStringSearch(){
	hits=0;
}

// Preprocessing method
void ClQSStringSearch::preQsBc(char *x, int m){
	int i;
	for (i=0; i<ASIZE; ++i)
		qsBc[i] = m; //+1 ???
	for (i=0; i<m; ++i)
		qsBc[x[i]] = m; //-1 ???
}

int* ClQSStringSearch::find(char* text){
	int j;
	textSize = strlen(text);	

    // Search
	j=0;
	while (j<=textSize-patternSize){
		if (memcmp(pattern, text+j, patternSize)==0)
		    hits++;          
			//cout << "offset=" << j;
		j+= qsBc[text[j+patternSize]]; //shift
	}
	return NULL; // TODO:
}

int  ClQSStringSearch::contains(char* text){
	int j;
	textSize = strlen(text);	

    // Search
	j=0;
	while (j<=textSize-patternSize){
		if (memcmp(pattern, text+j, patternSize)==0)
		    //cout << "offset=" << j;
			return 0;
	}

	return -1;
}

void ClQSStringSearch::preprocess(char* pat){
	pattern = pat;
    patternSize = strlen(pattern);

	ClQSStringSearch::preQsBc(pattern, patternSize);
}