#include <obs-module.h>

OBS_DECLARE_MODULE()

OBS_MODULE_USE_DEFAULT_LOCALE("obs-transitions", "en-US")

extern struct obs_source_info cut_transition;
extern struct obs_source_info fade_transition;
extern struct obs_source_info swipe_transition;

bool obs_module_load(void)
{
	obs_register_source(&cut_transition);
	obs_register_source(&fade_transition);
	obs_register_source(&swipe_transition);
	return true;
}