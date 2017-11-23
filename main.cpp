#include <stdio.h>
//#include <stdlib.h>
#include <malloc.h>
#include "Opcodes.h"
#include "Opfunction.h"
#include "Registers.h"
#include "CPU_info.h"

int main(int argc, char **argv) {

    bit8 *pamet;
    unsigned int i=HEADER_SIZE;
    char c;
    Registr r;

    pamet=(bit8*)malloc(SEGMENT_SIZE * sizeof(bit8));

    if (argc<=1){
        printf("%s","Nebyl zadan platny soubor \n");
    }
    else{
        FILE *f = fopen(argv[1], "r");

        while ((c = fgetc(f)) != EOF)
        {
            pamet[i++] = (bit8) c;

        }
    }

    bit8 instrukce;

    r.ip = HEADER_SIZE;			// nastaveni instruction pointeru na konec hlavicky, tedy na první istrukci samotného kódu
    r.cs = 0;
    r.ds = 0;
    r.es = 0;
    r.ss = 0;
    r.bp = HEADER_SIZE;
    r.sp = SEGMENT_SIZE -2;	// size = 65536


    while (true){
        instrukce = pamet[r.ip];

        if (instrukce == OPSIZE || instrukce == ADSIZE || instrukce == ESPRF)
        {

                printf ("Načítám prefix: %x (%d)\n", instrukce, instrukce);


            r.ip++;
        }else{
        switch (instrukce) {
            case MOVEAX:{
                printf("%s","MOVEAX");
                r.ip+=3;
            }
                break;
            case MOVEBX:{
                printf("%s","MOVEBX");
                r.ip+=3;
            }
                break;
            case MOVEDX:
            {
                printf("%s","MOVEDX");
                r.ip+=3;
            }
                break;
            case MOVESI:
            {
                printf("%s","MOVSI");
                r.ip+=3;
            }
                break;
            case MOVE8C:
            {
                printf("%s","MOVE8C");
                r.ip+=2;
            }
                break;
            case MOVE8E:
            {
                printf("%s","MOVE8E");
                r.ip+=2;
            }
                break;
            case XOR:
            {
                printf("%s","XOR");
                r.ip+=2;
            }
                break;
            case JMP:
            {
                printf("%s","JMP");
                r.ip+=2;
            }
                break;
            case INC:
            {
                printf("%s","INC");
                r.ip+=2;
            }
                break;
            case ADD:
            {
                printf("%s","ADD");
                r.ip+=2;
            }
                break;
            case MOVE8A:
            {
                printf("%s","MOVE8A");
                //zatim neni
            }
                break;
            case INCEBX:
            {
                printf("%s","INCEBX");
                r.ip+=1;
            }
                break;
            case INCEDX:
            {
                printf("%s","INCEDX");
                r.ip+=1;
            }
                break;
            case DECECX:
            {
                printf("%s","DECECX");
                r.ip+=3;
            }
                break;
            case MOVEAH:
            {
                printf("%s","MOVEAH");
                r.ip+=2;
            }
                break;
            case ADDADDR:
            {
                printf("%s","ADDADR");
                r.ip+=2;
            }
                break;
            case CMP:
            {
                printf("%s","CMP");
                r.ip+=3;
            }
                break;
            case JNE:
            {
                printf("%s","JNE");
                r.ip+=2;
            }
                break;
            case MOVEDI:
            {
                printf("%s","MOVEDI");
                r.ip+=3;
            }
                break;
            case MOVEC7:
            {
                printf("%s","MOVEC7");
                r.ip+=6;
            }
                break;
            case INT: 	{								// přerušení je trochu specifické, tak se řeší tady
                r.ip++;
                instrukce = pamet[r.ip];	// cislo preruseni
                //printf("Definované přerušení %d (0x%x)\n", instr, instr);

                if (instrukce == END){printf("%s","Konec programu. \n");return(0);}
            }break;

            }

            printf("%s","\n");
            r.ip++;
        }
        }




  printf("%s","HELLO");
    char znak;
    scanf("%c",&znak);




    return 0;
}