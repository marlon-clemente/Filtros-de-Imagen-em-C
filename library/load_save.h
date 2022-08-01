void achar_max(char* name) {
      int largura, altura;
      char code[3];
      FILE *ppm;
      strcat(name, ".ppm");
   		 if ((ppm = fopen(name, "r")) == NULL) {
        	error_msg(1);
        	exit(1);
    	}

    	fscanf(ppm, "%s", code);
    	fscanf(ppm, "%d %d", &largura, &altura);

      if(largura>altura){
        MAX = largura;
      }else{
        MAX = altura;
      }
}


void ler(pixel **imagem, char* name, char *code, int *color_max, int *largura, int *altura) {
    	FILE *ppm;
   		 if ((ppm = fopen(name, "r")) == NULL) {
        	error_msg(1);
        	exit(1);
    	}
    	fscanf(ppm, "%s", code);
    	fscanf(ppm, "%d %d", largura, altura);
    	fscanf(ppm, "%d", color_max);

      int i,j;
    	for (i = 0; i < *altura; i++) {
        	for (j = 0; j < *largura; j++) {
            	fscanf(ppm, "%d", &imagem[i][j].r);
            	fscanf(ppm, "%d", &imagem[i][j].g);
            	fscanf(ppm, "%d", &imagem[i][j].b);
        	}
    	}

    	fclose(ppm);
}

void salvar(pixel **imagem, char *code, int color_max, int largura, int altura){
    	int i, j;
    	FILE *ppm;
    	char nome_arq[50];
   	  printf ("Como que nome deseja salvar sua imagem?\n");

    	scanf("%s", nome_arq);
    	ppm = fopen(nome_arq, "w");
    	fprintf(ppm, "P3\n");
    	fprintf(ppm, "%d\n ", largura);
   	 	fprintf(ppm, "%d\n", altura);
    	fprintf(ppm, "%d\n", color_max);
      /*
      Laco para Salvar e verificar por pixel a pixel se nao ha nenhum
      pixel maior que 255 ou menor que 0, assim evitando alguma erros
      */
    	for (i = 0; i < altura; i++) {
        	for (j = 0; j < largura; j++) {
            	fprintf(ppm, "%d ", (imagem[i][j].r > 255) ? 255 : (imagem[i][j].r < 0) ? 0 : imagem[i][j].r);
            	fprintf(ppm, "%d ", (imagem[i][j].g > 255) ? 255 : (imagem[i][j].g < 0) ? 0 : imagem[i][j].g);
            	fprintf(ppm, "%d\n",(imagem[i][j].b > 255) ? 255 : (imagem[i][j].b < 0) ? 0 : imagem[i][j].b);
        	}
    	}

    	fclose(ppm);
}

void destruir (pixel **imagem){
    int i;
    for (i = 0; i < MAX; ++i){
        free(imagem[i]);
    }
    free(imagem);
}
