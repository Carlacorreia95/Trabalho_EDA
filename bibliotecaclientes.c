/**
 * @file bibliotecaclientes.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-23
 * 
 * 
 */
// inserir confirmar existencia de cliente antes de inserir novo cliente
//acrescentar ao ler dados do ficheiro para guardar para a lista
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bibliotecaclientes.h"

// ***************************Dividir a funçao ******************* 
// NodeDefinicaoDeCliente *AdicionarNode(int numerocliente, char nomecliente[], float saldo, long nifcliente, char moradacliente[]) {
//     NodeDefinicaoDeCliente *nodecliente = (NodeDefinicaoDeCliente *)malloc(sizeof(NodeDefinicaoDeCliente)); //Aloca memÃ³ria
//     nodecliente->nodecliente.numerocliente = numerocliente; //Adiciona os valores do utilizador
//     strcpy(nodecliente->nodecliente.nomecliente, nomecliente);
//     nodecliente->nodecliente.saldo = saldo;
//     nodecliente->nodecliente.nifcliente = nifcliente;
//     strcpy(nodecliente->nodecliente.moradacliente, moradacliente);
//     nodecliente->proximo = NULL;//Ã‰ null porque Ã© o ultimo

//     // if(headcliente == NULL) {
//     //     headcliente = nodecliente;
//     // }
//     // else {
//     //     NodeDefinicaoDeCliente *atual = headcliente;
//     //     while(atual->proximo != NULL) {//Para procurar pelo ultimo node
//     //         atual = atual->proximo;
//     //     }
//     //     atual->proximo = nodecliente;
//     // }
// return (nodecliente);
// }

//lê os dados do dos ficheiros para a estrutura.
//se não houver bin ele lê o txt
///aterar o adicionar node, deve ser criada uma função gestora que chame o ler e o adicionar. ver seguinte, confirmar a existencia dos txt.
/**
 * 
*/
int LerDados(NodeDefinicaoDeCliente clientes[]){
    FILE* fp;
    int i=0;
    fp = fopen("dados_clientes.bin","rt");  // read text
    if (fp != NULL){
        do{
            fscanf(fp,"%d;%[^;];%d;%f%f;%[^;]\n",&clientes[i].nodecliente.numerocliente, clientes[i].nodecliente.nomecliente,clientes[i].nodecliente.nifcliente,&clientes[i].nodecliente.saldo,&clientes[i].nodecliente.moradacliente);
            //AdicionarNode(clientes[i].nodecliente.numerocliente, clientes[i].nodecliente.nomecliente,clientes[i].nodecliente.saldo, clientes[i].nodecliente.nifcliente,clientes[i].nodecliente.moradacliente);
            i++;} while(!feof(fp));  // end of file  feof ==> >0 
        fclose(fp);
        return(i);
        }
        else {fp = fopen ("dados_clientes.txt","rt");
        fscanf(fp,"%d;%[^;];%d;%f%f;%[^;]\n",&clientes[i].nodecliente.numerocliente, clientes[i].nodecliente.nomecliente,clientes[i].nodecliente.nifcliente,&clientes[i].nodecliente.saldo,&clientes[i].nodecliente.moradacliente);
            //AdicionarNode(clientes[i].nodecliente.numerocliente, clientes[i].nodecliente.nomecliente,clientes[i].nodecliente.saldo, clientes[i].nodecliente.nifcliente,clientes[i].nodecliente.moradacliente);
            i++;} while(!feof(fp));  // end of file  feof ==> >0 
        fclose(fp);
        return(i);
        };

//adicionar dados lidos do ficheiro à lista
/*int AdicionarDadosFicheiros(NodeDefinicaoDeCliente clientes[]){
    LerDados(clientes[i].nodecliente.numerocliente, clientes[i].nodecliente.nomecliente,clientes[i].nodecliente.saldo, clientes[i].nodecliente.nifcliente,clientes[i].nodecliente.moradacliente)
    AdicionarNode(clientes[i].nodecliente.numerocliente, clientes[i].nodecliente.nomecliente,clientes[i].nodecliente.saldo, clientes[i].nodecliente.nifcliente,clientes[i].nodecliente.moradacliente);

}*/
//remove Cliente
int ApagarNode( int numerocliente) {
    NodeDefinicaoDeCliente *atual = headcliente;
    NodeDefinicaoDeCliente *anterior = NULL;

    while(atual != NULL) {//Corre a lista toda
        if(atual->nodecliente.numerocliente == numerocliente) {//Procura o Id escolhido
            if(anterior == NULL) {//Caso não exista anterior
                headcliente = atual->proximo;//O primeiro passa a ser o seguinte
            }
            else {
                anterior->proximo = atual->proximo;//Caso contrário substitui o endereço
            }
            free(atual);//Liberta a memória
            return (0);
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

//altera dados ( Criar metodo para alterar cada caracteristica do cliente e depois chamar uma funçao para alterar)
int ModificarNode(int numerocliente, char nomecliente[], float saldo, long nifcliente, char moradacliente[]) {
    NodeDefinicaoDeCliente *atual = headcliente;
    while(atual != NULL) {//Corre a lista toda
        if(atual-> nodecliente.numerocliente == numerocliente) {//Procura o Id escolhido
            strcpy(atual->nodecliente.nomecliente, nomecliente);//Substitui
            atual-> nodecliente.nifcliente = nifcliente;
            atual->nodecliente.saldo = saldo;
            strcpy(atual->nodecliente.moradacliente, moradacliente);
            return (0);
        }
        atual = atual->proximo;
    }
}

//Gravar para bin
int GuardarParaFicheiro(NodeDefinicaoDeCliente, char) {
    FILE *fp = fopen("dados_clientes.bin", "wb");
    NodeDefinicaoDeCliente *atual = headcliente;

    while(atual != NULL) {
        fprintf(fp, "%d %s %f %d %s\n", atual->nodecliente.numerocliente, atual->nodecliente.nomecliente, atual->nodecliente.saldo, atual->nodecliente.nifcliente, atual->nodecliente.moradacliente);
        atual = atual->proximo;
    }

    fclose(fp);
return (0);}

//Apagar memoria
int ApagarMemoria(NodeDefinicaoDeCliente *headcliente){
    NodeDefinicaoDeCliente *atual = headcliente;
    NodeDefinicaoDeCliente *temp;
    while (headcliente!=NULL)
    {
    temp=headcliente;
    headcliente = headcliente -> proximo;
    free(temp);
    }
    return (-1);
}