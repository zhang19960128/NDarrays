#include "ndarrays.h"
#include <iostream>
int main(){
	ndarrays a({3,3,3});
	ndarrays b=a;
	ndarrays c(b);
  a({1,1,1})=1;
	std::cout<<a({1,2,1})<<std::endl;
	return 0;
}
