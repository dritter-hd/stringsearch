#pragma once

#include "ClAbstractStringSearch.h"

class ClGSStringSearch : public ClAbstractStringSearch {
	private:
        char *pattern, *text;
        int textSize, patternSize, k, p, p1, p2, q, q1, q2, s;
			
		void GS(char *argY);
		void search();
		void parse();
		void newP1();
		void newP2();

    public:   
		double hits;

		ClGSStringSearch();

		virtual int* find(char*);
		virtual int  contains(char*);
		virtual void preprocess(char*);        
};