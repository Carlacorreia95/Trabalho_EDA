// Definir cliente
#ifndef A
#define A 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 25

typedef struct Cliente
{
    int numerocliente;
    long nifcliente;
    float saldo;
    char nomecliente[N], moradacliente[100];
}DefinicaoDeCliente;

// Lista ligada Cliente
typedef struct ListaClientes
{
    DefinicaoDeCliente nodecliente;
    struct ListaClientes *proximo;
}NodeDefinicaoDeCliente;

NodeDefinicaoDeCliente*headcliente = NULL;
//NodeDefinicaoDeCliente AdicionarNode(int numerocliente, char nomecliente[], float saldo, long nifcliente, char moradacliente[]);
int LerDados(NodeDefinicaoDeCliente clientes[]);
int AdicionarDadosFicheiros(NodeDefinicaoDeCliente clientes[]);
int ApagarNode( int numerocliente);
int ModificarNode(int numerocliente, char nomecliente[], float saldo, long nifcliente, char moradacliente[]);
void GuardarParaFicheiro(int numerocliente, char nomecliente[], float saldo, long nifcliente, char moradacliente[]);
int ApagarMemoria();

#endif
