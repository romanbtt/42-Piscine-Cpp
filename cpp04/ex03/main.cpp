#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

static void	separator( void )
{
	std::cout << "\033[1;31m-- -- -- -- -- -- -- -- -- -- -- -- -- --\033[0m";
	std::cout << std::endl;
}

int main( void )
{
	IMateriaSource* src = new MateriaSource();
	separator();

	src->learnMateria(new Ice());
	separator();
	src->learnMateria(new Cure());
	separator();

	ICharacter* me = new Character("me");
	separator();
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	separator();

	tmp = src->createMateria("cure");
	me->equip(tmp);
	separator();

	tmp = src->createMateria("Other");
	me->equip(tmp);
	separator();

	ICharacter* bob = new Character("bob");
	separator();

	me->use(-1, *bob);
	separator();
	me->use(0, *bob);
	separator();
	me->use(1, *bob);
	separator();
	me->use(2, *bob);
	separator();
	me->use(3, *bob);
	separator();
	me->use(4, *bob);
	separator();

	me->unequip(0);
	separator();
	me->use(0, *bob);
	separator();

	delete bob;
	separator();
	delete me;
	separator();
	delete src;
	separator();

	return 0;
}