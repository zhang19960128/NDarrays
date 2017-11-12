#include <initializer_list>
#include <vector>
#include <new>
#include <iostream>
class ndarrays{
	public:
	//construct differnt dimention list//
	ndarrays(std::initializer_list<int> l){
		size=l;
		size_t temp=1;
		for(auto i=l.begin();i!=l.end();i++){
			temp=temp*(*i);
		}
		p=new double[temp];
	}
	ndarrays(const ndarrays& a){
		size=a.size;
		size_t temp=1;
		for(auto i=a.size.begin();i!=a.size.end();i++){
			temp=temp*(*i);
		}
		p=new double[temp];
	}
	ndarrays& operator=(const ndarrays& a){
		size=a.size;
		size_t temp=1;
		for(auto i=a.size.begin();i!=a.size.end();i++){
			temp=temp*(*i);
		}
		p=new double[temp];
		return *this;
	}
	~ndarrays(){
		delete []p;
	}
	double& operator()(std::initializer_list<int> l){
		size_t dimen=size.size();
		std::vector<int> coord(l.begin(),l.end());
		int temp;
		if(dimen==1)
			return p[coord[0]];
		else 
			for(size_t t=0;t<dimen-1;t++){
			if(t==0) temp=coord[t]*size[t+1]+coord[t+1];
			else temp=temp*size[t+1]+coord[t+1];
		}
		return p[temp];
	}
	private:
	std::vector<int> size;
	double *p;
};
