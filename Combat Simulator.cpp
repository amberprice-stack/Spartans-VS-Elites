// Combat Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <random>

int getNumSpartans();
int getNumElites();
void printResults(int numSpartan, int numElites, int startSpartans, int startElites);
void simulatedBattle(int &numSpartan, int &numElites);

int main()
{
	int numElites;
	int numSpartan;
	int startElites;
	int startSpartans;

	
	
	std::cout << "*** Spartans Vs Elites ***\n\n";

	//get the number of spartans
	numSpartan = getNumSpartans();

	startSpartans = numSpartan;

	//get the number of elites
	numElites = getNumElites();

	startElites = numElites;

	std::cout << "\nBeginning combat!\n";

	simulatedBattle(numSpartan, numElites);

	printResults(numSpartan, numElites, startSpartans, startElites);
	
	
	system("PAUSE");
	return 0;
}

int getNumSpartans()
{
	int numSpartan;
	std::cout << "Enter the number of Spartans: ";
	std::cin >> numSpartan;
	return numSpartan;
}

int getNumElites()
{
	int numElites;
	std::cout << "Enter the number of Elites: ";
	std::cin >> numElites;
	return numElites;
}

void printResults(int numSpartan, int numElites, int startSpartans, int startElites)
{
	std::cout << "\nBattle is over!\n";
	if (numSpartan > 0)
	{
		std::cout << "\nSpartans Won!\n";
		std::cout << "There are " << numSpartan << " spartans left!\n";
	}
	else
	{
		std::cout << "\nElites Won!\n";
		std::cout << "There are " << numElites << " elites left!\n";
	}
	std::cout << startSpartans - numSpartan << " spartans and " << startElites - numElites << " elites lost their lives.\n\n";

}

void simulatedBattle(int &numSpartan, int &numElites)
{
	static std::default_random_engine randomEngine(time(NULL));
	std::uniform_real_distribution<float> attack(0.0f, 1.0f);
	
	char turn = 'S';

	//Human properties
	float spartanAttack = 0.6f;
	float spartanHealth = 250.0f;
	float spartanDamage = 200.0f;
	float currentSpartanHealth = spartanHealth;

	//Elite properties
	float eliteAttack = 0.7f;
	float eliteHealth = 220.0f;
	float eliteDamage = 200.0f;
	float currentEliteHealth = eliteHealth;
	
	float attackResult;
	
	while ((numSpartan > 0) && (numElites > 0))
	{
		//get attack result 
		attackResult = attack(randomEngine);
		//spartan turn
		if (turn == 'S')
		{
			//check if attack was successful
			if (attackResult <= spartanAttack)
			{
				currentEliteHealth -= spartanDamage;

				if (currentEliteHealth < 0)
				{
					numElites--;
					currentEliteHealth = spartanHealth;
				}
			}
			turn = 'E';
		}
		else if (turn == 'E')
		{
			if (attackResult <= eliteAttack)
			{
				currentSpartanHealth -= eliteDamage;

				if (currentSpartanHealth < 0)
				{
					numSpartan--;
					currentSpartanHealth = spartanHealth;
				}
			}
			turn = 'S';
		}


	}
}