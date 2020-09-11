#include "stdafx.h"
#include "ClTBMStringSearch.h"
// #include <xutility>
        
ClTBMStringSearch::ClTBMStringSearch(){
	hits=0;
}

// Preprocess-Methods
void ClTBMStringSearch::preBmBc(char *x, int m, int bmBc[]){

        for (int i=0; i<ASIZE; ++i)
            bmBc[i] = m;
        for (int j=0; j<m-1; ++j)
            bmBc[x[j]] = m-j-1;
}

void ClTBMStringSearch::suffixes(char *x, int m, int *suffix){
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

void ClTBMStringSearch::preBmGs(char *x, int m, int bmGs[]){
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
int* ClTBMStringSearch::find(char* text){             
    int bcShift, i, j, shift, u, v, turboShift;

    textSize = strlen(text);
    
    //Searching
    j = u = 0;
    shift = patternSize;

    while (j <= textSize-patternSize){
        i = patternSize-1;
        while (i >=0 && pattern[i] == text[i+j]){
            --i;
            if (u !=0 && i == patternSize-1-shift)
                i-=u;
        }
        if (i<0){
            //cout << "offset=" << j;
            hits++;
            shift = bmGs[0];
            u = patternSize-shift; 
        } else {
            v = patternSize-1-i;
            turboShift = u-v;
            bcShift = bmBc[text[i+j]]-patternSize+1+i;
            shift = drMax(turboShift, bcShift);
            shift = drMax(shift, bmGs[i]);
            
            if (shift == bmGs[i])
                u = drMin(patternSize-shift, v);
            else {
                if (turboShift < bcShift)
                	shift = drMax(shift, u+1);
                u=0;
            }
        }
        j += shift;
    }
	return NULL; // TODO:
}

int ClTBMStringSearch::contains(char* text){
    int bcShift, i, j, shift, u, v, turboShift;

        textSize = strlen(text);
        
        //Searching
        j = u = 0;
        shift = patternSize;
    
        while (j <= textSize-patternSize){
            i = patternSize-1;
            while (i >=0 && pattern[i] == text[i+j]){
                --i;
                if (u !=0 && i == patternSize-1-shift)
                    i-=u;
            }
            if (i<0){
                return 0; // contained
                
            } else {
                v = patternSize-1-i;
                turboShift = u-v;
                bcShift = bmBc[text[i+j]]-patternSize+1+i;
                shift = drMax(turboShift, bcShift);
                shift = drMax(shift, bmGs[i]);
                
                if (shift == bmGs[i])
                    u = drMin(patternSize-shift, v);
                else {
                    if (turboShift < bcShift)
                    	shift = drMax(shift, u+1);
                    u=0;
                }
            }
            j += shift;
        }
        return -1; // not contained
}

// Preprocess
void ClTBMStringSearch::preprocess(char* pat){
    pattern = pat;
    patternSize = strlen(pattern);
    
    preBmBc(pattern, patternSize, bmBc);
    preBmGs(pattern, patternSize, bmGs);
}               
