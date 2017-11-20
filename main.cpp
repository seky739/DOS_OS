#include <stdio.h>
#include <malloc.h>
#include "Opcodes.h"
#include "Opfunction.h"
#include "Registers.h"
#include "CPU_info.h"

int main(int argc, char **argv) {

    bit8 *pamet;
    char c;
    Registr r;

    pamet=(bit8*)malloc(SEGMENT_SIZE * sizeof(bit8));

    if (argc<=1){
        printf("%s","Nebyl zadan platny soubor \n");
    }
    else{
        FILE *f = fopen(argv[1], "r");
        int i=0;
        while ((c = fgetc(f)) != EOF)
        {
            pamet[i++] = (bit8) c;
            printf("%c",c);
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
            case MOVEAX:
                printf("%s","MOVEAX");
                break;
            case MOVEBX:
                printf("%s","MOVEBX");
                break;
            case MOVEDX:
                printf("%s","MOVEDX");
                break;
            case MOVESI:
                printf("%s","MOVSI");
                break;
            case MOVE8C:
                printf("%s","MOVE8C");
                break;
            case MOVE8E:
                printf("%s","MOVE8E");
                break;
            case XOR:
                printf("%s","XOR");
                break;
            case JMP:
                printf("%s","JMP");
                break;
            case INC:
                printf("%s","INC");
                break;
            case ADD:
                printf("%s","ADD");
                break;
            case MOVE8A:
                printf("%s","MOVE8A");
                break;
            case INCEBX:
                printf("%s","INCEBX");
                break;
            case INCEDX:
                printf("%s","INCEDX");
                break;
            case DECECX:
                printf("%s","DECECX");
                break;
            case MOVEAH:
                printf("%s","MOVEAH");
                break;
            case ADDADDR:
                printf("%s","ADDADR");
                break;
            case CMP:
                printf("%s","CMP");
                break;
            case JNE:
                printf("%s","JNE");
                break;
            case MOVEDI:
                printf("%s","MOVEDI");
                break;
            case MOVEC7:
                printf("%s","MOVEC7");
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