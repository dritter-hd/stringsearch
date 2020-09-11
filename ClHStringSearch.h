#pragma once

#include "ClAbstractStringSearch.h"

// non-unicode
#define ASIZE 256
#define XSIZE 256

class ClHStringSearch : public ClAbstractStringSearch {
	private:
        char *pattern;
        int textSize, patternSize, bmBc[ASIZE];
			
		void preBmBc(char *x, int m);
		
    public:   
		double hits;

		ClHStringSearch();

		virtual int* find(char*);
		virtual int  contains(char*);
		virtual void preprocess(char*);        
};