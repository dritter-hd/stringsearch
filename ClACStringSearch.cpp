#include "stdafx.h"
#include "ClACStringSearch.h"
// #include <xutility>

ClACStringSearch::ClACStringSearch(){
	hits = 0;                  
}
                            
// Preprocess-Methods
void ClACStringSearch::preKmp(char *x, int m, int kmpNext[]){
    int i, j;
    
    i=0;
    j = kmpNext[0] = -1;

    while (i<m){
        while (j > -1 && x[i] != x[j])
            j = kmpNext[j];
            
    i++; j++;
    
    if (x[i] == x[j])
        kmpNext[i] = kmpNext[j];
    else
        kmpNext[i] = j;
    }
}  
                   
// redefine abstract methods
int* ClACStringSearch::find(char* text){             
    int i, j, k, ell;

    textSize = strlen(text);
    
    //Searching 
    for (ell=1; pattern[ell-1] == pattern[ell]; ell++);
    
    if (ell==patternSize)
        ell = 0;
        
    i=ell;
    j=k=0;
        
    while (j<=textSize-patternSize){
        while (i<patternSize && pattern[i] == text[i+j])
            ++i;
        
        if (i>=patternSize){
            while (k<ell && pattern[k] == text[j+k])
                ++k;
            if (k>=ell){
                hits++;        
                //cout << "offset=" << j;
            }
        }
        j+= (i-kmpNext[i]);

        if (i==ell)
            k=drMax(0, k-1);
        else
            if (kmpNext[i]<=ell){
                k=drMax(0, kmpNext[i]);
                i=ell;
            } else {
                k=ell;
                i=kmpNext[i];
            }
    }
	return 0; // TODO:
}

int ClACStringSearch::contains(char* text){
    int i, j, k, ell;

        textSize = strlen(text);
        
        //Searching 
        for (ell=1; pattern[ell-1] == pattern[ell]; ell++);
        
        if (ell==patternSize)
            ell = 0;
            
        i=ell;
        j=k=0;
            
        while (j<=textSize-patternSize){
            while (i<patternSize && pattern[i] == text[i+j])
                ++i;
            
            if (i>=patternSize){
                while (k<ell && pattern[k] == text[j+k])
                    ++k;
                if (k>=ell)
                    return 0; // contained
            }
            j+= (i-kmpNext[i]);
    
            if (i==ell)
                k=drMax(0, k-1);
            else
                if (kmpNext[i]<=ell){
                    k=drMax(0, kmpNext[i]);
                    i=ell;
                } else {
                    k=ell;
                    i=kmpNext[i];
                }
        }
        return -1; // not contained
}

// Preprocess
void ClACStringSearch::preprocess(char* pat){
    pattern = pat;
    patternSize = strlen(pattern);
    
    preKmp(pattern, patternSize, kmpNext);
}   
