/*
* Este � um c�digo exemplo de trabalho com BST, demonstrando apenas inser��o e busca.
* Voc� deve modificar este c�digo de tal forma a incluir pelo menos dois outros
* campos (nome e cpf) e que o usu�rio possa digitar os dados (nome e cpf)
* e fazer busca por nome recebendo o cpf e por cpf recebendo o nome.
*/

#include<stdlib.h>
#include<stdio.h>

//definindo o elemento da �rvore
struct node {
	int data;
	struct node * right, *left;
};
typedef struct node node;

//prototipos
void inserir(node **, int);
void preorder(node *);
void inorder(node *);
void postorder(node *);
void Apagar(node *);
node* buscar(node **, int);

int main() {
	node *root;
	node *tmp;
	//int i;

	root = NULL;
	/* Inserindo n�s na �rvore */
	inserir(&root, 9);
	inserir(&root, 4);
	inserir(&root, 15);
	inserir(&root, 6);
	inserir(&root, 12);
	inserir(&root, 17);
	inserir(&root, 2);

	/* Imprimindo os n�s da �rvor */
	printf("Pre Order\n");
	preorder(root);

	printf("In Order\n");
	inorder(root);

	printf("Post Order\n");
	postorder(root);

	/* Search node into tree */
	tmp = buscar(&root, 4);
	if (tmp) {
		printf("Buscar valor na �rvore=%d\n", tmp->data);
	}
	else {
		printf("Nenhum dado encontrado.\n");
	}

	/* Apagando a �rvore*/
	Apagar(root);
	system("Pause");
	return 0;
}

/*
* Esta fun��o determina a posi��o do n� onde o valor ser� inserido.
* 1. verifica se a �rvore est� vazia. Se sim, insere o valor no n� raiz (root);
* 2. verifica se o valor a ser inserido � menor que o valor armazenado na raiz
* 2.a se sim, chama a fun��o inserir de forma recursiva enquanto existe um valor n�o null
* 2.b quando a fun��o encontra o valor mais a esquerda (um null) o n� � inserido nesta posi��o
*	3. verifica se o o valor do n� � maior que o valor armazenado na raiz e repete o mesmo procedimento
* desta vez indo para a direita.
*/
void inserir(node ** tree, int val) {
	node *temp = NULL;
	if (!(*tree)) {
		temp = (node *)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return;
	}
	if (val < (*tree)->data) {
		inserir(&(*tree)->left, val);
	}
	else if (val >(*tree)->data) {
		inserir(&(*tree)->right, val);
	}
}

/*
* Esta fun��o percore a �rvore em busca de um valor se o valor
* o n� encontrado ser� devolvido, caso contr�rio devolve NULL.
* 1. verifica se a �rvore est� vazia, se sim, devolve Null
* 2. verifica se o valor � igual ao valor armazenado na raiz, se sim devolve este n�.
* 3. verifica se o valor � menor que o valor da ra�z se sim, chama buscar recursivamente a partir do n� a esquerda.
* 4. verifica se o valor � maior e repete o processo pela direita.
*/

node* buscar(node ** tree, int val) {
	if (!(*tree)) {
		return NULL;
	}

	if (val < (*tree)->data) {
		buscar(&((*tree)->left), val);
	}
	else if (val >(*tree)->data) {
		buscar(&((*tree)->right), val);
	}
	else if (val == (*tree)->data) {
		return *tree;
	}
}

/*
* apaga a �rvore
*/
void Apagar(node * tree) {
	if (tree) {
		Apagar(tree->left);
		Apagar(tree->right);
		free(tree);
	}
}

/*
*	fun��es s� para verificar o que est� acontecendo
Preorder root, left e right.
inorder left, root e right.
Postorder left, right e root.
*/

void preorder(node * tree) {
	if (tree) {
		printf("%d\n", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}

}

void inorder(node * tree) {
	if (tree) {
		inorder(tree->left);
		printf("%d\n", tree->data);
		inorder(tree->right);
	}
}

void postorder(node * tree) {
	if (tree) {
		postorder(tree->left);
		postorder(tree->right);
		printf("%d\n", tree->data);
	}
}