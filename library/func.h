#include"heads.h"
#include"load_save.h"
#include"visual.h"

void espelho_horizontal (pixel **imagem, pixel **copia_img, int largura, int altura){
  int i, j;
  for (i = 0; i < altura; i++) {
      for (j = 0; j < largura; j++) {
          copia_img[i][j].r = imagem[i][largura - j].r;
          copia_img[i][j].g = imagem[i][largura - j].g;
          copia_img[i][j].b = imagem[i][largura - j].b;
      }
  }

  for (i = 0; i < altura; i++) {
      for (j = 0; j < largura; j++) {
          imagem[i][j].r = copia_img[i][j].r;
          imagem[i][j].g = copia_img[i][j].g;
          imagem[i][j].b = copia_img[i][j].b;
      }
  }
}
void espelho_vertical(pixel **imagem, pixel **copia_img, int largura, int altura){
  int i, j;
  for (i = 0; i < altura; i++) {
      for (j = 0; j < largura; j++) {
          copia_img[i][j].r = imagem[largura - i][j].r;
          copia_img[i][j].g = imagem[largura - i][j].g;
          copia_img[i][j].b = imagem[largura - i][j].b;
      }
  }

  for (i = 0; i < altura; i++) {
      for (j = 0; j < largura; j++) {
          imagem[i][j].r = copia_img[i][j].r;
          imagem[i][j].g = copia_img[i][j].g;
          imagem[i][j].b = copia_img[i][j].b;
      }
  }
}
void rotacao_esquerda(pixel **imagem, pixel **copia_img, int largura, int altura){
    int i, j;
        for(i = 0; i < largura; i++) {
            for(j = 0; j < altura; j++) {
                copia_img[i][j].r = imagem[j][largura-i-1].r;
                copia_img[i][j].g = imagem[j][largura-i-1].g;
                copia_img[i][j].b = imagem[j][largura-i-1].b;
            }
        }

        for (i = 0; i < largura; i++) {
            for (j = 0; j < altura; j++) {
                 imagem[i][j].r = copia_img[i][j].r;
                 imagem[i][j].g = copia_img[i][j].g;
                 imagem[i][j].b = copia_img[i][j].b;
            }
        }
}
void rotacao_direita(pixel **imagem, pixel **copia_img, int largura, int altura){
    int i, j;

    for(i = 0; i < altura; i++) {
        for(j = 0; j < largura; j++) {
            copia_img[i][j].r = imagem[altura - j -1][i].r;
            copia_img[i][j].g = imagem[altura - j -1][i].g;
            copia_img[i][j].b = imagem[altura - j -1][i].b;
        }
    }

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            imagem[i][j].r = copia_img[i][j].r;
            imagem[i][j].g = copia_img[i][j].g;
            imagem[i][j].b = copia_img[i][j].b;
        }
    }
}
void cinza(pixel **imagem, int largura, int altura) {
   int i, j;
   int media;
    for(i = 0; i <altura; i++){
        for(j = 0; j < largura; j++){
            media = (imagem[i][j].r + imagem[i][j].g + imagem[i][j].b) / 3;
            imagem[i][j].g = media;
            imagem[i][j].r = media;
            imagem[i][j].b = media;
        }
    }
}
void preto_branco(pixel **imagem, int largura, int altura) {
    int i, j, media;
    for(i = 0; i <altura; i++){
        for(j = 0; j < largura; j++){
            media = (imagem[i][j].r + imagem[i][j].g + imagem[i][j].b) / 3;
            if(media > 127){
                imagem[i][j].g = 255;
                imagem[i][j].r = 255;
                imagem[i][j].b = 255;
            }else{
                imagem[i][j].g = 0;
                imagem[i][j].r = 0;
                imagem[i][j].b = 0;
            }
        }
    }
}
void contraste (pixel **imagem, int largura, int altura) {
   int i, j;

   float contrast = 128;
   float F = (259 * (contrast + 255)) / (255 * (259 - contrast));

   for(i = 0; i <altura; i++){
        for(j = 0; j < largura; j++){
            imagem[i][j].r = F *(imagem[i][j].r - 128) + 128;
            imagem[i][j].g = F *(imagem[i][j].g - 128) + 128;
            imagem[i][j].b = F *(imagem[i][j].b - 128) + 128;
        }
    }
  }
