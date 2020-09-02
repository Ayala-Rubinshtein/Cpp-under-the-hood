#ifndef __ENCAPSULATION_H__
#define __ENCAPSULATION_H__
#define NUM_BOXES 3
/* Box*/
typedef struct Box
{
	double length;
    double width;
    double height;
}Box;
void Box_ctor_double( Box *this ,double dim);
void Box_ctor_double_double_double(Box* this ,double l, double w, double h);
void Box_ctor_void(Box* this );
void Box_dtor(Box* this);
void Box_void_print(const Box *this);
Box* Box_Box_operator_mult_double(Box *this,double mult);



/* Shelf */

typedef struct Shelf
{

    Box boxes[NUM_BOXES];
}Shelf;

void Shelf_void_setBox_int_box(Shelf *this,int index, const Box* dims);
double shelf_void_get_volume(Shelf *this);
void Shelf_void_print(Shelf *this);










#endif
