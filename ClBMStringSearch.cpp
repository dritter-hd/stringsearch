#include "stdafx.h"
#include "ClBMStringSearch.h"
// #include <xutility>

ClBMStringSearch::ClBMStringSearch(){
	hits=0;
}

// Preprocess-Methods
void ClBMStringSearch::preBmBc(char *x, int m, int bmBc[]){

        for (int i=0; i<ASIZE; ++i)
            bmBc[i] = m;
        for (int j=0; j<m-1; ++j)
            bmBc[x[j]] = m-j-1;
}

void ClBMStringSearch::suffixes(char *x, int m, int *suffix){
        int f, g;
        
        suffix[m-1] = m;
        g = m-1;
        
        for (int i=m-2; i >= 0; --i){
                if (i > g && (suffix[(i+m-1-f)] < (i-g)))
                    suffix[i] = suffix[(i+m-1-f)];
                else {
                    if (i<g)
                        g=i;
                    f=i;
                    
                    while (g >= 0 && (x[g] == x[(g+m-1-f)]))
                            --g;
                    suffix[i]=f-g;
                    }                  
            }     
        }                 

void ClBMStringSearch::preBmGs(char *x, int m, int bmGs[]){
        int i, j, suffix[XSIZE];
            
        suffixes(x, m, suffix);
        
        for (i=0; i<m; ++i)
            bmGs[i] = m;
        
        j=0;

        for (int i=m-1; i>=-1; --i)
            if (i==-1 || suffix[i] == i+1)
				for (int j=0; j<m-1-i; ++j)
					if (bmGs[j]==m)
						bmGs[j] = m-1-i;
        
        for (i=0; i<=(m-2); ++i)
            bmGs[m-1-suffix[i]] = m-1-i;
}

    
// redefine abstract methods
int* ClBMStringSearch::find(char* text){             
    int j=0, i=0;

    textSize = strlen(text);
    
    // Searching 
    while (j<=(textSize-patternSize)){
        for (i=patternSize-1; (i>=0) && (pattern[i] == text[i + j]); --i);
        if (i<0){
			//cout << "offset=" << j; //TODO: replace by return container
			hits++;
			j += bmGs[0];
        } else 
			j += drMax(bmGs[i], bmBc[text[i+j]] - patternSize+1+i);                          
        }
		return NULL; // TODO:
    }

int  ClBMStringSearch::contains(char* text){
    int j=0, i=0;

        textSize = strlen(text);
        
        // Searching 
        while (j<=(patternSize-textSize)){
            for (i=patternSize-1; (i>=0) && (pattern[i] == text[i + j]); --i);
            if (i<0){
            return 0; // contained

            } else 
            j += drMax(bmGs[i], bmBc[text[i+j]] - patternSize+1+i);                          
        }
        return -1; // not contained
}

// Preprocess
void ClBMStringSearch::preprocess(char* pat){
    pattern = pat;
    patternSize = strlen(pattern);
    
    preBmBc(pattern, patternSize, bmBc);
    preBmGs(pattern, patternSize, bmGs);
}                   
