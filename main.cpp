#include <stdio.h>
//#include <stdlib.h>
#include <malloc.h>
#include "Opcodes.h"
#include "Opfunction.h"
#include "Registers.h"
#include "CPU_info.h"

int OpTable[21]={0xB8,0x8C,0x8E,0x33,0xBA,0xBE,0xBB,0xEB,0xFF,0x03,0x8A,0x43,0x42,0x49,0xB4,0x00,0xBF,0xC7,0x7B,0x83,0x75};



int main(int argc, char **argv) {


    int (*handle_fce[])(Registr*,bit8*)= {moveEax, moveC, moveE, xor_instr,moveEdx,moveEsi,moveEbx,jmp,inc,add,moveA
            ,incebx,incedx,dececx,moveah,addaddr,movedi,movec7,jnp,cmp,jne};

    bit8 *pamet;
    int i=HEADER_SIZE;
    char c;
    Registr r;
    int retur;

    pamet=(bit8*)malloc(SEGMENT_SIZE * sizeof(bit8));
    for (int k = 0; k < (SEGMENT_SIZE * sizeof(bit8)); ++k) {
        pamet[k]=(bit8) 0;
    }

    if (argc<=1){
        printf("%s","Nebyl zadan platny soubor \n");
    }
    else{
        FILE *f = fopen(argv[1], "r");

        while (!feof(f)) // Tady jsem testoval EOF ktere se zastavilo po nacteni skoku a pak -1 ktere se tvarilo jako konec souboru
        {
            c = fgetc(f);
            pamet[i++] = (bit8) c;
             printf("%x \n",c);

        }
       /* if(c==-1){
            printf("Tady je -1");
        }
        c=fgetc(f);
        printf(" TADY jeste neco je %x \n",c);
        c=fgetc(f);
        printf(" TADY jeste neco je %x \n",c);
        c=fgetc(f);
        printf(" TADY jeste neco je %x \n",c);
        c=fgetc(f);
        printf(" TADY jeste neco je %x \n",c);*/
    }

    bit8 instrukce;

    r.ip = HEADER_SIZE;			// nastaveni instruction pointeru na konec hlavicky, tedy na první istrukci kódu
    r.cs = 0;
    r.ds = 0;
    r.es = 0;
    r.ss = 0;
    r.bp = HEADER_SIZE;
    r.sp = SEGMENT_SIZE -2;	// size = 65536
    r.instrukcniPrefix = 0;
    r.ESprefer = 0;
    r.porovnavani = 0;


    while (true){
        instrukce = pamet[r.ip];

        if (instrukce == OPSIZE || instrukce == ADSIZE || instrukce == ESPRF)
        {
            if (instrukce == ESPRF)
                r.ESprefer = 1;
            else
                r.instrukcniPrefix = instrukce;

            printf ("Načítám prefix: %x (%d) : %x \n", instrukce, instrukce,r.instrukcniPrefix);
            r.ip++;
        }else{

            int opTableIndex=-1;
            for (int j = 0; j < 21; ++j) {
                if (OpTable[j]==instrukce){
                    opTableIndex=j;
                    printf("volana FCE je :  %d \n",opTableIndex);
                    retur=handle_fce[opTableIndex](&r, pamet);
                    r.instrukcniPrefix=0;
                    break;
                }
            }
            if(instrukce==INT){
                opTableIndex=80;
                r.ip++;
                instrukce = pamet[r.ip];	// cislo preruseni

                switch (instrukce){
                    case 0x10:{
                        int_10(&r, pamet);
                    }
                        break;
                    case 0x20:{
                        int_20(&r, pamet);
                        printf("%s","Konec programu. \n");return(0);
                    }
                        break;
                    case 0x21:{
                        int_21(&r, pamet);

                    }
                        break;
                }
            }

                //printf("Definované přerušení %d (0x%x)\n", instr, instr);

                if(opTableIndex==-1 && instrukce!=INT){
                   r.ip++;
                }
                if(retur==-1){
                 printf("\n \nPri zpracovani doslo k chybe.\n \n");
                exit(-10);
                }
            }

        /*switch (instrukce) {
            case MOVEAX:{
                moveEax(&r, pamet);
                printf("%s","MOVEAX");

            }
                break;
            case MOVEBX:{
                moveEbx(&r, pamet);
                printf("%s","MOVEBX");

            }
                break;
            case MOVEDX:
            {
                moveEdx(&r, pamet);
                printf("%s","MOVEDX");

            }
                break;
            case MOVESI:
            {
                moveEsi(&r, pamet);
                printf("%s","MOVSI");

            }
                break;
            case MOVE8C:
            {
                moveC(&r, pamet);
                printf("%s","MOVE8C");

            }
                break;
            case MOVE8E:
            {
                moveE(&r, pamet);
                printf("%s","MOVE8E");

            }
                break;
            case XOR:
            {
                xor_instr(&r, pamet);
                printf("%s","XOR");

            }
                break;
            case JMP:
            {
                jmp(&r, pamet);
                printf("%s","JMP");

            }
                break;
            case INC:
            {
                inc(&r, pamet);
                printf("%s","INC");

            }
                break;
            case ADD:
            {
                add(&r, pamet);
                printf("%s","ADD");

            }
                break;
            case MOVE8A:
            {
                moveA(&r, pamet);
                printf("%s","MOVE8A");
                //zatim neni
            }
                break;
            case INCEBX:
            {
                incebx(&r, pamet);
                printf("%s","INCEBX");

            }
                break;
            case INCEDX:
            {
                incedx(&r, pamet);
                printf("%s","INCEDX");

            }
                break;
            case DECECX:
            {
                dececx(&r, pamet);
                printf("%s","DECECX");

            }
                break;
            case MOVEAH:
            {
                moveah(&r, pamet);
                printf("%s","MOVEAH");

            }
                break;
            case ADDADDR:
            {
                addaddr(&r, pamet);
                printf("%s","ADDADR");

            }
                break;
            case CMP:
            {
                cmp(&r, pamet);
                printf("%s","CMP");

            }
                break;
            case JNE:
            {
                jne(&r, pamet);
                printf("%s","JNE");

            }
                break;
            case MOVEDI:
            {
                movedi(&r, pamet);
                printf("%s","MOVEDI");

            }
                break;
            case MOVEC7:
            {
                movec7(&r, pamet);
                printf("%s","MOVEC7");

            }
                break;
            case INT: 	{								// přerušení je trochu specifické, tak se řeší tady
                r.ip++;
                instrukce = pamet[r.ip];	// cislo preruseni
                //printf("Definované přerušení %d (0x%x)\n", instr, instr);

                if (instrukce == END){printf("%s","Konec programu. \n");return(0);}
            }break;

            }*/

            printf("%s","\n");



        }
        }




