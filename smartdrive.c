#include <stdio.h>

int main() {
    double distancia;
    double horas, minutos, tempo_total;
    double capacidade_tanque, combustivel_atual;
    double distancia_percorrida, combustivel_gasto;
    double autonomia_veiculo, alcance, combustivel_necessario;
    double custo_total, valor_litro, litros_abastecer;
    double consumo_estimado, velocidade_media;
    char destino[50], opcao;

    printf("===========================\n");
    printf("         SMARTDRIVE\n");
    printf("===========================\n\n");

    //DESTINO
    printf("Destino da viagem: ");
    scanf(" %[^\n]", destino);

    //DISTANCIA
    printf("Distancia ate %s (KM): ", destino);
    scanf("%lf", &distancia);

    //TEMPO
    printf("\n-- TEMPO DE VIAGEM --\n");
    printf("Horas: ");
    scanf("%lf", &horas);
    printf("Minutos: ");
    scanf("%lf", &minutos);

    tempo_total = horas + (minutos / 60.0);

    // CÁLCULO DA AUTONOMIA
    printf("\n-- CALCULO DA AUTONOMIA --\n");
    printf("Informe uma viagem anterior para estimar o consumo.\n");
    printf("Distancia percorrida (KM): ");
    scanf("%lf", &distancia_percorrida);
    printf("Combustivel gasto (L): ");
    scanf("%lf", &combustivel_gasto);

    autonomia_veiculo = distancia_percorrida / combustivel_gasto;

    // VALIDACAO DA AUTONOMIA
    if (autonomia_veiculo < 5.0) {
        printf("\nAtencao: a autonomia calculada (%.2f KM/L) esta muito baixa.\n", autonomia_veiculo);
        printf("Deseja confirmar esse valor mesmo assim? [S/N]: ");
        scanf(" %c", &opcao);
        if (opcao == 'N' || opcao == 'n') {
            printf("\nReinicie o programa e verifique os valores informados.\n");
            return 0;
        }
    } else if (autonomia_veiculo > 30.0) {
        printf("\nAtencao: a autonomia calculada (%.2f KM/L) parece alta demais.\n", autonomia_veiculo);
        printf("Deseja confirmar esse valor mesmo assim? [S/N]: ");
        scanf(" %c", &opcao);
        if (opcao == 'N' || opcao == 'n') {
            printf("\nReinicie o programa e verifique os valores informados.\n");
            return 0;
        }
    }

    printf("\nAutonomia estimada do veiculo: %.2f KM/L\n", autonomia_veiculo);

    //COMBUSTIVEL
    printf("\n-- INFORMACOES SOBRE O COMBUSTIVEL --\n");
    printf("Capacidade total do tanque (L): ");
    scanf("%lf", &capacidade_tanque);
    printf("Quantidade de combustivel atual (L): ");
    scanf("%lf", &combustivel_atual);

    alcance = combustivel_atual * autonomia_veiculo;

    printf("\nCom %.2f L de combustivel, voce pode percorrer ate %.2f KM.\n", combustivel_atual, alcance);

    custo_total = 0.0;

    if (alcance < distancia) {
        printf("\nAlcance atual insuficiente (%.2f KM).", alcance);
        printf("\nDeseja abastecer? [S/N]: ");
        scanf(" %c", &opcao);

        if (opcao == 'S' || opcao == 's') {
            printf("Quantos litros deseja abastecer? ");
            scanf("%lf", &litros_abastecer);

            if (combustivel_atual + litros_abastecer > capacidade_tanque) {
                printf("Nao e possivel abastecer essa quantidade. O tanque so comporta %.2f L.\n",
                       capacidade_tanque - combustivel_atual);
            } else {
                printf("Valor do litro do combustivel (R$): ");
                scanf("%lf", &valor_litro);

                custo_total = litros_abastecer * valor_litro;
                combustivel_atual += litros_abastecer;
                alcance = combustivel_atual * autonomia_veiculo;

                printf("\nTanque atualizado: %.2f L, Alcance: %.2f KM, Custo total: R$ %.2f\n",
                       combustivel_atual, alcance, custo_total);
            }
        }
    }

    if (alcance >= distancia) {
        printf("\nAgora voce pode completar sua viagem para %s!\n", destino);
    } else {
        printf("\nAinda nao ha combustivel suficiente para completar a viagem.\n");
    }

    consumo_estimado = distancia / autonomia_veiculo;
    velocidade_media = distancia / tempo_total;

    printf("\n=============================\n");
    printf("       RESUMO DA VIAGEM\n");
    printf("=============================\n");
    printf("Destino: %s\n\n", destino);
    printf("Distancia total: %.2f KM\n", distancia);
    printf("Velocidade media: %.2f KM/H\n", velocidade_media);
    printf("Consumo estimado: %.2f L (%.2f KM/L)\n", consumo_estimado, autonomia_veiculo);
    printf("Tempo estimado: %.2f horas (%.2f minutos)\n", tempo_total, tempo_total * 60);
    printf("Custo total de combustivel: R$ %.2f\n", custo_total);

    printf("\nObrigado pela utilizacao do SMARTDRIVE e boa viagem!\n");

    return 0;
}
