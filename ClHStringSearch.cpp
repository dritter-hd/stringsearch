#include "stdafx.h"
#include "ClHStringSearch.h"
        
ClHStringSearch::ClHStringSearch(){
	hits=0;
}

// Preprocessing method
void ClHStringSearch::preBmBc(char *x, int m){
     for (int i=0; i<ASIZE; ++i)
         bmBc[i] = m;
     for (int j=0; j<m-1; ++j)
         bmBc[x[j]] = m-j-1;
}

// Search
int* ClHStringSearch::find(char* text){
	int j;	char c;

	textSize = strlen(text);

	// Searching
	j=0;
	
	while (j<=textSize-patternSize){
		c=text[j+patternSize-1];
		if (pattern[patternSize-1] == c && memcmp(pattern, text+j, patternSize-1)==0)
            hits++;  
			//cout << "offset=" << j;
		j+= bmBc[c];
	}
	return NULL; // TODO:
}

int ClHStringSearch::contains(char* text){
	int j;	char c;

	textSize = strlen(text);

	// Searching
	j=0;
	
	while (j<=textSize-patternSize){
		c=text[j+patternSize-1];
		if (pattern[patternSize-1] == c && memcmp(pattern, text+j, patternSize-1)==0)
            hits++;  
			//cout << "offset=" << j;
		j+= bmBc[c];
	}

	return -1;
}

void ClHStringSearch::preprocess(char* pat){
	pattern = pat;
    patternSize = strlen(pattern);

	ClHStringSearch::preBmBc(pattern, patternSize);
}   