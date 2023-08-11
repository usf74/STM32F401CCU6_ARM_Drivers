#ifndef BIT_MATH_H_INCLUDED
#define BIT_MATH_H_INCLUDED


#define SET_BIT(var,bit)     (var |= (1<<bit))
#define TOGGLE_BIT(var,bit)  (var ^= (1<< bit))
#define CLEAR_BIT(var,bit)   (var &=~ (1<< bit)) 
#define GET_BIT(var,bit)     ((var>>bit)&1) 

#endif // BIT_MATH_H_INCLUDED
