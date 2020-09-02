#include "inheritance.h"

/* PhysicalBox Defs */

void PhysicalBox_ctor_ddd(PhysicalBox *this, double l, double w, double h)
{
	Box_ctor_double_double_double(&(this->box) , l,  w,  h);
    PhysicalBox_printp_Pys(this);
}

void PhysicalBox_ctor_ddde(PhysicalBox *this, double l, double w, double h,enum Types t)
{
   const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
   Box_ctor_double_double_double(&(this->box) , l,  w,  h);
   this->material.material=t;
  
	printf("Material created, set to %s\n",names[this->material.material]);
   PhysicalBox_printp_Pys(this);
}

void PhysicalBox_ctor_e(PhysicalBox *this,enum Types t)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
   Box_ctor_double_double_double(&(this->box) , 1,  1,  1);
   this->material.material=t;
  
	printf("Material created, set to %s\n",names[this->material.material]);
   PhysicalBox_printp_Pys(this);
}

void PhysicalBox_dtor(PhysicalBox *this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox dtor, %f x %f x %f, %s;", this->box.width,  this->box.height,  this->box.length, names[this->material.material]);
    Box_dtor(&(this->box));
}
void PhysicalBox_printp_Pys(PhysicalBox *this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox, made of %s; ",names[this->material.material]);
    Box_void_print(&(this->box));
    printf("\n");
}

/* WeightBox Defs */

void WeightBox_ctor_dddd(WeightBox *this,double l, double w, double h, double wgt)
{
    Box_ctor_double_double_double(&(this->box) , l,  w,  h);
    this->weight=wgt;
    WeightBox_printw(this);
}

void WeightBox_copy_ctor_Wbox(WeightBox *this,const WeightBox* other)
{
	Box_ctor_double_double_double(&(this->box) , 1,1,1);
	 this->weight = other->weight;
   WeightBox_printw(this);
}

void WeightBox_dtor(WeightBox* this)
{
    printf("Destructing WeightBox; ");
  	WeightBox_printw(this);
  	 Box_dtor(&(this->box));
}

void WeightBox_operator_eq_Wbox(WeightBox *this,const WeightBox* other)
{
    Box_ctor_double_double_double(&(this->box) , 1,1,1);
    this->weight = other->weight;
    WeightBox_printw(this);
}

void WeightBox_printw(WeightBox *this)
{
    printf("WeightBox, weight: %f; ", this->weight);
    Box_void_print(&(this->box));
}
