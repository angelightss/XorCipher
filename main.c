#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int XorCipher(char chave[], char texto[200]){
    int textolen;
    textolen = strlen(texto);
    int chavelen = strlen(chave);
    char *output = (char *) malloc(sizeof(char) * textolen);
    FILE *xorcipher = fopen("xorcipher.txt", "w+");
    if (xorcipher == NULL) {
        printf("Erro ao abrir arquivo!");
    } else {
        for (int i = 0; i < strlen(texto); i++) {
            output[i] = texto[i] ^ chave[i % chavelen];
        }
        fputs(output, xorcipher);
    }
    fclose(xorcipher);
    free (output);
}

int Criptografar(char chave[]) {
    char texto[200];
    printf("Digite o texto para criptografar: \n=> ");
    scanf("\n%[^\n]s", texto);
    XorCipher(chave, texto);
}

int Descriptografar(char chave[]){
    char texto[200];
    printf("Digite o texto para descriptografar: \n=> ");
    scanf("\n%[^\n]s", texto);
    XorCipher(chave, texto);
}

int main(void)
{
    int opcao = 0;
    do
    {
        printf("----------Criptografia e Descriptografia XOR----------\n"
               "Selecione a opcao desejada:\n "
               "1 - Criptografar\n "
               "2 - Descriptografar\n "
               "3 - Sair\n"
               "------------------------------------------------------\n"
               "=> ");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                Criptografar("1234");
                break;
            case 2:
                Descriptografar("1234");
                break;
            case 3:
                continue;
                break;
            default:
                printf("\nOpção invalida! Digite novamente.\n");
        }
    }while(opcao != 3);
    return 0;
}

