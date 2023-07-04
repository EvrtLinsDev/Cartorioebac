	#include <stdio.h> //biblioteca	 de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h >//biblioteca reponsavel por cuidar de string

int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da cria��o de vari�veis
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es dos usu�rios
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
	FILE* file;
	
	file = fopen(arquivo, "w"); //cria o arquivo e ja escreve "W" Write (escrever)
	fprintf(file,cpf); //salva o valor do arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//atualiza o valor da string/variavel do arquivo ja criado "a" atualizar
	fprintf(file," Nome:");//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser Cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s",nome);//salva o valor da variavel/string
	
	file = fopen(arquivo, "a");//atualiza o valor da sring/variavel do arquivo ja criado
	fprintf(file,nome);//salva o valor arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//atualiza o valor do arquivo da string/variavel do arquivo ja criado
	fprintf(file," Sobrenome:");//salva o valor do arquivo
	fclose(file);//fecha o valor do arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s",sobrenome);//salva o valor da variavel/string
	
	file = fopen(arquivo, "a");//atualiza o valor do arquivo da string/variavel do arquivo ja criado
	fprintf(file,sobrenome);//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen (arquivo, "a");//atualiza o valor do arquivo da string/variavel do arquivo ja criado
	fprintf(file," Cargo:");//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s",cargo);//salva o valor da variavel/string
	
	file = fopen(arquivo, "a");//atualiza o valor da variavel/string do arquivo ja criado
	fprintf(file,cargo);//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen (arquivo, "a");//atualiza o valor da string/variavel do arquivo ja criado
	fprintf(file,".");//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	system ("pause");//pausa o sistema
}

int consulta()//fun��o respons�vel por consultar os usu�rios no sistema
{	
	setlocale (LC_ALL, "portuguese"); //definindo a linguagem
	
	char cpf[40];//Adicionando as vari�veis
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");//coletando inform��es do usu�rio
	scanf ("%s", cpf);//salvando o valor da string/variavel
	
	FILE  *file;
	file =fopen(cpf,"r");//Ler o valor da string/variavel do arquivo ja criado "r" read (ler)
	
	if(file == NULL)//An�lise em caso de arquivo inexistente
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");//informando o usu�rio
	}
	
	while (fgets(conteudo, 200,file) != NULL);//analise de arquivo existente "W" while
	printf ("Essas s�o as informa��es do usu�rio: ");//Exibindo informa��o de consulta
	printf ("%s", conteudo);//salvando o Valor da vari�vel/string
	printf("\n\n");
	fclose(file);//fechando o arquivo
	
	system ("pause");
	//pausando o sistema
}

int deletar()//fun��o respons�vel por deletar os usu�rios do sistema
{
	char cpf[40];//adicionando vari�vel
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//coletando informa��es do usu�rio
	scanf("%s",cpf);//salvando o valor da variavel/string
	
	remove(cpf);//adcionando a fu��o de remo��o
	
	FILE *file;
	file = fopen(cpf,"r");//Ler o valor da string/variavel do arquivo ja criado "r" read (ler)
	fclose(file);//fechando o arquivo
	
	if(file == NULL)//analise em caso de arquivo inexistente
	{
		printf ("o usu�rio n�o se encontra no sistema!.\n");
		system ("pause");
	}
	
	if (file != NULL)//tentativa de analise de arquivo existente
	{
		printf("o CPF do usu�rio foi deletado com sucesso!\n");
		system ("pause");
	}
	//pausando o sistema
}
int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");//respons�vel por limpar a tela
		
		setlocale (LC_ALL, "portuguese"); //definindo a linguagem
	
	
		printf ("*** Primeira Tela :D ***\n\n"); //inicio do menu
		printf ("Op��es de Menu\n\n");
		printf ("\t1 Registrar Nomes\n");
		printf ("\t2 Consultar Nome\n");
		printf ("\t3 Deletar Nomes\n\n");
		printf("\t4 Sair do Sistema \n\n");
		printf ("Op��o: ");//fim do menu
		
		scanf ("%d", &opcao);//armazenando a escolha do usuario
	
		system ("cls");//reponsavel por limpar a tela
		
		switch (opcao)//inicio da sele��o do menu
		{
			//chamada de func�es
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;//Quebra tudo e volta pro inicio
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system ("pause");
			break;
		}//fim da  sele��o do menu
		}
	}	
