#include "Dessinable.h"

	Dessinable:: ~Dessinable() = default;
	Dessinable:: Dessinable(Dessinable const&)=default;
	Dessinable& Dessinable:: operator=(Dessinable const&) =default;
	Dessinable:: Dessinable(Dessinable&&)                 = default; 
	Dessinable& Dessinable::operator=(Dessinable&&)      = default;
