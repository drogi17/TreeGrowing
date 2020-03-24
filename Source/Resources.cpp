#include "Resources.h"

Resources::Resources () {
	water = 0.f;
	energy = 0.f;
	materials = 0.f;
}

Resources::Resources (float w, float e, float m) {
	water = w;
	energy = e;
	materials = m;
}

Resources Resources::add (Resources res) {
	water += res.water;
	energy += res.energy;
	materials += res.materials;
	return *this; 
}

Resources Resources::subtract (Resources res) {
	Resources temp;
	if (water - res.water < 0.f) {
		temp.water = water;
		water = 0.f;
	} else {
		temp.water = res.water;
		water -= res.water;
	}
	if (energy - res.energy < 0.f) {
		temp.energy = energy;
		energy = 0.f;
	} else {
		temp.energy = res.energy;
		energy -= res.energy;
	}
	if (materials - res.materials < 0.f) {
		temp.materials = materials;
		materials = 0.f;
	} else {
		temp.materials = res.materials;
		materials -= res.materials;
	}
	return temp;
}

Resources Resources::multiply (float k) {
	Resources temp;
	temp.water = water * k;
	temp.energy = energy * k;
	temp.materials = materials * k;
	return temp;
}

bool Resources::check_capacity (Resources res) {
	if (water - res.water < 0.f) return false;
	if (energy - res.energy < 0.f) return false;
	if (materials - res.materials < 0.f) return false;
	return true;
}



