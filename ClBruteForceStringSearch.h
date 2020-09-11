#pragma once

#include "ClAbstractStringSearch.h"

// non-unicode
#define ASIZE 256
#define XSIZE 256
#define EOS '\0'

class ClBruteForceStringSearch : public ClAbstractStringSearch {
      private:
        char *pattern, *yb;
		int textSize, patternSize;

	 public:   
		double hits;

		ClBruteForceStringSearch();

		virtual int* find(char*);
		virtual int  contains(char*);
		virtual void preprocess(char*);   
};
