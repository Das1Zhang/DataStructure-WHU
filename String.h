#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MaxSize = 100;

class SqString;

class LinkString;

void GetNextCopy(string t, int *next);
int KMP_Copy(string s, string t);
void GetNext(string t, int *next);
int KMP(string s, string t);
void GetNextval(string t, int *nextval);
int KMPval(string s, string t);
