#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"


int main()
{
	//Part of Animal
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\033[1;31mPart of Animal\033[0m" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); // will output the cat sound!
	dog->makeSound(); // will output the dog sound
	animal->makeSound(); // default animal sound
	// delete --> avoid leak (call destructor)
	delete animal;
	delete cat;
	delete dog;

	// Part of WrongAnimal
	/*
		the goal of WrongAnimal --> to avoid the polymorphism
	*/
	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	const WrongAnimal	*wrongDog = new WrongDog();
	const WrongAnimal	*wrongCat = new WrongCat();

	std::cout << "\033[1;31mPart of WrongAnimal\033[0m" << std::endl;
	std::cout << wrongDog->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound(); // will output the wrongcat sound
	wrongDog->makeSound(); // will output the wrongdog sound
	wrongAnimal->makeSound(); // will output the wronganimal sound
	// delete --> avoid leak (call destructor)
	delete wrongAnimal;
	delete wrongDog;
	delete wrongCat;

	return 0;
}
