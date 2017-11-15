#include <iostream>
#include "ndarrays.h"
int main(){
	ndarrays a(3,2,1,1);
	a(0,0,0)=2;
	a(1,0,0)=2;
	std::cout<<a;
}
