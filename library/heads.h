

typedef struct {
    int r, g, b;
}pixel;
/*Variavel que armazena o valor maximo de pixels da imagem*/
int MAX;
/*Maniplulacao de arquivos ppm*/
void achar_max(char *name);
void ler(pixel **imagem, char* name, char *code, int *color_max, int *largura, int *altura);
void salvar(pixel **imagem, char *code, int color_max, int largura, int altura);
void destruir (pixel **imagem);
/*Manipulacao de posicionamentos*/
void espelho_horizontal(pixel **imagem, pixel **copia_img, int largura, int altura);
void espelho_vertical(pixel **imagem, pixel **copia_img, int largura, int altura);
void rotacao_esquerda(pixel **imagem, pixel **copia_img, int largura, int altura);
void rotacao_direita(pixel **imagem, pixel **copia_img, int largura, int altura);
/*Manipulacao de filtros e cores*/
void cinza(pixel **imagem, int largura, int altura);
void preto_branco(pixel **imagem, int largura, int coluna);
void contraste (pixel **imagem, int largura, int altura);
void negativo(pixel **imagem, int color_max, int largura, int altura);
void posterize(pixel **imagem, int color_max, int largura, int altura);
void pixalizar (pixel **imagem, int largura, int altura);
/*Filtros com matriz de convolucao*/
void img_emboss(pixel **imagem, int largura, int altura);
void sharpening(pixel **imagem, pixel **copia_img, int largura, int altura);
void img_blurring(pixel **imagem, int largura, int altura);
void bordas (pixel **imagem, pixel **copia_img, int largura, int altura);
void entrada (pixel **imagem, pixel **copia_img, int largura, int altura);
/*Funcoes visuais*/
void txt();
void error_msg(int x);
