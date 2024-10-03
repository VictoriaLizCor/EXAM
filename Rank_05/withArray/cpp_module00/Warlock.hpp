#ifndef WARLOCK_HPP
 #define  WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock
{
	public:
		Warlock(std::string const& name, std::string const& title);
		~Warlock();
		std::string const& getName() const;
		std::string const& getTitle() const;
		void setTitle(std::string const& name);
		void introduce(void) const;

	private:
		std::string _name;
		std::string _title;

		Warlock();
		Warlock(Warlock const& rhs);
		Warlock& operator=(Warlock const& rhs);

};
#endif