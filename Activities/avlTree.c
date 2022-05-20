/*
Actividad individual: Árbol AVL

Un árbol AVL que es un árbol binario de búsqueda equilibrado en el sentido de que para todo subárbol se cumple que la diferencia entre las alturas de sus dos hijos es como mucho 1. Además, por ser de búsqueda, también se cumple que la clave almacenada en la raíz de cualquier subárbol es estrictamente mayor que todas las claves en su hijo izquierdo y estrictamente menor que todas las claves en su hijo derecho.
*/
//Leonardo Daniel Riojas Sanchez A00825968
//Código creado el 29/10/2021
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXTREENODES 4000
int treeNodesCount = 0;

//Creamos la estructura para los nodos del arbol
struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

//Función para leer y crear el Binary Tree
struct TreeNode* create() {
  struct TreeNode* curr;
  int key;
  scanf("%d", &key);
  //Caso base
  if(key == -1) return NULL;
  //Revisar si ya se alcanzó el número máximo de nodos
  if(++treeNodesCount == MAXTREENODES) return NULL;

  curr = (struct TreeNode*) malloc(sizeof(struct TreeNode));
  curr->val = key;
  curr->left = create();
  curr->right = create();

  return curr;
}

/*Funciones para determinar si es un AVL*/
int max(int a, int b){
  return (a >= b) ? a : b;
}

int height(struct TreeNode* curr){
  if(curr == NULL) return 0;
  return 1 + max(height(curr->left), height(curr->right));
}

int isAVL(struct TreeNode* curr){
  if(curr == NULL) return 1;
  if(abs(height(curr->left) - height(curr->right)) <= 1 && isAVL(curr->left) && isAVL(curr->right))
    return 1;
  return 0;
}

//Revisar si es un Binary Search Tree
struct TreeNode* prev = NULL;
int isBST(struct TreeNode* curr){
  if(curr == NULL) return 1;

  if(!isBST(curr->left)) return 0;

  if(prev != NULL && curr->val <= prev->val) return 0;

  prev = curr;

  if(!isBST(curr->right)) return 0;

  return 1;
}

int main(){
  int trees;
  scanf("%d", &trees);

  for(int i = 0; i < trees; i++) {
    struct TreeNode* root;
    root = create();
    
    //Dormimos un segundo el proceso para el output
    sleep(1);
    if(isAVL(root) && isBST(root))
      printf("TREE AVL\n");
    else
      printf("NO AVL\n");
  }
  return 0;
}