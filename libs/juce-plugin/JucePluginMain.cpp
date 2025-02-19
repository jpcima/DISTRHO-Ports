/*
  ==============================================================================

   Main symbol/entry for juce plugins

  ==============================================================================
*/

#include "AppConfig.h"

#define JUCE_CORE_INCLUDE_NATIVE_HEADERS 1
#define JUCE_GUI_BASICS_INCLUDE_XHEADERS 1
#include "modules/juce_gui_basics/juce_gui_basics.h"
#undef None

#include "JucePluginMain.h"

#if JucePlugin_Build_AU
 #include "modules/juce_audio_plugin_client/AU/juce_AU_Wrapper.mm"
#elif JucePlugin_Build_LV2
 #include "modules/juce_audio_plugin_client/LV2/juce_LV2_Wrapper.cpp"
#elif JucePlugin_Build_RTAS
 #include "modules/juce_audio_plugin_client/RTAS/juce_RTAS_Wrapper.cpp"
#elif JucePlugin_Build_VST
 // we need to include 'juce_VSTMidiEventList' before 'juce_VST_Wrapper'
 #include "modules/juce_audio_plugin_client/utility/juce_IncludeSystemHeaders.h"
 #if JUCE_MAJOR_VERSION >= 6
 namespace Vst2 {
 #endif
 #include "modules/juce_audio_processors/format_types/juce_VSTInterface.h"
 #if JUCE_MAJOR_VERSION >= 6
 }
 #endif
 #include "modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h"
 #include "modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp"
#elif JucePlugin_Build_VST3
 #include "modules/juce_audio_plugin_client/VST3/juce_VST3_Wrapper.cpp"
#elif JucePlugin_Build_Standalone
 #include "juce_StandaloneFilterApplication.cpp"
#else
 #error Invalid configuration
#endif
