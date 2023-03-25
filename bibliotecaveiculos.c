#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bibliotecaveiculos.h"



//2. Armazenamento/leitura dos dados em ficheiro de texto (valores de simulação) e binários (preservar dados);
///lê os dados do dos ficheiros para a estrutura. Se não houver bin ele lê o txt
int LerVeiculos(NodeVeiculo veiculo[]){//char nomedoficheiroveiculo
    FILE* fp;
    int i=0;
    fp = fopen("dados_veiculos.bin","rt");  // read text
    if (fp != NULL){
        do{
            fscanf(fp,"%d;%d;%d;%[^;]\n",&veiculo[i].nodeveiculo.numeroveiculo, veiculo[i].nodeveiculo.autonomia, veiculo[i].nodeveiculo.capacidade,veiculo[i].nodeveiculo.localizacaogeocode);
            i++;} while(!feof(fp));  // end of file  feof ==> >0 
        fclose(fp);
        return(i);
        }
        else {fp = fopen ("dados_clientes.txt","rt");
        fscanf(fp,"%d;%d;%d;%[^;]\n",&veiculo[i].nodeveiculo.numeroveiculo, veiculo[i].nodeveiculo.autonomia, veiculo[i].nodeveiculo.capacidade,veiculo[i].nodeveiculo.localizacaogeocode);
            i++;} while(!feof(fp));  // end of file  feof ==> >0 
        fclose(fp);
        return(i);
        };

//3. Inserção de novos dados meio de mobilidade elétrica);
/// Insere um veículo um a um na lista
int AdicionarVeiculos (int numeroveiculo, int autonomia,int capacidade, char localizacaogeocode[]){
    NodeVeiculo *nodeveiculo = (NodeVeiculo *)malloc(sizeof(NodeVeiculo)); //Aloca memÃ³ria
    nodeveiculo->nodeveiculo.numeroveiculo = numeroveiculo; //Adiciona os valores do utilizador
    nodeveiculo->nodeveiculo.autonomia=autonomia;
    nodeveiculo->nodeveiculo.capacidade = capacidade;
    strcpy(nodeveiculo->nodeveiculo.localizacaogeocode,localizacaogeocode); 
    nodeveiculo->proximo = NULL;//Ã‰ null porque Ã© o ultimo

    if(headveiculo == NULL) {
        headveiculo = nodeveiculo;
    }
    else {
        NodeVeiculo *atual = headveiculo;
        while(atual->proximo != NULL) {//Para procurar pelo ultimo node
            atual = atual->proximo;
        }
        atual->proximo = nodeveiculo;
    }
}
//4. Remoção de determinados dados (cliente/gestor/meio de mobilidade elétrica);

int ApagarNodeVeiculos( int numeroveiculo) {
    NodeVeiculo *atual = headveiculo;
    NodeVeiculo *anterior = NULL;

    while(atual != NULL) {//Corre a lista toda
        if(atual->nodeveiculo.numeroveiculo == numeroveiculo) {//Procura o Id escolhido
            if(anterior == NULL) {//Caso não exista anterior
                headveiculo = atual->proximo;//O primeiro passa a ser o seguinte
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
//5. Alteração de determinados dados (cliente/gestor/meio de mobilidade elétrica);
///altera dados
int ModificarNodeVeiculos(int numeroveiculo, int autonomia, int capacidade, char localizacaogeocode[]) {
    NodeVeiculo *atual = headveiculo;
    while(atual != NULL) {//Corre a lista toda
        if(atual-> nodeveiculo.numeroveiculo == numeroveiculo) {//Procura o numero escolhido
            atual-> nodeveiculo.autonomia = autonomia;//Substitui
            atual->nodeveiculo.capacidade = capacidade;
            strcpy(atual->nodeveiculo.localizacaogeocode, localizacaogeocode);
            return (0);
        }
        atual = atual->proximo;
    }
}

///6. Registo do aluguer de um determinado meio de mobilidade elétrica;


//7/. Listagem dos meios de mobilidade elétrica por ordem decrescente de autonomia
/// a melhorar
int OrdenarDecrescenteVeiculos( int autonomia) {
    NodeVeiculo *atual = headveiculo;
    NodeVeiculo *anterior = NULL;
    NodeVeiculo *proximo = headveiculo->proximo;

    while(atual != NULL) {//Corre a lista toda
        if(atual->nodeveiculo.autonomia > proximo->nodeveiculo.autonomia) {//Procura o Id escolhido
            if(anterior == NULL) {//Caso não exista anterior
                headveiculo = atual->proximo;//O primeiro passa a ser o seguinte
            }
            else {
                anterior->proximo = atual->proximo;//Caso contrário substitui o endereço
            }

            return (0);
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

//Gravar para bin
void GuardarParaFicheiroVeiculo() {
    FILE *fp = fopen("dados_veiculos.bin", "wb");
    NodeVeiculo *atual = headveiculo;

    while(atual != NULL) {
        fprintf(fp, "%d %s %f %d %s\n", atual->nodeveiculo.numeroveiculo, atual->nodeveiculo.autonomia, atual->nodeveiculo.capacidade, atual->nodeveiculo.localizacaogeocode);
        atual = atual->proximo;
    }

    fclose(fp);
}

//Apagar memoria
int ApagarMemoriaVeiculo(){
    NodeVeiculo *atual = headveiculo;
    NodeVeiculo* temp;
    while (headveiculo!=NULL)
    {
    temp=headveiculo;
    headveiculo = headveiculo -> proximo;
    free(temp);
    }
    return (-1);
}