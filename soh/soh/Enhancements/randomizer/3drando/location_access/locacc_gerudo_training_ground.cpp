#include "../location_access.hpp"
#include "../../entrance.h"
#include "../../dungeon.h"

using namespace Rando;

void RegionTable_Init_GerudoTrainingGrounds() {
  /*--------------------------
  |    VANILLA/MQ DECIDER    |
  ---------------------------*/
  areaTable[RR_GERUDO_TRAINING_GROUND_ENTRYWAY] = Region("Gerudo Training Ground Entryway", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_LOBBY,    {[]{return ctx->GetDungeon(GERUDO_TRAINING_GROUND)->IsVanilla();}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LOBBY, {[]{return ctx->GetDungeon(GERUDO_TRAINING_GROUND)->IsMQ();}}),
                  Entrance(RR_GERUDO_FORTRESS,                  {[]{return true;}}),
  });

  /*--------------------------
  |     VANILLA DUNGEON      |
  ---------------------------*/
  if (ctx->GetDungeon(GERUDO_TRAINING_GROUND)->IsVanilla()) {
  areaTable[RR_GERUDO_TRAINING_GROUND_LOBBY] = Region("Gerudo Training Ground Lobby", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_LOBBY_LEFT_CHEST,  logic->CanUse(RG_FAIRY_BOW) || logic->CanUse(RG_FAIRY_SLINGSHOT)),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_LOBBY_RIGHT_CHEST, logic->CanUse(RG_FAIRY_BOW) || logic->CanUse(RG_FAIRY_SLINGSHOT)),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_STALFOS_CHEST,     logic->CanUse(RG_KOKIRI_SWORD) || logic->CanUse(RG_MASTER_SWORD) || logic->CanUse(RG_BIGGORON_SWORD)),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_BEAMOS_CHEST,      logic->HasExplosives() && (logic->CanUse(RG_KOKIRI_SWORD) || logic->CanUse(RG_MASTER_SWORD) || logic->CanUse(RG_BIGGORON_SWORD))),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_BEAMOS_SOUTH_HEART, true),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_BEAMOS_EAST_HEART,  true),
                }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_ENTRYWAY,         {[]{return true;}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_HEAVY_BLOCK_ROOM, {[]{return (logic->CanUse(RG_KOKIRI_SWORD) || logic->CanUse(RG_MASTER_SWORD) || logic->CanUse(RG_BIGGORON_SWORD)) && (logic->CanUse(RG_HOOKSHOT) || ctx->GetTrickOption(RT_GTG_WITHOUT_HOOKSHOT));}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_LAVA_ROOM,        {[]{return Here(RR_GERUDO_TRAINING_GROUND_LOBBY, []{return (logic->CanUse(RG_KOKIRI_SWORD) || logic->CanUse(RG_MASTER_SWORD) || logic->CanUse(RG_BIGGORON_SWORD)) && logic->HasExplosives();});}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_CENTRAL_MAZE,     {[]{return true;}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_CENTRAL_MAZE] = Region("Gerudo Training Ground Central Maze", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_HIDDEN_CEILING_CHEST,   logic->SmallKeys(RR_GERUDO_TRAINING_GROUND, 3) && (ctx->GetTrickOption(RT_LENS_GTG) || logic->CanUse(RG_LENS_OF_TRUTH))),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MAZE_PATH_FIRST_CHEST,  logic->SmallKeys(RR_GERUDO_TRAINING_GROUND, 4)),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MAZE_PATH_SECOND_CHEST, logic->SmallKeys(RR_GERUDO_TRAINING_GROUND, 6)),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MAZE_PATH_THIRD_CHEST,  logic->SmallKeys(RR_GERUDO_TRAINING_GROUND, 7)),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MAZE_PATH_FINAL_CHEST,  logic->SmallKeys(RR_GERUDO_TRAINING_GROUND, 9)),
                }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_CENTRAL_MAZE_RIGHT, {[]{return logic->SmallKeys(RR_GERUDO_TRAINING_GROUND, 9);}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_CENTRAL_MAZE_RIGHT] = Region("Gerudo Training Ground Central Maze Right", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MAZE_RIGHT_CENTRAL_CHEST, true),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MAZE_RIGHT_SIDE_CHEST,    true),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_FREESTANDING_KEY,         true),
                }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_HAMMER_ROOM, {[]{return logic->CanUse(RG_HOOKSHOT);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_LAVA_ROOM,   {[]{return true;}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_LAVA_ROOM] = Region("Gerudo Training Ground Lava Room", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_UNDERWATER_SILVER_RUPEE_CHEST, logic->CanUse(RG_HOOKSHOT) && logic->CanUse(RG_SONG_OF_TIME) && logic->CanUse(RG_IRON_BOOTS) && logic->WaterTimer() >= 24),
                }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_CENTRAL_MAZE_RIGHT, {[]{return logic->CanUse(RG_SONG_OF_TIME) || logic->IsChild;}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_HAMMER_ROOM,        {[]{return logic->CanUse(RG_LONGSHOT)  || (logic->CanUse(RG_HOVER_BOOTS) && logic->CanUse(RG_HOOKSHOT));}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_HAMMER_ROOM] = Region("Gerudo Training Ground Hammer Room", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_HAMMER_ROOM_CLEAR_CHEST,  logic->CanAttack()),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_HAMMER_ROOM_SWITCH_CHEST, logic->CanUse(RG_MEGATON_HAMMER) || (logic->TakeDamage() && ctx->GetTrickOption(RT_FLAMING_CHESTS))),
                }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_EYE_STATUE_LOWER, {[]{return logic->CanUse(RG_MEGATON_HAMMER) && logic->CanUse(RG_FAIRY_BOW);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_LAVA_ROOM,        {[]{return true;}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_EYE_STATUE_LOWER] = Region("Gerudo Training Ground Eye Statue Lower", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_EYE_STATUE_CHEST, logic->CanUse(RG_FAIRY_BOW)),
                }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_HAMMER_ROOM, {[]{return true;}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_EYE_STATUE_UPPER] = Region("Gerudo Training Ground Eye Statue Upper", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_NEAR_SCARECROW_CHEST, logic->CanUse(RG_FAIRY_BOW)),
                }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_EYE_STATUE_LOWER, {[]{return true;}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_HEAVY_BLOCK_ROOM] = Region("Gerudo Training Ground Heavy Block Room", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_BEFORE_HEAVY_BLOCK_CHEST, logic->CanJumpslashExceptHammer()),
                }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_EYE_STATUE_UPPER, {[]{return (ctx->GetTrickOption(RT_LENS_GTG) || logic->CanUse(RG_LENS_OF_TRUTH)) && (logic->CanUse(RG_HOOKSHOT) || (ctx->GetTrickOption(RT_GTG_FAKE_WALL) && logic->CanUse(RG_HOVER_BOOTS)));}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_LIKE_LIKE_ROOM,   {[]{return (ctx->GetTrickOption(RT_LENS_GTG) || logic->CanUse(RG_LENS_OF_TRUTH)) && (logic->CanUse(RG_HOOKSHOT) || (ctx->GetTrickOption(RT_GTG_FAKE_WALL) && logic->CanUse(RG_HOVER_BOOTS))) && logic->CanUse(RG_SILVER_GAUNTLETS);}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_LIKE_LIKE_ROOM] = Region("Gerudo Training Ground Like Like Room", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_HEAVY_BLOCK_FIRST_CHEST,  logic->CanJumpslashExceptHammer()),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_HEAVY_BLOCK_SECOND_CHEST, logic->CanJumpslashExceptHammer()),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_HEAVY_BLOCK_THIRD_CHEST,  logic->CanJumpslashExceptHammer()),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_HEAVY_BLOCK_FOURTH_CHEST, logic->CanJumpslashExceptHammer()),
  }, {});
  }

  /*---------------------------
  |   MASTER QUEST DUNGEON    |
  ---------------------------*/
  if (ctx->GetDungeon(GERUDO_TRAINING_GROUND)->IsMQ()) {
  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_LOBBY] = Region("Gerudo Training Ground MQ Lobby", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_LOBBY_LEFT_CHEST,       true),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_LOBBY_RIGHT_CHEST,      true),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_MAZE_PATH_FIRST_CHEST,  true),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_MAZE_PATH_SECOND_CHEST, true),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_LOBBY_LEFT_POT_1,      logic->CanBreakPots()),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_LOBBY_LEFT_POT_2,      logic->CanBreakPots()),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_LOBBY_RIGHT_POT_1,     logic->CanBreakPots()),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_LOBBY_RIGHT_POT_2,     logic->CanBreakPots()),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_ENTRYWAY,            {[]{return true;}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_MAZE_HIDDEN_ROOM, {[]{return ctx->GetTrickOption(RT_LENS_GTG_MQ) || logic->CanUse(RG_LENS_OF_TRUTH);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_MAZE_FIRST_LOCK,  {[]{return logic->SmallKeys(RR_GERUDO_TRAINING_GROUND, 1);}}),
                  //It's possible to use the torch in RR_GERUDO_TRAINING_GROUND_MQ_MAZE_HIDDEN_ROOM with flame storage to light these
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_SAND_ROOM,        {[]{return Here(RR_GERUDO_TRAINING_GROUND_MQ_LOBBY, []{return logic->HasFireSource();});}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_DINOLFOS_ROOM,    {[]{return Here(RR_GERUDO_TRAINING_GROUND_MQ_LOBBY, []{return (logic->IsAdult && logic->CanUse(RG_FAIRY_BOW)) || (logic->IsChild && logic->CanUse(RG_FAIRY_SLINGSHOT));});}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_MAZE_HIDDEN_ROOM] = Region("Gerudo Training Ground MQ Maze Hidden Room", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_HIDDEN_CEILING_CHEST,   true),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LOBBY,      {[]{return true;}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_MAZE_FIRST_LOCK] = Region("Gerudo Training Ground MQ Maze First Lock", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_MAZE_PATH_THIRD_CHEST, true),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LOBBY,       {[]{return logic->SmallKeys(RR_GERUDO_TRAINING_GROUND, 1);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_MAZE_CENTER, {[]{return logic->SmallKeys(RR_GERUDO_TRAINING_GROUND, 3);}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_MAZE_CENTER] = Region("Gerudo Training Ground MQ Center", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->MQGTGMazeSwitch, {[]{return logic->CanUse(RG_MEGATON_HAMMER);}}),
  }, {}, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_MAZE_FIRST_LOCK, {[]{return logic->SmallKeys(RR_GERUDO_TRAINING_GROUND, 3);}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_SAND_ROOM] = Region("Gerudo Training Ground MQ Sand Room", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_FIRST_IRON_KNUCKLE_CHEST, logic->CanKillEnemy(RE_IRON_KNUCKLE)),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LOBBY,     {[]{return true;}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LEFT_SIDE, {[]{return Here(RR_GERUDO_TRAINING_GROUND_MQ_SAND_ROOM, []{return logic->CanKillEnemy(RE_IRON_KNUCKLE);});}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_LEFT_SIDE] = Region("Gerudo Training Ground MQ Left Side", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_SAND_ROOM,    {[]{return true;}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_STALFOS_ROOM, {[]{return Here(RR_GERUDO_TRAINING_GROUND_MQ_LEFT_SIDE, []{return logic->CanUse(RG_LONGSHOT) || 
                                                                                                                                          ctx->GetTrickOption(RT_GTG_MQ_WIHTOUT_HOOKSHOT) || 
                                                                                                                                          (ctx->GetTrickOption(RT_GTG_MQ_WITH_HOOKSHOT) && logic->IsAdult && logic->CanJumpslash() && logic->CanUse(RG_HOOKSHOT));});}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_STALFOS_ROOM] = Region("Gerudo Training Ground MQ Stalfos Room", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->BlueFireAccess,  {[]{return true;}}),
  }, {
                  //Locations
                  //implies logic->CanKillEnemy(RE_BIG_SKULLTULA)
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_BEFORE_HEAVY_BLOCK_CHEST, logic->CanKillEnemy(RE_STALFOS, ED_CLOSE, true, 2, true)),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_BEHIND_BLOCK,      {[]{return Here(RR_GERUDO_TRAINING_GROUND_MQ_STALFOS_ROOM, []{return logic->CanKillEnemy(RE_STALFOS, ED_CLOSE, true, 2, true);}) && logic->CanUse(RG_SILVER_GAUNTLETS);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_STATUE_ROOM_LEDGE, {[]{return logic->IsAdult && Here(RR_GERUDO_TRAINING_GROUND_MQ_STALFOS_ROOM, []{return logic->CanKillEnemy(RE_STALFOS, ED_CLOSE, true, 2, true);}) && 
                                                                                  (ctx->GetTrickOption(RT_LENS_GTG_MQ) || logic->CanUse(RG_LENS_OF_TRUTH)) && logic->BlueFire() && 
                                                                                  (logic->CanUse(RG_SONG_OF_TIME) || (ctx->GetTrickOption(RT_GTG_FAKE_WALL) && logic->CanUse(RG_HOVER_BOOTS)));}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_BEHIND_BLOCK] = Region("Gerudo Training Ground MQ Behind Block", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  //implies logic->CanKillEnemy(RE_SPIKE)
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_HEAVY_BLOCK_CHEST, logic->CanKillEnemy(RE_FREEZARD)),
  }, {});

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_STATUE_ROOM_LEDGE] = Region("Gerudo Training Ground MQ Statue Room Ledge", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_STALFOS_ROOM,       {[]{return true;}}),
                  //implies dropping down to hit the switch. Using swords, especially master, is a bit awkward, may be trick worthy, but is only relevant with other tricks
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_MAGENTA_FIRE_ROOM,  {[]{return Here(RR_GERUDO_TRAINING_GROUND_MQ_STATUE_ROOM_LEDGE, []{return logic->CanUse(RG_HOOKSHOT) || logic->CanUse(RG_FAIRY_BOW) || logic->CanUse(RG_MASTER_SWORD) || logic->CanUse(RG_BIGGORON_SWORD) || logic->CanUse(RG_STICKS) || logic->CanUse(RG_FAIRY_SLINGSHOT) || logic->CanUse(RG_BOOMERANG);});}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_STATUE_ROOM,        {[]{return true;}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_MAGENTA_FIRE_ROOM] = Region("Gerudo Training Ground MQ Magenta Fire Room", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_ICE_ARROWS_CHEST, logic->MQGTGMazeSwitch),}, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_STATUE_ROOM_LEDGE,  {[]{return true;}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_STATUE_ROOM] = Region("Gerudo Training Ground MQ Statue ROom", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_EYE_STATUE_CHEST, logic->CanUse(RG_FAIRY_BOW)),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_STATUE_ROOM_LEDGE, {[]{return logic->CanUse(RG_LONGSHOT);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_TORCH_SLUG_ROOM,   {[]{return true;}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_TORCH_SLUG_ROOM] = Region("Gerudo Training Ground MQ Torch Slug Room", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  //implies logic->CanKillEnemy(RE_TORCH_SLUG)
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_SECOND_IRON_KNUCKLE_CHEST, logic->CanKillEnemy(RE_IRON_KNUCKLE)),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_FLAME_CIRCLE_CHEST,        logic->CanHitSwitch(ED_BOMB_THROW)),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_STATUE_ROOM,   {[]{return Here(RR_GERUDO_TRAINING_GROUND_MQ_TORCH_SLUG_ROOM, []{return logic->CanKillEnemy(RE_IRON_KNUCKLE);});}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_SWITCH_LEDGE,  {[]{return Here(RR_GERUDO_TRAINING_GROUND_MQ_TORCH_SLUG_ROOM, []{return logic->CanKillEnemy(RE_IRON_KNUCKLE);});}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_SWITCH_LEDGE] = Region("Gerudo Training Ground MQ Switch Ledge", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->MQGTGRightSideSwitch,    {[]{return logic->CanUse(RG_MEGATON_HAMMER);}}),
                  EventAccess(&logic->GTGPlatformSilverRupees, {[]{return logic->CanUse(RG_FIRE_ARROWS) && logic->CanUse(RG_HOVER_BOOTS);}}),
  }, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_DINOLFOS_CHEST, logic->IsAdult && (logic->CanUse(RG_MASTER_SWORD) || logic->CanUse(RG_KOKIRI_SWORD) || logic->CanUse(RG_BIGGORON_SWORD))),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LEDGE_SIDE_PLATFORMS,  {[]{return logic->CanUse(RG_FIRE_ARROWS);}}),
                  //the fire bubble here is a jerk if you are aiming for the nearest hook platform, you have to aim to the right hand side with hook to dodge it
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_PLATFORMS_UNLIT_TORCH, {[]{return logic->CanUse(RG_LONGSHOT) || (logic->GTGPlatformSilverRupees && logic->CanUse(RG_HOOKSHOT)) ||
                                                                                           ((logic->CanUse(RG_FIRE_ARROWS) && logic->GTGPlatformSilverRupees) && logic->CanUse(RG_HOVER_BOOTS));}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_MAZE_RIGHT,            {[]{return logic->MQGTGRightSideSwitch && logic->CanUse(RG_LONGSHOT);}}),
  });

//this region exists to place silver rupee items on later, normally it's all on fire and cannot be stood on without access from another area
//This covers the 2 platforms that can be jumped to directly from RR_GERUDO_TRAINING_GROUND_MQ_SWITCH_LEDGE
//the unshuffled rupee collection is handled by the event GTGPlatformSilverRupees
  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_LEDGE_SIDE_PLATFORMS] = Region("Gerudo Training Ground MQ Ledge Side Platforms", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  //This is merely to extend this region's logic if you have hovers
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_FURTHEST_PLATFORM,  {[]{return logic->CanUse(RG_HOVER_BOOTS);}}),
  });

