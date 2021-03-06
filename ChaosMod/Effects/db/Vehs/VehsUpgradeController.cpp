#include <stdafx.h>

static void OnStartMaxUpgrades()
{
	int count = 5;

	for (Vehicle veh : GetAllVehs())
	{
		SET_VEHICLE_MOD_KIT(veh, 0);
		for (int i = 0; i < 50; i++)
		{
			int max = GET_NUM_VEHICLE_MODS(veh, i);
			SET_VEHICLE_MOD(veh, i, max > 0 ? max - 1 : 0, true);

			TOGGLE_VEHICLE_MOD(veh, i, true);
		}

		SET_VEHICLE_TYRES_CAN_BURST(veh, false);
		SET_VEHICLE_WINDOW_TINT(veh, 1);

		if (--count == 0)
		{
			count = 5;

			WAIT(0);
		}
	}
}

static RegisterEffect registerEffect(EFFECT_VEH_MAX_UPGRADES, OnStartMaxUpgrades);

static void OnStartRandomUpgrades()
{
	int count = 5;

	for (Vehicle veh : GetAllVehs())
	{
		SET_VEHICLE_MOD_KIT(veh, 0);
		for (int i = 0; i < 50; i++)
		{
			int max = GET_NUM_VEHICLE_MODS(veh, i);
			SET_VEHICLE_MOD(veh, i, max > 0 ? g_random.GetRandomInt(0, max - 1) : 0, g_random.GetRandomInt(0, 1));

			TOGGLE_VEHICLE_MOD(veh, i, g_random.GetRandomInt(0, 1));
		}

		SET_VEHICLE_TYRES_CAN_BURST(veh, g_random.GetRandomInt(0, 1));
		SET_VEHICLE_WINDOW_TINT(veh, g_random.GetRandomInt(0, 6));

		SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, g_random.GetRandomInt(0, 255), g_random.GetRandomInt(0, 255), g_random.GetRandomInt(0, 255));
		SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, g_random.GetRandomInt(0, 255), g_random.GetRandomInt(0, 255), g_random.GetRandomInt(0, 255));

		if (--count == 0)
		{
			count = 5;

			WAIT(0);
		}
	}
}

static RegisterEffect registerEffect2(EFFECT_VEH_RANDOM_UPGRADES, OnStartRandomUpgrades);