#include "stdafx.h"
#include "ClGSStringSearch.h"
// #include <xutility>
        
	ClGSStringSearch::ClGSStringSearch(){
		hits=0;
	}

	// Searching - no preprocessing
	void ClGSStringSearch::search() {
	while (p <= textSize - patternSize) {
		while (p + s + q < textSize && pattern[s + q] == text[p + s + q])
			++q;
		if (q == patternSize - s && memcmp(pattern, text + p, s + 1) == 0){
			//cout << "offset=" << p << endl;
			hits++;
			}
		if (q == p1 + q1) {
			p += p1;
			q -= p1;
		}
		else {
			p += (q/k + 1);
			q = 0;
		}
	}
	}

	void ClGSStringSearch::newP2() {
	while (pattern[s + q2] == pattern[s + p2 + q2] && p2 + q2 < k*p2)
		++q2;
	if (p2 + q2 == k*p2)
		parse();
	else
		if (s + p2 + q2 == patternSize)
			search();
		else {
			if (q2 == p1 + q1) {
				p2 += p1;
				q2 -= p1;
			}
			else {
				p2 += (q2/k + 1);
				q2 = 0;
			}
			newP2();
		}
	}

	void ClGSStringSearch::newP1() {
	while (pattern[s + q1] == pattern[s + p1 + q1])
		++q1;
	if (p1 + q1 >= k*p1) {
		p2 = q1;
		q2 = 0;
		newP2();
	}
	else {
		if (s + p1 + q1 == patternSize)
			search();
		else {
			p1 += (q1/k + 1);
			q1 = 0;
			newP1();
		}
	}
	}

	void ClGSStringSearch::parse() {
	while (1) {
		while (pattern[s + q1] == pattern[s + p1 + q1])
			++q1;
		while (p1 + q1 >= k*p1) {
			s += p1;
			q1 -= p1;
		}
		p1 += (q1/k + 1);
		q1 = 0;
		if (p1 >= p2)
			break;
	}
	newP1();
	}

	void ClGSStringSearch::GS(char *argY) {
	text = argY;
	textSize = strlen(text);
	k = 4;
	p = q = s = q1 = p2 = q2 = 0;
	p1 = 1;
	newP1();
	}

	int* ClGSStringSearch::find(char* text){
		GS(text);

		return NULL; // TODO:
	}
	int  ClGSStringSearch::contains(char* text){
		GS(text);

		return -1; // TODO:
	}

	void ClGSStringSearch::preprocess(char* pat){
		pattern = pat;
		patternSize = strlen(pattern);
	} 