Number changebase (Number a , int base, int precision){
	int temp =0; 
	if (a.exp<0){
		temp=-1*a.exp;
	}
	//making only number base
	Number posbase , negbase ,tempbase;
	posbase=getbase(base);
	tempbase=posbase;
	//posbase.dts.push_back(base);
	//making only number 1
	Number one ;
	one.dts.push_back(1);
	//omly number 1/base;
	negbase=Div(one, posbase, precision,10);
	
	//calulating before decimal
	Number bef_dec;
	//bef_dec.dts.push_back(0);
	// calculating before decimal part ;
	for(int i = temp-1 ; i>=0 ; i--){
		Number x ;
		x.dts.clear();
		x.dts.push_back(a.dts[i]);
		Number t=Mul(negbase ,x,10);
		bef_dec=Add(bef_dec,t,10);
		posbase=Mul(tempbase,posbase,10);
		negbase=Div(one,posbase,precision,10);
	}
	posbase.dts.clear();
	posbase=getbase(base);
	posbase.exp=0;
	for(int i =temp ; i<a.dts.size();i++){
		Number x;
		x.dts.clear();
		x.dts.push_back(a.dts[i]);
		Number t =Mul(one,x,10);
		bef_dec=Add(bef_dec,t,10);
		one=Mul(one,posbase,10);
	}
	return bef_dec;
}