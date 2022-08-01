
void error_msg (int x){
    switch (x) {
        case 0:
            printf("Escolha Invalida!\n");
            break;
        case 1:
            printf("A imagem nao pode ser aberta!\n");
            printf("1 - Confira que voce digitou corretamente o nome da imagem\n");
            printf("    lembrando que nao eh necessario utilizar a extenssao .ppm\n");
            printf("2 - Confira se o diretorio da imagem esta correto\n");
            printf("3 - Verifique se a imagem realmente existe\n");
            break;
        case 2:
            printf("A imagem não eh de formato PPM!\n");
            break;
        default:
            printf("Erro desconhecido\n");
    }
}

void txt (){
    printf ("     ESCOLHA O FILTRO QUE DESEJA USAR:\n");
    printf ("__________________________________________\n");
    printf ("----------ESCALAS DE MOVIMENTACAO:--------\n");
    printf ("     1    ESPELHO HORIZONTAL\n");
    printf ("     2    ESPELHO VERTICAL\n");
    printf ("     3    ROTACAO 90 ESQUERDA\n");
    printf ("     4    ROTACAO 90 DIREITA\n");
    printf ("__________________________________________\n");
    printf ("----------ESCALAS DE COLOR----------------\n");
    printf ("     5    ESCALA CINZA\n");
    printf ("     6    BINARIZACAO\n");
    printf ("     7    ALTO CONSTRASTE\n");
    printf ("     8    NEGATIVO\n");
    printf ("     9    ESCALA POSTERIZADA\n");
    printf ("     10   ESCALA PIXELIZADA\n");
    printf ("__________________________________________\n");
    printf ("----------ESCALAS DE CONVOLUCAO-----------\n");
    printf ("     11   EMBOSS\n");
    printf ("     12   SHARPENING\n");
    printf ("     13   BLURRING\n");
    printf ("     14   DETECTOR DE BORDAS\n\n");
    printf ("     15   MATRIZ DO USUARIO\n");
    printf ("__________________________________________\n");
    printf ("     0    SAIR\n");
}