//this region exists to place silver rupee items on later, normally it's all on fire and cannot be stood on without access from another area
//This covers the platform that needs hover boots or the spawned targets to reach from any starting point other than RR_GERUDO_TRAINING_GROUND_MQ_MAZE_RIGHT
//the unshuffled rupee collection is handled by the event GTGPlatformSilverRupees
  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_FURTHEST_PLATFORM] = Region("Gerudo Training Ground MQ Furthest Platform", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  //This is merely to extend this region's logic if you have hovers
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LEDGE_SIDE_PLATFORMS,  {[]{return logic->CanUse(RG_HOVER_BOOTS);}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_PLATFORMS_UNLIT_TORCH] = Region("Gerudo Training Ground MQ Platforms Unlit Torch", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->GTGPlatformSilverRupees, {[]{return logic->HasFireSource() && logic->CanUse(RG_HOVER_BOOTS);}}),
  }, {}, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_UNDERWATER,            {[]{return logic->GTGPlatformSilverRupees;}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LEDGE_SIDE_PLATFORMS,  {[]{return logic->HasFireSource() && logic->CanUse(RG_HOVER_BOOTS);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_TORCH_SIDE_PLATFORMS,  {[]{return logic->HasFireSource() || logic->CanUse(RG_LONGSHOT);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_MAZE_RIGHT,            {[]{return logic->MQGTGRightSideSwitch && (logic->CanUse(RG_LONGSHOT) || (logic->CanUse(RG_HOOKSHOT) && logic->HasFireSource()));}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_TORCH_SIDE_PLATFORMS] = Region("Gerudo Training Ground Torch Side Platforms", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  //this torch shot is possible as child but tight and obtuse enough to be a trick
                  EventAccess(&logic->GTGPlatformSilverRupees, {[]{return ((logic->CanUse(RG_FAIRY_BOW) && logic->IsAdult) || logic->CanUse(RG_FIRE_ARROWS)) && logic->CanUse(RG_HOVER_BOOTS);}}),
  }, {}, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LEDGE_SIDE_PLATFORMS,  {[]{return ((logic->CanUse(RG_FAIRY_BOW) && logic->IsAdult) || logic->CanUse(RG_FIRE_ARROWS)) && logic->CanUse(RG_HOVER_BOOTS);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_PLATFORMS_UNLIT_TORCH, {[]{return (logic->CanUse(RG_FAIRY_BOW) && logic->IsAdult) || logic->CanUse(RG_FIRE_ARROWS) ||
                                                                                            logic->CanUse(RG_LONGSHOT);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_MAZE_RIGHT,            {[]{return logic->MQGTGRightSideSwitch && ((logic->CanUse(RG_FAIRY_BOW) && logic->IsAdult) || logic->CanUse(RG_FIRE_ARROWS) ||
                                                                                            logic->CanUse(RG_LONGSHOT));}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_DINOLFOS_ROOM,            {[]{return true;}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_UNDERWATER] = Region("Gerudo Training Ground MQ Underwater", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  //it is possible to snipe the stingers with bow or sling before dropping in, or just get really lucky, and avoid needing to take damage, but that might be trick worthy
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_UNDERWATER_SILVER_RUPEE_CHEST, logic->HasFireSource() && logic->CanUse(RG_IRON_BOOTS) && logic->WaterTimer() >= 24 && logic->TakeDamage()),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_PLATFORMS_UNLIT_TORCH, {[]{return true;}}),
  });


  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_MAZE_RIGHT] = Region("Gerudo Training Ground MQ Maze Right", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&logic->GTGPlatformSilverRupees, {[]{return logic->CanUse(RG_FIRE_ARROWS) && logic->CanUse(RG_HOVER_BOOTS);}}),
  }, {
                  //Locations
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_MAZE_RIGHT_CENTRAL_CHEST, true),
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_MAZE_RIGHT_SIDE_CHEST,    true),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LOBBY,                 {[]{return true;}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LEDGE_SIDE_PLATFORMS,  {[]{return logic->CanUse(RG_FIRE_ARROWS) || logic->CanUse(RG_LONGSHOT);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_PLATFORMS_UNLIT_TORCH, {[]{return logic->CanUse(RG_FIRE_ARROWS) || logic->CanUse(RG_LONGSHOT) || (logic->GTGPlatformSilverRupees && logic->CanUse(RG_HOVER_BOOTS));}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_LEDGE_SIDE_PLATFORMS,  {[]{return logic->CanUse(RG_FIRE_ARROWS);}}),
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_FURTHEST_PLATFORM,     {[]{return logic->CanUse(RG_FIRE_ARROWS);}}),
  });

  areaTable[RR_GERUDO_TRAINING_GROUND_MQ_DINOLFOS_ROOM] = Region("Gerudo Training Ground MQ Dinolfos Room", "Gerudo Training Ground", {RA_GERUDO_TRAINING_GROUND}, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  //EventAccess(&WallFairy, {[]{return WallFairy || (logic->IsAdult && logic->CanUse(RG_FAIRY_BOW));}}),
  }, {
                  //Locations
                  //implies logic->CanKillEnemy(RE_LIZALFOS and logic->CanKillEnemy(RE_DODONGO)
                  //is logic->CanKillEnemy(RE_DINOLFOS, ED_CLOSE, true, 2, true) && logic->CanKillEnemy(RE_ARMOS, ED_CLOSE, true, 1, true) broken down to exclude sticks, as it take too many to clear the room
                  //Proper enemy kill room ammo logic is needed to handle this room
                  //some combinations may be impossible without taking damage, keep an eye out for issues here
                  LOCATION(RC_GERUDO_TRAINING_GROUND_MQ_DINOLFOS_CHEST, logic->CanUse(RG_MASTER_SWORD) || logic->CanUse(RG_BIGGORON_SWORD) || logic->CanUse(RG_MEGATON_HAMMER) || logic->CanUse(RG_FAIRY_BOW) || 
                                                                        ((logic->CanUse(RG_NUTS) || logic->CanUse(RG_HOOKSHOT) || logic->CanUse(RG_BOOMERANG)) && (logic->CanUse(RG_KOKIRI_SWORD) || logic->CanUse(RG_FAIRY_SLINGSHOT)))),
  }, {
                  //Exits
                  Entrance(RR_GERUDO_TRAINING_GROUND_MQ_TORCH_SIDE_PLATFORMS, {[]{return Here(RR_GERUDO_TRAINING_GROUND_MQ_DINOLFOS_ROOM, []{return logic->CanUse(RG_MASTER_SWORD) || logic->CanUse(RG_BIGGORON_SWORD) || logic->CanUse(RG_MEGATON_HAMMER) || logic->CanUse(RG_FAIRY_BOW) || 
                                                                                                                                                   ((logic->CanUse(RG_NUTS) || logic->CanUse(RG_HOOKSHOT) || logic->CanUse(RG_BOOMERANG)) && (logic->CanUse(RG_KOKIRI_SWORD) || logic->CanUse(RG_FAIRY_SLINGSHOT)));});}}),
  });

  }
}
