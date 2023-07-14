#include <stdio.h>  // Biblioteca que enum1porta funcoes in e out
#include <locale.h> //Biblioteca que enum1porta as linguagens

#define SUCESSO 0 // Define Sucesso

void Questao1() {// Roda a questao 1

    //Variaveis inteiras
    int numero1, numero2;

    //pede ao usuario para inserir o valor dos numeros
    printf("Insira os dois valores para a comparação (insira espaços entre os números): \n");
    scanf("%d %d",&numero1, &numero2); // atribui o valor inserido aos numeros

    printf("resultadoado:\n");

    // se o numero 1 for maior que o numero 2, ele enum1ecuto o comando dentro das chaves, se nao passa para a pronum1ima condicional
    if(numero1 > numero2){
        printf("O numero %d é maior que o numero %d", numero1, numero2);
    }
    else if(numero1 == numero2){ //Se o numero 1 for igual ao numero, ele enum1ecuta o comando dentro das chaves, se nao passa para a pronum1ima condicional
        printf("O numero %d é igual ao numero %d", numero1, numero2);
    }
    else{ // Se nao passou por nenhuma condicional, o comando dentro das chaves sera enum1ecutado
        printf("O numero %d é menor que o numero %d", numero1, numero2);
    }

} 

void Questao2() { // Roda a questao 2

    //Variaveis
    int valornum1, valornum2, valorZ;

    //atribui o valor as variaveis
    printf("Insira o valor de num1, num2 e Z\n");
    scanf("%d %d %d", &valornum1, &valornum2, &valorZ);

    /*
    * Se o valor de num1 for menor que a soma dos outros o codigo passa para dentro das chaves, o mesmo se aplica nas outras situacoes 
    * (O operador '&&' significa 'e se' ou também a ja conhecida porta AND)
    */
    if(valornum1 < valornum2 + valorZ && valornum2 < valorZ + valornum1 && valorZ < valornum1 + valornum2) {
        printf("Os valores num1, num2 e Z formam um triangulo!!\n");
    }
    else{ //se nao foi atendido nenhuma das condicoes entao vai ser enum1ecutado o que esta dentro das seguintes chaves
        printf("Os valores num1, num2 e Z não formam um triangulo!!\n");
    }
} 

void Questao3() {// Roda a questao 3

    //Variaveis
    int dia;

    //atribui o valor inserido na variavel dia
    printf("Que dia da semana é hoje:");
    scanf("%d", &dia);

    //Confere o valor inserido em dia
    switch (dia)
    {
    case 1: { //se dia for igual a 1, entra nas chaves
        printf("Domingo");
        break;
    }
    case 2:{ //se dia for igual a 2, entra nas chaves
        printf("Segunda");
        break;
    }
    case 3:{ //se dia for igual a 3, entra nas chaves
        printf("Terça-Feira");
        break;
    }
    case 4:{ //se dia for igual a 4, entra nas chaves
        printf("Quarta-Feira");
        break;
    }
    case 5:{ //se dia for igual a 5, entra nas chaves
        printf("Quinta-Feira");
        break;
    }
    case 6:{ //se dia for igual a 6, entra nas chaves
        printf("Senum1ta-Feira");
        break;
    }
    case 7:{ //se dia for igual a 7, entra nas chaves
        printf("Sábado");
        break;
    }
    default: //se nao entrou em nenhuma das outras opcoes, significa entao que dia eh um valor invalido 
        printf("Dia invalido");
        break;
    }

} 

