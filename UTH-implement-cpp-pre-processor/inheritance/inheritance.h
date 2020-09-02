#ifndef __INHERITANCE_H__
#define __INHERITANCE_H__

#include <stdio.h>
#include "encapsulation.h"

/* Materials */
enum Types
    {
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
    }Types;
    
       
typedef struct Materials
{
}Materials;

typedef struct Material_t
{
	Materials materials;
    enum Types material;
}Material_t;

/* PhysicalBox */

typedef struct PhysicalBox
{
	
    Box box;
    Material_t material;
}PhysicalBox;

void PhysicalBox_printp_Pys(PhysicalBox *this);
void PhysicalBox_ctor_ddde(PhysicalBox *this, double l, double w, double h,enum Types t);
void PhysicalBox_ctor_ddd(PhysicalBox *this, double l, double w, double h);
void PhysicalBox_ctor_e(PhysicalBox *this,enum Types t);
void PhysicalBox_dtor(PhysicalBox *this);



/* WeightBox */

typedef struct WeightBox
{
	Box box;
    double weight;
}WeightBox;

void WeightBox_printw(WeightBox *this);
void WeightBox_operator_eq_Wbox(WeightBox *this,const WeightBox* other);
void WeightBox_dtor(WeightBox* this);
void WeightBox_copy_ctor_Wbox(WeightBox *this,const WeightBox* other);
void WeightBox_ctor_dddd(WeightBox *this,double l, double w, double h, double wgt);














#endif
