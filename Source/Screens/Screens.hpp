#pragma once
#ifndef SCREENS_HPP_INCLUDED
#define SCREENS_HPP_INCLUDED

//Basic Screen Class
#include "ScreenBase.hpp"

//Including each screen of application
#include "ScreenMenu.hpp"
#include "ScreenGame.hpp"
#include "ScreenSettings.hpp"
#include "../Settings/Settings.hpp"

#include <iostream>
const std::string RESOURCES_PATH_PREFIX =  "Resources/";
#endif