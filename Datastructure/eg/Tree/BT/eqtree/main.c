#include <stdio.h>
#include "stack.h"
#include "expresstree.h"
void myaction(btdata data);

int main(){
	char eq[100];
	scanf("%s",eq);
	IntoPost(eq);
	printf("%s\n",eq);
	btNode* exptree=MakeExpressTree(eq);
	printf("Prefix Expression : ");
	ShowPrefixExp(exptree);
	printf("\n");
	printf("Infix Expression : ");
	ShowInfixExp(exptree);
	printf("\n");
	printf("Postfix Expression : ");
	ShowPostfixExp(exptree);
	printf("\n");
	printf("\n ret : %d", EvalExpTree(exptree));
	
	
	return 0;
}
