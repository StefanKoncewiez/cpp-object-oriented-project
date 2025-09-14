#pragma once

class SupportADessin;
 
class Dessinable {
public:
//--------METHODE VIRTUELLE PURE----------------------------------------
	virtual void dessine_sur(SupportADessin&) = 0;
 
	virtual ~Dessinable();
	Dessinable(Dessinable const&);
	Dessinable& operator=(Dessinable const&);
	Dessinable(Dessinable&&);
	Dessinable& operator=(Dessinable&&);
	
	Dessinable()=default;
};
