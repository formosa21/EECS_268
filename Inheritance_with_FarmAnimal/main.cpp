#include "FarmAnimal.h"
#include "AnimalPen.h"
#include <iostream>

void goodbyeMessage(const FarmAnimal& animal);
void menu();

int main()
{
	int choice = 0;	
	double gallons_of_milk = 0.0;
	int num_of_eggs = 0;
	AnimalPen myPen;
	std::string yes_no = "";
	bool endloop = false;
	
	do
	{	
		do//temporary menu design
		{
			menu();
			std::cout << "choice : ";
			std::cin >> choice;
			if(choice == 1)
			{
				FarmAnimal* a1 = new Cow();
				Cow* c1 = nullptr;
				std::cout << "How many gallons of milk did this cow produce?: ";
				std::cin >> gallons_of_milk;
				c1 = static_cast<Cow*>(a1);  //cast c1 to be a1 [make sure this part]
				c1 -> setMilkProduced(gallons_of_milk);
				myPen.add(a1);
				c1 = nullptr;
				a1 = nullptr;
				
			}
			else if(choice == 2)
			{
				FarmAnimal* a2 = new Chicken();
				std::cout << "Add an eggless chicken to the pen? Ok. You're the boss. ";
				myPen.add(a2);
				a2 = nullptr;
			}
			else if(choice == 3)
			{
				FarmAnimal* a3 = new CyberChicken();
				CyberChicken* c2 = nullptr;
				std::cout << "How many eggs does this cyber chicken produce?: ";
				std::cin >> num_of_eggs;
				c2 = static_cast<CyberChicken*>(a3); //so c2 can do stuff a3 can't do
				c2 -> setCyberEggs(num_of_eggs);
				myPen.add(a3);
				c2 = nullptr;
				a3 = nullptr;
			}
			else
			{
				std::cout << "Please enter a valid choice!";
				choice = 0;
			}
		}while(choice == 0);
		
		//ask the user if enough animal is added to the pen
		std::cout << "Done adding animals? (y/n)";
		std::cin >> yes_no;
		if(yes_no == "y" || yes_no == "yes" || yes_no == "Y")
			endloop = true; 								
		
	}while(endloop == false); // end of do-while loop
	
	std::cout << "\nReleasing all animals!\n----------------------------------\n";
	FarmAnimal* temp;
	int eggstotal = 0;
	double milktotal = 0;

	while(!myPen.isEmpty())
	{
		temp = myPen.peek();
		if(temp -> getName() == "CyberChicken")
		{	CyberChicken* c2 = nullptr;
			c2 = static_cast<CyberChicken*>(temp);
			eggstotal += c2 -> getCyberEggs(); //add the eggs
			std::cout << "The CyberChicken laid " << c2 -> getCyberEggs() << " cyber eggs. Humanity is in truble.\n";
			c2 = nullptr;	
		}
		if(temp -> getName() == "Cow")
		{
			Cow* a1 = nullptr;
			a1 = static_cast<Cow*>(temp);
		  	milktotal += a1 -> getMilkProduced(); //add the milk	
			std::cout << "The cow produced " << a1 -> getMilkProduced() << " of milk.\n";
			a1 = nullptr;
		}
		if(temp -> getName() == "Chicken")
			std::cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help? \n";
			
		goodbyeMessage(*temp);//dereference 
		
		myPen.releaseAnimal();
	}

	temp = nullptr;	
	
	std::cout << "Your farm produced " << milktotal << " gallons of milk and " << eggstotal << " eggs.";




return 0;
}

void goodbyeMessage(const FarmAnimal& animal)
{
	std::cout << "Upon release the " << animal.getName() << " said " << animal.getSound() << "." << std::endl;
}

void menu()
{
	std::cout << "\nSelect an Animal to add to the Pen: \n";
	std::cout << "1)Cow (produces milk) \n";
	std::cout << "2)Chicken (cannot lay eggs) \n";
	std::cout << "3)Cyber Chicken (seems dangerous, but lay eggs) \n";
	std::cout << "-------------------------------------\n";
}
