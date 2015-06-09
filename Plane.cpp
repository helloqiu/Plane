#include "Plane.h"
Plane::Plane(int type){
	this->type = type;
}
void fire(){
	firer->fire(this->getPosititon());
}
int Plane::getType(){
	return type;
}
void Plane::setFirer(Firer &firer){
	this->firer = &firer;
}