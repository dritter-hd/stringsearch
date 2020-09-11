#pragma once

#include "ClAbstractStringSearch.h"

// non-unicode
#define ASIZE 256
#define XSIZE 256

class ClQSStringSearch : public ClAbstractStringSearch {
	private:
        char *pattern;
        int textSize, patternSize, qsBc[ASIZE];
			
		void preQsBc(char *x, int m);
		
    public:   
		double hits;

		ClQSStringSearch();

		virtual int* find(char*);
		virtual int  contains(char*);
		virtual void preprocess(char*);        
};