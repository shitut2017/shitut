
#include "MessageBox.h"

MessageBox::MessageBox(short Lleft, short Ltop, short Lwidth, size_t LzOrder, short Bl, short Ptop, short Pwidth,
                       short Pheight, size_t PzOrder, string text) {
    l = new Label(Lleft, Ltop, Lwidth, LzOrder);
    l->setValue(text);
    b[0] = new Button(Lleft,Ltop, Lwidth, LzOrder);
    b[0]->setValue("cancel");
    b[1]->setValue("ok");
    b[1] = new Button(Bl,Ltop, Lwidth, LzOrder);
    p = new Panel (Lleft, Ptop, Pwidth, Pheight, PzOrder);
    p->addControl(l);
    p->addControl(b[0]);
    p->addControl(b[1]);
}
