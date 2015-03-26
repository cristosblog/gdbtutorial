# Makefile for gdb crash course
# 
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#


CC=gcc
CXX=g++
CFLAGS= -std=c99 -Wall -pedantic -g
CXXFLAGS= -std=c++98 -Wall -pedantic -g

.PHONY: all clean
all: listing1 listing2 listing3 listing3b listing4

listing1: listing1.c
	$(CC) $(CFLAGS) listing1.c -o listing1

listing2: listing2.cpp
	$(CXX) $(CXXFLAGS) listing2.cpp -o listing2

listing3: listing3.c
	$(CC) $(CFLAGS) listing3.c -o listing3

listing3b: listing3b.c
	$(CC) $(CFLAGS) listing3b.c -o listing3b

listing4: listing4.c
	$(CC) $(CFLAGS) listing4.c -o listing4

clean:
	rm -f listing1 listing2 listing3 listing3b listing4

