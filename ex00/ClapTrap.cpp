/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:49:59 by jgo               #+#    #+#             */
/*   Updated: 2023/05/12 20:36:13 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: name_("default"),
	  hit_points_(10),
	  energy_points_(10),
	  attack_damage_(0),
	  init_hit_points_(10),
	  init_energy_points_(10),
	  init_attack_damage_(0){};

ClapTrap::ClapTrap(const std::string name)
	: name_(name),
	  hit_points_(10),
	  energy_points_(10),
	  attack_damage_(0),
	  init_hit_points_(10),
	  init_energy_points_(10),
	  init_attack_damage_(0){};

ClapTrap::ClapTrap(const ClapTrap& obj)
	: init_hit_points_(10), init_energy_points_(10), init_attack_damage_(0) {
	*this = obj;
}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->getName() << ": destruction... boom!"
			  << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& inst) {
	if (this != &inst) {
		this->name_ = inst.getName();
		this->energy_points_ = inst.getEnergyPoints();
		this->attack_damage_ = inst.getAttackDamage();
		this->hit_points_ = inst.getHitPoints();
	}
	return (*this);
}

std::string ClapTrap::getName(void) const {
	return (this->name_);
}
unsigned int ClapTrap::getHitPoints(void) const {
	return (this->hit_points_);
}
unsigned int ClapTrap::getEnergyPoints(void) const {
	return (this->energy_points_);
}
unsigned int ClapTrap::getAttackDamage(void) const {
	return (this->attack_damage_);
}

unsigned int ClapTrap::getInitHitPoints(void) const {
	return (this->init_hit_points_);
};
unsigned int ClapTrap::getInitEnergyPoints(void) const {
	return (this->init_energy_points_);
};
unsigned int ClapTrap::getInitAttackDamage(void) const {
	return (this->init_attack_damage_);
};

void ClapTrap::attack(const std::string& target) {
	if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0) {
		std::cout << "ClapTrap" << this->getName() << ": can't attack "
				  << target << " because out of hp/ep points" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "ClapTrap " << this->getName() << " attacks" << target
			  << ", causing " << this->getAttackDamage() << " points of damage!"
			  << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0) {
		std::cout << "ClapTrap " << this->getName() << ": can't repair "
				  << "because out of hp/ep points" << std::endl;
		return;
	}
	const unsigned int prev_amount = amount;
	this->energy_points_--;
	if (this->hit_points_ + amount > this->getInitHitPoints())
		this->hit_points_ = this->getInitHitPoints();
	else
		this->hit_points_ += amount;
	std::cout << "ClapTrap" << this->getName() << ":repair"
			  << amount - prev_amount << "points" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHitPoints() == 0) {
		std::cout << "there's no reaction...." << this->getName()
				  << "may be it just died" << std::endl;
		return;
	}
	std::cout << "ClapTrap" << this->getName() << "take " << amount << "damage";
	if (this->hit_points_ <= amount)
		std::cout << "boom!!" << std::endl;
	else
		std::cout << "ouch!!" << std::endl;
}

void prtStatus(void) const {
};