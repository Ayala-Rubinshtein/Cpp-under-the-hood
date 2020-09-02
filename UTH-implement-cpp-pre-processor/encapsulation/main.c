#include "encapsulation.h"
#include <stdio.h>
#include <stdbool.h>

static Box largeBox;

void thisFunc()
{

    printf("\n--- thisFunc() ---\n\n"); 
    static int first=true;
    static Box box99;
    if (first)
    {
    	Box_ctor_double_double_double(&box99 ,99, 99, 99);
    	first=false;
    }
    Box_Box_operator_mult_double(&box99,10);
}

void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n");
    static bool first = true;
    static Box box88;
    if(first)
    {
        Box_ctor_double_double_double(&box88, 88, 88, 88);
        first = false;
    }
     Box_Box_operator_mult_double(&box88, 10);
}

void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box b1;
    Box_ctor_double(&b1,3);
    Box b2;
    Box_ctor_double_double_double(&b2,4, 5, 6);
    
    printf("b1 volume: %f\n", b1.length * b1. width* b1.height);
    printf("b2 volume: %f\n", b2.length * b2. width* b2.height);
    
	Box_Box_operator_mult_double(&b1,1.5);
	Box_Box_operator_mult_double(&b2,0.5);	
    printf("b1 volume: %f\n", b1.length * b1. width* b1.height);
    printf("b2 volume: %f\n",b2.length * b2. width* b2.height);

    Box b3;
    b3 = b2;
    Box b4;
    b4.length=3*b2.length;
    b4.width= 3* b2.width ;
    b4.height=3* b2.height;
    printf("b3 %s b4\n", (b3.width == b4.width && b3.height == b4.height && b3.length == b4.length) ? "equals" : "does not equal");
   	Box_Box_operator_mult_double(&b3,1.5);
 	Box_Box_operator_mult_double(&b4,0.5);
    printf("Now, b3 %s b4\n", (b3.width == b4.width && b3.height == b4.height && b3.length == b4.length) ? "equals" : "does not equal");
  

    printf("\n--- End doBoxes() ---\n\n");
    
    Box_dtor(&b4);
    Box_dtor(&b3);
    Box_dtor(&b2);
    Box_dtor(&b1);
}

void doShelves()
{
	
    printf("\n--- start doShelves() ---\n\n");

    Box aBox;
    Box_ctor_double(&aBox,5);
    static  char* msg=DEF_MSG;
    Shelf aShelf;
    aShelf.massege=msg;
	Box box1;
    Box_ctor_void(&box1);
	Shelf_void_setBox_int_box(&aShelf,0,&box1);
	Box box2;
    Box_ctor_void(&box2);
	Shelf_void_setBox_int_box(&aShelf,1,&box2);
	Box box3;
    Box_ctor_void(&box3);
	Shelf_void_setBox_int_box(&aShelf,2,&box3);
    Shelf_void_print(&aShelf);
   	Shelf_void_setBox_int_box(&aShelf,1, &largeBox);
    Shelf_void_setBox_int_box(&aShelf,0, &aBox);
    Shelf_void_print(&aShelf);
    msg="This is the total volume on the shelf:";
	aShelf.massege=msg;
    Shelf_void_print(&aShelf);
    msg="Shelf's volume:";
	aShelf.massege=msg;
    Shelf_void_print(&aShelf);
	Box tmpbox;
	Box_ctor_double_double_double(&tmpbox,2, 4, 6);
	Box_dtor(&tmpbox);
	Shelf_void_setBox_int_box(&aShelf,1, &tmpbox);
	Box tmpbox2;
	Box_ctor_double(&tmpbox2,2);
    Shelf_void_setBox_int_box(&aShelf,2, &tmpbox2);
    Box_dtor(&tmpbox2);
    Shelf_void_print(&aShelf);

    printf("\n--- end doShelves() ---\n\n");
    Box_dtor(&aShelf.boxes[2]);
    Box_dtor(&aShelf.boxes[1]);
    Box_dtor(&aShelf.boxes[0]);
    Box_dtor(&aBox);
}

int main()
{
	printf("\n--- Start main() ---\n\n");
	
	Box_ctor_double_double_double(&largeBox ,10, 20, 30);
	
	doBoxes();
	   
    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();
    
    doShelves();
        
    printf("\n--- End main() ---\n\n");
    Box_dtor(&box99);
    Box_dtor(&largeBox);
	    
	return 0;
}
