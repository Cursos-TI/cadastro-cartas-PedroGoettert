#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

// No desafio acabei optando por algumas coisas que ainda não foram passado em aula, por eu já
// possuir algum tipo de conhecimento prévio em programação, como objetos, arrays e etc (Typescript)
// Então como a questão de logina não muda, precisei apenas estudar a sintaxe em C para conseguir
// implementrar algumas coisas que eu já conhecia de outras linguagens nesse desafio.
// Tentei manter um padrão de nomes usando snake_case para variaveis e tentei deixar o mais claro possivel
// Tudo o que acontece no código, para facilitar o entendimento de quem for analisar o código depois.

// Definição da estrutura da carta
typedef struct
{
  // Área para definição das variáveis para armazenar as propriedades das cidade
  // Estou usando variaveis em inglês como parte do estudo também.
  // Nas pesquisas vi que na linguagem C é mais comum usar nomes de variáveis em snake case

  int card_id, population, number_of_tourist_attractions;
  float population_density, gdp_per_capita;
  char city_name[50], state;
  float area, gdp;
  double super_power;
} Card;

// FUnção que automatiza o calculo do super_power da carta.
double calculate_super_power(const Card *card)
{
  return (double)card->population +
         (double)card->area +
         (double)card->gdp +
         (double)card->number_of_tourist_attractions +
         (double)card->population_density +
         (double)card->gdp_per_capita;
}

// Função que faz a comparação entre quem vai ganhar
const char *check_powers(double card1, double card2)
// Nos meus estudos vi que ao comparar double pode causar algum tipo de erro
// E para evitar esse erro é criado uma função que cria uma margem de erro que chamamos de epsilon
// Porém nesse momento acreditei que não preciso me aprofundar tanto, e quando realmente preciar dessa
// comparação mais precisa, irei estudar mais sobre o assunto.

// Eu quis criar uma função que me retornasse o ganhador de cada atributo da carta.
// Então criei essa função para comparar os valores e me retornar uma string com a carta que ganhou.
{
  if (card1 > card2)
  {
    return "Card1 ganhou";
  }
  else if (card1 == card2)
  {
    return "Empate";
  }
  else
  {
    return "Card2 ganhou";
  }
}

int main()
{
  // Declaro o uso da strutura Card para criar as cartas
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
    card1.super_power = calculate_super_power(&card1);
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

    card2.super_power = calculate_super_power(&card2);
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
    printf("Super Poder: %.2f \n", card1.super_power);
  }
  printf("---------------------------------------------------\n");

  printf("\nDados da carta 2: \n");

  {
    printf("Estado: %c \n", card2.state);
    printf("Cidade: %s \n", card2.city_name);
    printf("Código da carta: %c%02d \n", card2.state, card2.card_id);
    printf("População: %d \n", card2.population);                                // batalha 1
    printf("Área: %.2f km² \n", card2.area);                                     // Batalha 2
    printf("PIB: %.2f bilhões \n", card2.gdp);                                   // Batalha 3
    printf("Pontos Turísticos: %d \n", card2.number_of_tourist_attractions);     // Batalha 4
    printf("Densidade populacional: %.2f hab/km² \n", card2.population_density); // Batalha 5
    printf("PIB per capita: %.2f reais \n", card2.gdp_per_capita);               // Batalha 6
    printf("Super Poder: %.2f \n", card2.super_power);                           // Batalha 7
  }

  printf("\n---------------------------------------------------\n");

  // Área para realizar as batalhas entre as cartas

  printf("Hora da batalha!");

  printf("População: %s \n", check_powers((double)card1.population, (double)card2.population));                                               // batalha 1
  printf("Área: %s \n", check_powers((double)card1.area, (double)card2.area));                                                                // Batalha 2
  printf("PIB: %s \n", check_powers((double)card1.gdp, (double)card2.gdp));                                                                   // Batalha 3
  printf("Pontos Turísticos: %s \n", check_powers((double)card1.number_of_tourist_attractions, (double)card2.number_of_tourist_attractions)); // Batalha 4
  printf("Densidade populacional: %s \n", check_powers((double)card1.population_density, (double)card2.population_density));                  // Batalha 5
  printf("PIB per capita: %s \n", check_powers((double)card1.gdp_per_capita, (double)card2.gdp_per_capita));                                  // Batalha 6
  printf("Super Poder: %s \n", check_powers(card1.super_power, card2.super_power));                                                           // Batalha 7

  return 0;
}
