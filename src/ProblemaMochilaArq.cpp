#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Função de força bruta para resolver o problema da mochila usando vetores
int bruteForceKnapsack(const vector<int> &pesos, const vector<int> &valores_itens, int capacidade_mochila, int numero_itens)
{
    // Caso base: sem itens ou capacidade da mochila zero
    if (numero_itens == 0 || capacidade_mochila == 0)
        return 0;

    // Se o peso do item atual for maior que a capacidade restante, não o incluímos
    if (pesos[numero_itens - 1] > capacidade_mochila)
        return bruteForceKnapsack(pesos, valores_itens, capacidade_mochila, numero_itens - 1);

    // Caso contrário, temos duas opções:
    // 1. Incluir o item atual
    // 2. Não incluir o item atual
    else
        return max(valores_itens[numero_itens - 1] + bruteForceKnapsack(pesos, valores_itens, capacidade_mochila - pesos[numero_itens - 1], numero_itens - 1),
                   bruteForceKnapsack(pesos, valores_itens, capacidade_mochila, numero_itens - 1));
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Uso: " << argv[0] << " <nome_do_arquivo_de_entrada>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);

    if (inputFile.fail())
    {
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return 1;
    }

    int capacidade_mochila;
    int numero_itens;

    // Lendo a capacidade da mochila
    inputFile >> capacidade_mochila;

    // Lendo o número de itens
    inputFile >> numero_itens;

    // Vetores para armazenar os pesos e valores dos itens
    vector<int> pesos(numero_itens);
    vector<int> valores_itens(numero_itens);

    // Lendo os pesos dos itens
    for (int i = 0; i < numero_itens; i++)
    {
        inputFile >> pesos[i];
    }

    // Lendo os valores dos itens
    for (int i = 0; i < numero_itens; i++)
    {
        inputFile >> valores_itens[i];
    }

    inputFile.close();

    // Chamando a função de força bruta e exibindo o resultado
    cout << "Valor máximo possível na mochila: "
         << bruteForceKnapsack(pesos, valores_itens, capacidade_mochila, numero_itens) << endl;

    return 0;
}
