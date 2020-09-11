#pragma once

#include "ClAbstractStringSearch.h"

// non-unicode
#define ASIZE 256
#define XSIZE 256

class ClBMStringSearch : public ClAbstractStringSearch {
	private:
        char *pattern;
        int textSize, patternSize, bmBc[ASIZE], bmGs[XSIZE];
			
		void preBmBc(char *x, int m, int bmBc[]);
		void suffixes(char *x, int m, int *suffix);
		void preBmGs(char *x, int m, int bmGs[]);

		int drMax(int x, int y){ if (x>y)return x; else if (x<y) return y; else return x; };
		
    public:   
		double hits;

		ClBMStringSearch();

		virtual int* find(char*);
		virtual int  contains(char*);
		virtual void preprocess(char*);        
};
      