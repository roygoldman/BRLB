#ifndef HASHTABLE
#define HASHTABLE
#include <stdio.h>
#include <stdlib.h>

typedef struct _htnode HTNode;
typedef struct _hashtable Hashtable;
typedef struct _llnode LLNode;

typedef int (*CmpFct)( void *, void * );
typedef void (*FreeFct)( void * );
typedef int (*HashFct)( void * );

struct _htnode{
	void* key;
	void* value;
	HTNode* next;
};

struct _hashtable{
	HTNode** nodes;
	int size;
	HashFct hashfct;
	FreeFct freefct;
	CmpFct cmpfct;
};

struct _llnode{
	void* value;
	LLNode* next;
};

HTNode* HTNodeCreate(void* key, void* value, HTNode* next);
Hashtable* HTCreate(int size, HashFct hashfct, FreeFct freefct, CmpFct cmpfct);

void HTNodeDestroy(HTNode* node, FreeFct freefct);
void HTNodeDestroyR(HTNode* node, FreeFct freefct);
void HTDestroy(Hashtable* ht);

void HTAdd(Hashtable* ht, void* value, void* key);
void* HTGet(Hashtable* ht, void* key);

LLNode* HTDumpList(Hashtable* ht);

#endif