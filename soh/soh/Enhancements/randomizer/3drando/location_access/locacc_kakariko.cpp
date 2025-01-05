#include "../location_access.hpp"
#include "../../entrance.h"

using namespace Rando;

void RegionTable_Init_Kakariko() {
  areaTable[RR_KAKARIKO_VILLAGE] = Region("Kakariko Village", "Kakariko Village", {RA_KAKARIKO_VILLAGE}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->BugRock,                 {[]{return true;}}),
                  //Open Gate setting is applies in RR_ROOT
                  EventAccess(&logic->KakarikoVillageGateOpen, {[]{return logic->IsChild && logic->HasItem(RG_ZELDAS_LETTER);}}),
                }, {
                  //Locations
                  LOCATION(RC_SHEIK_IN_KAKARIKO,               logic->IsAdult && logic->HasItem(RG_FOREST_MEDALLION) && logic->HasItem(RG_FIRE_MEDALLION) && logic->HasItem(RG_WATER_MEDALLION)),
                  LOCATION(RC_KAK_ANJU_AS_CHILD,               logic->IsChild && logic->AtDay),
                  LOCATION(RC_KAK_ANJU_AS_ADULT,               logic->IsAdult && logic->AtDay),
                  LOCATION(RC_KAK_TRADE_POCKET_CUCCO,          logic->IsAdult && logic->AtDay && (logic->CanUse(RG_POCKET_EGG) && logic->WakeUpAdultTalon)),
                  //Can kill lower kak skulls with pots
                  LOCATION(RC_KAK_GS_HOUSE_UNDER_CONSTRUCTION, logic->IsChild && logic->CanGetNightTimeGS()),
                  LOCATION(RC_KAK_GS_SKULLTULA_HOUSE,          logic->IsChild && logic->CanGetNightTimeGS()),
                  LOCATION(RC_KAK_GS_GUARDS_HOUSE,             logic->IsChild && logic->CanGetNightTimeGS()),
                  LOCATION(RC_KAK_GS_TREE,                     logic->IsChild && logic->CanGetNightTimeGS()),
                  LOCATION(RC_KAK_GS_WATCHTOWER,               logic->IsChild && (logic->CanKillEnemy(RE_GOLD_SKULLTULA, ED_LONGSHOT) || (ctx->GetTrickOption(RT_KAK_TOWER_GS) && logic->CanJumpslashExceptHammer())) && logic->CanGetNightTimeGS()),
                  LOCATION(RC_KAK_NEAR_POTION_SHOP_POT_1,      logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_POTION_SHOP_POT_2,      logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_POTION_SHOP_POT_3,      logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_IMPAS_HOUSE_POT_1,      logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_IMPAS_HOUSE_POT_2,      logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_IMPAS_HOUSE_POT_3,      logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_GUARDS_HOUSE_POT_1,     logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_GUARDS_HOUSE_POT_2,     logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_GUARDS_HOUSE_POT_3,     logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_MEDICINE_SHOP_POT_1,    logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_MEDICINE_SHOP_POT_2,    logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_TREE, logic->IsChild && logic->CanBonkTrees()),
                }, {
                  //Exits
                  Entrance(RR_HYRULE_FIELD,             {[]{return true;}}),
                  Entrance(RR_KAK_CARPENTER_BOSS_HOUSE, {[]{return true;}}),
                  Entrance(RR_KAK_HOUSE_OF_SKULLTULA,   {[]{return true;}}),
                  Entrance(RR_KAK_IMPAS_HOUSE,          {[]{return true;}}),
                  Entrance(RR_KAK_WINDMILL,             {[]{return true;}}),
                  Entrance(RR_KAK_BAZAAR,               {[]{return logic->IsAdult && logic->AtDay;}}),
                  Entrance(RR_KAK_SHOOTING_GALLERY,     {[]{return logic->IsAdult && logic->AtDay;}}),
                  Entrance(RR_KAK_WELL,                 {[]{return logic->IsAdult || logic->DrainWell || logic->CanUse(RG_IRON_BOOTS);}}),
                  Entrance(RR_KAK_POTION_SHOP_FRONT,    {[]{return logic->AtDay || logic->IsChild;}}),
                  Entrance(RR_KAK_REDEAD_GROTTO,        {[]{return logic->CanOpenBombGrotto();}}),
                  Entrance(RR_KAK_IMPAS_LEDGE,          {[]{return (logic->IsChild && logic->AtDay) || (logic->IsAdult && ctx->GetTrickOption(RT_VISIBLE_COLLISION));}}),
                  Entrance(RR_KAK_WATCHTOWER,           {[]{return logic->IsAdult || logic->AtDay || logic->CanKillEnemy(RE_GOLD_SKULLTULA, ED_LONGSHOT) || (ctx->GetTrickOption(RT_KAK_TOWER_GS) && logic->CanJumpslashExceptHammer());}}),
                  Entrance(RR_KAK_ROOFTOP,              {[]{return logic->CanUse(RG_HOOKSHOT) || (ctx->GetTrickOption(RT_KAK_MAN_ON_ROOF) && logic->IsAdult);}}),
                  Entrance(RR_KAK_IMPAS_ROOFTOP,        {[]{return logic->CanUse(RG_HOOKSHOT) || (ctx->GetTrickOption(RT_KAK_ROOFTOP_GS) && logic->CanUse(RG_HOVER_BOOTS));}}),
                  Entrance(RR_THE_GRAVEYARD,            {[]{return true;}}),
                  Entrance(RR_KAK_BEHIND_GATE,          {[]{return logic->IsAdult || logic->KakarikoVillageGateOpen;}}),
                  //adult can jump from the fence near the windmill to ledgegrab the fence near granny's shop. is in logic on N64
                  Entrance(RR_KAK_BACKYARD,             {[]{return logic->IsAdult || logic->AtDay;}}),
  });

  areaTable[RR_KAK_IMPAS_LEDGE] = Region("Kak Impas Ledge", "Kakariko Village", {RA_KAKARIKO_VILLAGE}, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(RR_KAK_IMPAS_HOUSE_BACK, {[]{return true;}}),
                  Entrance(RR_KAKARIKO_VILLAGE,     {[]{return true;}}),
  });

  areaTable[RR_KAK_IMPAS_ROOFTOP] = Region("Kak Impas Rooftop", "Kakariko Village", {RA_KAKARIKO_VILLAGE}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_KAK_GS_ABOVE_IMPAS_HOUSE, logic->IsAdult && logic->CanGetNightTimeGS() && logic->CanKillEnemy(RE_GOLD_SKULLTULA)),
                }, {
                  //Exits
                  Entrance(RR_KAK_IMPAS_LEDGE,  {[]{return true;}}),
                  Entrance(RR_KAKARIKO_VILLAGE, {[]{return true;}}),
  });

  areaTable[RR_KAK_WATCHTOWER] = Region("Kak Watchtower", "Kakariko Village", {RA_KAKARIKO_VILLAGE}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  //exists for when age change is in logic.
                  LOCATION(RC_KAK_GS_WATCHTOWER, logic->IsChild && logic->CanUse(RG_DINS_FIRE) && logic->CanGetNightTimeGS()),
                }, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE, {[]{return true;}}),
                  Entrance(RR_KAK_ROOFTOP,      {[]{return ctx->GetTrickOption(RT_KAK_MAN_ON_ROOF) && logic->IsChild;}}),
  });

  areaTable[RR_KAK_ROOFTOP] = Region("Kak Rooftop", "Kakariko Village", {RA_KAKARIKO_VILLAGE}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_KAK_MAN_ON_ROOF, true),
                }, {
                  //Exits
                  Entrance(RR_KAK_BACKYARD,     {[]{return true;}}),
                  Entrance(RR_KAKARIKO_VILLAGE, {[]{return true;}}),
  });

  areaTable[RR_KAK_BACKYARD] = Region("Kak Backyard", "Kakariko Village", {RA_KAKARIKO_VILLAGE}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  //There's probably a trick to get these with rang from the main region
                  LOCATION(RC_KAK_NEAR_MEDICINE_SHOP_POT_1,    logic->IsChild && logic->CanBreakPots()),
                  LOCATION(RC_KAK_NEAR_MEDICINE_SHOP_POT_2,    logic->IsChild && logic->CanBreakPots()),
              }, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE,          {[]{return true;}}),
                  Entrance(RR_KAK_OPEN_GROTTO,           {[]{return true;}}),
                  Entrance(RR_KAK_ODD_POTION_BUILDING,   {[]{return logic->IsAdult;}}),
                  Entrance(RR_KAK_POTION_SHOP_BACK,      {[]{return logic->IsAdult && logic->AtDay;}}),
  });

  areaTable[RR_KAK_CARPENTER_BOSS_HOUSE] = Region("Kak Carpenter Boss House", "Kak Carpenter Boss House", {}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->WakeUpAdultTalon, {[]{return logic->IsAdult && logic->CanUse(RG_POCKET_EGG);}}),
                }, {}, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE, {[]{return true;}}),
  });

  areaTable[RR_KAK_HOUSE_OF_SKULLTULA] = Region("Kak House of Skulltula", "Kak House of Skulltula", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_KAK_10_GOLD_SKULLTULA_REWARD,  logic->GetGSCount() >= 10),
                  LOCATION(RC_KAK_20_GOLD_SKULLTULA_REWARD,  logic->GetGSCount() >= 20),
                  LOCATION(RC_KAK_30_GOLD_SKULLTULA_REWARD,  logic->GetGSCount() >= 30),
                  LOCATION(RC_KAK_40_GOLD_SKULLTULA_REWARD,  logic->GetGSCount() >= 40),
                  LOCATION(RC_KAK_50_GOLD_SKULLTULA_REWARD,  logic->GetGSCount() >= 50),
                  LOCATION(RC_KAK_100_GOLD_SKULLTULA_REWARD, logic->GetGSCount() >= 100)
                }, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE, {[]{return true;}}),
  });

  areaTable[RR_KAK_IMPAS_HOUSE] = Region("Kak Impas House", "Kak Impas House", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_KAK_IMPAS_HOUSE_COW, logic->CanUse(RG_EPONAS_SONG))
                }, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE, {[]{return true;}}),
  });

  areaTable[RR_KAK_IMPAS_HOUSE_BACK] = Region("Kak Impas House Back", "Kak Impas House", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_KAK_IMPAS_HOUSE_FREESTANDING_POH, true),
                  LOCATION(RC_KAK_IMPAS_HOUSE_COW,              logic->CanUse(RG_EPONAS_SONG))
                }, {
                  //Exits
                  Entrance(RR_KAK_IMPAS_LEDGE, {[]{return true;}}),
  });

  areaTable[RR_KAK_WINDMILL] = Region("Kak Windmill", "Windmill and Dampes Grave", {}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->DrainWell, {[]{return logic->DrainWell || (logic->IsChild && logic->CanUse(RG_SONG_OF_STORMS));}}),
                }, {
                  //Locations
                  LOCATION(RC_KAK_WINDMILL_FREESTANDING_POH, logic->CanUse(RG_BOOMERANG) || logic->DampesWindmillAccess || (logic->IsAdult && ctx->GetTrickOption(RT_KAK_ADULT_WINDMILL_POH)) || (logic->IsChild && logic->CanJumpslashExceptHammer() && ctx->GetTrickOption(RT_KAK_CHILD_WINDMILL_POH))),
                  LOCATION(RC_SONG_FROM_WINDMILL,            logic->IsAdult && logic->HasItem(RG_FAIRY_OCARINA)),
                }, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE, {[]{return true;}}),
  });

  areaTable[RR_KAK_BAZAAR] = Region("Kak Bazaar", "Kak Bazaar", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_KAK_BAZAAR_ITEM_1, true),
                  LOCATION(RC_KAK_BAZAAR_ITEM_2, true),
                  LOCATION(RC_KAK_BAZAAR_ITEM_3, true),
                  LOCATION(RC_KAK_BAZAAR_ITEM_4, true),
                  LOCATION(RC_KAK_BAZAAR_ITEM_5, true),
                  LOCATION(RC_KAK_BAZAAR_ITEM_6, true),
                  LOCATION(RC_KAK_BAZAAR_ITEM_7, true),
                  LOCATION(RC_KAK_BAZAAR_ITEM_8, true),
                }, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE, {[]{return true;}}),
  });

  areaTable[RR_KAK_SHOOTING_GALLERY] = Region("Kak Shooting Gallery", "Kak Shooting Gallery", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_KAK_SHOOTING_GALLERY_REWARD, logic->HasItem(RG_CHILD_WALLET) && logic->IsAdult && logic->CanUse(RG_FAIRY_BOW)),
                }, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE, {[]{return true;}}),
  });

  areaTable[RR_KAK_POTION_SHOP_FRONT] = Region("Kak Potion Shop Front", "Kak Potion Shop", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_KAK_POTION_SHOP_ITEM_1, logic->IsAdult),
                  LOCATION(RC_KAK_POTION_SHOP_ITEM_2, logic->IsAdult),
                  LOCATION(RC_KAK_POTION_SHOP_ITEM_3, logic->IsAdult),
                  LOCATION(RC_KAK_POTION_SHOP_ITEM_4, logic->IsAdult),
                  LOCATION(RC_KAK_POTION_SHOP_ITEM_5, logic->IsAdult),
                  LOCATION(RC_KAK_POTION_SHOP_ITEM_6, logic->IsAdult),
                  LOCATION(RC_KAK_POTION_SHOP_ITEM_7, logic->IsAdult),
                  LOCATION(RC_KAK_POTION_SHOP_ITEM_8, logic->IsAdult),
                }, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE,     {[]{return true;}}),
                  Entrance(RR_KAK_POTION_SHOP_BACK, {[]{return logic->IsAdult;}}),
  });

  areaTable[RR_KAK_POTION_SHOP_BACK] = Region("Kak Potion Shop Back", "Kak Potion Shop", {}, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(RR_KAK_BACKYARD,          {[]{return logic->IsAdult;}}),
                  Entrance(RR_KAK_POTION_SHOP_FRONT, {[]{return true;}}),
  });

  areaTable[RR_KAK_ODD_POTION_BUILDING] =
      Region("Kak Granny's Potion Shop", "Kak Granny's Potion Shop", {}, NO_DAY_NIGHT_CYCLE, {},
           // RANDOTODO blue pot access
           {
               LOCATION(RC_KAK_TRADE_ODD_MUSHROOM, logic->IsAdult && logic->CanUse(RG_ODD_MUSHROOM)),
               LOCATION(RC_KAK_GRANNYS_SHOP, logic->IsAdult && (logic->CanUse(RG_ODD_MUSHROOM) || logic->TradeQuestStep(RG_ODD_MUSHROOM))),
           },
           {
              // Exits
              Entrance(RR_KAK_BACKYARD, { [] { return true; } }),
           });

  areaTable[RR_KAK_REDEAD_GROTTO] = Region("Kak Redead Grotto", "Kak Redead Grotto", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_KAK_REDEAD_GROTTO_CHEST, logic->CanUse(RG_STICKS) || logic->CanUse(RG_KOKIRI_SWORD) || logic->CanUse(RG_DINS_FIRE) || logic->CanUse(RG_MEGATON_HAMMER) || logic->CanUse(RG_MASTER_SWORD) || logic->CanUse(RG_BIGGORON_SWORD)),
                }, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE, {[]{return true;}}),
  });

  areaTable[RR_KAK_OPEN_GROTTO] = Region("Kak Open Grotto", "Kak Open Grotto", {}, NO_DAY_NIGHT_CYCLE, grottoEvents, {
                  //Locations
                  LOCATION(RC_KAK_OPEN_GROTTO_CHEST,         true),
                  LOCATION(RC_KAK_OPEN_GROTTO_FISH,          logic->HasBottle()),
                  LOCATION(RC_KAK_OPEN_GROTTO_GOSSIP_STONE,  true),
                  LOCATION(RC_KAK_OPEN_GROTTO_BEEHIVE_LEFT,  logic->CanBreakLowerBeehives()),
                  LOCATION(RC_KAK_OPEN_GROTTO_BEEHIVE_RIGHT, logic->CanBreakLowerBeehives()),
                }, {
                  //Exits
                  Entrance(RR_KAK_BACKYARD, {[]{return true;}}),
  });

  areaTable[RR_KAK_BEHIND_GATE] = Region("Kak Behind Gate", "Kakariko Village", {RA_KAKARIKO_VILLAGE}, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE,     {[]{return logic->IsAdult || ctx->GetTrickOption(RT_VISIBLE_COLLISION) || logic->KakarikoVillageGateOpen;}}),
                  Entrance(RR_DEATH_MOUNTAIN_TRAIL, {[]{return true;}}),
  });

  areaTable[RR_KAK_WELL] = Region("Kak Behind Gate", "Kakariko Village", {RA_KAKARIKO_VILLAGE}, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(RR_KAKARIKO_VILLAGE,            {[]{return logic->IsAdult || logic->HasItem(RG_BRONZE_SCALE) || logic->DrainWell;}}),
                  Entrance(RR_BOTTOM_OF_THE_WELL_ENTRYWAY, {[]{return logic->IsChild || (logic->DrainWell && ctx->GetOption(RSK_SHUFFLE_DUNGEON_ENTRANCES).IsNot(RO_DUNGEON_ENTRANCE_SHUFFLE_OFF));}}),
  });

  areaTable[RR_THE_GRAVEYARD] = Region("The Graveyard", "The Graveyard", {RA_THE_GRAVEYARD}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->ButterflyFairy, {[]{return logic->ButterflyFairy || (logic->CanUse(RG_STICKS) && logic->AtDay);}}),
                  EventAccess(&logic->BeanPlantFairy, {[]{return logic->BeanPlantFairy || (CanPlantBean(RR_THE_GRAVEYARD) && logic->CanUse(RG_SONG_OF_STORMS));}}),
                  EventAccess(&logic->BugRock,        {[]{return true;}}),
                }, {
                  //Locations
                  LOCATION(RC_GRAVEYARD_FREESTANDING_POH,        (logic->IsAdult && CanPlantBean(RR_THE_GRAVEYARD)) || logic->CanUse(RG_LONGSHOT) || (ctx->GetTrickOption(RT_GY_POH) && logic->CanUse(RG_BOOMERANG))),
                  LOCATION(RC_GRAVEYARD_DAMPE_GRAVEDIGGING_TOUR, logic->HasItem(RG_CHILD_WALLET) && logic->IsChild && logic->AtNight), //TODO: This needs to change
                  LOCATION(RC_GRAVEYARD_GS_WALL,                 logic->IsChild && logic->HookshotOrBoomerang() && logic->CanGetNightTimeGS()),
                  LOCATION(RC_GRAVEYARD_GS_BEAN_PATCH,           logic->CanSpawnSoilSkull() && logic->CanAttack()),
                }, {
                  //Exits
                  Entrance(RR_GRAVEYARD_SHIELD_GRAVE,       {[]{return logic->IsAdult || logic->AtNight;}}),
                  Entrance(RR_GRAVEYARD_COMPOSERS_GRAVE,    {[]{return logic->CanUse(RG_ZELDAS_LULLABY);}}),
                  Entrance(RR_GRAVEYARD_HEART_PIECE_GRAVE,  {[]{return logic->IsAdult || logic->AtNight;}}),
                  Entrance(RR_GRAVEYARD_DAMPES_GRAVE,       {[]{return logic->IsAdult;}}),
                  Entrance(RR_GRAVEYARD_DAMPES_HOUSE,       {[]{return logic->IsAdult /*|| logic->AtDampeTime*/;}}), //TODO: This needs to be handled in ToD rework
                  Entrance(RR_KAKARIKO_VILLAGE,             {[]{return true;}}),
                  Entrance(RR_GRAVEYARD_WARP_PAD_REGION,    {[]{return false;}}),
  });

  areaTable[RR_GRAVEYARD_SHIELD_GRAVE] = Region("Graveyard Shield Grave", "Graveyard Shield Grave", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GRAVEYARD_SHIELD_GRAVE_CHEST, true),
                  //Free Fairies
                }, {
                  //Exits
                  Entrance(RR_THE_GRAVEYARD, {[]{return true;}}),
  });

  areaTable[RR_GRAVEYARD_HEART_PIECE_GRAVE] = Region("Graveyard Heart Piece Grave", "Graveyard Heart Piece Grave", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GRAVEYARD_HEART_PIECE_GRAVE_CHEST, logic->CanUse(RG_SUNS_SONG)),
                }, {
                  //Exits
                  Entrance(RR_THE_GRAVEYARD, {[]{return true;}}),
  });

  areaTable[RR_GRAVEYARD_COMPOSERS_GRAVE] = Region("Graveyard Composers Grave", "Graveyard Composers Grave", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GRAVEYARD_ROYAL_FAMILYS_TOMB_CHEST, logic->HasFireSource()),
                  LOCATION(RC_SONG_FROM_ROYAL_FAMILYS_TOMB,       logic->CanUseProjectile() || logic->CanJumpslash()),
                }, {
                  //Exits
                  Entrance(RR_THE_GRAVEYARD, {[]{return true;}}),
  });

  areaTable[RR_GRAVEYARD_DAMPES_GRAVE] = Region("Graveyard Dampes Grave", "Windmill and Dampes Grave", {}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->NutPot,               {[]{return true;}}),
                  EventAccess(&logic->DampesWindmillAccess, {[]{return logic->DampesWindmillAccess || (logic->IsAdult && logic->CanUse(RG_SONG_OF_TIME));}}),
                }, {
                  //Locations
                  LOCATION(RC_GRAVEYARD_HOOKSHOT_CHEST,              true),
                  LOCATION(RC_GRAVEYARD_DAMPE_RACE_FREESTANDING_POH, logic->IsAdult || ctx->GetTrickOption(RT_GY_CHILD_DAMPE_RACE_POH)),
                  LOCATION(RC_GY_DAMPES_GRAVE_POT_1,                 logic->CanBreakPots()),
                  LOCATION(RC_GY_DAMPES_GRAVE_POT_2,                 logic->CanBreakPots()),
                  LOCATION(RC_GY_DAMPES_GRAVE_POT_3,                 logic->CanBreakPots()),
                  LOCATION(RC_GY_DAMPES_GRAVE_POT_4,                 logic->CanBreakPots()),
                  LOCATION(RC_GY_DAMPES_GRAVE_POT_5,                 logic->CanBreakPots()),
                  LOCATION(RC_GY_DAMPES_GRAVE_POT_6,                 logic->CanBreakPots()),
                  LOCATION(RC_GRAVEYARD_DAMPE_RACE_RUPEE_1,          true),
                  LOCATION(RC_GRAVEYARD_DAMPE_RACE_RUPEE_2,          true),
                  LOCATION(RC_GRAVEYARD_DAMPE_RACE_RUPEE_3,          true),
                  LOCATION(RC_GRAVEYARD_DAMPE_RACE_RUPEE_4,          true),
                  LOCATION(RC_GRAVEYARD_DAMPE_RACE_RUPEE_5,          true),
                  LOCATION(RC_GRAVEYARD_DAMPE_RACE_RUPEE_6,          true),
                  LOCATION(RC_GRAVEYARD_DAMPE_RACE_RUPEE_7,          true),
                  LOCATION(RC_GRAVEYARD_DAMPE_RACE_RUPEE_8,          true),
                }, {
                  //Exits
                  Entrance(RR_THE_GRAVEYARD, {[]{return true;}}),
                  Entrance(RR_KAK_WINDMILL,  {[]{return logic->IsAdult && logic->CanUse(RG_SONG_OF_TIME);}}, false),
  });

  areaTable[RR_GRAVEYARD_DAMPES_HOUSE] = Region("Graveyard Dampes House", "Graveyard Dampes House", {}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_DAMPE_HINT, logic->IsAdult),
                }, {
                  //Exits
                  Entrance(RR_THE_GRAVEYARD, {[]{return true;}}),
  });

  areaTable[RR_GRAVEYARD_WARP_PAD_REGION] = Region("Graveyard Warp Pad Region", "Graveyard", {RA_THE_GRAVEYARD}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->GossipStoneFairy, {[]{return logic->CallGossipFairyExceptSuns();}}),
                }, {
                  //Locations
                  LOCATION(RC_GRAVEYARD_GOSSIP_STONE, true),
                }, {
                  //Exits
                  Entrance(RR_THE_GRAVEYARD,             {[]{return true;}}),
                  Entrance(RR_SHADOW_TEMPLE_ENTRYWAY,    {[]{return logic->CanUse(RG_DINS_FIRE) || (ctx->GetTrickOption(RT_GY_SHADOW_FIRE_ARROWS) && logic->IsAdult && logic->CanUse(RG_FIRE_ARROWS));}}),
  });

}
