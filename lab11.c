#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int atype(char a)
{ 

	if (a>='0' && a<='7') return 1;
	else return 2;

};

int main(){
       
        
		int state = 1;
		int symbol;
		int amount = 0;
		int amount2 = 0;

		while ((symbol = fgetc(stdin)) != EOF) {
		
			switch (state) {
				case 1:
					amount2 = amount;
					if ((atype(symbol) == 1) && (symbol != '0')) state = 2;
						
						else
							{state = 1;
							break;} 
					

				case 2: 
					if (atype(symbol) == 1) state = 3;
						else state = 1;
					 break;
				case 3:
					if (atype(symbol) == 1) {state = 4;
						amount = amount + 1;}
						else
							state = 1;
						
					 break;
				case 4:
					if (atype(symbol) == 1) 
						{state = 5;
							break;}
					if ((symbol == '8') || (symbol == '9')) {
						state = 1;
						amount = amount2;
						break;
					if (atype(symbol) == 2) state = 1;
					break;
					}
						
                case 5:
                if (symbol == '0') {
                	state = 1;
                	break;
                }
                if ((atype(symbol) == 1) || (symbol == '8') || (symbol == '9')) {  
    				state = 5;
    				amount = amount2;
    				break;
				}
						
				if (atype(symbol) == 2)  state = 1;
				break;

					
			};
		};
		printf("%d\n", amount );
    }
			
