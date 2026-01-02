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

    //"For"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //"To" (after "For")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
LABEL__AFTER_TO_00007FF752F23C40:

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //null statement (non-context)

    //"Do" (after "To" after "For")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF752F22350;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"_ff0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_ff0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"**"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex]; --opStackIndex;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //"NULL" (after "For")
    goto LABEL__AFTER_TO_00007FF752F23C40;
LABEL__EXIT_FOR_00007FF752F22350:
    --contextStackIndex;

    //null statement (non-context)

    //";"

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"For"

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //"To" (after "For")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
LABEL__AFTER_TO_00007FF752F2A000:

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //null statement (non-context)

    //"Do" (after "To" after "For")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF752F28710;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"For"

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //"To" (after "For")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
LABEL__AFTER_TO_00007FF752F2CDB8:

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //null statement (non-context)

    //"Do" (after "To" after "For")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF752F2B4C8;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"_jj0"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"++"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //"NULL" (after "For")
    goto LABEL__AFTER_TO_00007FF752F2CDB8;
LABEL__EXIT_FOR_00007FF752F2B4C8:
    --contextStackIndex;

    //"NULL" (after "For")
    goto LABEL__AFTER_TO_00007FF752F2A000;
LABEL__EXIT_FOR_00007FF752F28710:
    --contextStackIndex;

    //null statement (non-context)

    //";"

    //"_jj0"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    return 0;
}