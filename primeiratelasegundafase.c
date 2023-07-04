	#include <stdio.h> //biblioteca	 de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação espaço em memória
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h >//biblioteca reponsavel por cuidar de string

int registro()//função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da criação de variáveis
	printf("Digite o CPF a ser cadastrado: ");//coletando informações dos usuários
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string
	FILE* file;
	
	file = fopen(arquivo, "w"); //cria o arquivo e ja escreve "W" Write (escrever)
	fprintf(file,cpf); //salva o valor do arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//atualiza o valor da string/variavel do arquivo ja criado "a" atualizar
	fprintf(file," Nome:");//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser Cadastrado: ");//coletando informações do usuário
	scanf("%s",nome);//salva o valor da variavel/string
	
	file = fopen(arquivo, "a");//atualiza o valor da sring/variavel do arquivo ja criado
	fprintf(file,nome);//salva o valor arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//atualiza o valor do arquivo da string/variavel do arquivo ja criado
	fprintf(file," Sobrenome:");//salva o valor do arquivo
	fclose(file);//fecha o valor do arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informações do usuário
	scanf("%s",sobrenome);//salva o valor da variavel/string
	
	file = fopen(arquivo, "a");//atualiza o valor do arquivo da string/variavel do arquivo ja criado
	fprintf(file,sobrenome);//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen (arquivo, "a");//atualiza o valor do arquivo da string/variavel do arquivo ja criado
	fprintf(file," Cargo:");//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informações do usuário
	scanf("%s",cargo);//salva o valor da variavel/string
	
	file = fopen(arquivo, "a");//atualiza o valor da variavel/string do arquivo ja criado
	fprintf(file,cargo);//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen (arquivo, "a");//atualiza o valor da string/variavel do arquivo ja criado
	fprintf(file,".");//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	system ("pause");//pausa o sistema
}

int consulta()//função responsável por consultar os usuários no sistema
{	
	setlocale (LC_ALL, "portuguese"); //definindo a linguagem
	
	char cpf[40];//Adicionando as variáveis
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");//coletando informções do usuário
	scanf ("%s", cpf);//salvando o valor da string/variavel
	
	FILE  *file;
	file =fopen(cpf,"r");//Ler o valor da string/variavel do arquivo ja criado "r" read (ler)
	
	if(file == NULL)//Análise em caso de arquivo inexistente
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");//informando o usuário
	}
	
	while (fgets(conteudo, 200,file) != NULL);//analise de arquivo existente "W" while
	printf ("Essas são as informações do usuário: ");//Exibindo informação de consulta
	printf ("%s", conteudo);//salvando o Valor da variável/string
	printf("\n\n");
	fclose(file);//fechando o arquivo
	
	system ("pause");
	//pausando o sistema
}

int deletar()//função responsável por deletar os usuários do sistema
{
	char cpf[40];//adicionando variável
	
	printf("Digite o CPF do usuário a ser deletado: ");//coletando informações do usuário
	scanf("%s",cpf);//salvando o valor da variavel/string
	
	remove(cpf);//adcionando a fução de remoção
	
	FILE *file;
	file = fopen(cpf,"r");//Ler o valor da string/variavel do arquivo ja criado "r" read (ler)
	fclose(file);//fechando o arquivo
	
	if(file == NULL)//analise em caso de arquivo inexistente
	{
		printf ("o usuário não se encontra no sistema!.\n");
		system ("pause");
	}
	
	if (file != NULL)//tentativa de analise de arquivo existente
	{
		printf("o CPF do usuário foi deletado com sucesso!\n");
		system ("pause");
	}
	//pausando o sistema
}
int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");//responsável por limpar a tela
		
		setlocale (LC_ALL, "portuguese"); //definindo a linguagem
	
	
		printf ("*** Primeira Tela :D ***\n\n"); //inicio do menu
		printf ("Opções de Menu\n\n");
		printf ("\t1 Registrar Nomes\n");
		printf ("\t2 Consultar Nome\n");
		printf ("\t3 Deletar Nomes\n\n");
		printf("\t4 Sair do Sistema \n\n");
		printf ("Opção: ");//fim do menu
		
		scanf ("%d", &opcao);//armazenando a escolha do usuario
	
		system ("cls");//reponsavel por limpar a tela
		
		switch (opcao)//inicio da seleção do menu
		{
			//chamada de funcões
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
			printf("Essa opção não está disponível!\n");
			system ("pause");
			break;
		}//fim da  seleção do menu
		}
	}	
