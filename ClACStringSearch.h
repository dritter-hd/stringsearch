#pragma once

#include "ClAbstractStringSearch.h"

// non-unicode
#define ASIZE 256
#define XSIZE 256

class ClACStringSearch : public ClAbstractStringSearch {
	private:
        char *pattern;
        int textSize, patternSize, kmpNext[XSIZE];
			
		void preKmp(char *x, int m, int kmpNext[]);
		int drMax(int x, int y){ if (x>y)return x; else if (x<y) return y; else return x; };
		
    public:   
		double hits;

		ClACStringSearch();

		virtual int* find(char*);
		virtual int  contains(char*);
		virtual void preprocess(char*);        
};
