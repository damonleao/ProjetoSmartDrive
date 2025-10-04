#include <stdio.h>

int main ()
{
    double distancia; //Distância da viagem em KM
    double horas, minutos, tempo_total; //Horas, Minutos e o Tempo Total em horas da viagem
    double autonomia_veiculo; // Autonomia do carro
    double valor_litro; // Valor do litro do combustível
    double combustivel_atual; // Quantidade de combustível no veículo
    double capacidade_tanque; // Capacidade do máxima do tanque
    const double velocidade_media = 80.0; // Velocidade Média fixa
    char nova_consulta = 'S';


    do
    {

        printf("==== SMARTDRIVE ====\n");
        do
        {
            printf("\nDistancia da viagem (KM): ");
            scanf ("%lf", &distancia);
            if (distancia <= 0)
            {
                printf("Valor Invalido! A distancia deve ser maior do que zero.\n");
            }
        } while (distancia <= 0);

        do
        {
            printf ("\n--TEMPO DE VIAGEM--");
            printf("\nHoras: ");
            scanf ("%lf", &horas);
            printf("Minutos: ");
            scanf ("%lf", &minutos);
            if ((horas < 0 || minutos < 0) || (horas == 0 && minutos == 0))
            {
                printf ("Valor Invalido! Valores negativos nao sao aceitos e deve haver pelo menos um valor positivo em horas ou minutos.\n");
            }
        } while ((horas < 0 || minutos < 0) || (horas == 0 && minutos == 0));

        do
        {
            printf("\nAutonomia do automovel: ");
            scanf ("%lf", &autonomia_veiculo);
            if (autonomia_veiculo <= 0)
            {
                printf ("Valor Invalido! A autonomia deve ser maior do que zero.\n");
            }
        } while (autonomia_veiculo <= 0);


        do
        {
            printf ("\n--INFORMACOES SOBRE O COMBUSTIVEL DO VEICULO--");
            printf("\nCapacidade total do tanque: ");
            scanf ("%lf", &capacidade_tanque);
            printf("Quantidade de combustivel atual: ");
            scanf ("%lf", &combustivel_atual);
            if (capacidade_tanque <= 0 || capacidade_tanque < combustivel_atual || combustivel_atual < 0){
                printf("Valores Invalidos!A capacidade do tanque nao pode ser um valor negativo ou zero e a quantidade de combustivel\n nao pode ser maior que a capacidade do tanque.\n");
            }
        } while (capacidade_tanque <= 0 || capacidade_tanque < combustivel_atual);


        printf("\n\nDeseja realizar uma nova consulta [S/N]: ");
        scanf(" %c", &nova_consulta);
    }
    while (nova_consulta == 's' || nova_consulta == 'S');

    printf("\nObrigado pela utilizaçao do nosso sistema e otima viagem!");


    return 0;
}
