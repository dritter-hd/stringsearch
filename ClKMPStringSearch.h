#pragma once

#include "ClAbstractStringSearch.h"

// non-unicode
#define ASIZE 256
#define XSIZE 256

class ClKMPStringSearch : public ClAbstractStringSearch {
	private:
        char *pattern;
        int textSize, patternSize, kmpNext[XSIZE];
			
		void preKmp(char *x, int m);
		
    public:   
		double hits;

		ClKMPStringSearch();

		virtual int* find(char*);
		virtual int  contains(char*);
		virtual void preprocess(char*);        
};