#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

int data[8192] = {0};
int contextStack[8192] = {0}, contextStackIndex = 0;
int opStack[8192] = {0}, opStackIndex = 0, opTemp = 0;
int lastBindDataIndex = 0;

int main() {
    contextStackIndex = 0;
    opStackIndex = 0;
    opTemp = 0;
    lastBindDataIndex = 0;

    //";"

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Scan"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"Scan"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"++"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"--"
    opTemp = opStack[opStackIndex - 1] -= opStack[opStackIndex]; --opStackIndex;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"**"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex]; --opStackIndex;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"Div"
    opTemp = opStack[opStackIndex - 1] /= opStack[opStackIndex]; --opStackIndex;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"Mod"
    opTemp = opStack[opStackIndex - 1] %= opStack[opStackIndex]; --opStackIndex;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"--"
    opTemp = opStack[opStackIndex - 1] -= opStack[opStackIndex]; --opStackIndex;

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"**"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex]; --opStackIndex;

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"++"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"Div"
    opTemp = opStack[opStackIndex - 1] /= opStack[opStackIndex]; --opStackIndex;

    //"++"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_xx0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_xx0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"Mod"
    opTemp = opStack[opStackIndex - 1] %= opStack[opStackIndex]; --opStackIndex;

    //"++"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_xx0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_yy0"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    return 0;
}