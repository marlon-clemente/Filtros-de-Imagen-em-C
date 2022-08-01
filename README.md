## Gerador de Filtros de Imagens em Linguagem C  

### Compilar  

Para que o algoritmo compile e execute com sucesso, mantenha no diretório raiz uma imagem de formato PPM e siga os passos solicitados durante a execução. 

Use para compilar:

``ggc -ansi -o main main.c``
  
********************************************************  
### Filtros  

   ESCALAS DE ROTACAO:

    - ESPELHO HOTIZONTAL
    - ESPELHO VERTICAL
    - ROTACAO 90° DIREITA
    - ROTACAO 90 ESQUERDA

   FILTROS DE CORES:
 
    - ESCALA CINZA
    - BINARIZACAO (PRETO E BRANCO)
    - ALTO CONTRASTE
    - NEGATIVO
    - ESCALA POSTERIZADA
    - ESCALA PIXELZADA

   FILTROS COM MATRIZES DE CONVOLUCAO:
   
    - EMBOSS (alto relevo)
    - SHARPENING
    - BLURRING
    - DETECTOR DE BORDAS
    - MATRIZ DO USUARIO
 
********************************************************

### Como funciona cada função de manipulação:  
  
  
##### ROTACAO DE IMAGEM HORARIA E ANTIHORARIA:  
As funcoes recebem a imagem e a reescreve de maneira que
a linha passa a ser coluna e a coluna passa a ser linha.  

##### ESPELHAMENTO DE IMAGEM HORIZONTAL E VERTICAL:   
A funcao recebe a imagem e atraves de dois FOR as colunas
sao invertidas de maneira que nao altere as linhas isso no
caso do espelhamento horizontal, ja no vertical invertemos
as linhas sem alterar as colunas.

##### ESCALA DE COR CINZA   
A funcao recebe a imagem e com dois FOR acessa pixel a 
pixel tirando uma media dos valores RGB, que sao substituidos
nos valores originais.
o cinza ocorre quando o valor RGB sao iguais.
	
##### ESCALA DE BINARIZAÇAO   
A funcao recebe a imagem e atraves de dois FOR acessa pixel
a pixel gerando uma media do RGB da imagem,se a media for
menor ou igual a 127 o valor do RGB  passa a ser zero,
caso o valor seja maior a 127 os valores do RGB passa
a ser 255. Gerando assim somente o preto e o branco na imagem

##### ALTO CONTRASTE
A funcao recebe a imagem e atraves de dois FOR acessa pixel
a pixel gerando uma media do RGB da imagem,se a media for
menor ou igual a 127 o valor do RGB  passa a ser zero,
caso o valor seja maior a 127 os valores do RGB passa
a ser 255. Gerando assim somente o preto e o branco na imagem

##### ESCALA DE COR PIXELARIZADO   
A funcao recebe a imagem e atraves de dois FOR acessa pixel
a pixel gerando uma media do RGB, essa media calcula os pixel
ao redor do ponto do calculo, depois essa media é sustituida
na matriz principal assim dando o efeito a imagem

##### ESCALA DE COR NEGATIVA
A funcao recebe a imagem e atraves de dois FOR que acessa
pixel a pixel.  O  valor RGB  é  subtraido  de 255 e esse
resultado passa ser o RGB da imagem   

##### ESCALA DE COR POSTERIZADA
Função lê cada pixel da imagem e o altera o valor para o
seu extremo.

##### ESCALA COM MATRIZ DE CONVOLUCAO

As funcoes responsaveis pela manipulacao das matriz por convolucao,
recebem a imagem e a multiplica pixel a pixel por uma matriz determinada
pela própia funcao.

-------------------------------------------------------
	FILTROS         |     MATRIZ A QUAL O PIXEL É MULTIPLICADO
-------------------------------------------------------
                        |
                        |		| 0 -1  0|
    EMBOSS              |		| 0  0  0| + MAX/2
    (ALTO RELEVO)       |		| 0  1  0|
                        |		MAX = numeromaximo de pixels
-------------------------------------------------------
                        |
                        |		| 0 -1  0|
    SHARPENING          |		|-1  5 -1|
                        |		| 0 -1  0|
                        |
-------------------------------------------------------
                        |
                        |		|1  1  1 |
    BLURRING            |		|1  1  1 | x 1/9
                        |		|1  1  1 |
                        |
-------------------------------------------------------
                        |
    DETECTOR            |		|-1 -1 -1|
    DE                  |		|-1  8 -1|
    BORDAS              |		|-1 -1 -1|
                        |
-------------------------------------------------------             
			|
                        |	NESSA FUNCAO, OS VALORES
    USUARIO             |   	DA MATRIZ DE CONVOLUCAO SAO
    		        |	DETERMINADOS PELO USUARIO	
                        |		
------------------------------------------------------- 
