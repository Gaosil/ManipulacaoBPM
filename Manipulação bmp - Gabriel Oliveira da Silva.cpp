#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void informacoes(int *altura,int *largura,FILE *abrir,char imagem[])
{
	struct cabe
	{
		unsigned char tipo[2];
		unsigned long tam;
		unsigned char reserv[4];
		unsigned long desloc;
		unsigned long tamcab;
		unsigned long larg;
		unsigned long alt;
		short int biplanes;
		short int profundidade;
	}img;
	if((abrir=fopen(imagem,"r+b")) !=NULL) //Teste de abertura da imagem
	{
		fread(img.tipo,sizeof(char),2,abrir); 
		if(img.tipo[0]=='B'&&img.tipo[1]=='M') 
		{
        fread(&img.tam,sizeof(unsigned long),1,abrir); //Coletando os arquivos da imagem para o cabeçalho
        fread(img.reserv,sizeof(unsigned char),4,abrir);
        fread(&img.desloc,sizeof(unsigned long),1,abrir);
        fread(&img.tamcab,sizeof(unsigned long),1,abrir);
        fread(&img.larg,sizeof(unsigned long),1,abrir);
        fread(&img.alt,sizeof(unsigned long),1,abrir);
        fread(&img.biplanes,sizeof(short int),1,abrir);
        fread(&img.profundidade,sizeof(short int),1,abrir);
        printf("Tamanho da imagem selecionada: %d bytes de largura por %d bytes de altura\n\nProfundidade de cores:%d\n",img.larg,img.alt,img.profundidade);
        fclose(abrir);
        *altura=img.alt; //Atribuindo altura e largura em variáveis
        *largura=img.larg;
    }
    else{
    printf("A imagem selecionada nao se encontra no formato de bitmap\n");
    system("Pause");
    exit(0);
    }
}
	else
	{
	printf("Erro ao abrir a imagem\n");
	system("Pause");
	exit(0);
}
}
int azull(int altura, int largura, FILE *abrir, FILE *azul, unsigned char abrindo[], char cab[],char imagem[])
{
	char nome[100];
	int escolha1;
	for(int go=0;go<(strlen(imagem)-4);go++) 
	{
	nome[go]=imagem[go];
}
    nome[strlen(imagem)-4]='_';
    nome[strlen(imagem)-3]='B';
    nome[strlen(imagem)-2]='.';
    nome[strlen(imagem)-1]='b';
    nome[strlen(imagem)]='m';
    nome[strlen(imagem)+1]='p';
    nome[strlen(imagem)+2]='\0';
	if((abrir = fopen(imagem,"r+b"))!=NULL);
	{
        fread(cab,1,54,abrir); //Leitura de cabeçalho
        fseek(abrir,54,SEEK_SET);
        for(int alt=0;alt<altura;alt++)
            for(int larg=0;larg<(3*(largura+1));larg++)
            {
                abrindo[larg+(3*(largura+1)*alt)]=getc(abrir); //Pega os valores da imagem original
            }
            fclose(abrir);
        }
    azul=fopen(nome,"w+b");
    fwrite(cab,1,54,azul);
    fseek(abrir,54,SEEK_SET);
                for(int alt=0;alt<altura;alt++){
                    for(int larg=0; larg<(3*(largura+1)); larg++){
                    	if(larg==0||larg%3==0)
                        fputc(abrindo[larg + (3*(largura+1)*alt)],azul);
                        else
                        fputc(0,azul);
                }
        }
        fclose(azul);
        printf("Arquivo criado!\n Deseja voltar ao menu?\n[1]. Sim\n[0]. Nao\n");
				scanf("%d",&escolha1);
				return escolha1;
}
int verdee(int altura, int largura, FILE *abrir, FILE *verde, unsigned char abrindo[], char cab[],char imagem[])
{
	int i=0;
	char nome[100];
	int escolha1;
	for(int go=0;go<(strlen(imagem)-4);go++)
	{
	nome[go]=imagem[go];
}
    nome[strlen(imagem)-4]='_';
    nome[strlen(imagem)-3]='G';
    nome[strlen(imagem)-2]='.';
    nome[strlen(imagem)-1]='b';
    nome[strlen(imagem)]='m';
    nome[strlen(imagem)+1]='p';
    nome[strlen(imagem)+2]='\0';
	if((abrir = fopen(imagem,"r+b"))!=NULL);
	{
        fread(cab,1,54,abrir);
        fseek(abrir,54,SEEK_SET);
        for(int alt=0;alt<altura;alt++)
            for(int larg=0;larg<(3*(largura+1));larg++)
            {
                abrindo[larg+(3*(largura+1)*alt)]=getc(abrir);
            }
            fclose(abrir);
        }
    verde=fopen(nome,"w+b");
    fwrite(cab,1,54,verde);
    fseek(abrir,54,SEEK_SET);
                for(int alt=0;alt<altura;alt++){
                    for(int larg=0; larg<(3*(largura+1)); larg++){ //Ele vai incrementendo 1 a uma variavel
                    	if(i==0)                                 
                    	{
                    	fputc(0,verde);
                    	i++;
                    }
                    else
                    if(i==1)
                    {
                    	fputc(abrindo[larg + (3*(largura+1)*alt)],verde);
                    	i++;
					}
					else
					if(i==2)
					{
						fputc(0,verde);
						i=0;
					}
                    	
					}
                }
				fclose(verde);
				printf("Arquivo criado!\n Deseja voltar ao menu?\n 1. Sim\n 0. Nao\n");
				scanf("%d",&escolha1);
				return escolha1;
        }
        
