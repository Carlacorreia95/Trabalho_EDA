// só usar o printf no main
#include "bibliotecaclientes.h"
//#include "bibliotecaclientes.c"
#include "bibliotecaveiculos.h"
//#include "bibliotecaveiculos.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int opcao, numerocliente,numeroveiculo, autonomia, capacidade;
    char nomecliente[50], morada[50], localizacaogeocode;
    float saldo;
    long nif;
    NodeDefinicaoDeCliente clientes[50],headcliente;
    NodeVeiculo headveiculo;
    // colocar os numeros de cliente a somar??
    // adiciona os clientes um a um 
    int LerDados(NodeDefinicaoDeCliente clientes[]);
   
    do {
        printf("\n1. Adiciona Cliente  \n2. Remove um cliente\n3. Altera os dados dos clientes\n4. Guarda a Lista para os ficheiros\n5. Apagar a memoria\6.Adiciona Veículos\n0. Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Insira o nome: ");
                scanf("%s", &nomecliente);
                printf("Coloque o numero: ");
                scanf("%d", &numerocliente);
                printf("asdafdfgdfg"); // printf("%s",GetMsg(27,Idiom)
                char teste[50]="asdsdfgdfhdfgh";
                
                AdicionarNode(numerocliente, nomecliente, 123.0, 124572752, teste );
                break;
            case 2:
                printf("Coloque o Numero de Cliente a remover: ");
                scanf("%d", &numerocliente);
                ApagarNode(numerocliente);
                break;
            case 3:
                printf("Escolha o Numero de Cliente para alterar a informação: ");
                scanf("%d", &numerocliente);
                printf("Insira o Nome: ");
                scanf("%s", nomecliente);
                printf("Insira o morada: ");
                scanf("%s", morada);
                ModificarNode(numerocliente, nomecliente, 123.0, 124572752, morada,headcliente);
                break;
            case 4:
                GuardarParaFicheiro();
                printf("Guardar a Lista no ficheiro.\n");
                break;
            case 6:
                printf("Insira o nº veiculo : ");
                scanf("%d", &numeroveiculo);
                printf("Coloque o numero: ");
                scanf("%d", &autonomia);
                printf("Insira o nº veiculo : ");
                scanf("%d", &capacidade);
                printf("Coloque o numero: ");
                scanf("%d", &localizacaogeocode);
                //AdicionarVeiculo(numeroveiculo, nomecliente, 50);
                // printf("%s",GetMsg(27,Idiom)
                
            case 0:
                printf("Sair do Programa .\n");
                ApagarMemoria();
                break;
            default:
                printf("Opçao inválida.\n");
                break;
        }
    } while(opcao != 6);

    return 0;
}