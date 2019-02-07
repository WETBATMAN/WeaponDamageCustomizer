#include <iostream>
#include <API/ARK/Ark.h>
#include <json.hpp>
#include <API/UE/Math/ColorList.h>
#include <fstream>
#include "WeaponDamageCustomizerConfig.h"
#include "WeaponDamageCustomizer.h"

#pragma comment(lib, "ArkApi.lib")
#include "json.hpp"
DECLARE_HOOK(APrimalCharacter_TakeDamage, float, APrimalCharacter*, float, FDamageEvent *, AController *, AActor *);

float  Hook_APrimalCharacter_TakeDamage(APrimalCharacter* _this, float Damage, FDamageEvent* DamageEvent, AController* EventInstigator, AActor* DamageCauser)


{
	if (EventInstigator && EventInstigator != nullptr && EventInstigator->CharacterField())
	{
		if (_this->IsA(APrimalDinoCharacter::GetPrivateStaticClass()) && _this->TargetingTeamField() < 10000)
		{
			AShooterPlayerController* AttackerShooterController = static_cast<AShooterPlayerController*>(EventInstigator);
			if (AttackerShooterController && AttackerShooterController->PlayerStateField() && AttackerShooterController->GetPlayerCharacter() && AttackerShooterController->GetPlayerCharacter()->CurrentWeaponField() && AttackerShooterController->GetPlayerCharacter()->CurrentWeaponField()->AssociatedPrimalItemField())
			{
				FString WeaponName;
				AttackerShooterController->GetPlayerCharacter()->CurrentWeaponField()->AssociatedPrimalItemField()->GetItemName(&WeaponName, false, true, nullptr);
				if (_this != nullptr && WeaponName.Contains(L"Stone Pick"))
				{
					Damage = Damage * WeaponDamageCustomizer::StonePickDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Stone Hatchet"))
				{
					Damage = Damage * WeaponDamageCustomizer::StonePickDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Metal Pick"))
				{
					Damage = Damage * WeaponDamageCustomizer::MetalPickDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Metal Hatchet"))
				{
					Damage = Damage * WeaponDamageCustomizer::MetalHatchetDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Metal Sickle"))
				{
					Damage = Damage * WeaponDamageCustomizer::MetalSickleDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Chainsaw"))
				{
					Damage = Damage * WeaponDamageCustomizer::ChainsawDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Spear"))
				{
					Damage = Damage * WeaponDamageCustomizer::SpearDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Pike"))
				{
					Damage = Damage * WeaponDamageCustomizer::PikeDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Wooden Club"))
				{
					Damage = Damage * WeaponDamageCustomizer::WoodenClubDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Sword"))
				{
					Damage = Damage * WeaponDamageCustomizer::RegularSwordDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Electric Prod"))
				{
					Damage = Damage * WeaponDamageCustomizer::ElectricProdDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Slingshot"))
				{
					Damage = Damage * WeaponDamageCustomizer::SlingshotDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Boomerang"))
				{
					Damage = Damage * WeaponDamageCustomizer::BoomerangDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Whip"))
				{
					Damage = Damage * WeaponDamageCustomizer::WhipDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Bow"))
				{
					Damage = Damage * WeaponDamageCustomizer::BowDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Crossbow"))
				{
					Damage = Damage * WeaponDamageCustomizer::CrossBowDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Compound Bow"))
				{
					Damage = Damage * WeaponDamageCustomizer::CompoundBowDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Harpoon"))
				{
					Damage = Damage * WeaponDamageCustomizer::HarpoonLauncherDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Simple Postol"))
				{
					Damage = Damage * WeaponDamageCustomizer::SimplePistolDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Longneck"))
				{
					Damage = Damage * WeaponDamageCustomizer::LongneckDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Shotgun"))
				{
					Damage = Damage * WeaponDamageCustomizer::PrimitiveShotgunDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Fabricated Pistol"))
				{
					Damage = Damage * WeaponDamageCustomizer::FabricatedPistolDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Pump-Action Shotgun"))
				{
					Damage = Damage * WeaponDamageCustomizer::PumpShotgunDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Assault Rifle"))
				{
					Damage = Damage * WeaponDamageCustomizer::AssaultRifleDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Sniper"))
				{
					Damage = Damage * WeaponDamageCustomizer::SniperRifleDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Flamethrower"))
				{
					Damage = Damage * WeaponDamageCustomizer::FlamethrowerDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Lantern"))
				{
					Damage = Damage * WeaponDamageCustomizer::ChargeLanternDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Tek Rifle"))
				{
					Damage = Damage * WeaponDamageCustomizer::TekRifleDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Tek Sword"))
				{
					Damage = Damage * WeaponDamageCustomizer::TekSwordDamageMultiplierToWild;
				}
				if (_this != nullptr && WeaponName.Contains(L"Tek Railgun"))
				{
					Damage = Damage * WeaponDamageCustomizer::TekRailgunDamageMultiplierToWild;
				}
			}
		}
		if (_this->IsA(APrimalDinoCharacter::GetPrivateStaticClass()) && _this->TargetingTeamField() > 10000)
		{
			AShooterPlayerController* AttackerShooterController = static_cast<AShooterPlayerController*>(EventInstigator);
			if (AttackerShooterController && AttackerShooterController->PlayerStateField() && AttackerShooterController->GetPlayerCharacter() && AttackerShooterController->GetPlayerCharacter()->CurrentWeaponField() && AttackerShooterController->GetPlayerCharacter()->CurrentWeaponField()->AssociatedPrimalItemField())
			{
				FString WeaponName;
				AttackerShooterController->GetPlayerCharacter()->CurrentWeaponField()->AssociatedPrimalItemField()->GetItemName(&WeaponName, false, true, nullptr);
				if (_this != nullptr && WeaponName.Contains(L"Stone Pick"))
				{
					Damage = Damage * WeaponDamageCustomizer::StonePickDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Stone Hatchet"))
				{
					Damage = Damage * WeaponDamageCustomizer::StonePickDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Metal Pick"))
				{
					Damage = Damage * WeaponDamageCustomizer::MetalPickDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Metal Hatchet"))
				{
					Damage = Damage * WeaponDamageCustomizer::MetalHatchetDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Metal Sickle"))
				{
					Damage = Damage * WeaponDamageCustomizer::MetalSickleDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Chainsaw"))
				{
					Damage = Damage * WeaponDamageCustomizer::ChainsawDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Spear"))
				{
					Damage = Damage * WeaponDamageCustomizer::SpearDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Pike"))
				{
					Damage = Damage * WeaponDamageCustomizer::PikeDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Wooden Club"))
				{
					Damage = Damage * WeaponDamageCustomizer::WoodenClubDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Sword"))
				{
					Damage = Damage * WeaponDamageCustomizer::RegularSwordDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Electric Prod"))
				{
					Damage = Damage * WeaponDamageCustomizer::ElectricProdDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Slingshot"))
				{
					Damage = Damage * WeaponDamageCustomizer::SlingshotDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Boomerang"))
				{
					Damage = Damage * WeaponDamageCustomizer::BoomerangDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Whip"))
				{
					Damage = Damage * WeaponDamageCustomizer::WhipDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Bow"))
				{
					Damage = Damage * WeaponDamageCustomizer::BowDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Crossbow"))
				{
					Damage = Damage * WeaponDamageCustomizer::CrossBowDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Compound Bow"))
				{
					Damage = Damage * WeaponDamageCustomizer::CompoundBowDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Harpoon"))
				{
					Damage = Damage * WeaponDamageCustomizer::HarpoonLauncherDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Simple Postol"))
				{
					Damage = Damage * WeaponDamageCustomizer::SimplePistolDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Longneck"))
				{
					Damage = Damage * WeaponDamageCustomizer::LongneckDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Shotgun"))
				{
					Damage = Damage * WeaponDamageCustomizer::PrimitiveShotgunDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Fabricated Pistol"))
				{
					Damage = Damage * WeaponDamageCustomizer::FabricatedPistolDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Pump-Action Shotgun"))
				{
					Damage = Damage * WeaponDamageCustomizer::PumpShotgunDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Assault Rifle"))
				{
					Damage = Damage * WeaponDamageCustomizer::AssaultRifleDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Sniper"))
				{
					Damage = Damage * WeaponDamageCustomizer::SniperRifleDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Flamethrower"))
				{
					Damage = Damage * WeaponDamageCustomizer::FlamethrowerDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Lantern"))
				{
					Damage = Damage * WeaponDamageCustomizer::ChargeLanternDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Tek Rifle"))
				{
					Damage = Damage * WeaponDamageCustomizer::TekRifleDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Tek Sword"))
				{
					Damage = Damage * WeaponDamageCustomizer::TekSwordDamageMultiplierToTamed;
				}
				if (_this != nullptr && WeaponName.Contains(L"Tek Railgun"))
				{
					Damage = Damage * WeaponDamageCustomizer::TekRailgunDamageMultiplierToTamed;
				}
			}
		}
		if (_this->IsA(AShooterCharacter::GetPrivateStaticClass()))
		{
			AShooterPlayerController* AttackerShooterController = static_cast<AShooterPlayerController*>(EventInstigator);
			if (AttackerShooterController && AttackerShooterController->PlayerStateField() && AttackerShooterController->GetPlayerCharacter() && AttackerShooterController->GetPlayerCharacter()->CurrentWeaponField() && AttackerShooterController->GetPlayerCharacter()->CurrentWeaponField()->AssociatedPrimalItemField())
			{
				FString WeaponName;
				AttackerShooterController->GetPlayerCharacter()->CurrentWeaponField()->AssociatedPrimalItemField()->GetItemName(&WeaponName, false, true, nullptr);
				if (_this != nullptr && WeaponName.Contains(L"Stone Pick"))
				{
					Damage = Damage * WeaponDamageCustomizer::StonePickDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Stone Hatchet"))
				{
					Damage = Damage * WeaponDamageCustomizer::StonePickDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Metal Pick"))
				{
					Damage = Damage * WeaponDamageCustomizer::MetalPickDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Metal Hatchet"))
				{
					Damage = Damage * WeaponDamageCustomizer::MetalHatchetDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Metal Sickle"))
				{
					Damage = Damage * WeaponDamageCustomizer::MetalSickleDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Chainsaw"))
				{
					Damage = Damage * WeaponDamageCustomizer::ChainsawDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Spear"))
				{
					Damage = Damage * WeaponDamageCustomizer::SpearDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Pike"))
				{
					Damage = Damage * WeaponDamageCustomizer::PikeDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Wooden Club"))
				{
					Damage = Damage * WeaponDamageCustomizer::WoodenClubDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Sword"))
				{
					Damage = Damage * WeaponDamageCustomizer::RegularSwordDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Electric Prod"))
				{
					Damage = Damage * WeaponDamageCustomizer::ElectricProdDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Slingshot"))
				{
					Damage = Damage * WeaponDamageCustomizer::SlingshotDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Boomerang"))
				{
					Damage = Damage * WeaponDamageCustomizer::BoomerangDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Whip"))
				{
					Damage = Damage * WeaponDamageCustomizer::WhipDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Bow"))
				{
					Damage = Damage * WeaponDamageCustomizer::BowDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Crossbow"))
				{
					Damage = Damage * WeaponDamageCustomizer::CrossBowDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Compound Bow"))
				{
					Damage = Damage * WeaponDamageCustomizer::CompoundBowDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Harpoon"))
				{
					Damage = Damage * WeaponDamageCustomizer::HarpoonLauncherDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Simple Postol"))
				{
					Damage = Damage * WeaponDamageCustomizer::SimplePistolDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Longneck"))
				{
					Damage = Damage * WeaponDamageCustomizer::LongneckDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Shotgun"))
				{
					Damage = Damage * WeaponDamageCustomizer::PrimitiveShotgunDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Fabricated Pistol"))
				{
					Damage = Damage * WeaponDamageCustomizer::FabricatedPistolDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Pump-Action Shotgun"))
				{
					Damage = Damage * WeaponDamageCustomizer::PumpShotgunDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Assault Rifle"))
				{
					Damage = Damage * WeaponDamageCustomizer::AssaultRifleDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Sniper"))
				{
					Damage = Damage * WeaponDamageCustomizer::SniperRifleDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Flamethrower"))
				{
					Damage = Damage * WeaponDamageCustomizer::FlamethrowerDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Lantern"))
				{
					Damage = Damage * WeaponDamageCustomizer::ChargeLanternDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Tek Rifle"))
				{
					Damage = Damage * WeaponDamageCustomizer::TekRifleDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Tek Sword"))
				{
					Damage = Damage * WeaponDamageCustomizer::TekSwordDamageMultiplierToPlayer;
				}
				if (_this != nullptr && WeaponName.Contains(L"Tek Railgun"))
				{
					Damage = Damage * WeaponDamageCustomizer::TekRailgunDamageMultiplierToPlayer;
				}
			}
		}
	}
	return APrimalCharacter_TakeDamage_original(_this, Damage, DamageEvent, EventInstigator, DamageCauser);
}

void Load()
{
	Log::Get().Init("WeaponDamageCustomizer");

	try
	{
		ReadConfig();
	}
	catch (const std::exception& error)
	{
		Log::GetLog()->error(error.what());
		throw;
	}
	ArkApi::GetCommands().AddConsoleCommand("WeaponDamageCustomizer.Reload", &ReloadConfig);
	ArkApi::GetCommands().AddRconCommand("WeaponDamageCustomizer.Reload", &ReloadConfigRcon);
	ArkApi::GetHooks().SetHook("APrimalCharacter.TakeDamage", &Hook_APrimalCharacter_TakeDamage, &APrimalCharacter_TakeDamage_original);
}

void Unload()
{
	ArkApi::GetCommands().RemoveConsoleCommand("WeaponDamageCustomizer.Reload");
	ArkApi::GetCommands().RemoveRconCommand("WeaponDamageCustomizer.Reload");
	ArkApi::GetHooks().DisableHook("APrimalCharacter.TakeDamage", &Hook_APrimalCharacter_TakeDamage);
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Load();
		break;
	case DLL_PROCESS_DETACH:
		Unload();
		break;
	}
	return TRUE;
}