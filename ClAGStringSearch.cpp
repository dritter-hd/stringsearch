#include "stdafx.h"
#include "ClAGStringSearch.h"
// #include <xutility>

ClAGStringSearch::ClAGStringSearch(){
	hits = 0;                  
}

// Preprocess-Methods
void ClAGStringSearch::preBmBc(char *x, int m, int bmBc[]){

     for (int i=0; i<ASIZE; ++i)
         bmBc[i] = m;
     for (int j=0; j<m-1; ++j)
         bmBc[x[j]] = m-j-1;
}

void ClAGStringSearch::suffixes(char *x, int m, int *suffix){
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

void ClAGStringSearch::preBmGs(char *x, int m, int bmGs[], int suffix[]){
     int i, j;
     
     //for (int d=0; d<XSIZE; d++)
     //    suffix[d] = 0;
     
     suffixes(x, m, suffix);
     
     for (i=0; i<m; ++i)
         bmGs[i] = m;
     
     j=0;
     for (int i=m-1; i>=-1; --i){
         if (i==-1 || suffix[i] == i+1){
            for (int j=0; j<m-1-i; ++j){
                if (bmGs[j]==m){
                   bmGs[j] = m-1-i;
                }
            }
         }
     }
     
     for (i=0; i<=(m-2); ++i)
         bmGs[m-1-suffix[i]] = m-1-i;
}
             
// redefine abstract methods
int* ClAGStringSearch::find(char* text){             
	int i, j, k, s, shift;

	textSize = strlen(text);

	// Search
	j=0;
	while (j<=textSize-patternSize){
		i=patternSize-1;
		while (i>=0){
			k=skip[i];
			s=suff[i];
	        
			if (k>0)
				if (k>s){
            		if (i+1 == s)
            			i=(-1);
            		else
            			i-=s;
            		break;
				} else {
            		i-=k;
            		if (k<s)
            			break;
				}
			else {
				if (pattern[i] == text[i+j])
            		--i;
				else
            		break;
			}
		}
		if (i<0){
			//cout << "offset=" << j;
			hits++;
			skip[patternSize-1] = patternSize;
			shift = bmGs[0];
		} else {
			skip[patternSize-1] = patternSize-1-i;
			shift = drMax(bmGs[i], bmBc[text[i+j]]-patternSize+1+i);	
		}
		j+=shift;
		memcpy(skip, skip+shift, (patternSize-shift)*sizeof(int));
		memset(skip+patternSize-shift, 0, shift*sizeof(int));
	}
	return NULL; //TODO:
}

int ClAGStringSearch::contains(char* text){
	int i, j, k, s, shift;

	textSize = strlen(text);

	// Search
	j=0;
	while (j<=textSize-patternSize){
		i=patternSize-1;
		while (i>=0){
			k=skip[i];
			s=suff[i];
	        
			if (k>0)
				if (k>s){
            		if (i+1 == s)
            			i=(-1);
            		else
            			i-=s;
            		break;
				} else {
            		i-=k;
            		if (k<s)
            			break;
				}
			else {
				if (pattern[i] == text[i+j])
            		--i;
				else
            		break;
			}
		}
		if (i<0){
			return 0;

		} else {
			skip[patternSize-1] = patternSize-1-i;
			shift = drMax(bmGs[i], bmBc[text[i+j]]-patternSize+1+i);	
		}
		j+=shift;
		memcpy(skip, skip+shift, (patternSize-shift)*sizeof(int));
		memset(skip+patternSize-shift, 0, shift*sizeof(int));
	}
	return -1;
}

// Preprocess
void ClAGStringSearch::preprocess(char* pat){
    pattern = pat;
    patternSize = strlen(pattern);

    preBmGs(pattern, patternSize, bmGs, suff);
    preBmBc(pattern, patternSize, bmBc);
    memset(skip, 0, patternSize*sizeof(int));
}             
