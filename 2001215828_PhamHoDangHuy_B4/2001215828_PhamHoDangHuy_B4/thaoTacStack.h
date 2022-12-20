#ifndef ThaoTacStack
using namespace std;
#define ThaoTacStack
void initStack(Stack &s);
bool isEmptyStack(Stack s);
void pushStack(Stack &s, int v);
int popStack(Stack &s);
typedef struct pStack
{
	int top;
	pStack *next;
}*Stack;

void initStack(Stack &s)
{
	s = NULL;
}
bool isEmptyStack(Stack s)
{
	if (s == NULL)
		return 1;
	return 0;

}
void pushStack(Stack &s, int v){
	pStack *p = new pStack;
	if (p)
	{
		std::cout << "Memory empty";
		return;
	}
	p->top = v;
	p->next = s;
	s = p;
}
int popStack(Stack &s){
	pStack *p;
	if (isEmptyStack(s)) 
		return 0;
	p = s;
	s = p->next;
	int v = p->top;
	delete(p); return v;
}
#endif