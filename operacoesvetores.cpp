#include <stdio.h>
#define TF 5
#define TFU 10

void leitura(int vetor[TF]){
	// leitura de valores inseridos pelo usuario
	int i;
	for (i=0; i<TF; i++)
	{
		printf("\nEntre com valor da posicao %d = ", i);
		scanf("%d", &vetor[i]);
	}
}

void exibe(int vetor[TF]){
	// exibicao de valores do vetor
	int i;
	for (i=0; i<TF; i++)
		printf("\nVetor[%d] = %d", i, vetor[i]);
}

void exibeU(int vetor[TFU]){
	// exibicao de valores do vetor uniao
	int i;
	for (i=0; i<TFU; i++)
		printf("\nVetor[%d] = %d", i, vetor[i]);
}

int busca(int vetor[TF], int numero){
	// busca numero no vetor e retorna posicao
	int posicao = -1;
	int i;
	for (i=0; i<TF; i++)
	{
		if (numero == vetor[i])
			posicao = i;
	}
	return posicao;
}

void intersecao(int vetA[TF], int vetB[TF]){
	// imprimi interseccao dos vetores A e B
	printf("\nIntersecao dos vetores A e B");
	int numero, posicao;
	int tl = 0;
	for (int i=0; i<TF; i++)
	{
		numero = vetA[i];
		posicao = busca(vetB, numero);
		if (posicao != -1)
		{			
		printf("\nEncontrei o numero %d no vetor B", numero);
		tl++;
		}
	}
	printf("\nQtdade de numeros da interseccao = %d", tl);
}

void uniao(int vetA[TF], int vetB[TF], int vetU[TFU]){
	// cria vetU com uniao sem repeticao de vetA e vetB e imprimi numeros
	printf("\nUniao dos vetores A e B");
	
	int pular = 0;
	
	for (int i=0; i<TF; i++){
		// se numero de vetA no vetU, não adiciona de novo
		int numero = vetA[i];
		int posicao = busca(vetU, numero);
		if (posicao == -1) {
			vetU[i - pular] = vetA[i];
		}
		else {
			vetU[i + TF] = 0;
			pular++;
		}
	}
	
	for (int i=0; i<TF; i++){
		// se numero de vetB no vetU, não adiciona de novo
		int numero = vetB[i];
		int posicao = busca(vetU, numero);
		if (posicao == -1) {
			vetU[i + TF - pular] = vetB[i];
		}
		else {
			vetU[i + TF] = 0;
			pular++;
		}
	}
}

main()
{
	// declarao de variaveis
	int opcao = 0;
	int vetA[TF], vetB[TF], vetC[TF], vetU[TF];
	int tl = 0;
	
	// reseta vetU
	for (int i=0; i<TFU; i++){
		vetU[i] = 0;
	}
	
	// menu de opcoes
	while (opcao != 7)
	{
		printf("\n1 - Leitura do vetor A");
		printf("\n2 - Exibe o vetor A");
		printf("\n3 - Leitura do vetor B");
		printf("\n4 - Exibe o vetor B");
		printf("\n5 - Interseccao dos vetores - Vetor C");
		printf("\n6 - Uniao SEM repeticao");
		printf("\n7 - Sair");
		printf("\nSelecione opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao)
		{
		case 1:
			printf("\nLeitura do Vetor A");
			leitura(vetA);
			break;
		case 3:
			printf("\nLeitura do Vetor B");
			leitura(vetB);
			break;
		case 2:
			printf("\nExibe o vetor A");
			exibe(vetA);
			break;
		case 4:
			printf("\nExibe o vetor B");
			exibe(vetB);
			break;
		case 5:
			intersecao(vetA, vetB);
			break;
		case 6:
			uniao(vetA, vetB, vetU);
			exibeU(vetU);
			break;
		}
	}
}
