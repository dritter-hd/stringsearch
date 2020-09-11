#pragma once

#include "ClAbstractStringSearch.h"

// non-unicode
#define ASIZE 256
#define XSIZE 256

class ClCStringSearch : public ClAbstractStringSearch {
	private:
        char *pattern;
        int textSize, patternSize, h[XSIZE], next[XSIZE], shift[XSIZE];
			
		int preC(char *x, int m);
		
    public:   
		double hits;

		ClCStringSearch();

		virtual int* find(char*);
		virtual int  contains(char*);
		virtual void preprocess(char*);        
};
