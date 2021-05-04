
#include "Nextion.h"



//  LED PINS
int BC_1 =  25;
int BC_2 =  32;
int BC_3 =  33;

// COMPLEMENTARY VALUE TO SWITCH THE PINS
int comp1 = 0;
int comp2 = 0;
int comp3 = 0;

// DECLARE A BUTTON OBJECT [page id:0,component id:1, component name: "b0"].  

NexButton  b0 = NexButton(0, 2,"b0");
NexButton  b1 = NexButton(0, 3,"b1");
NexButton  b3 = NexButton(0, 4,"b2");


// REGISTER A BUTTON OBJECCT TO THE TOUCH EVENT LIST

NexTouch *nex_listen_list[] = 
{
    &b0,
    &b1,
    &b3,
    NULL
};



// ALL LED'S CALLBACK FUNCTIONS.
void b0PopCallback(void *ptr)
{
 
 comp1 = (!comp1);
 digitalWrite(BC_1, comp1);
 
// dbSerialPrintln(comp1);   
}

void b3PopCallback(void *ptr)
{
 
 comp3 = (!comp3);
 digitalWrite(BC_3, comp3);
 
 //dbSerialPrintln(comp3);   
}
void b1PopCallback(void *ptr)
{
 
 comp2 = (!comp2);
 digitalWrite(BC_2, comp2);
 //dbSerialPrintln(comp2); 
    
}




void setup(void)
{
  // SET THE PIN OUTPUT
    pinMode( BC_1, OUTPUT);
    pinMode( BC_2, OUTPUT);
    pinMode( BC_3, OUTPUT);
    
    nexInit();
    
   // REGISTER THE POP EVENT CALLBACK FUNCTION OF THE CURRENT BUTTON. 
    b0.attachPop(b0PopCallback, &b0);
    b1.attachPop(b1PopCallback, &b1);
    b3.attachPop(b3PopCallback, &b3);
    
    
}

void loop()
{

  
    nexLoop(nex_listen_list);
    
   
    
}
