#include<iostream>
#include<stdlib.h>
#include <utility>
#include "Map.hpp"

using namespace cs540;
int main () {
	Map<int, int> map1;
	
	/* ----------------------- Inserion ---------------------------------*/	
	
	/* Insert Nodes */
	std::pair <int,int> p, p1;
	
	p = std::make_pair (20,20);
	map1.insert(p);
	p = std::make_pair (10,10);
	map1.insert(p);
	p = std::make_pair (30,30);
	map1.insert(p);
	p = std::make_pair (5,5);
	map1.insert(p);
	p = std::make_pair (15,15);
	map1.insert(p);
	
	std::cout << "Insertion succeed [5] elemenet. \n" << std::endl;
	
	/* Insert few repitative nodes */
	p = std::make_pair (10,10); 
	map1.insert(p);
	std::cout << "Trying to insert 10 again, It will look in list and it already exist so, \nIt will not add again, It will be added in 'CACHE'. \n" << std::endl;
	
	/* Insert few repitative nodes */
	p = std::make_pair (10,10); 
	map1.insert(p);
	std::cout << "Trying to insert 10 again, It will now look in 'CACHE' for 10 and it exist so it wont add in list. \n" << std::endl;
	
	/* Adding */
	std::cout << "Insertion Records. \n" << std::endl;
	for(int i = 20; i < 100000; i++) {
		p = std::make_pair (i,i);
		map1.insert(p);
	}
std::cout << "Insertion Complete. \n" << std::endl;
	 
	/*-----------------------Exploit Locality-------------------------*/ 
	
	auto it1 = map1.find(10);
	std::cout << "10 was already in Cache, so it will look up in cache and return "  << (*it1).first << std::endl;
	
	auto it2 = map1.find(20000);
	std::cout << "Accessing 200000 for the first time (It will look in list (Traverse from height of the list) "  << (*it2).first << std::endl;
	
	auto it3 = map1.find(20010);
	std::cout << "Accessing 200010 for the first time (It will look in list (Traverse from height of the list) "  << (*it3).first << std::endl;
		
	
	auto it4 = map1.find(20000);
	std::cout << "Accessing 200000 again (It will look in Cache)"  << (*it4).first << std::endl;
	
	auto it5 = map1.find(20010);
	std::cout << "Accessing 200010 again (It will look in Cache)"  << (*it5).first << std::endl;
	
	std::cout << "It removes least frequently accessed node, whenever it reaches height of the skip list"  << std::endl;
	
	return 0;
}
