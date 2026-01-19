#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main()
{
  // Área para definição das variáveis para armazenar as propriedades das cidades

  // Estou usando variaveis em inglês como parte do estudo também.
  // Nas pesquisas vi que na linguagem C é mais comum usar nomes de variáveis em snake case

  int card_id1, population1, number_of_tourist_attractions1;
  float population_density1, gdp_per_capita1;
  char city_name1[50], state1;
  float area1, gdp1;

  int card_id2, population2, number_of_tourist_attractions2;
  float population_density2, gdp_per_capita2;
  char city_name2[50], state2;
  float area2, gdp2;

  // Define a variável billion para conversão de bilhões para unidades
  float billion = 1e9f;

  // Área para entrada de dados

  printf("Insira os dados da primeira carta \n");

  printf("Estado da carta: "); // No problema o estádo é de A até H (Cada uma das letras representa um estado do pais)
  scanf(" %c", &state1);

  getchar();

  printf("Nome da cidade: ");
  fgets(city_name1, sizeof(city_name1), stdin);
  city_name1[strcspn(city_name1, "\n")] = 0;

  printf("Código da carta: ");
  scanf("%d", &card_id1);

  printf("População da cidade: ");
  scanf("%d", &population1);

  printf("Área da cidade (em km²): ");
  scanf("%f", &area1);

  printf("PIB da cidade (em bilhões): ");
  scanf("%f", &gdp1);

  printf("Numero de pontos turisticos ");
  scanf("%d", &number_of_tourist_attractions1);

  // Faz a divisão da população pela área para obter a densidade populacional por hab/km²
  population_density1 = population1 / area1;

  gdp_per_capita1 = (gdp1 * billion) / population1; // Multiplico por 1000 para converter de bilhões para milhões

  printf("---------------------------------------------------\n");

  printf("\n Insira os dados da segunda carta \n");

  printf("Estado da carta: "); // No problema o estádo é de A até H (Cada uma das letras representa um estado do pais)
  scanf(" %c", &state2);

  getchar();

  printf("Nome da cidade: ");
  fgets(city_name2, sizeof(city_name2), stdin); // Usei o fgets para poder colocar o nome completo da cidade
  city_name2[strcspn(city_name2, "\n")] = 0;

  printf("Código da carta: ");
  scanf("%d", &card_id2);

  printf("População da cidade: ");
  scanf("%d", &population2);

  printf("Área da cidade (em km²): ");
  scanf("%f", &area2);

  printf("PIB da cidade (em bilhões): ");
  scanf("%f", &gdp2);

  printf("Numero de pontos turisticos ");
  scanf("%d", &number_of_tourist_attractions2);

  // Faz a divisão da população pela área para obter a densidade populacional por hab/km²
  population_density2 = population2 / area2;

  gdp_per_capita2 = (gdp2 * 1e9f) / population2; // Multiplico por 1000 para converter de bilhões para milhões

  printf("---------------------------------------------------\n");

  // Área para exibição dos dados da cidade

  printf("\nDados da carta 1: \n");

  printf("Estado: %c \n", state1);
  printf("Cidade: %s \n", city_name1);
  printf("Código da carta: %c%02d \n", state1, card_id1);
  printf("População: %d \n", population1);
  printf("Área: %.2f km² \n", area1);
  printf("PIB: %.2f bilhões \n", gdp1);
  printf("Pontos Turísticos: %d \n", number_of_tourist_attractions1);
  printf("Densidade populacional: %.2f hab/km² \n", population_density1);
  printf("PIB per capita: %.2f reais \n", gdp_per_capita1);

  printf("---------------------------------------------------\n");

  printf("\nDados da carta 2: \n");

  printf("Estado: %c \n", state2);
  printf("Cidade: %s \n", city_name2);
  printf("Código da carta: %c%02d \n", state2, card_id2);
  printf("População: %d \n", population2);
  printf("Área: %.2f km² \n", area2);
  printf("PIB: %.2f bilhões \n", gdp2);
  printf("Pontos Turísticos: %d \n", number_of_tourist_attractions2);
  printf("Densidade populacional: %.2f hab/km² \n", population_density2);
  printf("PIB per capita: %.2f reais \n", gdp_per_capita2);

  return 0;
}