void negativo(pixel **imagem, int color_max, int largura, int altura){
    int i, j;
    for(i = 0; i < altura; i++){
        for(j = 0; j < largura; j++){
            imagem[i][j].r = color_max - imagem[i][j].r;
            imagem[i][j].g = color_max - imagem[i][j].g;
            imagem[i][j].b = color_max - imagem[i][j].b;
        }
    }
}
void posterize(pixel **imagem, int color_max, int largura, int altura) {
    int i, j;

    for (i = 0; i < altura; i++)
        for (j = 0; j < largura; j++)
            imagem[i][j].r = (imagem[i][j].r > color_max/2) ? color_max: 0,
            imagem[i][j].g = (imagem[i][j].g > color_max/2) ? color_max: 0,
            imagem[i][j].b = (imagem[i][j].b > color_max/2) ? color_max: 0;
}
void pixalizar(pixel **imagem, int largura, int altura){
    int i, j;
    pixel original[altura][largura];
    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            original[i][j].r = imagem[i][j].r;
            original[i][j].g = imagem[i][j].g;
            original[i][j].b = imagem[i][j].b;
        }
    }
    pixel Media;
    for(i = 1; i <altura; i += 2){
        for(j = 1; j < largura; j += 2){
            Media.r = (original[i - 1][j - 1].r + original[i - 1][j].r + original[i][j - 1].r + original[i][j].r) / 4;
            Media.g = (original[i - 1][j - 1].g + original[i - 1][j].g + original[i][j - 1].g + original[i][j].g) / 4;
            Media.b = (original[i - 1][j - 1].b + original[i - 1][j].b + original[i][j - 1].b + original[i][j].b) / 4;

            imagem[i - 1][j - 1] = Media;
            imagem[i - 1][j] = Media;
            imagem[i][j - 1] = Media;
            imagem[i][j] = Media;
        }
    }
}
void img_emboss(pixel **imagem, int largura, int altura) {
    /*
      Função para deixar a imagem com o efeito de Alto Relevo
     *  Esse filtro pega o valor de uma posição (i + 1, j) e subtrai do
     *  valor da posição oposta (i - 1, j), substiruindo no valor central
     *  (i, j) e somando com a metade do componente para clareamento. <br>
     *  Seguindo a matriz:
     *  | 0 -1  0 |
     *  | 0  0  0 | + max/2
     *  | 0  1  0 |
     */

    int i, j;
    pixel tmp[altura][largura];

    /* Copia a imagem original para a temporária*/
    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            tmp[i][j].r = imagem[i][j].r;
            tmp[i][j].g = imagem[i][j].g;
            tmp[i][j].b = imagem[i][j].b;
        }
    }

    for (i = 1; i < altura - 1; i++)
        for (j = 0; j < largura -1; j++)
            tmp[i][j].r = imagem[i+1][j].r - imagem[i-1][j].r + 255/2,
            tmp[i][j].g = imagem[i+1][j].g - imagem[i-1][j].g + 255/2,
            tmp[i][j].b = imagem[i+1][j].b - imagem[i-1][j].b + 255/2;
    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            imagem[i][j].r = tmp[i][j].r;
            imagem[i][j].g = tmp[i][j].g;
            imagem[i][j].b = tmp[i][j].b;
        }
    }
}
void sharpening(pixel **imagem, pixel **copia_img, int largura, int altura) {
    int i, j;

    for( i = 0; i < altura; i++) {
        for(j = 0; j < largura; j++) {
            copia_img[i][j].r = 0;
            copia_img[i][j].g = 0;
            copia_img[i][j].b = 0;
        }
    }

    for(i = 1; i < altura - 1; i++) {
        for(j = 1; j < largura - 1; j++) {
            copia_img[i][j].r += (imagem[i-1][j-1].r * 0);
            copia_img[i][j].g += (imagem[i-1][j-1].g * 0);
            copia_img[i][j].b += (imagem[i-1][j-1].b * 0);

            copia_img[i][j].r += (imagem[i-1][j].r * -1);
            copia_img[i][j].g += (imagem[i-1][j].g * -1);
            copia_img[i][j].b += (imagem[i-1][j].b * -1);

            copia_img[i][j].r += (imagem[i-1][j+1].r * 0);
            copia_img[i][j].g += (imagem[i-1][j+1].g * 0);
            copia_img[i][j].b += (imagem[i-1][j+1].b * 0);

            copia_img[i][j].r += (imagem[i][j-1].r * -1);
            copia_img[i][j].g += (imagem[i][j-1].g * -1);
            copia_img[i][j].b += (imagem[i][j-1].b * -1);

            copia_img[i][j].r += (imagem[i][j].r * 5);
            copia_img[i][j].g += (imagem[i][j].g * 5);
            copia_img[i][j].b += (imagem[i][j].b * 5);

            copia_img[i][j].r += (imagem[i][j+1].r * -1);
            copia_img[i][j].g += (imagem[i][j+1].g * -1);
            copia_img[i][j].b += (imagem[i][j+1].b * -1);

            copia_img[i][j].r += (imagem[i+1][j-1].r * 0);
            copia_img[i][j].g += (imagem[i+1][j-1].g * 0);
            copia_img[i][j].b += (imagem[i+1][j-1].b * 0);

            copia_img[i][j].r += (imagem[i+1][j].r * -1);
            copia_img[i][j].g += (imagem[i+1][j].g * -1);
            copia_img[i][j].b += (imagem[i+1][j].b * -1);

            copia_img[i][j].r += (imagem[i+1][j+1].r * 0);
            copia_img[i][j].g += (imagem[i+1][j+1].g * 0);
            copia_img[i][j].b += (imagem[i+1][j+1].b * 0);
        }
    }

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            imagem[i][j].r = copia_img[i][j].r;
            imagem[i][j].g = copia_img[i][j].g;
            imagem[i][j].b = copia_img[i][j].b;
        }
    }
}
void img_blurring(pixel **imagem, int largura, int altura) {
     int i, j;
     pixel tmp[altura][largura];

     /* Copia a imagem original para a temporária*/
     for (i = 0; i < altura; i++) {
         for (j = 0; j < largura; j++) {
             tmp[i][j].r = imagem[i][j].r;
             tmp[i][j].g = imagem[i][j].g;
             tmp[i][j].b = imagem[i][j].b;
         }
     }

    for (i = 1; i < altura - 1; i++)
        for (j = 1; j < largura - 1; j++)
            imagem[i][j].r = (tmp[i-1][j-1].r + tmp[i-1][j].r + tmp[i-1][j+1].r +
                           tmp[i][j-1].r + tmp[i][j].r + tmp[i][j+1].r +
                           tmp[i+1][j-1].r + tmp[i+1][j].r + tmp[i+1][j+1].r)/9,
            imagem[i][j].g = (tmp[i-1][j-1].g + tmp[i-1][j].g + tmp[i-1][j+1].g +
                           tmp[i][j-1].g + tmp[i][j].g + tmp[i][j+1].g +
                           tmp[i+1][j-1].g + tmp[i+1][j].g + tmp[i+1][j+1].g)/9,
            imagem[i][j].b = (tmp[i-1][j-1].b + tmp[i-1][j].b + tmp[i-1][j+1].b +
                           tmp[i][j-1].b + tmp[i][j].b + tmp[i][j+1].b +
                           tmp[i+1][j-1].b + tmp[i+1][j].b + tmp[i+1][j+1].b)/9;
}
void bordas (pixel **imagem, pixel **copia_img, int largura, int altura){
    int i, j;
    for( i = 0; i < altura; i++) {
        for(j = 0; j < largura; j++) {
            copia_img[i][j].r = 0;
            copia_img[i][j].g = 0;
            copia_img[i][j].b = 0;
        }
    }
    for(i = 1; i < altura - 1; i++) {
        for(j = 1; j < largura - 1; j++) {
            copia_img[i][j].r += (imagem[i-1][j-1].r * -1);
            copia_img[i][j].g += (imagem[i-1][j-1].g * -1);
            copia_img[i][j].b += (imagem[i-1][j-1].b * -1);

            copia_img[i][j].r += (imagem[i-1][j].r * -1);
            copia_img[i][j].g += (imagem[i-1][j].g * -1);
            copia_img[i][j].b += (imagem[i-1][j].b * -1);

            copia_img[i][j].r += (imagem[i-1][j+1].r * -1);
            copia_img[i][j].g += (imagem[i-1][j+1].g * -1);
            copia_img[i][j].b += (imagem[i-1][j+1].b * -1);

            copia_img[i][j].r += (imagem[i][j-1].r) * -1;
            copia_img[i][j].g += (imagem[i][j-1].g * -1);
            copia_img[i][j].b += (imagem[i][j-1].b * -1);

            copia_img[i][j].r += (imagem[i][j].r * 8);
            copia_img[i][j].g += (imagem[i][j].g * 8);
            copia_img[i][j].b += (imagem[i][j].b * 8);

            copia_img[i][j].r += (imagem[i][j+1].r * -1);
            copia_img[i][j].g += (imagem[i][j+1].g * -1);
            copia_img[i][j].b += (imagem[i][j+1].b * -1);

            copia_img[i][j].r += (imagem[i+1][j-1].r * -1);
            copia_img[i][j].g += (imagem[i+1][j-1].g * -1);
            copia_img[i][j].b += (imagem[i+1][j-1].b * -1);

            copia_img[i][j].r += (imagem[i+1][j].r * -1);
            copia_img[i][j].g += (imagem[i+1][j].g * -1);
            copia_img[i][j].b += (imagem[i+1][j].b * -1);

            copia_img[i][j].r += (imagem[i+1][j+1].r * -1);
            copia_img[i][j].g += (imagem[i+1][j+1].g * -1);
            copia_img[i][j].b += (imagem[i+1][j+1].b * -1);
        }
    }

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            imagem[i][j].r = copia_img[i][j].r;
            imagem[i][j].g = copia_img[i][j].g;
            imagem[i][j].b = copia_img[i][j].b;
        }
    }
}
void entrada (pixel **imagem, pixel **copia_img, int largura, int altura){
    int i, j;
    float user[3][3];
    printf ("PREENCHA SUA MATRIZ SEGUINDO O ESQUEMA:\n");
    printf (" |00 01 02|\n |10 11 12| \n |20 21 22|\n");

    for(i=0; i<3; i++){
        for (j=0; j<3; j++){
            printf ("VALOR DE [%d][%d] >> ",i, j);
            scanf("%f",&user[i][j]);
        }
    }


    for( i = 0; i < altura; i++) {
        for(j = 0; j < largura; j++) {
            copia_img[i][j].r = 0;
            copia_img[i][j].g = 0;
            copia_img[i][j].b = 0;
        }
    }

    for(i = 1; i < altura - 1; i++) {
        for(j = 1; j < largura - 1; j++) {
            copia_img[i][j].r += (imagem[i-1][j-1].r * user[0][0]);
            copia_img[i][j].g += (imagem[i-1][j-1].g * user[0][0]);
            copia_img[i][j].b += (imagem[i-1][j-1].b * user[0][0]);

            copia_img[i][j].r += (imagem[i-1][j].r * user[0][1]);
            copia_img[i][j].g += (imagem[i-1][j].g * user[0][1]);
            copia_img[i][j].b += (imagem[i-1][j].b * user[0][1]);

            copia_img[i][j].r += (imagem[i-1][j+1].r * user[0][2]);
            copia_img[i][j].g += (imagem[i-1][j+1].g * user[0][2]);
            copia_img[i][j].b += (imagem[i-1][j+1].b * user[0][2]);

            copia_img[i][j].r += (imagem[i][j-1].r * user[1][0]);
            copia_img[i][j].g += (imagem[i][j-1].g * user[1][0]);
            copia_img[i][j].b += (imagem[i][j-1].b * user[1][0]);

            copia_img[i][j].r += (imagem[i][j].r * user[1][1]);
            copia_img[i][j].g += (imagem[i][j].g * user[1][1]);
            copia_img[i][j].b += (imagem[i][j].b * user[1][1]);

            copia_img[i][j].r += (imagem[i][j+1].r * user[1][2]);
            copia_img[i][j].g += (imagem[i][j+1].g * user[1][2]);
            copia_img[i][j].b += (imagem[i][j+1].b * user[1][2]);

            copia_img[i][j].r += (imagem[i+1][j-1].r * user[2][0]);
            copia_img[i][j].g += (imagem[i+1][j-1].g * user[2][0]);
            copia_img[i][j].b += (imagem[i+1][j-1].b * user[2][0]);

            copia_img[i][j].r += (imagem[i+1][j].r * user[2][1]);
            copia_img[i][j].g += (imagem[i+1][j].g * user[2][1]);
            copia_img[i][j].b += (imagem[i+1][j].b * user[2][1]);

            copia_img[i][j].r += (imagem[i+1][j+1].r * user[2][2]);
            copia_img[i][j].g += (imagem[i+1][j+1].g * user[2][2]);
            copia_img[i][j].b += (imagem[i+1][j+1].b * user[2][2]);
        }
    }

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            imagem[i][j].r = copia_img[i][j].r;
            imagem[i][j].g = copia_img[i][j].g;
            imagem[i][j].b = copia_img[i][j].b;
        }
    }

}
