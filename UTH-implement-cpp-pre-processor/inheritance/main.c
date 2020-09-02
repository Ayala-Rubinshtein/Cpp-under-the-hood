#include "inheritance.h"
#include <stdio.h>
void doMaterials()
{
	
	Materials mat;
	Material_t mat1;
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	Material_t mat2;
	
	struct MatTest { Materials mat; Material_t mat_t; }MatTest;
    printf("\n--- Start doMaterials() ---\n\n");
    

    printf("Size of Materials: %lu\n", sizeof(Materials)==0?1:sizeof(Materials));
    printf("Size of mat: %lu\n",sizeof(mat)==0?1:sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    
    printf("Size of Materials + Material_t: %lu\n", sizeof(Material_t)+sizeof(Material_t));
    
    
    mat1.material=OTHER;
    printf("Material created, set to %s\n",names[mat1.material]);
    
    
	mat2.material=METAL;
	printf("Material created, set to %s\n",names[mat2.material]);
    printf("\n--- End doMaterials() ---\n\n");
}


void doPhysicalBox()
{
     PhysicalBox pb1;
    PhysicalBox pb2;
    PhysicalBox pb3;
    PhysicalBox pb4;
    
    printf("\n--- Start doPhysicalBox() ---\n\n");

   
    PhysicalBox_ctor_ddde(&pb1,8, 6, 4,PLASTIC);
    PhysicalBox_ctor_ddde(&pb2,1, 1, 1,WOOD);
    PhysicalBox_ctor_ddde(&pb3,7, 7, 7,OTHER);
    printf("\npb4 is copy-constructed from pb1\n");
   	pb4 = pb1;
    PhysicalBox_printp_Pys(&pb4);
    PhysicalBox_printp_Pys(&pb1);
    printf("pb4 %s pb1\n", pb4.material.material==pb1.material.material && (pb4.box.width == pb1.box.width && pb4.box.height == pb1.box.height && pb4.box.length == pb1.box.length) ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
    PhysicalBox_printp_Pys(&pb4);
    PhysicalBox_printp_Pys(&pb3);
    printf("pb4 %s pb3\n", pb4.material.material==pb3.material.material && (pb4.box.width == pb3.box.width && pb4.box.height == pb3.box.height && pb4.box.length == pb3.box.length) ? "equals" : "does not equal");
    printf("\n--- End doPhysicalBox() ---\n\n");
    PhysicalBox_dtor(&pb4);
    PhysicalBox_dtor(&pb3);
    PhysicalBox_dtor(&pb2);
    PhysicalBox_dtor(&pb1);
}

void doWeightBox()
{
    WeightBox pw1;
    WeightBox pw2;
    WeightBox pw3;
    WeightBox pw4;
    printf("\n--- Start doWeightBox() ---\n\n");

    WeightBox_ctor_dddd(&pw1,8, 6, 4, 25);
    WeightBox_ctor_dddd(&pw2,1, 2, 3,0.0);
     WeightBox_ctor_dddd(&pw3,10, 20, 30, 15);
     
    printf("\npw4 is copy-constructed from pw1\n");
    WeightBox_copy_ctor_Wbox(&pw4,&pw1);
    WeightBox_printw(&pw4);
    WeightBox_printw(&pw1);
    printf("pw4 %s pw1\n", pw4.weight==pw1.weight && (pw4.box.width == pw1.box.width && pw4.box.height == pw1.box.height && pw4.box.length == pw1.box.length) ? "equals" : "does not equal");
    
    printf("\npw4 is copy-assigned from pw3\n");
    WeightBox_operator_eq_Wbox(&pw4,&pw3);
  WeightBox_printw(&pw4);
    WeightBox_printw(&pw3);
    printf("pw4 %s pw3\n", pw4.weight==pw3.weight && (pw4.box.width == pw3.box.width && pw4.box.height == pw3.box.height && pw4.box.length == pw3.box.length) ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
    WeightBox_dtor(&pw4);
    WeightBox_dtor(&pw3);
    WeightBox_dtor(&pw2);
    WeightBox_dtor(&pw1);
}
int main()
{
    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");
	return 0;
}
