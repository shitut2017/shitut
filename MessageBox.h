

#ifndef UNTITLED1_MESSAGEBOX_H
#define UNTITLED1_MESSAGEBOX_H


#include "Panel.h"
#include "Label.h"
#include "Button.h"

class MessageBox {
public:
    MessageBox(short Lleft, short Ltop, short Lwidth,size_t LzOrder,short Bl, short Ptop, short Pwidth, short Pheight,size_t PzOrder, string text);

    Panel *p;
    Label *l;
    Button **b;
};


#endif //UNTITLED1_MESSAGEBOX_H
