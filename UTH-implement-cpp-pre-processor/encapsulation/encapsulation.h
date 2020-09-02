#ifndef __ENCAPSULATION_H__
#define __ENCAPSULATION_H__
#define NUM_BOXES 3
#define DEF_MSG "The total volume held on the shelf is"
//// Box ////////////
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
//double Box_double_getWidth(const Box *box);
//double Box_double_getLength(const Box *box);
//double Box_double_getHeight(const Box *box);
//double Box_double_getVolume(const Box *box);
void Box_void_print(const Box *this);
Box* Box_Box_operator_mult_double(Box *this,double mult);
//Box Box_operator_mult__Box_double(Box *box,const Box* box1,double mult);


//// Shelf ////////////

typedef struct Shelf
{
	char* massege;
    Box boxes[NUM_BOXES];
}Shelf;

void Shelf_void_setBox_int_box(Shelf *this,int index, const Box* dims);
double shelf_void_get_volume(Shelf *this);
void Shelf_void_print(Shelf *this);










#endif // __ENCAPSULATION_H__
