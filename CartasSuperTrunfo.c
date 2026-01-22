#include <stdio.h>
#include <string.h>

typedef struct
{
  int card_id, population, number_of_tourist_attractions;
  float population_density, gdp_per_capita, super_power;
  char city_name[50], state;
  float area, gdp;
} Card;

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main()
{
  // Área para definição das variáveis para armazenar as propriedades das cidades

  // Estou usando variaveis em inglês como parte do estudo também.
  // Nas pesquisas vi que na linguagem C é mais comum usar nomes de variáveis em snake case
  Card card1;
  Card card2;

  // Define a variável billion para conversão de bilhões para unidades
  float billion = 1e9f;

  // Área para entrada de dados
  printf("Insira os dados da primeira carta \n");
  {
    printf("Estado da carta: "); // No problema o estádo é de A até H (Cada uma das letras representa um estado do pais)
    scanf(" %c", &card1.state);

    getchar();

    printf("Nome da cidade: ");
    fgets(card1.city_name, sizeof(card1.city_name), stdin);
    card1.city_name[strcspn(card1.city_name, "\n")] = 0;

    printf("Código da carta: ");
    scanf("%d", &card1.card_id);

    printf("População da cidade: ");
    scanf("%d", &card1.population);

    printf("Área da cidade (em km²): ");
    scanf("%f", &card1.area);

    printf("PIB da cidade (em bilhões): ");
    scanf("%f", &card1.gdp);

    printf("Numero de pontos turisticos ");
    scanf("%d", &card1.number_of_tourist_attractions);

    // Faz a divisão da população pela área para obter a densidade populacional por hab/km²
    card1.population_density = card1.population / card1.area;

    card1.gdp_per_capita = (card1.gdp * billion) / card1.population; // Multiplico por 1000 para converter de bilhões para milhões
  }
  printf("---------------------------------------------------\n");

  printf("\n Insira os dados da segunda carta \n");
  {
    printf("Estado da carta: "); // No problema o estádo é de A até H (Cada uma das letras representa um estado do pais)
    scanf(" %c", &card2.state);

    getchar();

    printf("Nome da cidade: ");
    fgets(card2.city_name, sizeof(card2.city_name), stdin); // Usei o fgets para poder colocar o nome completo da cidade
    card2.city_name[strcspn(card2.city_name, "\n")] = 0;

    printf("Código da carta: ");
    scanf("%d", &card2.card_id);
    printf("População da cidade: ");
    scanf("%d", &card2.population);

    printf("Área da cidade (em km²): ");
    scanf("%f", &card2.area);

    printf("PIB da cidade (em bilhões): ");
    scanf("%f", &card2.gdp);

    printf("Numero de pontos turisticos ");
    scanf("%d", &card2.number_of_tourist_attractions);

    // Faz a divisão da população pela área para obter a densidade populacional por hab/km²
    card2.population_density = card2.population / card2.area;

    card2.gdp_per_capita = (card2.gdp * 1e9f) / card2.population; // Multiplico por 1000 para converter de bilhões para milhões
  }
  printf("---------------------------------------------------\n");

  // Área para exibição dos dados da cidade

  printf("\nDados da carta 1: \n");

  {
    printf("Estado: %c \n", card1.state);
    printf("Cidade: %s \n", card1.city_name);
    printf("Código da carta: %c%02d \n", card1.state, card1.card_id);
    printf("População: %d \n", card1.population);
    printf("Área: %.2f km² \n", card1.area);
    printf("PIB: %.2f bilhões \n", card1.gdp);
    printf("Pontos Turísticos: %d \n", card1.number_of_tourist_attractions);
    printf("Densidade populacional: %.2f hab/km² \n", card1.population_density);
    printf("PIB per capita: %.2f reais \n", card1.gdp_per_capita);
  }
  printf("---------------------------------------------------\n");

  printf("\nDados da carta 2: \n");

  {
    printf("Estado: %c \n", card2.state);
    printf("Cidade: %s \n", card2.city_name);
    printf("Código da carta: %c%02d \n", card2.state, card2.card_id);
    printf("População: %d \n", card2.population);
    printf("Área: %.2f km² \n", card2.area);
    printf("PIB: %.2f bilhões \n", card2.gdp);
    printf("Pontos Turísticos: %d \n", card2.number_of_tourist_attractions);
    printf("Densidade populacional: %.2f hab/km² \n", card2.population_density);
    printf("PIB per capita: %.2f reais \n", card2.gdp_per_capita);
  }

  printf("\n---------------------------------------------------\n");

  printf("Hora da batalha!");

  return 0;
}
