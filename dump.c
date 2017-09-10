#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
void main(int args,char * params[]){
	FILE * rFile;
	size_t nbytes,rbytes;
	char * Memory;
	long pointer=0;
	int c_principal=0,c_principal2=0,aux=0,aux1=0,hex=0,v_ascii=0;
	if(args <= 1){
		printf("[F] Digite o nome de arquivo como paramentro Ex: .\\dump meu_arquivo.bin \n");
		return;
	}
	rFile = fopen(params[1],"rb");
	if(rFile == NULL){
		printf("[F] Nao foi encontrado ou falha de permissao no arquivo \n");
		return;
	}else{
		fseek(rFile,0,SEEK_END);
		nbytes = ftell(rFile);
		rewind(rFile);
		Memory = (char*)malloc(nbytes+16);
		memset(Memory,0,nbytes+16);
		//printf("[Ok] Arquivo inicializado com sucesso \n");
	}
	rbytes = fread(Memory,1,nbytes,rFile);
	if(rbytes  < 0){
		printf("[F] Nao foi possivel ler os bytes do arquivo \n");
		return;
	}
	printf("\n Offset   ");
	for(hex=0;hex <=15;hex++){
		printf("%.2X  ",(uint8_t)hex);
	}
	for(hex=0;hex <=15;hex++){
		printf("%.1x",(uint8_t)hex);
	}
	printf("\n");
	for(aux=0;aux <= rbytes/16;aux++){
		printf("%.8X: ",pointer);
		for(aux1=0;aux1 <= 15;aux1++){
			printf("%0.2X",(uint8_t)Memory[c_principal]);
			printf("  ");
			c_principal++;
		}
		for(aux1=0;aux1 <= 15;aux1++){
			for(v_ascii=Memory[c_principal2];v_ascii <= 32;v_ascii++){
				Memory[c_principal2] = 0x2E;
			}
			printf("%c",(uint8_t)Memory[c_principal2]);
			c_principal2++;
			if(c_principal2 == rbytes){
				break;
			}
		}
		pointer = pointer+16;
		printf("\n");
	}
}