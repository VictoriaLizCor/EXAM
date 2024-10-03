#ifndef FWOOSH_HPP
 #define  FWOOSH_HPP


#include <iostream>
#include <string>
#include "ASpell.hpp"

class Fwoosh: public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		ASpell* clone() const;
	private:
		// Fwoosh(Fwoosh const& rhs);
		// Fwoosh& operator=(Fwoosh const& rhs);

};
#endif
