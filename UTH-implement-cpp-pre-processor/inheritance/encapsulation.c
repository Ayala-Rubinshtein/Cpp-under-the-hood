#include <stdio.h>
#include "encapsulation.h"

const char* const DEF_MSG ="The total volume held on the shelf is";
const char* massege="The total volume held on the shelf is";
/* Box */

void Box_ctor_double( Box *this ,double dim)
{
	this-> length=dim;
    this-> width=dim;
    this-> height=dim;
    
    Box_void_print(this);
    
}

void Box_ctor_double_double_double(Box* this ,double l, double w, double h)
{
	this-> length=l;
    this-> width=w;
    this-> height=h;
    
    Box_void_print(this);
}

void Box_ctor_void(Box* this )
{
	this-> length=1;
    this-> width=1;
    this-> height=1;
    
    Box_void_print(this);
}

void Box_dtor(Box* this)
{
	printf("Box destructor, %f x %f x %f\n", this->width,  this->height,  this->length);
    
}



Box* Box_Box_operator_mult_double(Box *this,double mult)
{
	this->width *= mult;
    this->height *= mult;
    this->length *= mult;

    return this;
}

void Box_void_print(const Box *this)
{
	printf("Box: %f x %f x %f\n", this->length , this->width , this->height); 
}




/* Shelf */


void Shelf_void_setBox_int_box(Shelf *this,int index, const Box* dims)
{
    this->boxes[index] = *dims;
}

double shelf_void_get_volume(Shelf *this)
{
    double vol = 0;
    size_t i;
    for (i = 0; i <= NUM_BOXES; ++i)
        vol += this->boxes[i].width * this->boxes[i].length * this->boxes[i].height;

    return vol;
}

void Shelf_void_print(Shelf *this)
{
    printf("%s %f\n", massege, shelf_void_get_volume(this));
}
