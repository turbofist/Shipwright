#include "ShuffleTrees.h"
#include "soh_assets.h"

extern "C" {
#include "variables.h"
#include "overlays/actors/ovl_en_Wood02/z_en_wood02.h"
extern PlayState* gPlayState;
}

extern void EnItem00_DrawRandomizedItem(EnItem00* enItem00, PlayState* play);

extern "C" void EnWood02_RandomizerDraw(Actor* thisx, PlayState* play) {
    float treeSize = 1.0f;

    OPEN_DISPS(play->state.gfxCtx);
    Gfx_SetupDL_25Opa(play->state.gfxCtx);
    Matrix_Scale(treeSize, treeSize, treeSize, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(play->state.gfxCtx, (char*)__FILE__, __LINE__),
        G_MTX_MODELVIEW | G_MTX_LOAD);

    //TODO: Change this to a tree DL.
    gSPDisplayList(POLY_OPA_DISP++, (Gfx*)gRandoPotDL);
    CLOSE_DISPS(play->state.gfxCtx);
}

uint8_t EnWood02_RandomizerHoldsItem(EnWood02* treeActor, PlayState* play) {
    uint8_t treeSetting = Rando::Context::GetInstance()->GetOption(RSK_SHUFFLE_TREES).GetContextOptionIndex();

    // Don't pull randomized item if tree isn't randomized or is already checked
    if (!IS_RANDO ||
        Flags_GetRandomizerInf(treeActor->treeId.randomizerInf) ||
        treeActor->treeId.randomizerCheck == RC_UNKNOWN_CHECK) {
        return false;
    }
    else {
        return true;
    }
}

void EnWood02_RandomizerSpawnCollectible(EnWood02* treeActor, PlayState* play) {
    LUSLOG_DEBUG("Spawning collectible.", gPlayState->sceneNum, SCENE_MARKET_DAY);
    EnItem00* item00 = (EnItem00*)Item_DropCollectible2(play, &treeActor->actor.world.pos, ITEM00_SOH_DUMMY);
    item00->randoInf = treeActor->treeId.randomizerInf;
    item00->itemEntry = Rando::Context::GetInstance()->GetFinalGIEntry(treeActor->treeId.randomizerCheck, true, GI_NONE);
    item00->actor.draw = (ActorFunc)EnItem00_DrawRandomizedItem;
    item00->actor.velocity.y = 8.0f;
    item00->actor.speedXZ = 2.0f;
    item00->actor.world.rot.y = Rand_CenteredFloat(65536.0f);
}

void EnWood02_RandomizerInit(void* actorRef) {
    Actor* actor = static_cast<Actor*>(actorRef);

    LUSLOG_DEBUG("Scene num: (%d), SCENE_MARKET_DAY = %d", gPlayState->sceneNum, SCENE_MARKET_DAY);

    // 0x00 - Large trees
    // 0x01 - Medium trees
    // 0x02 - Small trees
    if (actor->id != ACTOR_EN_WOOD02 || (gPlayState->sceneNum != SCENE_MARKET_DAY && gPlayState->sceneNum != SCENE_HYRULE_FIELD) || actor->id == ACTOR_EN_WOOD02 && actor->params >= 0x03
        || gPlayState->sceneNum == SCENE_HYRULE_FIELD && gSaveContext.cutsceneIndex == 0xFFF3)
        return;

    EnWood02* treeActor = static_cast<EnWood02*>(actorRef);

    treeActor->treeId = OTRGlobals::Instance->gRandomizer->IdentifyTree(gPlayState->sceneNum, (s16)actor->world.pos.x, (s16)actor->world.pos.z);
}

void ShuffleTrees_OnVanillaBehaviorHandler(GIVanillaBehavior id, bool* should, va_list originalArgs) {
    va_list args;
    va_copy(args, originalArgs);

    // Draw custom model for pot to indicate it holding a randomized item.
    if (id == VB_TREE_SETUP_DRAW) {
        EnWood02* treeActor = va_arg(args, EnWood02*);
        if (EnWood02_RandomizerHoldsItem(treeActor, gPlayState)) {
            treeActor->actor.draw = (ActorFunc)EnWood02_RandomizerDraw;
            *should = false;
        }
    }

    // Do not spawn vanilla item from pot, instead spawn the randomized item.
    if (id == VB_TREE_DROP_ITEM) {
        EnWood02* treeActor = va_arg(args, EnWood02*);
        if (EnWood02_RandomizerHoldsItem(treeActor, gPlayState)) {
            EnWood02_RandomizerSpawnCollectible(treeActor, gPlayState);
            *should = false;
        }
    }

    va_end(args);
}
