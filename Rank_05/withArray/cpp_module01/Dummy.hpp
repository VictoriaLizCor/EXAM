#ifndef DUMMY_HPP
 #define  DUMMY_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"


class Dummy: public ATarget
{
	public:
		Dummy();
		~Dummy();
		ATarget* clone() const;

	private:
		// Dummy(Dummy const& rhs);
		// Dummy& operator=(Dummy const& rhs);

};
#endif
