
#ifndef B
#define B 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "bibliotecaclientes.h"



//definir veículos
//numero.veiculo,autonomia,capacidade,localizaçãogeocode
typedef struct Veiculo
{
    int numeroveiculo, autonomia, capacidade;
    char localizacaogeocode[50];
}DadosVeiculo;

// Lista ligada Cliente
typedef struct ListaVeiculo
{
    DadosVeiculo nodeveiculo;
    struct ListaVeiculo *proximo;
}NodeVeiculo;

NodeVeiculo *headveiculo = NULL;
int LerVeiculos(NodeVeiculo veiculo[]);//char nomedoficheiroveiculo
int AdicionarVeiculos (int numeroveiculo, int autonomia,int capacidade, char localizacaogeocode[]);
int ApagarNodeVeiculos( int numeroveiculo);
int ModificarNodeVeiculos( int numeroveiculo, int autonomia, int capacidade, char localizacaogeocode[]);
int OrdenarDecrescenteVeiculos( int autonomia);
void GuardarParaFicheiroVeiculo();
int ApagarMemoriaVeiculo();

#endif

