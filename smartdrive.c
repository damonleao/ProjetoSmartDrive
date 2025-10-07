#include <stdio.h>

int main()
{
    char destino[50], opcao;
    double distancia, horas, minutos, tempo_total;
    double distancia_percorrida, combustivel_gasto;
    double autonomia_veiculo, combustivel_atual, capacidade_tanque;
    double alcance, litros_abastecer, valor_litro, custo_total;
    double consumo_estimado, velocidade_media;

    printf("===========================\n");
    printf("         SMARTDRIVE\n");
    printf("===========================\n\n");

    // DESTINO
    printf("Destino da viagem: ");
    scanf(" %[^\n]", destino);

    // DISTÂNCIA
    do
    {
        printf("Distancia ate %s (KM): ", destino);
        scanf("%lf", &distancia);
        if (distancia <= 0)
            printf("Valor invalido! A distancia deve ser maior do que zero.\n");
    }
    while (distancia <= 0);

    // TEMPO
    do
    {
        printf("\n-- TEMPO DE VIAGEM --\n");
        printf("Horas: ");
        scanf("%lf", &horas);
        printf("Minutos: ");
        scanf("%lf", &minutos);
        if ((horas == 0 && minutos == 0) || horas < 0 || minutos < 0)
            printf("Valor invalido! Pelo menos horas ou minutos devem ser maiores que zero e nenhum dos valores pode ser negativo.\n");
    }
    while ((horas == 0 && minutos == 0) || horas < 0 || minutos < 0);

    tempo_total = horas + (minutos / 60.0);

    // AUTONOMIA
    do
    {
        printf("\n-- CALCULO DA AUTONOMIA --\n");
        printf("Informe uma viagem anterior para estimar o consumo.\n");
        printf("Distancia percorrida (KM): ");
        scanf("%lf", &distancia_percorrida);
        printf("Combustivel gasto (L): ");
        scanf("%lf", &combustivel_gasto);

        if (distancia_percorrida <= 0 || combustivel_gasto <= 0)
            printf("Valores invalidos! Ambos devem ser maiores que zero.\n");
    }
    while (distancia_percorrida <= 0 || combustivel_gasto <= 0);

    autonomia_veiculo = distancia_percorrida / combustivel_gasto;
    printf("Autonomia estimada do veiculo: %.2f KM/L\n", autonomia_veiculo);

    // TANQUE
    do
    {
        printf("\n-- INFORMACOES SOBRE O COMBUSTIVEL --\n");
        printf("Capacidade total do tanque (L): ");
        scanf("%lf", &capacidade_tanque);
        printf("Combustivel atual (L): ");
        scanf("%lf", &combustivel_atual);

        if (capacidade_tanque <= 0 || combustivel_atual < 0 || combustivel_atual > capacidade_tanque)
            printf("Valores invalidos! Verifique o limite do tanque e tente novamente.\n");
    }
    while (capacidade_tanque <= 0 || combustivel_atual < 0 || combustivel_atual > capacidade_tanque);

    // ALCANCE
    alcance = combustivel_atual * autonomia_veiculo;
    printf("\nCom %.2f L de combustivel, voce pode percorrer ate %.2f KM.\n", combustivel_atual, alcance);

    custo_total = 0.0;

    // ABASTECIMENTO
    if (alcance < distancia)
    {
        printf("\nAlcance atual insuficiente (%.2f KM).", alcance);
        printf("\nDeseja abastecer? [S/N]: ");
        scanf(" %c", &opcao);

        if (opcao == 'S' || opcao == 's')
        {
            do
            {
                printf("Quantos litros deseja abastecer? ");
                scanf("%lf", &litros_abastecer);

                if (litros_abastecer <= 0)
                    printf("Valor invalido! Deve ser maior que zero.\n");
                else if (combustivel_atual + litros_abastecer > capacidade_tanque)
                    printf("Nao e possivel abastecer essa quantidade. O tanque so comporta mais %.2f L.\n",
                           capacidade_tanque - combustivel_atual);

            }
            while (litros_abastecer <= 0 || combustivel_atual + litros_abastecer > capacidade_tanque);

            printf("Valor do litro do combustivel (R$): ");
            scanf("%lf", &valor_litro);

            combustivel_atual += litros_abastecer;
            custo_total += litros_abastecer * valor_litro;
            alcance = combustivel_atual * autonomia_veiculo;

            printf("\nTanque atualizado: %.2f L, Alcance: %.2f KM, Custo total: R$ %.2f\n",
                   combustivel_atual, alcance, custo_total);
        }
    }

    if (alcance >= distancia)
        printf("\nAgora voce pode completar sua viagem para %s!\n", destino);
    else
        printf("\nAinda nao ha combustivel suficiente para completar a viagem.\n");

    // RESUMO
    consumo_estimado = distancia / autonomia_veiculo;
    velocidade_media = distancia / tempo_total;

    printf("\n=============================\n");
    printf("       RESUMO DA VIAGEM\n");
    printf("=============================\n");
    printf("Destino: %s\n", destino);
    printf("Distancia total: %.2f KM\n", distancia);
    printf("Velocidade media: %.2f KM/H\n", velocidade_media);
    printf("Consumo estimado: %.2f L (%.2f KM/L)\n", consumo_estimado, autonomia_veiculo);
    printf("Tempo estimado: %.2f horas (%.2f minutos)\n", tempo_total, tempo_total * 60);
    printf("Custo total de combustivel: R$ %.2f\n", custo_total);

    printf("\nObrigado pela utilizacao do SMARTDRIVE e boa viagem!\n");

    return 0;
}
