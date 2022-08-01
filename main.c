#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"library/func.h"

int main(int argc, char** argv) {
      char code[3], name[25];
      int larg, alt, i, color_max, menu;

      printf("Digite o nome da imagem sem a extensao .pmm\n");
      scanf("%s", name);
      achar_max(name);
      pixel **imagem = (pixel**)malloc(MAX * sizeof(pixel*));
          for (i = 0; i < MAX; ++i){
              imagem[i] = (pixel*)malloc(MAX * sizeof(pixel));
          }

      pixel **copia_img = (pixel**)malloc(MAX * sizeof(pixel*));
          for (i = 0; i < MAX; ++i){
              copia_img[i] = (pixel*)malloc(MAX * sizeof(pixel));
          }


    	ler(imagem, name, code, &color_max, &larg, &alt);
    	txt();
      scanf ("%d",&menu);
      switch (menu){
            /*Filtros de posicoes*/
            case 1:
                system("clear");
                espelho_horizontal(imagem, copia_img, larg, alt);
                break;
            case 2:
                system("clear");
                espelho_vertical(imagem, copia_img, larg, alt);
                break;
            case 3:
                system("clear");
                rotacao_esquerda(imagem, copia_img, larg, alt);
                break;
            case 4:
                system("clear");
                rotacao_direita(imagem, copia_img, larg, alt);
                break;
            /*filtros de colorizacoes*/
            case 5:
                system("clear");
                cinza(imagem, larg, alt);
                break;
            case 6:
                system("clear");
                preto_branco(imagem, larg, alt);
                break;
            case 7:
                system("clear");
                contraste (imagem, larg, alt);
                break;
            case 8:
                system("clear");
                negativo(imagem, color_max, larg, alt);
                break;
            case 9:
                system("clear");
                posterize(imagem, color_max, larg, alt);
                break;
            case 10:
                system("clear");
                pixalizar(imagem, larg, alt);
                break;
            case 11:
                system("clear");
                img_emboss(imagem, larg, alt);
                break;
            case 12:
                system("clear");
                sharpening(imagem, copia_img, larg, alt);
                break;
            case 13:
                system("clear");
                img_blurring(imagem, larg, alt);
                break;
            case 14:
                system("clear");
                bordas(imagem, copia_img, larg, alt);
                break;
            case 15:
                system("clear");
                entrada(imagem, copia_img, larg, alt);
                break;
            case 0:
                system("clear");
                exit(1);
                break;
        	default:
                system("clear");
            	  error_msg(0);
                exit(1);
    	}

    	salvar(imagem, code, color_max, larg, alt);
    	destruir(imagem);

		return 0;
}
