
//O código não funciona a letra H,P e X, motivo? não faço a minima ideia




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no{
    char consoante;
    struct no* prox;
}NO;

NO* topo = NULL;
int tam = 0;

char desempilhar(){
    NO* aux = topo;
    topo = topo->prox;
    char lixeira = aux->consoante;
    free(lixeira);
    tam--;
    return lixeira;}

void empilhar(char letra){ 
    NO* novoNo = (NO*) malloc(sizeof(NO));
    novoNo->consoante = letra;
    novoNo->prox = topo;
    topo = novoNo;
    tam++;}


int main(){
    char frase[100] = "\0";

    printf("Insira sua frase:\n");
    fflush(stdin);
    scanf("%[^\n]s", frase);

    for(int i = 0; i < strlen(frase);){

        if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'u' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == ' ' && tam == 0){
            printf("%c", frase[i]);i++;}
        else{
            while(frase[i] != 'a' && frase[i] != 'e' && frase[i] != 'u' && frase[i] != 'i' && frase[i] != 'o' && frase[i] != ' ' && i < strlen(frase)){
                empilhar(frase[i]);i++;}}
            while(tam > 0){
                printf("%c", desempilhar());}}}
