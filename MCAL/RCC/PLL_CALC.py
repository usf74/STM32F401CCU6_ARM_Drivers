

Input_Clock=int(input("Enter Input Clock in MHZ\n"))
PLLP=2
PLLM=2
PLLN=192
Check_Flag=(input("Enable boundary check? (y/n)\n"))
if Check_Flag=='y':
    Check_Flag=1
else: 
    Check_Flag=0
print("P\tM\tN\tCLK")
while (PLLP<=8):
    while (PLLM<=63):
        while(PLLN<=432):
            if Check_Flag==1:
                if (1 < Input_Clock/PLLM < 2) and (192 < Input_Clock*PLLN/PLLM < 432) and (Input_Clock*PLLN/PLLM/PLLP<=84):
                    print(PLLP,"\t",PLLM,"\t",PLLN,"\t",Input_Clock*PLLN/PLLM/PLLP,"MHZ")
                    PLLN+=1
                else:
                     PLLN+=1
                    
            else:
                    print(PLLP,"\t",PLLM,"\t",PLLN,"\t",Input_Clock*PLLN/PLLM/PLLP,"MHZ")
                    PLLN+=1
                
        PLLM+=1
        PLLN=192
    PLLP+=2
    PLLM=2


