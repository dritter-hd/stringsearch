#include "stdafx.h"
#include "ClBruteForceStringSearch.h"
//#include <xutility>

ClBruteForceStringSearch::ClBruteForceStringSearch(){
	hits = 0;                  
}

int* ClBruteForceStringSearch::find(char* text){
  /* Searching */ 
  for (yb = text; *text != EOS; ++text) 
	if (memcmp(pattern, text, patternSize) == 0){
       //cout << "offset=" << text-yb << endl;
       hits++;              
    } 
	return NULL; //TODO:
}

int ClBruteForceStringSearch::contains(char* text){
  /* Searching */ 
  for (yb = text; *text != EOS; ++text) 
	if (memcmp(pattern, text, patternSize) == 0){
       //cout << "offset=" << text-yb << endl;
       return 0;             
    } 
	return -1;
}

void ClBruteForceStringSearch::preprocess(char* pat){
    pattern = pat;
    patternSize = strlen(pattern);
}  
 