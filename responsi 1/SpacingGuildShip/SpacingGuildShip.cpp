#include "SpacingGuildShip.hpp"
#include <iostream>

int SpacingGuildShip::producedShips = 0;
float SpacingGuildShip::totalGuildTravel = 0;

SpacingGuildShip::SpacingGuildShip() : guildNavigatorCount(3), maxPassengerCap(50), serialNum(this->producedShips + 1)
{
  this->passengerCount = 0;
  this->operatingGuildNavigator = this->guildNavigatorCount;
  this->spiceStock = 50;
  producedShips += 1;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(this->producedShips + 1)
{
  this->passengerCount = 0;
  this->spiceStock = spiceStock;
  this->operatingGuildNavigator = this->guildNavigatorCount;
  producedShips += 1;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip &newSpacingGuildShip) : maxPassengerCap(newSpacingGuildShip.maxPassengerCap), guildNavigatorCount(newSpacingGuildShip.guildNavigatorCount), serialNum(this->producedShips + 1)
{
  this->passengerCount = newSpacingGuildShip.passengerCount;
  this->operatingGuildNavigator = newSpacingGuildShip.operatingGuildNavigator;
  this->spiceStock = newSpacingGuildShip.spiceStock;
  producedShips += 1;
}

SpacingGuildShip::~SpacingGuildShip()
{
}

int SpacingGuildShip::getShipSerialNum() const
{
  return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const
{
  return this->passengerCount;
}

void SpacingGuildShip::travel(float distance)
{
  if (this->operatingGuildNavigator > 0)
  {
    totalGuildTravel += (distance / (E * E * this->operatingGuildNavigator));
    this->operatingGuildNavigator--;
  }
}

void SpacingGuildShip::boarding(int addedPassenger)
{
  int capacity = this->getPassengerCount();
  if (capacity + addedPassenger > this->maxPassengerCap)
  {
    this->passengerCount = this->maxPassengerCap;
  }
  else
  {
    this->passengerCount = capacity + addedPassenger;
  }
}

void SpacingGuildShip::dropOff(int droppedPassengers)
{
  int capacityNow = this->getPassengerCount();
  if (capacityNow - droppedPassengers < 0)
  {
    this->passengerCount = 0;
  }
  else
  {
    this->passengerCount = capacityNow - droppedPassengers;
  }
}

void SpacingGuildShip::refreshNavigator(int n)
{
  int spiceNow = this->spiceStock;
  int addedOps = n;
  while (spiceNow - addedOps * GUILD_NAVIGATOR_SPICE_DOSE < 0)
  {
    addedOps--;
  }
  this->operatingGuildNavigator += addedOps;
  this->spiceStock = spiceNow - addedOps * GUILD_NAVIGATOR_SPICE_DOSE;
}

void SpacingGuildShip::transitToArrakis(int addedSpice)
{
  this->spiceStock += addedSpice;
}