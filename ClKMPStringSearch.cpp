#include "stdafx.h"
#include "ClKMPStringSearch.h"

ClKMPStringSearch::ClKMPStringSearch(){
	hits = 0;                  
}

// Preprocessing method
void ClKMPStringSearch::preKmp(char *x, int m){
	int i, j;
	
	i=0;
	j = kmpNext[0] = -1;

	while (i<m){
		while (j > -1 && x[i] != x[j])
			j = kmpNext[j];
	i++;
	j++;
	
	if (x[i] == x[j])
		kmpNext[i] = kmpNext[j];
	else
		kmpNext[i] = j;
	}
}

	int* ClKMPStringSearch::find(char* text){
		int i, j;

		textSize = strlen(text);

		// Search
		i=j=0;	
		
		while (j<textSize){
			while (i>-1 && pattern[i] != text[j])
				i=kmpNext[i];
			i++;
			j++;
			
			if (i>=patternSize){
				hits++;
				//cout << "offset=" << j-m;
				i = kmpNext[i];
			}
		}

		return NULL; // TODO:
	}

	int  ClKMPStringSearch::contains(char* text){
		int i, j;

		textSize = strlen(text);

		// Search
		i=j=0;	
		
		while (j<textSize){
			while (i>-1 && pattern[i] != text[j])
				i=kmpNext[i];
			i++;
			j++;
			
			if (i>=patternSize){
				return 0;
			}
		}
		return -1;
	}
	
	void ClKMPStringSearch::preprocess(char* pat){
		pattern = pat;
		patternSize = strlen(pattern);
		
		preKmp(pat, patternSize);
	}   

