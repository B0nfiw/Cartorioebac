#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //função responsavel por cadastrar usuario no  sistema
{
	//ínicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do user
	scanf("%s", cpf); //%s refere-se à strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo - e o "w" siginifica escrever
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquico
	fprintf(file, ","); //separa as informações por uma vígula ","
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //escrita que irá ser transmitida
	scanf("%s", nome); 
	
	file = fopen (arquivo, "a");//abre o arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ",");//coloca uma "," para separar
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //escrita que será transmitida 
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, sobrenome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //escrita que será transmitida
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, cargo);
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a tela
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguegem

	
	char cpf[40]; //"[40]" - quantidade maxima de caracteres permitidas
	char conteudo[200]; //"[200]" - quantidade maxima de caracteres permitidas
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s,", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Será aberto o arquivo com as informações do cpf a ser consultado
	
	if(file == NULL) //Caso não exista é utulizado o "NULL", e logo será apresentado o seguinte printf:
	{
		printf("Não foi possíve abrir o arquivo, Arquivo não localizado! \n");		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf); //Consulta do cpf que será deletado
	
	remove(cpf); //cpf será removido
	
	FILE *file;
	file = fopen(cpf, "r"); 
	
	if (file == NULL)
	{
		printf("Usuário não se encontra no sistema! \n");
		system("pause"); //Caso não exista a mensagem do printf acima será mostrado
	}
	
	
}


int main()
    {
	int opcao=0; //Definindo as variáveis
	int x=1;
	
	for(x=1;x=1;)
    
	{
	
		system("cls"); //responsavel por limpar a tela
		
	 	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguegem
	
		printf("### Cartório da EBAC ###\n\n"); //Ínicio do Menu
	 	printf("Escolher a opção desejada do menu:\n\n");
	 	printf("\t1 - Registrar nomes\n");
	 	printf("\t2 - Consultar nomes\n");
	 	printf("\t3 - Deletar nomes\n"); //Fim do Menu
	 	printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
	
	 	scanf("%d", &opcao); //Armazenando a escolha do úsuario
	
	 	system("cls");
	
		    switch(opcao)
	    {
	    	case 1:
	    		registro(); //chamada de funções
		        break;
		        
		    case 2:
		    	consulta(); //chamada de funções com inserção de cpf para saber suas informações
		        break;
		        
		    case 3:
		    	deletar(); //função de deletar
		        break;
		        
		    case 4:
		    printf("Obrigado por utlizar o sistema!\n");
		    return 0;
		    break;
		    
		    default:
		    	printf("Opção não disponível!\n");
		        system("pause");
		        break;
	
			}
		}

	}
	
	

    
	
	
    