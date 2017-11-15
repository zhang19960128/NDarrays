#include <stdarg.h>
#include <vector>
#include <new>
#include <iostream>
#ifndef __NDARRAYS_H_INCLUDED__
#define __NDARRAYS_H_INCLUDED__
class ndarrays{
public:
//construct differnt dimention list//
ndarrays(int dimen,...);
ndarrays(const ndarrays& a);
ndarrays& operator=(const ndarrays& a);
~ndarrays(){
	delete [] p;
}
double& operator()(int a,...);
friend std::ostream& operator<<(std::ostream &os,ndarrays& out);
private:
	int dimention;
	std::vector<int> size;
	double *p;
	int linearlength;
};
#endif