void Questao4() { // Roda a questao 4

    //Variaveis
    float num1, num2, resultado;
    //valores inteiros necesarios
    int i, numInt1, numInt2, resultadoInt;
    char operacao;

    do{

        printf("\n\n==================================================================================\n\n");
        printf("Defina um valor para o número 1 seguido da operação que será usada e por ultimo o valor de número.\nOperacoes:\nSoma: +\nSubtração: -\nDivisão: /\nMultiplicação: .\nMódulo: %\nExponenciação: *\n(Para sair desta questão digite '0 0 0') \n");
		scanf("%f %c %f", &num1, &operacao, &num2);

		//+ = adição; - = subtração; / = divisão; . = multiplicação; % = módulo; * =exponenciação.
		switch (operacao) {
		   case '+': {//Se a operacao selecionada foi soma:
	          resultado = num1 + num2;
			  printf("O resultado da conta é: %0.2f + %0.2f = %0.2f  \n", num1, num2, resultado);
			  break;
		   }
		   case'-': {//Se a operacao selecionada foi Subtracao:
              resultado = num1 - num2;
              printf("O resultado da conta e: %0.2f - %0.2f = %0.2f  \n", num1, num2, resultado);
			  break;
		   }
		   case'/': { //Se a operacao selecionada foi divisao:
              resultado = num1 / num2;
              printf("O resultado da conta e: %0.2f / %0.2f = %0.2f   \n", num1, num2, resultado);
			  break;
		   }
		   case'.': {//Se a operacao selecionada foi Multiplicacao:
              resultado = num1 * num2;
              printf("O resultado da conta e: %0.2f . %0.2f = %0.2f  \n", num1, num2, resultado);
			  break;
		   }
		   case'%': {//se a operacao selecionada foi modulo:
            
              // A operacao de modulo aceita apenas valores inteiro, por isso convertemos tipo float para inteiro
              numInt1 = num1;
              numInt2 = num2;
            
              resultadoInt = numInt1 % numInt2;
              printf("O resultadoado da conta e: %d resto de %d = %d  \n", numInt1, numInt2, resultadoInt);
			  break;
		   }
		   case'*': {
              //O tipo de exponenciacao sofre o mesmo caso que a operacao de modulo
              numInt1 = num1;
              numInt2 = num2;
            
              resultadoInt = 1;
              for (i = 1; i <= numInt2; i++) {
	            resultadoInt = resultadoInt * numInt1;
              }
              printf("O resultadoado da conta e: %d * %d = %d \n", numInt1, numInt2, resultadoInt);
			  break;
		   }
           case '0': break;
		   default: {
              printf("Conta invalida  \n");
			  break;
		   }
		}

    }while(operacao != '0');// o loop ocorre enquanto a operacao nao for igual a zero

} 

void Questao5() {} // Roda a questao 5

void Questao6() {} // Roda a questao 6

void Questao7() {} // Roda a questao 7

int main(int argc, char **argv)
{

    setlocale(LC_ALL, ""); // atribui a linguagem para o codigo

    int escolha;

    do
    {

        printf("\n\n================================\n");

        // Mostra as opcoes disponiveis
        printf("Escolha uma das opções:\n[1] Questão 1\n[2] Questão 2\n[3] Questão 3\n[4] Questão 4\n[5] Questão 5\n[6] Questão 6\n[7] Questão 7\n[0] Fechar programa\nEscolha:\t");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            break;

        case 1:
        {
            printf("\e[1;1H\e[2J"); //printf que apaga o terminal

            Questao1(); //Chama a questao 1

            break;
        }
        case 2:
        {
            printf("\e[1;1H\e[2J");

            Questao2();

            break;
        }
        case 3:
        {
            printf("\e[1;1H\e[2J");

            Questao3();

            break;
        }
        case 4:
        {
            printf("\e[1;1H\e[2J");

            Questao4();

            break;
        }
        case 5:
        {
            printf("\e[1;1H\e[2J");

            Questao5();

            break;
        }
        case 6:
        {
            printf("\e[1;1H\e[2J");
            Questao6();
            break;
        }
        case 7:
        {
            printf("\e[1;1H\e[2J");

            Questao7();

            break;
        }
        default:
        {
            printf("\e[1;1H\e[2J");
            printf("\nOpÃ§ão invalida!!!\n");
        }
        }

    } while (escolha != 0);

    //apaga o terminal
    printf("\e[1;1H\e[2J");

    //Se chegou ate aqui eh porque deu tudo certo
    return SUCESSO;
}