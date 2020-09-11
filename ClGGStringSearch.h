#pragma once

#include "ClAbstractStringSearch.h"

// non-unicode
#define ASIZE 256
#define XSIZE 256

class ClGGStringSearch : public ClAbstractStringSearch {
	private:
        char *pattern;
        int textSize, patternSize, h[XSIZE], next[XSIZE], shift[XSIZE];
			
		int preCGG(char *x, int m, int h[], int next[], int shift[]);	
		
    public:   
		double hits;

		ClGGStringSearch();

		virtual int* find(char*);
		virtual int  contains(char*);
		virtual void preprocess(char*);        
};