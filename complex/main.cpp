#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "complex.hpp"
void Menu_Printf()
{
    std::cout << "Menu - _Complex"<<std::endl;
    std::cout << "[MODIFY FIRST CLASS]"<<std::endl;
    std::cout << "\t [1] - Set new Re z"<<std::endl;
    std::cout << "\t [2] - Set new Im z"<<std::endl;

   std::cout << "[MODIFY SECOND CLASS]"<<std::endl;
    std::cout << "\t [3] - Set new Re z"<<std::endl;
    std::cout << "\t [4] - Set new Im z"<<std::endl;
}
void Complex_Printf(Complex &Complex_First,Complex &Complex_Second)
{
    Complex l_Complex;   
    std::cout  << Complex_First << Complex_Second;
    std::cout << "ARGUMENT [1]:" << Complex_First.GetArg() << std::endl;
    std::cout << "ARGUMENT [2]:" << Complex_Second.GetArg() << std::endl;
    std::cout << "|Z| [1]:" << Complex_First.GetAbs() << std::endl;
    std::cout << "|Z| [2]:" << Complex_Second.GetAbs() << std::endl;
    std::cout << "A - B \t" << Complex_First - Complex_Second << std::endl;
    std::cout << "A + B \t" << Complex_First + Complex_Second << std::endl;
    std::cout << "B - A \t" << Complex_Second - Complex_First << std::endl;
    std::cout << "B + A \t" << Complex_Second + Complex_First << std::endl;
    std::cout << "A * B \t" << Complex_First * Complex_Second << std::endl;
    std::cout << "B * A \t" << Complex_Second * Complex_First << std::endl;
    std::cout << "A / B \t" << Complex_First / Complex_Second << std::endl;
    std::cout << "B / A \t" << Complex_Second / Complex_First << std::endl;
  
    if(Complex_Second == Complex_First)
    {
        std::cout << "[A] == [B]" << std::endl << std::endl;
    }

    else
    {
        std::cout << "[A] != [B]" << std::endl << std::endl;
    }

	l_Complex = Complex_Second;
	l_Complex*= Complex_First.GetReal();
	std::cout << Complex_Second << " * " << Complex_First.GetReal() << " = " << l_Complex << std::endl << std::endl;

	l_Complex = Complex_Second;
	l_Complex*= Complex_First.GetImag();
	std::cout << Complex_Second << " * " << Complex_First.GetImag() << " = " << l_Complex << std::endl << std::endl;

	l_Complex = Complex_Second;
	l_Complex*= Complex_Second.GetReal();
	std::cout << Complex_Second << " * " << Complex_Second.GetReal() << " = " << l_Complex << std::endl << std::endl;

	l_Complex = Complex_Second;
	l_Complex*= Complex_Second.GetImag();
	l_Complex = Complex_Second.GetImag() * Complex_Second;
	std::cout << Complex_Second << " * " << Complex_Second.GetImag() << " = " << l_Complex << std::endl << std::endl;

	l_Complex = Complex_First;
	l_Complex*= Complex_First.GetReal();
	std::cout << Complex_First << " * " << Complex_First.GetReal() << " = " << l_Complex << std::endl << std::endl;
	l_Complex = Complex_First;
	l_Complex*= Complex_First.GetImag();
	std::cout << Complex_First << " * " << Complex_First.GetImag() << " = " << l_Complex << std::endl << std::endl;

	l_Complex = Complex_First;
	l_Complex*= Complex_Second.GetReal();
	std::cout << Complex_First << " * " << Complex_Second.GetReal() << " = " << l_Complex << std::endl << std::endl;


	l_Complex = Complex_Second.GetImag() * Complex_First;
	std::cout << Complex_First << " * " << Complex_Second.GetImag() << " = " << l_Complex << std::endl << std::endl << std::endl;

	l_Complex =  Complex_First - Complex_Second.GetImag();
	std::cout << Complex_First << " - " << Complex_Second.GetImag() << " = " << l_Complex << std::endl << std::endl;

	l_Complex =  Complex_First + Complex_Second.GetImag();
	std::cout << Complex_First << " + " << Complex_Second.GetImag() << " = " << l_Complex << std::endl << std::endl;

	l_Complex =  Complex_First - Complex_Second.GetReal();
	std::cout << Complex_First << " - " << Complex_Second.GetReal() << " = " << l_Complex << std::endl << std::endl;


	l_Complex =  Complex_First + Complex_Second.GetReal();
	std::cout << Complex_First << " + " <<  Complex_Second.GetReal() + Complex_Second.GetReal() << " = " << l_Complex << std::endl << std::endl;  
	std::cout << Complex_First - Complex_Second;
}
  
int main()
{
    Complex Complex_First,Complex_Second;
    char l_Controller;
    float l_Temporary;
    Complex_Second-=Complex_Second-=Complex_Second;
   do
    {
            Menu_Printf();
            Complex_Printf(Complex_First,Complex_Second);
    	    std::cin >> l_Controller;
            l_Controller-=48;
      	    switch(l_Controller)
            {
        	case 1:
            	{
                	std::cout<<"[ENTER NEW VALUE]"<<std::endl;
                	std::cin >> l_Temporary;
			if(std::cin.fail())
			{
				abort();
			}
                	Complex_First.SetReal(l_Temporary);
               	        break;
            	}	
        	case 2:
            	{
                	std::cout<<"[ENTER NEW VALUE]"<<std::endl;
               		std::cin >> l_Temporary;
			if(std::cin.fail())
			{
				abort();
			}
                	Complex_First.SetImag(l_Temporary);
               	 	break;
            	}
       		case 3:
            	{
	                std::cout<<"[ENTER NEW VALUE]"<<std::endl;
	                std::cin >> l_Temporary;
			if(std::cin.fail())
			{
				abort();
			}
	                Complex_Second.SetReal(l_Temporary);
	                break;
	            }
	        case 4:
	            {
	                std::cout<<"[ENTER NEW VALUE]"<<std::endl;
        	        std::cin >> l_Temporary;
			if(std::cin.fail())
			{
				abort();
			}
        	        Complex_Second.SetImag(l_Temporary);
        	        break;
       		    }

	        default:
	            break;
        }
	std::cout<<std::endl<<std::endl;
    }
	while(l_Controller);  
	return 0;
}