int vermelhoo(int altura, int largura, FILE *abrir, FILE *vermelho, unsigned char abrindo[], char cab[],char imagem[])
{
	int i=0;
	char nome[100];
	int escolha1;
	for(int go=0;go<(strlen(imagem)-4);go++)
	{
	nome[go]=imagem[go];
}
    nome[strlen(imagem)-4]='_';
    nome[strlen(imagem)-3]='R';
    nome[strlen(imagem)-2]='.';
    nome[strlen(imagem)-1]='b';
    nome[strlen(imagem)]='m';
    nome[strlen(imagem)+1]='p';
    nome[strlen(imagem)+2]='\0';
	if((abrir = fopen(imagem,"r+b"))!=NULL);
	{
        fread(cab,1,54,abrir);
        fseek(abrir,54,SEEK_SET);
        for(int alt=0;alt<altura;alt++)
            for(int larg=0;larg<(3*(largura+1));larg++)
            {
                abrindo[larg+(3*(largura+1)*alt)]=getc(abrir);
            }
            fclose(abrir);
        }
    vermelho=fopen(nome,"w+b");
    fwrite(cab,1,54,vermelho);
    fseek(abrir,54,SEEK_SET);
                for(int alt=0;alt<altura;alt++){
                    for(int larg=0; larg<(3*(largura+1)); larg++){
                    	if(i==0)
                    	{
                    	fputc(0,vermelho);
                    	i++;
                    }
                    else
                    if(i==1)
                    {
					    fputc(0,vermelho);
                    	
                    	i++;
					}
					else
					if(i==2)
					{
						fputc(abrindo[larg + (3*(largura+1)*alt)],vermelho);
						i=0;
					}
                }
        }
        fclose(vermelho);
        printf("Arquivo criado!\n Deseja voltar ao menu?\n 1. Sim\n 0. Nao\n");
				scanf("%d",&escolha1);
				return escolha1;
}
int cinzaa(int altura, int largura, FILE *abrir, FILE *cinza, unsigned char abrindo[], char cab[],char imagem[])
{
	float media=0;
	int i=0;
	char nome[100];
	int escolha1;
	for(int go=0;go<(strlen(imagem)-4);go++)
	{
	nome[go]=imagem[go];
}
    nome[strlen(imagem)-4]='_';
    nome[strlen(imagem)-3]='g';
    nome[strlen(imagem)-2]='s';
    nome[strlen(imagem)-1]='.';
    nome[strlen(imagem)]='b';
    nome[strlen(imagem)+1]='m';
    nome[strlen(imagem)+2]='p';
    nome[strlen(imagem)+3]='\0';
	if((abrir = fopen(imagem,"r+b"))!=NULL);
	{
        fread(cab,1,54,abrir);
        fseek(abrir,54,SEEK_SET);
        for(int alt=0;alt<altura;alt++)
            for(int larg=0;larg<(3*(largura+1));larg++)
            {
                abrindo[larg+(3*(largura+1)*alt)]=getc(abrir);
            }
            fclose(abrir);
        }
    cinza=fopen(nome,"w+b");
    fwrite(cab,1,54,cinza);
    fseek(abrir,54,SEEK_SET);
                for(int alt=0;alt<altura;alt++){
                    for(int larg=0; larg<(3*(largura+1)); larg+=3){ //Faz a media dos 3 bytes do pixel e coloca em cada um o valor resultante
                    	media=(abrindo[larg+(3*(largura+1)*alt)] + abrindo[larg+1+(3*(largura+1)*alt)] + abrindo[larg+2+(3*(largura+1)*alt)])/3;
                    	fputc(media,cinza);
                    	fputc(media,cinza);
                    	fputc(media,cinza);
                    	media=0;
					}
                }
				fclose(cinza);
				 printf("Arquivo criado!\n Deseja voltar ao menu?\n 1. Sim\n 0. Nao\n");
				scanf("%d",&escolha1);
				return escolha1;
        }
        int contornoo(int altura, int largura, FILE *abrir, FILE *contorno, unsigned char abrindo[], char cab[],char imagem[])
{
	int i=0, cor, escolha1;
	char nome[100];
	for(int go=0;go<(strlen(imagem)-4);go++)
	{
	nome[go]=imagem[go];
}
    nome[strlen(imagem)-4]='_';
    nome[strlen(imagem)-3]='a';
    nome[strlen(imagem)-2]='c';
    nome[strlen(imagem)-1]='h';
    nome[strlen(imagem)]='e';
    nome[strlen(imagem)+1]='i';
    nome[strlen(imagem)+2]='.';
    nome[strlen(imagem)+3]='b';
    nome[strlen(imagem)+4]='m';
    nome[strlen(imagem)+5]='p';
    nome[strlen(imagem)+6]='\0';
	if((abrir = fopen(imagem,"r+b"))!=NULL);
	{
	printf("\nDeseja contornar qual das cores da imagem?\n 1. Vermelho\n 2. Verde\n 3. Azul\n");
    scanf("%d", &cor);
        fread(cab,1,54,abrir);
        fseek(abrir,54,SEEK_SET);
        for(int alt=0;alt<altura;alt++)
            for(int larg=0;larg<(3*(largura+1));larg++)
            {
                abrindo[larg+(3*(largura+1)*alt)]=getc(abrir);
            }
            fclose(abrir);
        
                for(int alt=0;alt<altura;alt++){
                    for(int larg=0; larg<(3*(largura+1)); larg+=3){ //Para cada cor ele testa 3 pixeis nas dimensões de cima, baixo, direita e esquerda
                    	if(cor==1){  //Testa primeiro se o pixel que ele ta e o próximo são brancos e o seguinte é da cor escolhida pelo usuario
                    		if(abrindo[larg+(3*(largura+1)*alt)]!=0&&abrindo[larg+1+(3*(largura+1)*alt)]!=0&&abrindo[larg+2+(3*(largura+1)*alt)]!=0&&abrindo[larg+3+(3*(largura+1)*alt)]!=0&&abrindo[larg+4+(3*(largura+1)*alt)]!=0&&abrindo[larg+5+(3*(largura+1)*alt)]!=0&&abrindo[larg+6+(3*(largura+1)*alt)]==0&&abrindo[larg+7+(3*(largura+1)*alt)]==0&&abrindo[larg+8+(3*(largura+1)*alt)]!=0)
                    		{ //Se for ele coloca a cor preta nos dois pixeis brancos testados
                    			abrindo[larg+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+1+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+2+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+3+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+4+(3*(largura+1)*alt)]=0;
								abrindo[larg+5+(3*(largura+1)*alt)]=0;
							} //Depois ele testa se o pixel que ele ta é da cor pedida pelo user e se os dois próximos são brancos
							if(abrindo[larg+(3*(largura+1)*alt)]==0&&abrindo[larg+1+(3*(largura+1)*alt)]==0&&abrindo[larg+2+(3*(largura+1)*alt)]!=0&&abrindo[larg+3+(3*(largura+1)*alt)]!=0&&abrindo[larg+4+(3*(largura+1)*alt)]!=0&&abrindo[larg+5+(3*(largura+1)*alt)]!=0&&abrindo[larg+6+(3*(largura+1)*alt)]!=0&&abrindo[larg+7+(3*(largura+1)*alt)]!=0&&abrindo[larg+8+(3*(largura+1)*alt)]!=0)
                    		{ //Se for ele pinta os dois pixeis brancos testados
                    			abrindo[larg+3+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+4+(3*(largura+1)*alt)]=0;
								abrindo[larg+5+(3*(largura+1)*alt)]=0;
								abrindo[larg+6+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+7+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+8+(3*(largura+1)*alt)]=0;
						} //Após isso ele testa se o pixel que ele ta e o acima dele são brancos e se o acima deles é da cor escolhida pelo usuario
							if(abrindo[larg+(3*(largura+1)*alt)]!=0&&abrindo[larg+1+(3*(largura+1)*alt)]!=0&&abrindo[larg+2+(3*(largura+1)*alt)]!=0&&abrindo[larg+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+1+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+2+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+(3*(largura+1)*(alt+2))]==0&&abrindo[larg+1+(3*(largura+1)*(alt+2))]==0&&abrindo[larg+2+(3*(largura+1)*(alt+2))]!=0)
                    		{ //Se for os dois pixeis brancos são pintados de preto
                    			abrindo[larg+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+1+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+2+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+(3*(largura+1)*(alt+1))]=0;
                    			abrindo[larg+1+(3*(largura+1)*(alt+1))]=0;
								abrindo[larg+2+(3*(largura+1)*(alt+1))]=0;
							} //Então ele testa se o que ele ta é da cor escolhida pelo usuario e se os dois abaixo dele são brancos
							if(abrindo[larg+(3*(largura+1)*alt)]==0&&abrindo[larg+1+(3*(largura+1)*alt)]==0&&abrindo[larg+2+(3*(largura+1)*alt)]!=0&&abrindo[larg+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+1+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+2+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+(3*(largura+1)*(alt+2))]!=0&&abrindo[larg+1+(3*(largura+1)*(alt+2))]!=0&&abrindo[larg+2+(3*(largura+1)*(alt+2))]!=0)
                    		{ //Se for ele pinta os dois pixeis brancos testados de branco
                    			abrindo[larg+(3*(largura+1)*(alt+2))]=0;
                    			abrindo[larg+1+(3*(largura+1)*(alt+2))]=0;
                    			abrindo[larg+2+(3*(largura+1)*(alt+2))]=0;
                    			abrindo[larg+(3*(largura+1)*(alt+1))]=0;
                    			abrindo[larg+1+(3*(largura+1)*(alt+1))]=0;
								abrindo[larg+2+(3*(largura+1)*(alt+1))]=0;
							}
						}
						if(cor==2){ 
                    		if(abrindo[larg+(3*(largura+1)*alt)]!=0&&abrindo[larg+1+(3*(largura+1)*alt)]!=0&&abrindo[larg+2+(3*(largura+1)*alt)]!=0&&abrindo[larg+3+(3*(largura+1)*alt)]!=0&&abrindo[larg+4+(3*(largura+1)*alt)]!=0&&abrindo[larg+5+(3*(largura+1)*alt)]!=0&&abrindo[larg+6+(3*(largura+1)*alt)]==0&&abrindo[larg+7+(3*(largura+1)*alt)]!=0&&abrindo[larg+8+(3*(largura+1)*alt)]==0)
                    		{
                    			abrindo[larg+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+1+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+2+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+3+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+4+(3*(largura+1)*alt)]=0;
								abrindo[larg+5+(3*(largura+1)*alt)]=0;
							}
							if(abrindo[larg+(3*(largura+1)*alt)]==0&&abrindo[larg+1+(3*(largura+1)*alt)]!=0&&abrindo[larg+2+(3*(largura+1)*alt)]==0&&abrindo[larg+3+(3*(largura+1)*alt)]!=0&&abrindo[larg+4+(3*(largura+1)*alt)]!=0&&abrindo[larg+5+(3*(largura+1)*alt)]!=0&&abrindo[larg+6+(3*(largura+1)*alt)]!=0&&abrindo[larg+7+(3*(largura+1)*alt)]!=0&&abrindo[larg+8+(3*(largura+1)*alt)]!=0)
                    		{
                    			
                    			abrindo[larg+3+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+4+(3*(largura+1)*alt)]=0;
								abrindo[larg+5+(3*(largura+1)*alt)]=0;
								abrindo[larg+6+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+7+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+8+(3*(largura+1)*alt)]=0;
						}
							if(abrindo[larg+(3*(largura+1)*alt)]!=0&&abrindo[larg+1+(3*(largura+1)*alt)]!=0&&abrindo[larg+2+(3*(largura+1)*alt)]!=0&&abrindo[larg+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+1+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+2+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+(3*(largura+1)*(alt+2))]==0&&abrindo[larg+1+(3*(largura+1)*(alt+2))]!=0&&abrindo[larg+2+(3*(largura+1)*(alt+2))]==0)
                    		{
                    			abrindo[larg+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+1+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+2+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+(3*(largura+1)*(alt+1))]=0;
                    			abrindo[larg+1+(3*(largura+1)*(alt+1))]=0;
								abrindo[larg+2+(3*(largura+1)*(alt+1))]=0;
							}
							if(abrindo[larg+(3*(largura+1)*alt)]==0&&abrindo[larg+1+(3*(largura+1)*alt)]!=0&&abrindo[larg+2+(3*(largura+1)*alt)]==0&&abrindo[larg+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+1+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+2+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+(3*(largura+1)*(alt+2))]!=0&&abrindo[larg+1+(3*(largura+1)*(alt+2))]!=0&&abrindo[larg+2+(3*(largura+1)*(alt+2))]!=0)
                    		{
                    			abrindo[larg+(3*(largura+1)*(alt+2))]=0;
                    			abrindo[larg+1+(3*(largura+1)*(alt+2))]=0;
                    			abrindo[larg+2+(3*(largura+1)*(alt+2))]=0;
                    			abrindo[larg+(3*(largura+1)*(alt+1))]=0;
                    			abrindo[larg+1+(3*(largura+1)*(alt+1))]=0;
								abrindo[larg+2+(3*(largura+1)*(alt+1))]=0;
							}
						}
						if(cor==3){
                    		if(abrindo[larg+(3*(largura+1)*alt)]!=0&&abrindo[larg+1+(3*(largura+1)*alt)]!=0&&abrindo[larg+2+(3*(largura+1)*alt)]!=0&&abrindo[larg+3+(3*(largura+1)*alt)]!=0&&abrindo[larg+4+(3*(largura+1)*alt)]!=0&&abrindo[larg+5+(3*(largura+1)*alt)]!=0&&abrindo[larg+6+(3*(largura+1)*alt)]!=0&&abrindo[larg+7+(3*(largura+1)*alt)]==0&&abrindo[larg+8+(3*(largura+1)*alt)]==0)
                    		{
                    			abrindo[larg+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+1+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+2+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+3+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+4+(3*(largura+1)*alt)]=0;
								abrindo[larg+5+(3*(largura+1)*alt)]=0;
							}
							if(abrindo[larg+(3*(largura+1)*alt)]!=0&&abrindo[larg+1+(3*(largura+1)*alt)]==0&&abrindo[larg+2+(3*(largura+1)*alt)]==0&&abrindo[larg+3+(3*(largura+1)*alt)]!=0&&abrindo[larg+4+(3*(largura+1)*alt)]!=0&&abrindo[larg+5+(3*(largura+1)*alt)]!=0&&abrindo[larg+6+(3*(largura+1)*alt)]!=0&&abrindo[larg+7+(3*(largura+1)*alt)]!=0&&abrindo[larg+8+(3*(largura+1)*alt)]!=0)
                    		{
                    			
                    			abrindo[larg+3+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+4+(3*(largura+1)*alt)]=0;
								abrindo[larg+5+(3*(largura+1)*alt)]=0;
								abrindo[larg+6+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+7+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+8+(3*(largura+1)*alt)]=0;
						}
							if(abrindo[larg+(3*(largura+1)*alt)]!=0&&abrindo[larg+1+(3*(largura+1)*alt)]!=0&&abrindo[larg+2+(3*(largura+1)*alt)]!=0&&abrindo[larg+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+1+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+2+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+(3*(largura+1)*(alt+2))]!=0&&abrindo[larg+1+(3*(largura+1)*(alt+2))]==0&&abrindo[larg+2+(3*(largura+1)*(alt+2))]==0)
                    		{
                    			abrindo[larg+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+1+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+2+(3*(largura+1)*alt)]=0;
                    			abrindo[larg+(3*(largura+1)*(alt+1))]=0;
                    			abrindo[larg+1+(3*(largura+1)*(alt+1))]=0;
								abrindo[larg+2+(3*(largura+1)*(alt+1))]=0;
							}
							if(abrindo[larg+(3*(largura+1)*alt)]!=0&&abrindo[larg+1+(3*(largura+1)*alt)]==0&&abrindo[larg+2+(3*(largura+1)*alt)]==0&&abrindo[larg+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+1+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+2+(3*(largura+1)*(alt+1))]!=0&&abrindo[larg+(3*(largura+1)*(alt+2))]!=0&&abrindo[larg+1+(3*(largura+1)*(alt+2))]!=0&&abrindo[larg+2+(3*(largura+1)*(alt+2))]!=0)
                    		{
                    			abrindo[larg+(3*(largura+1)*(alt+2))]=0;
                    			abrindo[larg+1+(3*(largura+1)*(alt+2))]=0;
                    			abrindo[larg+2+(3*(largura+1)*(alt+2))]=0;
                    			abrindo[larg+(3*(largura+1)*(alt+1))]=0;
                    			abrindo[larg+1+(3*(largura+1)*(alt+1))]=0;
								abrindo[larg+2+(3*(largura+1)*(alt+1))]=0;
							}
						}
                }
        }
	contorno=fopen(nome,"w+b");
    fwrite(cab,1,54,contorno);
    fseek(abrir,54,SEEK_SET);
        for(int alt=0;alt<altura;alt++)
                    for(int larg=0; larg<(3*(largura+1)); larg++)
                    	fputc(abrindo[larg+(3*(largura+1)*alt)],contorno);
        fclose(contorno);
        printf("Arquivo criado!\n Deseja voltar ao menu?\n 1. Sim\n 0. Nao\n");
				scanf("%d",&escolha1);
				return escolha1;
    }
}
int escolher()
{
	int escolha;
	printf("\n\n\nVoce deseja:\n1. Gravar arquivo apenas com componentes azuis.\n2. Gravar arquivo apenas com componentes verdes.\n3. Gravar arquivo apenas com componentes vermelhos.\n");
	printf("4. Contornar uma cor da imagem original.\n5. Gravar arquivo em escala de cinza.\n");
	scanf("%d",&escolha);
	return escolha;
}
int main()
{
	FILE *abrir, *azul, *verde, *vermelho, *cinza, *contorno;
	int altura, largura, escolha, escolha1;
	char imagem[100], cab[53];
	printf("Insira aqui o nome da sua imagem bitmap:\n");
	gets(imagem); //Pega o nome da imagem
	do
	{
	system("cls");
	informacoes(&altura,&largura,abrir, imagem);
	unsigned char abrindo[1999999];
	escolha=escolher();
	switch(escolha)
	{
	case 1:
		{
	escolha1=azull(altura,largura,abrir,azul,abrindo,cab,imagem);
	break;
}
    case 2:
	{
	escolha1=verdee(altura,largura,abrir,verde,abrindo,cab,imagem);
	break;
}
    case 3:
	{
	escolha1=vermelhoo(altura,largura,abrir,vermelho,abrindo,cab,imagem);
	break;
}
    case 4:
	{
	escolha1=contornoo(altura,largura,abrir,contorno,abrindo,cab,imagem);
	break;
}
    case 5:
	{
	escolha1=cinzaa(altura,largura,abrir,cinza,abrindo,cab,imagem);
	break;
}
}
}while(escolha1!=0);
}
