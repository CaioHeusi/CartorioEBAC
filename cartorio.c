#include <stdio.h> //biblioteca de comunaca��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rioos no sistema
{
	// in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" � a fun��o escrever
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e usa "a" fun��o de anexar novos dados
	fprintf(file,","); //adiciona v�rgula para separar os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s", nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //pausa o sistema a fim do usu�rio ter tempo de entender
}

int consulta() // Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" � a fun��o ler
	
	if(file == NULL) //If cria uma condi��o, no caso, relata se o CPF do usu�rio existe
	{
		printf("N�o foi poss�vel localizar o CPF.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // L� e imprime na tela as linhas, com estrutura de repeti��o while
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() // Fun��o respons�vel por deletar os usu�rios do sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" fun��o ler
	fclose(file);
	
	if(file == NULL) //Condi��o se o CPF existe ou n�o para ser deletado
	{
		printf("O CPF do usu�rio n�o se encontra no sistema.\n\n"); //Retorna o erro para o usu�rio
	}
	else //Usada para especificar um bloco de c�digo que deve ser executado se a condi��o associada ao if n�o for verdadeira.
	{
		remove(cpf);
		printf("O CPF do usu�rio foi deletado com sucecsso!\n\n"); //Relata pro usu�rio a a��o tomada ao deletar
	}
	system("pause");
}

int main() //Fun��o principal, ponto de entrada do programa
	{
	int opcao=0; // Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Fun��o para limpar a tela do programa
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opcao: "); //fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); // respons�vel por limpar a tela
		
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
			
		}
	
	}
}
