#ifndef SHUFFLETREES_H
#define SHUFFLETREES_H

#include <z64.h>
#include <soh/OTRGlobals.h>

#ifdef __cplusplus
extern "C" {
#endif
	void EnWood02_RandomizerInit(void* actorRef);
#ifdef __cplusplus
};
#endif

void ShuffleTrees_OnVanillaBehaviorHandler(GIVanillaBehavior id, bool* should, va_list originalArgs);

#endif //SHUFFLETREES_H
