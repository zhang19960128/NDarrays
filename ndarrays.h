#include <stdarg.h>
#include <vector>
#include <new>
#include <iostream>
class ndarrays{
public:
//construct differnt dimention list//
ndarrays(int dimen,...){
	/*construct a ndimentional array, the first argument is it's dimention, the comming arguments are the lengths of different dimentions*/
	va_list args;
	std::vector<int> a(0);
	va_start(args,dimen);
	dimention=dimen;
	int temp=1;
	int temp2;
	for(int i=0;i<dimen;i++){
		temp2=va_arg(args,int);
		a.push_back(temp2);
		temp=temp*(temp2);
	}
	va_end(args);
	size=a;
	linearlength=temp;
	p=new double[temp];
}
ndarrays(const ndarrays& a){
	size=a.size;
	dimention=a.dimention;
	int temp=1;
	for(auto i=size.begin();i<size.end();i++){
		temp=temp*(*i);
	}
	p=new double[temp];
	for(size_t t=0;t<a.linearlength;t++){
		p[t]=a.p[t];
	}
}
ndarrays& operator=(const ndarrays& a){
	size=a.size;
	dimention=a.dimention;
	int temp=1;
	for(auto i=size.begin();i<size.end();i++){
		temp=temp*(*i);
	}
	p=new double[temp];
	for(size_t t=0;t<a.linearlength;t++){
		p[t]=a.p[t];
	}
	return *this;
}
~ndarrays(){
	delete []p;
}
double& operator()(int a,...){
	int temp;
	va_list arg;
	int first;
	va_start(arg,a);
	first=a;
	if(dimention ==1){
		return p[first];
	}
	std::vector<int> coord(0);
	coord.push_back(first);
	for(size_t t=1;t<dimention;t++){
		first=va_arg(arg,int);
		coord.push_back(first);
	}
	va_end(arg);
	for(size_t t=0;t<dimention-1;t++){
		if(t==0) temp=coord[t]*size[t+1]+coord[t+1];
		else temp=temp*size[t+1]+coord[t+1];
	}
	return p[temp];
}
friend std::ostream& operator<<(std::ostream &os,ndarrays out);
private:
	int dimention;
	std::vector<int> size;
	double *p;
	int linearlength;
};
std::ostream& operator<<(std::ostream &os,ndarrays out){
	int temp=1;
	os<<"the dimention of the array is: "<<out.dimention<<std::endl;
	os<<"the sizes of different dimention are:"<<std::endl;
	for(auto t=out.size.cbegin();t!=out.size.cend();t++){
		os<<*t<<" ";
		temp=(*t)*temp;
	}
	os<<std::endl;
	os<<"elements are:"<<std::endl;
	for(size_t t=0;t<temp;t++){
		os<<(out.p)[t]<<std::endl;
	}
	return os;
}
