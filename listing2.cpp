/* 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Listing 2. Multiple breakpoints example */
/* Cristos' Blog - http://cristos.x25.pl */

#include <iostream>

class MyClass 
{
public:
	MyClass() {
		_x=0;
		std::cout << "MyClass constructor!" << std::endl;
	}

	explicit MyClass(int param) {
		_x = param;
		std::cout << "MyClass(int param) constructor!" << std::endl; 
	}

	void doSomething() {
		std::cout << "MyClass object does something" << std::endl;
	}

protected:
	int _x;
};

int main(int argc, char *argv[])
{
	std::cout << "Starting!..." << std::endl;

	MyClass objA; 
	MyClass objB(4); 

	objA.doSomething();
	objB.doSomething();
	
	std::cout << "Done!" << std::endl;

	return 0;
}
